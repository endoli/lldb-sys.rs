//===-- SBMemoryRegionInfoBinding.h -----------------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef LLDB_SBMemoryRegionInfoBinding_h_
#define LLDB_SBMemoryRegionInfoBinding_h_

#include "lldb/Bindings/SBBindingDefines.h"

#ifdef __cplusplus
extern "C" {
#endif

LLDB_API SBMemoryRegionInfoRef CreateSBMemoryRegionInfo(void);

LLDB_API SBMemoryRegionInfoRef CloneSBMemoryRegionInfo(SBMemoryRegionInfoRef instance);

LLDB_API void DisposeSBMemoryRegionInfo(SBMemoryRegionInfoRef instance);

LLDB_API void SBMemoryRegionInfoClear(SBMemoryRegionInfoRef instance);

LLDB_API lldb_addr_t SBMemoryRegionInfoGetRegionBase(SBMemoryRegionInfoRef instance);

LLDB_API lldb_addr_t SBMemoryRegionInfoGetRegionEnd(SBMemoryRegionInfoRef instance);

LLDB_API bool SBMemoryRegionInfoIsReadable(SBMemoryRegionInfoRef instance);

LLDB_API bool SBMemoryRegionInfoIsWritable(SBMemoryRegionInfoRef instance);

LLDB_API bool SBMemoryRegionInfoIsExecutable(SBMemoryRegionInfoRef instance);

LLDB_API bool SBMemoryRegionInfoIsMapped(SBMemoryRegionInfoRef instance);

LLDB_API const char *SBMemoryRegionInfoGetName(SBMemoryRegionInfoRef instance);

LLDB_API bool SBMemoryRegionInfoGetDescription(SBMemoryRegionInfoRef instance, SBStreamRef description);

#ifdef __cplusplus
}
#endif

#endif // LLDB_SBMemoryRegionInfoBinding_h_
