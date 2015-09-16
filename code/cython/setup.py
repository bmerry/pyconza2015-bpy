#!/usr/bin/env python

from distutils.core import setup
from Cython.Build import cythonize

setup(name='cython_petshop', ext_modules=cythonize('*.pyx'))
