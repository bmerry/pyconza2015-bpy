#include <boost/python.hpp>
#include <string>
#include <iostream>

using std::string;
using namespace boost::python;

class flowers {
public:
    PyObject *self;
    string name;
    flowers(PyObject *self, const string &name) : self(self), name(name) {}
};

class vase {
private:
    flowers *contents = nullptr;
    handle<> ref;
public:
    void set_contents(flowers &value) {
        contents = &value;
        ref = handle<>(borrowed(value.self));
    }

    string str() const {
        return (contents ? contents->name : "empty");
    }
};

BOOST_PYTHON_MODULE(backref) {
    class_<flowers, flowers, boost::noncopyable>("Flowers", init<string>());
    class_<vase>("Vase")
        .def("set_contents", &vase::set_contents)
        .def("__str__", &vase::str);
}
