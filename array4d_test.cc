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

#include "array4d.h"

#include <initializer_list>
#include <numeric>

//#include "tensorflow/compiler/xla/test.h"
//#include "test.h"

#include "test_helpers.h"

#include "array_slice.h"
//#include "tensorflow/core/lib/gtl/array_slice.h"

using namespace std;

namespace xla {
namespace {

class Array4dTest
{
public:

   Array4dTest() { run(); }

   void UninitializedDimsCtor();
   void FillCtor();
   void ContainerCtor();
   void InitializerListCtor();
   void Fill();
   void FillWithMultiples();
   void FillRasterDimensionDepthOne();
   void FillWithPzTestDepthOne();

   void run();
};

// Given an Array4D and a 4-tuple index, computes the linear index into the
// array idx represents.
template <typename T>
int64 Array4DLinearIndex(const Array4D<T>& arr,
                         tensorflow::gtl::ArraySlice<int64> idx) {
  EXPECT_EQ(4, idx.size());
  return (idx[3] + idx[2] * arr.n4() + idx[1] * arr.n3() * arr.n4() +
          idx[0] * arr.n2() * arr.n3() * arr.n4());
}

void Array4dTest::UninitializedDimsCtor()
{
  Array4D<int> empty(2, 3, 4, 5);
  EXPECT_EQ(empty.n1(), 2);
  EXPECT_EQ(empty.n2(), 3);
  EXPECT_EQ(empty.n3(), 4);
  EXPECT_EQ(empty.n4(), 5);
  EXPECT_EQ(empty.num_elements(), 120);
}

void Array4dTest::FillCtor()
{
  Array4D<int> fullof7(2, 3, 4, 5, 7);

  EXPECT_EQ(fullof7.n1(), 2);
  EXPECT_EQ(fullof7.n2(), 3);
  EXPECT_EQ(fullof7.n3(), 4);
  EXPECT_EQ(fullof7.n4(), 5);

  fullof7.Each([](tensorflow::gtl::ArraySlice<int64> idx, int* cell) {
    EXPECT_EQ(*cell, 7);
  });
}

void Array4dTest::ContainerCtor()
{
  // Fill an Array4D with a linear vector of [0..119] according to the default
  // row-major ordering.
  std::vector<int> filler(120);
  std::iota(filler.begin(), filler.end(), 0);

  Array4D<int> arr(2, 3, 4, 5, filler);

  EXPECT_EQ(arr.n1(), 2);
  EXPECT_EQ(arr.n2(), 3);
  EXPECT_EQ(arr.n3(), 4);
  EXPECT_EQ(arr.n4(), 5);

  arr.Each([&arr](tensorflow::gtl::ArraySlice<int64> idx, int* cell) {
    EXPECT_EQ(*cell, Array4DLinearIndex(arr, idx));
  });
}

void Array4dTest::InitializerListCtor()
{
  Array4D<int> arr = {{{{1}, {2}}, {{3}, {4}}, {{5}, {6}}, {{7}, {8}}},
                      {{{9}, {10}}, {{11}, {12}}, {{13}, {14}}, {{15}, {16}}},
                      {{{17}, {18}}, {{19}, {20}}, {{21}, {22}}, {{23}, {24}}}};

  EXPECT_EQ(arr.n1(), 3);
  EXPECT_EQ(arr.n2(), 4);
  EXPECT_EQ(arr.n3(), 2);
  EXPECT_EQ(arr.n4(), 1);
  EXPECT_EQ(arr.num_elements(), 24);

  EXPECT_EQ(arr(0, 0, 0, 0), 1);
  EXPECT_EQ(arr(0, 0, 1, 0), 2);
  EXPECT_EQ(arr(0, 1, 0, 0), 3);
  EXPECT_EQ(arr(0, 3, 1, 0), 8);
  EXPECT_EQ(arr(1, 0, 0, 0), 9);
  EXPECT_EQ(arr(1, 1, 1, 0), 12);
  EXPECT_EQ(arr(2, 0, 0, 0), 17);
  EXPECT_EQ(arr(2, 1, 1, 0), 20);
  EXPECT_EQ(arr(2, 2, 0, 0), 21);
  EXPECT_EQ(arr(2, 3, 1, 0), 24);
}

void Array4dTest::Fill()
{
  Array4D<int> fullof7(2, 3, 4, 5, 7);
  fullof7.Each([](tensorflow::gtl::ArraySlice<int64> idx, int* cell) {
    EXPECT_EQ(*cell, 7);
  });

  fullof7.Fill(11);
  fullof7.Each([](tensorflow::gtl::ArraySlice<int64> idx, int* cell) {
    EXPECT_EQ(*cell, 11);
  });
}

void Array4dTest::FillWithMultiples()
{
  Array4D<float> arr(2, 3, 4, 5);
  arr.FillWithMultiples(2.0f);

  arr.Each([&arr](tensorflow::gtl::ArraySlice<int64> idx, float* cell) {
    EXPECT_EQ(*cell, 2.0f * Array4DLinearIndex(arr, idx));
  });
}

void Array4dTest::FillRasterDimensionDepthOne()
{
  Array4D<float> array(1, 1, 128, 128);
  Array2D<float> raster(128, 128);
  for (int row = 0; row < 128; ++row) {
    for (int col = 0; col < 128; ++col) {
      raster(row, col) = row * 1000.f + col;
    }
  }

  array.FillWithYX(raster);

  VLOG(1) << array.ToString();

  EXPECT_FLOAT_EQ(raster(0, 0), array(0, 0, 0, 0));
  EXPECT_FLOAT_EQ(raster(0, 1), array(0, 0, 0, 1));
  EXPECT_FLOAT_EQ(raster(1, 0), array(0, 0, 1, 0));
  EXPECT_FLOAT_EQ(raster(1, 1), array(0, 0, 1, 1));
  EXPECT_FLOAT_EQ(raster(2, 0), array(0, 0, 2, 0));
  EXPECT_FLOAT_EQ(raster(127, 127), array(0, 0, 127, 127));

  EXPECT_FLOAT_EQ(0, array(0, 0, 0, 0));
  EXPECT_FLOAT_EQ(1, array(0, 0, 0, 1));
  EXPECT_FLOAT_EQ(2, array(0, 0, 0, 2));

  EXPECT_FLOAT_EQ(1001, array(0, 0, 1, 1));
  EXPECT_FLOAT_EQ(2001, array(0, 0, 2, 1));
  EXPECT_FLOAT_EQ(127000, array(0, 0, 127, 0));
  EXPECT_FLOAT_EQ(127127, array(0, 0, 127, 127));
}

void Array4dTest::FillWithPzTestDepthOne()
{
  Array2D<float> matrix(3, 2);
  std::initializer_list<std::initializer_list<float>> values = {
      {-3.f, -0.1f}, {0.f, -0.1f}, {3.f, 0.2f},
  };
  int rowno = 0;
  for (auto row : values) {
    int colno = 0;
    for (float f : row) {
      matrix(rowno, colno) = f;
      colno++;
    }
    rowno++;
  }

  Array4D<float> actual(3, 2, 1, 1);
  actual.FillWithPZ(matrix);

  EXPECT_FLOAT_EQ(-3, actual(0, 0, 0, 0));
  EXPECT_FLOAT_EQ(-0.1, actual(0, 1, 0, 0));

  EXPECT_FLOAT_EQ(0, actual(1, 0, 0, 0));
  EXPECT_FLOAT_EQ(-0.1, actual(1, 1, 0, 0));

  EXPECT_FLOAT_EQ(3, actual(2, 0, 0, 0));
  EXPECT_FLOAT_EQ(0.2, actual(2, 1, 0, 0));
}

void Array4dTest::run()
{
   UninitializedDimsCtor();
   FillCtor();
   ContainerCtor();
   InitializerListCtor();
   Fill();
   FillWithMultiples();
   FillRasterDimensionDepthOne();
   FillWithPzTestDepthOne();
}

}  // namespace
}  // namespace xla
