import sys
from PyQt5 import QtCore, QtGui, QtWidgets
from test1 import Ui_MainWindow

class MainWindow(QtWidgets.QMainWindow,  Ui_MainWindow):
    def __init__(self, parent=None):
        QtWidgets.QWidget.__init__(self, parent)
        self.setupUi(self)

        #self.lay1.show()

      # self.lay2.hide()
      #  self.listWidget.hide()

    def on_pu1_clicked(self):
        self.listWidget.hide()
        self.wi1.hide()
        
    def on_pu2_clicked(self):
        self.listWidget.show()
        self.wi1.show()
        
        
if __name__ == "__main__":
    app=0
    app = QtWidgets.QApplication(sys.argv)
    w = MainWindow()
    w.show()
    sys.exit(app.exec_())
