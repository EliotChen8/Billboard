import smbus  # 在程序中导入“smbus”模块
import time

bus = smbus.SMBus(1)  # 创建一个smbus实例


# 初始化外设
def setup(Addr):
    global address
    address = Addr


# 读出程序 根据输入参数选择读出频道
def read(chn):  # channel
    if chn == 0:
        bus.write_byte(address, 0x40)  # 发送一个控制字节到设备
    if chn == 1:
        bus.write_byte(address, 0x41)
    if chn == 2:
        bus.write_byte(address, 0x42)
    if chn == 3:
        bus.write_byte(address, 0x43)
    bus.read_byte(address)  # 从设备读取单个字节，而不指定设备寄存器。
    return bus.read_byte(address)  # 返回某通道输入的模拟值A/D转换后的数字值


def write(val):
    temp = val  # 将字符串值移动到temp
    temp = int(temp)  # 将字符串改为整数类型
    # print temp to see on terminal else comment out
    bus.write_byte_data(address, 0x40, temp)


def loop():
    while True:
        print
        ADC.read(0)
        # 打印电位计电压大小A/D转换后的数字值（从AIN0借口输入的）
        # 范围是0~255,0时LED灯熄灭，255时灯最亮
        ADC.write(ADC.read(0))
    # 将0通道输入的电位计电压数字值转化成模拟值从AOUT输出


# 给LED灯提供电源VCC输入
def destroy():
    ADC.write(0)


# 写入字节数据，将数字值转化成模拟值从AOUT输出
if __name__ == "__main__":
    try:
        setup(0x48)
        loop()
    except KeyboardInterrupt:
        destroy()
