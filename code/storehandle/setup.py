#!/usr/bin/env python
from setuptools import setup, Extension
import sys

extension = Extension(
    'storehandle',
    sources=['storehandle.cpp'],
    extra_compile_args=['-std=c++11'],
    language='c++',
    include_dirs=['../cpp'],
    libraries=['boost_python-py{}{}'.format(sys.version_info.major, sys.version_info.minor)])

setup(name='storehandle', ext_modules=[extension])
