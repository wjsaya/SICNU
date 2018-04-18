#!/usr/bin/python3
# -*- coding: utf-8 -*-
import sys
from PyQt5.QtWidgets import QWidget, QToolTip,QPushButton, QApplication
from PyQt5.QtGui import QFont

class Example(QWidget):
    def __init__(self):
        super().__init__()
        self.initUI()
        
    def initUI(self):
        #这种静态的方法设置一个用于显示工具提示的字体。我们使用10px滑体字体。
        QToolTip.setFont(QFont('黑体', 10))
        #创建一个提示，我们称之为settooltip()方法。我们可以使用丰富的文本格式
        self.setToolTip('qqqqq')
        #创建一个PushButton并为他设置一个tooltip
        btn = QPushButton('Button', self)
        btn.setToolTip('ppppp')
        #btn.sizeHint()显示默认尺寸
        btn.resize(btn.sizeHint())
        #移动窗口的位置
        btn.move(50, 50)
        self.resize(250, 150)
        self.setWindowTitle('Center')
        self.setWindowTitle('窗口')
        self.show()
        
if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())