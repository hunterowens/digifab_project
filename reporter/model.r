library("RPostgreSQL")

training_data <- read.csv('./training_data.csv',header=T)

con_vars = Sys.getenv(c("FABDB_USER", "FABDB_URL", "FABDB_PW", "FABDB_DB"))


drv <- dbDriver("PostgreSQL")   ## loads the PostgreSQL driver
con <- dbConnect(drv, 
	dbname=con_vars["FABDB_DB"],
	user=con_vars["FABDB_USER"],
	password=con_vars["FABDB_PW"],
	port=5432,host=con_vars["FABDB_URL"])   ## Open a connection 
rs <- dbSendQuery(con, "select * from ultrasonic WHERE room = 'HAL' LIMIT 10;")   ## Submits a statement

recorded_data <- fetch(rs,n=-1)



