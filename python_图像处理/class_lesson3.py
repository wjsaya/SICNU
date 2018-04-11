from PIL import Image
import numpy as np
from matplotlib import pyplot as plt
import time

class im_obj:
    def __init__(self, file):
        self.Name = file
        self.im_obj = Image.open(file)
        self.length, self.width = self.im_obj.size
        
    def details(self):
        '''
        传入图片名，显示基础参数
        '''
        print(self.Name)
        print("图片类型为\t%s" % self.im_obj.format)
        print("图片大小为\t" + str(self.im_obj.size))
        print("图片颜色通道模式为\t" + self.im_obj.mode)
      
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
        print('灰度图转换耗时\t\t' + str(time.time() - start_time))
#        gray_im.show()
        return(gray_im)

    def reverse(self):
        '''
        传入img,返回对应的反转图
        '''

        reverse_im = Image.new("RGB",(self.length, self.width))
        NO = 0
      #  print("reverse:" + str(type(img)))
        r_list = self.getRGB(sw='r')
        g_list = self.getRGB(sw='g')
        b_list = self.getRGB(sw='b')
        
        for i in range(0, self.length):
            for j in range(0, self.width):
                    reverse_im.putpixel((i, j), (255-r_list[NO], 255-g_list[NO], 255-b_list[NO]))    #将rgb转化为像素
                    NO += 1
#        reverse_im.show()
        return(reverse_im)
      

    def otsu(self):
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
            im_gray = self.toGray()
            

            max_g = 0
            suitable_T = 0
            im_gray = np.array(self.toGray())     #图像转numpy中ndarray
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
      

    def do2(self, T = -1):
            start_time = time.time()
            '''
            传入t，用给定t进行二值化
            '''
            if T == -1:
                    T = self.otsu()
            #print('开始二值化,T=' + str(T) + + "\t\t" +str(time.time()))
            img = np.array(self.toGray())
            #print(len(img))
            img_2 = Image.new("RGB", (self.width, self.length))
           # print(img[960, 960][0)
   # def asdasdasdd(self):
            for i in range(1, self.length):
               for j in range(1, self.width):
                    if (img[i, j][0] <= T):
                        img_2.putpixel((i, j), (0, 0, 0))
                    else:
                        pass
                    
                        #img_2.putpixel((i, j), (255, 255, 255))
                     #   reverse_im.putpixel((i, j), (255-r_list[NO], 255-g_list[NO], 255-b_list[NO]))    #将rgb转化为像素
                                               

  #          processName = fileName + "的二值化图, T=" + str(T)
#            plt.figure(processName)
 #           plt.imshow(img, cmap='gray')
   #         plt.axis('off')
            print('二值化耗时\t\t' + str(time.time() - start_time))
    #        plt.show()
            img_2.show()

if __name__ == '__main__':
        fileName = './lena.png'
        new_obj = im_obj(fileName)
#        new_obj.details()
#        new_obj.toGray()
#        new_obj.reverse()
#        T = new_obj.otsu()
        new_obj.do2(T=72)

        
 #       new_obj.gethist()
#        T = otsu(fileName)
#        do2(T, fileName)
#        fdxx(gray_im)
