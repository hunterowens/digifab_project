import serial
import time
from models import UltraSonicReading
import datetime
from sqlalchemy import *
from sqlalchemy.orm import *
from sqlalchemy.ext.declarative import *
import os
import sys, traceback

Base = declarative_base()

db_user = os.environ.get("FABDB_USER")
db_url = os.environ.get("FABDB_URL")
db_pw = os.environ.get("FABDB_PW")
db_db = os.environ.get("FABDB_DB")

engine = create_engine("postgresql://"+db_user+":"+db_pw+"@"+db_url+"/"+db_db)

SessionMkr = sessionmaker()
SessionMkr.configure(bind=engine)
session = SessionMkr()


# ser = serial.Serial('/dev/cu.usbmodem1431', 9600)

# while True:
# 	try:
# 		print ser.readline()
# 		time.sleep(1)
# 	except serial.serialutil.SerialException:
# 		time.sleep(1)


## parses the input from the Arudino 
## assumes that the order in teh string is 30,70,110,150
def parse_input(i):
	args = i.split(",")
	val_list = []
	for arg in args:
		val_list.append(int(arg))
	return val_list


def load_input(val_list):
	reading = UltraSonicReading(room="test",location="another_test",timestamp=datetime.datetime.now(), \
		reading_30=val_list[0], \
		reading_70=val_list[1], \
		reading_110=val_list[2], \
		reading_150=val_list[3] \
		)
	session.add(reading)
	session.commit()



if __name__ == '__main__':
	load_input(parse_input("3,5,67,24"))