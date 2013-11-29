import serial
import time
from models import UltraSonicReading
import datetime
from sqlalchemy import *
from sqlalchemy.orm import *
from sqlalchemy.ext.declarative import *
import os
import sys, traceback
import argparse
import logging

Base = declarative_base()

db_user = os.environ.get("FABDB_USER")
db_url = os.environ.get("FABDB_URL")
db_pw = os.environ.get("FABDB_PW")
db_db = os.environ.get("FABDB_DB")

engine = create_engine("postgresql://"+db_user+":"+db_pw+"@"+db_url+"/"+db_db)

SessionMkr = sessionmaker()
SessionMkr.configure(bind=engine)
session = SessionMkr()

## parses the input from the Arudino 
## assumes that the order in teh string is 30,70,110,150
def parse_input(i):
	args = i.split(",")
	val_list = []
	for arg in args:
		if arg != '':
			val_list.append(int(arg))
	return val_list

## loads input into DB
def load_input(val_list):
	reading = UltraSonicReading(room=room_in,location=loc,timestamp=datetime.datetime.now(), \
		reading_30=val_list[0], \
		reading_70=val_list[1], \
		reading_110=val_list[2], \
		reading_150=val_list[3] \
		)
	session.add(reading)
	session.commit()


## Main Loop
if __name__ == '__main__':
    parser = argparse.ArgumentParser(
        formatter_class=argparse.ArgumentDefaultsHelpFormatter
    )
    parser.add_argument('--room', required=True, type=str,
    help="""
        Name of the Room you are using
    """)
    parser.add_argument('--location', required=True, type=str,
    help="""
        Where within the room the sensor has been placed
    """)
    parser.add_argument('--serial', required=True, type=str,
    help="""
    	Where the serial port is. Should be in the form of /dev/cu.usbmodem1431 
    	or similar
    """)
    args = parser.parse_args()
    room_in = args.room
    loc = args.location
    serial_port = args.serial


## Serial and Logging Stufff
ser = serial.Serial(serial_port, 9600)
logging.basicConfig(filename='arudino_recorder.log',level=logging.DEBUG)

while True:
 	try:
 		load_input(parse_input(ser.readline()))
 	except serial.serialutil.SerialException:
 	 	logging.warning("Arudino Failed to Report Data")
 	 	pass
 	except IndexError:
		logging.warning("Bad Input Error")
		pass
	except sqlalchemy.exc.*:
		logging.warning("SQL Alchemy Error")
		pass
	else:
 		logging.info(sys.exc_info()[0])
		pass
