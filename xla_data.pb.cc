
#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "xla_data.pb.h"

#include "google/google_common.h"
#include "google/google_port.h"
#include "google/google_once.h"

#include <algorithm>

#include "google/google_generated_message_util.h"


//#include <google/protobuf/stubs/common.h>
//#include <google/protobuf/stubs/port.h>
//#include <google/protobuf/stubs/once.h>
//#include <google/protobuf/io/coded_stream.h>
//#include <google/protobuf/wire_format_lite_inl.h>
//#include <google/protobuf/descriptor.h>
//#include <google/protobuf/generated_message_reflection.h>
//#include <google/protobuf/reflection_ops.h>
//#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace xla {
class PaddingConfig_PaddingConfigDimensionDefaultTypeInternal
{
} _PaddingConfig_PaddingConfigDimension_default_instance_;

class PaddingConfigDefaultTypeInternal
{
} _PaddingConfig_default_instance_;

class LayoutDefaultTypeInternal
{
} _Layout_default_instance_;

class ShapeDefaultTypeInternal 
{
} _Shape_default_instance_;

class ProgramShapeDefaultTypeInternal
{
} _ProgramShape_default_instance_;

class ComputationHandleDefaultTypeInternal
{
} _ComputationHandle_default_instance_;

class GlobalDataHandleDefaultTypeInternal
{
} _GlobalDataHandle_default_instance_;

class ComputationDataHandleDefaultTypeInternal
{
} _ComputationDataHandle_default_instance_;

class LiteralDefaultTypeInternal
{
} _Literal_default_instance_;

class WindowDimensionDefaultTypeInternal
{
} _WindowDimension_default_instance_;

class WindowDefaultTypeInternal
{
} _Window_default_instance_;

class ConvolutionDimensionNumbersDefaultTypeInternal
{
} _ConvolutionDimensionNumbers_default_instance_;


bool PrimitiveType_IsValid(int value) 
{
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
      return true;
    default:
      return false;
  }
}

bool PaddingValue_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      return true;
    default:
      return false;
  }
}

bool UnaryOperation_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
      return true;
    default:
      return false;
  }
}

bool BinaryOperation_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
      return true;
    default:
      return false;
   }
}

bool RandomDistribution_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    default:
      return false;
  }
}

bool TernaryOperation_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    default:
      return false;
  }
}

bool VariadicOperation_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
      return true;
    default:
      return false;
  }
}


// ===================================================================

PaddingConfig_PaddingConfigDimension::PaddingConfig_PaddingConfigDimension()
{
  SharedCtor();
  // @@protoc_insertion_point(constructor:xla.PaddingConfig.PaddingConfigDimension)
}

PaddingConfig_PaddingConfigDimension::PaddingConfig_PaddingConfigDimension(const PaddingConfig_PaddingConfigDimension& from)
  : _cached_size_(0) 
{
  ::memcpy(&edge_padding_low_, &from.edge_padding_low_,
    reinterpret_cast<char*>(&interior_padding_) -
    reinterpret_cast<char*>(&edge_padding_low_) + sizeof(interior_padding_));
  // @@protoc_insertion_point(copy_constructor:xla.PaddingConfig.PaddingConfigDimension)
}

void PaddingConfig_PaddingConfigDimension::SharedCtor() {
  ::memset(&edge_padding_low_, 0, reinterpret_cast<char*>(&interior_padding_) -
    reinterpret_cast<char*>(&edge_padding_low_) + sizeof(interior_padding_));
  _cached_size_ = 0;
}

PaddingConfig_PaddingConfigDimension::~PaddingConfig_PaddingConfigDimension() {
  // @@protoc_insertion_point(destructor:xla.PaddingConfig.PaddingConfigDimension)
  SharedDtor();
}

void PaddingConfig_PaddingConfigDimension::SharedDtor() {
}

void PaddingConfig_PaddingConfigDimension::SetCachedSize(int size) const {
  //GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  //GOOGLE_SAFE_CONCURRENT_WRITES_END();
}

const PaddingConfig_PaddingConfigDimension& PaddingConfig_PaddingConfigDimension::default_instance() {
  //protobuf_xla_5fdata_2eproto::InitDefaults();
  return *internal_default_instance();
}

PaddingConfig_PaddingConfigDimension* PaddingConfig_PaddingConfigDimension::New(::google::protobuf::Arena* arena) const {
  PaddingConfig_PaddingConfigDimension* n = new PaddingConfig_PaddingConfigDimension;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void PaddingConfig_PaddingConfigDimension::Clear() {
// @@protoc_insertion_point(message_clear_start:xla.PaddingConfig.PaddingConfigDimension)
  ::memset(&edge_padding_low_, 0, reinterpret_cast<char*>(&interior_padding_) -
    reinterpret_cast<char*>(&edge_padding_low_) + sizeof(interior_padding_));
}

void PaddingConfig_PaddingConfigDimension::MergeFrom(const PaddingConfig_PaddingConfigDimension& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:xla.PaddingConfig.PaddingConfigDimension)
  GOOGLE_DCHECK_NE(&from, this);

  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.edge_padding_low() != 0) {
    set_edge_padding_low(from.edge_padding_low());
  }
  if (from.edge_padding_high() != 0) {
    set_edge_padding_high(from.edge_padding_high());
  }
  if (from.interior_padding() != 0) {
    set_interior_padding(from.interior_padding());
  }
}

//void PaddingConfig_PaddingConfigDimension::CopyFrom(const ::google::protobuf::Message& from) {
//// @@protoc_insertion_point(generalized_copy_from_start:xla.PaddingConfig.PaddingConfigDimension)
//  if (&from == this) return;
//  Clear();
//  MergeFrom(from);
//}

void PaddingConfig_PaddingConfigDimension::CopyFrom(const PaddingConfig_PaddingConfigDimension& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:xla.PaddingConfig.PaddingConfigDimension)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool PaddingConfig_PaddingConfigDimension::IsInitialized() const {
  return true;
}

void PaddingConfig_PaddingConfigDimension::Swap(PaddingConfig_PaddingConfigDimension* other) {
  if (other == this) return;
  InternalSwap(other);
}

void PaddingConfig_PaddingConfigDimension::InternalSwap(PaddingConfig_PaddingConfigDimension* other) {
  std::swap(edge_padding_low_, other->edge_padding_low_);
  std::swap(edge_padding_high_, other->edge_padding_high_);
  std::swap(interior_padding_, other->interior_padding_);
  std::swap(_cached_size_, other->_cached_size_);
}


#if PROTOBUF_INLINE_NOT_IN_HEADERS
// PaddingConfig_PaddingConfigDimension

void PaddingConfig_PaddingConfigDimension::clear_edge_padding_low() {
  edge_padding_low_ = GOOGLE_LONGLONG(0);
}
::google::protobuf::int64 PaddingConfig_PaddingConfigDimension::edge_padding_low() const {
  // @@protoc_insertion_point(field_get:xla.PaddingConfig.PaddingConfigDimension.edge_padding_low)
  return edge_padding_low_;
}
void PaddingConfig_PaddingConfigDimension::set_edge_padding_low(::google::protobuf::int64 value) {
  
  edge_padding_low_ = value;
  // @@protoc_insertion_point(field_set:xla.PaddingConfig.PaddingConfigDimension.edge_padding_low)
}

void PaddingConfig_PaddingConfigDimension::clear_edge_padding_high() {
  edge_padding_high_ = GOOGLE_LONGLONG(0);
}
::google::protobuf::int64 PaddingConfig_PaddingConfigDimension::edge_padding_high() const {
  // @@protoc_insertion_point(field_get:xla.PaddingConfig.PaddingConfigDimension.edge_padding_high)
  return edge_padding_high_;
}
void PaddingConfig_PaddingConfigDimension::set_edge_padding_high(::google::protobuf::int64 value) {
  
  edge_padding_high_ = value;
  // @@protoc_insertion_point(field_set:xla.PaddingConfig.PaddingConfigDimension.edge_padding_high)
}

