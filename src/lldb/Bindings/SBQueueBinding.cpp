//===-- SBQueueBinding.cpp --------------------------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "lldb/Bindings/LLDBBinding.h"
#include "lldb/API/LLDB.h"

using namespace lldb;

#ifdef __cplusplus
extern "C" {
#endif

SBQueueRef
CreateSBQueue()
{
    return reinterpret_cast<SBQueueRef>(new SBQueue());
}

SBQueueRef
CloneSBQueue(SBQueueRef instance)
{
    return reinterpret_cast<SBQueueRef>(new SBQueue(*reinterpret_cast<SBQueue *>(instance)));
}

void
DisposeSBQueue(SBQueueRef instance)
{
    delete reinterpret_cast<SBQueue *>(instance);
}

bool
SBQueueIsValid(SBQueueRef instance)
{
    SBQueue *unwrapped = reinterpret_cast<SBQueue *>(instance);
    return unwrapped->IsValid();
}

void
SBQueueClear(SBQueueRef instance)
{
    SBQueue *unwrapped = reinterpret_cast<SBQueue *>(instance);
    unwrapped->Clear();
}

SBProcessRef
SBQueueGetProcess(SBQueueRef instance)
{
    SBQueue *unwrapped = reinterpret_cast<SBQueue *>(instance);
    return reinterpret_cast<SBProcessRef>(new SBProcess(unwrapped->GetProcess()));
}

unsigned long long
SBQueueGetQueueID(SBQueueRef instance)
{
    SBQueue *unwrapped = reinterpret_cast<SBQueue *>(instance);
    return unwrapped->GetQueueID();
}

const char *
SBQueueGetName(SBQueueRef instance)
{
    SBQueue *unwrapped = reinterpret_cast<SBQueue *>(instance);
    return unwrapped->GetName();
}

unsigned int
SBQueueGetIndexID(SBQueueRef instance)
{
    SBQueue *unwrapped = reinterpret_cast<SBQueue *>(instance);
    return unwrapped->GetIndexID();
}

unsigned int
SBQueueGetNumThreads(SBQueueRef instance)
{
    SBQueue *unwrapped = reinterpret_cast<SBQueue *>(instance);
    return unwrapped->GetNumThreads();
}

SBThreadRef
SBQueueGetThreadAtIndex(SBQueueRef instance, uint32_t var0)
{
    SBQueue *unwrapped = reinterpret_cast<SBQueue *>(instance);
    return reinterpret_cast<SBThreadRef>(new SBThread(unwrapped->GetThreadAtIndex(var0)));
}

unsigned int
SBQueueGetNumPendingItems(SBQueueRef instance)
{
    SBQueue *unwrapped = reinterpret_cast<SBQueue *>(instance);
    return unwrapped->GetNumPendingItems();
}

SBQueueItemRef
SBQueueGetPendingItemAtIndex(SBQueueRef instance, uint32_t var0)
{
    SBQueue *unwrapped = reinterpret_cast<SBQueue *>(instance);
    return reinterpret_cast<SBQueueItemRef>(new SBQueueItem(unwrapped->GetPendingItemAtIndex(var0)));
}

unsigned int
SBQueueGetNumRunningItems(SBQueueRef instance)
{
    SBQueue *unwrapped = reinterpret_cast<SBQueue *>(instance);
    return unwrapped->GetNumRunningItems();
}

enum lldb::QueueKind
SBQueueGetKind(SBQueueRef instance)
{
    SBQueue *unwrapped = reinterpret_cast<SBQueue *>(instance);
    return unwrapped->GetKind();
}

#ifdef __cplusplus
}
#endif
