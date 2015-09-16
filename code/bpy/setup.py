#!/usr/bin/env python
from setuptools import setup, Extension

extension = Extension(
    'bpy_petshop',
    sources=['bpy_petshop.cpp', '../cpp/petshop.cpp'],
    depends=['../cpp/petshop.h'],
    language='c++',
    include_dirs=['../cpp'],
    libraries=['boost_python'])

setup(name='bpy_petshop', ext_modules=[extension])