void PaddingConfig_PaddingConfigDimension::clear_interior_padding() {
  interior_padding_ = GOOGLE_LONGLONG(0);
}
::google::protobuf::int64 PaddingConfig_PaddingConfigDimension::interior_padding() const {
  // @@protoc_insertion_point(field_get:xla.PaddingConfig.PaddingConfigDimension.interior_padding)
  return interior_padding_;
}
void PaddingConfig_PaddingConfigDimension::set_interior_padding(::google::protobuf::int64 value) {
  
  interior_padding_ = value;
  // @@protoc_insertion_point(field_set:xla.PaddingConfig.PaddingConfigDimension.interior_padding)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// ===================================================================

PaddingConfig::PaddingConfig()
{
  SharedCtor();
  // @@protoc_insertion_point(constructor:xla.PaddingConfig)
}

PaddingConfig::PaddingConfig(const PaddingConfig& from)
  : 
      dimensions_(from.dimensions_),
      _cached_size_(0)
{
  // @@protoc_insertion_point(copy_constructor:xla.PaddingConfig)
}

void PaddingConfig::SharedCtor() {
  _cached_size_ = 0;
}

PaddingConfig::~PaddingConfig() {
  // @@protoc_insertion_point(destructor:xla.PaddingConfig)
  SharedDtor();
}

void PaddingConfig::SharedDtor() {
}

void PaddingConfig::SetCachedSize(int size) const {
  //GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  //GOOGLE_SAFE_CONCURRENT_WRITES_END();
}

const PaddingConfig& PaddingConfig::default_instance() {
  //protobuf_xla_5fdata_2eproto::InitDefaults();
  return *internal_default_instance();
}

PaddingConfig* PaddingConfig::New(::google::protobuf::Arena* arena) const {
  PaddingConfig* n = new PaddingConfig;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void PaddingConfig::Clear() {
// @@protoc_insertion_point(message_clear_start:xla.PaddingConfig)
  dimensions_.Clear();
}

void PaddingConfig::MergeFrom(const PaddingConfig& from)
{
// @@protoc_insertion_point(class_specific_merge_from_start:xla.PaddingConfig)
  GOOGLE_DCHECK_NE(&from, this);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  dimensions_.MergeFrom(from.dimensions_);
}

//void PaddingConfig::CopyFrom(const ::google::protobuf::Message& from) 
//{
//// @@protoc_insertion_point(generalized_copy_from_start:xla.PaddingConfig)
//  if (&from == this) return;
//  Clear();
//  MergeFrom(from);
//}

void PaddingConfig::CopyFrom(const PaddingConfig& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:xla.PaddingConfig)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool PaddingConfig::IsInitialized() const {
  return true;
}

void PaddingConfig::Swap(PaddingConfig* other) {
  if (other == this) return;
  InternalSwap(other);
}
void PaddingConfig::InternalSwap(PaddingConfig* other) {
  dimensions_.InternalSwap(&other->dimensions_);
  std::swap(_cached_size_, other->_cached_size_);
}


#if PROTOBUF_INLINE_NOT_IN_HEADERS
// PaddingConfig

// repeated .xla.PaddingConfig.PaddingConfigDimension dimensions = 1;
int PaddingConfig::dimensions_size() const {
  return dimensions_.size();
}
void PaddingConfig::clear_dimensions() {
  dimensions_.Clear();
}
const ::xla::PaddingConfig_PaddingConfigDimension& PaddingConfig::dimensions(int index) const {
  // @@protoc_insertion_point(field_get:xla.PaddingConfig.dimensions)
  return dimensions_.Get(index);
}
::xla::PaddingConfig_PaddingConfigDimension* PaddingConfig::mutable_dimensions(int index) {
  // @@protoc_insertion_point(field_mutable:xla.PaddingConfig.dimensions)
  return dimensions_.Mutable(index);
}
::xla::PaddingConfig_PaddingConfigDimension* PaddingConfig::add_dimensions() {
  // @@protoc_insertion_point(field_add:xla.PaddingConfig.dimensions)
  return dimensions_.Add();
}
::google::protobuf::RepeatedPtrField< ::xla::PaddingConfig_PaddingConfigDimension >*
PaddingConfig::mutable_dimensions() {
  // @@protoc_insertion_point(field_mutable_list:xla.PaddingConfig.dimensions)
  return &dimensions_;
}
const ::google::protobuf::RepeatedPtrField< ::xla::PaddingConfig_PaddingConfigDimension >&
PaddingConfig::dimensions() const {
  // @@protoc_insertion_point(field_list:xla.PaddingConfig.dimensions)
  return dimensions_;
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// ===================================================================

Layout::Layout()
{
  SharedCtor();
  // @@protoc_insertion_point(constructor:xla.Layout)
}

Layout::Layout(const Layout& from)
  :
      minor_to_major_(from.minor_to_major_),
      padded_dimensions_(from.padded_dimensions_),
      _cached_size_(0)
{
  padding_value_ = from.padding_value_;
  // @@protoc_insertion_point(copy_constructor:xla.Layout)
}

void Layout::SharedCtor() {
  padding_value_ = 0;
  _cached_size_ = 0;
}

Layout::~Layout() {
  // @@protoc_insertion_point(destructor:xla.Layout)
  SharedDtor();
}

void Layout::SharedDtor() {
}

void Layout::SetCachedSize(int size) const {
  //GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  //GOOGLE_SAFE_CONCURRENT_WRITES_END();
}


const Layout& Layout::default_instance() {
  //protobuf_xla_5fdata_2eproto::InitDefaults();
  return *internal_default_instance();
}

Layout* Layout::New(::google::protobuf::Arena* arena) const {
  Layout* n = new Layout;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void Layout::Clear() {
// @@protoc_insertion_point(message_clear_start:xla.Layout)
  minor_to_major_.Clear();
  padded_dimensions_.Clear();
  padding_value_ = 0;
}


void Layout::MergeFrom(const Layout& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:xla.Layout)
  GOOGLE_DCHECK_NE(&from, this);
  tensorflow::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  minor_to_major_.MergeFrom(from.minor_to_major_);
  padded_dimensions_.MergeFrom(from.padded_dimensions_);
  if (from.padding_value() != 0) {
    set_padding_value(from.padding_value());
  }
}


void Layout::CopyFrom(const Layout& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:xla.Layout)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Layout::IsInitialized() const {
  return true;
}

void Layout::Swap(Layout* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Layout::InternalSwap(Layout* other) {
  minor_to_major_.InternalSwap(&other->minor_to_major_);
  padded_dimensions_.InternalSwap(&other->padded_dimensions_);
  std::swap(padding_value_, other->padding_value_);
  std::swap(_cached_size_, other->_cached_size_);
}


#if PROTOBUF_INLINE_NOT_IN_HEADERS
// Layout

int Layout::minor_to_major_size() const {
  return minor_to_major_.size();
}
void Layout::clear_minor_to_major() {
  minor_to_major_.Clear();
}
tensorflow::int64 Layout::minor_to_major(int index) const {
  // @@protoc_insertion_point(field_get:xla.Layout.minor_to_major)
  return minor_to_major_.Get(index);
}
void Layout::set_minor_to_major(int index, tensorflow::int64 value) {
  minor_to_major_.Set(index, value);
  // @@protoc_insertion_point(field_set:xla.Layout.minor_to_major)
}
void Layout::add_minor_to_major(tensorflow::int64 value) {
  minor_to_major_.Add(value);
  // @@protoc_insertion_point(field_add:xla.Layout.minor_to_major)
}
const ::google::protobuf::RepeatedField< tensorflow::int64 >&
Layout::minor_to_major() const {
  // @@protoc_insertion_point(field_list:xla.Layout.minor_to_major)
  return minor_to_major_;
}
::google::protobuf::RepeatedField< tensorflow::int64 >*
Layout::mutable_minor_to_major() {
  // @@protoc_insertion_point(field_mutable_list:xla.Layout.minor_to_major)
  return &minor_to_major_;
}

int Layout::padded_dimensions_size() const {
  return padded_dimensions_.size();
}
void Layout::clear_padded_dimensions() {
  padded_dimensions_.Clear();
}
tensorflow::int64 Layout::padded_dimensions(int index) const {
  // @@protoc_insertion_point(field_get:xla.Layout.padded_dimensions)
  return padded_dimensions_.Get(index);
}
void Layout::set_padded_dimensions(int index, tensorflow::int64 value) {
  padded_dimensions_.Set(index, value);
  // @@protoc_insertion_point(field_set:xla.Layout.padded_dimensions)
}
void Layout::add_padded_dimensions(tensorflow::int64 value) {
  padded_dimensions_.Add(value);
  // @@protoc_insertion_point(field_add:xla.Layout.padded_dimensions)
}
const ::google::protobuf::RepeatedField< tensorflow::int64 >&
Layout::padded_dimensions() const {
  // @@protoc_insertion_point(field_list:xla.Layout.padded_dimensions)
  return padded_dimensions_;
}
::google::protobuf::RepeatedField< tensorflow::int64 >*
Layout::mutable_padded_dimensions() {
  // @@protoc_insertion_point(field_mutable_list:xla.Layout.padded_dimensions)
  return &padded_dimensions_;
}

void Layout::clear_padding_value() {
  padding_value_ = 0;
}
::xla::PaddingValue Layout::padding_value() const {
  // @@protoc_insertion_point(field_get:xla.Layout.padding_value)
  return static_cast< ::xla::PaddingValue >(padding_value_);
}
void Layout::set_padding_value(::xla::PaddingValue value) {
  
  padding_value_ = value;
  // @@protoc_insertion_point(field_set:xla.Layout.padding_value)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// ===================================================================

Shape::Shape()
{
  SharedCtor();
  // @@protoc_insertion_point(constructor:xla.Shape)
}

Shape::Shape(const Shape& from)
 :
      dimensions_(from.dimensions_),
      tuple_shapes_(from.tuple_shapes_),
      _cached_size_(0)
{
  if (from.has_layout()) {
    layout_ = new ::xla::Layout(*from.layout_);
  } else {
    layout_ = NULL;
  }
  element_type_ = from.element_type_;
  // @@protoc_insertion_point(copy_constructor:xla.Shape)
}

void Shape::SharedCtor() {
  ::memset(&layout_, 0, reinterpret_cast<char*>(&element_type_) -
    reinterpret_cast<char*>(&layout_) + sizeof(element_type_));
  _cached_size_ = 0;
}

Shape::~Shape() {
  // @@protoc_insertion_point(destructor:xla.Shape)
  SharedDtor();
}

void Shape::SharedDtor() {
  if (this != internal_default_instance()) {
    delete layout_;
  }
}

void Shape::SetCachedSize(int size) const {
  //GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  //GOOGLE_SAFE_CONCURRENT_WRITES_END();
}


const Shape& Shape::default_instance() {
  //protobuf_xla_5fdata_2eproto::InitDefaults();
  return *internal_default_instance();
}

Shape* Shape::New(::google::protobuf::Arena* arena) const {
  Shape* n = new Shape;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void Shape::Clear() {
// @@protoc_insertion_point(message_clear_start:xla.Shape)
  dimensions_.Clear();
  tuple_shapes_.Clear();
  if (GetArenaNoVirtual() == NULL && layout_ != NULL) {
    delete layout_;
  }
  layout_ = NULL;
  element_type_ = 0;
}


void Shape::MergeFrom(const Shape& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:xla.Shape)
  GOOGLE_DCHECK_NE(&from, this);
  tensorflow::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  dimensions_.MergeFrom(from.dimensions_);
  tuple_shapes_.MergeFrom(from.tuple_shapes_);
  if (from.has_layout()) {
    mutable_layout()->::xla::Layout::MergeFrom(from.layout());
  }
  if (from.element_type() != 0) {
    set_element_type(from.element_type());
  }
}


void Shape::CopyFrom(const Shape& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:xla.Shape)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Shape::IsInitialized() const {
  return true;
}

void Shape::Swap(Shape* other) {
  if (other == this) return;
  InternalSwap(other);
}

void Shape::InternalSwap(Shape* other) {
  dimensions_.InternalSwap(&other->dimensions_);
  tuple_shapes_.InternalSwap(&other->tuple_shapes_);
  std::swap(layout_, other->layout_);
  std::swap(element_type_, other->element_type_);
  std::swap(_cached_size_, other->_cached_size_);
}


#if PROTOBUF_INLINE_NOT_IN_HEADERS
// Shape

void Shape::clear_element_type() {
  element_type_ = 0;
}
::xla::PrimitiveType Shape::element_type() const {
  // @@protoc_insertion_point(field_get:xla.Shape.element_type)
  return static_cast< ::xla::PrimitiveType >(element_type_);
}
void Shape::set_element_type(::xla::PrimitiveType value) {
  
  element_type_ = value;
  // @@protoc_insertion_point(field_set:xla.Shape.element_type)
}

int Shape::dimensions_size() const {
  return dimensions_.size();
}
void Shape::clear_dimensions() {
  dimensions_.Clear();
}
tensorflow::int64 Shape::dimensions(int index) const {
  // @@protoc_insertion_point(field_get:xla.Shape.dimensions)
  return dimensions_.Get(index);
}
void Shape::set_dimensions(int index, tensorflow::int64 value) {
  dimensions_.Set(index, value);
  // @@protoc_insertion_point(field_set:xla.Shape.dimensions)
}
void Shape::add_dimensions(tensorflow::int64 value) {
  dimensions_.Add(value);
  // @@protoc_insertion_point(field_add:xla.Shape.dimensions)
}
const ::google::protobuf::RepeatedField< tensorflow::int64 >&
Shape::dimensions() const {
  // @@protoc_insertion_point(field_list:xla.Shape.dimensions)
  return dimensions_;
}
::google::protobuf::RepeatedField< tensorflow::int64 >*
Shape::mutable_dimensions() {
  // @@protoc_insertion_point(field_mutable_list:xla.Shape.dimensions)
  return &dimensions_;
}

int Shape::tuple_shapes_size() const {
  return tuple_shapes_.size();
}
void Shape::clear_tuple_shapes() {
  tuple_shapes_.Clear();
}
const ::xla::Shape& Shape::tuple_shapes(int index) const {
  // @@protoc_insertion_point(field_get:xla.Shape.tuple_shapes)
  return tuple_shapes_.Get(index);
}
::xla::Shape* Shape::mutable_tuple_shapes(int index) {
  // @@protoc_insertion_point(field_mutable:xla.Shape.tuple_shapes)
  return tuple_shapes_.Mutable(index);
}
::xla::Shape* Shape::add_tuple_shapes() {
  // @@protoc_insertion_point(field_add:xla.Shape.tuple_shapes)
  return tuple_shapes_.Add();
}
::google::protobuf::RepeatedPtrField< ::xla::Shape >*
Shape::mutable_tuple_shapes() {
  // @@protoc_insertion_point(field_mutable_list:xla.Shape.tuple_shapes)
  return &tuple_shapes_;
}
const ::google::protobuf::RepeatedPtrField< ::xla::Shape >&
Shape::tuple_shapes() const {
  // @@protoc_insertion_point(field_list:xla.Shape.tuple_shapes)
  return tuple_shapes_;
}

bool Shape::has_layout() const {
  return this != internal_default_instance() && layout_ != NULL;
}
void Shape::clear_layout() {
  if (GetArenaNoVirtual() == NULL && layout_ != NULL) delete layout_;
  layout_ = NULL;
}
const ::xla::Layout& Shape::layout() const {
  // @@protoc_insertion_point(field_get:xla.Shape.layout)
  return layout_ != NULL ? *layout_
                         : *::xla::Layout::internal_default_instance();
}
::xla::Layout* Shape::mutable_layout() {
  
  if (layout_ == NULL) {
    layout_ = new ::xla::Layout;
  }
  // @@protoc_insertion_point(field_mutable:xla.Shape.layout)
  return layout_;
}
::xla::Layout* Shape::release_layout() {
  // @@protoc_insertion_point(field_release:xla.Shape.layout)
  
  ::xla::Layout* temp = layout_;
  layout_ = NULL;
  return temp;
}
void Shape::set_allocated_layout(::xla::Layout* layout) {
  delete layout_;
  layout_ = layout;
  if (layout) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:xla.Shape.layout)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// ===================================================================

ProgramShape::ProgramShape()
{
  SharedCtor();
  // @@protoc_insertion_point(constructor:xla.ProgramShape)
}

ProgramShape::ProgramShape(const ProgramShape& from)
  :
      parameters_(from.parameters_),
      parameter_names_(from.parameter_names_),
      _cached_size_(0)
{
  if (from.has_result()) {
    result_ = new ::xla::Shape(*from.result_);
  } else {
    result_ = NULL;
  }
  // @@protoc_insertion_point(copy_constructor:xla.ProgramShape)
}

void ProgramShape::SharedCtor() {
  result_ = NULL;
  _cached_size_ = 0;
}

ProgramShape::~ProgramShape() {
  // @@protoc_insertion_point(destructor:xla.ProgramShape)
  SharedDtor();
}

void ProgramShape::SharedDtor() {
  if (this != internal_default_instance()) {
    delete result_;
  }
}

void ProgramShape::SetCachedSize(int size) const {
  //GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  //GOOGLE_SAFE_CONCURRENT_WRITES_END();
}


const ProgramShape& ProgramShape::default_instance() {
  //protobuf_xla_5fdata_2eproto::InitDefaults();
  return *internal_default_instance();
}

ProgramShape* ProgramShape::New(::google::protobuf::Arena* arena) const {
  ProgramShape* n = new ProgramShape;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void ProgramShape::Clear() {
// @@protoc_insertion_point(message_clear_start:xla.ProgramShape)
  parameters_.Clear();
  parameter_names_.Clear();
  if (GetArenaNoVirtual() == NULL && result_ != NULL) {
    delete result_;
  }
  result_ = NULL;
}


void ProgramShape::MergeFrom(const ProgramShape& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:xla.ProgramShape)
  GOOGLE_DCHECK_NE(&from, this);
  tensorflow::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  parameters_.MergeFrom(from.parameters_);
  parameter_names_.MergeFrom(from.parameter_names_);
  if (from.has_result()) {
    mutable_result()->::xla::Shape::MergeFrom(from.result());
  }
}


void ProgramShape::CopyFrom(const ProgramShape& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:xla.ProgramShape)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ProgramShape::IsInitialized() const {
  return true;
}

void ProgramShape::Swap(ProgramShape* other) {
  if (other == this) return;
  InternalSwap(other);
}
void ProgramShape::InternalSwap(ProgramShape* other) {
  parameters_.InternalSwap(&other->parameters_);
  parameter_names_.InternalSwap(&other->parameter_names_);
  std::swap(result_, other->result_);
  std::swap(_cached_size_, other->_cached_size_);
}


#if PROTOBUF_INLINE_NOT_IN_HEADERS
// ProgramShape

int ProgramShape::parameters_size() const {
  return parameters_.size();
}
void ProgramShape::clear_parameters() {
  parameters_.Clear();
}
const ::xla::Shape& ProgramShape::parameters(int index) const {
  // @@protoc_insertion_point(field_get:xla.ProgramShape.parameters)
  return parameters_.Get(index);
}
::xla::Shape* ProgramShape::mutable_parameters(int index) {
  // @@protoc_insertion_point(field_mutable:xla.ProgramShape.parameters)
  return parameters_.Mutable(index);
}
::xla::Shape* ProgramShape::add_parameters() {
  // @@protoc_insertion_point(field_add:xla.ProgramShape.parameters)
  return parameters_.Add();
}
::google::protobuf::RepeatedPtrField< ::xla::Shape >*
ProgramShape::mutable_parameters() {
  // @@protoc_insertion_point(field_mutable_list:xla.ProgramShape.parameters)
  return &parameters_;
}
const ::google::protobuf::RepeatedPtrField< ::xla::Shape >&
ProgramShape::parameters() const {
  // @@protoc_insertion_point(field_list:xla.ProgramShape.parameters)
  return parameters_;
}

bool ProgramShape::has_result() const {
  return this != internal_default_instance() && result_ != NULL;
}
void ProgramShape::clear_result() {
  if (GetArenaNoVirtual() == NULL && result_ != NULL) delete result_;
  result_ = NULL;
}
const ::xla::Shape& ProgramShape::result() const {
  // @@protoc_insertion_point(field_get:xla.ProgramShape.result)
  return result_ != NULL ? *result_
                         : *::xla::Shape::internal_default_instance();
}
::xla::Shape* ProgramShape::mutable_result() {
  
  if (result_ == NULL) {
    result_ = new ::xla::Shape;
  }
  // @@protoc_insertion_point(field_mutable:xla.ProgramShape.result)
  return result_;
}
::xla::Shape* ProgramShape::release_result() {
  // @@protoc_insertion_point(field_release:xla.ProgramShape.result)
  
  ::xla::Shape* temp = result_;
  result_ = NULL;
  return temp;
}
void ProgramShape::set_allocated_result(::xla::Shape* result) {
  delete result_;
  result_ = result;
  if (result) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:xla.ProgramShape.result)
}

int ProgramShape::parameter_names_size() const {
  return parameter_names_.size();
}
void ProgramShape::clear_parameter_names() {
  parameter_names_.Clear();
}
const ::std::string& ProgramShape::parameter_names(int index) const {
  // @@protoc_insertion_point(field_get:xla.ProgramShape.parameter_names)
  return parameter_names_.Get(index);
}
::std::string* ProgramShape::mutable_parameter_names(int index) {
  // @@protoc_insertion_point(field_mutable:xla.ProgramShape.parameter_names)
  return parameter_names_.Mutable(index);
}
void ProgramShape::set_parameter_names(int index, const ::std::string& value) {
  // @@protoc_insertion_point(field_set:xla.ProgramShape.parameter_names)
  parameter_names_.Mutable(index)->assign(value);
}
#if LANG_CXX11
void ProgramShape::set_parameter_names(int index, ::std::string&& value) {
  // @@protoc_insertion_point(field_set:xla.ProgramShape.parameter_names)
  parameter_names_.Mutable(index)->assign(std::move(value));
}
#endif
void ProgramShape::set_parameter_names(int index, const char* value) {
  GOOGLE_DCHECK(value != NULL);
  parameter_names_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:xla.ProgramShape.parameter_names)
}
void ProgramShape::set_parameter_names(int index, const char* value, size_t size) {
  parameter_names_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:xla.ProgramShape.parameter_names)
}
::std::string* ProgramShape::add_parameter_names() {
  // @@protoc_insertion_point(field_add_mutable:xla.ProgramShape.parameter_names)
  return parameter_names_.Add();
}
void ProgramShape::add_parameter_names(const ::std::string& value) {
  parameter_names_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:xla.ProgramShape.parameter_names)
}
#if LANG_CXX11
void ProgramShape::add_parameter_names(::std::string&& value) {
  parameter_names_.Add(std::move(value));
  // @@protoc_insertion_point(field_add:xla.ProgramShape.parameter_names)
}
#endif
void ProgramShape::add_parameter_names(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  parameter_names_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:xla.ProgramShape.parameter_names)
}
void ProgramShape::add_parameter_names(const char* value, size_t size) {
  parameter_names_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:xla.ProgramShape.parameter_names)
}
const ::google::protobuf::RepeatedPtrField< ::std::string>&
ProgramShape::parameter_names() const {
  // @@protoc_insertion_point(field_list:xla.ProgramShape.parameter_names)
  return parameter_names_;
}
::google::protobuf::RepeatedPtrField< ::std::string>*
ProgramShape::mutable_parameter_names() {
  // @@protoc_insertion_point(field_mutable_list:xla.ProgramShape.parameter_names)
  return &parameter_names_;
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// ===================================================================

ComputationHandle::ComputationHandle()
{
  SharedCtor();
  // @@protoc_insertion_point(constructor:xla.ComputationHandle)
}

ComputationHandle::ComputationHandle(const ComputationHandle& from)
{
  handle_ = from.handle_;
  // @@protoc_insertion_point(copy_constructor:xla.ComputationHandle)
}

void ComputationHandle::SharedCtor() {
  handle_ = GOOGLE_LONGLONG(0);
  _cached_size_ = 0;
}

ComputationHandle::~ComputationHandle() {
  // @@protoc_insertion_point(destructor:xla.ComputationHandle)
  SharedDtor();
}

void ComputationHandle::SharedDtor() 
{
}

const ComputationHandle& ComputationHandle::default_instance() 
{
  //protobuf_xla_5fdata_2eproto::InitDefaults();
  return *internal_default_instance();
}

ComputationHandle* ComputationHandle::New(::google::protobuf::Arena* arena) const 
{
  ComputationHandle* n = new ComputationHandle;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void ComputationHandle::Clear() {
// @@protoc_insertion_point(message_clear_start:xla.ComputationHandle)
  handle_ = GOOGLE_LONGLONG(0);
}

void ComputationHandle::MergeFrom(const ComputationHandle& from) 
{
// @@protoc_insertion_point(class_specific_merge_from_start:xla.ComputationHandle)
  GOOGLE_DCHECK_NE(&from, this);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.handle() != 0) {
    set_handle(from.handle());
  }
}

void ComputationHandle::CopyFrom(const ComputationHandle& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:xla.ComputationHandle)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ComputationHandle::IsInitialized() const {
  return true;
}

void ComputationHandle::Swap(ComputationHandle* other) {
  if (other == this) return;
  InternalSwap(other);
}
void ComputationHandle::InternalSwap(ComputationHandle* other) {
  std::swap(handle_, other->handle_);
  std::swap(_cached_size_, other->_cached_size_);
}


#if PROTOBUF_INLINE_NOT_IN_HEADERS
// ComputationHandle

void ComputationHandle::clear_handle() {
  handle_ = GOOGLE_LONGLONG(0);
}
::google::protobuf::int64 ComputationHandle::handle() const {
  // @@protoc_insertion_point(field_get:xla.ComputationHandle.handle)
  return handle_;
}
void ComputationHandle::set_handle(::google::protobuf::int64 value) {
  
  handle_ = value;
  // @@protoc_insertion_point(field_set:xla.ComputationHandle.handle)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS
// ===================================================================

GlobalDataHandle::GlobalDataHandle()
{
   SharedCtor();
   // @@protoc_insertion_point(constructor:xla.GlobalDataHandle)
}

GlobalDataHandle::GlobalDataHandle(const GlobalDataHandle& from)
   : _cached_size_(0) 
{
   handle_ = from.handle_;
   // @@protoc_insertion_point(copy_constructor:xla.GlobalDataHandle)
}

void GlobalDataHandle::SharedCtor() 
{
   handle_ = GOOGLE_LONGLONG(0);
   _cached_size_ = 0;
}

GlobalDataHandle::~GlobalDataHandle()
{
   // @@protoc_insertion_point(destructor:xla.GlobalDataHandle)
   SharedDtor();
}

void GlobalDataHandle::SharedDtor() 
{
}

void GlobalDataHandle::SetCachedSize(int size) const 
{
   //GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
   _cached_size_ = size;
   //GOOGLE_SAFE_CONCURRENT_WRITES_END();
}

const GlobalDataHandle& GlobalDataHandle::default_instance() 
{
   //protobuf_xla_5fdata_2eproto::InitDefaults();
   return *internal_default_instance();
}

GlobalDataHandle* GlobalDataHandle::New(::google::protobuf::Arena* arena) const {
   GlobalDataHandle* n = new GlobalDataHandle;
   if (arena != NULL) {
      arena->Own(n);
   }
   return n;
}

void GlobalDataHandle::Clear() 
{
   // @@protoc_insertion_point(message_clear_start:xla.GlobalDataHandle)
   handle_ = GOOGLE_LONGLONG(0);
}

void GlobalDataHandle::MergeFrom(const GlobalDataHandle& from) 
{
   // @@protoc_insertion_point(class_specific_merge_from_start:xla.GlobalDataHandle)
   GOOGLE_DCHECK_NE(&from, this);
   ::google::protobuf::uint32 cached_has_bits = 0;
   (void)cached_has_bits;

   if (from.handle() != 0) {
      set_handle(from.handle());
   }
}

//void GlobalDataHandle::CopyFrom(const ::google::protobuf::Message& from) {
//   // @@protoc_insertion_point(generalized_copy_from_start:xla.GlobalDataHandle)
//   if (&from == this) return;
//   Clear();
//   MergeFrom(from);
//}

void GlobalDataHandle::CopyFrom(const GlobalDataHandle& from) {
   // @@protoc_insertion_point(class_specific_copy_from_start:xla.GlobalDataHandle)
   if (&from == this) return;
   Clear();
   MergeFrom(from);
}

bool GlobalDataHandle::IsInitialized() const {
   return true;
}

void GlobalDataHandle::Swap(GlobalDataHandle* other) {
   if (other == this) return;
   InternalSwap(other);
}
void GlobalDataHandle::InternalSwap(GlobalDataHandle* other) {
   std::swap(handle_, other->handle_);
   std::swap(_cached_size_, other->_cached_size_);
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// GlobalDataHandle

void GlobalDataHandle::clear_handle() {
   handle_ = GOOGLE_LONGLONG(0);
}
::google::protobuf::int64 GlobalDataHandle::handle() const {
   // @@protoc_insertion_point(field_get:xla.GlobalDataHandle.handle)
   return handle_;
}
void GlobalDataHandle::set_handle(::google::protobuf::int64 value) {

   handle_ = value;
   // @@protoc_insertion_point(field_set:xla.GlobalDataHandle.handle)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// ===================================================================

ComputationDataHandle::ComputationDataHandle()
{
  SharedCtor();
  // @@protoc_insertion_point(constructor:xla.ComputationDataHandle)
}
ComputationDataHandle::ComputationDataHandle(const ComputationDataHandle& from)
  : _cached_size_(0)
{
  handle_ = from.handle_;
  // @@protoc_insertion_point(copy_constructor:xla.ComputationDataHandle)
}

void ComputationDataHandle::SharedCtor() {
  handle_ = GOOGLE_LONGLONG(0);
  _cached_size_ = 0;
}

ComputationDataHandle::~ComputationDataHandle()
{
  // @@protoc_insertion_point(destructor:xla.ComputationDataHandle)
  SharedDtor();
}

void ComputationDataHandle::SharedDtor() {
}

void ComputationDataHandle::SetCachedSize(int size) const {
  //GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  //GOOGLE_SAFE_CONCURRENT_WRITES_END();
}

const ComputationDataHandle& ComputationDataHandle::default_instance() {
  //protobuf_xla_5fdata_2eproto::InitDefaults();
  return *internal_default_instance();
}

ComputationDataHandle* ComputationDataHandle::New(::google::protobuf::Arena* arena) const {
  ComputationDataHandle* n = new ComputationDataHandle;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void ComputationDataHandle::Clear() {
// @@protoc_insertion_point(message_clear_start:xla.ComputationDataHandle)
  handle_ = GOOGLE_LONGLONG(0);
}


void ComputationDataHandle::MergeFrom(const ComputationDataHandle& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:xla.ComputationDataHandle)
  GOOGLE_DCHECK_NE(&from, this);
  tensorflow::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.handle() != 0) {
    set_handle(from.handle());
  }
}


void ComputationDataHandle::CopyFrom(const ComputationDataHandle& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:xla.ComputationDataHandle)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ComputationDataHandle::IsInitialized() const {
  return true;
}

void ComputationDataHandle::Swap(ComputationDataHandle* other) {
  if (other == this) return;
  InternalSwap(other);
}

void ComputationDataHandle::InternalSwap(ComputationDataHandle* other) {
  std::swap(handle_, other->handle_);
  std::swap(_cached_size_, other->_cached_size_);
}


#if PROTOBUF_INLINE_NOT_IN_HEADERS
// ComputationDataHandle

void ComputationDataHandle::clear_handle() {
  handle_ = GOOGLE_LONGLONG(0);
}
tensorflow::int64 ComputationDataHandle::handle() const {
  // @@protoc_insertion_point(field_get:xla.ComputationDataHandle.handle)
  return handle_;
}
void ComputationDataHandle::set_handle(tensorflow::int64 value) {
  
  handle_ = value;
  // @@protoc_insertion_point(field_set:xla.ComputationDataHandle.handle)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS


Literal::Literal()
{
  SharedCtor();
  // @@protoc_insertion_point(constructor:xla.Literal)
}

Literal::Literal(const Literal& from)
  : 
      preds_(from.preds_),
      s32s_(from.s32s_),
      s64s_(from.s64s_),
      u32s_(from.u32s_),
      u64s_(from.u64s_),
      f32s_(from.f32s_),
      f64s_(from.f64s_),
      tuple_literals_(from.tuple_literals_),
      _cached_size_(0)
{
  u8s_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.u8s().size() > 0) {
    u8s_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.u8s_);
  }
  if (from.has_shape()) {
    shape_ = new ::xla::Shape(*from.shape_);
  } else {
    shape_ = NULL;
  }
  // @@protoc_insertion_point(copy_constructor:xla.Literal)
}

void Literal::SharedCtor() {
  u8s_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  shape_ = NULL;
  _cached_size_ = 0;
}

Literal::~Literal() {
  // @@protoc_insertion_point(destructor:xla.Literal)
  SharedDtor();
}

void Literal::SharedDtor() {
  u8s_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (this != internal_default_instance()) {
    delete shape_;
  }
}

void Literal::SetCachedSize(int size) const {
  //GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  //GOOGLE_SAFE_CONCURRENT_WRITES_END();
}

const Literal& Literal::default_instance() {
  //protobuf_xla_5fdata_2eproto::InitDefaults();
  return *internal_default_instance();
}

Literal* Literal::New(::google::protobuf::Arena* arena) const {
  Literal* n = new Literal;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void Literal::Clear() {
// @@protoc_insertion_point(message_clear_start:xla.Literal)
  preds_.Clear();
  s32s_.Clear();
  s64s_.Clear();
  u32s_.Clear();
  u64s_.Clear();
  f32s_.Clear();
  f64s_.Clear();
  tuple_literals_.Clear();
  u8s_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (GetArenaNoVirtual() == NULL && shape_ != NULL) {
    delete shape_;
  }
  shape_ = NULL;
}


void Literal::MergeFrom(const Literal& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:xla.Literal)
  GOOGLE_DCHECK_NE(&from, this);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  preds_.MergeFrom(from.preds_);
  s32s_.MergeFrom(from.s32s_);
  s64s_.MergeFrom(from.s64s_);
  u32s_.MergeFrom(from.u32s_);
  u64s_.MergeFrom(from.u64s_);
  f32s_.MergeFrom(from.f32s_);
  f64s_.MergeFrom(from.f64s_);
  tuple_literals_.MergeFrom(from.tuple_literals_);
  if (from.u8s().size() > 0) {

    u8s_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.u8s_);
  }
  if (from.has_shape()) {
    mutable_shape()->::xla::Shape::MergeFrom(from.shape());
  }
}

//void Literal::CopyFrom(const ::google::protobuf::Message& from) {
//// @@protoc_insertion_point(generalized_copy_from_start:xla.Literal)
//  if (&from == this) return;
//  Clear();
//  MergeFrom(from);
//}

void Literal::CopyFrom(const Literal& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Literal::IsInitialized() const {
  return true;
}

void Literal::Swap(Literal* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Literal::InternalSwap(Literal* other) {
  preds_.InternalSwap(&other->preds_);
  s32s_.InternalSwap(&other->s32s_);
  s64s_.InternalSwap(&other->s64s_);
  u32s_.InternalSwap(&other->u32s_);
  u64s_.InternalSwap(&other->u64s_);
  f32s_.InternalSwap(&other->f32s_);
  f64s_.InternalSwap(&other->f64s_);
  tuple_literals_.InternalSwap(&other->tuple_literals_);
  u8s_.Swap(&other->u8s_);
  std::swap(shape_, other->shape_);
  std::swap(_cached_size_, other->_cached_size_);
}


#if PROTOBUF_INLINE_NOT_IN_HEADERS
// Literal

bool Literal::has_shape() const {
  return this != internal_default_instance() && shape_ != NULL;
}
void Literal::clear_shape() {
  if (GetArenaNoVirtual() == NULL && shape_ != NULL) delete shape_;
  shape_ = NULL;
}
const ::xla::Shape& Literal::shape() const {
  // @@protoc_insertion_point(field_get:xla.Literal.shape)
  return shape_ != NULL ? *shape_
                         : *::xla::Shape::internal_default_instance();
}
::xla::Shape* Literal::mutable_shape() {
  
  if (shape_ == NULL) {
    shape_ = new ::xla::Shape;
  }
  // @@protoc_insertion_point(field_mutable:xla.Literal.shape)
  return shape_;
}
::xla::Shape* Literal::release_shape() {
  // @@protoc_insertion_point(field_release:xla.Literal.shape)
  
  ::xla::Shape* temp = shape_;
  shape_ = NULL;
  return temp;
}
void Literal::set_allocated_shape(::xla::Shape* shape) {
  delete shape_;
  shape_ = shape;
  if (shape) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:xla.Literal.shape)
}

int Literal::preds_size() const {
  return preds_.size();
}
void Literal::clear_preds() {
  preds_.Clear();
}
bool Literal::preds(int index) const {
  // @@protoc_insertion_point(field_get:xla.Literal.preds)
  return preds_.Get(index);
}
void Literal::set_preds(int index, bool value) {
  preds_.Set(index, value);
  // @@protoc_insertion_point(field_set:xla.Literal.preds)
}
void Literal::add_preds(bool value) {
  preds_.Add(value);
  // @@protoc_insertion_point(field_add:xla.Literal.preds)
}
const ::google::protobuf::RepeatedField< bool >&
Literal::preds() const {
  // @@protoc_insertion_point(field_list:xla.Literal.preds)
  return preds_;
}
::google::protobuf::RepeatedField< bool >*
Literal::mutable_preds() {
  // @@protoc_insertion_point(field_mutable_list:xla.Literal.preds)
  return &preds_;
}

void Literal::clear_u8s() {
  u8s_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
const ::std::string& Literal::u8s() const {
  // @@protoc_insertion_point(field_get:xla.Literal.u8s)
  return u8s_.GetNoArena();
}
void Literal::set_u8s(const ::std::string& value) {
  
  u8s_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:xla.Literal.u8s)
}
#if LANG_CXX11
void Literal::set_u8s(::std::string&& value) {
  
  u8s_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:xla.Literal.u8s)
}
#endif
void Literal::set_u8s(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  u8s_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:xla.Literal.u8s)
}
void Literal::set_u8s(const void* value, size_t size) {
  
  u8s_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:xla.Literal.u8s)
}
::std::string* Literal::mutable_u8s() {
  
  // @@protoc_insertion_point(field_mutable:xla.Literal.u8s)
  return u8s_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
::std::string* Literal::release_u8s() {
  // @@protoc_insertion_point(field_release:xla.Literal.u8s)
  
  return u8s_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
void Literal::set_allocated_u8s(::std::string* u8s) {
  if (u8s != NULL) {
    
  } else {
    
  }
  u8s_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), u8s);
  // @@protoc_insertion_point(field_set_allocated:xla.Literal.u8s)
}

