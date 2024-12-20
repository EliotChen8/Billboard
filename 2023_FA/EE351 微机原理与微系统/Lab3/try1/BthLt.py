#!/usr/bin/env python
import PCF8591 as ADC
import time


def setup():
    ADC.setup(0x48)


def loop():
    while True:
        # 打印电位计电压大小A/D转换后的数字值（从AIN0借口输入的）
        # 范围是0~255,0时LED灯熄灭，255时灯最亮
        tmp = 0
        if tmp < 255
            out = tmp * (255 - 125) / 255 + 125
            ADC.write(out)
            tmp = tmp + 5
            time.sleep(0.05)
        else
            tmp = 0


# 给LED灯提供电源VCC输入
def destroy():
    ADC.write(0)


if __name__ == "__main__":
    try:
        setup()
        loop()
    except KeyboardInterrupt:
        destroy()
