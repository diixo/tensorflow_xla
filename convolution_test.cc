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

// Tests of convolution with trivial kernels and no special variations (like
// strides and padding).

#include <memory>

#include "array2d.h"
#include "array4d.h"
#include "computation_builder.h"
#include "global_data.h"
//#include "tensorflow/compiler/xla/client/local_client.h"
#include "padding.h"
#include "layout_util.h"
//#include "tensorflow/compiler/xla/legacy_flags/cpu_compiler_flags.h"
#include "literal_util.h"
#include "ptr_util.h"
#include "reference_util.h"
#include "shape_util.h"
#include "statusor.h"
#include "client_library_test_base.h"

#include "literal_test_util.h"
#include "test_helpers.h"
//#include "tensorflow/compiler/xla/tests/test_macros.h"
#include "xla_data.pb.h"
#include "str_util.h"
#include "strcat.h"
//#include "test.h"

#include "base.h"
//#include "tensorflow/core/platform/types.h"

namespace xla {
namespace {


class ConvolutionTest : public ClientLibraryTestBase
{
 public:
#if XLA_TEST_BACKEND_GPU
  // XLA:GPU sometimes uses FFT convolution which isn't as precise as spatial
  // convolution. So relax the absolute error threshold.
  ErrorSpec error_spec_ = ErrorSpec(1e-3f);
#else
  ErrorSpec error_spec_ = ErrorSpec(1e-4f);
#endif

  ConvolutionTest() { run(); }

  void ForwardPassConvolution_3x3x256_256_OutputZ_Iota();
  void Convolve_1x1x1x2_1x1x1x2_Valid();
  void Convolve_1x1x4x4_1x1x2x2_Valid();
  void Convolve_1x1x4x4_1x1x2x2_Same();
  void Convolve_1x1x4x4_1x1x3x3_Same();
  void Convolve1D_1x2x5_1x2x2_Valid();
  void Convolve3D_1x4x2x3x3_2x2x2x3x3_Valid();

  void Conv2D_1x2x2x2_2x2_Same();
  void Conv2D_2x2x2x2_2x2_Same();
  void Conv2D_1x1x4x4_3x3_SameValid();

  void Conv2D_1x1x5x7_3x2_Same();
  void Conv2D_1x1x5x7_2x3_Same();
  void Conv2D_1x1x6x8_3x2_Same();
  void Conv2D_1x1x6x8_2x3_Same();

