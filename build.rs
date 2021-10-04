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
    println!("cargo:rerun-if-env-changed=LLVM_ROOT");
    println!("cargo:rerun-if-env-changed=LLVM_BUILD_ROOT");
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
    println!("cargo:rerun-if-env-changed=DOCS_RS");
    if let Ok(_) = std::env::var("DOCS_RS") {
        return;
    }
    get_compiler_config()
        .cpp(true)
        .flag("-std=c++14")
        .warnings(false)
        .include("src")
        .file("src/lldb/UnityBuild.cpp")
        .compile("liblldb-c.a");
}
