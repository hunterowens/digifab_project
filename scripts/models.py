from sqlalchemy import *
from sqlalchemy.orm import *
from sqlalchemy.ext.declarative import *
from sqlalchemy.types import DateTime
import argparse
import os

Base = declarative_base()

db_user = os.environ.get("FABDB_USER")
db_url = os.environ.get("FABDB_URL")
db_pw = os.environ.get("FABDB_PW")
db_db = os.environ.get("FABDB_DB")

engine = create_engine("postgresql://"+db_user+":"+db_pw+"@"+db_url+"/"+db_db)

SessionMkr = sessionmaker()
SessionMkr.configure(bind=engine)
session = SessionMkr()

class UltraSonicReading(Base):
	__tablename__ = 'ultrasonic'
	id = Column(Integer, primary_key=True,autoincrement=True)
	room = Column(String(255))
	location = Column(String(255))
	timestamp = Column(DateTime)
	reading_30 = Column(Integer)
	reading_70 = Column(Integer)
	reading_110 = Column(Integer)
	reading_150 = Column(Integer)

if __name__ == "__main__":
	parser = argparse.ArgumentParser()
	parser.add_argument("-c", help="creates the tables in the db")
	args = parser.parse_args()
	if args.c:
		print "creating tables"
		SessionMkr = sessionmaker()
		SessionMkr.configure(bind=engine)
		session = SessionMkr()
		Base.metadata.create_all(engine)
		print "tables created"
