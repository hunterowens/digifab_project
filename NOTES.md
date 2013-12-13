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
The piece of software is the Arudino  

## The Data: Understand and Mapping It
## The Model: Justification and Results
## Future Work:
