//===-- SBInstructionListBinding.cpp ----------------------------*- C++ -*-===//
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

SBInstructionListRef
CreateSBInstructionList()
{
    return reinterpret_cast<SBInstructionListRef>(new SBInstructionList());
}

SBInstructionListRef
CloneSBInstructionList(SBInstructionListRef instance)
{
    return reinterpret_cast<SBInstructionListRef>(new SBInstructionList(*reinterpret_cast<SBInstructionList *>(instance)));
}

void
DisposeSBInstructionList(SBInstructionListRef instance)
{
    delete reinterpret_cast<SBInstructionList *>(instance);
}

bool
SBInstructionListIsValid(SBInstructionListRef instance)
{
    SBInstructionList *unwrapped = reinterpret_cast<SBInstructionList *>(instance);
    return unwrapped->IsValid();
}

unsigned int
SBInstructionListGetSize(SBInstructionListRef instance)
{
    SBInstructionList *unwrapped = reinterpret_cast<SBInstructionList *>(instance);
    return unwrapped->GetSize();
}

SBInstructionRef
SBInstructionListGetInstructionAtIndex(SBInstructionListRef instance, uint32_t idx)
{
    SBInstructionList *unwrapped = reinterpret_cast<SBInstructionList *>(instance);
    return reinterpret_cast<SBInstructionRef>(new SBInstruction(unwrapped->GetInstructionAtIndex(idx)));
}

void
SBInstructionListClear(SBInstructionListRef instance)
{
    SBInstructionList *unwrapped = reinterpret_cast<SBInstructionList *>(instance);
    unwrapped->Clear();
}

void
SBInstructionListAppendInstruction(SBInstructionListRef instance, SBInstructionRef inst)
{
    SBInstructionList *unwrapped = reinterpret_cast<SBInstructionList *>(instance);
    unwrapped->AppendInstruction(*reinterpret_cast<SBInstruction *>(inst));
}

void
SBInstructionListPrint(SBInstructionListRef instance, FILE *out)
{
    SBInstructionList *unwrapped = reinterpret_cast<SBInstructionList *>(instance);
    unwrapped->Print(out);
}

bool
SBInstructionListGetDescription(SBInstructionListRef instance, SBStreamRef description)
{
    SBInstructionList *unwrapped = reinterpret_cast<SBInstructionList *>(instance);
    return unwrapped->GetDescription(*reinterpret_cast<SBStream *>(description));
}

bool
SBInstructionListDumpEmulationForAllInstructions(SBInstructionListRef instance, const char *triple)
{
    SBInstructionList *unwrapped = reinterpret_cast<SBInstructionList *>(instance);
    return unwrapped->DumpEmulationForAllInstructions(triple);
}

#ifdef __cplusplus
}
#endif