int Literal::s32s_size() const {
  return s32s_.size();
}
void Literal::clear_s32s() {
  s32s_.Clear();
}
::google::protobuf::int32 Literal::s32s(int index) const {
  // @@protoc_insertion_point(field_get:xla.Literal.s32s)
  return s32s_.Get(index);
}
void Literal::set_s32s(int index, ::google::protobuf::int32 value) {
  s32s_.Set(index, value);
  // @@protoc_insertion_point(field_set:xla.Literal.s32s)
}
void Literal::add_s32s(::google::protobuf::int32 value) {
  s32s_.Add(value);
  // @@protoc_insertion_point(field_add:xla.Literal.s32s)
}
const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
Literal::s32s() const {
  // @@protoc_insertion_point(field_list:xla.Literal.s32s)
  return s32s_;
}
::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
Literal::mutable_s32s() {
  // @@protoc_insertion_point(field_mutable_list:xla.Literal.s32s)
  return &s32s_;
}

int Literal::s64s_size() const {
  return s64s_.size();
}
void Literal::clear_s64s() {
  s64s_.Clear();
}
::google::protobuf::int64 Literal::s64s(int index) const {
  // @@protoc_insertion_point(field_get:xla.Literal.s64s)
  return s64s_.Get(index);
}
void Literal::set_s64s(int index, ::google::protobuf::int64 value) {
  s64s_.Set(index, value);
  // @@protoc_insertion_point(field_set:xla.Literal.s64s)
}
void Literal::add_s64s(::google::protobuf::int64 value) {
  s64s_.Add(value);
  // @@protoc_insertion_point(field_add:xla.Literal.s64s)
}
const ::google::protobuf::RepeatedField< ::google::protobuf::int64 >&
Literal::s64s() const {
  // @@protoc_insertion_point(field_list:xla.Literal.s64s)
  return s64s_;
}
::google::protobuf::RepeatedField< ::google::protobuf::int64 >*
Literal::mutable_s64s() {
  // @@protoc_insertion_point(field_mutable_list:xla.Literal.s64s)
  return &s64s_;
}

