from PIL import Image
import numpy as np
from matplotlib import pyplot as plt
import time

def get_details(fileName = ''):
        '''
        传入图片名，显示基础参数
        '''
        im = Image.open(fileName)
        #im.show()
        print("图片类型为\t%s" % im.format)
        print("图片大小为\t" + str(im.size))
        print("图片颜色通道模式为\t" + im.mode)
        #r,g,b = im.split()     #通道分割
        #im = Image.merge("RGB", (g,r,b))       #rgb翻转
        #im.save('lena_rgb.jpg')

def disRGB():
    '''
    输出r,g,b三通道的图
    '''
#   int(r[NO]),int(0),int(0)
   
    for i in range(0,length):
        for j in range(0,width):
            r_im.putpixel((i,j),(  ))#rgb转化为像素
            NO += 1
    r_im.show()
    
     
    NO = 0
    for i in range(0,length):
        for j in range(0,width):
            g_im.putpixel((i,j),(int(0),int(g[NO]),int(0)))#rgb转化为像素
            NO += 1
    g_im.show()
     
    NO = 0
    for i in range(0,length):
        for j in range(0,width):
            b_im.putpixel((i,j),(int(0),int(0),int(b[NO])))#rgb转化为像素
            NO += 1
    b_im.show()
    

def toGray(fileName=''):
    start_time = time.time()
    '''
    传入fileName,返回对应的灰度图
    '''
    img = Image.open(fileName)
    length, width = img.size

    gray_im = Image.new("RGB",(length, width))
    gray_list = getRGB(sw='gray', fileName=fileName)
    NO = 0
    for i in range(0, length):
        for j in range(0, width):
            gray_im.putpixel((i, j), (gray_list[NO], gray_list[NO], gray_list[NO]))    #将rgb转化为像素
            NO += 1
    #gray_im.show()
    print('灰度图转换耗时\t\t' + str(time.time() - start_time))
  #  gray_im.show()
    return(gray_im)
  
def getRGB(sw='', fileName=''):
    start_time = time.time()
    '''
    传入两个参数,sw为r,g,b,gray四选一,表示通道
    fileName为想要打开的文件
    '''
    #print(type(fileName))
    if (type(fileName) != str):
        img = fileName
    else:
        img = Image.open(fileName)
    im = img.load()
    length, width = img.size

    r_list = []
    g_list = []
    b_list = []
    gray_list = []
    
    for i in range(0, length):
        for j in range(0, width):
            r, g, b = im[i, j]
            if (sw == 'r'):
                r_list.append(r)
            if (sw == 'g'):
                g_list.append(g)
            if (sw == 'b'):
                b_list.append(b)
            if (sw == 'gray'):
                gray_list.append((r*19595 + g*38469 + b*7472) >> 16)

    print('灰度提取耗时\t\t' + str(time.time() - start_time))
    if (sw == 'r'):
        return r_list
    if (sw == 'g'):
        return g_list
    if (sw == 'b'):
        return b_list
    if (sw == 'gray'):
        return gray_list
    return 0

def do2(T = '',fileName = ''):
        start_time = time.time()
        '''
        传入t，用给定t进行二值化
        '''
        if len(fileName) == 0:
                print('未传入图片名')
                return False
        #print('开始二值化,T=' + str(T) + + "\t\t" +str(time.time()))
        img = np.array(Image.open(fileName).convert('L'))
        rows, cols = img.shape
        for i in range(rows):
                for j in range(cols):
                        if (img[i, j] <= T):
                                img[i, j] = 0
                        else:
                                img[i, j] = 1
        
        processName = fileName + "的二值化图, T=" + str(T)
        plt.figure(processName)
        plt.imshow(img, cmap='gray')
        plt.axis('off')
        print('二值化耗时\t\t' + str(time.time() - start_time))
        plt.show()


