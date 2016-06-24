extern crate lldb_sys as lldb;

fn main() {
    let dbg = lldb::SBDebuggerCreate();
    println!("{:?}", dbg);
}