int Literal::u32s_size() const {
  return u32s_.size();
}
void Literal::clear_u32s() {
  u32s_.Clear();
}
::google::protobuf::uint32 Literal::u32s(int index) const {
  // @@protoc_insertion_point(field_get:xla.Literal.u32s)
  return u32s_.Get(index);
}
void Literal::set_u32s(int index, ::google::protobuf::uint32 value) {
  u32s_.Set(index, value);
  // @@protoc_insertion_point(field_set:xla.Literal.u32s)
}
void Literal::add_u32s(::google::protobuf::uint32 value) {
  u32s_.Add(value);
  // @@protoc_insertion_point(field_add:xla.Literal.u32s)
}
const ::google::protobuf::RepeatedField< ::google::protobuf::uint32 >&
Literal::u32s() const {
  // @@protoc_insertion_point(field_list:xla.Literal.u32s)
  return u32s_;
}
::google::protobuf::RepeatedField< ::google::protobuf::uint32 >*
Literal::mutable_u32s() {
  // @@protoc_insertion_point(field_mutable_list:xla.Literal.u32s)
  return &u32s_;
}

int Literal::u64s_size() const {
  return u64s_.size();
}
void Literal::clear_u64s() {
  u64s_.Clear();
}
::google::protobuf::uint64 Literal::u64s(int index) const {
  // @@protoc_insertion_point(field_get:xla.Literal.u64s)
  return u64s_.Get(index);
}
void Literal::set_u64s(int index, ::google::protobuf::uint64 value) {
  u64s_.Set(index, value);
  // @@protoc_insertion_point(field_set:xla.Literal.u64s)
}
void Literal::add_u64s(::google::protobuf::uint64 value) {
  u64s_.Add(value);
  // @@protoc_insertion_point(field_add:xla.Literal.u64s)
}
const ::google::protobuf::RepeatedField< ::google::protobuf::uint64 >&
Literal::u64s() const {
  // @@protoc_insertion_point(field_list:xla.Literal.u64s)
  return u64s_;
}
::google::protobuf::RepeatedField< ::google::protobuf::uint64 >*
Literal::mutable_u64s() {
  // @@protoc_insertion_point(field_mutable_list:xla.Literal.u64s)
  return &u64s_;
}

