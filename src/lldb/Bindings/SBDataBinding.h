//===-- SBDataBinding.h -----------------------------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef LLDB_SBDataBinding_h_
#define LLDB_SBDataBinding_h_

#include "lldb/Bindings/SBBindingDefines.h"

#ifdef __cplusplus
extern "C" {
#endif

LLDB_API SBDataRef CreateSBData(void);

LLDB_API void DisposeSBData(SBDataRef instance);

LLDB_API unsigned char SBDataGetAddressByteSize(SBDataRef instance);

LLDB_API void SBDataSetAddressByteSize(SBDataRef instance, uint8_t addr_byte_size);

LLDB_API void SBDataClear(SBDataRef instance);

LLDB_API bool SBDataIsValid(SBDataRef instance);

LLDB_API unsigned int SBDataGetByteSize(SBDataRef instance);

LLDB_API ENUM(ByteOrder) SBDataGetByteOrder(SBDataRef instance);

LLDB_API void SBDataSetByteOrder(SBDataRef instance, ENUM(ByteOrder) endian);

LLDB_API float SBDataGetFloat(SBDataRef instance, SBErrorRef error, lldb_offset_t offset);

LLDB_API double SBDataGetDouble(SBDataRef instance, SBErrorRef error, lldb_offset_t offset);

LLDB_API long double SBDataGetLongDouble(SBDataRef instance, SBErrorRef error, lldb_offset_t offset);

LLDB_API unsigned long long SBDataGetAddress(SBDataRef instance, SBErrorRef error, lldb_offset_t offset);

LLDB_API unsigned char SBDataGetUnsignedInt8(SBDataRef instance, SBErrorRef error, lldb_offset_t offset);

LLDB_API unsigned short SBDataGetUnsignedInt16(SBDataRef instance, SBErrorRef error, lldb_offset_t offset);

LLDB_API unsigned int SBDataGetUnsignedInt32(SBDataRef instance, SBErrorRef error, lldb_offset_t offset);

LLDB_API unsigned long long SBDataGetUnsignedInt64(SBDataRef instance, SBErrorRef error,
                                                       lldb_offset_t offset);

LLDB_API signed char SBDataGetSignedInt8(SBDataRef instance, SBErrorRef error, lldb_offset_t offset);

LLDB_API short SBDataGetSignedInt16(SBDataRef instance, SBErrorRef error, lldb_offset_t offset);

LLDB_API int SBDataGetSignedInt32(SBDataRef instance, SBErrorRef error, lldb_offset_t offset);

LLDB_API long long SBDataGetSignedInt64(SBDataRef instance, SBErrorRef error, lldb_offset_t offset);

LLDB_API const char *SBDataGetString(SBDataRef instance, SBErrorRef error, lldb_offset_t offset);

LLDB_API unsigned int SBDataReadRawData(SBDataRef instance, SBErrorRef error, lldb_offset_t offset,
                                            void *buf, size_t size);

LLDB_API bool SBDataGetDescription(SBDataRef instance, SBStreamRef description, lldb_addr_t base_addr);

LLDB_API void SBDataSetData(SBDataRef instance, SBErrorRef error, void *buf, size_t size,
                            ENUM(ByteOrder) endian, uint8_t addr_size);

LLDB_API bool SBDataAppend(SBDataRef instance, SBDataRef rhs);

LLDB_API SBDataRef SBDataCreateDataFromCString(ENUM(ByteOrder) endian, uint32_t addr_byte_size, const char *data);

LLDB_API SBDataRef
SBDataCreateDataFromUInt64Array(ENUM(ByteOrder) endian, uint32_t addr_byte_size, uint64_t *array, size_t array_len);

LLDB_API SBDataRef
SBDataCreateDataFromUInt32Array(ENUM(ByteOrder) endian, uint32_t addr_byte_size, uint32_t *array, size_t array_len);

LLDB_API SBDataRef
SBDataCreateDataFromSInt64Array(ENUM(ByteOrder) endian, uint32_t addr_byte_size, int64_t *array, size_t array_len);

LLDB_API SBDataRef
SBDataCreateDataFromSInt32Array(ENUM(ByteOrder) endian, uint32_t addr_byte_size, int32_t *array, size_t array_len);

LLDB_API SBDataRef
SBDataCreateDataFromDoubleArray(ENUM(ByteOrder) endian, uint32_t addr_byte_size, double *array, size_t array_len);

LLDB_API bool SBDataSetDataFromCString(SBDataRef instance, const char *data);

LLDB_API bool SBDataSetDataFromUInt64Array(SBDataRef instance, uint64_t *array, size_t array_len);

LLDB_API bool SBDataSetDataFromUInt32Array(SBDataRef instance, uint32_t *array, size_t array_len);

LLDB_API bool SBDataSetDataFromSInt64Array(SBDataRef instance, int64_t *array, size_t array_len);

LLDB_API bool SBDataSetDataFromSInt32Array(SBDataRef instance, int32_t *array, size_t array_len);

LLDB_API bool SBDataSetDataFromDoubleArray(SBDataRef instance, double *array, size_t array_len);

#ifdef __cplusplus
}
#endif

#endif // LLDB_SBDataBinding_h_
