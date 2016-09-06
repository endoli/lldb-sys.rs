#! /bin/sh

rm -rf ../external/*
g++ \
    -MM \
    -std=c++14 \
    -I /home/slnpacifist/projects/llvm/build/include/ \
    -I /home/slnpacifist/projects/llvm/include/ \
    -I /home/slnpacifist/projects/llvm/tools/lldb/include/ \
    -I ../src/ ../src/lldb/Bindings/*.cpp \
    | grep -Po '[\-\w/]+\.h' \
    | grep -v -P "^/src/lldb/Bindings" \
    | sort -u \
    | xargs -I % ./copy_dependency.sh % ../external/