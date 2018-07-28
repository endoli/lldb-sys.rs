extern crate cc;

use cc::Build;

#[cfg(target_os = "linux")]
use std::{fs, process::Command};

#[cfg(target_os = "linux")]
fn get_llvm_output(arg: &str) -> String {
    let llvm_config = std::env::var("LLVM_CONFIG").unwrap_or("llvm-config".into());
    let res = Command::new(llvm_config).arg(arg).output().unwrap();
    if !res.status.success() {
        panic!(
            "Could not run \"llvm-config {}\": {}",
            arg,
            res.status.code().unwrap()
        );
    }
    String::from_utf8(res.stdout).unwrap().trim().to_string()
}

#[cfg(target_os = "linux")]
fn match_libname(name: &str) -> Option<String> {
    if name.starts_with("liblldb.so") || name.starts_with("liblldb-") {
        if let Some(pos) = name.rfind(".so") {
            return Some(name["lib".len()..pos].into());
        }
    }
    None
}

#[cfg(test)]
#[test]
fn test_match_libname() {
    assert_eq!(match_libname("liblldb.so"), Some("lldb"));
    assert_eq!(match_libname("liblldb-3.8.so"), Some("lldb-3.8"));
    assert_eq!(match_libname("liblldbIntelFeatures.so"), None);
}

#[cfg(target_os = "linux")]
fn get_compiler_config() -> Build {
    // On linux lib directory and headers directory are provided by `llvm-config` utility.
    let llvm_headers_path = get_llvm_output("--includedir");
    let llvm_lib_path = get_llvm_output("--libdir");
    let lib_name = fs::read_dir(&llvm_lib_path)
        .expect("failed to stat libdir from llvm-config")
        .filter_map(|entry| match_libname(entry.unwrap().file_name().to_str().unwrap()))
        .nth(0)
        .expect("unable to locate shared library of liblldb");
    println!("cargo:rustc-link-search={}", llvm_lib_path);
    println!("cargo:rustc-link-lib={}", lib_name);
    let mut res = cc::Build::new();
    res.include(llvm_headers_path);
    res
}

#[cfg(target_os = "macos")]
fn get_compiler_config() -> Build {
    println!("cargo:rustc-link-lib=framework=LLDB");
    println!("cargo:rustc-link-search=framework=/Applications/Xcode.app/Contents/SharedFrameworks");
    let mut res = cc::Build::new();
    res.include(env!("LLVM_ROOT").to_owned() + "/tools/lldb/include")
        .include(env!("LLVM_ROOT").to_owned() + "/include")
        .include(env!("LLVM_BUILD_ROOT").to_owned() + "/include");
    res
}

#[cfg(not(any(target_os = "macos", target_os = "linux")))]
fn get_compiler_config() -> Build {
    panic!("Only MacOS and Linux are supported currently");
}

