#!/usr/bin/env python

# Copyright 2015 SKA South Africa
#
# This program is free software: you can redistribute it and/or modify it under
# the terms of the GNU Lesser General Public License as published by the Free
# Software Foundation, either version 3 of the License, or (at your option) any
# later version.
#
# This program is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
# FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
# details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

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
