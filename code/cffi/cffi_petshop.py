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

from _cffi_petshop import ffi, lib

class Parrot(object):
    def __init__(self):
        self._this = lib.parrot_new()

    def __del__(self):
        lib.parrot_delete(self._this)

    def voom(self):
        lib.parrot_voom(self._this)

    @property
    def volts(self):
        return lib.parrot_get_volts(self._this)

    @volts.setter
    def volts(self, value):
        lib.parrot_set_volts(self._this, value)
