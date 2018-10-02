//===-- SBExpressionOptionsBinding.h ----------------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef LLDB_SBExpressionOptionsBinding_h_
#define LLDB_SBExpressionOptionsBinding_h_

#include "lldb/Bindings/SBBindingDefines.h"

#ifdef __cplusplus
extern "C" {
#endif

LLDB_API SBExpressionOptionsRef CreateSBExpressionOptions(void);

LLDB_API SBExpressionOptionsRef CloneSBExpressionOptions(SBExpressionOptionsRef instance);

LLDB_API void DisposeSBExpressionOptions(SBExpressionOptionsRef instance);

LLDB_API bool SBExpressionOptionsGetCoerceResultToId(SBExpressionOptionsRef instance);

LLDB_API void SBExpressionOptionsSetCoerceResultToId(SBExpressionOptionsRef instance, bool coerce);

LLDB_API bool SBExpressionOptionsGetUnwindOnError(SBExpressionOptionsRef instance);

LLDB_API void SBExpressionOptionsSetUnwindOnError(SBExpressionOptionsRef instance, bool unwind);

LLDB_API bool SBExpressionOptionsGetIgnoreBreakpoints(SBExpressionOptionsRef instance);

LLDB_API void SBExpressionOptionsSetIgnoreBreakpoints(SBExpressionOptionsRef instance, bool ignore);

LLDB_API ENUM(DynamicValueType) SBExpressionOptionsGetFetchDynamicValue(SBExpressionOptionsRef instance);

LLDB_API void SBExpressionOptionsSetFetchDynamicValue(SBExpressionOptionsRef instance,
                                                      ENUM(DynamicValueType) dynamic);

LLDB_API unsigned int SBExpressionOptionsGetTimeoutInMicroSeconds(SBExpressionOptionsRef instance);

LLDB_API void SBExpressionOptionsSetTimeoutInMicroSeconds(SBExpressionOptionsRef instance, uint32_t timeout);

LLDB_API unsigned int SBExpressionOptionsGetOneThreadTimeoutInMicroSeconds(SBExpressionOptionsRef instance);

LLDB_API void SBExpressionOptionsSetOneThreadTimeoutInMicroSeconds(SBExpressionOptionsRef instance,
                                                                       uint32_t timeout);

LLDB_API bool SBExpressionOptionsGetTryAllThreads(SBExpressionOptionsRef instance);

LLDB_API void SBExpressionOptionsSetTryAllThreads(SBExpressionOptionsRef instance, bool run_others);

LLDB_API bool SBExpressionOptionsGetStopOthers(SBExpressionOptionsRef instance);

LLDB_API void SBExpressionOptionsSetStopOthers(SBExpressionOptionsRef instance, bool stop_others);

LLDB_API bool SBExpressionOptionsGetTrapExceptions(SBExpressionOptionsRef instance);

LLDB_API void SBExpressionOptionsSetTrapExceptions(SBExpressionOptionsRef instance, bool trap_exceptions);

LLDB_API void SBExpressionOptionsSetLanguage(SBExpressionOptionsRef instance, ENUM(LanguageType) language);

#ifndef BINDGEN
LLDB_API void SBExpressionOptionsSetCancelCallback(SBExpressionOptionsRef instance,
                                                       lldb::ExpressionCancelCallback callback, void *baton);
#endif

LLDB_API bool SBExpressionOptionsGetGenerateDebugInfo(SBExpressionOptionsRef instance);

LLDB_API void SBExpressionOptionsSetGenerateDebugInfo(SBExpressionOptionsRef instance, bool b);

LLDB_API bool SBExpressionOptionsGetSuppressPersistentResult(SBExpressionOptionsRef instance);

LLDB_API void SBExpressionOptionsSetSuppressPersistentResult(SBExpressionOptionsRef instance, bool b);

#ifdef __cplusplus
}
#endif

#endif // LLDB_SBExpressionOptionsBinding_h_
