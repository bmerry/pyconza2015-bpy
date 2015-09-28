/* This code is taken from spead2. */

#ifndef STOREHANDLE_H
#define STOREHANDLE_H

#include <boost/python.hpp>

template<typename T, boost::python::handle<> T::*handle_ptr,
    std::size_t custodian, std::size_t ward,
    class BasePolicy_ = boost::python::default_call_policies>
struct store_handle_postcall : BasePolicy_
{
    static_assert(custodian != ward, "object must not hold reference to itself");

    static PyObject* postcall(PyObject *args, PyObject *result)
    {
        std::size_t arity = PyTuple_GET_SIZE(args);
        if (custodian > arity || ward > arity)
        {
            PyErr_SetString(PyExc_IndexError,
                            "store_handle_postcall: argument index out of range");
            return nullptr;
        }

        result = BasePolicy_::postcall(args, result);
        if (result == nullptr)
            return nullptr;

        PyObject *owner = custodian > 0 ? PyTuple_GET_ITEM(args, custodian - 1) : result;
        PyObject *child = ward > 0 ? PyTuple_GET_ITEM(args, ward - 1) : result;
        boost::python::extract<T &> extractor(owner);
        try
        {
            T &target = extractor();
            target.*handle_ptr = boost::python::handle<>(boost::python::borrowed(child));
        }
        catch (boost::python::error_already_set)
        {
            Py_XDECREF(result);
            return nullptr;
        }
        return result;
    }
};

#endif // !STORE_HANDLE_H
