//===-- SBBlockBinding.cpp --------------------------------------*- C++ -*-===//
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

SBBlockRef
CreateSBBlock()
{
    return reinterpret_cast<SBBlockRef>(new SBBlock());
}

SBBlockRef
CloneSBBlock(SBBlockRef instance)
{
    return reinterpret_cast<SBBlockRef>(new SBBlock(*reinterpret_cast<SBBlock *>(instance)));
}

void
DisposeSBBlock(SBBlockRef instance)
{
    delete reinterpret_cast<SBBlock *>(instance);
}

bool
SBBlockIsInlined(SBBlockRef instance)
{
    SBBlock *unwrapped = reinterpret_cast<SBBlock *>(instance);
    return unwrapped->IsInlined();
}

bool
SBBlockIsValid(SBBlockRef instance)
{
    SBBlock *unwrapped = reinterpret_cast<SBBlock *>(instance);
    return unwrapped->IsValid();
}

const char *
SBBlockGetInlinedName(SBBlockRef instance)
{
    SBBlock *unwrapped = reinterpret_cast<SBBlock *>(instance);
    return unwrapped->GetInlinedName();
}

SBFileSpecRef
SBBlockGetInlinedCallSiteFile(SBBlockRef instance)
{
    SBBlock *unwrapped = reinterpret_cast<SBBlock *>(instance);
    return reinterpret_cast<SBFileSpecRef>(new SBFileSpec(unwrapped->GetInlinedCallSiteFile()));
}

unsigned int
SBBlockGetInlinedCallSiteLine(SBBlockRef instance)
{
    SBBlock *unwrapped = reinterpret_cast<SBBlock *>(instance);
    return unwrapped->GetInlinedCallSiteLine();
}

unsigned int
SBBlockGetInlinedCallSiteColumn(SBBlockRef instance)
{
    SBBlock *unwrapped = reinterpret_cast<SBBlock *>(instance);
    return unwrapped->GetInlinedCallSiteColumn();
}

SBBlockRef
SBBlockGetParent(SBBlockRef instance)
{
    SBBlock *unwrapped = reinterpret_cast<SBBlock *>(instance);
    return reinterpret_cast<SBBlockRef>(new SBBlock(unwrapped->GetParent()));
}

SBBlockRef
SBBlockGetSibling(SBBlockRef instance)
{
    SBBlock *unwrapped = reinterpret_cast<SBBlock *>(instance);
    return reinterpret_cast<SBBlockRef>(new SBBlock(unwrapped->GetSibling()));
}

SBBlockRef
SBBlockGetFirstChild(SBBlockRef instance)
{
    SBBlock *unwrapped = reinterpret_cast<SBBlock *>(instance);
    return reinterpret_cast<SBBlockRef>(new SBBlock(unwrapped->GetFirstChild()));
}

unsigned int
SBBlockGetNumRanges(SBBlockRef instance)
{
    SBBlock *unwrapped = reinterpret_cast<SBBlock *>(instance);
    return unwrapped->GetNumRanges();
}

SBAddressRef
SBBlockGetRangeStartAddress(SBBlockRef instance, uint32_t idx)
{
    SBBlock *unwrapped = reinterpret_cast<SBBlock *>(instance);
    return reinterpret_cast<SBAddressRef>(new SBAddress(unwrapped->GetRangeStartAddress(idx)));
}

SBAddressRef
SBBlockGetRangeEndAddress(SBBlockRef instance, uint32_t idx)
{
    SBBlock *unwrapped = reinterpret_cast<SBBlock *>(instance);
    return reinterpret_cast<SBAddressRef>(new SBAddress(unwrapped->GetRangeEndAddress(idx)));
}

unsigned int
SBBlockGetRangeIndexForBlockAddress(SBBlockRef instance, SBAddressRef block_addr)
{
    SBBlock *unwrapped = reinterpret_cast<SBBlock *>(instance);
    return unwrapped->GetRangeIndexForBlockAddress(*reinterpret_cast<SBAddress *>(block_addr));
}

SBValueListRef
SBBlockGetVariables(SBBlockRef instance, SBFrameRef frame, bool arguments, bool locals, bool statics,
                        lldb::DynamicValueType use_dynamic)
{
    SBBlock *unwrapped = reinterpret_cast<SBBlock *>(instance);
    return reinterpret_cast<SBValueListRef>(new SBValueList(
        unwrapped->GetVariables(*reinterpret_cast<SBFrame *>(frame), arguments, locals, statics, use_dynamic)));
}

SBValueListRef
SBBlockGetVariables2(SBBlockRef instance, SBTargetRef target, bool arguments, bool locals, bool statics)
{
    SBBlock *unwrapped = reinterpret_cast<SBBlock *>(instance);
    return reinterpret_cast<SBValueListRef>(
        new SBValueList(unwrapped->GetVariables(*reinterpret_cast<SBTarget *>(target), arguments, locals, statics)));
}

SBBlockRef
SBBlockGetContainingInlinedBlock(SBBlockRef instance)
{
    SBBlock *unwrapped = reinterpret_cast<SBBlock *>(instance);
    return reinterpret_cast<SBBlockRef>(new SBBlock(unwrapped->GetContainingInlinedBlock()));
}

bool
SBBlockGetDescription(SBBlockRef instance, SBStreamRef description)
{
    SBBlock *unwrapped = reinterpret_cast<SBBlock *>(instance);
    return unwrapped->GetDescription(*reinterpret_cast<SBStream *>(description));
}

#ifdef __cplusplus
}
#endif
