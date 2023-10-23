bus = smbus.SMBus(1)  # 创建一个smbus实例


def setup(Addr):
    global address
    address = Addr


def read(chn):
    if chn == 0:
        bus.write_byte(address, 0x40)
    if chn == 1:
        bus.write_byte(address, 0x41)
    if chn == 2:
        bus.write_byte(address, 0x42)
    if chn == 3:
        bus.write_byte(address, 0x43)
    bus.read_byte(address)
    return bus.read_byte(address)


def write(val):
    temp = val
    temp = int(temp)
    bus.write_byte_data(address, 0x40, temp)


if __name__ == "__main__":
    setup(0x48)
    while True:
        print
        '电位计   AIN0 = ', read(0)  # 电位计
        print
        '光敏电阻 AIN1 = ', read(1)  # 光敏电阻
        print
        '热敏电阻 AIN2 = ', read(2)  # 热敏电阻
    tmp = read(0)
    tmp = tmp * (255 - 125) / 255 + 125  # 125以下LED不会亮，所以将“0-255”转换为“125-255”，调节亮度时灯不会熄灭
    write(tmp)
    time.sleep(2)
