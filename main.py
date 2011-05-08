
"""
sets up a dummy window with an empty steel widget in it.
"""

import sys
from PySide.QtCore import *
from PySide.QtGui import *

#should be in LD_LIBRARY_PATH be found
#-> whther a ternial export, or as a launch prefix for any needing app:
#env LD_LIBRARY_PATH=/media/z2/cpp/1105/Hybrid python ./main.py
from PyQSteelWidget import *

a = QApplication(sys.argv)
m=QMainWindow()
m.setWindowTitle('QSteelWidget')
m.resize(800,600)
m.show()
m.setCentralWidget(QSteelWidget())
a.exec_()
