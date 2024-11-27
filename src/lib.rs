// Licensed under the Apache License, Version 2.0 <LICENSE-APACHE or
// http://www.apache.org/licenses/LICENSE-2.0> or the MIT license
// <LICENSE-MIT or http://opensource.org/licenses/MIT>, at your
// option. This file may not be copied, modified, or distributed
// except according to those terms.

//! # lldb-sys
//!
//! [LLDB](https://lldb.llvm.org/) is a debugger from the
//! [LLVM](https://llvm.org/) project. It is usable as both a
//! standalone program as well as via an API.
//!
//! This crate provides a low-level, fairly direct mapping of the
//! [public C++ API](https://lldb.llvm.org/cpp_reference/namespacelldb.html)
//! for LLDB into unsafe Rust.
//!
//! It is primarily for use by a higher level crate, such as
//! [lldb.rs](https://crates.io/crates/lldb/).

#![allow(non_upper_case_globals)]
#![allow(non_camel_case_types)]
#![allow(non_snake_case)]
#![allow(dead_code)]
#![allow(improper_ctypes)]

mod bindings;
pub use bindings::root::lldb::*;
