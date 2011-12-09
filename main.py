#!/usr/bin/python

print 'bootstrapping...'

import sys
import os

#making sure we are where we should
root,script=os.path.split(os.path.abspath(__file__))
os.chdir(root)

#making sure we can load shared object modules located in our folder
if 'LD_LIBRARY_PATH' not in os.environ or root not in os.environ['LD_LIBRARY_PATH']:
    print 'adding test\'s root folder (\'%(root)s\') to LD_LIBRARY_PATH and relaunching...'%locals()
    os.environ['LD_LIBRARY_PATH']=root+':'+os.environ['LD_LIBRARY_PATH']
    os.execve(script, (script,), os.environ)
else:
    print 'LD_LIBRARY_PATH:',os.environ['LD_LIBRARY_PATH']


import PySide
from PySide.QtCore import *
from PySide.QtGui import *

import PyQSteelWidget

class MainWindow(QMainWindow):
    def __init__(self, parent=None):
        super(MainWindow, self).__init__(parent)

def assert_widget_methods(widget):
    print '== checking expected widget methods are here =='
    # list of method we expect to be present in the widget
    methods=[
             'addResourceLocation',
             'createAgent',
             'isSteelReady',
             'removeResourceLocation',
             'saveCurrentLevel',
             'setLevel',
             'dropTargetPosition',
             'dropTargetRotation',
             'agentPosition',
             'cameraPosition',
             'cameraRotation',
             'engineModeUpdate',
             '',
             ]
    methods=[m for m in map(str.strip,methods) if len(m)]
    here=dir(widget)
    missing=[]
    for method in methods:
        print '\rchecking %(method)s...'%locals(),
        if method in here:
            print 'ok'
        else:
            print 'missing !'
            missing.append(method)
    print '== report =='
    print 'found %i/%i methods'%(len(methods)-len(missing),len(methods))
    print 'missing methods:\n\t','\n\t'.join(missing)
    return not bool(missing)
     
if __name__ == '__main__':
    app = QApplication(sys.argv)
    window = MainWindow()
    w=PyQSteelWidget.QSteelWidget()
    window.setCentralWidget(w)
    if not assert_widget_methods(w):
        exit()
    window.show()
    app.exec_()
