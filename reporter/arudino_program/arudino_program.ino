//This is a way of generating the inputes from the 4 sensor decives into the 
// python script
// Author: Hunter Owens
// Date: 24/11/2013

const unsigned int pin30  = 1;
const unsigned int pin70  = 2;
const unsigned int pin110 = 3;
const unsigned int pin150 = 4;

//converts the reading into a cm value representing how far away the nearest
// obj is 
unsigned long convert(int val) {
  unsigned long res;
  res = (val / 147) * 2.54;
  return res;
}

void setup() { 
  //starts a serial connection 
  Serial.begin(9600);
}

void loop() {
  // res vars
  unsigned int reading30,reading70,reading110,reading150;
  unsigned long res30,res70,res110,res150;
  //set up the pins for input
  pinMode(pin30, INPUT);
  pinMode(pin70, INPUT);
  pinMode(pin110, INPUT);
  pinMode(pin150, INPUT);
  //record the readings
  reading30 = pulseIn(pin30,HIGH);
  reading70 = pulseIn(pin70,HIGH);
  reading110 = pulseIn(pin110,HIGH);
  reading150 = pulseIn(pin150,HIGH);
  //convert the readings
  res30 = convert(reading30);
  res70 = convert(reading70);
  res110 = convert(reading110);
  res150 = convert(reading150);
  //print the results
  Serial.print(res30);
  Serial.print(",");
  Serial.print(res70);
  Serial.print(",");
  Serial.print(res110);
  Serial.print(",");
  Serial.println(res150);
  //Wait 1 Second
  delay(1000);
}

  
