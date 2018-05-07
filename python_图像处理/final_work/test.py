import sys
from PyQt5 import QtCore, QtGui, QtWidgets

class Example(QtWidgets.QDialog):
    def __init__(self, parent=None):
        super(Example, self).__init__(parent)
        self.slotCustom()

    def slotCustom(self):    
            customMsgBox=QtWidgets.QMessageBox(self)    
            customMsgBox.setWindowTitle("Custom message box")    
            lockButton=customMsgBox.addButton(self.tr("锁定"),    
                                              QtWidgets.QMessageBox.ActionRole)    
            unlockButton=customMsgBox.addButton(self.tr("解锁"),    
                                                QtWidgets.QMessageBox.ActionRole)    
            cancelButton=customMsgBox.addButton("cancel",QtWidgets.QMessageBox.ActionRole)    
        
            customMsgBox.setText(self.tr("这是一个自定义消息框!"))    
            customMsgBox.exec_()    
        
            button=customMsgBox.clickedButton()    
            if button==lockButton:    
                self.label.setText("Custom MessageBox/Lock")    
            elif button==unlockButton:    
                self.label.setText("Custom MessageBox/Unlock")    
            elif button==cancelButton:    
                self.label.setText("Custom MessageBox/Cancel")    

if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    ex = Example()
    ex.show()
    sys.exit(app.exec_())