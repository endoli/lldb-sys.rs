//===-- SBUnixSignalsBinding.cpp --------------------------------*- C++ -*-===//
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

using namespace lldb;

#ifdef __cplusplus
extern "C" {
#endif

SBUnixSignalsRef
CreateSBUnixSignals()
{
    return reinterpret_cast<SBUnixSignalsRef>(new SBUnixSignals());
}

void
DisposeSBUnixSignals(SBUnixSignalsRef instance)
{
    delete reinterpret_cast<SBUnixSignals *>(instance);
}

void
SBUnixSignalsClear(SBUnixSignalsRef instance)
{
    SBUnixSignals *unwrapped = reinterpret_cast<SBUnixSignals *>(instance);
    unwrapped->Clear();
}

bool
SBUnixSignalsIsValid(SBUnixSignalsRef instance)
{
    SBUnixSignals *unwrapped = reinterpret_cast<SBUnixSignals *>(instance);
    return unwrapped->IsValid();
}

const char *
SBUnixSignalsGetSignalAsCString(SBUnixSignalsRef instance, int signo)
{
    SBUnixSignals *unwrapped = reinterpret_cast<SBUnixSignals *>(instance);
    return unwrapped->GetSignalAsCString(signo);
}

int
SBUnixSignalsGetSignalNumberFromName(SBUnixSignalsRef instance, const char *name)
{
    SBUnixSignals *unwrapped = reinterpret_cast<SBUnixSignals *>(instance);
    return unwrapped->GetSignalNumberFromName(name);
}

bool
SBUnixSignalsGetShouldSuppress(SBUnixSignalsRef instance, int signo)
{
    SBUnixSignals *unwrapped = reinterpret_cast<SBUnixSignals *>(instance);
    return unwrapped->GetShouldSuppress(signo);
}

bool
SBUnixSignalsSetShouldSuppress(SBUnixSignalsRef instance, int signo, bool value)
{
    SBUnixSignals *unwrapped = reinterpret_cast<SBUnixSignals *>(instance);
    return unwrapped->SetShouldSuppress(signo, value);
}

bool
SBUnixSignalsGetShouldStop(SBUnixSignalsRef instance, int signo)
{
    SBUnixSignals *unwrapped = reinterpret_cast<SBUnixSignals *>(instance);
    return unwrapped->GetShouldStop(signo);
}

bool
SBUnixSignalsSetShouldStop(SBUnixSignalsRef instance, int signo, bool value)
{
    SBUnixSignals *unwrapped = reinterpret_cast<SBUnixSignals *>(instance);
    return unwrapped->SetShouldStop(signo, value);
}

bool
SBUnixSignalsGetShouldNotify(SBUnixSignalsRef instance, int signo)
{
    SBUnixSignals *unwrapped = reinterpret_cast<SBUnixSignals *>(instance);
    return unwrapped->GetShouldNotify(signo);
}

bool
SBUnixSignalsSetShouldNotify(SBUnixSignalsRef instance, int signo, bool value)
{
    SBUnixSignals *unwrapped = reinterpret_cast<SBUnixSignals *>(instance);
    return unwrapped->SetShouldNotify(signo, value);
}

int
SBUnixSignalsGetNumSignals(SBUnixSignalsRef instance)
{
    SBUnixSignals *unwrapped = reinterpret_cast<SBUnixSignals *>(instance);
    return unwrapped->GetNumSignals();
}

int
SBUnixSignalsGetSignalAtIndex(SBUnixSignalsRef instance, int index)
{
    SBUnixSignals *unwrapped = reinterpret_cast<SBUnixSignals *>(instance);
    return unwrapped->GetSignalAtIndex(index);
}

#ifdef __cplusplus
}
#endif
