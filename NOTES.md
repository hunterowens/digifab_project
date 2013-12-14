#Notes

This section contains a series of thoughts and notes on the project - essentially, a write up. 

## Intro
This project set out to capture movement in the build environment. That is, how can something reprent in how people move about the room. We know how people use websites (a la Google Analytics) but not how people use the built environment. 

##False Start: Cameras. 
Initally, the thought was to use a camera. Using the (OpenCV)[http://opencv.org/] Library and the Python Bindings, I built a python script that recongized when a person entered the frame. However, this provided a serious problem.

Depth Perception.

That is cameras provide person recognition, but their lack of depth perception proved too limiting. An attempt was made to divide quadrants and create a network of cameras, but that appeared to be overengineering on a simple problem. The sensors allowed depth perception with the addition of some statistical noise. 

## The Build: Requirements and Limitations
### Hardware
Once the distance sensors had decided on, it was time to create the build. Initally, the though was to have the sensors in different places. However, a suggestion from Professor Stevens provided that using the sensors all at an angle would provide a field of vision that can be used to monitor activity. 

<img src="https://github.com/hunterowens/digifab_project/raw/gh-pages/model.png" width="400px" style="display: block;
    margin-left: auto;
    margin-right: auto;">
    
Each Matbotix EZ1 Sensor has a range between 6-256 inches. From approx 24 inches away, it sensors things in a approx 30 inch circuference cone between those two areas. Using 4 sesnors, it is possible to build a reasonable coverage map for things. 

The Base is a series of measured holes that fit the sensors at 30,70,110, & 150 degreed angles (measured from center). This creates the ideal semi-circle field of 'vision'. The Base can be built using any 3D printer that can print STLs. I used a Makerbot 2. The Model is found in `/build`. 

To wire sensors, you'll need to connect each sensor to the GND, 5V out and a digital pin on the arduino. Solder those to the 5V, GND, and Pulse Width holes on the sensor. The pulse with is (147uS/inch). 

This measurement actually explains how this sensors work, which is sending out an sound pulse and listenign for the return. The sensors are intersting things to work with and provide a wide range of semi-accurate data.

### Software
The piece of software is the Arudino program that runs on the arudino itself. It output 4 common seperate values that are the readings from each sensor. The reported readings are an average of 10 readings made by the sensors themself. Increasing above 10 slowed down the reporting to far less than once per second, which is the ideal rate. 

Next a Python Script was build to shove the data into a PostgresQL database on the Amazon Cloud. A Rasberry Pi was the ideal device to run the connection between the two. 

## The Data: Understand and Mapping It

Every Second, the system collects a piece of data like this. 

```
id          | 445
room        | HAL
location    | East_Wall
timestamp   | 2013-11-30 20:06:26.138436
reading_30  | 175
reading_70  | 277
reading_110 | 156
reading_150 | 140
```
Each reading represents the distance to the nearest point seen in each sensors field of vision. Do this 101,918 times and and you have what I like to call a dataset. 

Summaries of each Reading:

```
   reading_30   
 Min.   : 27.0  
 1st Qu.:198.0  
 Median :306.0  
 Mean   :299.3  
 3rd Qu.:404.0  
 Max.   :631.0  
 
   reading_70 
 Min.   : 17  
 1st Qu.: 67  
 Median :156  
 Mean   :167  
 3rd Qu.:248  
 Max.   :435  
 
  reading_110 
    
 Min.   : 14.0  
 1st Qu.: 23.0  
 Median :165.0  
 Mean   :145.3  
 3rd Qu.:210.0  
 Max.   :504.0  
 
  reading_150   
 Min.   : 16.0  
 1st Qu.:125.0  
 Median :140.0  
 Mean   :154.4  
 3rd Qu.:168.0  
 Max.   :598.0 
 ```



## The Model: Justification and Results
In order to turn the readings into data, we needed a model. 
 
Rather than try and deduce and a statistical model, I was able to use linear regession using a simple inutitive idea that led to good results. The distances between the sensor and the sensor reading represent two point on a triangle. Since we also know the angle, we can then use `sin()` and `cos()` to determine the phyiscal x-y value in terms of distance. 

To start, generating a training dataset is helpful 

<img src="https://github.com/hunterowens/digifab_project/raw/gh-pages/training_graph.png" width="500px" style="display: block;
    margin-left: auto;
    margin-right: auto;"/>
	    
*0,0 is the location of the sensor mount. Distance is in inches.*

    
This is a bad training dataset, seeing as it only influences the 30/70 degree sensors while introducing the 110,150 ones as noise. Yet, here is the model.

```
//fit the sample data
xfit <- lm(x ~ reading_30+reading_70+reading_110+reading_150,data=training_data)
yfit <- lm(y ~ reading_30+reading_70+reading_110+reading_150,data=training_data)

//make predictions
x_predictions <- predict(xfit,recorded_data)
y_predcitions <- predict(yfit,recorded_data) 
```

This model yields this graph.

<img src="https://github.com/hunterowens/digifab_project/raw/gh-pages/predictions_graph.png" width="500px" style="display: block;
    margin-left: auto;
    margin-right: auto;"/>

*0,0 is the location of the sensor mount. Distance is in inches.*
    
However, what is interesting is the clustering of predictions right in front of the sensor. Most predictions cluster because very little activity was happening the in HAL. 

## Future Work:
There are several directions in which I'd like to take the project. 

1) Improve the Sensors and Improve the Model. This option is basically about following through a bit more with the current setup. 

2) Use a Less Noisy Room. Would Generate Better Data

3) Know that I understand quite a bit more about how distance sensing works by working with these low level sensor work, I would be interested in using a Kinect or Asus ActionX2 to produce better data and cooler visualizations. 

This project has been all about using embedded small systems that are now possible for cheap given some of the innovations discussed in the course. The idea of embedded systems telling us how we interact with the built-environment is a problem that I think will be investegated quite a lot in the near future. 