// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: vanet_block.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_vanet_5fblock_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_vanet_5fblock_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3019000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3019004 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_vanet_5fblock_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_vanet_5fblock_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[3]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_vanet_5fblock_2eproto;
namespace vanet_block {
class block_data;
struct block_dataDefaultTypeInternal;
extern block_dataDefaultTypeInternal _block_data_default_instance_;
class psuedoid;
struct psuedoidDefaultTypeInternal;
extern psuedoidDefaultTypeInternal _psuedoid_default_instance_;
class response;
struct responseDefaultTypeInternal;
extern responseDefaultTypeInternal _response_default_instance_;
}  // namespace vanet_block
PROTOBUF_NAMESPACE_OPEN
template<> ::vanet_block::block_data* Arena::CreateMaybeMessage<::vanet_block::block_data>(Arena*);
template<> ::vanet_block::psuedoid* Arena::CreateMaybeMessage<::vanet_block::psuedoid>(Arena*);
template<> ::vanet_block::response* Arena::CreateMaybeMessage<::vanet_block::response>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace vanet_block {

// ===================================================================

class block_data final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:vanet_block.block_data) */ {
 public:
  inline block_data() : block_data(nullptr) {}
  ~block_data() override;
  explicit constexpr block_data(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  block_data(const block_data& from);
  block_data(block_data&& from) noexcept
    : block_data() {
    *this = ::std::move(from);
  }

  inline block_data& operator=(const block_data& from) {
    CopyFrom(from);
    return *this;
  }
  inline block_data& operator=(block_data&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const block_data& default_instance() {
    return *internal_default_instance();
  }
  static inline const block_data* internal_default_instance() {
    return reinterpret_cast<const block_data*>(
               &_block_data_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(block_data& a, block_data& b) {
    a.Swap(&b);
  }
  inline void Swap(block_data* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(block_data* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  block_data* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<block_data>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const block_data& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const block_data& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(block_data* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "vanet_block.block_data";
  }
  protected:
  explicit block_data(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kVinFieldNumber = 1,
    kPidFieldNumber = 2,
    kPkFieldNumber = 3,
    kStatusFieldNumber = 4,
  };
  // string vin = 1;
  void clear_vin();
  const std::string& vin() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_vin(ArgT0&& arg0, ArgT... args);
  std::string* mutable_vin();
  PROTOBUF_NODISCARD std::string* release_vin();
  void set_allocated_vin(std::string* vin);
  private:
  const std::string& _internal_vin() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_vin(const std::string& value);
  std::string* _internal_mutable_vin();
  public:

  // string pid = 2;
  void clear_pid();
  const std::string& pid() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_pid(ArgT0&& arg0, ArgT... args);
  std::string* mutable_pid();
  PROTOBUF_NODISCARD std::string* release_pid();
  void set_allocated_pid(std::string* pid);
  private:
  const std::string& _internal_pid() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_pid(const std::string& value);
  std::string* _internal_mutable_pid();
  public:

  // string pk = 3;
  void clear_pk();
  const std::string& pk() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_pk(ArgT0&& arg0, ArgT... args);
  std::string* mutable_pk();
  PROTOBUF_NODISCARD std::string* release_pk();
  void set_allocated_pk(std::string* pk);
  private:
  const std::string& _internal_pk() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_pk(const std::string& value);
  std::string* _internal_mutable_pk();
  public:

  // string status = 4;
  void clear_status();
  const std::string& status() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_status(ArgT0&& arg0, ArgT... args);
  std::string* mutable_status();
  PROTOBUF_NODISCARD std::string* release_status();
  void set_allocated_status(std::string* status);
  private:
  const std::string& _internal_status() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_status(const std::string& value);
  std::string* _internal_mutable_status();
  public:

  // @@protoc_insertion_point(class_scope:vanet_block.block_data)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr vin_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr pid_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr pk_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr status_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_vanet_5fblock_2eproto;
};
// -------------------------------------------------------------------

class response final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:vanet_block.response) */ {
 public:
  inline response() : response(nullptr) {}
  ~response() override;
  explicit constexpr response(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  response(const response& from);
  response(response&& from) noexcept
    : response() {
    *this = ::std::move(from);
  }

  inline response& operator=(const response& from) {
    CopyFrom(from);
    return *this;
  }
  inline response& operator=(response&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const response& default_instance() {
    return *internal_default_instance();
  }
  static inline const response* internal_default_instance() {
    return reinterpret_cast<const response*>(
               &_response_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(response& a, response& b) {
    a.Swap(&b);
  }
  inline void Swap(response* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(response* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  response* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<response>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const response& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const response& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(response* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "vanet_block.response";
  }
  protected:
  explicit response(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kStatusFieldNumber = 1,
  };
  // int32 status = 1;
  void clear_status();
  int32_t status() const;
  void set_status(int32_t value);
  private:
  int32_t _internal_status() const;
  void _internal_set_status(int32_t value);
  public:

  // @@protoc_insertion_point(class_scope:vanet_block.response)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  int32_t status_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_vanet_5fblock_2eproto;
};
// -------------------------------------------------------------------

class psuedoid final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:vanet_block.psuedoid) */ {
 public:
  inline psuedoid() : psuedoid(nullptr) {}
  ~psuedoid() override;
  explicit constexpr psuedoid(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  psuedoid(const psuedoid& from);
  psuedoid(psuedoid&& from) noexcept
    : psuedoid() {
    *this = ::std::move(from);
  }

  inline psuedoid& operator=(const psuedoid& from) {
    CopyFrom(from);
    return *this;
  }
  inline psuedoid& operator=(psuedoid&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const psuedoid& default_instance() {
    return *internal_default_instance();
  }
  static inline const psuedoid* internal_default_instance() {
    return reinterpret_cast<const psuedoid*>(
               &_psuedoid_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(psuedoid& a, psuedoid& b) {
    a.Swap(&b);
  }
  inline void Swap(psuedoid* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(psuedoid* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  psuedoid* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<psuedoid>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const psuedoid& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const psuedoid& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(psuedoid* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "vanet_block.psuedoid";
  }
  protected:
  explicit psuedoid(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kPidFieldNumber = 1,
  };
  // string pid = 1;
  void clear_pid();
  const std::string& pid() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_pid(ArgT0&& arg0, ArgT... args);
  std::string* mutable_pid();
  PROTOBUF_NODISCARD std::string* release_pid();
  void set_allocated_pid(std::string* pid);
  private:
  const std::string& _internal_pid() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_pid(const std::string& value);
  std::string* _internal_mutable_pid();
  public:

  // @@protoc_insertion_point(class_scope:vanet_block.psuedoid)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr pid_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_vanet_5fblock_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// block_data

// string vin = 1;
inline void block_data::clear_vin() {
  vin_.ClearToEmpty();
}
inline const std::string& block_data::vin() const {
  // @@protoc_insertion_point(field_get:vanet_block.block_data.vin)
  return _internal_vin();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void block_data::set_vin(ArgT0&& arg0, ArgT... args) {
 
 vin_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:vanet_block.block_data.vin)
}
inline std::string* block_data::mutable_vin() {
  std::string* _s = _internal_mutable_vin();
  // @@protoc_insertion_point(field_mutable:vanet_block.block_data.vin)
  return _s;
}
inline const std::string& block_data::_internal_vin() const {
  return vin_.Get();
}
inline void block_data::_internal_set_vin(const std::string& value) {
  
  vin_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* block_data::_internal_mutable_vin() {
  
  return vin_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* block_data::release_vin() {
  // @@protoc_insertion_point(field_release:vanet_block.block_data.vin)
  return vin_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void block_data::set_allocated_vin(std::string* vin) {
  if (vin != nullptr) {
    
  } else {
    
  }
  vin_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), vin,
      GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (vin_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    vin_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:vanet_block.block_data.vin)
}

// string pid = 2;
inline void block_data::clear_pid() {
  pid_.ClearToEmpty();
}
inline const std::string& block_data::pid() const {
  // @@protoc_insertion_point(field_get:vanet_block.block_data.pid)
  return _internal_pid();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void block_data::set_pid(ArgT0&& arg0, ArgT... args) {
 
 pid_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:vanet_block.block_data.pid)
}
inline std::string* block_data::mutable_pid() {
  std::string* _s = _internal_mutable_pid();
  // @@protoc_insertion_point(field_mutable:vanet_block.block_data.pid)
  return _s;
}
inline const std::string& block_data::_internal_pid() const {
  return pid_.Get();
}
inline void block_data::_internal_set_pid(const std::string& value) {
  
  pid_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* block_data::_internal_mutable_pid() {
  
  return pid_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* block_data::release_pid() {
  // @@protoc_insertion_point(field_release:vanet_block.block_data.pid)
  return pid_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void block_data::set_allocated_pid(std::string* pid) {
  if (pid != nullptr) {
    
  } else {
    
  }
  pid_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), pid,
      GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (pid_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    pid_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:vanet_block.block_data.pid)
}

// string pk = 3;
inline void block_data::clear_pk() {
  pk_.ClearToEmpty();
}
inline const std::string& block_data::pk() const {
  // @@protoc_insertion_point(field_get:vanet_block.block_data.pk)
  return _internal_pk();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void block_data::set_pk(ArgT0&& arg0, ArgT... args) {
 
 pk_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:vanet_block.block_data.pk)
}
inline std::string* block_data::mutable_pk() {
  std::string* _s = _internal_mutable_pk();
  // @@protoc_insertion_point(field_mutable:vanet_block.block_data.pk)
  return _s;
}
inline const std::string& block_data::_internal_pk() const {
  return pk_.Get();
}
inline void block_data::_internal_set_pk(const std::string& value) {
  
  pk_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* block_data::_internal_mutable_pk() {
  
  return pk_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* block_data::release_pk() {
  // @@protoc_insertion_point(field_release:vanet_block.block_data.pk)
  return pk_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void block_data::set_allocated_pk(std::string* pk) {
  if (pk != nullptr) {
    
  } else {
    
  }
  pk_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), pk,
      GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (pk_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    pk_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:vanet_block.block_data.pk)
}

// string status = 4;
inline void block_data::clear_status() {
  status_.ClearToEmpty();
}
inline const std::string& block_data::status() const {
  // @@protoc_insertion_point(field_get:vanet_block.block_data.status)
  return _internal_status();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void block_data::set_status(ArgT0&& arg0, ArgT... args) {
 
 status_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:vanet_block.block_data.status)
}
inline std::string* block_data::mutable_status() {
  std::string* _s = _internal_mutable_status();
  // @@protoc_insertion_point(field_mutable:vanet_block.block_data.status)
  return _s;
}
inline const std::string& block_data::_internal_status() const {
  return status_.Get();
}
inline void block_data::_internal_set_status(const std::string& value) {
  
  status_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* block_data::_internal_mutable_status() {
  
  return status_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* block_data::release_status() {
  // @@protoc_insertion_point(field_release:vanet_block.block_data.status)
  return status_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void block_data::set_allocated_status(std::string* status) {
  if (status != nullptr) {
    
  } else {
    
  }
  status_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), status,
      GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (status_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    status_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:vanet_block.block_data.status)
}

// -------------------------------------------------------------------

// response

// int32 status = 1;
inline void response::clear_status() {
  status_ = 0;
}
inline int32_t response::_internal_status() const {
  return status_;
}
inline int32_t response::status() const {
  // @@protoc_insertion_point(field_get:vanet_block.response.status)
  return _internal_status();
}
inline void response::_internal_set_status(int32_t value) {
  
  status_ = value;
}
inline void response::set_status(int32_t value) {
  _internal_set_status(value);
  // @@protoc_insertion_point(field_set:vanet_block.response.status)
}

// -------------------------------------------------------------------

// psuedoid

// string pid = 1;
inline void psuedoid::clear_pid() {
  pid_.ClearToEmpty();
}
inline const std::string& psuedoid::pid() const {
  // @@protoc_insertion_point(field_get:vanet_block.psuedoid.pid)
  return _internal_pid();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void psuedoid::set_pid(ArgT0&& arg0, ArgT... args) {
 
 pid_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:vanet_block.psuedoid.pid)
}
inline std::string* psuedoid::mutable_pid() {
  std::string* _s = _internal_mutable_pid();
  // @@protoc_insertion_point(field_mutable:vanet_block.psuedoid.pid)
  return _s;
}
inline const std::string& psuedoid::_internal_pid() const {
  return pid_.Get();
}
inline void psuedoid::_internal_set_pid(const std::string& value) {
  
  pid_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* psuedoid::_internal_mutable_pid() {
  
  return pid_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* psuedoid::release_pid() {
  // @@protoc_insertion_point(field_release:vanet_block.psuedoid.pid)
  return pid_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void psuedoid::set_allocated_pid(std::string* pid) {
  if (pid != nullptr) {
    
  } else {
    
  }
  pid_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), pid,
      GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (pid_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    pid_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:vanet_block.psuedoid.pid)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace vanet_block

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_vanet_5fblock_2eproto
