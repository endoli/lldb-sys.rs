//===-- SBWatchpointBinding.h -----------------------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef LLDB_SBWatchpointBinding_h_
#define LLDB_SBWatchpointBinding_h_

#include "lldb/Bindings/SBBindingDefines.h"

#ifdef __cplusplus
extern "C" {
#endif

LLDB_API SBWatchpointRef CreateSBWatchpoint(void);

LLDB_API void DisposeSBWatchpoint(SBWatchpointRef instance);

LLDB_API bool SBWatchpointIsValid(SBWatchpointRef instance);

LLDB_API SBErrorRef SBWatchpointGetError(SBWatchpointRef instance);

LLDB_API int SBWatchpointGetID(SBWatchpointRef instance);

LLDB_API int SBWatchpointGetHardwareIndex(SBWatchpointRef instance);

LLDB_API unsigned long long SBWatchpointGetWatchAddress(SBWatchpointRef instance);

LLDB_API unsigned int SBWatchpointGetWatchSize(SBWatchpointRef instance);

LLDB_API void SBWatchpointSetEnabled(SBWatchpointRef instance, bool enabled);

LLDB_API bool SBWatchpointIsEnabled(SBWatchpointRef instance);

LLDB_API unsigned int SBWatchpointGetHitCount(SBWatchpointRef instance);

LLDB_API unsigned int SBWatchpointGetIgnoreCount(SBWatchpointRef instance);

LLDB_API void SBWatchpointSetIgnoreCount(SBWatchpointRef instance, uint32_t n);

LLDB_API const char *SBWatchpointGetCondition(SBWatchpointRef instance);

LLDB_API void SBWatchpointSetCondition(SBWatchpointRef instance, const char *condition);

LLDB_API bool SBWatchpointGetDescription(SBWatchpointRef instance, SBStreamRef description,
                                             LLDBDescriptionLevel level);

LLDB_API void SBWatchpointClear(SBWatchpointRef instance);

LLDB_API bool SBWatchpointEventIsWatchpointEvent(SBEventRef event);

LLDB_API LLDBWatchpointEventType SBWatchpointGetWatchpointEventTypeFromEvent(SBEventRef event);

LLDB_API SBWatchpointRef SBWatchpointGetWatchpointFromEvent(SBEventRef event);

#ifdef __cplusplus
}
#endif

#endif // LLDB_SBWatchpointBinding_h_
