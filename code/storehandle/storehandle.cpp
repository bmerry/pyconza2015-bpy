#include <boost/python.hpp>
#include <string>
#include <iostream>
#include "storehandle.h"

using std::string;
using namespace boost::python;

class flowers {
public:
    string name;
    explicit flowers(const string &name) : name(name) {}
};

class vase {
private:
    flowers *contents = nullptr;
public:
    handle<> flowers_handle;

    void set_contents(flowers &value) {
        contents = &value;
    }

    string str() const {
        return (contents ? contents->name : "empty");
    }
};

BOOST_PYTHON_MODULE(storehandle) {
    class_<flowers>("Flowers", init<string>());
    class_<vase>("Vase")
        .def("set_contents", &vase::set_contents,
             store_handle_postcall<vase, &vase::flowers_handle, 1, 2>())
        .def("__str__", &vase::str);
}
