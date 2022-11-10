import time
import board
import neopixel
import random

pixel_pin = board.D18
num_pixels = 38
ORDER = neopixel.GRB

bilmatik_altin_kazandiran=[0,23]
seviye=[23,31]
hediye=[31,38]
zemin_rengi=[[95,22,87],[0,69,49],[100,0,60],[38,23,60],[84,69,52],[74,78,76],[20,37,29],[10,61,74],[44,89,35],[29,29,29]]

renk=0
oyun_durumu=0
soru_seviye=0
odul_cevap=2
odul_ver=2

#--------------RENKLER-------------------
bright_yellow=[95,22,87]	#f1dd38
dark_blue=[0,69,49]		#007cb0
pure_orange=[100,0,60]	 	#ff9900
moderate_green=[38,23,60]	#61993b
slightly_pink=[84,69,52]        #d584b1
grayish_blue=[74,78,76] 	#bdc3c7
very_dark_blue=[20,37,29]	#34495e
strong_cyan=[10,61,74]	  	#1abc9c
soft_blue=[44,89,35]	  	#7158e2
very_dark_gray=[29,29,29] 	#4b4b4b
#----------------------------------------

pixels = neopixel.NeoPixel(pixel_pin, num_pixels, brightness=0.2, auto_write=False,
                           pixel_order=ORDER)

def wheel(pos):
    if pos < 0 or pos > 255:
        r = g = b = 0
    elif pos < 85:
        r = int(pos * 3)
        g = int(255 - pos*3)
        b = 0
    elif pos < 170:
        pos -= 85
        r = int(255 - pos*3)
        g = 0
        b = int(pos*3)
    else:
        pos -= 170
        r = 0
        g = int(pos*3)
        b = int(255 - pos*3)
    return (r, g, b) if ORDER == neopixel.RGB or ORDER == neopixel.GRB else (r, g, b, 0)
 
