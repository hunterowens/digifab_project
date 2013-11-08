// A quick way of print output from a maxsonar sensor to console

int sonarPin = 0; //pin connected to analog out on maxsonar sensor
int lightPin = 13; 
int inchesAway; 

void setup() {
  pinMode(lightPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  inchesAway = analogRead(sonarPin) / 2; // read the input
  // Loop that writes value, in inches, to output stream
  if (inchesAway > 0) {
    Serial.println(inchesAway);
  }
  // Does the Lighting of hte LED
  
  if (inchesAway < 24) { // if something is 24 inches then lightPin HIGH
    digitalWrite(lightPin, HIGH);
  }
  else {
    digitalWrite(lightPin, LOW); // set it to low if greater than 24
  }
  delay(1000);
}
  
