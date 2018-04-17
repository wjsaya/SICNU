from PIL import Image
from PIL import ImageTk
import numpy as np
from matplotlib import pyplot as plt
import tkinter
import time



class im_obj:
    def __init__(self, file):
        self.Name = file
        self.im_obj = Image.open(file)
        self.length, self.width = self.im_obj.size

    def getRGB(self, sw=''):
        start_time = time.time()
        '''
        传入两个参数,sw为r,g,b,gray四选一,表示通道
        '''
        r_list = []
        g_list = []
        b_list = []
        gray_list = []
        im = self.im_obj.load()
        
        for i in range(0, self.length):
            for j in range(0, self.width):
                r, g, b = im[i, j]
                if (sw == 'r'):
                    r_list.append(r)
                if (sw == 'g'):
                    g_list.append(g)
                if (sw == 'b'):
                    b_list.append(b)
                if (sw == 'gray'):
                    gray_list.append((r*19595 + g*38469 + b*7472) >> 16)
                    #L = R * 299/1000 + G * 587/1000+ B * 114/1000
#        print('灰度提取耗时\t\t' + str(time.time() - start_time))
        if (sw == 'r'):
            return r_list
        if (sw == 'g'):
            return g_list
        if (sw == 'b'):
            return b_list
        if (sw == 'gray'):
            return gray_list
        return 0

    def toGray(self):
        start_time = time.time()
        '''
        传入fileName,返回对应的灰度图
        '''
       
        gray_im = Image.new("RGB",(self.length, self.width))
        gray_list = self.getRGB(sw='gray')
        NO = 0
        for i in range(0, self.length):
            for j in range(0, self.width):
                gray_im.putpixel((i, j), (gray_list[NO], gray_list[NO], gray_list[NO]))    #将rgb转化为像素
                NO += 1
#        print('灰度图转换耗时\t\t' + str(time.time() - start_time))
#        gray_im.show()
 #       gray_im.show()
        return(gray_im)


    def reverse(self, kw=''):
        '''
        传入img,返回对应的反转图
        '''
        reverse_im = Image.new("RGB",(self.length, self.width))
        NO = 0
        if kw == 'gray':
            gray_list = self.getRGB(sw='gray')

        else:
            r_list = self.getRGB(sw='r')
            g_list = self.getRGB(sw='g')
            b_list = self.getRGB(sw='b')

        if kw == 'gray':
            for i in range(0, self.length):
                for j in range(0, self.width):
                        reverse_im.putpixel((i, j), (255-gray_list[NO], 255-gray_list[NO], 255-gray_list[NO]))    #将rgb转化为像素
                        NO += 1

        if kw == '':
            for i in range(0, self.length):
                for j in range(0, self.width):
                        reverse_im.putpixel((i, j), (255-r_list[NO], 255-g_list[NO], 255-b_list[NO]))    #将rgb转化为像素
                        NO += 1
#        reverse_im.show()
        return(reverse_im)

    def fdxx(self, fileName = '', sw=125):
        '''
        传入img,传入阈值,默认125
        返回分段线性变换结果
        '''
        if (type(fileName) != str):
            img = fileName
        else:
            img = Image.open(fileName)
        length, width = img.size
        fdxx_im = Image.new("RGB",(length, width))
        gray_list = self.getRGB(sw='gray')
        NO = 0
        for i in range(0, length):
            for j in range(0, width):
                    if(gray_list[NO] <= sw):
                        fdxx_im.putpixel((i, j), (12, 12, 12))    #将rgb转化为像素
                    else:
                        fdxx_im.putpixel((i, j), (255, 255, 255))    #将rgb转化为像素
                    NO += 1
       # fdxx_im.show()
        return(fdxx_im)

