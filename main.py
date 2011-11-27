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
         
if __name__ == '__main__':
    app = QApplication(sys.argv)
    window = MainWindow()
    window.setCentralWidget(PyQSteelWidget.QSteelWidget())
    window.show()
    app.exec_()
