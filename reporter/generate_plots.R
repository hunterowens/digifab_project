library("ggplot2")

max = 100

train_graph <- read.csv('./training_data.csv',header=T)
qplot(x,y,data=train_graph,xmin = -max,xmax= max)

predictions <- read.csv('./predictions.csv',header=T)
qplot(x_predictions,y_predcitions,data=predictions, xmin = -max,xmax= max)