//This is a way of generating the inputes from the 4 sensor decives into the 
// python script
// Author: Hunter Owens
// Date: 24/11/2013
const unsigned int pin30  = 2;
const unsigned int pin70  = 3;
const unsigned int pin110 = 4;
const unsigned int pin150 = 5;

//converts the reading into a cm value representing how far away the nearest
// obj is 
//double convert(double val) {
  //double res;
  //res = (val / 147) * 2.54;
  //return res;
//}

const unsigned int numReadings = 10; // number of readings per second 

void setup() { 
  //starts a serial connection 
  Serial.begin(9600);
}


// res vars
double reading30,reading70,reading110,reading150;
double sum30, sum70, sum110, sum150;
double avg30, avg70, avg110, avg150;

void loop() {

  
  //set up the pins for input
  pinMode(pin30, INPUT);
  pinMode(pin70, INPUT);
  pinMode(pin110, INPUT);
  pinMode(pin150, INPUT);
  
  //record the readings and then average them. 
  for (int i = 0; i < numReadings; i++) {
    //take the readings
    reading30 = pulseIn(pin30,HIGH);
    reading70 = pulseIn(pin70,HIGH);
    reading110 = pulseIn(pin110,HIGH);
    reading150 = pulseIn(pin150,HIGH);
    //convert the readings
    sum30 += ((reading30 / 147) * 2.54);
    sum70 += ((reading70 / 147) * 2.54);
    sum110 += ((reading110 / 147) * 2.54);
    sum150 += ((reading150 / 147) * 2.54);
    // wait to take next reading number of readings
    delay(1000/numReadings);  
   }
   
   // Avg the readings
   avg30 = sum30 / numReadings;
   avg70 = sum70 / numReadings;
   avg110 = sum110 / numReadings;
   avg150 = sum150 / numReadings;

 
   //Average the readings 
   //print the results
   Serial.print(avg30);
   Serial.print(",");
   Serial.print(avg70);
   Serial.print(",");
   Serial.print(avg110);
   Serial.print(",");
   Serial.println(avg150);
   
   // reset the variables to 0
   // res vars
  reading30 = reading70 = reading110 = reading150 = 0;
  sum30 = sum70 = sum110 = sum150 = 0;
  avg30 = avg70 = avg110 = avg150 = 0;
}

  
