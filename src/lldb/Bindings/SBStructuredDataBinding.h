//===-- SBStructuredDataBinding.h -------------------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef LLDB_SBStructuredDataBinding_h_
#define LLDB_SBStructuredDataBinding_h_

#include "lldb/Bindings/SBBindingDefines.h"

#ifdef __cplusplus
extern "C" {
#endif

LLDB_API SBStructuredDataRef CreateSBStructuredData(void);

LLDB_API void DisposeSBStructuredData(SBStructuredDataRef instance);

LLDB_API bool SBStructuredDataIsValid(SBStructuredDataRef instance);

LLDB_API void SBStructuredDataClear(SBStructuredDataRef instance);

LLDB_API SBErrorRef SBStructuredDataGetAsJSON(SBStructuredDataRef instance, SBStreamRef stream);

LLDB_API SBErrorRef SBStructuredDataGetDescription(SBStructuredDataRef instance, SBStreamRef stream);

#ifdef __cplusplus
}
#endif

#endif // LLDB_SBStructuredDataBinding_h_
