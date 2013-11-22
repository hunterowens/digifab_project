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



def parse_input(i):
	args = i.split()
	for arg in args:
		int(arg)
	print args


if __name__ == '__main__':
	parse_input("3,5,67,24")