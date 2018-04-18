#include <Python.h>

static PyObject* ref_count(PyObject* self, PyObject* args) {
    PyObject* object;

    if (! PyArg_ParseTuple( args, "O", &object)) {
        return NULL;
    }

    return Py_BuildValue("i", Py_REFCNT(object));
}

static char ref_docs[] = "count(): get reference count";

static PyMethodDef ref_funcs[] = {
        {"count", (PyCFunction)ref_count, METH_VARARGS, ref_docs},
        {NULL, NULL, 0, NULL}
};

static struct PyModuleDef ref_def = {
        PyModuleDef_HEAD_INIT,
        "ref",
        NULL,
        -1,
        ref_funcs,
};

PyMODINIT_FUNC PyInit_ref(void) {
    return PyModule_Create(&ref_def);
}