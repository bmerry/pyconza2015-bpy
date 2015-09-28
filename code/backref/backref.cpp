/* Copyright 2015 SKA South Africa
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option) any
 * later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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
