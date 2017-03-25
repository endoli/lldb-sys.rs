//===-- SBStructuredDataBinding.cpp ---------------------------------------*- C++ -*-===//
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

SBStructuredDataRef
CreateSBStructuredData()
{
    return reinterpret_cast<SBStructuredDataRef>(new SBStructuredData());
}

void
DisposeSBStructuredData(SBStructuredDataRef instance)
{
    delete reinterpret_cast<SBStructuredData *>(instance);
}

bool
SBStructuredDataIsValid(SBStructuredDataRef instance)
{
    SBStructuredData *unwrapped = reinterpret_cast<SBStructuredData *>(instance);
    return unwrapped->IsValid();
}

void
SBStructuredDataClear(SBStructuredDataRef instance)
{
    SBStructuredData *unwrapped = reinterpret_cast<SBStructuredData *>(instance);
    unwrapped->Clear();
}

SBErrorRef
SBStructuredDataGetAsJSON(SBStructuredDataRef instance, SBStreamRef description)
{
    SBStructuredData *unwrapped = reinterpret_cast<SBStructuredData *>(instance);
    return reinterpret_cast<SBErrorRef>(new SBError(unwrapped->GetAsJSON(*reinterpret_cast<SBStream *>(description))));
}

SBErrorRef
SBStructuredDataGetDescription(SBStructuredDataRef instance, SBStreamRef description)
{
    SBStructuredData *unwrapped = reinterpret_cast<SBStructuredData *>(instance);
    return reinterpret_cast<SBErrorRef>(new SBError(unwrapped->GetDescription(*reinterpret_cast<SBStream *>(description))));
}

#ifdef __cplusplus
}
#endif
