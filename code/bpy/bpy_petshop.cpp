#include <boost/python.hpp>
#include "petshop.h"

using namespace petshop;
using namespace boost::python;

BOOST_PYTHON_MODULE(bpy_petshop)
{
    class_<Parrot>("Parrot")
        .def("voom", &Parrot::voom)
        .add_property("volts", &Parrot::get_volts, &Parrot::set_volts);
}
