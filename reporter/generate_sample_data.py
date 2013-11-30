import argparse
import serial
from utils import parse_input
import csv
import time

if __name__ == '__main__':
    parser = argparse.ArgumentParser(
        formatter_class=argparse.ArgumentDefaultsHelpFormatter
    )
    parser.add_argument('--serial', required=True, type=str,
    help="""
    	Where the serial port is. Should be in the form of /dev/cu.usbmodem1431 
    	or similar
    """)
    parser.add_argument('--x', required=True, type=float,
    help="""
        X value of person position
        """)
    parser.add_argument('--y', required=True, type=float,
    help="""
        Y value of person position
        """)
    args = parser.parse_args()
    serial_port = args.serial
    x = args.x
    y = args.y
    ser = serial.Serial(serial_port, 9600)
    time.sleep(2)
    while True:
        print ser.readline()
        val = ser.readline()
        time.sleep(1)
        break
    val_list = parse_input(val)
    with open('training_data.csv', 'ab') as csvfile:
        spamwriter = csv.writer(csvfile, delimiter=',',
                            quotechar='"', quoting=csv.QUOTE_MINIMAL)
        spamwriter.writerow([x,y,val_list])
