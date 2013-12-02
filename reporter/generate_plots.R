library("ggplot2")


train_graph <- read.csv('./training_data.csv',header=T)
qplot(x,y,data=train_graph)

predictions <- read.csv('./predictions.csv',header=T)
qplot(x_predictions,y_predcitions,data=predictions)