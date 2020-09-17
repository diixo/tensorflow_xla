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

// Simple hash functions used for internal data structures

#ifndef TENSORFLOW_LIB_HASH_HASH_H_
#define TENSORFLOW_LIB_HASH_HASH_H_

#include <stddef.h>
#include <stdint.h>

#include "base.h"

namespace tensorflow {

extern uint32 Hash32(const char* data, size_t n, uint32 seed);
extern uint64 Hash64(const char* data, size_t n, uint64 seed);

inline uint64 Hash64(const char* data, size_t n) {
  return Hash64(data, n, 0xDECAFCAFFE);
}

inline uint64 Hash64(const string& str) {
  return Hash64(str.data(), str.size());
}

inline uint64 Hash64Combine(uint64 a, uint64 b) {
  return a ^ (b + 0x9e3779b97f4a7800ULL + (a << 10) + (a >> 4));
}

// Convenience Hash functors
struct HashStr {
  size_t operator()(const string& s) const {
    return static_cast<size_t>(Hash64(s));
  }
};
template <typename PTR>
struct HashPtr {
  size_t operator()(const PTR p) const {
    // Hash pointers as integers, but bring more entropy to the lower bits.
    size_t k = static_cast<size_t>(reinterpret_cast<uintptr_t>(p));
    return k + (k >> 6);
  }
};

}  // namespace tensorflow

#endif  // TENSORFLOW_LIB_HASH_HASH_H_
