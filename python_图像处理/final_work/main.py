# -*- coding: utf-8 -*-
from PyQt5.QtCore import pyqtSlot
from PyQt5 import QtGui
import sys
from PyQt5 import QtWidgets
from PyQt5 import QtCore

from Ui_MainWindow import Ui_MainWindow

from PIL import Image
from PIL.ImageQt import ImageQt

import os


class MainWindow(QtWidgets.QMainWindow,  Ui_MainWindow):
    def __init__(self, parent=None):
        QtWidgets.QWidget.__init__(self, parent)
        self.setupUi(self)
        self.setWindowIcon(QtGui.QIcon('./icons/mainWindow.jpg'))
        self.action_open.triggered.connect(self.on_button_open_clicked)
        self.action_save.triggered.connect(self.on_button_save_clicked)
        self.action_quit.triggered.connect(self.close)
        self.button_8.clicked.connect(self.close)

    def closeEvent(self, event): 
        #重写closeEvent,添加确认弹框
        if (isinstance(self.img_prev.pixmap(), QtGui.QPixmap)) is False:
            #sys.exit() 
            # 如果不用if嵌套,直接sys.exit()也可,但是if嵌套逻辑更清晰.
            # 如果self.img_prev.pixmap()不是Qpixmap,那么img_prev标签则没有图片,那么直接同意closeEvent退出即可.
            event.accept()
        else:
            checkMsgBox = QtWidgets.QMessageBox(self) 
            checkMsgBox.setWindowTitle("退出?") 
            checkMsgBox.setWindowIcon(QtGui.QIcon('./icons/quit.ico'))
            savequitButton = checkMsgBox.addButton(self.tr("保存&退出"), QtWidgets.QMessageBox.ActionRole)
            justquitButton = checkMsgBox.addButton(self.tr("直接退出"), QtWidgets.QMessageBox.ActionRole)
            cancelButton = checkMsgBox.addButton("手滑了,取消",QtWidgets.QMessageBox.ActionRole)
            checkMsgBox.setText(self.tr("对图片的修改还未保存,直接退出?"))
            checkMsgBox.exec_()
        
            button = checkMsgBox.clickedButton()
            if button == savequitButton:
                self.on_button_save_clicked()
                event.accept()
            elif button == justquitButton:
                event.accept()
            elif button == cancelButton:
                event.ignore()


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
    def on_action_about_triggered(self): 
        self.statusBar().showMessage('关于我们')   ###############################################################3
        QtWidgets.QMessageBox.information(None, "关于我们",
            "第X组\n")
        
    @pyqtSlot()
    def on_button_open_clicked(self): 
        self.fileName = [None, '2']
        self.fileName = QtWidgets.QFileDialog.getOpenFileName(self,
		    "打开图片",
		    "./",
		    "Image files(*.jpeg *.jpg *.png *.bmp) ;; 所有文件 (*)")
        self.statusBar().showMessage("已打开:" + self.fileName[0])
        self.setWindowTitle("打开")
        im = QtGui.QPixmap(self.fileName[0])
        self.imgWidth, self.imgHight = im.width(), im.height()
        self.unit = im.width()/200
        self.img_origin.setPixmap(im)


    def on_slider_origin_valueChanged(self):
        value_now = (self.slider_origin.value()+1) * self.unit
        self.statusBar().showMessage("原图原尺寸：" + str(self.imgWidth) + "X" + str(self.imgHight) +
                          "\t原图当前尺寸：" + str(self.imgWidth - value_now) +
                          "X" + str(self.imgHight - value_now))
        im = QtGui.QPixmap(self.fileName[0]).scaled(self.imgWidth - value_now, self.imgHight - value_now, aspectRatioMode=QtCore.Qt.KeepAspectRatio)
        self.img_origin.setPixmap(im)
        

    def on_slider_prev_valueChanged(self):
        if 'prevDisplay' not in dir(self):
            self.prevDisplay = self.img_prev.pixmap().copy()    #保存预览图最初样貌,scaled会调用
            self.prevOrigin = self.prevDisplay.copy()
        else:
            self.prevDisplay = self.prevOrigin.copy()

        value_now = (self.slider_prev.value()+1) * self.unit
        self.statusBar().showMessage("预览图原尺寸：" + str(self.imgWidth) + "X" + str(self.imgHight) +
                          "\t预览图当前尺寸：" + str(self.imgWidth - value_now) +
                          "X" + str(self.imgHight - value_now))
        #缩放比例有点问题，待优化
        im = self.prevDisplay.scaled(self.imgWidth - value_now, self.imgHight - value_now, aspectRatioMode=QtCore.Qt.KeepAspectRatio)
        self.img_prev.setPixmap(im)

    @pyqtSlot()
    def on_button_save_clicked(self):      

        QtWidgets.QMessageBox.information(None, "提示",
            "保存图片为右边预览窗口的图片,包括图片大小都是\n"
            "建议将图片缩放到所需尺寸后再保存\n")

        self.saveimg_name, self.saveimg_type = QtWidgets.QFileDialog.getSaveFileName(self,  
            "文件保存",
            "./",
            "Image files(*.jpeg *.jpg *.png *.bmp) ;; 所有文件 (*)")
        if(self.imgsave(self.saveimg_name)):
            self.statusBar().showMessage("已保存为:" + self.saveimg_name)


    @pyqtSlot()
    def on_button_1_clicked(self):
        self.gray(self.fileName[0])
        im = self.gray(self.fileName[0])
        self.img_prev.setPixmap(im)
        self.statusBar().showMessage("彩色图转灰度图完毕")

    @pyqtSlot()
    def on_button_2_clicked(self):
        self.setWindowTitle("灰->二")
        im = self.erzhi(self.fileName[0])
        self.img_prev.setPixmap(im)
        self.statusBar().showMessage("转换二值图完毕")

        
    @pyqtSlot()
    def on_button_3_clicked(self):
        QtWidgets.QMessageBox.information(None, "Tips",
            "要缩放图片?拖动图片下方的滑块试试\n")

    @pyqtSlot()
    def on_button_4_clicked(self):
        self.statusBar().showMessage("去噪 按钮按下")

    @pyqtSlot()
    def on_button_5_clicked(self):
        pass
        #测试图片实时缩放
       # self.statusBar().showMessage("push 按钮按下")
       # self.setWindowTitle("push")

    @pyqtSlot()
    def on_button_6_clicked(self):
        self.statusBar().showMessage("边缘提取 按钮按下")

    @pyqtSlot()
    def on_button_7_clicked(self):
        self.statusBar().showMessage("加躁 按钮按下")



if __name__ == "__main__":
    app=0
    app = QtWidgets.QApplication(sys.argv)
    w = MainWindow()
    w.show()
    sys.exit(app.exec_())


