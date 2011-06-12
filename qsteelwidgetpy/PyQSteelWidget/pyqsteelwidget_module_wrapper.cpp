
#include <Python.h>
#include <shiboken.h>
#include <algorithm>
#include "pyqsteelwidget_python.h"



// Extra includes

// Global functions ------------------------------------------------------------

static PyMethodDef PyQSteelWidget_methods[] = {
    {0} // Sentinel
};

// Classes initialization functions ------------------------------------------------------------
void init_QSteelWidget(PyObject* module);

PyTypeObject** SbkPyQSteelWidgetTypes;

PyTypeObject** SbkPySide_QtCoreTypes;

PyTypeObject** SbkPySide_QtGuiTypes;

// Module initialization ------------------------------------------------------------

#if defined _WIN32 || defined __CYGWIN__
    #define SBK_EXPORT_MODULE __declspec(dllexport)
#elif __GNUC__ >= 4
    #define SBK_EXPORT_MODULE __attribute__ ((visibility("default")))
#else
    #define SBK_EXPORT_MODULE
#endif

extern "C" SBK_EXPORT_MODULE void initPyQSteelWidget()
{
    if (!Shiboken::importModule("PySide.QtCore", &SbkPySide_QtCoreTypes)) {
        PyErr_SetString(PyExc_ImportError,"could not import PySide.QtCore");
        return;
    }

    if (!Shiboken::importModule("PySide.QtGui", &SbkPySide_QtGuiTypes)) {
        PyErr_SetString(PyExc_ImportError,"could not import PySide.QtGui");
        return;
    }

    Shiboken::init();
    PyObject* module = Py_InitModule("PyQSteelWidget", PyQSteelWidget_methods);

    // Create a CObject containing the API pointer array's address
    static PyTypeObject* cppApi[SBK_PyQSteelWidget_IDX_COUNT];
    SbkPyQSteelWidgetTypes = cppApi;
    PyObject* cppApiObject = PyCObject_FromVoidPtr(reinterpret_cast<void*>(cppApi), 0);
    PyModule_AddObject(module, "_Cpp_Api", cppApiObject);

    // Initialize classes in the type system
    init_QSteelWidget(module);

    // Register primitive types on TypeResolver

    if (PyErr_Occurred()) {
        PyErr_Print();
        Py_FatalError("can't initialize module PyQSteelWidget");
    }
}

