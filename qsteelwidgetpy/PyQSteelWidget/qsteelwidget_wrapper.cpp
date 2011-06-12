
//workaround to access protected functions
#define protected public

// default includes
#include <shiboken.h>
#include <typeresolver.h>
#include <typeinfo>
#include <set>
#include "pyqsteelwidget_python.h"

#include "qsteelwidget_wrapper.h"

// Extra includes
#include <QList>
#include <qbytearray.h>
#include <qcursor.h>
#include <qfont.h>
#include <qfontinfo.h>
#include <qfontmetrics.h>
#include <qkeysequence.h>
#include <qmargins.h>
#include <qobject.h>
#include <qpaintdevice.h>
#include <qpalette.h>
#include <qpoint.h>
#include <qrect.h>
#include <qregion.h>
#include <qsize.h>
#include <qsizepolicy.h>
#include <qvector3d.h>
#include <qwidget.h>


// Native ---------------------------------------------------------

QSteelWidgetWrapper::QSteelWidgetWrapper(QWidget * parent) : QSteelWidget(parent) {
    // ... middle
}

void QSteelWidgetWrapper::actionEvent(QActionEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef py_override(Shiboken::BindingManager::instance().getOverride(this, "actionEvent"));
    if (py_override.isNull()) {
        gil.release();
        return this->::QWidget::actionEvent(event);
    }

    Shiboken::AutoDecRef pyargs(Py_BuildValue("(N)",
        Shiboken::Converter< ::QActionEvent * >::toPython(event)
    ));
    bool invalidadeArg1 = PyTuple_GET_ITEM(pyargs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(py_override, pyargs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidadeArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyargs, 0));
}

void QSteelWidgetWrapper::changeEvent(QEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef py_override(Shiboken::BindingManager::instance().getOverride(this, "changeEvent"));
    if (py_override.isNull()) {
        gil.release();
        return this->::QWidget::changeEvent(event);
    }

    Shiboken::AutoDecRef pyargs(Py_BuildValue("(N)",
        Shiboken::Converter< ::QEvent * >::toPython(event)
    ));
    bool invalidadeArg1 = PyTuple_GET_ITEM(pyargs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(py_override, pyargs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidadeArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyargs, 0));
}

