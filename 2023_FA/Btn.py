#!/usr/bin/env python
import RPi.GPIO as GPIO

BtnPin = 11
Rpin   = 12
Gpin   = 13

def setup():
	GPIO.setmode(GPIO.BOARD)       # Numbers GPIOs by physical location
	GPIO.setup(Gpin, GPIO.OUT)     # Set Green Led Pin mode to output
	GPIO.setup(Rpin, GPIO.OUT)     # Set Red Led Pin mode to output
	GPIO.setup(BtnPin, GPIO.IN, pull_up_down=GPIO.PUD_UP)    # Set BtnPin's mode is input, and pull up to high level(3.3V)
	GPIO.add_event_detect(BtnPin, GPIO.BOTH, callback=detect, bouncetime=200)

def Led(x):         #控制双色LED灯闪烁的函数
	if x == 0:
		GPIO.output(Rpin, 1)  #红灯亮
		GPIO.output(Gpin, 0)  #绿灯灭
	if x == 1:
		GPIO.output(Rpin, 0)  #红灯灭
		GPIO.output(Gpin, 1)  #绿灯亮

def Print(x):        #打印按键是否按下的提示消息
	if x == 0:
		print '    ***********************'
		print '    *   Button is down!   *'
		print '    ***********************'
	elif x == 1:
		print '    ***********************'
		print '    *   Button is up !   *'
		print '    ***********************'

def detect(chn):
	Led(GPIO.input(BtnPin))    #控制双色LED灯闪烁
	Print(GPIO.input(BtnPin))  #打印按键是否按下的提示消息

def loop():
	while True:
	pass  #pass 不做任何事情，一般用做占位语句。

def destroy():
	GPIO.output(Gpin, GPIO.LOW)       # Green led off
	GPIO.output(Rpin, GPIO.LOW)       # Red led off
	GPIO.cleanup()                    # Release resource

if __name__ == '__main__':     # 主程序入口
	setup()
	try:
		loop()
	except KeyboardInterrupt:  #  'Ctrl+C' 
		destroy()
