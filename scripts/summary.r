#A script to generate summary statics for the room

library("RPostgreSQL")


#get env Variables
con_vars = Sys.getenv(c("FABDB_USER", "FABDB_URL", "FABDB_PW", "FABDB_DB"))

#Fetch the data
drv <- dbDriver("PostgreSQL")   ## loads the PostgreSQL driver
con <- dbConnect(drv, 
	dbname=con_vars["FABDB_DB"],
	user=con_vars["FABDB_USER"],
	password=con_vars["FABDB_PW"],
	port=5432,
	host=con_vars["FABDB_URL"])   ## Open a connection 
rs <- dbSendQuery(con, "SELECT * FROM ultrasonic WHERE room = 'HAL';")   ## Submits a statement
recorded_data <- fetch(rs,n=-1)
summary(recorded_data[5])
summary(recorded_data[6])
summary(recorded_data[7])
summary(recorded_data[8])