#A script to generate data for the records with an X-Y record

library("RPostgreSQL")

training_data <- read.csv('./training_data.csv',header=T)

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

#fit the sample data
xfit <- lm(x ~ reading_30+reading_70+reading_110+reading_150,data=training_data)
yfit <- lm(y ~ reading_30+reading_70+reading_110+reading_150,data=training_data)

#make predictions
x_predictions <- predict(xfit,recorded_data)
y_predcitions <- predict(yfit,recorded_data)

#join the predictions and write to file. 
predictions <- cbind(x_predictions,y_predcitions)

write.table(predictions,"./predictions.csv",sep=",")