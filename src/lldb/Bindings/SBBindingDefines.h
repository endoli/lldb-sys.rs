//===-- SBBindingDefines.h --- ----------------------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef LLDB_SBBindingDefines_h_
#define LLDB_SBBindingDefines_h_

// C Includes
// C++ Includes
// Other libraries and framework includes
// Project includes

#ifdef BINDGEN
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#if defined (_MSC_VER)
    #if defined(EXPORT_LIBLLDB)
        #define  LLDB_API __declspec(dllexport)
    #elif defined(IMPORT_LIBLLDB)
        #define  LLDB_API __declspec(dllimport)
    #else
        #define LLDB_API
    #endif
#else // defined (_MSC_VER)
    #define LLDB_API
#endif

typedef uint64_t lldb_addr_t;
typedef uint64_t lldb_user_id_t;
typedef uint64_t lldb_pid_t;
typedef uint64_t lldb_tid_t;
typedef uint64_t lldb_offset_t;

#else

#include "lldb/lldb-enumerations.h"
#include "lldb/lldb-defines.h"
#include "lldb/lldb-forward.h"
#include "lldb/lldb-types.h"

typedef lldb::addr_t lldb_addr_t;
typedef lldb::user_id_t lldb_user_id_t;
typedef lldb::pid_t lldb_pid_t;
typedef lldb::tid_t lldb_tid_t;
typedef lldb::offset_t lldb_offset_t;

#endif

LLDB_API typedef struct SBAddressOpaque *SBAddressRef;
LLDB_API typedef struct SBAttachInfoOpaque *SBAttachInfoRef;
LLDB_API typedef struct SBBlockOpaque *SBBlockRef;
LLDB_API typedef struct SBBreakpointOpaque *SBBreakpointRef;
LLDB_API typedef struct SBBreakpointLocationOpaque *SBBreakpointLocationRef;
LLDB_API typedef struct SBBroadcasterOpaque *SBBroadcasterRef;
LLDB_API typedef struct SBCommandOpaque *SBCommandRef;
LLDB_API typedef struct SBCommandInterpreterOpaque *SBCommandInterpreterRef;
LLDB_API typedef struct SBCommandInterpreterRunOptionsOpaque *SBCommandInterpreterRunOptionsRef;
LLDB_API typedef struct SBCommandPluginInterfaceOpaque *SBCommandPluginInterfaceRef;
LLDB_API typedef struct SBCommandReturnObjectOpaque *SBCommandReturnObjectRef;
LLDB_API typedef struct SBCommunicationOpaque *SBCommunicationRef;
LLDB_API typedef struct SBCompileUnitOpaque *SBCompileUnitRef;
LLDB_API typedef struct SBDataOpaque *SBDataRef;
LLDB_API typedef struct SBDebuggerOpaque *SBDebuggerRef;
LLDB_API typedef struct SBDeclarationOpaque *SBDeclarationRef;
LLDB_API typedef struct SBErrorOpaque *SBErrorRef;
LLDB_API typedef struct SBEventOpaque *SBEventRef;
LLDB_API typedef struct SBEventListOpaque *SBEventListRef;
LLDB_API typedef struct SBExecutionContextOpaque *SBExecutionContextRef;
LLDB_API typedef struct SBExpressionOptionsOpaque *SBExpressionOptionsRef;
LLDB_API typedef struct SBFileSpecOpaque *SBFileSpecRef;
LLDB_API typedef struct SBFileSpecListOpaque *SBFileSpecListRef;
LLDB_API typedef struct SBFrameOpaque *SBFrameRef;
LLDB_API typedef struct SBFunctionOpaque *SBFunctionRef;
LLDB_API typedef struct SBHostOSOpaque *SBHostOSRef;
LLDB_API typedef struct SBInstructionOpaque *SBInstructionRef;
LLDB_API typedef struct SBInstructionListOpaque *SBInstructionListRef;
LLDB_API typedef struct SBLaunchInfoOpaque *SBLaunchInfoRef;
LLDB_API typedef struct SBLineEntryOpaque *SBLineEntryRef;
LLDB_API typedef struct SBListenerOpaque *SBListenerRef;
LLDB_API typedef struct SBModuleOpaque *SBModuleRef;
LLDB_API typedef struct SBModuleSpecOpaque *SBModuleSpecRef;
LLDB_API typedef struct SBModuleSpecListOpaque *SBModuleSpecListRef;
LLDB_API typedef struct SBPlatformOpaque *SBPlatformRef;
LLDB_API typedef struct SBProcessOpaque *SBProcessRef;
LLDB_API typedef struct SBQueueOpaque *SBQueueRef;
LLDB_API typedef struct SBQueueItemOpaque *SBQueueItemRef;
LLDB_API typedef struct SBSectionOpaque *SBSectionRef;
LLDB_API typedef struct SBSourceManagerOpaque *SBSourceManagerRef;
LLDB_API typedef struct SBStreamOpaque *SBStreamRef;
LLDB_API typedef struct SBStringListOpaque *SBStringListRef;
LLDB_API typedef struct SBSymbolOpaque *SBSymbolRef;
LLDB_API typedef struct SBSymbolContextOpaque *SBSymbolContextRef;
LLDB_API typedef struct SBSymbolContextListOpaque *SBSymbolContextListRef;
LLDB_API typedef struct SBTargetRefOpaque *SBTargetRef;
LLDB_API typedef struct SBThreadRefOpaque *SBThreadRef;
LLDB_API typedef struct SBThreadCollectionOpaque *SBThreadCollectionRef;
LLDB_API typedef struct SBThreadPlanOpaque *SBThreadPlanRef;
LLDB_API typedef struct SBTypeOpaque *SBTypeRef;
LLDB_API typedef struct SBTypeMemberOpaque *SBTypeMemberRef;
LLDB_API typedef struct SBTypeCategoryOpaque *SBTypeCategoryRef;
LLDB_API typedef struct SBTypeEnumMemberOpaque *SBTypeEnumMemberRef;
LLDB_API typedef struct SBTypeEnumMemberListOpaque *SBTypeEnumMemberListRef;
LLDB_API typedef struct SBTypeFilterOpaque *SBTypeFilterRef;
LLDB_API typedef struct SBTypeFormatOpaque *SBTypeFormatRef;
LLDB_API typedef struct SBTypeMemberFunctionOpaque *SBTypeMemberFunctionRef;
LLDB_API typedef struct SBTypeNameSpecifierOpaque *SBTypeNameSpecifierRef;
LLDB_API typedef struct SBTypeSummaryOpaque *SBTypeSummaryRef;
LLDB_API typedef struct SBTypeSummaryOptionsOpaque *SBTypeSummaryOptionsRef;
LLDB_API typedef struct SBInputReaderOpaque *SBInputReaderRef;
LLDB_API typedef struct SBPlatformConnectOptionsOpaque *SBPlatformConnectOptionsRef;
LLDB_API typedef struct SBPlatformShellCommandOpaque *SBPlatformShellCommandRef;

