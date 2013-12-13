Panopticon
===============

Learning how people interact with the build environment. A project for the Digital Fabrication Class at the University of Chicago. 

## About
This project relies on 4 [Maxbotix EZ-1 High Preformance Rangefinders](http://www.maxbotix.com/documents/MB1010_Datasheet.pdf), a Arudino and a Raspberry Pi or other computer with a USB port. Having a 3D printer will be helpful in building the models. It also requires some sort of sql database (I used PostgresQL) for storing the data. 

The sensors range from 6-254 inches and report back a single reading, that is the distance between the sensor and the next nearest object. By arranging these in a half-circle pattern, we can detect how objects are moving throughout a room.

`/build` contains the .stl model for the sensor base. 

`/scripts` contains the python and R scripts for loading the data into the database and creating graphs/visualization and running the statistical model. 

`/datavis` contains output about the project generated so far.

`/arudino_program` contains the program to load onto an arudino to generate the data. Make sure to change the pins to reflect the correct values for your setup.

## Usage / Data Collection
=============

1. Assemble the base and wire the sensors to an aruduino. Hook the arudino into a computer with an internet connection. I recommend a raspberry pi or beagle board. 
2. Setup youre environment - set env vars for the database connection and determine the location of the serial port on your machine. It is typically `/dev/ttySOMETHING`. 
3. Use a virtualenv to install the requirements in `scripts/requirements.txt`. 
4. Run `models.py -c create` to create the database tables.
5. Build a training dataset. Empty the room and lay down a grid (I used masking tape). Have one person stand at points and the run the `generate_sample_data.py --x [num] --y [num] --serial` script to generate a good set of training data. The X and Y values should refer to where the person is in teh room, with the mount being [0,0] and Y extending in the positive direction. 
6. Run the `arudino_to_db.py` script to start collecting data. 


## Model / Graphing Data
=========
This section is under active development. Please check back again later. 
## License
=========
MIT - See LICENSE for Details.
## Contact
==========
This project came about because Ian Foster and Rick Stevens let me play around with sensors and an arudino. Questions can be directed to howens@uchicago.edu. 