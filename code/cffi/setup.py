#!/usr/bin/env python
from setuptools import setup

setup(
    name='cffi_petshop',
    setup_requires=['cffi'],
    cffi_modules=['cffi_petshop_build.py:ffi'],
    install_requires=['cffi'])
