//===-- SBBreakpointLocationBinding.h ---------------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef LLDB_SBBreakpointLocationBinding_h_
#define LLDB_SBBreakpointLocationBinding_h_

#include "lldb/Bindings/SBBindingDefines.h"

#ifdef __cplusplus
extern "C" {
#endif

LLDB_API SBBreakpointLocationRef CreateSBBreakpointLocation();

LLDB_API void DisposeSBBreakpointLocation(SBBreakpointLocationRef instance);

LLDB_API int SBBreakpointLocationGetID(SBBreakpointLocationRef instance);

LLDB_API bool SBBreakpointLocationIsValid(SBBreakpointLocationRef instance);

LLDB_API SBAddressRef SBBreakpointLocationGetAddress(SBBreakpointLocationRef instance);

LLDB_API unsigned long long SBBreakpointLocationGetLoadAddress(SBBreakpointLocationRef instance);

LLDB_API void SBBreakpointLocationSetEnabled(SBBreakpointLocationRef instance, bool enabled);

LLDB_API bool SBBreakpointLocationIsEnabled(SBBreakpointLocationRef instance);

LLDB_API unsigned int SBBreakpointLocationGetIgnoreCount(SBBreakpointLocationRef instance);

LLDB_API void SBBreakpointLocationSetIgnoreCount(SBBreakpointLocationRef instance, uint32_t n);

LLDB_API void SBBreakpointLocationSetCondition(SBBreakpointLocationRef instance, const char *condition);

LLDB_API const char *SBBreakpointLocationGetCondition(SBBreakpointLocationRef instance);

LLDB_API void SBBreakpointLocationSetScriptCallbackFunction(SBBreakpointLocationRef instance,
                                                                const char *callback_function_name);

LLDB_API SBErrorRef
SBBreakpointLocationSetScriptCallbackBody(SBBreakpointLocationRef instance, const char *script_body_text);

LLDB_API void SBBreakpointLocationSetThreadID(SBBreakpointLocationRef instance, lldb_tid_t sb_thread_id);

LLDB_API unsigned long long SBBreakpointLocationGetThreadID(SBBreakpointLocationRef instance);

LLDB_API void SBBreakpointLocationSetThreadIndex(SBBreakpointLocationRef instance, uint32_t index);

LLDB_API unsigned int SBBreakpointLocationGetThreadIndex(SBBreakpointLocationRef instance);

LLDB_API void SBBreakpointLocationSetThreadName(SBBreakpointLocationRef instance, const char *thread_name);

LLDB_API const char *SBBreakpointLocationGetThreadName(SBBreakpointLocationRef instance);

LLDB_API void SBBreakpointLocationSetQueueName(SBBreakpointLocationRef instance, const char *queue_name);

LLDB_API const char *SBBreakpointLocationGetQueueName(SBBreakpointLocationRef instance);

LLDB_API bool SBBreakpointLocationIsResolved(SBBreakpointLocationRef instance);

LLDB_API bool SBBreakpointLocationGetDescription(SBBreakpointLocationRef instance, SBStreamRef description,
                                                     LLDBDescriptionLevel level);

LLDB_API SBBreakpointRef SBBreakpointLocationGetBreakpoint(SBBreakpointLocationRef instance);

#ifdef __cplusplus
}
#endif

#endif // LLDB_SBBreakpointLocationBinding_h_
