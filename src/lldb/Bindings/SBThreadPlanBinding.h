//===-- SBThreadPlanBinding.h -----------------------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef LLDB_SBThreadPlanBinding_h_
#define LLDB_SBThreadPlanBinding_h_

#include "lldb/Bindings/SBBindingDefines.h"

#ifdef __cplusplus
extern "C" {
#endif

LLDB_API SBThreadPlanRef CreateSBThreadPlan();

LLDB_API SBThreadPlanRef CreateSBThreadPlan2(SBThreadRef thread, const char *class_name);

LLDB_API void DisposeSBThreadPlan(SBThreadPlanRef instance);

LLDB_API bool SBThreadPlanIsValid(SBThreadPlanRef instance);

LLDB_API void SBThreadPlanClear(SBThreadPlanRef instance);

LLDB_API enum LLDBStopReason SBThreadPlanGetStopReason(SBThreadPlanRef instance);

LLDB_API unsigned int SBThreadPlanGetStopReasonDataCount(SBThreadPlanRef instance);

LLDB_API unsigned long long SBThreadPlanGetStopReasonDataAtIndex(SBThreadPlanRef instance, uint32_t idx);

LLDB_API SBThreadRef SBThreadPlanGetThread(SBThreadPlanRef instance);

LLDB_API bool SBThreadPlanGetDescription(SBThreadPlanRef instance, SBStreamRef description);

LLDB_API void SBThreadPlanSetPlanComplete(SBThreadPlanRef instance, bool success);

LLDB_API bool SBThreadPlanIsPlanComplete(SBThreadPlanRef instance);

LLDB_API bool SBThreadPlanIsValid(SBThreadPlanRef instance);

LLDB_API SBThreadPlanRef SBThreadPlanQueueThreadPlanForStepOverRange(SBThreadPlanRef instance,
                                                                             SBAddressRef start_address,
                                                                             lldb_addr_t range_size);

LLDB_API SBThreadPlanRef SBThreadPlanQueueThreadPlanForStepInRange(SBThreadPlanRef instance,
                                                                           SBAddressRef start_address,
                                                                           lldb_addr_t range_size);

LLDB_API SBThreadPlanRef
SBThreadPlanQueueThreadPlanForStepOut(SBThreadPlanRef instance, uint32_t frame_idx_to_step_to, bool first_insn);

LLDB_API SBThreadPlanRef
SBThreadPlanQueueThreadPlanForRunToAddress(SBThreadPlanRef instance, SBAddressRef address);

#ifdef __cplusplus
}
#endif

#endif // LLDB_SBThreadPlanBinding_h_
