#Notes

This section contains a series of thoughts and notes on the project - essentially, a write up. 

## Intro
This project set out to capture movement in the build environment. That is, how can something reprent in how people move about the room. We know how people use websites (a la Google Analytics) but not how people use the built environment. 

##False Start: Cameras. 
Initally, the thought was to use a camera. Using the (OpenCV)[http://opencv.org/] Library and the Python Bindings, I built a python script that recongized when a person entered the frame. However, this provided a serious problem.

Depth Perception.

That is cameras provide person recognition, but their lack of depth perception proved too limiting. An attempt was made to divide quadrants and create a network of cameras, but that appeared to be overengineering on a simple problem. The sensors allowed depth perception with the addition of some statistical noise. 

## The Build: Requirements and Limitations

## The Data: Understand and Mapping It
## The Model: Justification and Results
## Future Work:
