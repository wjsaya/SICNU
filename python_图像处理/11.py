from PIL import Image
import numpy as np
from matplotlib import pyplot as plt
import pylab 

 

def OTSU_enhance(img_gray, th_begin=0, th_end=256, th_step=1):  

    max_g = 0  
    suitable_th = 0  
    for threshold in range(th_begin, th_end, th_step):  
        bin_img = img_gray > threshold  
        bin_img_inv = img_gray <= threshold  
        fore_pix = np.sum(bin_img)  
        back_pix = np.sum(bin_img_inv)  
        if 0 == fore_pix:  
            break  
        if 0 == back_pix:  
            continue  
  
        w0 = float(fore_pix) / img_gray.size  
        u0 = float(np.sum(img_gray * bin_img)) / fore_pix  
        w1 = float(back_pix) / img_gray.size  
        u1 = float(np.sum(img_gray * bin_img_inv)) / back_pix  
        # intra-class variance  
        g = w0 * w1 * (u0 - u1) * (u0 - u1)  
        if g > max_g:  
            max_g = g  
            suitable_th = threshold  
    return suitable_th  

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


if __name__ == '__main__':
        fileName = './lena.png'
        #do2(200, fileName)
        im = Image.open(fileName)
        im1 = im.convert('L') 
        T = OTSU_enhance(im1)
        do2(T, fileName)