void QSteelWidgetWrapper::childEvent(QChildEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef py_override(Shiboken::BindingManager::instance().getOverride(this, "childEvent"));
    if (py_override.isNull()) {
        gil.release();
        return this->::QObject::childEvent(arg__1);
    }

    Shiboken::AutoDecRef pyargs(Py_BuildValue("(N)",
        Shiboken::Converter< ::QChildEvent * >::toPython(arg__1)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(py_override, pyargs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QSteelWidgetWrapper::closeEvent(QCloseEvent * e)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef py_override(Shiboken::BindingManager::instance().getOverride(this, "closeEvent"));
    if (py_override.isNull()) {
        gil.release();
        return this->::QSteelWidget::closeEvent(e);
    }

    Shiboken::AutoDecRef pyargs(Py_BuildValue("(N)",
        Shiboken::Converter< ::QCloseEvent * >::toPython(e)
    ));
    bool invalidadeArg1 = PyTuple_GET_ITEM(pyargs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(py_override, pyargs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidadeArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyargs, 0));
}

void QSteelWidgetWrapper::connectNotify(const char * signal)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef py_override(Shiboken::BindingManager::instance().getOverride(this, "connectNotify"));
    if (py_override.isNull()) {
        gil.release();
        return this->::QObject::connectNotify(signal);
    }

    Shiboken::AutoDecRef pyargs(Py_BuildValue("(N)",
        Shiboken::Converter< const char * >::toPython(signal)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(py_override, pyargs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QSteelWidgetWrapper::contextMenuEvent(QContextMenuEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef py_override(Shiboken::BindingManager::instance().getOverride(this, "contextMenuEvent"));
    if (py_override.isNull()) {
        gil.release();
        return this->::QWidget::contextMenuEvent(event);
    }

    Shiboken::AutoDecRef pyargs(Py_BuildValue("(N)",
        Shiboken::Converter< ::QContextMenuEvent * >::toPython(event)
    ));
    bool invalidadeArg1 = PyTuple_GET_ITEM(pyargs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(py_override, pyargs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidadeArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyargs, 0));
}

void QSteelWidgetWrapper::customEvent(QEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef py_override(Shiboken::BindingManager::instance().getOverride(this, "customEvent"));
    if (py_override.isNull()) {
        gil.release();
        return this->::QObject::customEvent(arg__1);
    }

    Shiboken::AutoDecRef pyargs(Py_BuildValue("(N)",
        Shiboken::Converter< ::QEvent * >::toPython(arg__1)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(py_override, pyargs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

int QSteelWidgetWrapper::devType() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return int(0);
    Shiboken::AutoDecRef py_override(Shiboken::BindingManager::instance().getOverride(this, "devType"));
    if (py_override.isNull()) {
        gil.release();
        return this->::QWidget::devType();
    }

    Shiboken::AutoDecRef pyargs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(py_override, pyargs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return int(0);
    }
    // Check return type
    bool typeIsValid = PyInt_Check(pyResult);
    if (!typeIsValid) {
        PyErr_Format(PyExc_TypeError, "Invalid return value in function %s, expected %s, got %s.", "QSteelWidget.devType", "int", pyResult->ob_type->tp_name);
        return int(0);
    }
    int cppResult(Shiboken::Converter< int >::toCpp(pyResult));
    return cppResult;
}

void QSteelWidgetWrapper::disconnectNotify(const char * signal)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef py_override(Shiboken::BindingManager::instance().getOverride(this, "disconnectNotify"));
    if (py_override.isNull()) {
        gil.release();
        return this->::QObject::disconnectNotify(signal);
    }

    Shiboken::AutoDecRef pyargs(Py_BuildValue("(N)",
        Shiboken::Converter< const char * >::toPython(signal)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(py_override, pyargs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QSteelWidgetWrapper::dragEnterEvent(QDragEnterEvent * e)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef py_override(Shiboken::BindingManager::instance().getOverride(this, "dragEnterEvent"));
    if (py_override.isNull()) {
        gil.release();
        return this->::QSteelWidget::dragEnterEvent(e);
    }

    Shiboken::AutoDecRef pyargs(Py_BuildValue("(N)",
        Shiboken::Converter< ::QDragEnterEvent * >::toPython(e)
    ));
    bool invalidadeArg1 = PyTuple_GET_ITEM(pyargs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(py_override, pyargs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidadeArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyargs, 0));
}

void QSteelWidgetWrapper::dragLeaveEvent(QDragLeaveEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef py_override(Shiboken::BindingManager::instance().getOverride(this, "dragLeaveEvent"));
    if (py_override.isNull()) {
        gil.release();
        return this->::QWidget::dragLeaveEvent(event);
    }

    Shiboken::AutoDecRef pyargs(Py_BuildValue("(N)",
        Shiboken::Converter< ::QDragLeaveEvent * >::toPython(event)
    ));
    bool invalidadeArg1 = PyTuple_GET_ITEM(pyargs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(py_override, pyargs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidadeArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyargs, 0));
}

void QSteelWidgetWrapper::dragMoveEvent(QDragMoveEvent * e)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef py_override(Shiboken::BindingManager::instance().getOverride(this, "dragMoveEvent"));
    if (py_override.isNull()) {
        gil.release();
        return this->::QSteelWidget::dragMoveEvent(e);
    }

    Shiboken::AutoDecRef pyargs(Py_BuildValue("(N)",
        Shiboken::Converter< ::QDragMoveEvent * >::toPython(e)
    ));
    bool invalidadeArg1 = PyTuple_GET_ITEM(pyargs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(py_override, pyargs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidadeArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyargs, 0));
}

void QSteelWidgetWrapper::dropEvent(QDropEvent * e)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef py_override(Shiboken::BindingManager::instance().getOverride(this, "dropEvent"));
    if (py_override.isNull()) {
        gil.release();
        return this->::QSteelWidget::dropEvent(e);
    }

    Shiboken::AutoDecRef pyargs(Py_BuildValue("(N)",
        Shiboken::Converter< ::QDropEvent * >::toPython(e)
    ));
    bool invalidadeArg1 = PyTuple_GET_ITEM(pyargs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(py_override, pyargs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidadeArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyargs, 0));
}

void QSteelWidgetWrapper::enterEvent(QEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef py_override(Shiboken::BindingManager::instance().getOverride(this, "enterEvent"));
    if (py_override.isNull()) {
        gil.release();
        return this->::QWidget::enterEvent(event);
    }

    Shiboken::AutoDecRef pyargs(Py_BuildValue("(N)",
        Shiboken::Converter< ::QEvent * >::toPython(event)
    ));
    bool invalidadeArg1 = PyTuple_GET_ITEM(pyargs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(py_override, pyargs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidadeArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyargs, 0));
}

bool QSteelWidgetWrapper::event(QEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return bool(0);
    Shiboken::AutoDecRef py_override(Shiboken::BindingManager::instance().getOverride(this, "event"));
    if (py_override.isNull()) {
        gil.release();
        return this->::QWidget::event(arg__1);
    }

    Shiboken::AutoDecRef pyargs(Py_BuildValue("(N)",
        Shiboken::Converter< ::QEvent * >::toPython(arg__1)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(py_override, pyargs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return bool(0);
    }
    // Check return type
    bool typeIsValid = PyBool_Check(pyResult);
    if (!typeIsValid) {
        PyErr_Format(PyExc_TypeError, "Invalid return value in function %s, expected %s, got %s.", "QSteelWidget.event", "bool", pyResult->ob_type->tp_name);
        return bool(0);
    }
    bool cppResult(Shiboken::Converter< bool >::toCpp(pyResult));
    return cppResult;
}

bool QSteelWidgetWrapper::eventFilter(QObject * arg__1, QEvent * arg__2)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return bool(0);
    Shiboken::AutoDecRef py_override(Shiboken::BindingManager::instance().getOverride(this, "eventFilter"));
    if (py_override.isNull()) {
        gil.release();
        return this->::QObject::eventFilter(arg__1, arg__2);
    }

    Shiboken::AutoDecRef pyargs(Py_BuildValue("(NN)",
        Shiboken::Converter< ::QObject * >::toPython(arg__1),
        Shiboken::Converter< ::QEvent * >::toPython(arg__2)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(py_override, pyargs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return bool(0);
    }
    // Check return type
    bool typeIsValid = PyBool_Check(pyResult);
    if (!typeIsValid) {
        PyErr_Format(PyExc_TypeError, "Invalid return value in function %s, expected %s, got %s.", "QSteelWidget.eventFilter", "bool", pyResult->ob_type->tp_name);
        return bool(0);
    }
    bool cppResult(Shiboken::Converter< bool >::toCpp(pyResult));
    return cppResult;
}

void QSteelWidgetWrapper::focusInEvent(QFocusEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef py_override(Shiboken::BindingManager::instance().getOverride(this, "focusInEvent"));
    if (py_override.isNull()) {
        gil.release();
        return this->::QWidget::focusInEvent(event);
    }

    Shiboken::AutoDecRef pyargs(Py_BuildValue("(N)",
        Shiboken::Converter< ::QFocusEvent * >::toPython(event)
    ));
    bool invalidadeArg1 = PyTuple_GET_ITEM(pyargs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(py_override, pyargs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidadeArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyargs, 0));
}

bool QSteelWidgetWrapper::focusNextPrevChild(bool next)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return bool(0);
    Shiboken::AutoDecRef py_override(Shiboken::BindingManager::instance().getOverride(this, "focusNextPrevChild"));
    if (py_override.isNull()) {
        gil.release();
        return this->::QWidget::focusNextPrevChild(next);
    }

    Shiboken::AutoDecRef pyargs(Py_BuildValue("(N)",
        Shiboken::Converter< bool >::toPython(next)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(py_override, pyargs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return bool(0);
    }
    // Check return type
    bool typeIsValid = PyBool_Check(pyResult);
    if (!typeIsValid) {
        PyErr_Format(PyExc_TypeError, "Invalid return value in function %s, expected %s, got %s.", "QSteelWidget.focusNextPrevChild", "bool", pyResult->ob_type->tp_name);
        return bool(0);
    }
    bool cppResult(Shiboken::Converter< bool >::toCpp(pyResult));
    return cppResult;
}

void QSteelWidgetWrapper::focusOutEvent(QFocusEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef py_override(Shiboken::BindingManager::instance().getOverride(this, "focusOutEvent"));
    if (py_override.isNull()) {
        gil.release();
        return this->::QWidget::focusOutEvent(event);
    }

    Shiboken::AutoDecRef pyargs(Py_BuildValue("(N)",
        Shiboken::Converter< ::QFocusEvent * >::toPython(event)
    ));
    bool invalidadeArg1 = PyTuple_GET_ITEM(pyargs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(py_override, pyargs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidadeArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyargs, 0));
}

int QSteelWidgetWrapper::heightForWidth(int arg__1) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return int(0);
    Shiboken::AutoDecRef py_override(Shiboken::BindingManager::instance().getOverride(this, "heightForWidth"));
    if (py_override.isNull()) {
        gil.release();
        return this->::QWidget::heightForWidth(arg__1);
    }

    Shiboken::AutoDecRef pyargs(Py_BuildValue("(i)",
        arg__1
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(py_override, pyargs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return int(0);
    }
    // Check return type
    bool typeIsValid = PyInt_Check(pyResult);
    if (!typeIsValid) {
        PyErr_Format(PyExc_TypeError, "Invalid return value in function %s, expected %s, got %s.", "QSteelWidget.heightForWidth", "int", pyResult->ob_type->tp_name);
        return int(0);
    }
    int cppResult(Shiboken::Converter< int >::toCpp(pyResult));
    return cppResult;
}

void QSteelWidgetWrapper::hideEvent(QHideEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef py_override(Shiboken::BindingManager::instance().getOverride(this, "hideEvent"));
    if (py_override.isNull()) {
        gil.release();
        return this->::QWidget::hideEvent(event);
    }

    Shiboken::AutoDecRef pyargs(Py_BuildValue("(N)",
        Shiboken::Converter< ::QHideEvent * >::toPython(event)
    ));
    bool invalidadeArg1 = PyTuple_GET_ITEM(pyargs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(py_override, pyargs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidadeArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyargs, 0));
}

void QSteelWidgetWrapper::inputMethodEvent(QInputMethodEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef py_override(Shiboken::BindingManager::instance().getOverride(this, "inputMethodEvent"));
    if (py_override.isNull()) {
        gil.release();
        return this->::QWidget::inputMethodEvent(event);
    }

    Shiboken::AutoDecRef pyargs(Py_BuildValue("(N)",
        Shiboken::Converter< ::QInputMethodEvent * >::toPython(event)
    ));
    bool invalidadeArg1 = PyTuple_GET_ITEM(pyargs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(py_override, pyargs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidadeArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyargs, 0));
}

QVariant QSteelWidgetWrapper::inputMethodQuery(Qt::InputMethodQuery arg__1) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return QVariant(0);
    Shiboken::AutoDecRef py_override(Shiboken::BindingManager::instance().getOverride(this, "inputMethodQuery"));
    if (py_override.isNull()) {
        gil.release();
        return this->::QWidget::inputMethodQuery(arg__1);
    }

    Shiboken::AutoDecRef pyargs(Py_BuildValue("(N)",
        Shiboken::Converter< ::Qt::InputMethodQuery >::toPython(arg__1)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(py_override, pyargs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return QVariant(0);
    }
    // Check return type
    bool typeIsValid = Shiboken::Converter< QVariant >::isConvertible(pyResult);
    if (!typeIsValid) {
        PyErr_Format(PyExc_TypeError, "Invalid return value in function %s, expected %s, got %s.", "QSteelWidget.inputMethodQuery", "QVariant", pyResult->ob_type->tp_name);
        return QVariant(0);
    }
    QVariant cppResult(Shiboken::Converter< QVariant >::toCpp(pyResult));
    return cppResult;
}

void QSteelWidgetWrapper::keyPressEvent(QKeyEvent * e)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef py_override(Shiboken::BindingManager::instance().getOverride(this, "keyPressEvent"));
    if (py_override.isNull()) {
        gil.release();
        return this->::QSteelWidget::keyPressEvent(e);
    }

    Shiboken::AutoDecRef pyargs(Py_BuildValue("(N)",
        Shiboken::Converter< ::QKeyEvent * >::toPython(e)
    ));
    bool invalidadeArg1 = PyTuple_GET_ITEM(pyargs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(py_override, pyargs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidadeArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyargs, 0));
}

void QSteelWidgetWrapper::keyReleaseEvent(QKeyEvent * e)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef py_override(Shiboken::BindingManager::instance().getOverride(this, "keyReleaseEvent"));
    if (py_override.isNull()) {
        gil.release();
        return this->::QSteelWidget::keyReleaseEvent(e);
    }

    Shiboken::AutoDecRef pyargs(Py_BuildValue("(N)",
        Shiboken::Converter< ::QKeyEvent * >::toPython(e)
    ));
    bool invalidadeArg1 = PyTuple_GET_ITEM(pyargs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(py_override, pyargs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidadeArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyargs, 0));
}

void QSteelWidgetWrapper::languageChange()
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef py_override(Shiboken::BindingManager::instance().getOverride(this, "languageChange"));
    if (py_override.isNull()) {
        gil.release();
        return this->::QWidget::languageChange();
    }

    Shiboken::AutoDecRef pyargs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(py_override, pyargs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QSteelWidgetWrapper::leaveEvent(QEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef py_override(Shiboken::BindingManager::instance().getOverride(this, "leaveEvent"));
    if (py_override.isNull()) {
        gil.release();
        return this->::QWidget::leaveEvent(event);
    }

    Shiboken::AutoDecRef pyargs(Py_BuildValue("(N)",
        Shiboken::Converter< ::QEvent * >::toPython(event)
    ));
    bool invalidadeArg1 = PyTuple_GET_ITEM(pyargs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(py_override, pyargs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidadeArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyargs, 0));
}

int QSteelWidgetWrapper::metric(QPaintDevice::PaintDeviceMetric arg__1) const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return int(0);
    Shiboken::AutoDecRef py_override(Shiboken::BindingManager::instance().getOverride(this, "metric"));
    if (py_override.isNull()) {
        gil.release();
        return this->::QWidget::metric(arg__1);
    }

    Shiboken::AutoDecRef pyargs(Py_BuildValue("(N)",
        Shiboken::Converter< ::QPaintDevice::PaintDeviceMetric >::toPython(arg__1)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(py_override, pyargs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return int(0);
    }
    // Check return type
    bool typeIsValid = PyInt_Check(pyResult);
    if (!typeIsValid) {
        PyErr_Format(PyExc_TypeError, "Invalid return value in function %s, expected %s, got %s.", "QSteelWidget.metric", "int", pyResult->ob_type->tp_name);
        return int(0);
    }
    int cppResult(Shiboken::Converter< int >::toCpp(pyResult));
    return cppResult;
}

QSize QSteelWidgetWrapper::minimumSizeHint() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return QSize();
    Shiboken::AutoDecRef py_override(Shiboken::BindingManager::instance().getOverride(this, "minimumSizeHint"));
    if (py_override.isNull()) {
        gil.release();
        return this->::QWidget::minimumSizeHint();
    }

    Shiboken::AutoDecRef pyargs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(py_override, pyargs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return QSize();
    }
    // Check return type
    bool typeIsValid = Shiboken::Converter< ::QSize >::isConvertible(pyResult);
    if (!typeIsValid) {
        PyErr_Format(PyExc_TypeError, "Invalid return value in function %s, expected %s, got %s.", "QSteelWidget.minimumSizeHint", Shiboken::SbkType<QSize >()->tp_name, pyResult->ob_type->tp_name);
        return QSize();
    }
    QSize cppResult(Shiboken::Converter< ::QSize >::toCpp(pyResult));
    return cppResult;
}

void QSteelWidgetWrapper::mouseDoubleClickEvent(QMouseEvent * e)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef py_override(Shiboken::BindingManager::instance().getOverride(this, "mouseDoubleClickEvent"));
    if (py_override.isNull()) {
        gil.release();
        return this->::QSteelWidget::mouseDoubleClickEvent(e);
    }

    Shiboken::AutoDecRef pyargs(Py_BuildValue("(N)",
        Shiboken::Converter< ::QMouseEvent * >::toPython(e)
    ));
    bool invalidadeArg1 = PyTuple_GET_ITEM(pyargs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(py_override, pyargs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidadeArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyargs, 0));
}

void QSteelWidgetWrapper::mouseMoveEvent(QMouseEvent * e)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef py_override(Shiboken::BindingManager::instance().getOverride(this, "mouseMoveEvent"));
    if (py_override.isNull()) {
        gil.release();
        return this->::QSteelWidget::mouseMoveEvent(e);
    }

    Shiboken::AutoDecRef pyargs(Py_BuildValue("(N)",
        Shiboken::Converter< ::QMouseEvent * >::toPython(e)
    ));
    bool invalidadeArg1 = PyTuple_GET_ITEM(pyargs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(py_override, pyargs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidadeArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyargs, 0));
}

void QSteelWidgetWrapper::mousePressEvent(QMouseEvent * e)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef py_override(Shiboken::BindingManager::instance().getOverride(this, "mousePressEvent"));
    if (py_override.isNull()) {
        gil.release();
        return this->::QSteelWidget::mousePressEvent(e);
    }

    Shiboken::AutoDecRef pyargs(Py_BuildValue("(N)",
        Shiboken::Converter< ::QMouseEvent * >::toPython(e)
    ));
    bool invalidadeArg1 = PyTuple_GET_ITEM(pyargs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(py_override, pyargs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidadeArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyargs, 0));
}

void QSteelWidgetWrapper::mouseReleaseEvent(QMouseEvent * e)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef py_override(Shiboken::BindingManager::instance().getOverride(this, "mouseReleaseEvent"));
    if (py_override.isNull()) {
        gil.release();
        return this->::QSteelWidget::mouseReleaseEvent(e);
    }

    Shiboken::AutoDecRef pyargs(Py_BuildValue("(N)",
        Shiboken::Converter< ::QMouseEvent * >::toPython(e)
    ));
    bool invalidadeArg1 = PyTuple_GET_ITEM(pyargs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(py_override, pyargs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidadeArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyargs, 0));
}

void QSteelWidgetWrapper::moveEvent(QMoveEvent * e)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef py_override(Shiboken::BindingManager::instance().getOverride(this, "moveEvent"));
    if (py_override.isNull()) {
        gil.release();
        return this->::QSteelWidget::moveEvent(e);
    }

    Shiboken::AutoDecRef pyargs(Py_BuildValue("(N)",
        Shiboken::Converter< ::QMoveEvent * >::toPython(e)
    ));
    bool invalidadeArg1 = PyTuple_GET_ITEM(pyargs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(py_override, pyargs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidadeArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyargs, 0));
}

QPaintEngine * QSteelWidgetWrapper::paintEngine() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return 0;
    Shiboken::AutoDecRef py_override(Shiboken::BindingManager::instance().getOverride(this, "paintEngine"));
    if (py_override.isNull()) {
        gil.release();
        return this->::QSteelWidget::paintEngine();
    }

    Shiboken::AutoDecRef pyargs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(py_override, pyargs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return 0;
    }
    // Check return type
    bool typeIsValid = Shiboken::Converter< ::QPaintEngine * >::isConvertible(pyResult);
    typeIsValid = typeIsValid || (pyResult == Py_None);
    if (!typeIsValid) {
        PyErr_Format(PyExc_TypeError, "Invalid return value in function %s, expected %s, got %s.", "QSteelWidget.paintEngine", Shiboken::SbkType<QPaintEngine >()->tp_name, pyResult->ob_type->tp_name);
        return 0;
    }
    QPaintEngine * cppResult(Shiboken::Converter< ::QPaintEngine * >::toCpp(pyResult));
    return cppResult;
}

void QSteelWidgetWrapper::paintEvent(QPaintEvent * e)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef py_override(Shiboken::BindingManager::instance().getOverride(this, "paintEvent"));
    if (py_override.isNull()) {
        gil.release();
        return this->::QSteelWidget::paintEvent(e);
    }

    Shiboken::AutoDecRef pyargs(Py_BuildValue("(N)",
        Shiboken::Converter< ::QPaintEvent * >::toPython(e)
    ));
    bool invalidadeArg1 = PyTuple_GET_ITEM(pyargs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(py_override, pyargs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidadeArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyargs, 0));
}

void QSteelWidgetWrapper::resizeEvent(QResizeEvent * e)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef py_override(Shiboken::BindingManager::instance().getOverride(this, "resizeEvent"));
    if (py_override.isNull()) {
        gil.release();
        return this->::QSteelWidget::resizeEvent(e);
    }

    Shiboken::AutoDecRef pyargs(Py_BuildValue("(N)",
        Shiboken::Converter< ::QResizeEvent * >::toPython(e)
    ));
    bool invalidadeArg1 = PyTuple_GET_ITEM(pyargs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(py_override, pyargs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidadeArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyargs, 0));
}

void QSteelWidgetWrapper::setVisible(bool visible)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef py_override(Shiboken::BindingManager::instance().getOverride(this, "setVisible"));
    if (py_override.isNull()) {
        gil.release();
        return this->::QWidget::setVisible(visible);
    }

    Shiboken::AutoDecRef pyargs(Py_BuildValue("(N)",
        Shiboken::Converter< bool >::toPython(visible)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(py_override, pyargs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QSteelWidgetWrapper::showEvent(QShowEvent * e)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef py_override(Shiboken::BindingManager::instance().getOverride(this, "showEvent"));
    if (py_override.isNull()) {
        gil.release();
        return this->::QSteelWidget::showEvent(e);
    }

    Shiboken::AutoDecRef pyargs(Py_BuildValue("(N)",
        Shiboken::Converter< ::QShowEvent * >::toPython(e)
    ));
    bool invalidadeArg1 = PyTuple_GET_ITEM(pyargs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(py_override, pyargs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidadeArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyargs, 0));
}

QSize QSteelWidgetWrapper::sizeHint() const
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return QSize();
    Shiboken::AutoDecRef py_override(Shiboken::BindingManager::instance().getOverride(this, "sizeHint"));
    if (py_override.isNull()) {
        gil.release();
        return this->::QWidget::sizeHint();
    }

    Shiboken::AutoDecRef pyargs(PyTuple_New(0));

    Shiboken::AutoDecRef pyResult(PyObject_Call(py_override, pyargs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return QSize();
    }
    // Check return type
    bool typeIsValid = Shiboken::Converter< ::QSize >::isConvertible(pyResult);
    if (!typeIsValid) {
        PyErr_Format(PyExc_TypeError, "Invalid return value in function %s, expected %s, got %s.", "QSteelWidget.sizeHint", Shiboken::SbkType<QSize >()->tp_name, pyResult->ob_type->tp_name);
        return QSize();
    }
    QSize cppResult(Shiboken::Converter< ::QSize >::toCpp(pyResult));
    return cppResult;
}

void QSteelWidgetWrapper::tabletEvent(QTabletEvent * event)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef py_override(Shiboken::BindingManager::instance().getOverride(this, "tabletEvent"));
    if (py_override.isNull()) {
        gil.release();
        return this->::QWidget::tabletEvent(event);
    }

    Shiboken::AutoDecRef pyargs(Py_BuildValue("(N)",
        Shiboken::Converter< ::QTabletEvent * >::toPython(event)
    ));
    bool invalidadeArg1 = PyTuple_GET_ITEM(pyargs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(py_override, pyargs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidadeArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyargs, 0));
}

void QSteelWidgetWrapper::timerEvent(QTimerEvent * arg__1)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef py_override(Shiboken::BindingManager::instance().getOverride(this, "timerEvent"));
    if (py_override.isNull()) {
        gil.release();
        return this->::QObject::timerEvent(arg__1);
    }

    Shiboken::AutoDecRef pyargs(Py_BuildValue("(N)",
        Shiboken::Converter< ::QTimerEvent * >::toPython(arg__1)
    ));

    Shiboken::AutoDecRef pyResult(PyObject_Call(py_override, pyargs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
}

void QSteelWidgetWrapper::wheelEvent(QWheelEvent * e)
{
    Shiboken::GilState gil;
    if (PyErr_Occurred())
        return ;
    Shiboken::AutoDecRef py_override(Shiboken::BindingManager::instance().getOverride(this, "wheelEvent"));
    if (py_override.isNull()) {
        gil.release();
        return this->::QSteelWidget::wheelEvent(e);
    }

    Shiboken::AutoDecRef pyargs(Py_BuildValue("(N)",
        Shiboken::Converter< ::QWheelEvent * >::toPython(e)
    ));
    bool invalidadeArg1 = PyTuple_GET_ITEM(pyargs, 0)->ob_refcnt == 1;

    Shiboken::AutoDecRef pyResult(PyObject_Call(py_override, pyargs, NULL));
    // An error happened in python code!
    if (pyResult.isNull()) {
        PyErr_Print();
        return ;
    }
    if (invalidadeArg1)
        Shiboken::Object::invalidate(PyTuple_GET_ITEM(pyargs, 0));
}

QSteelWidgetWrapper::~QSteelWidgetWrapper()
{
    SbkObject* wrapper = Shiboken::BindingManager::instance().retrieveWrapper(this);
    Shiboken::Object::destroy(wrapper, this);
}

// Target ---------------------------------------------------------

extern "C" {
static int
Sbk_QSteelWidget_Init(PyObject* self, PyObject* args, PyObject* kwds)
{
    if (Shiboken::Object::isUserType(self) && !Shiboken::ObjectType::canCallConstructor(self->ob_type, Shiboken::SbkType<QSteelWidget >()))
        return -1;

    QSteelWidgetWrapper* cptr = 0;
    int overloadId = -1;
    SbkObject* sbkSelf = reinterpret_cast<SbkObject*>(self);
    SbkObjectType* type = reinterpret_cast<SbkObjectType*>(self->ob_type);
    SbkObjectType* myType = reinterpret_cast<SbkObjectType*>(SbkPyQSteelWidgetTypes[SBK_QSTEELWIDGET_IDX]);
    if (type != myType) {
        Shiboken::ObjectType::copyMultimpleheritance(type, myType);
    }



    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyargs[] = {0};

    // invalid argument lengths


    if (!PyArg_ParseTuple(args, "|O:QSteelWidget", &(pyargs[0])))
        return -1;

    // Overloaded function decisor
    // 0: QSteelWidget(QWidget*)
    if (numArgs == 0) {
        overloadId = 0; // QSteelWidget(QWidget*)
    } else if (Shiboken::Converter< ::QWidget * >::isConvertible(pyargs[0])) {
        overloadId = 0; // QSteelWidget(QWidget*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSteelWidget_Init_TypeError;

    // Call function/method
    {
        {
            if (kwds) {
                const char* errorArgName = 0;
                PyObject* value = PyDict_GetItemString(kwds, "parent");
                if (value) {
                    if (pyargs[0])
                        errorArgName = "parent";
                    else if (Shiboken::Converter< ::QWidget * >::isConvertible(value))
                        pyargs[0] = value;
                    else
                        goto Sbk_QSteelWidget_Init_TypeError;
                }
                if (errorArgName) {
                    PyErr_Format(PyExc_TypeError, "PyQSteelWidget.QSteelWidget(): got multiple values for keyword argument '%s'", errorArgName);
                    return -1;
                }
            }
            if (!Shiboken::Object::isValid(pyargs[0]))
                return -1;
            QWidget * cppArg0 = pyargs[0] ? Shiboken::Converter<QWidget * >::toCpp(pyargs[0]) : 0L;

            if(!PyErr_Occurred()) {
                // QSteelWidget(QWidget*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cptr = new QSteelWidgetWrapper(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
        }
    }

    if (PyErr_Occurred() || !Shiboken::Object::setCppPointer(sbkSelf, Shiboken::SbkType<QSteelWidget >(), cptr)) {
        delete cptr;
        return -1;
    }
    if (!cptr) goto Sbk_QSteelWidget_Init_TypeError;

    Shiboken::Object::setValidCpp(sbkSelf, true);
    Shiboken::Object::setHasCppWrapper(sbkSelf, true);
    Shiboken::BindingManager::instance().registerWrapper(sbkSelf, cptr);


    return 1;

    Sbk_QSteelWidget_Init_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWidget = 0L", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PyQSteelWidget.QSteelWidget", overloads);
        return -1;
}

static PyObject* Sbk_QSteelWidgetFunc_addInanimate(PyObject* self, PyObject* args)
{
    QSteelWidget* cppSelf = 0;
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = Shiboken::Converter< QSteelWidget* >::toCpp(self);

    PyObject* pyResult = 0;
    int overloadId = -1;
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyargs[] = {0, 0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "addInanimate", 3, 3, &(pyargs[0]), &(pyargs[1]), &(pyargs[2])))
        return 0;


    // Overloaded function decisor
    // 0: addInanimate(QString,QVector3D,QVector4D)
    if (numArgs == 3 && Shiboken::Converter< QString >::isConvertible(pyargs[0]) && Shiboken::Converter< ::QVector3D >::isConvertible(pyargs[1]) && Shiboken::Converter< ::QVector4D >::isConvertible(pyargs[2])) {
        overloadId = 0; // addInanimate(QString,QVector3D,QVector4D)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSteelWidgetFunc_addInanimate_TypeError;

    // Call function/method
    {
        {
            QString cppArg0 = Shiboken::Converter<QString >::toCpp(pyargs[0]);
            if (!Shiboken::Object::isValid(pyargs[1]))
                return 0;
            QVector3D cppArg1 = Shiboken::Converter<QVector3D >::toCpp(pyargs[1]);
            if (!Shiboken::Object::isValid(pyargs[2]))
                return 0;
            QVector4D cppArg2 = Shiboken::Converter<QVector4D >::toCpp(pyargs[2]);

            if(!PyErr_Occurred()) {
                // addInanimate(QString,QVector3D,QVector4D)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                unsigned long cppResult = cppSelf->addInanimate(cppArg0, cppArg1, cppArg2);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Converter< unsigned long >::toPython(cppResult);
            }
        }
    }


    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSteelWidgetFunc_addInanimate_TypeError:
        const char* overloads[] = {"QString, PySide.QtGui.QVector3D, PySide.QtGui.QVector4D", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PyQSteelWidget.QSteelWidget.addInanimate", overloads);
        return 0;
}

static PyObject* Sbk_QSteelWidgetFunc_closeEvent(PyObject* self, PyObject* arg)
{
    QSteelWidget* cppSelf = 0;
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = Shiboken::Converter< QSteelWidget* >::toCpp(self);

    int overloadId = -1;

    // Overloaded function decisor
    // 0: closeEvent(QCloseEvent*)
    if (Shiboken::Converter< ::QCloseEvent * >::isConvertible(arg)) {
        overloadId = 0; // closeEvent(QCloseEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSteelWidgetFunc_closeEvent_TypeError;

    // Call function/method
    {
        {
            if (!Shiboken::Object::isValid(arg))
                return 0;
            QCloseEvent * cppArg0 = Shiboken::Converter<QCloseEvent * >::toCpp(arg);

            if(!PyErr_Occurred()) {
                // closeEvent(QCloseEvent*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                (Shiboken::Object::isUserType(self) ? cppSelf->::QSteelWidget::closeEvent(cppArg0) : cppSelf->closeEvent(cppArg0));
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
        }
    }


    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSteelWidgetFunc_closeEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QCloseEvent", 0};
        Shiboken::setErrorAboutWrongArguments(arg, "PyQSteelWidget.QSteelWidget.closeEvent", overloads);
        return 0;
}

static PyObject* Sbk_QSteelWidgetFunc_dragEnterEvent(PyObject* self, PyObject* arg)
{
    QSteelWidget* cppSelf = 0;
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = Shiboken::Converter< QSteelWidget* >::toCpp(self);

    int overloadId = -1;

    // Overloaded function decisor
    // 0: dragEnterEvent(QDragEnterEvent*)
    if (Shiboken::Converter< ::QDragEnterEvent * >::isConvertible(arg)) {
        overloadId = 0; // dragEnterEvent(QDragEnterEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSteelWidgetFunc_dragEnterEvent_TypeError;

    // Call function/method
    {
        {
            if (!Shiboken::Object::isValid(arg))
                return 0;
            QDragEnterEvent * cppArg0 = Shiboken::Converter<QDragEnterEvent * >::toCpp(arg);

            if(!PyErr_Occurred()) {
                // dragEnterEvent(QDragEnterEvent*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                (Shiboken::Object::isUserType(self) ? cppSelf->::QSteelWidget::dragEnterEvent(cppArg0) : cppSelf->dragEnterEvent(cppArg0));
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
        }
    }


    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSteelWidgetFunc_dragEnterEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QDragEnterEvent", 0};
        Shiboken::setErrorAboutWrongArguments(arg, "PyQSteelWidget.QSteelWidget.dragEnterEvent", overloads);
        return 0;
}

static PyObject* Sbk_QSteelWidgetFunc_dragMoveEvent(PyObject* self, PyObject* arg)
{
    QSteelWidget* cppSelf = 0;
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = Shiboken::Converter< QSteelWidget* >::toCpp(self);

    int overloadId = -1;

    // Overloaded function decisor
    // 0: dragMoveEvent(QDragMoveEvent*)
    if (Shiboken::Converter< ::QDragMoveEvent * >::isConvertible(arg)) {
        overloadId = 0; // dragMoveEvent(QDragMoveEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSteelWidgetFunc_dragMoveEvent_TypeError;

    // Call function/method
    {
        {
            if (!Shiboken::Object::isValid(arg))
                return 0;
            QDragMoveEvent * cppArg0 = Shiboken::Converter<QDragMoveEvent * >::toCpp(arg);

            if(!PyErr_Occurred()) {
                // dragMoveEvent(QDragMoveEvent*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                (Shiboken::Object::isUserType(self) ? cppSelf->::QSteelWidget::dragMoveEvent(cppArg0) : cppSelf->dragMoveEvent(cppArg0));
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
        }
    }


    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSteelWidgetFunc_dragMoveEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QDragMoveEvent", 0};
        Shiboken::setErrorAboutWrongArguments(arg, "PyQSteelWidget.QSteelWidget.dragMoveEvent", overloads);
        return 0;
}

static PyObject* Sbk_QSteelWidgetFunc_dropEvent(PyObject* self, PyObject* arg)
{
    QSteelWidget* cppSelf = 0;
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = Shiboken::Converter< QSteelWidget* >::toCpp(self);

    int overloadId = -1;

    // Overloaded function decisor
    // 0: dropEvent(QDropEvent*)
    if (Shiboken::Converter< ::QDropEvent * >::isConvertible(arg)) {
        overloadId = 0; // dropEvent(QDropEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSteelWidgetFunc_dropEvent_TypeError;

    // Call function/method
    {
        {
            if (!Shiboken::Object::isValid(arg))
                return 0;
            QDropEvent * cppArg0 = Shiboken::Converter<QDropEvent * >::toCpp(arg);

            if(!PyErr_Occurred()) {
                // dropEvent(QDropEvent*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                (Shiboken::Object::isUserType(self) ? cppSelf->::QSteelWidget::dropEvent(cppArg0) : cppSelf->dropEvent(cppArg0));
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
        }
    }


    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSteelWidgetFunc_dropEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QDropEvent", 0};
        Shiboken::setErrorAboutWrongArguments(arg, "PyQSteelWidget.QSteelWidget.dropEvent", overloads);
        return 0;
}

static PyObject* Sbk_QSteelWidgetFunc_dropTargetPosition(PyObject* self, PyObject* arg)
{
    QSteelWidget* cppSelf = 0;
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = Shiboken::Converter< QSteelWidget* >::toCpp(self);

    PyObject* pyResult = 0;
    int overloadId = -1;

    // Overloaded function decisor
    // 0: dropTargetPosition(QVector3D)
    if (Shiboken::Converter< ::QVector3D >::isConvertible(arg)) {
        overloadId = 0; // dropTargetPosition(QVector3D)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSteelWidgetFunc_dropTargetPosition_TypeError;

    // Call function/method
    {
        {
            if (!Shiboken::Object::isValid(arg))
                return 0;
            QVector3D cppArg0 = Shiboken::Converter<QVector3D >::toCpp(arg);

            if(!PyErr_Occurred()) {
                // dropTargetPosition(QVector3D)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QVector3D cppResult = cppSelf->dropTargetPosition(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Converter< ::QVector3D >::toPython(cppResult);
            }
        }
    }


    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSteelWidgetFunc_dropTargetPosition_TypeError:
        const char* overloads[] = {"PySide.QtGui.QVector3D", 0};
        Shiboken::setErrorAboutWrongArguments(arg, "PyQSteelWidget.QSteelWidget.dropTargetPosition", overloads);
        return 0;
}

static PyObject* Sbk_QSteelWidgetFunc_dropTargetRotation(PyObject* self)
{
    QSteelWidget* cppSelf = 0;
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = Shiboken::Converter< QSteelWidget* >::toCpp(self);

    PyObject* pyResult = 0;

    // Call function/method
    {
        {

            if(!PyErr_Occurred()) {
                // dropTargetRotation()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QVector4D cppResult = cppSelf->dropTargetRotation();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Converter< ::QVector4D >::toPython(cppResult);
            }
        }
    }


    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSteelWidgetFunc_engineModeUpdate(PyObject* self)
{
    QSteelWidget* cppSelf = 0;
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = Shiboken::Converter< QSteelWidget* >::toCpp(self);


    // Call function/method
    {
        {

            if(!PyErr_Occurred()) {
                // engineModeUpdate()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->engineModeUpdate();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
        }
    }


    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QSteelWidgetFunc_grabInputs(PyObject* self)
{
    QSteelWidget* cppSelf = 0;
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = Shiboken::Converter< QSteelWidget* >::toCpp(self);


    // Call function/method
    {
        {

            if(!PyErr_Occurred()) {
                // grabInputs()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->grabInputs();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
        }
    }


    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QSteelWidgetFunc_inanimatePosition(PyObject* self, PyObject* arg)
{
    QSteelWidget* cppSelf = 0;
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = Shiboken::Converter< QSteelWidget* >::toCpp(self);

    PyObject* pyResult = 0;
    int overloadId = -1;

    // Overloaded function decisor
    // 0: inanimatePosition(ulong)
    if (SbkNumber_Check(arg)) {
        overloadId = 0; // inanimatePosition(ulong)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSteelWidgetFunc_inanimatePosition_TypeError;

    // Call function/method
    {
        {
            unsigned long cppArg0 = Shiboken::Converter<unsigned long >::toCpp(arg);

            if(!PyErr_Occurred()) {
                // inanimatePosition(ulong)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QVector3D cppResult = cppSelf->inanimatePosition(cppArg0);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Converter< ::QVector3D >::toPython(cppResult);
            }
        }
    }


    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;

    Sbk_QSteelWidgetFunc_inanimatePosition_TypeError:
        const char* overloads[] = {"unsigned long", 0};
        Shiboken::setErrorAboutWrongArguments(arg, "PyQSteelWidget.QSteelWidget.inanimatePosition", overloads);
        return 0;
}

static PyObject* Sbk_QSteelWidgetFunc_initSteel(PyObject* self)
{
    QSteelWidget* cppSelf = 0;
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = Shiboken::Converter< QSteelWidget* >::toCpp(self);


    // Call function/method
    {
        {

            if(!PyErr_Occurred()) {
                // initSteel()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->initSteel();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
        }
    }


    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QSteelWidgetFunc_isSteelReady(PyObject* self)
{
    QSteelWidget* cppSelf = 0;
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = Shiboken::Converter< QSteelWidget* >::toCpp(self);

    PyObject* pyResult = 0;

    // Call function/method
    {
        {

            if(!PyErr_Occurred()) {
                // isSteelReady()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                bool cppResult = cppSelf->isSteelReady();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Converter< bool >::toPython(cppResult);
            }
        }
    }


    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSteelWidgetFunc_keyPressEvent(PyObject* self, PyObject* arg)
{
    QSteelWidget* cppSelf = 0;
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = Shiboken::Converter< QSteelWidget* >::toCpp(self);

    int overloadId = -1;

    // Overloaded function decisor
    // 0: keyPressEvent(QKeyEvent*)
    if (Shiboken::Converter< ::QKeyEvent * >::isConvertible(arg)) {
        overloadId = 0; // keyPressEvent(QKeyEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSteelWidgetFunc_keyPressEvent_TypeError;

    // Call function/method
    {
        {
            if (!Shiboken::Object::isValid(arg))
                return 0;
            QKeyEvent * cppArg0 = Shiboken::Converter<QKeyEvent * >::toCpp(arg);

            if(!PyErr_Occurred()) {
                // keyPressEvent(QKeyEvent*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                (Shiboken::Object::isUserType(self) ? cppSelf->::QSteelWidget::keyPressEvent(cppArg0) : cppSelf->keyPressEvent(cppArg0));
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
        }
    }


    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSteelWidgetFunc_keyPressEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QKeyEvent", 0};
        Shiboken::setErrorAboutWrongArguments(arg, "PyQSteelWidget.QSteelWidget.keyPressEvent", overloads);
        return 0;
}

static PyObject* Sbk_QSteelWidgetFunc_keyReleaseEvent(PyObject* self, PyObject* arg)
{
    QSteelWidget* cppSelf = 0;
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = Shiboken::Converter< QSteelWidget* >::toCpp(self);

    int overloadId = -1;

    // Overloaded function decisor
    // 0: keyReleaseEvent(QKeyEvent*)
    if (Shiboken::Converter< ::QKeyEvent * >::isConvertible(arg)) {
        overloadId = 0; // keyReleaseEvent(QKeyEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSteelWidgetFunc_keyReleaseEvent_TypeError;

    // Call function/method
    {
        {
            if (!Shiboken::Object::isValid(arg))
                return 0;
            QKeyEvent * cppArg0 = Shiboken::Converter<QKeyEvent * >::toCpp(arg);

            if(!PyErr_Occurred()) {
                // keyReleaseEvent(QKeyEvent*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                (Shiboken::Object::isUserType(self) ? cppSelf->::QSteelWidget::keyReleaseEvent(cppArg0) : cppSelf->keyReleaseEvent(cppArg0));
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
        }
    }


    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSteelWidgetFunc_keyReleaseEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QKeyEvent", 0};
        Shiboken::setErrorAboutWrongArguments(arg, "PyQSteelWidget.QSteelWidget.keyReleaseEvent", overloads);
        return 0;
}

static PyObject* Sbk_QSteelWidgetFunc_mouseDoubleClickEvent(PyObject* self, PyObject* arg)
{
    QSteelWidget* cppSelf = 0;
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = Shiboken::Converter< QSteelWidget* >::toCpp(self);

    int overloadId = -1;

    // Overloaded function decisor
    // 0: mouseDoubleClickEvent(QMouseEvent*)
    if (Shiboken::Converter< ::QMouseEvent * >::isConvertible(arg)) {
        overloadId = 0; // mouseDoubleClickEvent(QMouseEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSteelWidgetFunc_mouseDoubleClickEvent_TypeError;

    // Call function/method
    {
        {
            if (!Shiboken::Object::isValid(arg))
                return 0;
            QMouseEvent * cppArg0 = Shiboken::Converter<QMouseEvent * >::toCpp(arg);

            if(!PyErr_Occurred()) {
                // mouseDoubleClickEvent(QMouseEvent*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                (Shiboken::Object::isUserType(self) ? cppSelf->::QSteelWidget::mouseDoubleClickEvent(cppArg0) : cppSelf->mouseDoubleClickEvent(cppArg0));
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
        }
    }


    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSteelWidgetFunc_mouseDoubleClickEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QMouseEvent", 0};
        Shiboken::setErrorAboutWrongArguments(arg, "PyQSteelWidget.QSteelWidget.mouseDoubleClickEvent", overloads);
        return 0;
}

static PyObject* Sbk_QSteelWidgetFunc_mouseMoveEvent(PyObject* self, PyObject* arg)
{
    QSteelWidget* cppSelf = 0;
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = Shiboken::Converter< QSteelWidget* >::toCpp(self);

    int overloadId = -1;

    // Overloaded function decisor
    // 0: mouseMoveEvent(QMouseEvent*)
    if (Shiboken::Converter< ::QMouseEvent * >::isConvertible(arg)) {
        overloadId = 0; // mouseMoveEvent(QMouseEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSteelWidgetFunc_mouseMoveEvent_TypeError;

    // Call function/method
    {
        {
            if (!Shiboken::Object::isValid(arg))
                return 0;
            QMouseEvent * cppArg0 = Shiboken::Converter<QMouseEvent * >::toCpp(arg);

            if(!PyErr_Occurred()) {
                // mouseMoveEvent(QMouseEvent*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                (Shiboken::Object::isUserType(self) ? cppSelf->::QSteelWidget::mouseMoveEvent(cppArg0) : cppSelf->mouseMoveEvent(cppArg0));
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
        }
    }


    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSteelWidgetFunc_mouseMoveEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QMouseEvent", 0};
        Shiboken::setErrorAboutWrongArguments(arg, "PyQSteelWidget.QSteelWidget.mouseMoveEvent", overloads);
        return 0;
}

static PyObject* Sbk_QSteelWidgetFunc_mousePressEvent(PyObject* self, PyObject* arg)
{
    QSteelWidget* cppSelf = 0;
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = Shiboken::Converter< QSteelWidget* >::toCpp(self);

    int overloadId = -1;

    // Overloaded function decisor
    // 0: mousePressEvent(QMouseEvent*)
    if (Shiboken::Converter< ::QMouseEvent * >::isConvertible(arg)) {
        overloadId = 0; // mousePressEvent(QMouseEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSteelWidgetFunc_mousePressEvent_TypeError;

    // Call function/method
    {
        {
            if (!Shiboken::Object::isValid(arg))
                return 0;
            QMouseEvent * cppArg0 = Shiboken::Converter<QMouseEvent * >::toCpp(arg);

            if(!PyErr_Occurred()) {
                // mousePressEvent(QMouseEvent*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                (Shiboken::Object::isUserType(self) ? cppSelf->::QSteelWidget::mousePressEvent(cppArg0) : cppSelf->mousePressEvent(cppArg0));
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
        }
    }


    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSteelWidgetFunc_mousePressEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QMouseEvent", 0};
        Shiboken::setErrorAboutWrongArguments(arg, "PyQSteelWidget.QSteelWidget.mousePressEvent", overloads);
        return 0;
}

static PyObject* Sbk_QSteelWidgetFunc_mouseReleaseEvent(PyObject* self, PyObject* arg)
{
    QSteelWidget* cppSelf = 0;
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = Shiboken::Converter< QSteelWidget* >::toCpp(self);

    int overloadId = -1;

    // Overloaded function decisor
    // 0: mouseReleaseEvent(QMouseEvent*)
    if (Shiboken::Converter< ::QMouseEvent * >::isConvertible(arg)) {
        overloadId = 0; // mouseReleaseEvent(QMouseEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSteelWidgetFunc_mouseReleaseEvent_TypeError;

    // Call function/method
    {
        {
            if (!Shiboken::Object::isValid(arg))
                return 0;
            QMouseEvent * cppArg0 = Shiboken::Converter<QMouseEvent * >::toCpp(arg);

            if(!PyErr_Occurred()) {
                // mouseReleaseEvent(QMouseEvent*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                (Shiboken::Object::isUserType(self) ? cppSelf->::QSteelWidget::mouseReleaseEvent(cppArg0) : cppSelf->mouseReleaseEvent(cppArg0));
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
        }
    }


    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSteelWidgetFunc_mouseReleaseEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QMouseEvent", 0};
        Shiboken::setErrorAboutWrongArguments(arg, "PyQSteelWidget.QSteelWidget.mouseReleaseEvent", overloads);
        return 0;
}

static PyObject* Sbk_QSteelWidgetFunc_moveEvent(PyObject* self, PyObject* arg)
{
    QSteelWidget* cppSelf = 0;
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = Shiboken::Converter< QSteelWidget* >::toCpp(self);

    int overloadId = -1;

    // Overloaded function decisor
    // 0: moveEvent(QMoveEvent*)
    if (Shiboken::Converter< ::QMoveEvent * >::isConvertible(arg)) {
        overloadId = 0; // moveEvent(QMoveEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSteelWidgetFunc_moveEvent_TypeError;

    // Call function/method
    {
        {
            if (!Shiboken::Object::isValid(arg))
                return 0;
            QMoveEvent * cppArg0 = Shiboken::Converter<QMoveEvent * >::toCpp(arg);

            if(!PyErr_Occurred()) {
                // moveEvent(QMoveEvent*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                (Shiboken::Object::isUserType(self) ? cppSelf->::QSteelWidget::moveEvent(cppArg0) : cppSelf->moveEvent(cppArg0));
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
        }
    }


    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSteelWidgetFunc_moveEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QMoveEvent", 0};
        Shiboken::setErrorAboutWrongArguments(arg, "PyQSteelWidget.QSteelWidget.moveEvent", overloads);
        return 0;
}

static PyObject* Sbk_QSteelWidgetFunc_paintEngine(PyObject* self)
{
    QSteelWidget* cppSelf = 0;
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = Shiboken::Converter< QSteelWidget* >::toCpp(self);

    PyObject* pyResult = 0;

    // Call function/method
    {
        {

            if(!PyErr_Occurred()) {
                // paintEngine()const
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                QPaintEngine * cppResult = (Shiboken::Object::isUserType(self) ? const_cast<const QSteelWidget*>(cppSelf)->::QSteelWidget::paintEngine() : const_cast<const QSteelWidget*>(cppSelf)->paintEngine());
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                pyResult = Shiboken::Converter< ::QPaintEngine * >::toPython(cppResult);
            }
        }
    }


    if (PyErr_Occurred() || !pyResult) {
        Py_XDECREF(pyResult);
        return 0;
    }
    return pyResult;
}

static PyObject* Sbk_QSteelWidgetFunc_paintEvent(PyObject* self, PyObject* arg)
{
    QSteelWidget* cppSelf = 0;
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = Shiboken::Converter< QSteelWidget* >::toCpp(self);

    int overloadId = -1;

    // Overloaded function decisor
    // 0: paintEvent(QPaintEvent*)
    if (Shiboken::Converter< ::QPaintEvent * >::isConvertible(arg)) {
        overloadId = 0; // paintEvent(QPaintEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSteelWidgetFunc_paintEvent_TypeError;

    // Call function/method
    {
        {
            if (!Shiboken::Object::isValid(arg))
                return 0;
            QPaintEvent * cppArg0 = Shiboken::Converter<QPaintEvent * >::toCpp(arg);

            if(!PyErr_Occurred()) {
                // paintEvent(QPaintEvent*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                (Shiboken::Object::isUserType(self) ? cppSelf->::QSteelWidget::paintEvent(cppArg0) : cppSelf->paintEvent(cppArg0));
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
        }
    }


    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSteelWidgetFunc_paintEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QPaintEvent", 0};
        Shiboken::setErrorAboutWrongArguments(arg, "PyQSteelWidget.QSteelWidget.paintEvent", overloads);
        return 0;
}

static PyObject* Sbk_QSteelWidgetFunc_quickLog(PyObject* self, PyObject* arg)
{
    QSteelWidget* cppSelf = 0;
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = Shiboken::Converter< QSteelWidget* >::toCpp(self);

    int overloadId = -1;

    // Overloaded function decisor
    // 0: quickLog(QString)
    // 1: quickLog(const char*)
    if (Shiboken::Converter< const char * >::isConvertible(arg)) {
        overloadId = 1; // quickLog(const char*)
    } else if (Shiboken::Converter< QString >::isConvertible(arg)) {
        overloadId = 0; // quickLog(QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSteelWidgetFunc_quickLog_TypeError;

    // Call function/method
    {
        switch (overloadId) {
            case 0: // quickLog(QString)
            {
                QString cppArg0 = Shiboken::Converter<QString >::toCpp(arg);

                if(!PyErr_Occurred()) {
                    // quickLog(QString)
                    PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                    cppSelf->quickLog(cppArg0);
                    PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                }
                break;
            }
            case 1: // quickLog(const char*)
            {
                const char * cppArg0 = Shiboken::Converter<const char * >::toCpp(arg);

                if(!PyErr_Occurred()) {
                    // quickLog(const char*)
                    PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                    cppSelf->quickLog(cppArg0);
                    PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
                }
                break;
            }
        }
    }


    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSteelWidgetFunc_quickLog_TypeError:
        const char* overloads[] = {"QString", "str", 0};
        Shiboken::setErrorAboutWrongArguments(arg, "PyQSteelWidget.QSteelWidget.quickLog", overloads);
        return 0;
}

static PyObject* Sbk_QSteelWidgetFunc_releaseInputs(PyObject* self)
{
    QSteelWidget* cppSelf = 0;
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = Shiboken::Converter< QSteelWidget* >::toCpp(self);


    // Call function/method
    {
        {

            if(!PyErr_Occurred()) {
                // releaseInputs()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->releaseInputs();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
        }
    }


    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QSteelWidgetFunc_resizeEvent(PyObject* self, PyObject* arg)
{
    QSteelWidget* cppSelf = 0;
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = Shiboken::Converter< QSteelWidget* >::toCpp(self);

    int overloadId = -1;

    // Overloaded function decisor
    // 0: resizeEvent(QResizeEvent*)
    if (Shiboken::Converter< ::QResizeEvent * >::isConvertible(arg)) {
        overloadId = 0; // resizeEvent(QResizeEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSteelWidgetFunc_resizeEvent_TypeError;

    // Call function/method
    {
        {
            if (!Shiboken::Object::isValid(arg))
                return 0;
            QResizeEvent * cppArg0 = Shiboken::Converter<QResizeEvent * >::toCpp(arg);

            if(!PyErr_Occurred()) {
                // resizeEvent(QResizeEvent*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                (Shiboken::Object::isUserType(self) ? cppSelf->::QSteelWidget::resizeEvent(cppArg0) : cppSelf->resizeEvent(cppArg0));
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
        }
    }


    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSteelWidgetFunc_resizeEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QResizeEvent", 0};
        Shiboken::setErrorAboutWrongArguments(arg, "PyQSteelWidget.QSteelWidget.resizeEvent", overloads);
        return 0;
}

static PyObject* Sbk_QSteelWidgetFunc_setLevel(PyObject* self, PyObject* args)
{
    QSteelWidget* cppSelf = 0;
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = Shiboken::Converter< QSteelWidget* >::toCpp(self);

    int overloadId = -1;
    int numArgs = PyTuple_GET_SIZE(args);
    PyObject* pyargs[] = {0, 0};

    // invalid argument lengths


    if (!PyArg_UnpackTuple(args, "setLevel", 2, 2, &(pyargs[0]), &(pyargs[1])))
        return 0;


    // Overloaded function decisor
    // 0: setLevel(QString,QString)
    if (numArgs == 2 && Shiboken::Converter< QString >::isConvertible(pyargs[0]) && Shiboken::Converter< QString >::isConvertible(pyargs[1])) {
        overloadId = 0; // setLevel(QString,QString)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSteelWidgetFunc_setLevel_TypeError;

    // Call function/method
    {
        {
            QString cppArg0 = Shiboken::Converter<QString >::toCpp(pyargs[0]);
            QString cppArg1 = Shiboken::Converter<QString >::toCpp(pyargs[1]);

            if(!PyErr_Occurred()) {
                // setLevel(QString,QString)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->setLevel(cppArg0, cppArg1);
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
        }
    }


    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSteelWidgetFunc_setLevel_TypeError:
        const char* overloads[] = {"QString, QString", 0};
        Shiboken::setErrorAboutWrongArguments(args, "PyQSteelWidget.QSteelWidget.setLevel", overloads);
        return 0;
}

static PyObject* Sbk_QSteelWidgetFunc_showEvent(PyObject* self, PyObject* arg)
{
    QSteelWidget* cppSelf = 0;
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = Shiboken::Converter< QSteelWidget* >::toCpp(self);

    int overloadId = -1;

    // Overloaded function decisor
    // 0: showEvent(QShowEvent*)
    if (Shiboken::Converter< ::QShowEvent * >::isConvertible(arg)) {
        overloadId = 0; // showEvent(QShowEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSteelWidgetFunc_showEvent_TypeError;

    // Call function/method
    {
        {
            if (!Shiboken::Object::isValid(arg))
                return 0;
            QShowEvent * cppArg0 = Shiboken::Converter<QShowEvent * >::toCpp(arg);

            if(!PyErr_Occurred()) {
                // showEvent(QShowEvent*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                (Shiboken::Object::isUserType(self) ? cppSelf->::QSteelWidget::showEvent(cppArg0) : cppSelf->showEvent(cppArg0));
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
        }
    }


    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSteelWidgetFunc_showEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QShowEvent", 0};
        Shiboken::setErrorAboutWrongArguments(arg, "PyQSteelWidget.QSteelWidget.showEvent", overloads);
        return 0;
}

static PyObject* Sbk_QSteelWidgetFunc_startEngineMode(PyObject* self)
{
    QSteelWidget* cppSelf = 0;
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = Shiboken::Converter< QSteelWidget* >::toCpp(self);


    // Call function/method
    {
        {

            if(!PyErr_Occurred()) {
                // startEngineMode()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->startEngineMode();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
        }
    }


    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QSteelWidgetFunc_stopEngineMode(PyObject* self)
{
    QSteelWidget* cppSelf = 0;
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = Shiboken::Converter< QSteelWidget* >::toCpp(self);


    // Call function/method
    {
        {

            if(!PyErr_Occurred()) {
                // stopEngineMode()
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                cppSelf->stopEngineMode();
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
        }
    }


    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;
}

static PyObject* Sbk_QSteelWidgetFunc_wheelEvent(PyObject* self, PyObject* arg)
{
    QSteelWidget* cppSelf = 0;
    if (!Shiboken::Object::isValid(self))
        return 0;
    cppSelf = Shiboken::Converter< QSteelWidget* >::toCpp(self);

    int overloadId = -1;

    // Overloaded function decisor
    // 0: wheelEvent(QWheelEvent*)
    if (Shiboken::Converter< ::QWheelEvent * >::isConvertible(arg)) {
        overloadId = 0; // wheelEvent(QWheelEvent*)
    }

    // Function signature not found.
    if (overloadId == -1) goto Sbk_QSteelWidgetFunc_wheelEvent_TypeError;

    // Call function/method
    {
        {
            if (!Shiboken::Object::isValid(arg))
                return 0;
            QWheelEvent * cppArg0 = Shiboken::Converter<QWheelEvent * >::toCpp(arg);

            if(!PyErr_Occurred()) {
                // wheelEvent(QWheelEvent*)
                PyThreadState* _save = PyEval_SaveThread(); // Py_BEGIN_ALLOW_THREADS
                (Shiboken::Object::isUserType(self) ? cppSelf->::QSteelWidget::wheelEvent(cppArg0) : cppSelf->wheelEvent(cppArg0));
                PyEval_RestoreThread(_save); // Py_END_ALLOW_THREADS
            }
        }
    }


    if (PyErr_Occurred()) {
        return 0;
    }
    Py_RETURN_NONE;

    Sbk_QSteelWidgetFunc_wheelEvent_TypeError:
        const char* overloads[] = {"PySide.QtGui.QWheelEvent", 0};
        Shiboken::setErrorAboutWrongArguments(arg, "PyQSteelWidget.QSteelWidget.wheelEvent", overloads);
        return 0;
}

static PyMethodDef Sbk_QSteelWidget_methods[] = {
    {"addInanimate", (PyCFunction)Sbk_QSteelWidgetFunc_addInanimate, METH_VARARGS},
    {"closeEvent", (PyCFunction)Sbk_QSteelWidgetFunc_closeEvent, METH_O},
    {"dragEnterEvent", (PyCFunction)Sbk_QSteelWidgetFunc_dragEnterEvent, METH_O},
    {"dragMoveEvent", (PyCFunction)Sbk_QSteelWidgetFunc_dragMoveEvent, METH_O},
    {"dropEvent", (PyCFunction)Sbk_QSteelWidgetFunc_dropEvent, METH_O},
    {"dropTargetPosition", (PyCFunction)Sbk_QSteelWidgetFunc_dropTargetPosition, METH_O},
    {"dropTargetRotation", (PyCFunction)Sbk_QSteelWidgetFunc_dropTargetRotation, METH_NOARGS},
    {"engineModeUpdate", (PyCFunction)Sbk_QSteelWidgetFunc_engineModeUpdate, METH_NOARGS},
    {"grabInputs", (PyCFunction)Sbk_QSteelWidgetFunc_grabInputs, METH_NOARGS},
    {"inanimatePosition", (PyCFunction)Sbk_QSteelWidgetFunc_inanimatePosition, METH_O},
    {"initSteel", (PyCFunction)Sbk_QSteelWidgetFunc_initSteel, METH_NOARGS},
    {"isSteelReady", (PyCFunction)Sbk_QSteelWidgetFunc_isSteelReady, METH_NOARGS},
    {"keyPressEvent", (PyCFunction)Sbk_QSteelWidgetFunc_keyPressEvent, METH_O},
    {"keyReleaseEvent", (PyCFunction)Sbk_QSteelWidgetFunc_keyReleaseEvent, METH_O},
    {"mouseDoubleClickEvent", (PyCFunction)Sbk_QSteelWidgetFunc_mouseDoubleClickEvent, METH_O},
    {"mouseMoveEvent", (PyCFunction)Sbk_QSteelWidgetFunc_mouseMoveEvent, METH_O},
    {"mousePressEvent", (PyCFunction)Sbk_QSteelWidgetFunc_mousePressEvent, METH_O},
    {"mouseReleaseEvent", (PyCFunction)Sbk_QSteelWidgetFunc_mouseReleaseEvent, METH_O},
    {"moveEvent", (PyCFunction)Sbk_QSteelWidgetFunc_moveEvent, METH_O},
    {"paintEngine", (PyCFunction)Sbk_QSteelWidgetFunc_paintEngine, METH_NOARGS},
    {"paintEvent", (PyCFunction)Sbk_QSteelWidgetFunc_paintEvent, METH_O},
    {"quickLog", (PyCFunction)Sbk_QSteelWidgetFunc_quickLog, METH_O},
    {"releaseInputs", (PyCFunction)Sbk_QSteelWidgetFunc_releaseInputs, METH_NOARGS},
    {"resizeEvent", (PyCFunction)Sbk_QSteelWidgetFunc_resizeEvent, METH_O},
    {"setLevel", (PyCFunction)Sbk_QSteelWidgetFunc_setLevel, METH_VARARGS},
    {"showEvent", (PyCFunction)Sbk_QSteelWidgetFunc_showEvent, METH_O},
    {"startEngineMode", (PyCFunction)Sbk_QSteelWidgetFunc_startEngineMode, METH_NOARGS},
    {"stopEngineMode", (PyCFunction)Sbk_QSteelWidgetFunc_stopEngineMode, METH_NOARGS},
    {"wheelEvent", (PyCFunction)Sbk_QSteelWidgetFunc_wheelEvent, METH_O},

    {0} // Sentinel
};

static PyObject* Sbk_QSteelWidget_get_mIsSteelReady(PyObject* self, void*)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    PyObject* val = Shiboken::Converter< bool >::toPython( Shiboken::Converter< QSteelWidget* >::toCpp(self)->mIsSteelReady);
    return val;
}

static int Sbk_QSteelWidget_set_mIsSteelReady(PyObject* self, PyObject* value, void*)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    if (value == 0) {
        PyErr_SetString(PyExc_TypeError, "'mIsSteelReady' may not be deleted");
        return -1;
    }
    if (!SbkNumber_Check(value)) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'mIsSteelReady', 'bool' or convertible type expected");
        return -1;
    }

    Shiboken::Converter< QSteelWidget* >::toCpp(self)->mIsSteelReady = Shiboken::Converter< bool >::toCpp(value);

    return 0;
}

static PyObject* Sbk_QSteelWidget_get_mLastMousePosition(PyObject* self, void*)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    PyObject* val = Shiboken::createWrapper(&Shiboken::Converter< QSteelWidget* >::toCpp(self)->mLastMousePosition);
    Shiboken::Object::releaseOwnership(val);
    Shiboken::Object::setParent(self, val);
    return val;
}

static int Sbk_QSteelWidget_set_mLastMousePosition(PyObject* self, PyObject* value, void*)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    if (value == 0) {
        PyErr_SetString(PyExc_TypeError, "'mLastMousePosition' may not be deleted");
        return -1;
    }
    if (!Shiboken::Converter< ::QPoint >::isConvertible(value)) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'mLastMousePosition', 'QPoint' or convertible type expected");
        return -1;
    }

    Shiboken::Converter< QSteelWidget* >::toCpp(self)->mLastMousePosition = Shiboken::Converter< ::QPoint >::toCpp(value);

    return 0;
}

static PyObject* Sbk_QSteelWidget_get_mTimer(PyObject* self, void*)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    PyObject* val = Shiboken::Converter< ::QTimer * >::toPython( Shiboken::Converter< QSteelWidget* >::toCpp(self)->mTimer);
    return val;
}

static int Sbk_QSteelWidget_set_mTimer(PyObject* self, PyObject* value, void*)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    if (value == 0) {
        PyErr_SetString(PyExc_TypeError, "'mTimer' may not be deleted");
        return -1;
    }
    if (!Shiboken::Converter< ::QTimer * >::isConvertible(value)) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'mTimer', 'QTimer' or convertible type expected");
        return -1;
    }

    Shiboken::Converter< QSteelWidget* >::toCpp(self)->mTimer = Shiboken::Converter< ::QTimer * >::toCpp(value);

    Shiboken::Object::keepReference(reinterpret_cast<SbkObject*>(self), "mTimer", value);

    return 0;
}

static PyObject* Sbk_QSteelWidget_get_mIsInputGrabbed(PyObject* self, void*)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    PyObject* val = Shiboken::Converter< bool >::toPython( Shiboken::Converter< QSteelWidget* >::toCpp(self)->mIsInputGrabbed);
    return val;
}

static int Sbk_QSteelWidget_set_mIsInputGrabbed(PyObject* self, PyObject* value, void*)
{
    if (!Shiboken::Object::isValid(self))
        return 0;
    if (value == 0) {
        PyErr_SetString(PyExc_TypeError, "'mIsInputGrabbed' may not be deleted");
        return -1;
    }
    if (!SbkNumber_Check(value)) {
        PyErr_SetString(PyExc_TypeError, "wrong type attributed to 'mIsInputGrabbed', 'bool' or convertible type expected");
        return -1;
    }

    Shiboken::Converter< QSteelWidget* >::toCpp(self)->mIsInputGrabbed = Shiboken::Converter< bool >::toCpp(value);

    return 0;
}

// Getters and Setters for QSteelWidget
static PyGetSetDef Sbk_QSteelWidget_getsetlist[] = {
    {const_cast<char*>("mIsSteelReady"), Sbk_QSteelWidget_get_mIsSteelReady, Sbk_QSteelWidget_set_mIsSteelReady},
    {const_cast<char*>("mLastMousePosition"), Sbk_QSteelWidget_get_mLastMousePosition, Sbk_QSteelWidget_set_mLastMousePosition},
    {const_cast<char*>("mTimer"), Sbk_QSteelWidget_get_mTimer, Sbk_QSteelWidget_set_mTimer},
    {const_cast<char*>("mIsInputGrabbed"), Sbk_QSteelWidget_get_mIsInputGrabbed, Sbk_QSteelWidget_set_mIsInputGrabbed},
    {0}  // Sentinel
};

} // extern "C"

static int mi_offsets[] = { -1, -1, -1, -1, -1, -1, -1 };
int*
Sbk_QSteelWidget_mi_init(const void* cptr)
{
    if (mi_offsets[0] == -1) {
        std::set<int> offsets;
        std::set<int>::iterator it;
        const QSteelWidget* class_ptr = reinterpret_cast<const QSteelWidget*>(cptr);
        size_t base = (size_t) class_ptr;
        offsets.insert(((size_t) static_cast<const QWidget*>(class_ptr)) - base);
        offsets.insert(((size_t) static_cast<const QWidget*>((QSteelWidget*)((void*)class_ptr))) - base);
        offsets.insert(((size_t) static_cast<const QObject*>(class_ptr)) - base);
        offsets.insert(((size_t) static_cast<const QObject*>((QWidget*)((void*)class_ptr))) - base);
        offsets.insert(((size_t) static_cast<const QPaintDevice*>(class_ptr)) - base);
        offsets.insert(((size_t) static_cast<const QPaintDevice*>((QWidget*)((void*)class_ptr))) - base);

        offsets.erase(0);

        int i = 0;
        for (it = offsets.begin(); it != offsets.end(); it++) {
            mi_offsets[i] = *it;
            i++;
        }
    }
    return mi_offsets;
}
static void* Sbk_QSteelWidgetSpecialCastFunction(void* obj, SbkObjectType* desiredType)
{
    QSteelWidget* me = reinterpret_cast<QSteelWidget*>(obj);
    if (desiredType == reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX]))
        return static_cast<QWidget*>(me);
    else if (desiredType == reinterpret_cast<SbkObjectType*>(SbkPySide_QtCoreTypes[SBK_QOBJECT_IDX]))
        return static_cast<QObject*>(me);
    else if (desiredType == reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QPAINTDEVICE_IDX]))
        return static_cast<QPaintDevice*>(me);
    return me;
}


// Class Definition -----------------------------------------------
extern "C" {
static SbkObjectType Sbk_QSteelWidget_Type = { { {
    PyObject_HEAD_INIT(&SbkObjectType_Type)
    /*ob_size*/             0,
    /*tp_name*/             "PyQSteelWidget.QSteelWidget",
    /*tp_basicsize*/        sizeof(SbkObject),
    /*tp_itemsize*/         0,
    /*tp_dealloc*/          &SbkDeallocWrapper,
    /*tp_print*/            0,
    /*tp_getattr*/          0,
    /*tp_setattr*/          0,
    /*tp_compare*/          0,
    /*tp_repr*/             0,
    /*tp_as_number*/        0,
    /*tp_as_sequence*/      0,
    /*tp_as_mapping*/       0,
    /*tp_hash*/             0,
    /*tp_call*/             0,
    /*tp_str*/              0,
    /*tp_getattro*/         0,
    /*tp_setattro*/         0,
    /*tp_as_buffer*/        0,
    /*tp_flags*/            Py_TPFLAGS_DEFAULT|Py_TPFLAGS_BASETYPE|Py_TPFLAGS_CHECKTYPES,
    /*tp_doc*/              0,
    /*tp_traverse*/         0,
    /*tp_clear*/            0,
    /*tp_richcompare*/      0,
    /*tp_weaklistoffset*/   0,
    /*tp_iter*/             0,
    /*tp_iternext*/         0,
    /*tp_methods*/          Sbk_QSteelWidget_methods,
    /*tp_members*/          0,
    /*tp_getset*/           Sbk_QSteelWidget_getsetlist,
    /*tp_base*/             0,
    /*tp_dict*/             0,
    /*tp_descr_get*/        0,
    /*tp_descr_set*/        0,
    /*tp_dictoffset*/       0,
    /*tp_init*/             Sbk_QSteelWidget_Init,
    /*tp_alloc*/            0,
    /*tp_new*/              SbkObjectTpNew,
    /*tp_free*/             0,
    /*tp_is_gc*/            0,
    /*tp_bases*/            0,
    /*tp_mro*/              0,
    /*tp_cache*/            0,
    /*tp_subclasses*/       0,
    /*tp_weaklist*/         0
}, },
    /*priv_data*/           0
};
} //extern

static SbkObjectType* Sbk_QSteelWidget_typeDiscovery(void* cptr, SbkObjectType* instanceType)
{
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType<QObject >()) && dynamic_cast<QSteelWidget*>(reinterpret_cast<QObject*>(cptr)))
        return &Sbk_QSteelWidget_Type;
    if (instanceType == reinterpret_cast<SbkObjectType*>(Shiboken::SbkType<QPaintDevice >()) && dynamic_cast<QSteelWidget*>(reinterpret_cast<QPaintDevice*>(cptr)))
        return &Sbk_QSteelWidget_Type;
    return 0;
}


void init_QSteelWidget(PyObject* module)
{
    SbkPyQSteelWidgetTypes[SBK_QSTEELWIDGET_IDX] = reinterpret_cast<PyTypeObject*>(&Sbk_QSteelWidget_Type);

    Shiboken::ObjectType::initPrivateData(&Sbk_QSteelWidget_Type);
    Sbk_QSteelWidget_Type.super.ht_type.tp_base = SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX];
    Sbk_QSteelWidget_Type.super.ht_type.tp_bases = PyTuple_Pack(1,
        (PyTypeObject*)SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX]);

    MultipleInheritanceInitFunction func;
    func = Sbk_QSteelWidget_mi_init;
    Shiboken::ObjectType::setMultipleIheritanceFunction(&Sbk_QSteelWidget_Type, func);
    Shiboken::ObjectType::setCastFunction(&Sbk_QSteelWidget_Type, &Sbk_QSteelWidgetSpecialCastFunction);
    Shiboken::ObjectType::setDestructorFunction(&Sbk_QSteelWidget_Type, &Shiboken::callCppDestructor<QSteelWidget >);
    Py_INCREF((PyObject*)&Sbk_QSteelWidget_Type); //Incref due the 'PyModule_AddObject' steals the reference.
    if (PyType_Ready((PyTypeObject*)&Sbk_QSteelWidget_Type) < 0)
        return;

    // Fill type discovery information
    Shiboken::ObjectType::setTypeDiscoveryFunction(&Sbk_QSteelWidget_Type, &Sbk_QSteelWidget_typeDiscovery);
    Shiboken::BindingManager& bm = Shiboken::BindingManager::instance();
    bm.addClassInheritance(reinterpret_cast<SbkObjectType*>(SbkPySide_QtGuiTypes[SBK_QWIDGET_IDX]), &Sbk_QSteelWidget_Type);

    Shiboken::ObjectType::setOriginalName(&Sbk_QSteelWidget_Type, "QSteelWidget*");
    PyModule_AddObject(module, "QSteelWidget",
        ((PyObject*)&Sbk_QSteelWidget_Type));

    // Initialize signals
    PySideSignal* signal_item;

    signal_item = PySide::Signal::newObject("onNewLogLine", "QString", NULL);
    PySide::Signal::addSignalToWrapper(&Sbk_QSteelWidget_Type, "onNewLogLine", signal_item);
    Py_DECREF((PyObject*) signal_item);
    signal_item = PySide::Signal::newObject("onSteelReady", "void", NULL);
    PySide::Signal::addSignalToWrapper(&Sbk_QSteelWidget_Type, "onSteelReady", signal_item);
    Py_DECREF((PyObject*) signal_item);
    signal_item = PySide::Signal::newObject("onItemDropped", "QString", NULL);
    PySide::Signal::addSignalToWrapper(&Sbk_QSteelWidget_Type, "onItemDropped", signal_item);
    Py_DECREF((PyObject*) signal_item);


    Shiboken::TypeResolver::createObjectTypeResolver<QSteelWidget >("QSteelWidget*");
    Shiboken::TypeResolver::createObjectTypeResolver<QSteelWidget >(typeid(QSteelWidget).name());
    Shiboken::TypeResolver::createObjectTypeResolver<QSteelWidget >(typeid(QSteelWidgetWrapper).name());
}

