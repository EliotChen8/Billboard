import smbus
import time

bus = smbus.SMBus(1)


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


if __name__ == "__main__":
    setup(0x48)
    while True:
        tmp = read(0)
        tmp = tmp * (255 - 125) / 255 + 125
        write(tmp)
