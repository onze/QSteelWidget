TEMPLATE = lib
TARGET = ../QSteelWidget
CONFIG += qt
QT += core gui

UI_DIR = build
RCC_DIR = build
MOC_DIR = build
OBJECTS_DIR = build

INCLUDEPATH += /media/z2/cpp/1105/Steel/Steel/include
INCLUDEPATH += /usr/local/include/OGRE

HEADERS += unittests.h
HEADERS += QtOgreConversions.h
HEADERS += QSteelWidget.h

SOURCES += unittests.cpp
SOURCES += QtOgreConversions.cpp
SOURCES += QSteelWidget.cpp