fn main() {
    get_compiler_config()
        .cpp(true)
        .flag("-std=c++14")
        .warnings(false)
        .include("src")
        .file("src/lldb/Bindings/SBAddressBinding.cpp")
        .file("src/lldb/Bindings/SBAttachInfoBinding.cpp")
        .file("src/lldb/Bindings/SBBlockBinding.cpp")
        .file("src/lldb/Bindings/SBBreakpointBinding.cpp")
        .file("src/lldb/Bindings/SBBreakpointListBinding.cpp")
        .file("src/lldb/Bindings/SBBreakpointLocationBinding.cpp")
        .file("src/lldb/Bindings/SBBreakpointNameBinding.cpp")
        .file("src/lldb/Bindings/SBBroadcasterBinding.cpp")
        .file("src/lldb/Bindings/SBCommandInterpreterBinding.cpp")
        .file("src/lldb/Bindings/SBCommandReturnObjectBinding.cpp")
        .file("src/lldb/Bindings/SBCommunicationBinding.cpp")
        .file("src/lldb/Bindings/SBCompileUnitBinding.cpp")
        .file("src/lldb/Bindings/SBDataBinding.cpp")
        .file("src/lldb/Bindings/SBDebuggerBinding.cpp")
        .file("src/lldb/Bindings/SBDeclarationBinding.cpp")
        .file("src/lldb/Bindings/SBErrorBinding.cpp")
        .file("src/lldb/Bindings/SBEventBinding.cpp")
        .file("src/lldb/Bindings/SBExecutionContextBinding.cpp")
        .file("src/lldb/Bindings/SBExpressionOptionsBinding.cpp")
        .file("src/lldb/Bindings/SBFileSpecBinding.cpp")
        .file("src/lldb/Bindings/SBFileSpecListBinding.cpp")
        .file("src/lldb/Bindings/SBFrameBinding.cpp")
        .file("src/lldb/Bindings/SBFunctionBinding.cpp")
        .file("src/lldb/Bindings/SBHostOSBinding.cpp")
        .file("src/lldb/Bindings/SBInstructionBinding.cpp")
        .file("src/lldb/Bindings/SBInstructionListBinding.cpp")
        .file("src/lldb/Bindings/SBLanguageRuntimeBinding.cpp")
        .file("src/lldb/Bindings/SBLaunchInfoBinding.cpp")
        .file("src/lldb/Bindings/SBLineEntryBinding.cpp")
        .file("src/lldb/Bindings/SBListenerBinding.cpp")
        .file("src/lldb/Bindings/SBMemoryRegionInfoBinding.cpp")
        .file("src/lldb/Bindings/SBMemoryRegionInfoListBinding.cpp")
        .file("src/lldb/Bindings/SBModuleBinding.cpp")
        .file("src/lldb/Bindings/SBModuleSpecBinding.cpp")
        .file("src/lldb/Bindings/SBPlatformBinding.cpp")
        .file("src/lldb/Bindings/SBProcessBinding.cpp")
        .file("src/lldb/Bindings/SBProcessInfoBinding.cpp")
        .file("src/lldb/Bindings/SBQueueBinding.cpp")
        .file("src/lldb/Bindings/SBQueueItemBinding.cpp")
        .file("src/lldb/Bindings/SBSectionBinding.cpp")
        .file("src/lldb/Bindings/SBSourceManagerBinding.cpp")
        .file("src/lldb/Bindings/SBStreamBinding.cpp")
        .file("src/lldb/Bindings/SBStringListBinding.cpp")
        .file("src/lldb/Bindings/SBStructuredDataBinding.cpp")
        .file("src/lldb/Bindings/SBSymbolBinding.cpp")
        .file("src/lldb/Bindings/SBSymbolContextBinding.cpp")
        .file("src/lldb/Bindings/SBSymbolContextListBinding.cpp")
        .file("src/lldb/Bindings/SBTargetBinding.cpp")
        .file("src/lldb/Bindings/SBThreadBinding.cpp")
        .file("src/lldb/Bindings/SBThreadCollectionBinding.cpp")
        .file("src/lldb/Bindings/SBThreadPlanBinding.cpp")
        .file("src/lldb/Bindings/SBTypeBinding.cpp")
        .file("src/lldb/Bindings/SBTypeCategoryBinding.cpp")
        .file("src/lldb/Bindings/SBTypeEnumMemberBinding.cpp")
        .file("src/lldb/Bindings/SBTypeFilterBinding.cpp")
        .file("src/lldb/Bindings/SBTypeFormatBinding.cpp")
        .file("src/lldb/Bindings/SBTypeNameSpecifierBinding.cpp")
        .file("src/lldb/Bindings/SBTypeSummaryBinding.cpp")
        .file("src/lldb/Bindings/SBTypeSyntheticBinding.cpp")
        .file("src/lldb/Bindings/SBUnixSignalsBinding.cpp")
        .file("src/lldb/Bindings/SBValueBinding.cpp")
        .file("src/lldb/Bindings/SBValueListBinding.cpp")
        .file("src/lldb/Bindings/SBVariablesOptionsBinding.cpp")
        .file("src/lldb/Bindings/SBWatchpointBinding.cpp")
        .compile("liblldb-c.a");
}
