

#ifndef SBK_PYQSTEELWIDGET_PYTHON_H
#define SBK_PYQSTEELWIDGET_PYTHON_H

//workaround to access protected functions
#define protected public

#include <Python.h>
#include <conversions.h>
#include <sbkenum.h>
#include <basewrapper.h>
#include <bindingmanager.h>
#include <memory>

// Module Includes
#include <pyside_qtcore_python.h>
#include <pyside_qtgui_python.h>

// Binded library includes
#include <QSteelWidget.h>
// Conversion Includes - Primitive Types
#include <QString>
#include <signalmanager.h>
#include <typeresolver.h>
#include <QtConcurrentFilter>
#include <QTextDocument>

// Conversion Includes - Container Types
#include <QList>
#include <QMap>
#include <QStack>
#include <QMultiMap>
#include <QVector>
#include <QPair>
#include <pysideconversions.h>
#include <QSet>
#include <QStringList>

// Type indices
#define SBK_QSTEELWIDGET_IDX                                         0
#define SBK_PyQSteelWidget_IDX_COUNT                                 1

// This variable stores all python types exported by this module
extern PyTypeObject** SbkPyQSteelWidgetTypes;

// Macros for type check

namespace Shiboken
{

// PyType functions, to get the PyObjectType for a type T
template<> inline PyTypeObject* SbkType< ::QSteelWidget >() { return reinterpret_cast<PyTypeObject*>(SbkPyQSteelWidgetTypes[SBK_QSTEELWIDGET_IDX]); }

// Generated converters declarations ----------------------------------

template<>
struct Converter< ::QSteelWidget* > : ObjectTypeConverter< ::QSteelWidget >
{
};

template<>
struct Converter< ::QSteelWidget > : ObjectTypeReferenceConverter< ::QSteelWidget >
{
};

} // namespace Shiboken

// User defined converters --------------------------------------------
// Generated converters implemantations -------------------------------


#endif // SBK_PYQSTEELWIDGET_PYTHON_H

