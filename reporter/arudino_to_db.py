import serial
import time
ser = serial.Serial('/dev/cu.usbmodem1431', 9600)

while True:
	try:
		print ser.readline()
	except serial.serialutil.SerialException:
		print "error"
		time.sleep(1)

