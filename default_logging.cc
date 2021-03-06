/* Copyright 2015 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include "default_logging.h"
#include "env_time.h"
#include "macros.h"

//#include "tensorflow/core/platform/default/logging.h"
//#include "tensorflow/core/platform/env_time.h"
//#include "tensorflow/core/platform/macros.h"

#if defined(PLATFORM_POSIX_ANDROID)
#include <android/log.h>
#include <iostream>
#include <sstream>
#endif

#include <stdlib.h>
#include <time.h>

static std::string LogMsgLevel(int level, const char* pFormat, ...)
{
   va_list arg;

   va_start(arg, pFormat);
   std::string outText;
   const int size = vsnprintf(nullptr, 0, pFormat, arg);
   va_end(arg);

   outText.resize(size);

   va_start(arg, pFormat);
   vsnprintf(&outText[0], size + 1, pFormat, arg);
   va_end(arg);
   return outText;
}

#define LOG_HELPER_BODY(L) \
    { \
        va_list ptr; \
        va_start(ptr, format); \
        LogMsgLevel(static_cast<int>(L), format, ptr); \
        va_end(ptr); \
    }


void LOG_MSG(const char *format, ...)       LOG_HELPER_BODY(tensorflow::INFO)
void LOG_WARNING(const char *format, ...)   LOG_HELPER_BODY(tensorflow::WARNING)
void LOG_ERROR(const char *format, ...)     LOG_HELPER_BODY(tensorflow::ERROR)

//----------------------------------------------------------------------------

namespace tensorflow {
namespace internal {

LogMessage::LogMessage(const char* fname, int line, int severity)
    : fname_(fname), line_(line), severity_(severity) {}

#if defined(PLATFORM_POSIX_ANDROID)
void LogMessage::GenerateLogMessage() {
  int android_log_level;
  switch (severity_) {
    case INFO:
      android_log_level = ANDROID_LOG_INFO;
      break;
    case WARNING:
      android_log_level = ANDROID_LOG_WARN;
      break;
    case ERROR:
      android_log_level = ANDROID_LOG_ERROR;
      break;
    case FATAL:
      android_log_level = ANDROID_LOG_FATAL;
      break;
    default:
      if (severity_ < INFO) {
        android_log_level = ANDROID_LOG_VERBOSE;
      } else {
        android_log_level = ANDROID_LOG_ERROR;
      }
      break;
  }

  std::stringstream ss;
  const char* const partial_name = strrchr(fname_, '/');
  ss << (partial_name != nullptr ? partial_name + 1 : fname_) << ":" << line_
     << " " << str();
  __android_log_write(android_log_level, "native", ss.str().c_str());

  // Also log to stderr (for standalone Android apps).
  std::cerr << "native : " << ss.str() << std::endl;

  // Android logging at level FATAL does not terminate execution, so abort()
  // is still required to stop the program.
  if (severity_ == FATAL) {
    abort();
  }
}

#else

const wchar_t* wasctime()
{
   static wchar_t result[64];

   time_t rawtime;
   tm timeinfo;

   time(&rawtime);

#if defined(__unix__)
   localtime_r(&rawtime, &timeinfo);
#elif defined(_MSC_VER)
   localtime_s(&timeinfo, &rawtime);
#else
   static std::mutex mtx;
   std::lock_guard<std::mutex> lock(mtx);
   timeinfo = *std::localtime(&rawtime);
#endif

   swprintf(result, sizeof(result), L"%d-%.2d-%.2d %.2dh:%.2dm:%.2ds",
      1900 + timeinfo.tm_year,
      int(timeinfo.tm_mon + 1),
      timeinfo.tm_mday, timeinfo.tm_hour,
      timeinfo.tm_min, timeinfo.tm_sec
   );
   return result;
}


void LogMessage::GenerateLogMessage() 
{
   wprintf(L"%s\n", wasctime());

	/*
  static EnvTime* env_time = tensorflow::EnvTime::Default();
  uint64 now_micros = env_time->NowMicros();
  time_t now_seconds = static_cast<time_t>(now_micros / 1000000);
  int32 micros_remainder = static_cast<int32>(now_micros % 1000000);
  const size_t time_buffer_size = 30;
  char time_buffer[time_buffer_size];
  strftime(time_buffer, time_buffer_size, "%Y-%m-%d %H:%M:%S",
	   localtime(&now_seconds));

  // TODO(jeff,sanjay): Replace this with something that logs through the env.
  fprintf(stderr, "%s.%06d: %c %s:%d] %s\n", time_buffer, micros_remainder,
	  "IWEF"[severity_], fname_, line_, str().c_str());
	  */
}
#endif


