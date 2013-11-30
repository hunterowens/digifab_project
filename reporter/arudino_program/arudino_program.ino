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
float convert(float val) {
  float res;
  res = (val / 147) * 2.54;
  return res;
}

const unsigned int numReadings = 10; // number of readings per second 

void setup() { 
  //starts a serial connection 
  Serial.begin(9600);
}

void loop() {
  // res vars
  float reading30[numReadings],reading70[numReadings],reading110[numReadings],reading150[numReadings];
  float res30[numReadings],res70[numReadings],res110[numReadings],res150[numReadings];
  float sum30, sum70, sum110, sum150;
  float avg30, avg70, avg110, avg150;
  
  //set up the pins for input
  pinMode(pin30, INPUT);
  pinMode(pin70, INPUT);
  pinMode(pin110, INPUT);
  pinMode(pin150, INPUT);
  
  //record the readings and then average them. 
  for (int i = 0; i < numReadings; i++) {
    //take the readings
    reading30[i] = pulseIn(pin30,HIGH);
    reading70[i] = pulseIn(pin70,HIGH);
    reading110[i] = pulseIn(pin110,HIGH);
    reading150[i] = pulseIn(pin150,HIGH);
    //convert the readings
    res30[i] = convert(reading30[i]);
    res70[i] = convert(reading70[i]);
    res110[i] = convert(reading110[i]);
    res150[i] = convert(reading150[i]);
    // wait to take next reading number of readings
    delay(1000/numReadings);  
   }
   //Sum the readings
   for (int j = 0; j < numReadings; j++) {
     sum30 += res30[j];
     sum70 += res70[j];
     sum110 += res110[j];
     sum150 += res150[j];
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
}

  
