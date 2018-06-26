from PIL import Image
from PIL import ImageTk
import numpy as np
from matplotlib import pyplot as plt
import tkinter
import matplotlib.cm as cm
import time

class im_obj:
    def __init__(self, file):
        self.Name = file
        self.im_obj = Image.open(file)
        self.length, self.width = self.im_obj.size
        self.getGray = self.toGray

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
        if type(self.getGray) is Image.Image:
            print("已有灰度图")
            return self.getGray

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
        self.getGray = gray_im
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

def FDXX(fileName):
        new_obj = im_obj(fileName)
        length = new_obj.length
        hight = new_obj.width
        
            #fdxx_ops(new_obj, 100, 190, 130, 150, 100, 200)
            
        root = tkinter.Tk(className = "灰度图分段线性变换")
        root.geometry(str(length) + "x" + str(int(hight / 1.5)))

        gray = new_obj.toGray()
        gray_img = ImageTk.PhotoImage(gray)
        fdxx_img1 = fdxx_ops(new_obj, 10, 190, 130, 150, 100, 200)
        fdxx_img = ImageTk.PhotoImage(fdxx_img1)

        gray_frame = tkinter.LabelFrame(width = (length/2 + 50), height = (hight/2 + 50), font=("微软雅黑", 15, "bold"), text = '灰度图')
        fdxx_frame = tkinter.LabelFrame(width = (length/2 + 50), height = (hight/2 + 50), font=("微软雅黑", 15, "bold"), text = '分段线性')
        fdxx_buttom_frame = tkinter.LabelFrame(width = (length/2 + 50), height = (100), font=("微软雅黑", 15, "bold"), text = '分段线性值')

        gray_frame.pack_propagate(0)
        fdxx_frame.pack_propagate(0)
        fdxx_buttom_frame.pack_propagate(0)
        gray_frame.grid(row=0, column=1)
        fdxx_frame.grid(row=0, column=2)
        fdxx_buttom_frame.grid(row=1, column=2)
        a=tkinter.Entry(fdxx_buttom_frame, text='a', show=None)
        a.grid(row=0, column=0)
        b=tkinter.Entry(fdxx_buttom_frame,show=None)
        b.grid(row=0, column=1)
        c=tkinter.Entry(fdxx_buttom_frame,show=None)
        c.grid(row=1, column=0)
        d=tkinter.Entry(fdxx_buttom_frame,show=None)
        d.grid(row=1, column=1)
        Mf=tkinter.Entry(fdxx_buttom_frame,show=None)
        Mf.grid(row=2, column=0)
        Mg=tkinter.Entry(fdxx_buttom_frame,show=None)
        Mg.grid(row=2, column=1)

        
        gray_label_img = tkinter.Label(gray_frame, width=length/2, height=hight/2, image = gray_img)
        fdxx_label_img = tkinter.Label(fdxx_frame, width=length/2, height=hight/2, image = fdxx_img)
            
        gray_label_img.pack()
        fdxx_label_img.pack()

        root.mainloop()

def fdxx_ops(obj, a, b, c, d, Mf, Mg):
        hight = obj.length
        width = obj.width
        origon_im = obj.im_obj.load()
        fdxx_im = Image.new("RGB",(hight, width))
        for i in range(0, hight):
            for j in range(0, width):
                if((origon_im[i, j][0] >= 0) & (origon_im[i, j][0] <= a-1)):
                    temp = int(c*origon_im[i, j][0]/a)
                    fdxx_im.putpixel((i, j), (temp, temp, temp))
                    
                elif((origon_im[i, j][0] >= a ) & (origon_im[i, j][0] <= b-1)):
                    temp = int((d-c)/(b-a) * (origon_im[i, j][0]-a) + c)
                    fdxx_im.putpixel((i, j), (temp, temp, temp))
                    
                else:
                    temp = int((Mg-d)/(Mf-b)*(origon_im[i, j][0]-b)+d)
                    fdxx_im.putpixel((i, j), (temp, temp, temp))
        #fdxx_im.show()
        return(fdxx_im)
    