namespace {

// Parse log level (int64) from environment variable (char*)
int64 LogLevelStrToInt(const char* tf_env_var_val) {
  if (tf_env_var_val == nullptr) {
    return 0;
  }

  // Ideally we would use env_var / safe_strto64, but it is
  // hard to use here without pulling in a lot of dependencies,
  // so we use std:istringstream instead
  string min_log_level(tf_env_var_val);
  std::istringstream ss(min_log_level);
  int64 level;
  if (!(ss >> level)) {
    // Invalid vlog level setting, set level to default (0)
    level = 0;
  }

  return level;
}

int64 MinLogLevelFromEnv() {
   const char* tf_env_var_val = 0;  // getenv("TF_CPP_MIN_LOG_LEVEL");
  return LogLevelStrToInt(tf_env_var_val);
}

int64 MinVLogLevelFromEnv() {
   const char* tf_env_var_val = 0;  // getenv("TF_CPP_MIN_VLOG_LEVEL");
  return LogLevelStrToInt(tf_env_var_val);
}

}  // namespace

int64 LogMessage::MinVLogLevel() {
   static int64 min_vlog_level = MinVLogLevelFromEnv();
   return min_vlog_level;
}

LogMessage::~LogMessage() {
  // Read the min log level once during the first call to logging.
  static int64 min_log_level = MinLogLevelFromEnv();
  if (TF_PREDICT_TRUE(severity_ >= min_log_level)) GenerateLogMessage();
}


LogMessageFatal::LogMessageFatal(const char* file, int line)
    : LogMessage(file, line, FATAL) {}

LogMessageFatal::~LogMessageFatal() {
  // abort() ensures we don't return (we promised we would not via
  // ATTRIBUTE_NORETURN).
  GenerateLogMessage();
  abort();
}

void LogString(const char* fname, int line, int severity,
               const string& message) {
  LogMessage(fname, line, severity) << message;
}

template <>
void MakeCheckOpValueString(std::ostream* os, const char& v) {
  if (v >= 32 && v <= 126) {
    (*os) << "'" << v << "'";
  } else {
    (*os) << "char value " << static_cast<short>(v);
  }
}

template <>
void MakeCheckOpValueString(std::ostream* os, const signed char& v) {
  if (v >= 32 && v <= 126) {
    (*os) << "'" << v << "'";
  } else {
    (*os) << "signed char value " << static_cast<short>(v);
  }
}

template <>
void MakeCheckOpValueString(std::ostream* os, const unsigned char& v) {
  if (v >= 32 && v <= 126) {
    (*os) << "'" << v << "'";
  } else {
    (*os) << "unsigned char value " << static_cast<unsigned short>(v);
  }
}

#if LANG_CXX11
template <>
void MakeCheckOpValueString(std::ostream* os, const std::nullptr_t& p) {
  (*os) << "nullptr";
}
#endif

CheckOpMessageBuilder::CheckOpMessageBuilder(const char* exprtext)
    : stream_(new std::ostringstream) {
  *stream_ << "Check failed: " << exprtext << " (";
}

CheckOpMessageBuilder::~CheckOpMessageBuilder() { delete stream_; }

std::ostream* CheckOpMessageBuilder::ForVar2() {
  *stream_ << " vs. ";
  return stream_;
}

string* CheckOpMessageBuilder::NewString() {
  *stream_ << ")";
  return new string(stream_->str());
}

}  // namespace internal
}  // namespace tensorflow
