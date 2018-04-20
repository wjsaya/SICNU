# -*- coding: utf-8 -*- 
import sys
from PyQt5.QtWidgets import QApplication, QWidget
from PyQt5.QtGui import QIcon

class Example(QWidget):
    def __init__(self):
        super().__init__()
        self.initUI() #界面绘制交给InitUi方法

    def initUI(self):
        #设置窗口的位置和大小
        self.setGeometry(500, 500, 900, 500)  #x, y, width, hight
        #设置窗口的标题
        self.setWindowTitle('图标')
        #设置窗口的图标，引用当前目录下的web.png图片
        self.setWindowIcon(QIcon('./1 (1).jpg'))
        
        #显示窗口
        self.show()
        
        
if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())