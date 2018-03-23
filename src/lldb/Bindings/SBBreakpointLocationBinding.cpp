//===-- SBBreakpointLocationBinding.cpp -------------------------*- C++ -*-===//
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

SBBreakpointLocationRef
CreateSBBreakpointLocation()
{
    return reinterpret_cast<SBBreakpointLocationRef>(new SBBreakpointLocation());
}

void
DisposeSBBreakpointLocation(SBBreakpointLocationRef instance)
{
    delete reinterpret_cast<SBBreakpointLocation *>(instance);
}

int
SBBreakpointLocationGetID(SBBreakpointLocationRef instance)
{
    SBBreakpointLocation *unwrapped = reinterpret_cast<SBBreakpointLocation *>(instance);
    return unwrapped->GetID();
}

bool
SBBreakpointLocationIsValid(SBBreakpointLocationRef instance)
{
    SBBreakpointLocation *unwrapped = reinterpret_cast<SBBreakpointLocation *>(instance);
    return unwrapped->IsValid();
}

SBAddressRef
SBBreakpointLocationGetAddress(SBBreakpointLocationRef instance)
{
    SBBreakpointLocation *unwrapped = reinterpret_cast<SBBreakpointLocation *>(instance);
    return reinterpret_cast<SBAddressRef>(new SBAddress(unwrapped->GetAddress()));
}

unsigned long long
SBBreakpointLocationGetLoadAddress(SBBreakpointLocationRef instance)
{
    SBBreakpointLocation *unwrapped = reinterpret_cast<SBBreakpointLocation *>(instance);
    return unwrapped->GetLoadAddress();
}

void
SBBreakpointLocationSetEnabled(SBBreakpointLocationRef instance, bool enabled)
{
    SBBreakpointLocation *unwrapped = reinterpret_cast<SBBreakpointLocation *>(instance);
    unwrapped->SetEnabled(enabled);
}

bool
SBBreakpointLocationIsEnabled(SBBreakpointLocationRef instance)
{
    SBBreakpointLocation *unwrapped = reinterpret_cast<SBBreakpointLocation *>(instance);
    return unwrapped->IsEnabled();
}

uint32_t
SBBreakpointLocationGetHitCount(SBBreakpointLocationRef instance)
{
    SBBreakpointLocation *unwrapped = reinterpret_cast<SBBreakpointLocation *>(instance);
    return unwrapped->GetHitCount();
}

unsigned int
SBBreakpointLocationGetIgnoreCount(SBBreakpointLocationRef instance)
{
    SBBreakpointLocation *unwrapped = reinterpret_cast<SBBreakpointLocation *>(instance);
    return unwrapped->GetIgnoreCount();
}

void
SBBreakpointLocationSetIgnoreCount(SBBreakpointLocationRef instance, uint32_t n)
{
    SBBreakpointLocation *unwrapped = reinterpret_cast<SBBreakpointLocation *>(instance);
    unwrapped->SetIgnoreCount(n);
}

void
SBBreakpointLocationSetCondition(SBBreakpointLocationRef instance, const char *condition)
{
    SBBreakpointLocation *unwrapped = reinterpret_cast<SBBreakpointLocation *>(instance);
    unwrapped->SetCondition(condition);
}

const char *
SBBreakpointLocationGetCondition(SBBreakpointLocationRef instance)
{
    SBBreakpointLocation *unwrapped = reinterpret_cast<SBBreakpointLocation *>(instance);
    return unwrapped->GetCondition();
}

void
SBBreakpointLocationSetScriptCallbackFunction(SBBreakpointLocationRef instance,
                                                  const char *callback_function_name)
{
    SBBreakpointLocation *unwrapped = reinterpret_cast<SBBreakpointLocation *>(instance);
    unwrapped->SetScriptCallbackFunction(callback_function_name);
}

SBErrorRef
SBBreakpointLocationSetScriptCallbackBody(SBBreakpointLocationRef instance, const char *script_body_text)
{
    SBBreakpointLocation *unwrapped = reinterpret_cast<SBBreakpointLocation *>(instance);
    return reinterpret_cast<SBErrorRef>(new SBError(unwrapped->SetScriptCallbackBody(script_body_text)));
}

void
SBBreakpointLocationSetThreadID(SBBreakpointLocationRef instance, lldb_tid_t sb_thread_id)
{
    SBBreakpointLocation *unwrapped = reinterpret_cast<SBBreakpointLocation *>(instance);
    unwrapped->SetThreadID(sb_thread_id);
}

unsigned long long
SBBreakpointLocationGetThreadID(SBBreakpointLocationRef instance)
{
    SBBreakpointLocation *unwrapped = reinterpret_cast<SBBreakpointLocation *>(instance);
    return unwrapped->GetThreadID();
}

void
SBBreakpointLocationSetThreadIndex(SBBreakpointLocationRef instance, uint32_t index)
{
    SBBreakpointLocation *unwrapped = reinterpret_cast<SBBreakpointLocation *>(instance);
    unwrapped->SetThreadIndex(index);
}

unsigned int
SBBreakpointLocationGetThreadIndex(SBBreakpointLocationRef instance)
{
    SBBreakpointLocation *unwrapped = reinterpret_cast<SBBreakpointLocation *>(instance);
    return unwrapped->GetThreadIndex();
}

void
SBBreakpointLocationSetThreadName(SBBreakpointLocationRef instance, const char *thread_name)
{
    SBBreakpointLocation *unwrapped = reinterpret_cast<SBBreakpointLocation *>(instance);
    unwrapped->SetThreadName(thread_name);
}

const char *
SBBreakpointLocationGetThreadName(SBBreakpointLocationRef instance)
{
    SBBreakpointLocation *unwrapped = reinterpret_cast<SBBreakpointLocation *>(instance);
    return unwrapped->GetThreadName();
}

void
SBBreakpointLocationSetQueueName(SBBreakpointLocationRef instance, const char *queue_name)
{
    SBBreakpointLocation *unwrapped = reinterpret_cast<SBBreakpointLocation *>(instance);
    unwrapped->SetQueueName(queue_name);
}

const char *
SBBreakpointLocationGetQueueName(SBBreakpointLocationRef instance)
{
    SBBreakpointLocation *unwrapped = reinterpret_cast<SBBreakpointLocation *>(instance);
    return unwrapped->GetQueueName();
}

bool
SBBreakpointLocationIsResolved(SBBreakpointLocationRef instance)
{
    SBBreakpointLocation *unwrapped = reinterpret_cast<SBBreakpointLocation *>(instance);
    return unwrapped->IsResolved();
}

bool
SBBreakpointLocationGetDescription(SBBreakpointLocationRef instance, SBStreamRef description,
                                       enum lldb::DescriptionLevel level)
{
    SBBreakpointLocation *unwrapped = reinterpret_cast<SBBreakpointLocation *>(instance);
    return unwrapped->GetDescription(*reinterpret_cast<SBStream *>(description), level);
}

SBBreakpointRef
SBBreakpointLocationGetBreakpoint(SBBreakpointLocationRef instance)
{
    SBBreakpointLocation *unwrapped = reinterpret_cast<SBBreakpointLocation *>(instance);
    return reinterpret_cast<SBBreakpointRef>(new SBBreakpoint(unwrapped->GetBreakpoint()));
}

#ifdef __cplusplus
}
#endif
