# -*- coding: utf-8 -*-

from PyQt5.QtCore import pyqtSlot
from PyQt5 import QtGui
import sys
from PyQt5 import QtWidgets
from PyQt5 import QtCore

from MainWindow import Ui_MainWindow

from PIL import Image
from PIL.ImageQt import ImageQt

import os


class MainWindow(QtWidgets.QMainWindow,  Ui_MainWindow):
    def __init__(self, parent=None):
        QtWidgets.QWidget.__init__(self, parent)
        self.setupUi(self)
        self.on_button_open_clicked()
        self.slider_origin.valueChanged.connect(self.slider_origin_changed)
        self.slider_prev.valueChanged.connect(self.slider_prev_changed)
        #槽链接有点问题？origin可使用，prev使用有问题

    def imgsave(self, filename):
        try:
            self.img_prev.pixmap().save(filename)
            return True
        except:
            return False

    def gray(self, filename):
        im = Image.open(filename).convert('L')
        QtImage1 = ImageQt(im)
        pixmap = QtGui.QPixmap.fromImage(QtImage1)
        return pixmap
        #im.save('gray.jpeg')

    def erzhi(self, filename):
        im = Image.open(filename).convert('L').convert('1')
        QtImage1 = ImageQt(im)
        pixmap = QtGui.QPixmap.fromImage(QtImage1)
        return pixmap
        #im.save('erzhi.jpeg')

    @pyqtSlot()
    def on_button_open_clicked(self): 
        self.fileName = [None, '2']
        self.fileName = QtWidgets.QFileDialog.getOpenFileName(self,
		    "打开图片",
		    "./",
		    "Image files(*.jpeg *.jpg *.png *.bmp) ;; 所有文件 (*)")
        self.tips.setText("已打开:" + self.fileName[0])
        self.setWindowTitle("打开")
        im = QtGui.QPixmap(self.fileName[0])
        self.unitWidth, self.unitHigh = im.width()/100, im.height()/100
        #获取图片分辨率，稍后将并以150为跨度进行缩放
        self.img_origin.setPixmap(im)
        #self.img_origin.setScaledContents(True)
        #图片太小则拉伸填充，太大则直接跨界

    
    def slider_origin_changed(self):
        value_now = self.slider_origin.value()
        self.tips.setText("origin原始尺寸：" + str(100 * self.unitWidth) + "X" + str(100 * self.unitHigh) +
                          "\norigin图当前尺寸：" + str(value_now*self.unitWidth) +
                          "X" + str(value_now*self.unitHigh))
        im = QtGui.QPixmap(self.fileName[0]).scaled(value_now*self.unitWidth, value_now*self.unitHigh, aspectRatioMode=QtCore.Qt.KeepAspectRatio)
        #缩放比例有点问题，待优化
        self.img_origin.setPixmap(im)
        

    def slider_prev_changed(self):
        value_now = self.slider_prev.value()
        self.tips.setText("prev原始尺寸：" + str(100 * self.unitWidth) + "X" + str(100 * self.unitHigh) +
                          "\nprev图当前尺寸：" + str(value_now*self.unitWidth) +
                          "X" + str(value_now*self.unitHigh))
        im = self.img_prev.pixmap().scaled(value_now*self.unitWidth, value_now*self.unitHigh, aspectRatioMode=QtCore.Qt.KeepAspectRatio)
        self.img_prev.setPixmap(im)

        
        
    @pyqtSlot()
    def on_button_save_clicked(self):
        self.tips.setText("保存 按钮按下")
        self.setWindowTitle("保存")
        self.saveimg_name, self.saveimg_type = QtWidgets.QFileDialog.getSaveFileName(self,  
            "文件保存",  
            "./",  
            "Image files(*.jpeg *.jpg *.png *.bmp) ;; 所有文件 (*)")
        if(self.imgsave(self.saveimg_name)):
            self.tips.setText("已保存为:" + self.saveimg_name)


    @pyqtSlot()
    def on_button_1_clicked(self):
        self.tips.setText("彩色已转灰度，文件为./gray.jpeg")
        self.setWindowTitle("彩->灰")
        self.gray(self.fileName[0])
        im = self.gray(self.fileName[0])#.scaled(300,200)
        self.img_prev.setPixmap(im)

    @pyqtSlot()
    def on_button_2_clicked(self):
        self.tips.setText("转换二值图完毕，文件为./erzhi.jpeg")
        self.setWindowTitle("灰->二")
        im = self.erzhi(self.fileName[0])#.scaled(300,200)
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
        #测试图片实时缩放
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
    app=0
    app = QtWidgets.QApplication(sys.argv)
    w = MainWindow()
    w.show()
    sys.exit(app.exec_())


