#!/bin/sh


QTGUI_INC="/usr/include/qt4:/usr/include/qt4/QtGui:/usr/include/qt4/Qt"
QTCORE_INC="/usr/include/qt4:/usr/include/qt4/QtCore"
STEEL_INC="/media/z2/cpp/1105/Steel/Steel/include"

QTTYPESYSTEM="/home/onze/pkg/pyside-sandbox/share/PySide/typesystems"

all: shared

lib: qsteelwidget/QSteelWidget.cpp qsteelwidget/QSteelWidget.h
	cd qsteelwidget;qmake
	cd qsteelwidget;make

bindings: lib data/global.h data/typesystem.xml
	cd qsteelwidgetpy;generatorrunner --silent \
		--generatorSet=shiboken \
	    ../data/global.h \
	    --include-paths=../qsteelwidget:$(QTCORE_INC):$(QTGUI_INC):$(STEEL_INC) \
	    --typesystem-paths=../data:$(QTTYPESYSTEM) \
	    --output-directory=. \
	    ../data/typesystem.xml
	    
shared: bindings
	cd qsteelwidgetpy;qmake
	cd qsteelwidgetpy;make
	rm -rf PyQSteelWidget.so
	ln -s libPyQSteelWidget.so PyQSteelWidget.so
	rm -f $(WELD_HOME)/src/PyQSteelWidget.so
	cp PyQSteelWidget.so $(WELD_HOME)/src/PyQSteelWidget.so
	
	echo "done"

clean:
	rm -rf qsteelwidget/build
	rm -rf qsteelwidget/Makefile
	
	rm -rf qsteelwidgetpy/Makefile
	rm -rf qsteelwidgetpy/*.log
	rm -rf qsteelwidgetpy/*.cpp
	rm -rf qsteelwidgetpy/*.h
	
	rm ./*.so