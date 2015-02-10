# -*- coding: utf-8 -*-
import random
import time

__author__ = 'kduma'


import serial
import serialports


# print(serialports.serial_ports())
ser = serial.Serial("/dev/tty.usbmodem1411", 9600, timeout=0)
print ser.name

time.sleep(2)
ser.write("8888")
for i in range(0, 9999):
    # ser.write("%4d" % random.randrange(0,9999))
    ser.write("%4d" % input('podaj liczbę:'))
    time.sleep(0.2)
ser.close()