#ifndef LLDB_DISABLE_PYTHON
LLDB_API typedef struct SBTypeSyntheticOpaque *SBTypeSyntheticRef;
#endif
LLDB_API typedef struct SBTypeListOpaque *SBTypeListRef;
LLDB_API typedef struct SBValueOpaque *SBValueRef;
LLDB_API typedef struct SBValueListOpaque *SBValueListRef;
LLDB_API typedef struct SBVariablesOptionsOpaque *SBVariablesOptionsRef;
LLDB_API typedef struct SBWatchpointOpaque *SBWatchpointRef;
LLDB_API typedef struct SBUnixSignalsOpaque *SBUnixSignalsRef;

#ifdef BINDGEN
#include "lldb/Bindings/SBBindingEnumerations.h"

LLDB_API typedef enum LLDBAddressClass LLDBAddressClass;
LLDB_API typedef enum LLDBDynamicValueType LLDBDynamicValueType;
LLDB_API typedef enum LLDBBreakpointEventType LLDBBreakpointEventType;
LLDB_API typedef enum LLDBDescriptionLevel LLDBDescriptionLevel;
LLDB_API typedef enum LLDBCommandArgumentType LLDBCommandArgumentType;
LLDB_API typedef enum LLDBReturnStatus LLDBReturnStatus;
LLDB_API typedef enum LLDBConnectionStatus LLDBConnectionStatus;
LLDB_API typedef enum LLDBLanguageType LLDBLanguageType;
LLDB_API typedef enum LLDBByteOrder LLDBByteOrder;
LLDB_API typedef enum LLDBWatchpointEventType LLDBWatchpointEventType;
LLDB_API typedef enum LLDBFormat LLDBFormat;
LLDB_API typedef enum LLDBValueType LLDBValueType;
LLDB_API typedef enum LLDBTypeSummaryCapping LLDBTypeSummaryCapping;
LLDB_API typedef enum LLDBMemberFunctionKind LLDBMemberFunctionKind;
LLDB_API typedef enum LLDBTemplateArgumentKind LLDBTemplateArgumentKind;
LLDB_API typedef enum LLDBTypeClass LLDBTypeClass;
LLDB_API typedef enum LLDBBasicType LLDBBasicType;
LLDB_API typedef enum LLDBStopReason LLDBStopReason;
LLDB_API typedef enum LLDBRunMode LLDBRunMode;
LLDB_API typedef enum LLDBMatchType LLDBMatchType;
LLDB_API typedef enum LLDBSymbolType LLDBSymbolType;
LLDB_API typedef enum LLDBSectionType LLDBSectionType;
LLDB_API typedef enum LLDBQueueItemKind LLDBQueueItemKind;
LLDB_API typedef enum LLDBStateType LLDBStateType;
LLDB_API typedef enum LLDBInstrumentationRuntimeType LLDBInstrumentationRuntimeType;
LLDB_API typedef enum LLDBPathType LLDBPathType;
LLDB_API typedef enum LLDBExpressionEvaluationPhase LLDBExpressionEvaluationPhase;
LLDB_API typedef enum LLDBErrorType LLDBErrorType;
LLDB_API typedef enum LLDBScriptLanguage LLDBScriptLanguage;
LLDB_API typedef enum LLDBAddressClass LLDBAddressClass;
LLDB_API typedef enum LLDBQueueKind LLDBQueueKind;
LLDB_API typedef enum LLDBInputReaderGranularity LLDBInputReaderGranularity;
LLDB_API typedef enum LLDBInputReaderAction LLDBInputReaderAction;
#else
#include "lldb/lldb-enumerations.h"

