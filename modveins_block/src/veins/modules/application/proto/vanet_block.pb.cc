// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: vanet_block.proto

#include "vanet_block.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
namespace vanet_block {
constexpr block_data::block_data(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : vin_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , pid_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , pk_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string)
  , status_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string){}
struct block_dataDefaultTypeInternal {
  constexpr block_dataDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~block_dataDefaultTypeInternal() {}
  union {
    block_data _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT block_dataDefaultTypeInternal _block_data_default_instance_;
constexpr response::response(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : status_(0){}
struct responseDefaultTypeInternal {
  constexpr responseDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~responseDefaultTypeInternal() {}
  union {
    response _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT responseDefaultTypeInternal _response_default_instance_;
constexpr psuedoid::psuedoid(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : pid_(&::PROTOBUF_NAMESPACE_ID::internal::fixed_address_empty_string){}
struct psuedoidDefaultTypeInternal {
  constexpr psuedoidDefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~psuedoidDefaultTypeInternal() {}
  union {
    psuedoid _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT psuedoidDefaultTypeInternal _psuedoid_default_instance_;
}  // namespace vanet_block
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_vanet_5fblock_2eproto[3];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_vanet_5fblock_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_vanet_5fblock_2eproto = nullptr;

const uint32_t TableStruct_vanet_5fblock_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::vanet_block::block_data, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::vanet_block::block_data, vin_),
  PROTOBUF_FIELD_OFFSET(::vanet_block::block_data, pid_),
  PROTOBUF_FIELD_OFFSET(::vanet_block::block_data, pk_),
  PROTOBUF_FIELD_OFFSET(::vanet_block::block_data, status_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::vanet_block::response, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::vanet_block::response, status_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::vanet_block::psuedoid, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::vanet_block::psuedoid, pid_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::vanet_block::block_data)},
  { 10, -1, -1, sizeof(::vanet_block::response)},
  { 17, -1, -1, sizeof(::vanet_block::psuedoid)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::vanet_block::_block_data_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::vanet_block::_response_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::vanet_block::_psuedoid_default_instance_),
};

const char descriptor_table_protodef_vanet_5fblock_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\021vanet_block.proto\022\013vanet_block\"B\n\nbloc"
  "k_data\022\013\n\003vin\030\001 \001(\t\022\013\n\003pid\030\002 \001(\t\022\n\n\002pk\030\003"
  " \001(\t\022\016\n\006status\030\004 \001(\t\"\032\n\010response\022\016\n\006stat"
  "us\030\001 \001(\005\"\027\n\010psuedoid\022\013\n\003pid\030\001 \001(\t2\316\001\n\017Bl"
  "ockchainVanet\022=\n\013reg_vehicle\022\027.vanet_blo"
  "ck.block_data\032\025.vanet_block.response\022<\n\n"
  "update_pid\022\027.vanet_block.block_data\032\025.va"
  "net_block.response\022>\n\014qurery_Block\022\025.van"
  "et_block.psuedoid\032\027.vanet_block.block_da"
  "taBVZTgithub.com/Adityak9/fabric-samples"
  "/asset-transfer-basic/application-gatewa"
  "y-go/protob\006proto3"
  ;
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_vanet_5fblock_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_vanet_5fblock_2eproto = {
  false, false, 458, descriptor_table_protodef_vanet_5fblock_2eproto, "vanet_block.proto", 
  &descriptor_table_vanet_5fblock_2eproto_once, nullptr, 0, 3,
  schemas, file_default_instances, TableStruct_vanet_5fblock_2eproto::offsets,
  file_level_metadata_vanet_5fblock_2eproto, file_level_enum_descriptors_vanet_5fblock_2eproto, file_level_service_descriptors_vanet_5fblock_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_vanet_5fblock_2eproto_getter() {
  return &descriptor_table_vanet_5fblock_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_vanet_5fblock_2eproto(&descriptor_table_vanet_5fblock_2eproto);
namespace vanet_block {

// ===================================================================

class block_data::_Internal {
 public:
};

block_data::block_data(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:vanet_block.block_data)
}
block_data::block_data(const block_data& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  vin_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    vin_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_vin().empty()) {
    vin_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_vin(), 
      GetArenaForAllocation());
  }
  pid_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    pid_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_pid().empty()) {
    pid_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_pid(), 
      GetArenaForAllocation());
  }
  pk_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    pk_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_pk().empty()) {
    pk_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_pk(), 
      GetArenaForAllocation());
  }
  status_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    status_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_status().empty()) {
    status_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_status(), 
      GetArenaForAllocation());
  }
  // @@protoc_insertion_point(copy_constructor:vanet_block.block_data)
}

