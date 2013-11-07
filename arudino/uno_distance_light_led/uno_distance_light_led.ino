// using the maxsonar quick start http://www.adafruit.com
// http://www.adafruit.com/index.php?main_page=product_info&cPath=35&products_id=172

int sonarPin = 0; //pin connected to analog out on maxsonar sensor
int lightPin = 13; 
int inchesAway; 

void setup() {
  pinMode(lightPin, OUTPUT);

}

void loop() {
  inchesAway = analogRead(sonarPin) /2;
 
  if (inchesAway < 24) { // if something is 24 inches then lightPin HIGH
    digitalWrite(lightPin, HIGH);
  }
  else {
    digitalWrite(lightPin, LOW); // set it to low if greater than 24
  }
}