int Literal::f32s_size() const {
  return f32s_.size();
}
void Literal::clear_f32s() {
  f32s_.Clear();
}
float Literal::f32s(int index) const {
  // @@protoc_insertion_point(field_get:xla.Literal.f32s)
  return f32s_.Get(index);
}
void Literal::set_f32s(int index, float value) {
  f32s_.Set(index, value);
  // @@protoc_insertion_point(field_set:xla.Literal.f32s)
}
void Literal::add_f32s(float value) {
  f32s_.Add(value);
  // @@protoc_insertion_point(field_add:xla.Literal.f32s)
}
const ::google::protobuf::RepeatedField< float >&
Literal::f32s() const {
  // @@protoc_insertion_point(field_list:xla.Literal.f32s)
  return f32s_;
}
::google::protobuf::RepeatedField< float >*
Literal::mutable_f32s() {
  // @@protoc_insertion_point(field_mutable_list:xla.Literal.f32s)
  return &f32s_;
}

int Literal::f64s_size() const {
  return f64s_.size();
}
void Literal::clear_f64s() {
  f64s_.Clear();
}
double Literal::f64s(int index) const {
  // @@protoc_insertion_point(field_get:xla.Literal.f64s)
  return f64s_.Get(index);
}
void Literal::set_f64s(int index, double value) {
  f64s_.Set(index, value);
  // @@protoc_insertion_point(field_set:xla.Literal.f64s)
}
void Literal::add_f64s(double value) {
  f64s_.Add(value);
  // @@protoc_insertion_point(field_add:xla.Literal.f64s)
}
const ::google::protobuf::RepeatedField< double >&
Literal::f64s() const {
  // @@protoc_insertion_point(field_list:xla.Literal.f64s)
  return f64s_;
}
::google::protobuf::RepeatedField< double >*
Literal::mutable_f64s() {
  // @@protoc_insertion_point(field_mutable_list:xla.Literal.f64s)
  return &f64s_;
}