def ZFTJH(fileName = ''):
    image = Image.open(fileName).convert("L") 
    image_array = np.array(image)
    plt.subplot(2,2,1)
    plt.hist(image_array.flatten(),256)
    plt.subplot(2,2,2)
    plt.imshow(image,cmap=cm.gray)
    plt.axis("off")
    plt.title("origon")
    
    a = zftjh_do(image_array)  #利用刚定义的直方图均衡化函数对图像进行均衡化处理
    plt.subplot(2,2,3)
    plt.hist(a[0].flatten(),256)
    plt.subplot(2,2,4)
    plt.imshow(Image.fromarray(a[0]),cmap=cm.gray)
    plt.axis("off")
    plt.title("jun heng hua")
    
    plt.show()

def zftjh_do(image_array,image_bins=256):
    # 将图像矩阵转化成直方图数据，返回元组(频数，直方图区间坐标)
    image_array2,bins = np.histogram(image_array.flatten(),image_bins)
    # 计算直方图的累积函数
    cdf = image_array2.cumsum()
    # 将累积函数转化到区间[0,255]
    cdf = (255.0/cdf[-1])*cdf
    # 原图像矩阵利用累积函数进行转化，插值过程
    image2_array = np.interp(image_array.flatten(),bins[:-1],cdf)
    # 返回均衡化后的图像矩阵和累积函数
    return (image2_array.reshape(image_array.shape),cdf)

def PYJX(fileName=''):
    MOVE=500    #右移100像素
    img = Image.open(fileName)
    width, hight = img.size
    
    origon_array = np.array(img)
    move_array = Image.new("RGB",(width, hight))
    mirror_array = Image.new("RGB",(width, hight))
    
    for i in range(0, width):
        for j in range(0, hight):
            #if(i<MOVE):
            #    move_array.putpixel((i, j), (0, 0, 0))   #剩下的直接填白
            #else:
            move_array.putpixel((i, j), tuple(origon_array[j][i-MOVE])) 
    
        
    for i in range(0, width):
        for j in range(0, hight):
                mirror_array.putpixel((i, j), tuple(origon_array[j][width-1-i])) 
       
    plt.subplot(2,2,1)
    plt.title("origon")
    plt.axis("off")
    plt.imshow(origon_array)
    
    plt.subplot(2,2,2)
    plt.title("moved++"+str(MOVE))
    plt.imshow(move_array)
    
    plt.subplot(2,2,3)
    plt.title("mirror")
    plt.axis("off")
    plt.imshow(mirror_array)
    
    plt.show()
    

def FDSX(fileName=''):
    img = Image.open(fileName)
    width, hight = img.size
    
    origon_array = np.array(img)
    small_array = Image.new("RGB",(width, hight))
    big_array = Image.new("RGB",(int(width/2), int(hight/2)))
    
    for i in range(0, width):
        for j in range(0, hight):
            pass
        #            big_array.putpixel((i, j), (int(origon_array[i][j][0]/2), int(origon_array[i][j][1]/2), int(origon_array[i][j][2]/2)))
            
    for i in range(0, int(width/2)):
        for j in range(0, int(hight/2)):
                big_array.putpixel((i, j), tuple(origon_array[int(j/2)][int(i/2)])) 
       
    plt.subplot(2,2,1)
    plt.title("origon")
    plt.axis("off")
    plt.imshow(origon_array)
    
    plt.subplot(2,2,2)
    plt.title("big")
    plt.imshow(big_array)
    
    plt.subplot(2,2,3)
    plt.title("small")
    plt.axis("off")
    plt.imshow(small_array)
    
    plt.show()
    
    
if __name__ == '__main__':
        '''
        灰度图反转并对比显示
        '''
        fileName = './lena.png'
        a = im_obj(fileName)
        aa = a.getGray()
        aa.show()
#        dis_gray_reverse(fileName)
#        FDXX(fileName)
 #       ZFTJH(fileName)
 #       PYJX(fileName)
#        FDSX(fileName)
