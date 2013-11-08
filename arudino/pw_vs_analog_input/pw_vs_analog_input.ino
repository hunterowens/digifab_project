//Testing Maxsonar inputs PW vs Analog

const int pwPin = 7;
const int anPin = 0;
int avgrange=60;
int sum=0;//Create sum variable so it can be averaged
long pulse, inches_pw, anVolt, inches_analog;

void setup() {
  Serial.begin(9600);
  pinMode(pwPin, INPUT);
}

void loop() {
  //PW Reading
  pulse = pulseIn(pwPin, HIGH);
  //147uS per inch
  inches_pw = pulse/147;
  //change inches to centimetres
  //Now for the pw code
  
   //MaxSonar Analog reads are known to be very sensitive. See the Arduino forum for more information.
  //A simple fix is to average out a sample of n readings to get a more consistant reading.\\ 
  //Even with averaging I still find it to be less accurate than the pw method.\\ 
  //This loop gets 60 reads and averages them

  for(int i = 0; i < avgrange ; i++)
  {
    //Used to read in the analog voltage output that is being sent by the MaxSonar device.
    //Scale factor is (Vcc/512) per inch. A 5V supply yields ~9.8mV/in
    //Arduino analog pin goes from 0 to 1024, so the value has to be divided by 2 to get the actual inches
    anVolt = analogRead(anPin)/2;
    sum += anVolt;
    delay(10);
  }  
  inches_analog = sum/avgrange;
  Serial.print("PW: ");
  Serial.print(inches_pw);
  Serial.print(" | ");
  Serial.print("Analog: ");
  Serial.println(inches_analog);
  delay(500);
}
