
QT_INC=/usr/include/qt4:/usr/include/qt4/Qt:/usr/include/qt4/QtCore:/usr/include/qt4/QtGui

STEEL_INC=/media/z2/cpp/1105/Steel/Steel/include

#global pyside install `pkg-config pyside --variable=typesystemdir`
TYPESYSTEMS=/usr/share/PySide/typesystems

#local pyside install
#TYPESYSTEMS=/home/onze/pkg/pyside-sandbox/share/PySide/typesystems

all: lib bindings shared

lib: qsteelwidget/QSteelWidget.cpp qsteelwidget/QSteelWidget.h
	cd qsteelwidget && qmake && make

bindings: global.h typesystem_qsteelwidget.xml
	generatorrunner \
	--generator-set=shiboken \
	--avoid-protected-hack \
	--enable-parent-ctor-heuristic \
	--enable-pyside-extensions \
	--enable-return-value-heuristic \
	--debug-level=sparse \
	--no-supress-warnings \
    --include-paths=qsteelwidget:$(QT_INC):$(STEEL_INC):/usr/include/PySide:/usr/include/shiboken \
    --typesystem-paths=.:$(TYPESYSTEMS) \
    --output-directory=qsteelwidgetpy \
    global.h \
    typesystem_qsteelwidget.xml
	    
shared: qsteelwidgetpy/qsteelwidgetpy.pro qsteelwidgetpy/PyQSteelWidget/pyqsteelwidget_module_wrapper.cpp qsteelwidgetpy/PyQSteelWidget/qsteelwidget_wrapper.cpp
	cd qsteelwidgetpy && qmake && make
	cp ./qsteelwidget/build/*.so* ./
	cp ./qsteelwidgetpy/build/*.so* ./
	cp ./*.so* $(WELD_HOME)/src/plugins
	ln -fs ./libPyQSteelWidget.so ./PyQSteelWidget.so
	cd $(WELD_HOME)/src/plugins && ln -fs ./libPyQSteelWidget.so ./PyQSteelWidget.so
	echo "done"

clean:
	#lib
	rm -rf ./shared
	
	#bindings
	rm -rf qsteelwidget/build
	rm -rf qsteelwidget/Makefile
	
	#shared
	rm -rf qsteelwidgetpy/build
	rm -rf qsteelwidgetpy/Makefile
	rm -rf qsteelwidgetpy/*.log
	rm -rf qsteelwidgetpy/*.cpp
	rm -rf qsteelwidgetpy/*.h
	
