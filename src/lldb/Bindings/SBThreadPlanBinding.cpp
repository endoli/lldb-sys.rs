//===-- SBThreadPlanBinding.cpp ---------------------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "lldb/API/LLDB.h"
#include "lldb/API/SBThreadPlan.h"
#include "lldb/Bindings/LLDBBinding.h"

using namespace lldb;

#ifdef __cplusplus
extern "C" {
#endif

SBThreadPlanRef CreateSBThreadPlan() {
  return reinterpret_cast<SBThreadPlanRef>(new SBThreadPlan());
}

SBThreadPlanRef CreateSBThreadPlan2(SBThreadRef thread,
                                    const char *class_name) {
  return reinterpret_cast<SBThreadPlanRef>(
      new SBThreadPlan(*reinterpret_cast<SBThread *>(thread), class_name));
}

SBThreadPlanRef CloneSBThreadPlan(SBThreadPlanRef instance) {
  return reinterpret_cast<SBThreadPlanRef>(
      new SBThreadPlan(*reinterpret_cast<SBThreadPlan *>(instance)));
}

void DisposeSBThreadPlan(SBThreadPlanRef instance) {
  delete reinterpret_cast<SBThreadPlan *>(instance);
}

bool SBThreadPlanIsValid(SBThreadPlanRef instance) {
  SBThreadPlan *unwrapped = reinterpret_cast<SBThreadPlan *>(instance);
  return unwrapped->IsValid();
}

void SBThreadPlanClear(SBThreadPlanRef instance) {
  SBThreadPlan *unwrapped = reinterpret_cast<SBThreadPlan *>(instance);
  unwrapped->Clear();
}

enum lldb::StopReason SBThreadPlanGetStopReason(SBThreadPlanRef instance) {
  SBThreadPlan *unwrapped = reinterpret_cast<SBThreadPlan *>(instance);
  return unwrapped->GetStopReason();
}

size_t SBThreadPlanGetStopReasonDataCount(SBThreadPlanRef instance) {
  SBThreadPlan *unwrapped = reinterpret_cast<SBThreadPlan *>(instance);
  return unwrapped->GetStopReasonDataCount();
}

uint64_t SBThreadPlanGetStopReasonDataAtIndex(SBThreadPlanRef instance,
                                              uint32_t idx) {
  SBThreadPlan *unwrapped = reinterpret_cast<SBThreadPlan *>(instance);
  return unwrapped->GetStopReasonDataAtIndex(idx);
}

SBThreadRef SBThreadPlanGetThread(SBThreadPlanRef instance) {
  SBThreadPlan *unwrapped = reinterpret_cast<SBThreadPlan *>(instance);
  return reinterpret_cast<SBThreadRef>(new SBThread(unwrapped->GetThread()));
}

bool SBThreadPlanGetDescription(SBThreadPlanRef instance,
                                SBStreamRef description) {
  SBThreadPlan *unwrapped = reinterpret_cast<SBThreadPlan *>(instance);
  return unwrapped->GetDescription(*reinterpret_cast<SBStream *>(description));
}

void SBThreadPlanSetPlanComplete(SBThreadPlanRef instance, bool success) {
  SBThreadPlan *unwrapped = reinterpret_cast<SBThreadPlan *>(instance);
  unwrapped->SetPlanComplete(success);
}

bool SBThreadPlanIsPlanComplete(SBThreadPlanRef instance) {
  SBThreadPlan *unwrapped = reinterpret_cast<SBThreadPlan *>(instance);
  return unwrapped->IsPlanComplete();
}

bool SBThreadPlanIsPlanStale(SBThreadPlanRef instance) {
  SBThreadPlan *unwrapped = reinterpret_cast<SBThreadPlan *>(instance);
  return unwrapped->IsPlanStale();
}

SBThreadPlanRef
SBThreadPlanQueueThreadPlanForStepOverRange(SBThreadPlanRef instance,
                                            SBAddressRef start_address,
                                            lldb_addr_t range_size) {
  SBThreadPlan *unwrapped = reinterpret_cast<SBThreadPlan *>(instance);
  return reinterpret_cast<SBThreadPlanRef>(
      new SBThreadPlan(unwrapped->QueueThreadPlanForStepOverRange(
          *reinterpret_cast<SBAddress *>(start_address), range_size)));
}

SBThreadPlanRef
SBThreadPlanQueueThreadPlanForStepInRange(SBThreadPlanRef instance,
                                          SBAddressRef start_address,
                                          lldb_addr_t range_size) {
  SBThreadPlan *unwrapped = reinterpret_cast<SBThreadPlan *>(instance);
  return reinterpret_cast<SBThreadPlanRef>(
      new SBThreadPlan(unwrapped->QueueThreadPlanForStepInRange(
          *reinterpret_cast<SBAddress *>(start_address), range_size)));
}

SBThreadPlanRef SBThreadPlanQueueThreadPlanForStepOut(
    SBThreadPlanRef instance, uint32_t frame_idx_to_step_to, bool first_insn) {
  SBThreadPlan *unwrapped = reinterpret_cast<SBThreadPlan *>(instance);
  return reinterpret_cast<SBThreadPlanRef>(new SBThreadPlan(
      unwrapped->QueueThreadPlanForStepOut(frame_idx_to_step_to, first_insn)));
}

SBThreadPlanRef
SBThreadPlanQueueThreadPlanForRunToAddress(SBThreadPlanRef instance,
                                           SBAddressRef address) {
  SBThreadPlan *unwrapped = reinterpret_cast<SBThreadPlan *>(instance);
  return reinterpret_cast<SBThreadPlanRef>(
      new SBThreadPlan(unwrapped->QueueThreadPlanForRunToAddress(
          *reinterpret_cast<SBAddress *>(address))));
}

#ifdef __cplusplus
}
#endif
