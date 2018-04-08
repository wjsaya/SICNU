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


def do2(T = '',fileName = ''):
        '''
        传入t，用给定t进行二值化
        '''
        if len(fileName) == 0:
                print('未传入图片名')
                return False
        print('开始二值化,T=' + str(T))
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
        plt.show()


def otsu(fileName = ''):
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
        im_gray = im.convert('L') 
    #    img = np.array(Image.open(fileName).convert('L'))
        size = im_gray.size[0] * im_gray.size[1]
#        print(size)

        max_g = 0
        suitable_th = 0

        im_gray = np.array(im_gray)     #图像转数组

        for threshold in range(0, 255, 1):
       #         print(im_gray > threshold)
                bin_img = im_gray > threshold
                bin_img_inv = im_gray <= threshold
                fore_pix = np.sum(bin_img)
                back_pix = np.sum(bin_img_inv)

                if 0 == fore_pix:
                        break
                if 0 == back_pix:
                        continue

                w0 = float(fore_pix) / im_gray.size
                u0 = float(np.sum(im_gray * bin_img)) / fore_pix
                w1 = float(back_pix) / im_gray.size
                u1 = float(np.sum(im_gray * bin_img_inv)) / back_pix
                # intra-class variance
                g = w0 * w1 * (u0 - u1) * (u0 - u1)
                if g > max_g:
                        max_g = g
                        suitable_th = threshold
        return suitable_th
 #       print(np.sum(im_gray))
#        print(fore_pix)
 #       print(back_pix)
        




def gethist(fileName = ''):
        im = pylab.array(Image.open(fileName).convert('L'))
        processName = fileName + '直方图'
        plt.figure(processName)
        arr = im.flatten()
        n, bins, patches = plt.hist(arr, bins=256, facecolor='red', alpha=0.75)
        plt.show()



      #  pylab.hist(im.flatten(),1)
     #   pylab.show()



if __name__ == '__main__':
        fileName = './lena.png'
        #do2(200, fileName)
        #gethist(fileName)
        T = otsu(fileName)
        do2(T, fileName)

