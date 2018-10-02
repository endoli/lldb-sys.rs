//===-- SBQueueBinding.h ----------------------------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef LLDB_SBQueueBinding_h_
#define LLDB_SBQueueBinding_h_

#include "lldb/Bindings/SBBindingDefines.h"

#ifdef __cplusplus
extern "C" {
#endif

LLDB_API SBQueueRef CreateSBQueue(void);

LLDB_API SBQueueRef CloneSBQueue(SBQueueRef instance);

LLDB_API void DisposeSBQueue(SBQueueRef instance);

LLDB_API bool SBQueueIsValid(SBQueueRef instance);

LLDB_API void SBQueueClear(SBQueueRef instance);

LLDB_API SBProcessRef SBQueueGetProcess(SBQueueRef instance);

LLDB_API unsigned long long SBQueueGetQueueID(SBQueueRef instance);

LLDB_API const char *SBQueueGetName(SBQueueRef instance);

LLDB_API unsigned int SBQueueGetIndexID(SBQueueRef instance);

LLDB_API unsigned int SBQueueGetNumThreads(SBQueueRef instance);

LLDB_API SBThreadRef SBQueueGetThreadAtIndex(SBQueueRef instance, uint32_t);

LLDB_API unsigned int SBQueueGetNumPendingItems(SBQueueRef instance);

LLDB_API SBQueueItemRef SBQueueGetPendingItemAtIndex(SBQueueRef instance, uint32_t);

LLDB_API unsigned int SBQueueGetNumRunningItems(SBQueueRef instance);

LLDB_API ENUM(QueueKind) SBQueueGetKind(SBQueueRef instance);

#ifdef __cplusplus
}
#endif

#endif // LLDB_SBQueueBinding_h_
