//===-- SBProcessBinding.cpp ------------------------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "lldb/Bindings/LLDBBinding.h"
#include "lldb/API/LLDB.h"
#include "lldb/API/SBUnixSignals.h"
#include "lldb/API/SBThreadCollection.h"

using namespace lldb;

#ifdef __cplusplus
extern "C" {
#endif

SBProcessRef
CreateSBProcess()
{
    return reinterpret_cast<SBProcessRef>(new SBProcess());
}

void
DisposeSBProcess(SBProcessRef instance)
{
    delete reinterpret_cast<SBProcess *>(instance);
}

const char *
SBProcessGetBroadcasterClassName()
{
    return lldb::SBProcess::GetBroadcasterClassName();
}

const char *
SBProcessGetPluginName(SBProcessRef instance)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return unwrapped->GetPluginName();
}

const char *
SBProcessGetShortPluginName(SBProcessRef instance)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return unwrapped->GetShortPluginName();
}

void
SBProcessClear(SBProcessRef instance)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    unwrapped->Clear();
}

bool
SBProcessIsValid(SBProcessRef instance)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return unwrapped->IsValid();
}

SBTargetRef
SBProcessGetTarget(SBProcessRef instance)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return reinterpret_cast<SBTargetRef>(new SBTarget(unwrapped->GetTarget()));
}

enum lldb::ByteOrder
SBProcessGetByteOrder(SBProcessRef instance)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return unwrapped->GetByteOrder();
}

unsigned int
SBProcessPutSTDIN(SBProcessRef instance, const char *src, size_t src_len)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return unwrapped->PutSTDIN(src, src_len);
}

unsigned int
SBProcessGetSTDOUT(SBProcessRef instance, char *dst, size_t dst_len)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return unwrapped->GetSTDOUT(dst, dst_len);
}

unsigned int
SBProcessGetSTDERR(SBProcessRef instance, char *dst, size_t dst_len)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return unwrapped->GetSTDERR(dst, dst_len);
}

unsigned int
SBProcessGetAsyncProfileData(SBProcessRef instance, char *dst, size_t dst_len)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return unwrapped->GetAsyncProfileData(dst, dst_len);
}

void
SBProcessReportEventState(SBProcessRef instance, SBEventRef event, FILE *out)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    unwrapped->ReportEventState(*reinterpret_cast<SBEvent *>(event), reinterpret_cast<FILE *>(out));
}

void
SBProcessAppendEventStateReport(SBProcessRef instance, SBEventRef event,
                                    SBCommandReturnObjectRef result)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    unwrapped->AppendEventStateReport(*reinterpret_cast<SBEvent *>(event),
                                      *reinterpret_cast<SBCommandReturnObject *>(result));
}

bool
SBProcessRemoteAttachToProcessWithID(SBProcessRef instance, lldb_pid_t pid, SBErrorRef error)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return unwrapped->RemoteAttachToProcessWithID(pid, *reinterpret_cast<SBError *>(error));
}

bool
SBProcessRemoteLaunch(SBProcessRef instance, const char **argv, const char **envp, const char *stdin_path,
                          const char *stdout_path, const char *stderr_path, const char *working_directory,
                          uint32_t launch_flags, bool stop_at_entry, SBErrorRef error)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return unwrapped->RemoteLaunch(argv, envp, stdin_path, stdout_path, stderr_path, working_directory, launch_flags,
                                   stop_at_entry, *reinterpret_cast<SBError *>(error));
}

unsigned int
SBProcessGetNumThreads(SBProcessRef instance)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return unwrapped->GetNumThreads();
}

SBThreadRef
SBProcessGetThreadAtIndex(SBProcessRef instance, size_t index)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return reinterpret_cast<SBThreadRef>(new SBThread(unwrapped->GetThreadAtIndex(index)));
}

SBThreadRef
SBProcessGetThreadByID(SBProcessRef instance, lldb_tid_t sb_thread_id)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return reinterpret_cast<SBThreadRef>(new SBThread(unwrapped->GetThreadByID(sb_thread_id)));
}

SBThreadRef
SBProcessGetThreadByIndexID(SBProcessRef instance, uint32_t index_id)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return reinterpret_cast<SBThreadRef>(new SBThread(unwrapped->GetThreadByIndexID(index_id)));
}

SBThreadRef
SBProcessGetSelectedThread(SBProcessRef instance)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return reinterpret_cast<SBThreadRef>(new SBThread(unwrapped->GetSelectedThread()));
}

SBThreadRef
SBProcessCreateOSPluginThread(SBProcessRef instance, lldb_tid_t tid, lldb_addr_t context)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return reinterpret_cast<SBThreadRef>(new SBThread(unwrapped->CreateOSPluginThread(tid, context)));
}

