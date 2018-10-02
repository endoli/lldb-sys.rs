//===-- SBWatchpointBinding.cpp ---------------------------------*- C++ -*-===//
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

SBWatchpointRef
CreateSBWatchpoint()
{
    return reinterpret_cast<SBWatchpointRef>(new SBWatchpoint());
}

SBWatchpointRef
CloneSBWatchpoint(SBWatchpointRef instance)
{
    return reinterpret_cast<SBWatchpointRef>(new SBWatchpoint(*reinterpret_cast<SBWatchpoint *>(instance)));
}

void
DisposeSBWatchpoint(SBWatchpointRef instance)
{
    delete reinterpret_cast<SBWatchpoint *>(instance);
}

bool
SBWatchpointIsValid(SBWatchpointRef instance)
{
    SBWatchpoint *unwrapped = reinterpret_cast<SBWatchpoint *>(instance);
    return unwrapped->IsValid();
}

SBErrorRef
SBWatchpointGetError(SBWatchpointRef instance)
{
    SBWatchpoint *unwrapped = reinterpret_cast<SBWatchpoint *>(instance);
    return reinterpret_cast<SBErrorRef>(new SBError(unwrapped->GetError()));
}

int
SBWatchpointGetID(SBWatchpointRef instance)
{
    SBWatchpoint *unwrapped = reinterpret_cast<SBWatchpoint *>(instance);
    return unwrapped->GetID();
}

int
SBWatchpointGetHardwareIndex(SBWatchpointRef instance)
{
    SBWatchpoint *unwrapped = reinterpret_cast<SBWatchpoint *>(instance);
    return unwrapped->GetHardwareIndex();
}

unsigned long long
SBWatchpointGetWatchAddress(SBWatchpointRef instance)
{
    SBWatchpoint *unwrapped = reinterpret_cast<SBWatchpoint *>(instance);
    return unwrapped->GetWatchAddress();
}

unsigned int
SBWatchpointGetWatchSize(SBWatchpointRef instance)
{
    SBWatchpoint *unwrapped = reinterpret_cast<SBWatchpoint *>(instance);
    return unwrapped->GetWatchSize();
}

void
SBWatchpointSetEnabled(SBWatchpointRef instance, bool enabled)
{
    SBWatchpoint *unwrapped = reinterpret_cast<SBWatchpoint *>(instance);
    unwrapped->SetEnabled(enabled);
}

bool
SBWatchpointIsEnabled(SBWatchpointRef instance)
{
    SBWatchpoint *unwrapped = reinterpret_cast<SBWatchpoint *>(instance);
    return unwrapped->IsEnabled();
}

unsigned int
SBWatchpointGetHitCount(SBWatchpointRef instance)
{
    SBWatchpoint *unwrapped = reinterpret_cast<SBWatchpoint *>(instance);
    return unwrapped->GetHitCount();
}

unsigned int
SBWatchpointGetIgnoreCount(SBWatchpointRef instance)
{
    SBWatchpoint *unwrapped = reinterpret_cast<SBWatchpoint *>(instance);
    return unwrapped->GetIgnoreCount();
}

void
SBWatchpointSetIgnoreCount(SBWatchpointRef instance, uint32_t n)
{
    SBWatchpoint *unwrapped = reinterpret_cast<SBWatchpoint *>(instance);
    unwrapped->SetIgnoreCount(n);
}

const char *
SBWatchpointGetCondition(SBWatchpointRef instance)
{
    SBWatchpoint *unwrapped = reinterpret_cast<SBWatchpoint *>(instance);
    return unwrapped->GetCondition();
}

void
SBWatchpointSetCondition(SBWatchpointRef instance, const char *condition)
{
    SBWatchpoint *unwrapped = reinterpret_cast<SBWatchpoint *>(instance);
    unwrapped->SetCondition(condition);
}

bool
SBWatchpointGetDescription(SBWatchpointRef instance, SBStreamRef description, enum lldb::DescriptionLevel level)
{
    SBWatchpoint *unwrapped = reinterpret_cast<SBWatchpoint *>(instance);
    return unwrapped->GetDescription(*reinterpret_cast<SBStream *>(description), level);
}

void
SBWatchpointClear(SBWatchpointRef instance)
{
    SBWatchpoint *unwrapped = reinterpret_cast<SBWatchpoint *>(instance);
    unwrapped->Clear();
}

bool
SBWatchpointEventIsWatchpointEvent(SBEventRef event)
{
    return lldb::SBWatchpoint::EventIsWatchpointEvent(*reinterpret_cast<SBEvent *>(event));
}

lldb::WatchpointEventType
SBWatchpointGetWatchpointEventTypeFromEvent(SBEventRef event)
{
    return lldb::SBWatchpoint::GetWatchpointEventTypeFromEvent(*reinterpret_cast<SBEvent *>(event));
}

SBWatchpointRef
SBWatchpointGetWatchpointFromEvent(SBEventRef event)
{
    return reinterpret_cast<SBWatchpointRef>(
        new SBWatchpoint(lldb::SBWatchpoint::GetWatchpointFromEvent(*reinterpret_cast<SBEvent *>(event))));
}

#ifdef __cplusplus
}
#endif
