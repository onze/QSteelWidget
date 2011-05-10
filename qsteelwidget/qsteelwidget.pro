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

HEADERS += QSteelWidget.h
			
SOURCES += QSteelWidget.cpp