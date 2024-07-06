/*

 */
#include <Python.h>
#include "gpio.h"

static PyObject *py_gen_port(PyObject *self, PyObject *args) {
  char *buf;
  if (!PyArg_ParseTuple(args, "s", &buf) ){
    return NULL;
  }
  return Py_BuildValue("s", gen_port(buf));
}


static PyMethodDef methods[] = {
  { "gen_port", py_gen_port, METH_VARARGS, "gen_port"},
  { NULL, NULL, NULL, 0, NULL},
};

static struct PyModuleDef module = {
  PyModuleDef_HEAD_INIT,
  "npi_gpio",
  NULL,
  -1,
  methods
};

PyMODINIT_FUNC PyInit_npi_gpio(void) {
  return PyModule_Create(&module);
}
