#!/usr/bin/env python
# _*_ coding:utf-8 _*_
import tkinter
from PIL import Image
from PIL import ImageTk
 
def p_label(sw=0):
    global gray_label_img
    print('./1 ('+ str(sw) +').jpg')
    gray_img = ImageTk.PhotoImage(Image.open('./1 ('+ str(sw) +').jpg'))
 #   gray_img = ImageTk.PhotoImage(Image.open('F:/github/SICNU/python_图像处理/1 ('+ str(sw) +').jpg'))
    gray_label_img['image'] = gray_img
    gray_label.pack()
 
root = tkinter.Tk()
fdxx_buttom_frame = tkinter.LabelFrame(width = 200, height = 200, font=("微软雅黑", 15, "bold"), text = '分段线性更改按钮')
fdxx_buttom_frame.grid(row=0, column=0)


gray_img = ImageTk.PhotoImage(Image.open('./1 (2).jpg'))
gray_label_img = tkinter.Label(fdxx_buttom_frame, image = gray_img)
gray_label_img.pack()


Lb = tkinter.Label(fdxx_buttom_frame,text='origon')
Lb.pack()

B_n1 = tkinter.Button(fdxx_buttom_frame,text='1',command= lambda : p_label( sw=1)) #command后面不能有任何的标点符号
B_n2 = tkinter.Button(fdxx_buttom_frame,text='2',command= lambda : p_label( sw=2)) #command后面不能有任何的标点符号
B_n3 = tkinter.Button(fdxx_buttom_frame,text='3',command= lambda : p_label( sw=3)) #command后面不能有任何的标点符号
B_n4 = tkinter.Button(fdxx_buttom_frame,text='4',command= lambda : p_label( sw=4)) #command后面不能有任何的标点符号
B_n5 = tkinter.Button(fdxx_buttom_frame,text='5',command= lambda : p_label( sw=5)) #command后面不能有任何的标点符号
#_label(Lb, sw=1)
B_n1.pack()
B_n2.pack()
B_n3.pack()
B_n4.pack()
B_n5.pack()

root.mainloop()