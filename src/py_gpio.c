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

static PyObject *py_write_gpio(PyObject *self, PyObject *args) {
  int pin, val;
  if (!PyArg_ParseTuple(args, "ii", &pin, &val) ){
    return NULL;
  }
  return Py_BuildValue("i", write_gpio_port(pin, val));
}

static PyObject *py_read_gpio(PyObject *self, PyObject *args) {
  int pin;
  if (!PyArg_ParseTuple(args, "i", &pin) ){
    return NULL;
  }
  return Py_BuildValue("i", read_gpio_port(pin));
}

static PyObject *py_setup_gpio(PyObject *self, PyObject *args) {
  int pin, dir;
  if (!PyArg_ParseTuple(args, "ii", &pin, &dir) ){
    return NULL;
  }
  return Py_BuildValue("i", setup_gpio_port(pin, dir));
}

static PyObject *py_unsetup_gpio(PyObject *self, PyObject *args) {
  int pin;
  if (!PyArg_ParseTuple(args, "i", &pin) ){
    return NULL;
  }
  return Py_BuildValue("i", unsetup_gpio_port(pin));
}

static PyMethodDef methods[] = {
  { "gen_port", py_gen_port, METH_VARARGS, "gen_port"},
  { "setup", py_setup_gpio, METH_VARARGS, "setup port"},
  { "shutdown", py_unsetup_gpio, METH_VARARGS, "unsetup port"},
  { "input", py_read_gpio, METH_VARARGS, "digital in"},
  { "output", py_write_gpio, METH_VARARGS, "digital out"},
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
