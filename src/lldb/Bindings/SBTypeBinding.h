//===-- SBTypeBinding.h -----------------------------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef LLDB_SBTypeBinding_h_
#define LLDB_SBTypeBinding_h_

#include "lldb/Bindings/SBBindingDefines.h"

#ifdef __cplusplus
extern "C" {
#endif

LLDB_API SBTypeMemberRef CreateSBTypeMember();

LLDB_API void DisposeSBTypeMember(SBTypeMemberRef instance);

LLDB_API bool SBTypeMemberIsValid(SBTypeMemberRef instance);

LLDB_API const char *SBTypeMemberGetName(SBTypeMemberRef instance);

LLDB_API SBTypeRef SBTypeMemberGetType(SBTypeMemberRef instance);

LLDB_API unsigned long long SBTypeMemberGetOffsetInBytes(SBTypeMemberRef instance);

LLDB_API unsigned long long SBTypeMemberGetOffsetInBits(SBTypeMemberRef instance);

LLDB_API bool SBTypeMemberIsBitfield(SBTypeMemberRef instance);

LLDB_API unsigned int SBTypeMemberGetBitfieldSizeInBits(SBTypeMemberRef instance);

LLDB_API bool SBTypeMemberGetDescription(SBTypeMemberRef instance, SBStreamRef description,
                                             LLDBDescriptionLevel description_level);

LLDB_API SBTypeMemberFunctionRef CreateSBTypeMemberFunction();

LLDB_API SBTypeMemberFunctionRef CreateSBTypeMemberFunction2(SBTypeMemberFunctionRef rhs);

LLDB_API void DisposeSBTypeMemberFunction(SBTypeMemberFunctionRef instance);

LLDB_API bool SBTypeMemberFunctionIsValid(SBTypeMemberFunctionRef instance);

LLDB_API const char *SBTypeMemberFunctionGetName(SBTypeMemberFunctionRef instance);

LLDB_API SBTypeRef SBTypeMemberFunctionGetType(SBTypeMemberFunctionRef instance);

LLDB_API SBTypeRef SBTypeMemberFunctionGetReturnType(SBTypeMemberFunctionRef instance);

LLDB_API unsigned int SBTypeMemberFunctionGetNumberOfArguments(SBTypeMemberFunctionRef instance);

LLDB_API SBTypeRef SBTypeMemberFunctionGetArgumentTypeAtIndex(SBTypeMemberFunctionRef instance, uint32_t);

LLDB_API LLDBMemberFunctionKind SBTypeMemberFunctionGetKind(SBTypeMemberFunctionRef instance);

LLDB_API bool SBTypeMemberFunctionGetDescription(SBTypeMemberFunctionRef instance, SBStreamRef description,
                                                     LLDBDescriptionLevel description_level);

LLDB_API SBTypeRef CreateSBType();

LLDB_API void DisposeSBType(SBTypeRef instance);

LLDB_API bool SBTypeIsValid(SBTypeRef instance);

LLDB_API unsigned long long SBTypeGetByteSize(SBTypeRef instance);

LLDB_API bool SBTypeIsPointerType(SBTypeRef instance);

LLDB_API bool SBTypeIsReferenceType(SBTypeRef instance);

LLDB_API bool SBTypeIsFunctionType(SBTypeRef instance);

LLDB_API bool SBTypeIsPolymorphicClass(SBTypeRef instance);

LLDB_API bool SBTypeIsArrayType(SBTypeRef instance);

LLDB_API bool SBTypeIsVectorType(SBTypeRef instance);

LLDB_API bool SBTypeIsTypedefType(SBTypeRef instance);

LLDB_API SBTypeRef SBTypeGetPointerType(SBTypeRef instance);

LLDB_API SBTypeRef SBTypeGetPointeeType(SBTypeRef instance);

LLDB_API SBTypeRef SBTypeGetReferenceType(SBTypeRef instance);

LLDB_API SBTypeRef SBTypeGetTypedefedType(SBTypeRef instance);

LLDB_API SBTypeRef SBTypeGetDereferencedType(SBTypeRef instance);

LLDB_API SBTypeRef SBTypeGetUnqualifiedType(SBTypeRef instance);

LLDB_API SBTypeRef SBTypeGetArrayElementType(SBTypeRef instance);

LLDB_API SBTypeRef SBTypeGetVectorElementType(SBTypeRef instance);

LLDB_API SBTypeRef SBTypeGetCanonicalType(SBTypeRef instance);

LLDB_API LLDBBasicType SBTypeGetBasicType(SBTypeRef instance);

LLDB_API SBTypeRef SBTypeGetBasicType2(SBTypeRef instance, LLDBBasicType type);

LLDB_API unsigned int SBTypeGetNumberOfFields(SBTypeRef instance);

LLDB_API unsigned int SBTypeGetNumberOfDirectBaseClasses(SBTypeRef instance);

LLDB_API unsigned int SBTypeGetNumberOfVirtualBaseClasses(SBTypeRef instance);

LLDB_API SBTypeMemberRef SBTypeGetFieldAtIndex(SBTypeRef instance, uint32_t idx);

LLDB_API SBTypeMemberRef SBTypeGetDirectBaseClassAtIndex(SBTypeRef instance, uint32_t idx);

LLDB_API SBTypeMemberRef SBTypeGetVirtualBaseClassAtIndex(SBTypeRef instance, uint32_t idx);

LLDB_API SBTypeEnumMemberListRef SBTypeGetEnumMembers(SBTypeRef instance);

LLDB_API unsigned int SBTypeGetNumberOfTemplateArguments(SBTypeRef instance);

LLDB_API SBTypeRef SBTypeGetTemplateArgumentType(SBTypeRef instance, uint32_t idx);

LLDB_API LLDBTemplateArgumentKind SBTypeGetTemplateArgumentKind(SBTypeRef instance, uint32_t idx);

LLDB_API SBTypeRef SBTypeGetFunctionReturnType(SBTypeRef instance);

LLDB_API SBTypeListRef SBTypeGetFunctionArgumentTypes(SBTypeRef instance);

LLDB_API unsigned int SBTypeGetNumberOfMemberFunctions(SBTypeRef instance);

LLDB_API SBTypeMemberFunctionRef SBTypeGetMemberFunctionAtIndex(SBTypeRef instance, uint32_t idx);

LLDB_API const char *SBTypeGetName(SBTypeRef instance);

LLDB_API const char *SBTypeGetDisplayTypeName(SBTypeRef instance);

LLDB_API LLDBTypeClass SBTypeGetTypeClass(SBTypeRef instance);

LLDB_API bool SBTypeIsTypeComplete(SBTypeRef instance);

LLDB_API unsigned int SBTypeGetTypeFlags(SBTypeRef instance);

LLDB_API bool SBTypeGetDescription(SBTypeRef instance, SBStreamRef description,
                                       LLDBDescriptionLevel description_level);

LLDB_API SBTypeListRef CreateSBTypeList();

LLDB_API void DisposeSBTypeList(SBTypeListRef instance);

LLDB_API bool SBTypeListIsValid(SBTypeListRef instance);

LLDB_API void SBTypeListAppend(SBTypeListRef instance, SBTypeRef type);

LLDB_API SBTypeRef SBTypeListGetTypeAtIndex(SBTypeListRef instance, uint32_t index);

LLDB_API unsigned int SBTypeListGetSize(SBTypeListRef instance);

#ifdef __cplusplus
}
#endif

#endif // LLDB_SBTypeBinding_h_
