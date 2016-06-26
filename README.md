# lldb-sys

[![](http://meritbadge.herokuapp.com/lldb-sys)](https://crates.io/crates/lldb-sys)

Dual licensed under the MIT and Apache 2 licenses. The C bindings for LLDB are
licensed under the same license as LLVM.

## Installation

This crate works with Cargo and is on
[crates.io](https://crates.io/crates/lldb-sys).
Add it to your `Cargo.toml` like so:

```toml
[dependencies]
lldb-sys = "0.0.1"
```

You will need to have 2 environment variables set to do the build:

* `LLVM_ROOT` - This points to the root of the LLVM source tree.
* `LLVM_BUILD_ROOT` - This points to the root of an LLVM build directory. This may be the same as the LLVM source tree, especially if you're working from a binary install.

For now, you will have to set an `@rpath` manually on your executables so
that they can find the `LLDB.framework` at runtime. This can be done with
`install_name_tool`:

```shell
install_name_tool -add_rpath /Applications/Xcode.app/Contents/SharedFrameworks target/debug/examples/barebones
```

Alternatively, for testing and local work, you can set the
`DYLD_FRAMEWORK_PATH`:

```shell
export DYLD_FRAMEWORK_PATH=/Applications/Xcode.app/Contents/SharedFrameworks
```

## Status of Implementation

Things are under active development. This project is not quite
usable yet as some of the basic functionality is being written.

## Contribution

Unless you explicitly state otherwise, any contribution
intentionally submitted for inclusion in the work by you,
as defined in the Apache-2.0 license, shall be dual licensed
as above, without any additional terms or conditions.

## Binding Re-generation

If something happens where the Rust bindings need to be re-generated,
they were generated from this set of files with `bindgen`:

```shell
bindgen --match SB --output src/lldb_sys.rs src/lldb/Bindings/LLDBBinding.h -- -Isrc -DBINDGEN
```
