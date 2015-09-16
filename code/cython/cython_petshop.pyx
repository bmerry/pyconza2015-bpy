# distutils: language=c++
# distutils: sources=../cpp/petshop.cpp
# distutils: include_dirs=../cpp

cimport c_petshop

cdef class Parrot:
    cdef c_petshop.Parrot _this

    def voom(self):
        self._this.voom()

    property volts:
        def __get__(self):
            return self._this.get_volts()

        def __set__(self, volts):
            self._this.set_volts(volts)
