from PIL import Image
import numpy as np
from matplotlib import pyplot as plt
import pylab 

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

def otsu(fileName = ''):
        '''
        类判别分析法（otsu）求二值化的阈值T
        '''
        if len(fileName) == 0:
                print('otsu函数，未接收到图片名')
                return False
        im = pylab.array(Image.open(fileName).convert('L'))
        pylab.hist(im.flatten(),128)
        pylab.show()


if __name__ == '__main__':
        #fileName = 'lena.png'
        fileName = './lena.png'
        otsu(fileName)









def get2(T = '',fileName = ''):
        '''
        传入t，用给定t进行二值化
        '''
        if len(fileName) == 0:
                print('未传入图片名')
                return False
        print('开始二值化,T=' + str(T)
        img = np.array(Image.open(fileName).convert('L'))
        rows, cols = img.shape
        for i in range(rows):
                for j in range(cols):
                        if (img[i, j] <= T):
                                img[i, j] = 0
                        else:
                                img[i, j] = 1
        plt.figure("T=" + str(T))
        plt.imshow(img, cmap='gray')
        plt.axis('off')
        plt.show()

