import io
from PIL import Image
from PyQt5.QtGui import QImage
from PyQt5.QtCore import QBuffer

def func1():
	img = QImage("lena.jpeg")
	buffer = QBuffer()
	buffer.open(QBuffer.ReadWrite)
	img.save(buffer, "PNG")
	pil_im = Image.open(io.BytesIO(buffer.data()))
	print(type(img))
	print(type(pil_im))
	pil_im.show()

def func2():
	pil_im = Image.open('./lena.jpeg')
	img = QImage()	
	buffer = QBuffer()
	buffer.open(QBuffer.ReadWrite)
	img = Qimage(io.BytesIO(buffer.data()))
	print(type(img))
	print(type(pil_im))
	


if __name__ == '__main__':
	func1()
	func2()