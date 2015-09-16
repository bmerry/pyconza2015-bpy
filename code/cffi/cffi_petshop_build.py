#!/usr/bin/env python
from cffi import FFI
ffi = FFI()

ffi.set_source("_cffi_petshop", """#include "petshop_wrap.h" """,
    include_dirs=['../cpp'],
    sources=['../cpp/petshop_wrap.cpp', '../cpp/petshop.cpp'],
    language='c++')

ffi.cdef("""
typedef struct
{
    ...;
} parrot_handle;

parrot_handle parrot_new(void);
void parrot_delete(parrot_handle);
void parrot_voom(parrot_handle);
void parrot_set_volts(parrot_handle, int volts);
int parrot_get_volts(parrot_handle);
""")

if __name__ == '__main__':
    ffi.compile()
