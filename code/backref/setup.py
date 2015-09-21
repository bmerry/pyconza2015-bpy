#!/usr/bin/env python
from setuptools import setup, Extension
import sys

extension = Extension(
    'backref',
    sources=['backref.cpp'],
    extra_compile_args=['-std=c++11', '-DUSE_CUSTODIAN_AND_WARD'],
    language='c++',
    include_dirs=['../cpp'],
    libraries=['boost_python-py{}{}'.format(sys.version_info.major, sys.version_info.minor)])

setup(name='backref', ext_modules=[extension])