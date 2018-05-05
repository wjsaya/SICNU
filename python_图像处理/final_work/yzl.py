# -*- coding: utf-8 -*-

from PyQt5.QtCore import pyqtSlot
from PyQt5 import QtGui
import sys
from PyQt5 import QtWidgets

from MainWindow import Ui_MainWindow

from PIL import Image
from PIL.ImageQt import ImageQt

import os



class MainWindow(QtWidgets.QMainWindow,  Ui_MainWindow):
    def __init__(self, parent=None):
        QtWidgets.QWidget.__init__(self, parent)
        self.setupUi(self)
        self.on_button_open_clicked()

    def gray(self, filename):
        im = Image.open(filename).convert('L')
        im.save('gray.jpeg')

    def erzhi(self, filename):
        im = Image.open(filename).convert('L').convert('1')
        im.save('erzhi.jpeg')

    def test(self, filename):
        im = Image.open(filename)
        QtImage1 = ImageQt(im)
        QtImage2 = QtGui.QImage(QtImage1)
        pixmap = QtGui.QPixmap.fromImage(QtImage2)
        return pixmap
        
    @pyqtSlot()
    def on_button_open_clicked(self): 
        self.fileName = [None, '2']
        self.fileName = QtWidgets.QFileDialog.getOpenFileName(self,"打开图片",".","Image files(*.jpeg *.jpg *.png *.bmp) ;; 所有文件 * ")
        self.tips.setText("已打开:" + self.fileName[0])
        self.setWindowTitle("打开")
        im = QtGui.QPixmap(self.fileName[0]).scaled(300,200)
        self.img_origin.setPixmap(im)

    @pyqtSlot()
    def on_button_save_clicked(self):
        self.tips.setText("保存 按钮按下")
        self.setWindowTitle("保存")
        print("start test")
        im = self.test(self.fileName[0])
        print(im)
        print("stop test")
        self.img_prev.setPixmap(im)


    @pyqtSlot()
    def on_button_1_clicked(self):
        self.tips.setText("彩色已转灰度，文件为./gray.jpeg")
        self.setWindowTitle("彩->灰")
        self.gray(self.fileName[0])
        im = QtGui.QPixmap('./gray.jpeg').scaled(300,200)
        self.img_prev.setPixmap(im)

    @pyqtSlot()
    def on_button_2_clicked(self):
        self.tips.setText("转换二值图完毕，文件为./erzhi.jpeg")
        self.setWindowTitle("灰->二")
        self.erzhi(self.fileName[0])
        im = QtGui.QPixmap('./erzhi.jpeg').scaled(300,200)
        self.img_prev.setPixmap(im)

        
    @pyqtSlot()
    def on_button_3_clicked(self):
        self.tips.setText("几何变换 按钮按下")
        self.setWindowTitle("几何变换")

    @pyqtSlot()
    def on_button_4_clicked(self):
        self.tips.setText("去噪 按钮按下")
        self.setWindowTitle("去噪")

    @pyqtSlot()
    def on_button_5_clicked(self):
        self.tips.setText("push 按钮按下")
        self.setWindowTitle("push")

    @pyqtSlot()
    def on_button_6_clicked(self):
        self.tips.setText("边缘提取 按钮按下")
        self.setWindowTitle("边缘提取")

    @pyqtSlot()
    def on_button_7_clicked(self):
        self.tips.setText("加躁 按钮按下")
        self.setWindowTitle("加躁")

    @pyqtSlot()
    def on_button_8_clicked(self):
        self.tips.setText("退出 按钮按下")
        self.setWindowTitle("退出")


if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    w = MainWindow()
    w.show()
    sys.exit(app.exec_())
