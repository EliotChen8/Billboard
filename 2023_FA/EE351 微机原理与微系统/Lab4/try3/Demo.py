#!/usr/bin/env python
import PCF8591 as ADC
import RPi.GPIO as GPIO
import time
import math

DO = 17
GPIO.setmode(GPIO.BCM)


def setup():
    ADC.setup(0x48)
    GPIO.setup(DO, GPIO.IN)


def Print(x):
    if x == 1:
        print
        ''
        print
        '***********'
        print
        '* Better~ *'
        print
        '***********'
        print
        ''
    if x == 0:
        print
        ''
        print
        '************'
        print
        '* Too Hot! *'
        print
        '************'
        print
        ''


def loop():
    status = 1
    tmp = 1
    while True:
        analogVal = ADC.read(0)  # 温度传感器模拟输出A/D转化后的数字值
        Vr = 5 * float(analogVal) / 255  # Vr为数字值转化为热敏电阻的原始模拟电压值
        Rt = 10000 * Vr / (5 - Vr)
        # Rt是热敏电阻在T1温度下的阻值,10000=10k为与热敏电阻串联的电阻的阻值
        # 查阅传感器电路图知，因为是串联，所以电流值相等 Vr/Rt=(5-Vr)/10000

        temp = 1 / (((math.log(Rt / 10000)) / 3950) + (1 / (273.15 + 25)))
        # T1=1/（ln（Rt/R）/B+1/T2） 对应的摄氏温度t=T1-273.15
        # R=10k=10000 B=3950 T2=(273.15+25)
        temp = temp - 273.15
        print
        'temperature = ', temp, 'C'

        if temp > 33:
            tmp = 0;
        elif temp < 31:
            tmp = 1;

        if tmp != status:
            Print(tmp)
            status = tmp

        time.sleep(0.2)


if __name__ == '__main__':
    try:
        setup()
        loop()
    except KeyboardInterrupt:
        pass