int Literal::tuple_literals_size() const {
  return tuple_literals_.size();
}
void Literal::clear_tuple_literals() {
  tuple_literals_.Clear();
}
const ::xla::Literal& Literal::tuple_literals(int index) const {
  // @@protoc_insertion_point(field_get:xla.Literal.tuple_literals)
  return tuple_literals_.Get(index);
}
::xla::Literal* Literal::mutable_tuple_literals(int index) {
  // @@protoc_insertion_point(field_mutable:xla.Literal.tuple_literals)
  return tuple_literals_.Mutable(index);
}
::xla::Literal* Literal::add_tuple_literals() {
  // @@protoc_insertion_point(field_add:xla.Literal.tuple_literals)
  return tuple_literals_.Add();
}
::google::protobuf::RepeatedPtrField< ::xla::Literal >*
Literal::mutable_tuple_literals() {
  // @@protoc_insertion_point(field_mutable_list:xla.Literal.tuple_literals)
  return &tuple_literals_;
}
const ::google::protobuf::RepeatedPtrField< ::xla::Literal >&
Literal::tuple_literals() const {
  // @@protoc_insertion_point(field_list:xla.Literal.tuple_literals)
  return tuple_literals_;
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS


// ===================================================================

WindowDimension::WindowDimension()
{
  SharedCtor();
  // @@protoc_insertion_point(constructor:xla.WindowDimension)
}

WindowDimension::WindowDimension(const WindowDimension& from)
  : _cached_size_(0)
{
  ::memcpy(&size_, &from.size_,
    reinterpret_cast<char*>(&base_dilation_) -
    reinterpret_cast<char*>(&size_) + sizeof(base_dilation_));
  // @@protoc_insertion_point(copy_constructor:xla.WindowDimension)
}

void WindowDimension::SharedCtor() {
  ::memset(&size_, 0, reinterpret_cast<char*>(&base_dilation_) -
    reinterpret_cast<char*>(&size_) + sizeof(base_dilation_));
  _cached_size_ = 0;
}

WindowDimension::~WindowDimension() {
  // @@protoc_insertion_point(destructor:xla.WindowDimension)
  SharedDtor();
}

void WindowDimension::SharedDtor() {
}

void WindowDimension::SetCachedSize(int size) const {
  //GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  //GOOGLE_SAFE_CONCURRENT_WRITES_END();
}


const WindowDimension& WindowDimension::default_instance() {
  //protobuf_xla_5fdata_2eproto::InitDefaults();
  return *internal_default_instance();
}

WindowDimension* WindowDimension::New(::google::protobuf::Arena* arena) const {
  WindowDimension* n = new WindowDimension;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void WindowDimension::Clear() {
// @@protoc_insertion_point(message_clear_start:xla.WindowDimension)
  ::memset(&size_, 0, reinterpret_cast<char*>(&base_dilation_) -
    reinterpret_cast<char*>(&size_) + sizeof(base_dilation_));
}

void WindowDimension::MergeFrom(const WindowDimension& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:xla.WindowDimension)
  GOOGLE_DCHECK_NE(&from, this);
  tensorflow::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.size() != 0) {
    set_size(from.size());
  }
  if (from.stride() != 0) {
    set_stride(from.stride());
  }
  if (from.padding_low() != 0) {
    set_padding_low(from.padding_low());
  }
  if (from.padding_high() != 0) {
    set_padding_high(from.padding_high());
  }
  if (from.window_dilation() != 0) {
    set_window_dilation(from.window_dilation());
  }
  if (from.base_dilation() != 0) {
    set_base_dilation(from.base_dilation());
  }
}


