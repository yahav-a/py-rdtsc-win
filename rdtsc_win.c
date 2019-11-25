#include <Python.h>
#include <intrin.h>


PyObject *rdtsc_win_rdtsc(PyObject *self) {

	uint64_t val = __rdtsc();
	PyObject * result = Py_BuildValue("K", val);

	return result;
}

/*
 * List of functions to add to rdtsc_win in exec_rdtsc_win().
 */
static PyMethodDef rdtsc_win_functions[] = {
    { "rdtsc", (PyCFunction)rdtsc_win_rdtsc, METH_VARARGS, "rdtsc" },
    { NULL, NULL, 0, NULL } /* marks end of array */
};

/*
 * Initialize rdtsc_win. May be called multiple times, so avoid
 * using static state.
 */
int exec_rdtsc_win(PyObject *module) {
    PyModule_AddFunctions(module, rdtsc_win_functions);

    PyModule_AddStringConstant(module, "__author__", "icebp");
    PyModule_AddStringConstant(module, "__version__", "1.0.0");
    PyModule_AddIntConstant(module, "year", 2019);

    return 0; /* success */
}

/*
 * Documentation for rdtsc_win.
 */
PyDoc_STRVAR(rdtsc_win_doc, "The rdtsc_win module");


static PyModuleDef_Slot rdtsc_win_slots[] = {
    { Py_mod_exec, exec_rdtsc_win },
    { 0, NULL }
};

static PyModuleDef rdtsc_win_def = {
    PyModuleDef_HEAD_INIT,
    "rdtsc_win",
    rdtsc_win_doc,
    0,              /* m_size */
    NULL,           /* m_methods */
    rdtsc_win_slots,
    NULL,           /* m_traverse */
    NULL,           /* m_clear */
    NULL,           /* m_free */
};

PyMODINIT_FUNC PyInit_rdtsc_win() {
    return PyModuleDef_Init(&rdtsc_win_def);
}