LLDB_API typedef enum lldb::AddressClass LLDBAddressClass;
LLDB_API typedef enum lldb::DynamicValueType LLDBDynamicValueType;
LLDB_API typedef enum lldb::BreakpointEventType LLDBBreakpointEventType;
LLDB_API typedef enum lldb::DescriptionLevel LLDBDescriptionLevel;
LLDB_API typedef enum lldb::CommandArgumentType LLDBCommandArgumentType;
LLDB_API typedef enum lldb::ReturnStatus LLDBReturnStatus;
LLDB_API typedef enum lldb::ConnectionStatus LLDBConnectionStatus;
LLDB_API typedef enum lldb::LanguageType LLDBLanguageType;
LLDB_API typedef enum lldb::ByteOrder LLDBByteOrder;
LLDB_API typedef enum lldb::WatchpointEventType LLDBWatchpointEventType;
LLDB_API typedef enum lldb::Format LLDBFormat;
LLDB_API typedef enum lldb::ValueType LLDBValueType;
LLDB_API typedef enum lldb::TypeSummaryCapping LLDBTypeSummaryCapping;
LLDB_API typedef enum lldb::MemberFunctionKind LLDBMemberFunctionKind;
LLDB_API typedef enum lldb::TemplateArgumentKind LLDBTemplateArgumentKind;
LLDB_API typedef enum lldb::TypeClass LLDBTypeClass;
LLDB_API typedef enum lldb::BasicType LLDBBasicType;
LLDB_API typedef enum lldb::StopReason LLDBStopReason;
LLDB_API typedef enum lldb::RunMode LLDBRunMode;
LLDB_API typedef enum lldb::MatchType LLDBMatchType;
LLDB_API typedef enum lldb::SymbolType LLDBSymbolType;
LLDB_API typedef enum lldb::SectionType LLDBSectionType;
LLDB_API typedef enum lldb::QueueItemKind LLDBQueueItemKind;
LLDB_API typedef enum lldb::StateType LLDBStateType;
LLDB_API typedef enum lldb::InstrumentationRuntimeType LLDBInstrumentationRuntimeType;
LLDB_API typedef enum lldb::PathType LLDBPathType;
LLDB_API typedef enum lldb::ExpressionEvaluationPhase LLDBExpressionEvaluationPhase;
LLDB_API typedef enum lldb::ErrorType LLDBErrorType;
LLDB_API typedef enum lldb::ScriptLanguage LLDBScriptLanguage;
LLDB_API typedef enum lldb::AddressClass LLDBAddressClass;
LLDB_API typedef enum lldb::QueueKind LLDBQueueKind;
LLDB_API typedef enum lldb::InputReaderGranularity LLDBInputReaderGranularity;
LLDB_API typedef enum lldb::InputReaderAction LLDBInputReaderAction;
#endif // !BINDGEN

#endif // LLDB_SBBindingDefines_h_
