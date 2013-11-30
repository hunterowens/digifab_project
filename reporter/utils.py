import serial
import time
from models import UltraSonicReading
import datetime
import sqlalchemy
from sqlalchemy import *
from sqlalchemy.orm import *
from sqlalchemy.ext.declarative import *

## parses the input from the Arudino 
## assumes that the order in teh string is 30,70,110,150
def parse_input(i):
	args = i.split(",")
	val_list = []
	for arg in args:
		if arg != '':
			val_list.append(float(arg))
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
