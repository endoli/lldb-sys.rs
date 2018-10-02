//===-- SBBreakpointBinding.h -----------------------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef LLDB_SBBreakpointBinding_h_
#define LLDB_SBBreakpointBinding_h_

#include "lldb/Bindings/SBBindingDefines.h"
#ifndef BINDGEN
#include <lldb/API/SBBreakpoint.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

LLDB_API SBBreakpointRef CreateSBBreakpoint(void);

LLDB_API SBBreakpointRef CloneSBBreakpoint(SBBreakpointRef instance);

LLDB_API void DisposeSBBreakpoint(SBBreakpointRef instance);

LLDB_API int SBBreakpointGetID(SBBreakpointRef instance);

LLDB_API bool SBBreakpointIsValid(SBBreakpointRef instance);

LLDB_API void SBBreakpointClearAllBreakpointSites(SBBreakpointRef instance);

LLDB_API SBBreakpointLocationRef
SBBreakpointFindLocationByAddress(SBBreakpointRef instance, lldb_addr_t vm_addr);

LLDB_API int SBBreakpointFindLocationIDByAddress(SBBreakpointRef instance, lldb_addr_t vm_addr);

LLDB_API SBBreakpointLocationRef SBBreakpointFindLocationByID(SBBreakpointRef instance, int bp_loc_id);

LLDB_API SBBreakpointLocationRef SBBreakpointGetLocationAtIndex(SBBreakpointRef instance, uint32_t index);

LLDB_API void SBBreakpointSetEnabled(SBBreakpointRef instance, bool enable);

LLDB_API bool SBBreakpointIsEnabled(SBBreakpointRef instance);

LLDB_API void SBBreakpointSetOneShot(SBBreakpointRef instance, bool one_shot);

LLDB_API bool SBBreakpointIsOneShot(SBBreakpointRef instance);

LLDB_API bool SBBreakpointIsInternal(SBBreakpointRef instance);

LLDB_API unsigned int SBBreakpointGetHitCount(SBBreakpointRef instance);

LLDB_API void SBBreakpointSetIgnoreCount(SBBreakpointRef instance, uint32_t count);

LLDB_API unsigned int SBBreakpointGetIgnoreCount(SBBreakpointRef instance);

LLDB_API void SBBreakpointSetCondition(SBBreakpointRef instance, const char *condition);

LLDB_API const char *SBBreakpointGetCondition(SBBreakpointRef instance);

LLDB_API void SBBreakpointSetThreadID(SBBreakpointRef instance, lldb_tid_t sb_thread_id);

LLDB_API unsigned long long SBBreakpointGetThreadID(SBBreakpointRef instance);

LLDB_API void SBBreakpointSetThreadIndex(SBBreakpointRef instance, uint32_t index);

LLDB_API unsigned int SBBreakpointGetThreadIndex(SBBreakpointRef instance);

LLDB_API void SBBreakpointSetThreadName(SBBreakpointRef instance, const char *thread_name);

LLDB_API const char *SBBreakpointGetThreadName(SBBreakpointRef instance);

LLDB_API void SBBreakpointSetQueueName(SBBreakpointRef instance, const char *queue_name);

LLDB_API const char *SBBreakpointGetQueueName(SBBreakpointRef instance);

#ifndef BINDGEN
LLDB_API void SBBreakpointSetCallback(SBBreakpointRef instance,
                                          lldb::SBBreakpointHitCallback callback, void *baton);
#endif // BINDGEN

LLDB_API void SBBreakpointSetScriptCallbackFunction(SBBreakpointRef instance,
                                                        const char *callback_function_name);

LLDB_API void SBBreakpointSetCommandLineCommands(SBBreakpointRef instance, SBStringListRef commands);

LLDB_API bool SBBreakpointGetCommandLineCommands(SBBreakpointRef instance, SBStringListRef commands);

LLDB_API SBErrorRef
SBBreakpointSetScriptCallbackBody(SBBreakpointRef instance, const char *script_body_text);

LLDB_API bool SBBreakpointAddName(SBBreakpointRef instance, const char *new_name);

LLDB_API void SBBreakpointRemoveName(SBBreakpointRef instance, const char *name_to_remove);

LLDB_API bool SBBreakpointMatchesName(SBBreakpointRef instance, const char *name);

LLDB_API void SBBreakpointGetNames(SBBreakpointRef instance, SBStringListRef names);

LLDB_API unsigned int SBBreakpointGetNumResolvedLocations(SBBreakpointRef instance);

LLDB_API unsigned int SBBreakpointGetNumLocations(SBBreakpointRef instance);

LLDB_API bool SBBreakpointGetDescription(SBBreakpointRef instance, SBStreamRef description);

LLDB_API bool SBBreakpointGetDescription2(SBBreakpointRef instance, SBStreamRef description, bool include_locations);

LLDB_API bool SBBreakpointEventIsBreakpointEvent(SBEventRef event);

LLDB_API ENUM(BreakpointEventType) SBBreakpointGetBreakpointEventTypeFromEvent(SBEventRef event);

LLDB_API SBBreakpointRef SBBreakpointGetBreakpointFromEvent(SBEventRef event);

LLDB_API SBBreakpointLocationRef
SBBreakpointGetBreakpointLocationAtIndexFromEvent(SBEventRef event, uint32_t loc_idx);

LLDB_API unsigned int SBBreakpointGetNumBreakpointLocationsFromEvent(SBEventRef event_sp);

#ifdef __cplusplus
}
#endif

#endif // LLDB_SBBreakpointBinding_h_
