//A basic tripwire using PW input on a MaxSonar Sensor

const int pwPin = 7;
const int ledPin = 13;
long pulse, inches;
long default_len;

void setup() {
  Serial.begin(9600);
  pinMode(pwPin,INPUT);
  pulse = pulseIn(pwPin,HIGH);
  default_len = pulse / 147;
  //LED Setup
  pinMode(ledPin, OUTPUT);
  Serial.println(default_len);
}

void loop() {
  pulse = pulseIn(pwPin,HIGH);
  inches = pulse/147;
  if (inches < default_len) {
    digitalWrite(ledPin,HIGH);
  }
  else {
    digitalWrite(ledPin,LOW);
  }
  Serial.println(inches);
}
