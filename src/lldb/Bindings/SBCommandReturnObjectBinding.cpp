//===-- SBCommandReturnObjectBinding.cpp ------------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "lldb/Bindings/LLDBBinding.h"
#include "lldb/API/LLDB.h"
#include "lldb/Interpreter/CommandReturnObject.h"
#include "stdarg.h"

using namespace lldb;

#ifdef __cplusplus
extern "C" {
#endif

SBCommandReturnObjectRef
CreateSBCommandReturnObject()
{
    return reinterpret_cast<SBCommandReturnObjectRef>(new SBCommandReturnObject());
}

void *
SBCommandReturnObjectRelease(SBCommandReturnObjectRef instance)
{
    SBCommandReturnObject *unwrapped = reinterpret_cast<SBCommandReturnObject *>(instance);
    return unwrapped->Release();
}

SBCommandReturnObjectRef
CloneSBCommandReturnObject(SBCommandReturnObjectRef instance)
{
    return reinterpret_cast<SBCommandReturnObjectRef>(new SBCommandReturnObject(*reinterpret_cast<SBCommandReturnObject *>(instance)));
}

void
DisposeSBCommandReturnObject(SBCommandReturnObjectRef instance)
{
    delete reinterpret_cast<SBCommandReturnObject *>(instance);
}

bool
SBCommandReturnObjectIsValid(SBCommandReturnObjectRef instance)
{
    SBCommandReturnObject *unwrapped = reinterpret_cast<SBCommandReturnObject *>(instance);
    return unwrapped->IsValid();
}

const char *
SBCommandReturnObjectGetOutput(SBCommandReturnObjectRef instance)
{
    SBCommandReturnObject *unwrapped = reinterpret_cast<SBCommandReturnObject *>(instance);
    return unwrapped->GetOutput();
}

const char *
SBCommandReturnObjectGetError(SBCommandReturnObjectRef instance)
{
    SBCommandReturnObject *unwrapped = reinterpret_cast<SBCommandReturnObject *>(instance);
    return unwrapped->GetError();
}

unsigned int
SBCommandReturnObjectPutOutput(SBCommandReturnObjectRef instance, FILE *fh)
{
    SBCommandReturnObject *unwrapped = reinterpret_cast<SBCommandReturnObject *>(instance);
    return unwrapped->PutOutput(fh);
}

unsigned int
SBCommandReturnObjectGetOutputSize(SBCommandReturnObjectRef instance)
{
    SBCommandReturnObject *unwrapped = reinterpret_cast<SBCommandReturnObject *>(instance);
    return unwrapped->GetOutputSize();
}

unsigned int
SBCommandReturnObjectGetErrorSize(SBCommandReturnObjectRef instance)
{
    SBCommandReturnObject *unwrapped = reinterpret_cast<SBCommandReturnObject *>(instance);
    return unwrapped->GetErrorSize();
}

unsigned int
SBCommandReturnObjectPutError(SBCommandReturnObjectRef instance, FILE *fh)
{
    SBCommandReturnObject *unwrapped = reinterpret_cast<SBCommandReturnObject *>(instance);
    return unwrapped->PutError(fh);
}

void
SBCommandReturnObjectClear(SBCommandReturnObjectRef instance)
{
    SBCommandReturnObject *unwrapped = reinterpret_cast<SBCommandReturnObject *>(instance);
    unwrapped->Clear();
}

enum lldb::ReturnStatus
SBCommandReturnObjectGetStatus(SBCommandReturnObjectRef instance)
{
    SBCommandReturnObject *unwrapped = reinterpret_cast<SBCommandReturnObject *>(instance);
    return unwrapped->GetStatus();
}

void
SBCommandReturnObjectSetStatus(SBCommandReturnObjectRef instance, lldb::ReturnStatus status)
{
    SBCommandReturnObject *unwrapped = reinterpret_cast<SBCommandReturnObject *>(instance);
    unwrapped->SetStatus(status);
}

bool
SBCommandReturnObjectSucceeded(SBCommandReturnObjectRef instance)
{
    SBCommandReturnObject *unwrapped = reinterpret_cast<SBCommandReturnObject *>(instance);
    return unwrapped->Succeeded();
}

bool
SBCommandReturnObjectHasResult(SBCommandReturnObjectRef instance)
{
    SBCommandReturnObject *unwrapped = reinterpret_cast<SBCommandReturnObject *>(instance);
    return unwrapped->HasResult();
}

void
SBCommandReturnObjectAppendMessage(SBCommandReturnObjectRef instance, const char *message)
{
    SBCommandReturnObject *unwrapped = reinterpret_cast<SBCommandReturnObject *>(instance);
    unwrapped->AppendMessage(message);
}

void
SBCommandReturnObjectAppendWarning(SBCommandReturnObjectRef instance, const char *message)
{
    SBCommandReturnObject *unwrapped = reinterpret_cast<SBCommandReturnObject *>(instance);
    unwrapped->AppendWarning(message);
}

bool
SBCommandReturnObjectGetDescription(SBCommandReturnObjectRef instance, SBStreamRef description)
{
    SBCommandReturnObject *unwrapped = reinterpret_cast<SBCommandReturnObject *>(instance);
    return unwrapped->GetDescription(*reinterpret_cast<SBStream *>(description));
}

void
SBCommandReturnObjectSetImmediateOutputFile(SBCommandReturnObjectRef instance, FILE *fh)
{
    SBCommandReturnObject *unwrapped = reinterpret_cast<SBCommandReturnObject *>(instance);
    unwrapped->SetImmediateOutputFile(fh);
}

void
SBCommandReturnObjectSetImmediateErrorFile(SBCommandReturnObjectRef instance, FILE *fh)
{
    SBCommandReturnObject *unwrapped = reinterpret_cast<SBCommandReturnObject *>(instance);
    unwrapped->SetImmediateErrorFile(fh);
}

void
SBCommandReturnObjectPutCString(SBCommandReturnObjectRef instance, const char *string, int len)
{
    SBCommandReturnObject *unwrapped = reinterpret_cast<SBCommandReturnObject *>(instance);
    unwrapped->PutCString(string, len);
}

unsigned int
SBCommandReturnObjectPrintf(SBCommandReturnObjectRef instance, const char *format, ...)
{
    if (!format)
        return 0;

    unsigned int retVal;
    SBCommandReturnObject *unwrapped = reinterpret_cast<SBCommandReturnObject *>(instance);

    va_list args;
    va_start(args, format);
    retVal = unwrapped->Printf(format, args);
    va_end(args);

    return retVal;
}

const char *
SBCommandReturnObjectGetOutput2(SBCommandReturnObjectRef instance, bool only_if_no_immediate)
{
    SBCommandReturnObject *unwrapped = reinterpret_cast<SBCommandReturnObject *>(instance);
    return unwrapped->GetOutput(only_if_no_immediate);
}

const char *
SBCommandReturnObjectGetError2(SBCommandReturnObjectRef instance, bool only_if_no_immediate)
{
    SBCommandReturnObject *unwrapped = reinterpret_cast<SBCommandReturnObject *>(instance);
    return unwrapped->GetError(only_if_no_immediate);
}

void
SBCommandReturnObjectSetError(SBCommandReturnObjectRef instance, SBErrorRef error,
                                  const char *fallback_error_cstr)
{
    SBCommandReturnObject *unwrapped = reinterpret_cast<SBCommandReturnObject *>(instance);
    unwrapped->SetError(*reinterpret_cast<SBError *>(error), fallback_error_cstr);
}

void
SBCommandReturnObjectSetError2(SBCommandReturnObjectRef instance, const char *error_cstr)
{
    SBCommandReturnObject *unwrapped = reinterpret_cast<SBCommandReturnObject *>(instance);
    unwrapped->SetError(error_cstr);
}

#ifdef __cplusplus
}
#endif
