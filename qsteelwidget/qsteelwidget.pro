TEMPLATE = lib
CONFIG += qt
QT += core gui

TARGET = build/QSteelWidget

UI_DIR = build
RCC_DIR = build
MOC_DIR = build
OBJECTS_DIR = build

INCLUDEPATH += /media/z2/cpp/1105/Steel/Steel/include
INCLUDEPATH += /usr/local/include/OGRE
INCLUDEPATH += /usr/include/jsoncpp

LIBS += -L/media/z2/cpp/1105/Steel/Debug -lSteel
LIBS += -L/usr/include/jsoncpp -ljsoncpp

HEADERS += QSteelWidget.h
HEADERS += QtOgreConversions.h
HEADERS += unittests.h

SOURCES += QSteelWidget.cpp
SOURCES += QtOgreConversions.cpp
SOURCES += unittests.cpp