#-----------------Gokkusagi animasyonu metodu-------------
def rainbow(first_start,end_stop):
    
    for j in range(255):
        for i in range(first_start,end_stop):
            pixel_index = (i * 256 // num_pixels) + j
            pixels[i] = wheel(pixel_index & 255)
        pixels.show()
        time.sleep(0.001)

#-----------------Heart animasyon metodu-----------
def heart(first_start,end_stop,set):

	for i in range(first_start,end_stop):
		pixels[i]=(set,0,0)
	time.sleep(0.09)
	pixels.show()


#-----------------Animasyon bölümü rengi ayarlama metodu-----------
def anime1(first_start,end_stop):
	
	for i in range (5):
		for h in range(first_start,end_stop):
			efect_number=random.randrange(0,100,1)
			pixel_index=h
			pixels[h]=wheel(pixel_index*efect_number& 255)
			time.sleep(0.01)
			pixels.show()
		

#-----------------Tur bölümü rengi ayarlama metodu----------- 
def tur(first_start,end_stop,level,game,state):
	if level==5 and game==1:
		if state==1:
			pixels[23]=(0,0,255)
			pixels[24]=(0,0,255)
		if state==0:
			pixels[23]=(255,0,0)
			pixels[24]=(255,0,0)
		if state==2:
			pixels[23]=(255,255,255)
			pixels[24]=(255,255,255)

		pixels[25]=(250,0,80)
		pixels[26]=(250,0,80)
		pixels[27]=(250,0,80)
		pixels[28]=(250,0,80)
		pixels[29]=(250,0,80)
		pixels[30]=(250,0,80)

		pixels[25]=(250,0,80)
		pixels[26]=(250,0,80)
		pixels[27]=(250,0,80)
		pixels[28]=(250,0,80)
		pixels[29]=(250,0,80)
		pixels[30]=(250,0,80)
	if level==10 and game==1:		
		if state==1:
			pixels[25]=(0,0,255)
			pixels[26]=(0,0,255)
		if state==0:
			pixels[25]=(255,0,0)
			pixels[26]=(255,0,0)
		if state==2:
			pixels[25]=(255,255,255)
			pixels[26]=(255,255,255)

		pixels[24]=(255,255,255)
		pixels[23]=(255,255,255)
		pixels[27]=(250,0,80)
		pixels[28]=(250,0,80)
		pixels[29]=(250,0,80)
		pixels[30]=(250,0,80)
	if level==15 and game==1:
		if state==1:
			pixels[27]=(0,0,255)
			pixels[28]=(0,0,255)
		if state==0:
			pixels[27]=(255,0,0)
			pixels[28]=(255,0,0)
		if state==2:
			pixels[27]=(255,255,255)
			pixels[28]=(255,255,255)

		pixels[26]=(255,255,255)
		pixels[25]=(255,255,255)
		pixels[24]=(255,255,255)
		pixels[23]=(255,255,255)
		pixels[29]=(250,0,80)
		pixels[30]=(250,0,80)
	if level==20 and game==1:
		if state==1:
			pixels[29]=(0,0,255)
			pixels[30]=(0,0,255)
		if state==0:
			pixels[29]=(255,0,0)
			pixels[30]=(255,0,0)	
		if state==2:
			pixels[29]=(255,255,255)
			pixels[30]=(255,255,255)
		
		pixels[26]=(255,255,255)
		pixels[25]=(255,255,255)
		pixels[24]=(255,255,255)
		pixels[23]=(255,255,255)
		pixels[27]=(255,255,255)
		pixels[28]=(255,255,255)
	if level==0 and game==1:
		pixels[23]=(250,0,80)
		pixels[24]=(250,0,80)
		pixels[25]=(250,0,80)
		pixels[26]=(250,0,80)
		pixels[27]=(250,0,80)
		pixels[28]=(250,0,80)
		pixels[29]=(250,0,80)
		pixels[30]=(250,0,80)
		
	if (level>0 or level<20) and game==0:	
		for i in range(first_start,end_stop):
			pixels[i]=(255,255,255)
			pixels.show()

#-----------------hediye bölümü rengi ayarlama metodu-----------
def gift(first_start,end_stop,state):
	if state==0:
		for i in range(first_start,end_stop):
			pixels[i]=(255,0,0)
	elif state==1:
		for i in range(first_start,end_stop):
			pixels[i]=(0,0,255)


	else:
		color_rand=random.randrange(0,4,1)
		for i in range(first_start,end_stop):
			if color_rand==0:
				pixels[i]=(84,52,69)
			elif color_rand==1:
				pixels[i]=(100,60,0)
			elif color_rand==2:
				pixels[i]=(0,49,69)
			elif color_rand==3:
				pixels[i]=(255,255,255)
			elif color_rand==4:
				pixels[i]=(95,87,22)
		pixels.show()
		time.sleep(0.4)

#--------------------zemin rengi ayarlama metodu------------------------	
def zemin(color,first_start,end_stop):
	for i in range(first_start,end_stop):
		pixels[i]=(color[0],color[1],color[2])
	pixels.show()
	
#------------------------durum[0] 1 ise oyun oynanıyor-------------------------
def calis():
	global oyun_durumu
	global renk
	global soru_seviye
	global odul_cevap
	global odul_ver
	
	#*********tur(first_start,end_stop,level,game,state)****************
	#level ->	oyundaki ödül soru sırası		(5-10-15-20)
	#game  ->	oyunda mıyız değilmiyiz			(0-1)
	#state ->	oyundaki soruyu doğrumu bildi yanlışmı	(0-1-2)
	#**************************************************************

	#********gift(first_start,end_stop,state)***********************
	#first_start -> pixel başlangıç noktası
	#end_stop    -> pixel bitiş noktası
	#state	     -> ödül aldı almadı rengi (0-1-2)
	#***************************************************************

	if oyun_durumu==1:
		zemin(zemin_rengi[renk],bilmatik_altin_kazandiran[0],bilmatik_altin_kazandiran[1])

		tur(seviye[0],seviye[1],soru_seviye,oyun_durumu,odul_cevap)

		gift(hediye[0],hediye[1],odul_ver)




#------------------------durum[0] 0 ise oyun oynanmıyor-----------------------------
	else:
		anime_random=random.randrange(0,3,1)
		if anime_random==0:
			anime1(bilmatik_altin_kazandiran[0],bilmatik_altin_kazandiran[1])
			tur(seviye[0],seviye[1],0,oyun_durumu,0)
			gift(hediye[0],hediye[1],2)
			
		elif anime_random==1:
			rainbow(bilmatik_altin_kazandiran[0],bilmatik_altin_kazandiran[1])
			tur(seviye[0],seviye[1],0,oyun_durumu,0)			
			gift(hediye[0],hediye[1],2)	

def soket(soket_oyun_durumu,soket_zemin_renk,soket_soru_seviyesi,soket_odul_cevap,soket_odul_ver):
	global oyun_durumu
	global renk
	global soru_seviye
	global odul_cevap
	global odul_ver

	oyun_durumu=soket_oyun_durumu
	renk=soket_zemin_renk
	soru_seviye=soket_soru_seviyesi
	odul_cevap=soket_odul_cevap
	odul_ver=soket_odul_ver

while True:
	#soket(oyundurumu, zeminrengi, soruseviyesi, ödül sorusucevabı, ödülüver)
	soket(1,3,5,1,1)
	calis()
	