  void run();
};

void ConvolutionTest::ForwardPassConvolution_3x3x256_256_OutputZ_Iota()
{
  const int kInputActivationSizeY = 3;
  const int kInputActivationSizeX = 3;
  const int kInputActivationSizeZ = 256;
  const int kKernelSizeX = 2;
  const int kKernelSizeY = 2;
  const int kOutputActivationSizeZ = 256;
  const int kMiniBatchSize = 4;
  auto alhs =
      MakeUnique<Array4D<float>>(kMiniBatchSize, kInputActivationSizeZ,
                                 kInputActivationSizeY, kInputActivationSizeX);
  alhs->FillWithMultiples(1.0f);
  ASSERT_EQ(3, alhs->width());
  ASSERT_EQ(3, alhs->height());

  auto arhs =
      MakeUnique<Array4D<float>>(kOutputActivationSizeZ, kInputActivationSizeZ,
                                 kKernelSizeY, kKernelSizeX);
  Array2D<float> rhs_raster({
      {1.0f, 0.0f},  // row 0
      {0.0f, 0.0f},  // row 1
  });
  arhs->FillWithYX(rhs_raster);
  ASSERT_EQ(2, arhs->width());
  ASSERT_EQ(2, arhs->height());

  ComputationBuilder builder(TestName());
  auto lhs = builder.ConstantR4FromArray4D<float>(*alhs);
  auto rhs = builder.ConstantR4FromArray4D<float>(*arhs);
  builder.Conv(lhs, rhs, {1, 1}, Padding::kValid);

  std::unique_ptr<Array4D<float>> aexpected =
      ReferenceUtil::Conv4D(*alhs, *arhs, {1, 1}, Padding::kValid);

   ComputeAndCompareR4<float>(&builder, *aexpected, {}, error_spec_);
}

void ConvolutionTest::Convolve_1x1x1x2_1x1x1x2_Valid()
{
  ComputationBuilder builder(TestName());
  {
    Shape input_shape = ShapeUtil::MakeShape(F32, {1, 1, 1, 2});
    Shape filter_shape = ShapeUtil::MakeShape(F32, {1, 1, 1, 2});
    auto input = builder.Parameter(0, input_shape, "input");
    auto filter = builder.Parameter(1, filter_shape, "filter");
    builder.Conv(input, filter, {1, 1}, Padding::kValid);
  }

  Array4D<float> input(1, 1, 1, 2);
  input.FillWithYX(Array2D<float>({
      {1, 2},
  }));
  Array4D<float> filter(1, 1, 1, 2);
  filter.FillWithYX(Array2D<float>({
      {5, 6},
  }));

  std::unique_ptr<Array4D<float>> aexpected =
      ReferenceUtil::Conv4D(input, filter, {1, 1}, Padding::kValid);

  //auto input_literal =
  //    client_->TransferToServer(*LiteralUtil::CreateR4FromArray4D(input))
  //        .ConsumeValueOrDie();
  //auto filter_literal =
  //    client_->TransferToServer(*LiteralUtil::CreateR4FromArray4D(filter))
  //        .ConsumeValueOrDie();

  ComputeAndCompareR4<float>(&builder, *aexpected, {}, error_spec_);
}

// Tests valid padding for 2D convolution in raster space.
void ConvolutionTest::Convolve_1x1x4x4_1x1x2x2_Valid()
{
  ComputationBuilder builder(TestName());
  {
    Shape input_shape = ShapeUtil::MakeShape(F32, {1, 1, 4, 4});
    Shape filter_shape = ShapeUtil::MakeShape(F32, {1, 1, 2, 2});
    auto input = builder.Parameter(0, input_shape, "input");
    auto filter = builder.Parameter(1, filter_shape, "filter");
    builder.Conv(input, filter, {1, 1}, Padding::kValid);
  }

  Array4D<float> input(1, 1, 4, 4);
  // clang-format off
  input.FillWithYX(Array2D<float>({
    {1,  2,  3,  4 },
    {5,  6,  7,  8 },
    {9,  10, 11, 12},
    {13, 14, 15, 16},
  }));
  // clang-format on
  Array4D<float> filter(1, 1, 2, 2);
  // clang-format off
  filter.FillWithYX(Array2D<float>({
    {5, 6},
    {7, 8},
  }));
  // clang-format on

  std::unique_ptr<Array4D<float>> aexpected =
      ReferenceUtil::Conv4D(input, filter, {1, 1}, Padding::kValid);

  //auto input_literal =
  //    client_->TransferToServer(*LiteralUtil::CreateR4FromArray4D(input))
  //        .ConsumeValueOrDie();
  //auto filter_literal =
  //    client_->TransferToServer(*LiteralUtil::CreateR4FromArray4D(filter))
  //        .ConsumeValueOrDie();

  ComputeAndCompareR4<float>(&builder, *aexpected, {}, error_spec_);
}

// Tests same padding for 2D convolution in raster space.
void ConvolutionTest::Convolve_1x1x4x4_1x1x2x2_Same()
{
  ComputationBuilder builder(TestName());
  {
    Shape input_shape = ShapeUtil::MakeShape(F32, {1, 1, 4, 4});
    Shape filter_shape = ShapeUtil::MakeShape(F32, {1, 1, 2, 2});
    auto input = builder.Parameter(0, input_shape, "input");
    auto filter = builder.Parameter(1, filter_shape, "filter");
    builder.Conv(input, filter, {1, 1}, Padding::kSame);
  }

  Array4D<float> input(1, 1, 4, 4);
  // clang-format off
  input.FillWithYX(Array2D<float>({
    {1,  2,  3,  4 },
    {5,  6,  7,  8 },
    {9,  10, 11, 12},
    {13, 14, 15, 16},
  }));
  // clang-format on
  Array4D<float> filter(1, 1, 2, 2);
  // clang-format off
  filter.FillWithYX(Array2D<float>({
    {5, 6},
    {7, 8},
  }));
  // clang-format on

  std::unique_ptr<Array4D<float>> aexpected =
      ReferenceUtil::Conv4D(input, filter, {1, 1}, Padding::kSame);

  //auto input_literal =
  //    client_->TransferToServer(*LiteralUtil::CreateR4FromArray4D(input))
  //        .ConsumeValueOrDie();
  //auto filter_literal =
  //    client_->TransferToServer(*LiteralUtil::CreateR4FromArray4D(filter))
  //        .ConsumeValueOrDie();

  ComputeAndCompareR4<float>(&builder, *aexpected, {}, error_spec_);
}

// Tests same padding for 2D convolution in raster space with an odd sized
// kernel.
void ConvolutionTest::Convolve_1x1x4x4_1x1x3x3_Same()
{
  ComputationBuilder builder(TestName());
  {
    Shape input_shape = ShapeUtil::MakeShape(F32, {1, 1, 4, 4});
    Shape filter_shape = ShapeUtil::MakeShape(F32, {1, 1, 3, 3});
    auto input = builder.Parameter(0, input_shape, "input");
    auto filter = builder.Parameter(1, filter_shape, "filter");
    builder.Conv(input, filter, {1, 1}, Padding::kSame);
  }

  Array4D<float> input(1, 1, 4, 4);
  // clang-format off
  input.FillWithYX(Array2D<float>({
    {1,  2,  3,  4 },
    {5,  6,  7,  8 },
    {9,  10, 11, 12},
    {13, 14, 15, 16},
  }));
  // clang-format on
  Array4D<float> filter(1, 1, 3, 3);
  // clang-format off
  filter.FillWithYX(Array2D<float>({
    { 5,  6,  7},
    { 8,  9, 10},
    {11, 12, 13},
  }));
  // clang-format on

  std::unique_ptr<Array4D<float>> aexpected =
      ReferenceUtil::Conv4D(input, filter, {1, 1}, Padding::kSame);

  //auto input_literal =
  //    client_->TransferToServer(*LiteralUtil::CreateR4FromArray4D(input))
  //        .ConsumeValueOrDie();
  //auto filter_literal =
  //    client_->TransferToServer(*LiteralUtil::CreateR4FromArray4D(filter))
  //        .ConsumeValueOrDie();

  ComputeAndCompareR4<float>(&builder, *aexpected, {}, error_spec_);
}

// TODO(b/32873825): implement 1D convolution on GPU.
void ConvolutionTest::Convolve1D_1x2x5_1x2x2_Valid()
{
  ComputationBuilder builder(TestName());
  {
    Shape input_shape = ShapeUtil::MakeShape(F32, {1, 2, 5});
    Shape filter_shape = ShapeUtil::MakeShape(F32, {1, 2, 2});
    auto input = builder.Parameter(0, input_shape, "input");
    auto filter = builder.Parameter(1, filter_shape, "filter");
    builder.Conv(input, filter, {1}, Padding::kValid);
  }

  Array3D<float> input({{{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}}});
  Array3D<float> filter({{{10, 20}, {30, 40}}});

  Array3D<float> expected({{{510, 610, 710, 810}}});

  //auto input_literal =
  //    client_->TransferToServer(*LiteralUtil::CreateR3FromArray3D(input))
  //        .ConsumeValueOrDie();
  //auto filter_literal =
  //    client_->TransferToServer(*LiteralUtil::CreateR3FromArray3D(filter))
  //        .ConsumeValueOrDie();

  ComputeAndCompareR3<float>(&builder, expected, {}, error_spec_);
}

// TODO(b/32873825): implement 3D convolution on GPU.
void ConvolutionTest::Convolve3D_1x4x2x3x3_2x2x2x3x3_Valid()
{
  ComputationBuilder builder(TestName());
  std::vector<int64> input_dims = {1, 4, 2, 3, 3};
  std::vector<int64> filter_dims = {2, 2, 2, 3, 3};
  Shape input_shape = ShapeUtil::MakeShape(F32, input_dims);
  Shape filter_shape = ShapeUtil::MakeShape(F32, filter_dims);
  {
    auto input = builder.Parameter(0, input_shape, "input");
    auto filter = builder.Parameter(1, filter_shape, "filter");

    // Tensorflow dimension numbers for 3D convolution.
    ConvolutionDimensionNumbers dnums;
    dnums.set_batch_dimension(0);
    dnums.add_spatial_dimensions(1);
    dnums.add_spatial_dimensions(2);
    dnums.add_spatial_dimensions(3);
    dnums.set_feature_dimension(4);
    dnums.add_kernel_spatial_dimensions(0);
    dnums.add_kernel_spatial_dimensions(1);
    dnums.add_kernel_spatial_dimensions(2);
    dnums.set_kernel_input_feature_dimension(3);
    dnums.set_kernel_output_feature_dimension(4);

    builder.ConvWithGeneralDimensions(input, filter, {1, 1, 1}, Padding::kValid,
                                      dnums);
  }

  std::vector<float> input_elems(ShapeUtil::ElementsIn(input_shape));
  std::iota(input_elems.begin(), input_elems.end(), 1.0f);
  auto input_r1 = LiteralUtil::CreateR1<float>(input_elems);
  auto input_r5 =
      LiteralUtil::Reshape(*input_r1, input_dims).ConsumeValueOrDie();

  std::vector<float> filter_elems(ShapeUtil::ElementsIn(filter_shape));
  std::iota(filter_elems.begin(), filter_elems.end(), 1.0f);
  auto filter_r1 = LiteralUtil::CreateR1<float>(filter_elems);
  auto filter_r5 =
      LiteralUtil::Reshape(*filter_r1, filter_dims).ConsumeValueOrDie();

  auto expected_r1 = LiteralUtil::CreateR1<float>(
      {19554, 19962, 20370, 22110, 22590, 23070, 34890, 35730, 36570, 37446,
       38358, 39270, 50226, 51498, 52770, 52782, 54126, 55470});
  auto expected_r5 =
      LiteralUtil::Reshape(*expected_r1, {1, 3, 1, 2, 3}).ConsumeValueOrDie();

  //auto input_literal = client_->TransferToServer(*input_r5).ConsumeValueOrDie();
  //auto filter_literal =
  //    client_->TransferToServer(*filter_r5).ConsumeValueOrDie();

  //ComputeAndCompareLiteral(&builder, *expected_r5,
  //                         {input_literal.get(), filter_literal.get()},
  //                         error_spec_);
}



void ConvolutionTest::run()
{
   ForwardPassConvolution_3x3x256_256_OutputZ_Iota();
   Convolve_1x1x1x2_1x1x1x2_Valid();
   Convolve_1x1x4x4_1x1x2x2_Valid();
   Convolve_1x1x4x4_1x1x2x2_Same();
   Convolve_1x1x4x4_1x1x3x3_Same();
   Convolve1D_1x2x5_1x2x2_Valid();
   Convolve3D_1x4x2x3x3_2x2x2x3x3_Valid();

   Conv2D_1x2x2x2_2x2_Same();
   Conv2D_2x2x2x2_2x2_Same();
   Conv2D_1x1x4x4_3x3_SameValid();

   Conv2D_1x1x5x7_3x2_Same();
   Conv2D_1x1x5x7_2x3_Same();
   Conv2D_1x1x6x8_3x2_Same();
   Conv2D_1x1x6x8_2x3_Same();
}

void ConvolutionTest::Conv2D_1x2x2x2_2x2_Same()
{
   Array4D<float> input({
   {  // batch_1
      {  // channel_1
         { 3.5f,  1.5f },
         { -4.0f, 5.0f }
      },
      {  // channel_2
         { 7.0f,  9.0f },
         { -4.0f, -2.5f }
      }
   }
   });


   Array2D<float> kernel({
      { 0.5f,  1.5f },
      { 1.0f,  0.8f }
   });

   Array4D<float> result({ {
      {
         { 15.0f,  7.75f },
         { -0.25f,  1.25f }
      }
      } });

   auto conv_1_1_same = ReferenceUtil::Conv2D<float>(input, kernel, { 1, 1 }, Padding::kSame);

   ASSERT_EQ(result, *conv_1_1_same);

   auto conv_2_2_same = ReferenceUtil::Conv2D<float>(input, kernel, { 2, 2 }, Padding::kSame);

   ASSERT_EQ(Array4D<float>({{{{ 15.0f }}}}), *conv_2_2_same);
}

void ConvolutionTest::Conv2D_2x2x2x2_2x2_Same()
{
   Array4D<float> input({
      {  // batch_1
         {  // channel_1
            { 3.5f,  1.5f },
            { -4.0f, 5.0f }
         },
         {  // channel_2
            { 7.0f,  9.0f },
            { -4.0f, -2.5f }
         }
      }
      ,
      {  // batch_2
         {  // channel_1
            { 3.5f,  1.5f },
            { -4.0f, 5.0f }
         },
         {  // channel_2
            { 7.0f,  9.0f },
            { -4.0f, -2.5f }
         }
      }
   });


   Array2D<float> kernel({
      { 0.5f,  1.5f },
      { 1.0f,  0.8f }
   });

   Array4D<float> result({
   {
      {
         { 15.0f,  7.75f },
         { -0.25f,  1.25f }
      }
   }
   ,
   {
      {
         { 15.0f,  7.75f },
         { -0.25f,  1.25f }
      }      
   }
   });

   auto conv_1_1_same = ReferenceUtil::Conv2D<float>(input, kernel, { 1, 1 }, Padding::kSame);

   ASSERT_EQ(result, *conv_1_1_same);

   auto conv_2_2_same = ReferenceUtil::Conv2D<float>(input, kernel, { 2, 2 }, Padding::kSame);

   ASSERT_EQ(Array4D<float>({ { { { 15.0f } } } , { { { 15.0f } } } }), *conv_2_2_same);
}

void ConvolutionTest::Conv2D_1x1x4x4_3x3_SameValid()
{
   Array4D<float> input(
   {
      {  // batch_1
         {  // channel_1
            { 4.f, 3.f, 1.f, 0.f },
            { 2.f, 1.f, 0.f, 1.f },
            { 1.f, 2.f, 4.f, 1.f },
            { 3.f, 1.f, 0.f, 2.f }
         }
      }
   });

   Array2D<float> kernel(
   {
      { 1.f, 0.f, 1.f },
      { 2.f, 1.f, 0.f },
      { 0.f, 0.f, 1.f }
   });

   //////////////////////////////////////////////////////////////////

   auto conv_1_1_same = ReferenceUtil::Conv2D<float>(input, kernel, { 1, 1 }, Padding::kSame);

   const Array4D<float> expect_1_1_same = {
   {
      {
         { 5.f,  11.f,  8.f,  2.f },
         { 7.f,  14.f,  6.f,  2.f },
         { 3.f,   6.f,  12.f, 9.f },
         { 5.f,  12.f,  5.f,  6.f }
      }
   }
   };

   ASSERT_EQ(expect_1_1_same, *conv_1_1_same);

   //////////////////////////////////////////////////////////////////

   auto conv_2_2_same = ReferenceUtil::Conv2D<float>(input, kernel, { 2, 2 }, Padding::kSame);

   const Array4D<float> expect_2_2_same = { 
   {
      {
         { 14.f, 2.f },
         { 12.f, 6.f }
      }
   } 
   };

   ASSERT_EQ(expect_2_2_same, *conv_2_2_same);

   //////////////////////////////////////////////////////////////////

   auto conv_1_1_valid = ReferenceUtil::Conv2D<float>(input, kernel, { 1, 1 }, Padding::kValid);

   const Array4D<float> expect_1_1_valid = { 
   {
      {
         { 14.f, 6.f },
         { 6.f, 12.f }
      }
   } 
   };

   ASSERT_EQ(expect_1_1_valid, *conv_1_1_valid);

   //////////////////////////////////////////////////////////////////

   auto conv_2_2_valid = ReferenceUtil::Conv2D<float>(input, kernel, { 2, 2 }, Padding::kValid);
   
   const Array4D<float> expect_2_2_valid = { {{{14.f}}} };

   ASSERT_EQ(expect_2_2_valid, *conv_2_2_valid);
}

/*

x = tf.constant([
[1., 1., 1., 1.,  1.,  1., 1.],
[1., 2., 1., 1.,  1.,  1., 1.],
[1., 1., 2., 4.,  6.,  1., 1.],
[1., 1., 8., 10., 12., 1., 1.],
[1., 1., 1., 1.,  1.,  1., 1.],
])
x = tf.reshape(x, [1, 5, 7, 1])

kernel = tf.constant([[1., 1., 1., 1., 1., 1.]])
kernel = tf.reshape(kernel, [3, 2, 1, 1])

convSame_2x2 = tf.nn.conv2d(x, kernel, [1, 2, 2, 1], padding = 'SAME');

with tf.Session() as sess:
  print(convSame_2x2.eval(), [convSame_2x2])

*/
void ConvolutionTest::Conv2D_1x1x5x7_3x2_Same()
{
   std::vector<float> input_data = {
      1, 1, 1, 1,  1,  1, 1,  //
      1, 2, 1, 1,  1,  1, 1,  //
      1, 1, 2, 4,  6,  1, 1,  //
      1, 1, 8, 10, 12, 1, 1,  //
      1, 1, 1, 1,  1,  1, 1   //
   };

   std::vector<float> kernel = { 1, 1, 1, 1, 1, 1 };  // 3x2

   auto result = xla::ReferenceUtil::Conv2D(
      xla::Array4D<float>(1, 1, 5, 7, input_data),
      xla::Array2D<float>(3, 2, (kernel)),
      { 2, 2 },
      xla::Padding::kSame);

   std::vector<float> out_data = {
      5, 4,  4,  2,
      7, 26, 22, 3,
      4, 20, 15, 2
   };

   ASSERT_EQ(xla::Array4D<float>(1, 1, 3, 4, out_data), *result);

   //printf("%s result=%s\n", __FUNCTION__, result->ToString().c_str());
}

/*

x = tf.constant([
[1., 1., 1., 1.,  1.,  1., 1.],
[1., 2., 1., 1.,  1.,  1., 1.],
[1., 1., 2., 4.,  6.,  1., 1.],
[1., 1., 8., 10., 12., 1., 1.],
[1., 1., 1., 1.,  1.,  1., 1.],
])
x = tf.reshape(x, [1, 5, 7, 1])

kernel = tf.constant([[1., 1., 1., 1., 1., 1.]])
kernel = tf.reshape(kernel, [2, 3, 1, 1])

convSame_2x2 = tf.nn.conv2d(x, kernel, [1, 2, 2, 1], padding = 'SAME');

with tf.Session() as sess:
  print(convSame_2x2.eval(), [convSame_2x2])

*/
void ConvolutionTest::Conv2D_1x1x5x7_2x3_Same()
{
   std::vector<float> input_data = {
      1, 1, 1, 1,  1,  1, 1,  //
      1, 2, 1, 1,  1,  1, 1,  //
      1, 1, 2, 4,  6,  1, 1,  //
      1, 1, 8, 10, 12, 1, 1,  //
      1, 1, 1, 1,  1,  1, 1   //
   };

   std::vector<float> kernel = { 1, 1, 1, 1, 1, 1 };  // 2x3

   auto result = xla::ReferenceUtil::Conv2D(
      xla::Array4D<float>(1, 1, 5, 7, input_data),
      xla::Array2D<float>(2, 3, (kernel)),
      { 2, 2 },
      xla::Padding::kSame);

   std::vector<float> out_data = {
      5, 7,  6,  4,
      4, 26, 34, 4,
      2, 3,  3,  2
   };

   ASSERT_EQ(xla::Array4D<float>(1, 1, 3, 4, out_data), *result);

   //printf("%s result=%s\n", __FUNCTION__, result->ToString().c_str());
}

/*

x = tf.constant([
[1., 1., 1., 1.,  1.,  1., 1., 1.],
[1., 2., 1., 1.,  1.,  1., 1., 1.],
[1., 1., 2., 4.,  6.,  1., 1., 1.],
[1., 1., 8., 10., 12., 1., 1., 1.],
[1., 1., 1., 1.,  1.,  1., 2., 1.],
[1., 1., 1., 1.,  1.,  1., 1., 1.],
])
x = tf.reshape(x, [1, 6, 8, 1])

kernel = tf.constant([[1., 1., 1., 1., 1., 1.]])
kernel = tf.reshape(kernel, [3, 2, 1, 1])

convSame_2x2 = tf.nn.conv2d(x, kernel, [1, 2, 2, 1], padding = 'SAME');

with tf.Session() as sess:
  print(convSame_2x2.eval(), [convSame_2x2])

*/
void ConvolutionTest::Conv2D_1x1x6x8_3x2_Same()
{
   std::vector<float> input_data = {
      1, 1, 1, 1,  1,  1, 1, 1, //
      1, 2, 1, 1,  1,  1, 1, 1, //
      1, 1, 2, 4,  6,  1, 1, 1, //
      1, 1, 8, 10, 12, 1, 1, 1, //
      1, 1, 1, 1,  1,  1, 2, 1, //
      1, 1, 1, 1,  1,  1, 1, 1  //
   };

   std::vector<float> kernel = { 1, 1, 1, 1, 1, 1 };  // 3x2

   auto result = xla::ReferenceUtil::Conv2D(
      xla::Array4D<float>(1, 1, 6, 8, input_data),
      xla::Array2D<float>(3, 2, (kernel)),
      { 2, 2 },
      xla::Padding::kSame);

   std::vector<float> out_data = {
      7, 10, 11, 6,
      6, 26, 22, 7,
      4, 4,  4,  5
   };

   ASSERT_EQ(xla::Array4D<float>(1, 1, 3, 4, out_data), *result);

   //printf("%s result=%s\n", __FUNCTION__, result->ToString().c_str());
}

/*

x = tf.constant([
[1., 1., 1., 1.,  1.,  1., 1., 1.],
[1., 2., 1., 1.,  1.,  1., 1., 1.],
[1., 1., 2., 4.,  6.,  1., 1., 1.],
[1., 1., 8., 10., 12., 1., 1., 1.],
[1., 1., 1., 1.,  1.,  1., 2., 1.],
[1., 1., 1., 1.,  1.,  1., 1., 1.],
])
x = tf.reshape(x, [1, 6, 8, 1])

kernel = tf.constant([[1., 1., 1., 1., 1., 1.]])
kernel = tf.reshape(kernel, [2, 3, 1, 1])

convSame_2x2 = tf.nn.conv2d(x, kernel, [1, 2, 2, 1], padding = 'SAME');

with tf.Session() as sess:
  print(convSame_2x2.eval(), [convSame_2x2])

*/
void ConvolutionTest::Conv2D_1x1x6x8_2x3_Same()
{
   std::vector<float> input_data = {
      1, 1, 1, 1,  1,  1, 1, 1, //
      1, 2, 1, 1,  1,  1, 1, 1, //
      1, 1, 2, 4,  6,  1, 1, 1, //
      1, 1, 8, 10, 12, 1, 1, 1, //
      1, 1, 1, 1,  1,  1, 2, 1, //
      1, 1, 1, 1,  1,  1, 1, 1  //
   };

   std::vector<float> kernel = { 1, 1, 1, 1, 1, 1 };  // 2x3

   auto result = xla::ReferenceUtil::Conv2D(
      xla::Array4D<float>(1, 1, 6, 8, input_data),
      xla::Array2D<float>(2, 3, (kernel)),
      { 2, 2 },
      xla::Padding::kSame);

   std::vector<float> out_data = {
      7,  6,  6,  4,
      14, 42, 22, 4,
      6,  6,  7,  5
   };

   ASSERT_EQ(xla::Array4D<float>(1, 1, 3, 4, out_data), *result);

   //printf("%s result=%s\n", __FUNCTION__, result->ToString().c_str());
}

}  // namespace
}  // namespace xla


/*
int main(int argc, char** argv)
{
   // TODO:
  const bool parse_result = tensorflow::Flags::Parse(&argc, argv, flag_list);
  if (!parse_result) {
    LOG(ERROR) << "\n" << usage;
    return 2;
  }
  testing::InitGoogleTest(&argc, argv);
  if (argc > 1) {
    LOG(ERROR) << "Unknown argument " << argv[1] << "\n" << usage;
    return 2;
  }
  return RUN_ALL_TESTS();
}
*/