def dis_gray_reverse(fileName):
        new_obj = im_obj(fileName)
        length = new_obj.length
        hight = new_obj.width

        root = tkinter.Tk(className = "灰度图与灰度反转图")
        root.geometry(str(length) + "x" + str(hight))

        gray_img = ImageTk.PhotoImage(new_obj.toGray())
        reverse_img = ImageTk.PhotoImage(new_obj.reverse(kw='gray'))

        gray_frame = tkinter.LabelFrame(width = (length/2 + 50), height = (hight/2 + 50), font=("微软雅黑", 15, "bold"), text = '灰度图')
        reverse_frame = tkinter.LabelFrame(width = (length/2 + 50), height = (hight/2 + 50), font=("微软雅黑", 15, "bold"), text = '灰度反转图')

        gray_frame.pack_propagate(0)
        reverse_frame.pack_propagate(0)
        #frame根据内容自动调整大小,改为0关闭

        gray_frame.pack(expand='yes',  side = "left")
        reverse_frame.pack(expand='yes',  side = "right")

        gray_label_img = tkinter.Label(gray_frame, width=length/2, height=hight/2, image = gray_img)
        reverse_label_img = tkinter.Label(reverse_frame, width=length/2, height=hight/2, image = reverse_img)

        gray_label_img.pack()
        reverse_label_img.pack()

        root.mainloop()


def fdxx_change(gray_img, sw=100):
   # global reverse_label_img
    print(sw)
    gray_img = ImageTk.PhotoImage(Image.open(gray_img))
    #reverse_label_img['image'] = new_obj.toGray()
    reverse_label_img['image'] = gray_img
    reverse_label.pack()


    
if __name__ == '__main__':
        '''
        灰度图反转并对比显示
        '''
        fileName = './lena.png'
#        dis_gray_reverse(fileName)

        new_obj = im_obj(fileName)
        length = new_obj.length
        hight = new_obj.width

        root = tkinter.Tk(className = "灰度图分段线性变换")
        root.geometry(str(length) + "x" + str(hight))

        gray = new_obj.toGray()

        gray_img = ImageTk.PhotoImage(gray)
        fdxx_img = ImageTk.PhotoImage(new_obj.fdxx(gray, sw=100))

        gray_frame = tkinter.LabelFrame(width = (length/2 + 50), height = (hight/2 + 50), font=("微软雅黑", 15, "bold"), text = '灰度图')
        fdxx_frame = tkinter.LabelFrame(width = (length/2 + 50), height = (hight/2 + 50), font=("微软雅黑", 15, "bold"), text = '分段线性')
        fdxx_buttom_frame = tkinter.LabelFrame(width = (length/2 + 50), height = (100), font=("微软雅黑", 15, "bold"), text = '分段线性更改按钮')

        gray_frame.pack_propagate(0)
        fdxx_frame.pack_propagate(0)
        fdxx_buttom_frame.pack_propagate(0)
        #frame根据内容自动调整大小,改为0关闭

 #       gray_frame.pack(expand='yes',  side = "left")
 #       fdxx_frame.pack(expand='yes',  side = "right")
 #       fdxx_buttom_frame.pack(expand='yes',  side = "bottom")
        gray_frame.grid(row=0, column=0)
        fdxx_frame.grid(row=0, column=1)
        fdxx_buttom_frame.grid(row=1, column=1)

        gray_label_img = tkinter.Label(gray_frame, width=length/2, height=hight/2, image = gray_img)
        reverse_label_img = tkinter.Label(fdxx_frame, width=length/2, height=hight/2, image = fdxx_img)

        gray_label_img.pack()
        reverse_label_img.pack()

        fdxx100 = tkinter.Button(fdxx_buttom_frame, text='Button100', command=lambda : fdxx_change(fileName, sw=100))
        fdxx150 = tkinter.Button(fdxx_buttom_frame, text='Button150', command=lambda : fdxx_change(fileName, sw=150))
        fdxx200 = tkinter.Button(fdxx_buttom_frame, text='Button200', command=lambda : fdxx_change(fileName, sw=200))

        #fdxx100.grid(row=0, column=0)
        fdxx100.pack()
        fdxx150.grid(row=0, column=2)
        fdxx200.grid(row=0, column=4)
        root.mainloop()