bool
SBProcessSetSelectedThread(SBProcessRef instance, SBThreadRef thread)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return unwrapped->SetSelectedThread(*reinterpret_cast<SBThread *>(thread));
}

bool
SBProcessSetSelectedThreadByID(SBProcessRef instance, lldb_tid_t tid)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return unwrapped->SetSelectedThreadByID(tid);
}

bool
SBProcessSetSelectedThreadByIndexID(SBProcessRef instance, uint32_t index_id)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return unwrapped->SetSelectedThreadByIndexID(index_id);
}

unsigned int
SBProcessGetNumQueues(SBProcessRef instance)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return unwrapped->GetNumQueues();
}

SBQueueRef
SBProcessGetQueueAtIndex(SBProcessRef instance, size_t index)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return reinterpret_cast<SBQueueRef>(new SBQueue(unwrapped->GetQueueAtIndex(index)));
}

lldb::StateType
SBProcessGetState(SBProcessRef instance)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return unwrapped->GetState();
}

int
SBProcessGetExitStatus(SBProcessRef instance)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return unwrapped->GetExitStatus();
}

const char *
SBProcessGetExitDescription(SBProcessRef instance)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return unwrapped->GetExitDescription();
}

unsigned long long
SBProcessGetProcessID(SBProcessRef instance)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return unwrapped->GetProcessID();
}

unsigned int
SBProcessGetUniqueID(SBProcessRef instance)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return unwrapped->GetUniqueID();
}

unsigned int
SBProcessGetAddressByteSize(SBProcessRef instance)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return unwrapped->GetAddressByteSize();
}

SBErrorRef
SBProcessDestroy(SBProcessRef instance)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return reinterpret_cast<SBErrorRef>(new SBError(unwrapped->Destroy()));
}

SBErrorRef
SBProcessContinue(SBProcessRef instance)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return reinterpret_cast<SBErrorRef>(new SBError(unwrapped->Continue()));
}

SBErrorRef
SBProcessStop(SBProcessRef instance)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return reinterpret_cast<SBErrorRef>(new SBError(unwrapped->Stop()));
}

SBErrorRef
SBProcessKill(SBProcessRef instance)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return reinterpret_cast<SBErrorRef>(new SBError(unwrapped->Kill()));
}

SBErrorRef
SBProcessDetach(SBProcessRef instance)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return reinterpret_cast<SBErrorRef>(new SBError(unwrapped->Detach()));
}

SBErrorRef
SBProcessDetach2(SBProcessRef instance, bool keep_stopped)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return reinterpret_cast<SBErrorRef>(new SBError(unwrapped->Detach(keep_stopped)));
}

SBErrorRef
SBProcessSignal(SBProcessRef instance, int signal)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return reinterpret_cast<SBErrorRef>(new SBError(unwrapped->Signal(signal)));
}

SBUnixSignalsRef
SBProcessGetUnixSignals(SBProcessRef instance)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return reinterpret_cast<SBUnixSignalsRef>(new SBUnixSignals(unwrapped->GetUnixSignals()));
}

void
SBProcessSendAsyncInterrupt(SBProcessRef instance)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    unwrapped->SendAsyncInterrupt();
}

unsigned int
SBProcessGetStopID(SBProcessRef instance, bool include_expression_stops)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return unwrapped->GetStopID(include_expression_stops);
}

unsigned int
SBProcessReadMemory(SBProcessRef instance, lldb_addr_t addr, void *buf, size_t size, SBErrorRef error)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return unwrapped->ReadMemory(addr, buf, size, *reinterpret_cast<SBError *>(error));
}

unsigned int
SBProcessWriteMemory(SBProcessRef instance, lldb_addr_t addr, void *buf, size_t size, SBErrorRef error)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return unwrapped->WriteMemory(addr, buf, size, *reinterpret_cast<SBError *>(error));
}

unsigned int
SBProcessReadCStringFromMemory(SBProcessRef instance, lldb_addr_t addr, void *buf, size_t size,
                                   SBErrorRef error)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return unwrapped->ReadCStringFromMemory(addr, buf, size, *reinterpret_cast<SBError *>(error));
}

unsigned long long
SBProcessReadUnsignedFromMemory(SBProcessRef instance, lldb_addr_t addr, uint32_t byte_size,
                                    SBErrorRef error)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return unwrapped->ReadUnsignedFromMemory(addr, byte_size, *reinterpret_cast<SBError *>(error));
}

unsigned long long
SBProcessReadPointerFromMemory(SBProcessRef instance, lldb_addr_t addr, SBErrorRef error)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return unwrapped->ReadPointerFromMemory(addr, *reinterpret_cast<SBError *>(error));
}

lldb::StateType
SBProcessGetStateFromEvent(SBEventRef event)
{
    return lldb::SBProcess::GetStateFromEvent(*reinterpret_cast<SBEvent *>(event));
}

