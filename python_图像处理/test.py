'''Tkinter教程之Frame篇'''
#Frame就是屏幕上的一块矩形区域，多是用来作为容器（container）来布局窗体。
'''1.创建Frame'''

#添加不同颜色的Frame，大小均为20*400
'''2.向Frame中添加Widget'''
# -*- coding: cp936 -*-
from tkinter import *
root = Tk()

LabelFrame(height = 200,width = 300,text = 'red').pack(expand='yes',  side = "left")
LabelFrame(height = 200,width = 300,text = 'blue').pack(expand='yes',  side = "right")

root.mainloop()

#author:     jcodeer
#blog:    jcodeer.cublog.cn
#email:    jcodeer@126.com
