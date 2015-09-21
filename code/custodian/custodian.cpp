#include <boost/python.hpp>
#include <string>
#include <iostream>

using std::string;

class flowers {
public:
    string name;
    explicit flowers(const string &name) : name(name) {}
};

class vase {
private:
    flowers *contents = nullptr;
public:
    void set_contents(flowers &value) {
        contents = &value;
    }

    string str() const {
        return (contents ? contents->name : "empty");
    }
};

BOOST_PYTHON_MODULE(custodian) {
    using namespace boost::python;
    class_<flowers>("Flowers", init<string>());
    class_<vase>("Vase")
        .def("set_contents", &vase::set_contents
#ifdef USE_CUSTODIAN_AND_WARD
             , with_custodian_and_ward_postcall<1, 2>()
#endif
        )
        .def("__str__", &vase::str);
}
