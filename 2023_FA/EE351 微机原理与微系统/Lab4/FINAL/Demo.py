import PCF8591 as ADC
import RPi.GPIO as GPIO
import time
import math

DO = 17
GPIO.setmode(GPIO.BCM)


def setup():
    ADC.setup(0x48)
    GPIO.setup(DO, GPIO.IN)


def loop():
    status = 1
    tmp = 1
    while True:
        analogVal = ADC.read(0)
        Vr = 5 * float(analogVal) / 255
        Rt = 10000 * Vr / (5 - Vr)
        temp = 1 / (((math.log(Rt / 10000)) / 3950) + (1 / (273.15 + 25)))
        temp = temp - 273.15
        print('temperature = ', temp, 'C')
        if temp > 33:
            tmp = 0;
        elif temp < 31:
            tmp = 1;
        time.sleep(0.5)


if __name__ == '__main__':
    try:
        setup()
        loop()
    except KeyboardInterrupt:
        pass
