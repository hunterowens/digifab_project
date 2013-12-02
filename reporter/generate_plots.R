library("ggplot2")

max = 100

png("./training_graph.png")
train_graph <- read.csv('./training_data.csv',header=T)
qplot(x,y,data=train_graph,xmin = -max,xmax= max)
dev.off()

png("./predictions_graph.png")
predictions <- read.csv('./predictions.csv',header=T)
qplot(x_predictions,y_predcitions,data=predictions, xmin = -max,xmax= max)
dev.off()