bool
SBProcessGetRestartedFromEvent(SBEventRef event)
{
    return lldb::SBProcess::GetRestartedFromEvent(*reinterpret_cast<SBEvent *>(event));
}

unsigned int
SBProcessGetNumRestartedReasonsFromEvent(SBEventRef event)
{
    return lldb::SBProcess::GetNumRestartedReasonsFromEvent(*reinterpret_cast<SBEvent *>(event));
}

const char *
SBProcessGetRestartedReasonAtIndexFromEvent(SBEventRef event, size_t idx)
{
    return lldb::SBProcess::GetRestartedReasonAtIndexFromEvent(*reinterpret_cast<SBEvent *>(event), idx);
}

SBProcessRef
SBProcessGetProcessFromEvent(SBEventRef event)
{
    return reinterpret_cast<SBProcessRef>(
        new SBProcess(lldb::SBProcess::GetProcessFromEvent(*reinterpret_cast<SBEvent *>(event))));
}

bool
SBProcessGetInterruptedFromEvent(SBEventRef event)
{
    return lldb::SBProcess::GetInterruptedFromEvent(*reinterpret_cast<SBEvent *>(event));
}

SBStructuredDataRef
SBProcessGetStructuredDataFromEvent(SBEventRef event)
{
    return reinterpret_cast<SBStructuredDataRef>(
        new SBStructuredData(lldb::SBProcess::GetStructuredDataFromEvent(*reinterpret_cast<SBEvent *>(event))));
}

bool
SBProcessEventIsProcessEvent(SBEventRef event)
{
    return lldb::SBProcess::EventIsProcessEvent(*reinterpret_cast<SBEvent *>(event));
}

bool
SBProcessEventIsStructuredDataEvent(SBEventRef event)
{
    return lldb::SBProcess::EventIsStructuredDataEvent(*reinterpret_cast<SBEvent *>(event));
}

SBBroadcasterRef
SBProcessGetBroadcaster(SBProcessRef instance)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return reinterpret_cast<SBBroadcasterRef>(new SBBroadcaster(unwrapped->GetBroadcaster()));
}

const char *
SBProcessGetBroadcasterClass()
{
    return lldb::SBProcess::GetBroadcasterClass();
}

bool
SBProcessGetDescription(SBProcessRef instance, SBStreamRef description)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return unwrapped->GetDescription(*reinterpret_cast<SBStream *>(description));
}

unsigned int
SBProcessGetNumSupportedHardwareWatchpoints(SBProcessRef instance, SBErrorRef error)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return unwrapped->GetNumSupportedHardwareWatchpoints(*reinterpret_cast<SBError *>(error));
}

unsigned int
SBProcessLoadImage(SBProcessRef instance, SBFileSpecRef image_spec, SBErrorRef error)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return unwrapped->LoadImage(*reinterpret_cast<SBFileSpec *>(image_spec), *reinterpret_cast<SBError *>(error));
}

SBErrorRef
SBProcessUnloadImage(SBProcessRef instance, uint32_t image_token)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return reinterpret_cast<SBErrorRef>(new SBError(unwrapped->UnloadImage(image_token)));
}

SBErrorRef
SBProcessSendEventData(SBProcessRef instance, const char *data)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return reinterpret_cast<SBErrorRef>(new SBError(unwrapped->SendEventData(data)));
}

unsigned int
SBProcessGetNumExtendedBacktraceTypes(SBProcessRef instance)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return unwrapped->GetNumExtendedBacktraceTypes();
}

const char *
SBProcessGetExtendedBacktraceTypeAtIndex(SBProcessRef instance, uint32_t idx)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return unwrapped->GetExtendedBacktraceTypeAtIndex(idx);
}

SBThreadCollectionRef
SBProcessGetHistoryThreads(SBProcessRef instance, lldb_addr_t addr)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return reinterpret_cast<SBThreadCollectionRef>(new SBThreadCollection(unwrapped->GetHistoryThreads(addr)));
}

bool
SBProcessIsInstrumentationRuntimePresent(SBProcessRef instance, enum lldb::InstrumentationRuntimeType type)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return unwrapped->IsInstrumentationRuntimePresent(type);
}

SBErrorRef
SBProcessSaveCore(SBProcessRef instance, const char *file_name)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return reinterpret_cast<SBErrorRef>(new SBError(unwrapped->SaveCore(file_name)));
}

SBProcessInfoRef
SBProcessGetProcessInfo(SBProcessRef instance)
{
    SBProcess *unwrapped = reinterpret_cast<SBProcess *>(instance);
    return reinterpret_cast<SBProcessInfoRef>(new SBProcessInfo(unwrapped->GetProcessInfo()));
}

#ifdef __cplusplus
}
#endif
