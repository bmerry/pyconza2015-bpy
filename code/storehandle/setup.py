#!/usr/bin/env python
from setuptools import setup, Extension
import sys

extension = Extension(
    'storehandle',
    sources=['storehandle.cpp'],
    dependencies=['storehandle.h'],
    extra_compile_args=['-std=c++11'],
    language='c++',
    libraries=['boost_python-py{}{}'.format(sys.version_info.major, sys.version_info.minor)])

setup(name='storehandle', ext_modules=[extension])
