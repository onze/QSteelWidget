TEMPLATE = lib
CONFIG += qt
QT += core gui

UI_DIR = build
RCC_DIR = build
MOC_DIR = build
OBJECTS_DIR = build

INCLUDEPATH += PyQSteelWidget
INCLUDEPATH += ../qsteelwidget
INCLUDEPATH += ../pyqsteelwidget

INCLUDEPATH += /usr/include/python2.7

#global pyside install
INCLUDEPATH += /usr/include/shiboken
INCLUDEPATH += /usr/include/PySide
INCLUDEPATH += /usr/include/PySide/QtCore
INCLUDEPATH += /usr/include/PySide/QtGui

#local pyside install
#INCLUDEPATH += /home/onze/pkg/pyside-sandbox/include/shiboken
#INCLUDEPATH += /home/onze/pkg/pyside-sandbox/include/PySide
#INCLUDEPATH += /home/onze/pkg/pyside-sandbox/include/PySide/QtCore
#INCLUDEPATH += /home/onze/pkg/pyside-sandbox/include/PySide/QtGui

INCLUDEPATH += /usr/local/include/OGRE
INCLUDEPATH += /media/z2/cpp/1105/Steel/Steel/include
INCLUDEPATH += /usr/include/jsoncpp

INCLUDEPATH += $(`pkg-config pyside --cflags`)
INCLUDEPATH += $(`pkg-config shiboken --cflags`)

LIBS += -ldl 
LIBS += -lpython2.7
LIBS += -lpyside
LIBS += -lshiboken
#LIBS += $(`pkg-config pyside --libs`)
#LIBS += $(`pkg-config shiboken --libs`)
LIBS += -L/media/z2/cpp/1105/Steel/Debug/ -lSteel
LIBS += -L../qsteelwidget/build -lQSteelWidget
LIBS += -L/usr/include/jsoncpp -ljsoncpp


TARGET = build/PyQSteelWidget

SOURCES += \
    PyQSteelWidget/pyqsteelwidget_module_wrapper.cpp \
    PyQSteelWidget/qsteelwidget_wrapper.cpp \