inline void block_data::SharedCtor() {
vin_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  vin_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
pid_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  pid_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
pk_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  pk_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
status_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  status_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

block_data::~block_data() {
  // @@protoc_insertion_point(destructor:vanet_block.block_data)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void block_data::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  vin_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  pid_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  pk_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  status_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void block_data::ArenaDtor(void* object) {
  block_data* _this = reinterpret_cast< block_data* >(object);
  (void)_this;
}
void block_data::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void block_data::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void block_data::Clear() {
// @@protoc_insertion_point(message_clear_start:vanet_block.block_data)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  vin_.ClearToEmpty();
  pid_.ClearToEmpty();
  pk_.ClearToEmpty();
  status_.ClearToEmpty();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* block_data::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string vin = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          auto str = _internal_mutable_vin();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "vanet_block.block_data.vin"));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // string pid = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          auto str = _internal_mutable_pid();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "vanet_block.block_data.pid"));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // string pk = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 26)) {
          auto str = _internal_mutable_pk();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "vanet_block.block_data.pk"));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // string status = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 34)) {
          auto str = _internal_mutable_status();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "vanet_block.block_data.status"));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* block_data::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:vanet_block.block_data)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // string vin = 1;
  if (!this->_internal_vin().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_vin().data(), static_cast<int>(this->_internal_vin().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "vanet_block.block_data.vin");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_vin(), target);
  }

  // string pid = 2;
  if (!this->_internal_pid().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_pid().data(), static_cast<int>(this->_internal_pid().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "vanet_block.block_data.pid");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_pid(), target);
  }

  // string pk = 3;
  if (!this->_internal_pk().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_pk().data(), static_cast<int>(this->_internal_pk().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "vanet_block.block_data.pk");
    target = stream->WriteStringMaybeAliased(
        3, this->_internal_pk(), target);
  }

  // string status = 4;
  if (!this->_internal_status().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_status().data(), static_cast<int>(this->_internal_status().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "vanet_block.block_data.status");
    target = stream->WriteStringMaybeAliased(
        4, this->_internal_status(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:vanet_block.block_data)
  return target;
}

size_t block_data::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:vanet_block.block_data)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string vin = 1;
  if (!this->_internal_vin().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_vin());
  }

  // string pid = 2;
  if (!this->_internal_pid().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_pid());
  }

  // string pk = 3;
  if (!this->_internal_pk().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_pk());
  }

  // string status = 4;
  if (!this->_internal_status().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_status());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData block_data::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    block_data::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*block_data::GetClassData() const { return &_class_data_; }

void block_data::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<block_data *>(to)->MergeFrom(
      static_cast<const block_data &>(from));
}


void block_data::MergeFrom(const block_data& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:vanet_block.block_data)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_vin().empty()) {
    _internal_set_vin(from._internal_vin());
  }
  if (!from._internal_pid().empty()) {
    _internal_set_pid(from._internal_pid());
  }
  if (!from._internal_pk().empty()) {
    _internal_set_pk(from._internal_pk());
  }
  if (!from._internal_status().empty()) {
    _internal_set_status(from._internal_status());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void block_data::CopyFrom(const block_data& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:vanet_block.block_data)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool block_data::IsInitialized() const {
  return true;
}

void block_data::InternalSwap(block_data* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &vin_, lhs_arena,
      &other->vin_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &pid_, lhs_arena,
      &other->pid_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &pk_, lhs_arena,
      &other->pk_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &status_, lhs_arena,
      &other->status_, rhs_arena
  );
}

::PROTOBUF_NAMESPACE_ID::Metadata block_data::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_vanet_5fblock_2eproto_getter, &descriptor_table_vanet_5fblock_2eproto_once,
      file_level_metadata_vanet_5fblock_2eproto[0]);
}

// ===================================================================

class response::_Internal {
 public:
};

response::response(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:vanet_block.response)
}
response::response(const response& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  status_ = from.status_;
  // @@protoc_insertion_point(copy_constructor:vanet_block.response)
}

inline void response::SharedCtor() {
status_ = 0;
}

