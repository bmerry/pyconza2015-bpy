#!/usr/bin/env python
from setuptools import setup, Extension
import sys

extension = Extension(
    'bpy_petshop',
    sources=['bpy_petshop.cpp', '../cpp/petshop.cpp'],
    depends=['../cpp/petshop.h'],
    language='c++',
    include_dirs=['../cpp'],
    libraries=['boost_python-py{}{}'.format(sys.version_info.major, sys.version_info.minor)])

setup(name='bpy_petshop', ext_modules=[extension])
