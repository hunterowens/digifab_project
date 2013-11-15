from sqlalchemy import *
from sqlalchemy.orm import *
from sqlalchemy.ext.declarative import *
import Datetime

Base = declarative_base()

Class UltraSonicReading(Base):
	__tablename__ = 'ultrasonic'
	id = Column(uuid, primary_key=True)
	room = Column(String(255))
	location = Column(String(255))
	timestamp = Column(Datetime)
	value = Column(Integer)
	default_value = Column(Integer)
