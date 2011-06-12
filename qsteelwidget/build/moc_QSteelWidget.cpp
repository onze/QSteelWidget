/****************************************************************************
** Meta object code from reading C++ file 'QSteelWidget.h'
**
** Created: Sat Jun 11 21:58:35 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../QSteelWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QSteelWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QSteelWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,
      34,   29,   13,   13, 0x05,
      60,   56,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      85,   83,   13,   13, 0x0a,
     108,   83,   13,   13, 0x0a,
     137,   83,   13,   13, 0x0a,
     167,   83,   13,   13, 0x0a,
     199,   83,   13,   13, 0x0a,
     225,   83,   13,   13, 0x0a,
     253,   83,   13,   13, 0x0a,
     289,   83,   13,   13, 0x0a,
     314,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QSteelWidget[] = {
    "QSteelWidget\0\0onSteelReady()\0line\0"
    "onNewLogLine(QString)\0url\0"
    "onItemDropped(QString)\0e\0"
    "moveEvent(QMoveEvent*)\0"
    "mouseMoveEvent(QMouseEvent*)\0"
    "mousePressEvent(QMouseEvent*)\0"
    "mouseReleaseEvent(QMouseEvent*)\0"
    "keyPressEvent(QKeyEvent*)\0"
    "keyReleaseEvent(QKeyEvent*)\0"
    "mouseDoubleClickEvent(QMouseEvent*)\0"
    "wheelEvent(QWheelEvent*)\0engineModeUpdate()\0"
};

const QMetaObject QSteelWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QSteelWidget,
      qt_meta_data_QSteelWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QSteelWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QSteelWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QSteelWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QSteelWidget))
        return static_cast<void*>(const_cast< QSteelWidget*>(this));
    if (!strcmp(_clname, "Ogre::LogListener"))
        return static_cast< Ogre::LogListener*>(const_cast< QSteelWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int QSteelWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: onSteelReady(); break;
        case 1: onNewLogLine((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: onItemDropped((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: moveEvent((*reinterpret_cast< QMoveEvent*(*)>(_a[1]))); break;
        case 4: mouseMoveEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 5: mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 6: mouseReleaseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 7: keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 8: keyReleaseEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 9: mouseDoubleClickEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 10: wheelEvent((*reinterpret_cast< QWheelEvent*(*)>(_a[1]))); break;
        case 11: engineModeUpdate(); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void QSteelWidget::onSteelReady()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QSteelWidget::onNewLogLine(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QSteelWidget::onItemDropped(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