def otsu(fileName = ''):
        start_time = time.time()
        '''
        类判别分析法（otsu）求二值化的阈值T

        假设我们使用阈值T将灰度图像分割为前景和背景
        size：图像总像素个数
        u：图像的平均灰度
        w0：前景像素点占整幅图像大小的比例
        u0：前景像素点的平均值
        w1：背景像素点占整幅图像大小的比例
        u0：背景像素点的平均值
        g：类间方差
        u = w0 * u0 + w1 * u1  (1)
        g = w0*(u - u0)^2 + w1*(u - u1)^2 (2)
        将(1)代入(2)得：
        g = w0 * w1 * (u0 - u1)^2
        采用遍历的方法，遍历所有阈值，当g最大时，该阈值就是我们所求的认为最合适的阈值了。 
        '''
        if len(fileName) == 0:
                print('otsu函数，未接收到图片名')
                return False
        im = Image.open(fileName)
        #im_gray = im.convert('L')
        im_gray = toGray(fileName = fileName)
        size = im_gray.size[0] * im_gray.size[1]

        max_g = 0
        suitable_T = 0
        im_gray = np.array(im_gray)     #图像转numpy中ndarray
        time1 = 0#np_sum耗时
        time3 = 0#计算耗时
        for loop_T in range(0, 255):

                count_start = time.time()

                fore_pix_list = (im_gray > loop_T)
                back_pix_list = (im_gray <= loop_T)
                #大于和小于等于给定临时T，通过比较获取两个大于或者小于等于临时T的nparray，两个数组的组成元素为True和False
                fore_pix = np.sum(fore_pix_list)
                back_pix = np.sum(back_pix_list)

                time1 += (time.time() - count_start)
                count_start = time.time()

                #统计True个数，即当前大于或者小于等于T的像素点个数
                if 0 is fore_pix:
                #如果前景中的像素点统计为0，由于T从0-255递增，如果没有大于T最大值，即255的像素点时，即代表遍历完毕。
                        break
                if 0 is back_pix:
                #如果背景像素点为0个，即没有小于临时T的像素点，跳过本轮，让T自增1继续进行统计
                        continue


                w0 = float(fore_pix) / im_gray.size
                #求前景所有像素点个数/所有像素点的比例
                u0 = float(np.sum(im_gray * fore_pix_list)) / fore_pix
                #im_gray * fore_pix_list，[true, false]*[1,2]=[1, 0],false对应转化为0，其余不变.
                #np.sum的axis默认为0，所以统计本行统计非0的累计和，np.sum([1,2,3,0])结果为6
                w1 = float(back_pix) / im_gray.size
                u1 = float(np.sum(im_gray * back_pix_list)) / back_pix
                g = w0 * w1 * (u0 - u1) * (u0 - u1)

                time3 += (time.time() - count_start)
                count_start = time.time()

                #套用公式，求出类间方差g
                if g > max_g:
                #过滤出最大的类间方差，并提取对应的T
                        max_g = g
                        suitable_T = loop_T


                
        print('获取T耗时\t\t' + str(time.time() - start_time))
        print(time1)
        print(time3)

        return suitable_T
        #返回最大的T，即为OTSU法求出的最合适T
  
def reverse(img=''):
    '''
    传入img,返回对应的反转图
    '''
    length, width = img.size

    reverse_im = Image.new("RGB",(length, width))
    NO = 0
  #  print("reverse:" + str(type(img)))
    r_list = getRGB(sw='r', fileName=img)
    g_list = getRGB(sw='g', fileName=img)
    b_list = getRGB(sw='b', fileName=img)
    
    for i in range(0, length):
        for j in range(0, width):
                reverse_im.putpixel((i, j), (255-r_list[NO], 255-g_list[NO], 255-b_list[NO]))    #将rgb转化为像素
                NO += 1
    reverse_im.show()
    return(reverse_im)
  
def fdxx(fileName = ''):
    '''
    传入img,返回分段线性变换结果
    100,15,255;
    '''

    if (type(fileName) != str):
        img = fileName
    else:
        img = Image.open(fileName)

    length, width = img.size
    fdxx_im = Image.new("RGB",(length, width))
    gray_list = getRGB(sw='gray', fileName=img)
    NO = 0
    for i in range(0, length):
        for j in range(0, width):
                if(gray_list[NO] <= 100):
                    fdxx_im.putpixel((i, j), (100, 100, 100))    #将rgb转化为像素
                elif(100 < gray_list[NO] <= 150):
                    fdxx_im.putpixel((i, j), (150, 150, 150))    #将rgb转化为像素
                else:
                    fdxx_im.putpixel((i, j), (255, 255, 255))    #将rgb转化为像素
                NO += 1
    fdxx_im.show()
    return(fdxx_im)


def gethist(fileName = ''):
        '''
        输出指定文件的直方图
        '''
        im = pylab.array(Image.open(fileName).convert('L'))
        processName = fileName + '直方图'
        plt.figure(processName)
        arr = im.flatten()
        n, bins, patches = plt.hist(arr, bins=256, facecolor='red', alpha=0.75)
        plt.show()




if __name__ == '__main__':
        fileName = './lena.png'
#        gethist(fileName)
        gray_im = toGray(fileName)
#        reverse(gray_im)
#        T = otsu(fileName)
#        do2(T, fileName)
        fdxx(gray_im)

