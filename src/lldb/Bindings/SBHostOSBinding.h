//===-- SBHostOSBinding.h ---------------------------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef LLDB_SBHostOSBinding_h_
#define LLDB_SBHostOSBinding_h_

#include "lldb/Bindings/SBBindingDefines.h"

#ifdef __cplusplus
extern "C" {
#endif

LLDB_API SBFileSpecRef SBHostOSGetProgramFileSpec();

LLDB_API SBFileSpecRef SBHostOSGetLLDBPythonPath();

LLDB_API SBFileSpecRef SBHostOSGetLLDBPath(LLDBPathType path_type);

#ifdef __cplusplus
}
#endif

#endif // LLDB_SBHostOSBinding_h_
