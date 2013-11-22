import serial
import time
import models
ser = serial.Serial('/dev/cu.usbmodem1431', 9600)

while True:
	try:
		print ser.readline()
		time.sleep(1)
	except serial.serialutil.SerialException:
		time.sleep(1)

