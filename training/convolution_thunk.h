/* Copyright 2017 The TensorFlow Authors. All Rights Reserved.

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

#ifndef TENSORFLOW_COMPILER_XLA_SERVICE_GPU_CONVOLUTION_THUNK_H_
#define TENSORFLOW_COMPILER_XLA_SERVICE_GPU_CONVOLUTION_THUNK_H_

#include "tensorflow/compiler/xla/service/buffer_assignment.h"
#include "tensorflow/compiler/xla/service/gpu/buffer_allocations.h"
#include "tensorflow/compiler/xla/service/gpu/gpu_executable.h"
#include "tensorflow/compiler/xla/service/gpu/thunk.h"
#include "tensorflow/compiler/xla/service/hlo_instruction.h"
#include "tensorflow/compiler/xla/types.h"
#include "tensorflow/compiler/xla/xla_data.pb.h"
#include "tensorflow/core/lib/core/status.h"
#include "tensorflow/core/platform/stream_executor_no_cuda.h"

namespace xla {
namespace gpu {

// A one-time scratch allocator for forward and backward convolution. The
// scratch buffers allocated are released on destruction.
//
// Not thread-safe.
class ConvolveScratchAllocator : public perftools::gputools::ScratchAllocator {
 public:
  ConvolveScratchAllocator(int device_ordinal,
                           DeviceMemoryAllocator* memory_allocator);

  ~ConvolveScratchAllocator() override;

  int64 GetMemoryLimitInBytes(perftools::gputools::Stream* stream) override;

  int64 TotalAllocatedBytes() { return total_allocated_bytes_; }

  perftools::gputools::port::StatusOr<perftools::gputools::DeviceMemory<uint8>>
  AllocateBytes(perftools::gputools::Stream* stream, int64 byte_size) override;

 private:
  const int device_ordinal_;
  DeviceMemoryAllocator* memory_allocator_;
  std::vector<perftools::gputools::DeviceMemoryBase> allocated_buffers_;
  int64 total_allocated_bytes_ = 0;
};

// This class stores everything that StreamExecutor needs to launch a BNN
// convolution. It is generated by IrEmitter.
//
// This is thread-compatible.
class ConvolutionThunk : public Thunk {
 public:
  // ConvolutionThunk performs one of the following types of convolution.
  enum class ConvolutionKind {
    kBackwardFilter,  // Backward convolution for filter.
    kBackwardInput,   // Backward convolution for input.
    kForward,         // Forward convolution.
  };

  // Constructs a thunk for launching a DNN convolution.
  // Semantics of null hlo_instruction argument are as in Thunk.
  ConvolutionThunk(ConvolutionKind convolution_kind,
                   BufferAllocation::Index input_buffer,
                   BufferAllocation::Index filter_buffer,
                   BufferAllocation::Index output_buffer,
                   const Shape& input_shape, const Shape& filter_shape,
                   const Shape& output_shape, const Window& window,
                   const ConvolutionDimensionNumbers& dnums,
                   const HloInstruction* hlo);

  ConvolutionThunk(const ConvolutionThunk&) = delete;
  ConvolutionThunk& operator=(const ConvolutionThunk&) = delete;

  // Does the convolution for the thunk on "stream". If the
  // xla_gpu_autotune_convolution_algorithm is turned on, auto-tuning happens on
  // the first run of this function.
  tensorflow::Status ExecuteOnStream(
      const BufferAllocations& buffer_allocations,
      perftools::gputools::Stream* stream) override;

 private:
  tensorflow::Status ConvolveWithTune(
      const perftools::gputools::dnn::BatchDescriptor& input_descriptor,
      perftools::gputools::DeviceMemory<float> input_data,
      const perftools::gputools::dnn::FilterDescriptor& filter_descriptor,
      perftools::gputools::DeviceMemory<float> filter_data,
      const perftools::gputools::dnn::BatchDescriptor& output_descriptor,
      perftools::gputools::DeviceMemory<float> output_data,
      const perftools::gputools::dnn::ConvolutionDescriptor&
          convolution_descriptor,
      const BufferAllocations& buffer_allocations,
      perftools::gputools::Stream* stream);

  tensorflow::Status Convolve(
      const perftools::gputools::dnn::BatchDescriptor& input_descriptor,
      perftools::gputools::DeviceMemory<float> input_data,
      const perftools::gputools::dnn::FilterDescriptor& filter_descriptor,
      perftools::gputools::DeviceMemory<float> filter_data,
      const perftools::gputools::dnn::BatchDescriptor& output_descriptor,
      perftools::gputools::DeviceMemory<float> output_data,
      const perftools::gputools::dnn::ConvolutionDescriptor&
          convolution_descriptor,
      const perftools::gputools::dnn::AlgorithmConfig& algorithm_config,
      perftools::gputools::Stream* stream,
      ConvolveScratchAllocator* scratch_allocator,
      perftools::gputools::dnn::ProfileResult* profile_result);

  // Returns the convolve algorithms that can be used for this ConvolutionThunk.
  std::vector<perftools::gputools::dnn::AlgorithmType> GetAlgorithms(
      perftools::gputools::StreamExecutor* stream_exec) const;

  // Fastest cuDNN convolution algorithm for this thunk learned from
  // auto-tuning. If auto-tuning is disabled or failed, best_algorithm_ is set
  // to the default value indicating cuDNN's convolution will choose
  // the best algorithm from some heuristics based on its parameters.
  perftools::gputools::dnn::AlgorithmConfig best_algorithm_;

  ConvolutionKind convolution_kind_;

  BufferAllocation::Index input_buffer_;
  BufferAllocation::Index filter_buffer_;
  BufferAllocation::Index output_buffer_;

  Shape input_shape_;
  Shape filter_shape_;
  Shape output_shape_;

  Window window_;

  ConvolutionDimensionNumbers dim_nums_;
};

string ConvolutionKindToString(
    ConvolutionThunk::ConvolutionKind convolution_kind);

}  // namespace gpu
}  // namespace xla

#endif  // TENSORFLOW_COMPILER_XLA_SERVICE_GPU_CONVOLUTION_THUNK_H_
