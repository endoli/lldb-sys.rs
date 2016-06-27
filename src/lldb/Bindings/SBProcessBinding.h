//===-- SBProcessBinding.h --------------------------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef LLDB_SBProcessBinding_h_
#define LLDB_SBProcessBinding_h_

#include "lldb/Bindings/SBBindingDefines.h"

#ifdef __cplusplus
extern "C" {
#endif

LLDB_API SBProcessRef CreateSBProcess(void);

LLDB_API void DisposeSBProcess(SBProcessRef instance);

LLDB_API const char *SBProcessGetBroadcasterClassName(void);

LLDB_API const char *SBProcessGetPluginName(SBProcessRef instance);

LLDB_API const char *SBProcessGetShortPluginName(SBProcessRef instance);

LLDB_API void SBProcessClear(SBProcessRef instance);

LLDB_API bool SBProcessIsValid(SBProcessRef instance);

LLDB_API SBTargetRef SBProcessGetTarget(SBProcessRef instance);

LLDB_API LLDBByteOrder SBProcessGetByteOrder(SBProcessRef instance);

LLDB_API unsigned int SBProcessPutSTDIN(SBProcessRef instance, const char *src, size_t src_len);

LLDB_API unsigned int SBProcessGetSTDOUT(SBProcessRef instance, char *dst, size_t dst_len);

LLDB_API unsigned int SBProcessGetSTDERR(SBProcessRef instance, char *dst, size_t dst_len);

LLDB_API unsigned int SBProcessGetAsyncProfileData(SBProcessRef instance, char *dst, size_t dst_len);

LLDB_API void SBProcessReportEventState(SBProcessRef instance, SBEventRef event, FILE *out);

LLDB_API void SBProcessAppendEventStateReport(SBProcessRef instance, SBEventRef event,
                                                  SBCommandReturnObjectRef result);

LLDB_API bool SBProcessRemoteAttachToProcessWithID(SBProcessRef instance, lldb_pid_t pid,
                                                       SBErrorRef error);

LLDB_API bool SBProcessRemoteLaunch(SBProcessRef instance, const char **argv, const char **envp,
                                        const char *stdin_path, const char *stdout_path, const char *stderr_path,
                                        const char *working_directory, uint32_t launch_flags, bool stop_at_entry,
                                        SBErrorRef error);

LLDB_API unsigned int SBProcessGetNumThreads(SBProcessRef instance);

LLDB_API SBThreadRef SBProcessGetThreadAtIndex(SBProcessRef instance, size_t index);

LLDB_API SBThreadRef SBProcessGetThreadByID(SBProcessRef instance, lldb_tid_t sb_thread_id);

LLDB_API SBThreadRef SBProcessGetThreadByIndexID(SBProcessRef instance, uint32_t index_id);

LLDB_API SBThreadRef SBProcessGetSelectedThread(SBProcessRef instance);

LLDB_API SBThreadRef
SBProcessCreateOSPluginThread(SBProcessRef instance, lldb_tid_t tid, lldb_addr_t context);

LLDB_API bool SBProcessSetSelectedThread(SBProcessRef instance, SBThreadRef thread);

LLDB_API bool SBProcessSetSelectedThreadByID(SBProcessRef instance, lldb_tid_t tid);

LLDB_API bool SBProcessSetSelectedThreadByIndexID(SBProcessRef instance, uint32_t index_id);

LLDB_API unsigned int SBProcessGetNumQueues(SBProcessRef instance);

LLDB_API SBQueueRef SBProcessGetQueueAtIndex(SBProcessRef instance, size_t index);

LLDB_API LLDBStateType SBProcessGetState(SBProcessRef instance);

LLDB_API int SBProcessGetExitStatus(SBProcessRef instance);

LLDB_API const char *SBProcessGetExitDescription(SBProcessRef instance);

LLDB_API unsigned long long SBProcessGetProcessID(SBProcessRef instance);

LLDB_API unsigned int SBProcessGetUniqueID(SBProcessRef instance);

LLDB_API unsigned int SBProcessGetAddressByteSize(SBProcessRef instance);

LLDB_API SBErrorRef SBProcessDestroy(SBProcessRef instance);

LLDB_API SBErrorRef SBProcessContinue(SBProcessRef instance);

LLDB_API SBErrorRef SBProcessStop(SBProcessRef instance);

LLDB_API SBErrorRef SBProcessKill(SBProcessRef instance);

LLDB_API SBErrorRef SBProcessDetach(SBProcessRef instance);

LLDB_API SBErrorRef SBProcessDetach2(SBProcessRef instance, bool keep_stopped);

LLDB_API SBErrorRef SBProcessSignal(SBProcessRef instance, int signal);

LLDB_API SBUnixSignalsRef SBProcessGetUnixSignals(SBProcessRef instance);

LLDB_API void SBProcessSendAsyncInterrupt(SBProcessRef instance);

LLDB_API unsigned int SBProcessGetStopID(SBProcessRef instance, bool include_expression_stops);

LLDB_API unsigned int SBProcessReadMemory(SBProcessRef instance, lldb_addr_t addr, void *buf, size_t size,
                                              SBErrorRef error);

LLDB_API unsigned int SBProcessWriteMemory(SBProcessRef instance, lldb_addr_t addr, void *buf, size_t size,
                                               SBErrorRef error);

LLDB_API unsigned int SBProcessReadCStringFromMemory(SBProcessRef instance, lldb_addr_t addr, void *buf,
                                                         size_t size, SBErrorRef error);

LLDB_API unsigned long long SBProcessReadUnsignedFromMemory(SBProcessRef instance, lldb_addr_t addr,
                                                                uint32_t byte_size, SBErrorRef error);

LLDB_API unsigned long long SBProcessReadPointerFromMemory(SBProcessRef instance, lldb_addr_t addr,
                                                               SBErrorRef error);

LLDB_API LLDBStateType SBProcessGetStateFromEvent(SBEventRef event);

LLDB_API bool SBProcessGetRestartedFromEvent(SBEventRef event);

LLDB_API unsigned int SBProcessGetNumRestartedReasonsFromEvent(SBEventRef event);

LLDB_API const char *SBProcessGetRestartedReasonAtIndexFromEvent(SBEventRef event, size_t idx);

LLDB_API SBProcessRef SBProcessGetProcessFromEvent(SBEventRef event);

LLDB_API bool SBProcessEventIsProcessEvent(SBEventRef event);

LLDB_API SBBroadcasterRef SBProcessGetBroadcaster(SBProcessRef instance);

LLDB_API const char *SBProcessGetBroadcasterClass(void);

LLDB_API bool SBProcessGetDescription(SBProcessRef instance, SBStreamRef description);

LLDB_API unsigned int SBProcessGetNumSupportedHardwareWatchpoints(SBProcessRef instance, SBErrorRef error);

LLDB_API unsigned int SBProcessLoadImage(SBProcessRef instance, SBFileSpecRef image_spec,
                                             SBErrorRef error);

LLDB_API SBErrorRef SBProcessUnloadImage(SBProcessRef instance, uint32_t image_token);

LLDB_API SBErrorRef SBProcessSendEventData(SBProcessRef instance, const char *data);

LLDB_API unsigned int SBProcessGetNumExtendedBacktraceTypes(SBProcessRef instance);

LLDB_API const char *SBProcessGetExtendedBacktraceTypeAtIndex(SBProcessRef instance, uint32_t idx);

LLDB_API SBThreadCollectionRef SBProcessGetHistoryThreads(SBProcessRef instance, lldb_addr_t addr);

LLDB_API bool SBProcessIsInstrumentationRuntimePresent(SBProcessRef instance,
                                                           LLDBInstrumentationRuntimeType type);

#ifdef __cplusplus
}
#endif

#endif // LLDB_SBProcessBinding_h_