response::~response() {
  // @@protoc_insertion_point(destructor:vanet_block.response)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void response::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void response::ArenaDtor(void* object) {
  response* _this = reinterpret_cast< response* >(object);
  (void)_this;
}
void response::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void response::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void response::Clear() {
// @@protoc_insertion_point(message_clear_start:vanet_block.response)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  status_ = 0;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* response::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // int32 status = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          status_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* response::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:vanet_block.response)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 status = 1;
  if (this->_internal_status() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteInt32ToArray(1, this->_internal_status(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:vanet_block.response)
  return target;
}

size_t response::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:vanet_block.response)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // int32 status = 1;
  if (this->_internal_status() != 0) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::Int32SizePlusOne(this->_internal_status());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData response::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    response::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*response::GetClassData() const { return &_class_data_; }

void response::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<response *>(to)->MergeFrom(
      static_cast<const response &>(from));
}


void response::MergeFrom(const response& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:vanet_block.response)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_status() != 0) {
    _internal_set_status(from._internal_status());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void response::CopyFrom(const response& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:vanet_block.response)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool response::IsInitialized() const {
  return true;
}

void response::InternalSwap(response* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(status_, other->status_);
}

::PROTOBUF_NAMESPACE_ID::Metadata response::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_vanet_5fblock_2eproto_getter, &descriptor_table_vanet_5fblock_2eproto_once,
      file_level_metadata_vanet_5fblock_2eproto[1]);
}

// ===================================================================

class psuedoid::_Internal {
 public:
};

psuedoid::psuedoid(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:vanet_block.psuedoid)
}
psuedoid::psuedoid(const psuedoid& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  pid_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    pid_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_pid().empty()) {
    pid_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, from._internal_pid(), 
      GetArenaForAllocation());
  }
  // @@protoc_insertion_point(copy_constructor:vanet_block.psuedoid)
}

inline void psuedoid::SharedCtor() {
pid_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  pid_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

psuedoid::~psuedoid() {
  // @@protoc_insertion_point(destructor:vanet_block.psuedoid)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void psuedoid::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  pid_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void psuedoid::ArenaDtor(void* object) {
  psuedoid* _this = reinterpret_cast< psuedoid* >(object);
  (void)_this;
}
void psuedoid::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void psuedoid::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void psuedoid::Clear() {
// @@protoc_insertion_point(message_clear_start:vanet_block.psuedoid)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  pid_.ClearToEmpty();
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* psuedoid::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string pid = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          auto str = _internal_mutable_pid();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "vanet_block.psuedoid.pid"));
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* psuedoid::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:vanet_block.psuedoid)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // string pid = 1;
  if (!this->_internal_pid().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_pid().data(), static_cast<int>(this->_internal_pid().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "vanet_block.psuedoid.pid");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_pid(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:vanet_block.psuedoid)
  return target;
}

size_t psuedoid::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:vanet_block.psuedoid)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string pid = 1;
  if (!this->_internal_pid().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_pid());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData psuedoid::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    psuedoid::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*psuedoid::GetClassData() const { return &_class_data_; }

void psuedoid::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to,
                      const ::PROTOBUF_NAMESPACE_ID::Message& from) {
  static_cast<psuedoid *>(to)->MergeFrom(
      static_cast<const psuedoid &>(from));
}


void psuedoid::MergeFrom(const psuedoid& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:vanet_block.psuedoid)
  GOOGLE_DCHECK_NE(&from, this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_pid().empty()) {
    _internal_set_pid(from._internal_pid());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void psuedoid::CopyFrom(const psuedoid& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:vanet_block.psuedoid)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool psuedoid::IsInitialized() const {
  return true;
}

void psuedoid::InternalSwap(psuedoid* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      &pid_, lhs_arena,
      &other->pid_, rhs_arena
  );
}

::PROTOBUF_NAMESPACE_ID::Metadata psuedoid::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_vanet_5fblock_2eproto_getter, &descriptor_table_vanet_5fblock_2eproto_once,
      file_level_metadata_vanet_5fblock_2eproto[2]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace vanet_block
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::vanet_block::block_data* Arena::CreateMaybeMessage< ::vanet_block::block_data >(Arena* arena) {
  return Arena::CreateMessageInternal< ::vanet_block::block_data >(arena);
}
template<> PROTOBUF_NOINLINE ::vanet_block::response* Arena::CreateMaybeMessage< ::vanet_block::response >(Arena* arena) {
  return Arena::CreateMessageInternal< ::vanet_block::response >(arena);
}
template<> PROTOBUF_NOINLINE ::vanet_block::psuedoid* Arena::CreateMaybeMessage< ::vanet_block::psuedoid >(Arena* arena) {
  return Arena::CreateMessageInternal< ::vanet_block::psuedoid >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>