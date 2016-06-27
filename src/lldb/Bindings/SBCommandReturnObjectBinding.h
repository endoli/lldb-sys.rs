//===-- SBCommandReturnObjectBinding.h --------------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef LLDB_SBCommandReturnObjectBinding_h_
#define LLDB_SBCommandReturnObjectBinding_h_

#include "lldb/Bindings/SBBindingDefines.h"

#ifdef __cplusplus
extern "C" {
#endif

LLDB_API SBCommandReturnObjectRef CreateSBCommandReturnObject(void);

LLDB_API void *SBCommandReturnObjectRelease(SBCommandReturnObjectRef instance);

LLDB_API void DisposeSBCommandReturnObject(SBCommandReturnObjectRef instance);

LLDB_API bool SBCommandReturnObjectIsValid(SBCommandReturnObjectRef instance);

LLDB_API const char *SBCommandReturnObjectGetOutput(SBCommandReturnObjectRef instance);

LLDB_API const char *SBCommandReturnObjectGetError(SBCommandReturnObjectRef instance);

LLDB_API unsigned int SBCommandReturnObjectPutOutput(SBCommandReturnObjectRef instance, FILE *fh);

LLDB_API unsigned int SBCommandReturnObjectGetOutputSize(SBCommandReturnObjectRef instance);

LLDB_API unsigned int SBCommandReturnObjectGetErrorSize(SBCommandReturnObjectRef instance);

LLDB_API unsigned int SBCommandReturnObjectPutError(SBCommandReturnObjectRef instance, FILE *fh);

LLDB_API void SBCommandReturnObjectClear(SBCommandReturnObjectRef instance);

LLDB_API LLDBReturnStatus SBCommandReturnObjectGetStatus(SBCommandReturnObjectRef instance);

LLDB_API void SBCommandReturnObjectSetStatus(SBCommandReturnObjectRef instance, LLDBReturnStatus status);

LLDB_API bool SBCommandReturnObjectSucceeded(SBCommandReturnObjectRef instance);

LLDB_API bool SBCommandReturnObjectHasResult(SBCommandReturnObjectRef instance);

LLDB_API void SBCommandReturnObjectAppendMessage(SBCommandReturnObjectRef instance, const char *message);

LLDB_API void SBCommandReturnObjectAppendWarning(SBCommandReturnObjectRef instance, const char *message);

LLDB_API bool SBCommandReturnObjectGetDescription(SBCommandReturnObjectRef instance,
                                                      SBStreamRef description);

LLDB_API void SBCommandReturnObjectSetImmediateOutputFile(SBCommandReturnObjectRef instance, FILE *fh);

LLDB_API void SBCommandReturnObjectSetImmediateErrorFile(SBCommandReturnObjectRef instance, FILE *fh);

LLDB_API void SBCommandReturnObjectPutCString(SBCommandReturnObjectRef instance, const char *string, int len);

LLDB_API unsigned int SBCommandReturnObjectPrintf(SBCommandReturnObjectRef instance, const char *format, ...);

LLDB_API const char *SBCommandReturnObjectGetOutput2(SBCommandReturnObjectRef instance,
                                                         bool only_if_no_immediate);

LLDB_API const char *SBCommandReturnObjectGetError2(SBCommandReturnObjectRef instance,
                                                        bool only_if_no_immediate);

LLDB_API void SBCommandReturnObjectSetError(SBCommandReturnObjectRef instance, SBErrorRef error,
                                                const char *fallback_error_cstr);

LLDB_API void SBCommandReturnObjectSetError2(SBCommandReturnObjectRef instance, const char *error_cstr);

#ifdef __cplusplus
}
#endif

#endif // LLDB_SBCommandReturnObjectBinding_h_
