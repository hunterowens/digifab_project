import argparse
import serial

if __name__ == '__main__':
    parser = argparse.ArgumentParser(
        formatter_class=argparse.ArgumentDefaultsHelpFormatter
    )
    parser.add_argument('--serial', required=True, type=str,
    help="""
    	Where the serial port is. Should be in the form of /dev/cu.usbmodem1431 
    	or similar
    """)
    args = parser.parse_args()
    serial_port = args.serial
    ser = serial.Serial(serial_port, 9600)
    while True:
    	print ser.readline()
