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
