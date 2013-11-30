import argparse
import serial
from utils import parse_input

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
    parse_input("7,7,7,7")