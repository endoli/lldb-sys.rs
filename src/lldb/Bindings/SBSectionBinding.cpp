//===-- SBSectionBinding.cpp ------------------------------------*- C++ -*-===//
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

SBSectionRef
CreateSBSection()
{
    return reinterpret_cast<SBSectionRef>(new SBSection());
}

SBSectionRef
CloneSBSection(SBSectionRef instance)
{
    return reinterpret_cast<SBSectionRef>(new SBSection(*reinterpret_cast<SBSection *>(instance)));
}

void
DisposeSBSection(SBSectionRef instance)
{
    delete reinterpret_cast<SBSection *>(instance);
}

bool
SBSectionIsValid(SBSectionRef instance)
{
    SBSection *unwrapped = reinterpret_cast<SBSection *>(instance);
    return unwrapped->IsValid();
}

const char *
SBSectionGetName(SBSectionRef instance)
{
    SBSection *unwrapped = reinterpret_cast<SBSection *>(instance);
    return unwrapped->GetName();
}

SBSectionRef
SBSectionGetParent(SBSectionRef instance)
{
    SBSection *unwrapped = reinterpret_cast<SBSection *>(instance);
    return reinterpret_cast<SBSectionRef>(new SBSection(unwrapped->GetParent()));
}

SBSectionRef
SBSectionFindSubSection(SBSectionRef instance, const char *sect_name)
{
    SBSection *unwrapped = reinterpret_cast<SBSection *>(instance);
    return reinterpret_cast<SBSectionRef>(new SBSection(unwrapped->FindSubSection(sect_name)));
}

unsigned int
SBSectionGetNumSubSections(SBSectionRef instance)
{
    SBSection *unwrapped = reinterpret_cast<SBSection *>(instance);
    return unwrapped->GetNumSubSections();
}

SBSectionRef
SBSectionGetSubSectionAtIndex(SBSectionRef instance, size_t idx)
{
    SBSection *unwrapped = reinterpret_cast<SBSection *>(instance);
    return reinterpret_cast<SBSectionRef>(new SBSection(unwrapped->GetSubSectionAtIndex(idx)));
}

lldb_addr_t
SBSectionGetFileAddress(SBSectionRef instance)
{
    SBSection *unwrapped = reinterpret_cast<SBSection *>(instance);
    return unwrapped->GetFileAddress();
}

lldb_addr_t
SBSectionGetLoadAddress(SBSectionRef instance, SBTargetRef target)
{
    SBSection *unwrapped = reinterpret_cast<SBSection *>(instance);
    return unwrapped->GetLoadAddress(*reinterpret_cast<SBTarget *>(target));
}

lldb_addr_t
SBSectionGetByteSize(SBSectionRef instance)
{
    SBSection *unwrapped = reinterpret_cast<SBSection *>(instance);
    return unwrapped->GetByteSize();
}

unsigned long long
SBSectionGetFileOffset(SBSectionRef instance)
{
    SBSection *unwrapped = reinterpret_cast<SBSection *>(instance);
    return unwrapped->GetFileOffset();
}

unsigned long long
SBSectionGetFileByteSize(SBSectionRef instance)
{
    SBSection *unwrapped = reinterpret_cast<SBSection *>(instance);
    return unwrapped->GetFileByteSize();
}

SBDataRef
SBSectionGetSectionData(SBSectionRef instance)
{
    SBSection *unwrapped = reinterpret_cast<SBSection *>(instance);
    return reinterpret_cast<SBDataRef>(new SBData(unwrapped->GetSectionData()));
}

SBDataRef
SBSectionGetSectionData2(SBSectionRef instance, uint64_t offset, uint64_t size)
{
    SBSection *unwrapped = reinterpret_cast<SBSection *>(instance);
    return reinterpret_cast<SBDataRef>(new SBData(unwrapped->GetSectionData(offset, size)));
}

enum lldb::SectionType
SBSectionGetSectionType(SBSectionRef instance)
{
    SBSection *unwrapped = reinterpret_cast<SBSection *>(instance);
    return unwrapped->GetSectionType();
}

unsigned int
SBSectionGetTargetByteSize(SBSectionRef instance)
{
    SBSection *unwrapped = reinterpret_cast<SBSection *>(instance);
    return unwrapped->GetTargetByteSize();
}

bool
SBSectionGetDescription(SBSectionRef instance, SBStreamRef description)
{
    SBSection *unwrapped = reinterpret_cast<SBSection *>(instance);
    return unwrapped->GetDescription(*reinterpret_cast<SBStream *>(description));
}

#ifdef __cplusplus
}
#endif
