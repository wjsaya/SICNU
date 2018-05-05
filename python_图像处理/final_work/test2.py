from PyQt5.QtWidgets import QApplication, QLabel, QSlider  
from PyQt5 import QtWidgets  
from PyQt5.QtCore import Qt  
from PyQt5.QtGui import QPixmap  
  
class SliderLabel(QtWidgets.QWidget):  
    def __init__(self, parent= None):  
        QtWidgets.QWidget.__init__(self)  
          
        self.setGeometry(300, 300, 500, 320)  
        self.setWindowTitle('SliderLabel')  
        self.slider = QSlider(Qt.Horizontal, self)  
        self.slider.setFocusPolicy(Qt.NoFocus)  
        self.slider.setGeometry(30, 40, 100, 30)  
        self.slider.valueChanged.connect(self.changeValue)
        self.label = QLabel(self)  
        self.label.setPixmap(QPixmap('icons/1.png'))  
        self.label.setGeometry(160, 40, 300, 250)  
  
          
    def changeValue(self, value):  
        pos = self.slider.value()
        self.label.setText(str(pos))
          
  
if __name__ == "__main__":  
    import sys  
    app = QApplication(sys.argv)  
    qb = SliderLabel()  
    qb.show()  
    sys.exit(app.exec_())