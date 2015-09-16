cdef extern from "petshop.h" namespace "petshop":
    cdef cppclass Parrot:
        void voom()
        void set_volts(int volts)
        int get_volts()
