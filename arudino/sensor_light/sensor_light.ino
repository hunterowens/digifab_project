//Lights and Distance Sensing

const int pwPin = 7;
const int ledPin = A5;
long inches;

long pulse;

void setup() {
  Serial.begin(9600);
  pinMode(pwPin,INPUT);
  //pinMode(ledPin, OUTPUT);
}

void loop() {
  pulse = pulseIn(pwPin, HIGH);
  inches = pulse/147;
  if (inches > 255) {
    analogWrite(ledPin,255);
  }
  else {
    analogWrite(ledPin,inches);
  }
  Serial.println(inches);
}
