//===-- SBMemoryRegionInfoBinding.cpp ---------------------------*- C++ -*-===//
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

SBMemoryRegionInfoRef
CreateSBMemoryRegionInfo()
{
    return reinterpret_cast<SBMemoryRegionInfoRef>(new SBMemoryRegionInfo());
}

SBMemoryRegionInfoRef
CloneSBMemoryRegionInfo(SBMemoryRegionInfoRef instance)
{
    return reinterpret_cast<SBMemoryRegionInfoRef>(new SBMemoryRegionInfo(*reinterpret_cast<SBMemoryRegionInfo *>(instance)));
}

void
DisposeSBMemoryRegionInfo(SBMemoryRegionInfoRef instance)
{
    delete reinterpret_cast<SBMemoryRegionInfo *>(instance);
}

void
SBMemoryRegionInfoClear(SBMemoryRegionInfoRef instance)
{
    SBMemoryRegionInfo *unwrapped = reinterpret_cast<SBMemoryRegionInfo *>(instance);
    unwrapped->Clear();
}

lldb_addr_t
SBMemoryRegionInfoGetRegionBase(SBMemoryRegionInfoRef instance)
{
    SBMemoryRegionInfo *unwrapped = reinterpret_cast<SBMemoryRegionInfo *>(instance);
    return unwrapped->GetRegionBase();
}

lldb_addr_t
SBMemoryRegionInfoGetRegionEnd(SBMemoryRegionInfoRef instance)
{
    SBMemoryRegionInfo *unwrapped = reinterpret_cast<SBMemoryRegionInfo *>(instance);
    return unwrapped->GetRegionEnd();
}

bool
SBMemoryRegionInfoIsReadable(SBMemoryRegionInfoRef instance)
{
    SBMemoryRegionInfo *unwrapped = reinterpret_cast<SBMemoryRegionInfo *>(instance);
    return unwrapped->IsReadable();
}

bool
SBMemoryRegionInfoIsWritable(SBMemoryRegionInfoRef instance)
{
    SBMemoryRegionInfo *unwrapped = reinterpret_cast<SBMemoryRegionInfo *>(instance);
    return unwrapped->IsWritable();
}

bool
SBMemoryRegionInfoIsExecutable(SBMemoryRegionInfoRef instance)
{
    SBMemoryRegionInfo *unwrapped = reinterpret_cast<SBMemoryRegionInfo *>(instance);
    return unwrapped->IsExecutable();
}

bool
SBMemoryRegionInfoIsMapped(SBMemoryRegionInfoRef instance)
{
    SBMemoryRegionInfo *unwrapped = reinterpret_cast<SBMemoryRegionInfo *>(instance);
    return unwrapped->IsMapped();
}

const char *
SBMemoryRegionInfoGetName(SBMemoryRegionInfoRef instance)
{
    SBMemoryRegionInfo *unwrapped = reinterpret_cast<SBMemoryRegionInfo *>(instance);
    return unwrapped->GetName();
}

bool
SBMemoryRegionInfoGetDescription(SBMemoryRegionInfoRef instance, SBStreamRef description)
{
    SBMemoryRegionInfo *unwrapped = reinterpret_cast<SBMemoryRegionInfo *>(instance);
    return unwrapped->GetDescription(*reinterpret_cast<SBStream *>(description));
}

#ifdef __cplusplus
}
#endif

