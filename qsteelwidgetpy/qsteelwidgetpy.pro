TEMPLATE = lib
QT += core gui

INCLUDEPATH += qsteelwidget
INCLUDEPATH += ../qsteelwidget

INCLUDEPATH += /usr/include/python2.6
INCLUDEPATH += /usr/local/include/shiboken
INCLUDEPATH += /usr/local/include/PySide
INCLUDEPATH += /usr/local/include/PySide/QtCore
INCLUDEPATH += /usr/local/include/PySide/QtGui

INCLUDEPATH += /usr/local/include/OGRE
INCLUDEPATH += /media/z2/cpp/1105/Steel/Steel/include

LIBS += -ldl -lpython2.6
LIBS += -lpyside
LIBS += -lshiboken
LIBS += -l:/media/z2/cpp/1105/Steel/Debug/libSteel.so
LIBS += -L.. -lQSteelWidget

TARGET = ../PyQSteelWidget

SOURCES += \
    PyQSteelWidget/pyqsteelwidget_module_wrapper.cpp \
    PyQSteelWidget/qsteelwidget_wrapper.cpp \