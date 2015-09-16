#!/usr/bin/env python
from setuptools import setup, Extension

setup(
    name='capi_petshop',
    ext_modules=[Extension('capi_petshop',
        sources=['capi_petshop.cpp', '../cpp/petshop.cpp'],
        depends=['../cpp/petshop.h'],
        include_dirs=['../cpp'],
        language='c++')]
)
