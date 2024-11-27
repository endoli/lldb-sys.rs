use std::{ fs::OpenOptions, io::Write, path::PathBuf, process::Command};

fn get_llvm_output(arg: &str) -> String {
    let llvm_config = std::env::var("LLVM_CONFIG").unwrap_or_else(|_| "llvm-config".into());
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

fn main() {
    println!("cargo:rerun-if-env-changed=LLVM_CONFIG");
    println!("cargo:rerun-if-env-changed=LLDB_ADDITIONAL_INCLUDE_DIRS");
    println!("cargo:rerun-if-changed=src/lib.rs");
    println!("cargo:rerun-if-changed=src/debugger.cpp");
    println!("cargo:rerun-if-changed=include/debuger.h");
    println!("cargo:rustc-link-lib=lldb");
    println!("cargo:rustc-link-lib=stdc++");

    let llvm_headers_path = get_llvm_output("--includedir");
    let llvm_lib_path = get_llvm_output("--libdir");

    println!("cargo:rustc-link-search={}", llvm_lib_path);

    let bindings = bindgen::Builder::default()
        .parse_callbacks(Box::new(bindgen::CargoCallbacks::new()))
        .header(format!("{}/lldb/API/LLDB.h", llvm_headers_path))
        .layout_tests(false)
        .allowlist_item("lldb::.*")
        .opaque_type(".*")
        .no_copy("lldb::.*")
        .enable_cxx_namespaces()
        .generate_cstr(true)
        .clang_arg("-xc++")
        .generate()
        .expect("Unable to generate bindings");

    let bindings = bindings.to_string().replace(
        "pub _bindgen_opaque_blob",
        "pub _bindgen_phantom: [u64; 3usize], pub _bindgen_opaque_blob",
    );

    let mut file = OpenOptions::new()
        .write(true)
        .truncate(true)
		.create(true)
        .open(PathBuf::from("./src/").join("bindings.rs"))
        .expect("could not open bindings file");

    file.write(bindings.as_bytes())
        .expect("could not write bindings file");

}