void WindowDimension::CopyFrom(const WindowDimension& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:xla.WindowDimension)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool WindowDimension::IsInitialized() const {
  return true;
}

void WindowDimension::Swap(WindowDimension* other) {
  if (other == this) return;
  InternalSwap(other);
}

void WindowDimension::InternalSwap(WindowDimension* other) {
  std::swap(size_, other->size_);
  std::swap(stride_, other->stride_);
  std::swap(padding_low_, other->padding_low_);
  std::swap(padding_high_, other->padding_high_);
  std::swap(window_dilation_, other->window_dilation_);
  std::swap(base_dilation_, other->base_dilation_);
  std::swap(_cached_size_, other->_cached_size_);
}


#if PROTOBUF_INLINE_NOT_IN_HEADERS
// WindowDimension

void WindowDimension::clear_size() {
  size_ = GOOGLE_LONGLONG(0);
}
tensorflow::int64 WindowDimension::size() const {
  // @@protoc_insertion_point(field_get:xla.WindowDimension.size)
  return size_;
}
void WindowDimension::set_size(tensorflow::int64 value) {
  
  size_ = value;
  // @@protoc_insertion_point(field_set:xla.WindowDimension.size)
}

void WindowDimension::clear_stride() {
  stride_ = GOOGLE_LONGLONG(0);
}
tensorflow::int64 WindowDimension::stride() const {
  // @@protoc_insertion_point(field_get:xla.WindowDimension.stride)
  return stride_;
}
void WindowDimension::set_stride(tensorflow::int64 value) {
  
  stride_ = value;
  // @@protoc_insertion_point(field_set:xla.WindowDimension.stride)
}

void WindowDimension::clear_padding_low() {
  padding_low_ = GOOGLE_LONGLONG(0);
}
tensorflow::int64 WindowDimension::padding_low() const {
  // @@protoc_insertion_point(field_get:xla.WindowDimension.padding_low)
  return padding_low_;
}
void WindowDimension::set_padding_low(tensorflow::int64 value) {
  
  padding_low_ = value;
  // @@protoc_insertion_point(field_set:xla.WindowDimension.padding_low)
}

void WindowDimension::clear_padding_high() {
  padding_high_ = GOOGLE_LONGLONG(0);
}
tensorflow::int64 WindowDimension::padding_high() const {
  // @@protoc_insertion_point(field_get:xla.WindowDimension.padding_high)
  return padding_high_;
}
void WindowDimension::set_padding_high(tensorflow::int64 value) {
  
  padding_high_ = value;
  // @@protoc_insertion_point(field_set:xla.WindowDimension.padding_high)
}

void WindowDimension::clear_window_dilation() {
  window_dilation_ = GOOGLE_LONGLONG(0);
}
tensorflow::int64 WindowDimension::window_dilation() const {
  // @@protoc_insertion_point(field_get:xla.WindowDimension.window_dilation)
  return window_dilation_;
}
void WindowDimension::set_window_dilation(tensorflow::int64 value) {
  
  window_dilation_ = value;
  // @@protoc_insertion_point(field_set:xla.WindowDimension.window_dilation)
}

