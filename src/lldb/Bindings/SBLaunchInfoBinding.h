//===-- SBLaunchInfoBinding.h -----------------------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef LLDB_SBLaunchInfoBinding_h_
#define LLDB_SBLaunchInfoBinding_h_

#include "lldb/Bindings/SBBindingDefines.h"

#ifdef __cplusplus
extern "C" {
#endif

LLDB_API SBLaunchInfoRef CreateSBLaunchInfo(const char **argv);

LLDB_API SBLaunchInfoRef CloneSBLaunchInfo(SBLaunchInfoRef instance);

LLDB_API void DisposeSBLaunchInfo(SBLaunchInfoRef instance);

LLDB_API unsigned long long SBLaunchInfoGetProcessID(SBLaunchInfoRef instance);

LLDB_API unsigned int SBLaunchInfoGetUserID(SBLaunchInfoRef instance);

LLDB_API unsigned int SBLaunchInfoGetGroupID(SBLaunchInfoRef instance);

LLDB_API bool SBLaunchInfoUserIDIsValid(SBLaunchInfoRef instance);

LLDB_API bool SBLaunchInfoGroupIDIsValid(SBLaunchInfoRef instance);

LLDB_API void SBLaunchInfoSetUserID(SBLaunchInfoRef instance, uint32_t uid);

LLDB_API void SBLaunchInfoSetGroupID(SBLaunchInfoRef instance, uint32_t gid);

LLDB_API SBFileSpecRef SBLaunchInfoGetExecutableFile(SBLaunchInfoRef instance);

LLDB_API void SBLaunchInfoSetExecutableFile(SBLaunchInfoRef instance, SBFileSpecRef exe_file,
                                                bool add_as_first_arg);

LLDB_API SBListenerRef SBLaunchInfoGetListener(SBLaunchInfoRef instance);

LLDB_API void SBLaunchInfoSetListener(SBLaunchInfoRef instance, SBListenerRef listener);

LLDB_API unsigned int SBLaunchInfoGetNumArguments(SBLaunchInfoRef instance);

LLDB_API const char *SBLaunchInfoGetArgumentAtIndex(SBLaunchInfoRef instance, uint32_t idx);

LLDB_API void SBLaunchInfoSetArguments(SBLaunchInfoRef instance, const char **argv, bool append);

LLDB_API unsigned int SBLaunchInfoGetNumEnvironmentEntries(SBLaunchInfoRef instance);

LLDB_API const char *SBLaunchInfoGetEnvironmentEntryAtIndex(SBLaunchInfoRef instance, uint32_t idx);

LLDB_API void SBLaunchInfoSetEnvironmentEntries(SBLaunchInfoRef instance, const char **envp, bool append);

LLDB_API void SBLaunchInfoClear(SBLaunchInfoRef instance);

LLDB_API const char *SBLaunchInfoGetWorkingDirectory(SBLaunchInfoRef instance);

LLDB_API void SBLaunchInfoSetWorkingDirectory(SBLaunchInfoRef instance, const char *working_dir);

LLDB_API unsigned int SBLaunchInfoGetLaunchFlags(SBLaunchInfoRef instance);

LLDB_API void SBLaunchInfoSetLaunchFlags(SBLaunchInfoRef instance, uint32_t flags);

LLDB_API const char *SBLaunchInfoGetProcessPluginName(SBLaunchInfoRef instance);

LLDB_API void SBLaunchInfoSetProcessPluginName(SBLaunchInfoRef instance, const char *plugin_name);

LLDB_API const char *SBLaunchInfoGetShell(SBLaunchInfoRef instance);

LLDB_API void SBLaunchInfoSetShell(SBLaunchInfoRef instance, const char *path);

LLDB_API bool SBLaunchInfoGetShellExpandArguments(SBLaunchInfoRef instance);

LLDB_API void SBLaunchInfoSetShellExpandArguments(SBLaunchInfoRef instance, bool glob);

LLDB_API unsigned int SBLaunchInfoGetResumeCount(SBLaunchInfoRef instance);

LLDB_API void SBLaunchInfoSetResumeCount(SBLaunchInfoRef instance, uint32_t c);

LLDB_API bool SBLaunchInfoAddCloseFileAction(SBLaunchInfoRef instance, int fd);

LLDB_API bool SBLaunchInfoAddDuplicateFileAction(SBLaunchInfoRef instance, int fd, int dup_fd);

LLDB_API bool SBLaunchInfoAddOpenFileAction(SBLaunchInfoRef instance, int fd, const char *path, bool read,
                                                bool write);

LLDB_API bool SBLaunchInfoAddSuppressFileAction(SBLaunchInfoRef instance, int fd, bool read, bool write);

LLDB_API void SBLaunchInfoSetLaunchEventData(SBLaunchInfoRef instance, const char *data);

LLDB_API const char *SBLaunchInfoGetLaunchEventData(SBLaunchInfoRef instance);

LLDB_API bool SBLaunchInfoGetDetachOnError(SBLaunchInfoRef instance);

LLDB_API void SBLaunchInfoSetDetachOnError(SBLaunchInfoRef instance, bool enable);

#ifdef __cplusplus
}
#endif

#endif // LLDB_SBLaunchInfoBinding_h_
