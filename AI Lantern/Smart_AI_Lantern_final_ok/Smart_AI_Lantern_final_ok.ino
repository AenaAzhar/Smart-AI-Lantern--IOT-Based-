#include <RBDdimmer.h>//
//#define USE_SERIAL  SerialUSB //Serial for boards whith USB serial port
#define USE_SERIAL  Serial
#define outputPin  12 
#define zerocross  2 // for boards with CHANGEBLE input pins
//dimmerLamp dimmer(outputPin, zerocross); //initialase port for dimmer for ESP8266, ESP32, Arduino due boards
dimmerLamp dimmer(outputPin); //initialase port for dimmer for MEGA, Leonardo, UNO, Arduino M0, Arduino Zero
int outVal = 0;
const int analogInPin = A0;
int sensorValue = 0;

String incomingString;
const int Rled= 5,Gled= 6,Bled= 7; 

int ledPin = 13;                // choose the pin for the LED
int inputPin = 8;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status
 int relay=11;


void setup() {
  USE_SERIAL.begin(9600);
  pinMode(Rled, OUTPUT);
  pinMode(Gled, OUTPUT);
  pinMode(Bled, OUTPUT);
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare sensor as input
  pinMode(relay, OUTPUT);
  digitalWrite(Rled, LOW);
  digitalWrite(Gled, LOW);
  digitalWrite(Bled, LOW);


  dimmer.begin(NORMAL_MODE, ON); //dimmer initialisation: name.begin(MODE, STATE) 

}

void loop() 
{
   sensorValue = analogRead(analogInPin);
  //outVal = map(analogRead(0), 1, 1024, 0, 100); // analogRead(analog_pin), min_analog, max_analog, 100%, 0%);
  outVal = map(sensorValue, 500, 1023, 0, 100);
 // USE_SERIAL.println(outVal); 
  dimmer.setPower(outVal); // name.setPower(0%-100%)
 val = digitalRead(inputPin);

if (val == HIGH)	// check if the input is HIGH
  {            
    digitalWrite(ledPin, HIGH);  // turn LED ON
    digitalWrite(relay, LOW); 
	
    if (pirState == LOW) 
	{
      Serial.println("Motion detected!");	// print on output change
      pirState = HIGH;
    }
  } 
  else 
  {
    digitalWrite(ledPin, LOW); // turn LED OFF
	  digitalWrite(relay, HIGH); 
    if (pirState == HIGH)
	{
      Serial.println("Motion ended!");	// print on output change
      pirState = LOW;
    }
  }

if (Serial.available() > 0) {
    // read the incoming string:
    incomingString = Serial.readString();
    // prints the received data
    Serial.print("I received: ");
    Serial.println(incomingString);
 int indexR = incomingString.indexOf("red");
  int indexG = incomingString.indexOf("green");
 int indexB = incomingString.indexOf("blue");
   if(indexR>=0){
    Serial.print("Comparison is: ");
    Serial.println("Red");
        digitalWrite(Rled, HIGH);
       digitalWrite(Gled, LOW);
        digitalWrite(Bled, LOW); }

if(indexG>=0){
    Serial.print("Comparison is: ");
    Serial.println("Green");
    digitalWrite(Rled, LOW);
        digitalWrite(Gled, HIGH);
        digitalWrite(Bled, LOW);

   }
   if(indexB>=0){
    Serial.print("Comparison is: ");
    Serial.println("Blue");
    digitalWrite(Rled, LOW);
        digitalWrite(Gled, LOW);
        digitalWrite(Bled, HIGH); }
  }}