void WindowDimension::clear_base_dilation() {
  base_dilation_ = GOOGLE_LONGLONG(0);
}
tensorflow::int64 WindowDimension::base_dilation() const {
  // @@protoc_insertion_point(field_get:xla.WindowDimension.base_dilation)
  return base_dilation_;
}
void WindowDimension::set_base_dilation(tensorflow::int64 value) {
  
  base_dilation_ = value;
  // @@protoc_insertion_point(field_set:xla.WindowDimension.base_dilation)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// ===================================================================

Window::Window()
{
  SharedCtor();
  // @@protoc_insertion_point(constructor:xla.Window)
}

Window::Window(const Window& from)
   :
      dimensions_(from.dimensions_),
      _cached_size_(0)
{
  // @@protoc_insertion_point(copy_constructor:xla.Window)
}

void Window::SharedCtor() {
  _cached_size_ = 0;
}

Window::~Window() {
  // @@protoc_insertion_point(destructor:xla.Window)
  SharedDtor();
}

void Window::SharedDtor() {
}

void Window::SetCachedSize(int size) const {
  //GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  //GOOGLE_SAFE_CONCURRENT_WRITES_END();
}


const Window& Window::default_instance() {
  //protobuf_xla_5fdata_2eproto::InitDefaults();
  return *internal_default_instance();
}

Window* Window::New(::google::protobuf::Arena* arena) const {
  Window* n = new Window;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void Window::Clear() {
// @@protoc_insertion_point(message_clear_start:xla.Window)
  dimensions_.Clear();
}


void Window::MergeFrom(const Window& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:xla.Window)
  GOOGLE_DCHECK_NE(&from, this);
  tensorflow::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  dimensions_.MergeFrom(from.dimensions_);
}


void Window::CopyFrom(const Window& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:xla.Window)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Window::IsInitialized() const {
  return true;
}

void Window::Swap(Window* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Window::InternalSwap(Window* other) {
  dimensions_.InternalSwap(&other->dimensions_);
  std::swap(_cached_size_, other->_cached_size_);
}


#if PROTOBUF_INLINE_NOT_IN_HEADERS
// Window

int Window::dimensions_size() const {
  return dimensions_.size();
}
void Window::clear_dimensions() {
  dimensions_.Clear();
}
const ::xla::WindowDimension& Window::dimensions(int index) const {
  // @@protoc_insertion_point(field_get:xla.Window.dimensions)
  return dimensions_.Get(index);
}
::xla::WindowDimension* Window::mutable_dimensions(int index) {
  // @@protoc_insertion_point(field_mutable:xla.Window.dimensions)
  return dimensions_.Mutable(index);
}
::xla::WindowDimension* Window::add_dimensions() {
  // @@protoc_insertion_point(field_add:xla.Window.dimensions)
  return dimensions_.Add();
}
::google::protobuf::RepeatedPtrField< ::xla::WindowDimension >*
Window::mutable_dimensions() {
  // @@protoc_insertion_point(field_mutable_list:xla.Window.dimensions)
  return &dimensions_;
}
const ::google::protobuf::RepeatedPtrField< ::xla::WindowDimension >&
Window::dimensions() const {
  // @@protoc_insertion_point(field_list:xla.Window.dimensions)
  return dimensions_;
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// ===================================================================

ConvolutionDimensionNumbers::ConvolutionDimensionNumbers()
{
  SharedCtor();
  // @@protoc_insertion_point(constructor:xla.ConvolutionDimensionNumbers)
}

ConvolutionDimensionNumbers::ConvolutionDimensionNumbers(const ConvolutionDimensionNumbers& from)
   :
      spatial_dimensions_(from.spatial_dimensions_),
      kernel_spatial_dimensions_(from.kernel_spatial_dimensions_),
      _cached_size_(0) 
{
  ::memcpy(&batch_dimension_, &from.batch_dimension_,
    reinterpret_cast<char*>(&kernel_output_feature_dimension_) -
    reinterpret_cast<char*>(&batch_dimension_) + sizeof(kernel_output_feature_dimension_));
  // @@protoc_insertion_point(copy_constructor:xla.ConvolutionDimensionNumbers)
}

void ConvolutionDimensionNumbers::SharedCtor() {
  ::memset(&batch_dimension_, 0, reinterpret_cast<char*>(&kernel_output_feature_dimension_) -
    reinterpret_cast<char*>(&batch_dimension_) + sizeof(kernel_output_feature_dimension_));
  _cached_size_ = 0;
}

ConvolutionDimensionNumbers::~ConvolutionDimensionNumbers() {
  // @@protoc_insertion_point(destructor:xla.ConvolutionDimensionNumbers)
  SharedDtor();
}

void ConvolutionDimensionNumbers::SharedDtor() {
}

void ConvolutionDimensionNumbers::SetCachedSize(int size) const {
  //GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  //GOOGLE_SAFE_CONCURRENT_WRITES_END();
}


const ConvolutionDimensionNumbers& ConvolutionDimensionNumbers::default_instance() {
  //protobuf_xla_5fdata_2eproto::InitDefaults();
  return *internal_default_instance();
}

ConvolutionDimensionNumbers* ConvolutionDimensionNumbers::New(::google::protobuf::Arena* arena) const {
  ConvolutionDimensionNumbers* n = new ConvolutionDimensionNumbers;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void ConvolutionDimensionNumbers::Clear() {
// @@protoc_insertion_point(message_clear_start:xla.ConvolutionDimensionNumbers)
  spatial_dimensions_.Clear();
  kernel_spatial_dimensions_.Clear();
  ::memset(&batch_dimension_, 0, reinterpret_cast<char*>(&kernel_output_feature_dimension_) -
    reinterpret_cast<char*>(&batch_dimension_) + sizeof(kernel_output_feature_dimension_));
}

void ConvolutionDimensionNumbers::MergeFrom(const ConvolutionDimensionNumbers& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:xla.ConvolutionDimensionNumbers)
  GOOGLE_DCHECK_NE(&from, this);

  tensorflow::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  spatial_dimensions_.MergeFrom(from.spatial_dimensions_);
  kernel_spatial_dimensions_.MergeFrom(from.kernel_spatial_dimensions_);
  if (from.batch_dimension() != 0) {
    set_batch_dimension(from.batch_dimension());
  }
  if (from.feature_dimension() != 0) {
    set_feature_dimension(from.feature_dimension());
  }
  if (from.kernel_input_feature_dimension() != 0) {
    set_kernel_input_feature_dimension(from.kernel_input_feature_dimension());
  }
  if (from.kernel_output_feature_dimension() != 0) {
    set_kernel_output_feature_dimension(from.kernel_output_feature_dimension());
  }
}

void ConvolutionDimensionNumbers::CopyFrom(const ConvolutionDimensionNumbers& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:xla.ConvolutionDimensionNumbers)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ConvolutionDimensionNumbers::IsInitialized() const {
  return true;
}

void ConvolutionDimensionNumbers::Swap(ConvolutionDimensionNumbers* other) {
  if (other == this) return;
  InternalSwap(other);
}

void ConvolutionDimensionNumbers::InternalSwap(ConvolutionDimensionNumbers* other) {
  spatial_dimensions_.InternalSwap(&other->spatial_dimensions_);
  kernel_spatial_dimensions_.InternalSwap(&other->kernel_spatial_dimensions_);
  std::swap(batch_dimension_, other->batch_dimension_);
  std::swap(feature_dimension_, other->feature_dimension_);
  std::swap(kernel_input_feature_dimension_, other->kernel_input_feature_dimension_);
  std::swap(kernel_output_feature_dimension_, other->kernel_output_feature_dimension_);
  std::swap(_cached_size_, other->_cached_size_);
}


#if PROTOBUF_INLINE_NOT_IN_HEADERS
// ConvolutionDimensionNumbers

void ConvolutionDimensionNumbers::clear_batch_dimension() {
  batch_dimension_ = GOOGLE_LONGLONG(0);
}
tensorflow::int64 ConvolutionDimensionNumbers::batch_dimension() const {
  // @@protoc_insertion_point(field_get:xla.ConvolutionDimensionNumbers.batch_dimension)
  return batch_dimension_;
}
void ConvolutionDimensionNumbers::set_batch_dimension(tensorflow::int64 value) {
  
  batch_dimension_ = value;
  // @@protoc_insertion_point(field_set:xla.ConvolutionDimensionNumbers.batch_dimension)
}

void ConvolutionDimensionNumbers::clear_feature_dimension() {
  feature_dimension_ = GOOGLE_LONGLONG(0);
}
tensorflow::int64 ConvolutionDimensionNumbers::feature_dimension() const {
  // @@protoc_insertion_point(field_get:xla.ConvolutionDimensionNumbers.feature_dimension)
  return feature_dimension_;
}
void ConvolutionDimensionNumbers::set_feature_dimension(tensorflow::int64 value) {
  
  feature_dimension_ = value;
  // @@protoc_insertion_point(field_set:xla.ConvolutionDimensionNumbers.feature_dimension)
}

int ConvolutionDimensionNumbers::spatial_dimensions_size() const {
  return spatial_dimensions_.size();
}
void ConvolutionDimensionNumbers::clear_spatial_dimensions() {
  spatial_dimensions_.Clear();
}
tensorflow::int64 ConvolutionDimensionNumbers::spatial_dimensions(int index) const {
  // @@protoc_insertion_point(field_get:xla.ConvolutionDimensionNumbers.spatial_dimensions)
  return spatial_dimensions_.Get(index);
}
void ConvolutionDimensionNumbers::set_spatial_dimensions(int index, tensorflow::int64 value) {
  spatial_dimensions_.Set(index, value);
  // @@protoc_insertion_point(field_set:xla.ConvolutionDimensionNumbers.spatial_dimensions)
}
void ConvolutionDimensionNumbers::add_spatial_dimensions(tensorflow::int64 value) {
  spatial_dimensions_.Add(value);
  // @@protoc_insertion_point(field_add:xla.ConvolutionDimensionNumbers.spatial_dimensions)
}
const ::google::protobuf::RepeatedField< tensorflow::int64 >&
ConvolutionDimensionNumbers::spatial_dimensions() const {
  // @@protoc_insertion_point(field_list:xla.ConvolutionDimensionNumbers.spatial_dimensions)
  return spatial_dimensions_;
}
::google::protobuf::RepeatedField< tensorflow::int64 >*
ConvolutionDimensionNumbers::mutable_spatial_dimensions() {
  // @@protoc_insertion_point(field_mutable_list:xla.ConvolutionDimensionNumbers.spatial_dimensions)
  return &spatial_dimensions_;
}

void ConvolutionDimensionNumbers::clear_kernel_input_feature_dimension() {
  kernel_input_feature_dimension_ = GOOGLE_LONGLONG(0);
}
tensorflow::int64 ConvolutionDimensionNumbers::kernel_input_feature_dimension() const {
  // @@protoc_insertion_point(field_get:xla.ConvolutionDimensionNumbers.kernel_input_feature_dimension)
  return kernel_input_feature_dimension_;
}
void ConvolutionDimensionNumbers::set_kernel_input_feature_dimension(tensorflow::int64 value) {
  
  kernel_input_feature_dimension_ = value;
  // @@protoc_insertion_point(field_set:xla.ConvolutionDimensionNumbers.kernel_input_feature_dimension)
}

void ConvolutionDimensionNumbers::clear_kernel_output_feature_dimension() {
  kernel_output_feature_dimension_ = GOOGLE_LONGLONG(0);
}
tensorflow::int64 ConvolutionDimensionNumbers::kernel_output_feature_dimension() const {
  // @@protoc_insertion_point(field_get:xla.ConvolutionDimensionNumbers.kernel_output_feature_dimension)
  return kernel_output_feature_dimension_;
}
void ConvolutionDimensionNumbers::set_kernel_output_feature_dimension(tensorflow::int64 value) {
  
  kernel_output_feature_dimension_ = value;
  // @@protoc_insertion_point(field_set:xla.ConvolutionDimensionNumbers.kernel_output_feature_dimension)
}

int ConvolutionDimensionNumbers::kernel_spatial_dimensions_size() const {
  return kernel_spatial_dimensions_.size();
}
void ConvolutionDimensionNumbers::clear_kernel_spatial_dimensions() {
  kernel_spatial_dimensions_.Clear();
}
tensorflow::int64 ConvolutionDimensionNumbers::kernel_spatial_dimensions(int index) const {
  // @@protoc_insertion_point(field_get:xla.ConvolutionDimensionNumbers.kernel_spatial_dimensions)
  return kernel_spatial_dimensions_.Get(index);
}
void ConvolutionDimensionNumbers::set_kernel_spatial_dimensions(int index, tensorflow::int64 value) {
  kernel_spatial_dimensions_.Set(index, value);
  // @@protoc_insertion_point(field_set:xla.ConvolutionDimensionNumbers.kernel_spatial_dimensions)
}
void ConvolutionDimensionNumbers::add_kernel_spatial_dimensions(tensorflow::int64 value) {
  kernel_spatial_dimensions_.Add(value);
  // @@protoc_insertion_point(field_add:xla.ConvolutionDimensionNumbers.kernel_spatial_dimensions)
}
const ::google::protobuf::RepeatedField< tensorflow::int64 >&
ConvolutionDimensionNumbers::kernel_spatial_dimensions() const {
  // @@protoc_insertion_point(field_list:xla.ConvolutionDimensionNumbers.kernel_spatial_dimensions)
  return kernel_spatial_dimensions_;
}
::google::protobuf::RepeatedField< tensorflow::int64 >*
ConvolutionDimensionNumbers::mutable_kernel_spatial_dimensions() {
  // @@protoc_insertion_point(field_mutable_list:xla.ConvolutionDimensionNumbers.kernel_spatial_dimensions)
  return &kernel_spatial_dimensions_;
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace xla

// @@protoc_insertion_point(global_scope)
