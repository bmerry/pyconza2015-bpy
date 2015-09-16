#include "Python.h"
#include "petshop.h"
#include <memory>

typedef struct
{
    PyObject_HEAD
    petshop::Parrot wrapped;
} Parrot;

static PyTypeObject ParrotType =
{
    PyVarObject_HEAD_INIT(NULL, 0)
    "capi_petshop.Parrot"
};

static PyObject *
Parrot_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    Parrot *self = (Parrot *) type->tp_alloc(type, 0);
    if (self != NULL)
    {
        new (&self->wrapped) petshop::Parrot();
    }
    return (PyObject *) self;
}

static void Parrot_dealloc(Parrot *self)
{
    self->wrapped.~Parrot();
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyObject *Parrot_voom(Parrot *self)
{
    self->wrapped.voom();
    Py_RETURN_NONE;
}

static PyObject *Parrot_get_volts(Parrot *self, void *closure)
{
    return PyLong_FromLong(self->wrapped.get_volts());
}

static int Parrot_set_volts(Parrot *self, PyObject *value, void *closure)
{
    long volts = PyLong_AsLong(value);
    if (PyErr_Occurred())
        return -1;
    if (volts < INT_MIN || volts > INT_MAX)
    {
        PyErr_SetString(PyExc_OverflowError, "Python int too large to convert to C int");
        return -1;
    }
    self->wrapped.set_volts(volts);
    return 0;
}

static PyMethodDef Parrot_methods[] =
{
    {"voom", (PyCFunction) Parrot_voom, METH_NOARGS, "voom"},
    {NULL}
};

static PyGetSetDef Parrot_getseters[] = {
    {"volts", (getter) Parrot_get_volts, (setter) Parrot_set_volts, "volts", NULL},
    {NULL}
};

static struct PyModuleDef capi_petshop_module = {
    PyModuleDef_HEAD_INIT,
    "capi_petshop",
    NULL,
    -1,
    NULL,
};

extern "C"
{

PyMODINIT_FUNC
PyInit_capi_petshop(void)
{
    PyObject *m;
    ParrotType.tp_new = Parrot_new;
    ParrotType.tp_basicsize = sizeof(Parrot);
    ParrotType.tp_flags = Py_TPFLAGS_DEFAULT;
    ParrotType.tp_dealloc = (destructor) Parrot_dealloc;
    ParrotType.tp_methods = Parrot_methods;
    ParrotType.tp_getset = Parrot_getseters;
    if (PyType_Ready(&ParrotType) < 0)
        return NULL;

    m = PyModule_Create(&capi_petshop_module);
    if (m == NULL)
        return NULL;

    Py_INCREF(&ParrotType);
    PyModule_AddObject(m, "Parrot", (PyObject *) &ParrotType);
    return m;
}

}
