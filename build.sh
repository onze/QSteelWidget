#!/bin/sh

cd qsteelwidget
qmake
make
cd ..

cd qsteelwidgetpy

QTGUI_INC=/usr/include/qt4:/usr/include/qt4/QtGui:/usr/include/qt4/Qt/
QTCORE_INC=/usr/include/qt4:/usr/include/qt4/QtCore:
QTTYPESYSTEM=/home/onze/pkg/pyside-sandbox/share/PySide/typesystems

generatorrunner --generatorSet=shiboken \
    ../data/global.h \
    --include-paths=../qsteelwidget:$QTCORE_INC:$QTGUI_INC \
    --typesystem-paths=../data:$QTTYPESYSTEM \
    --output-directory=. \
    ../data/typesystem.xml

qmake
make
cd ..

rm -rf PyQSteelWidget.so
ln -s libPyQSteelWidget.so PyQSteelWidget.so

echo "done"

