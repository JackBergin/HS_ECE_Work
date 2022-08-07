/*
Name: Jack Bergin
Date: 12/22/18
Class: Electrical Engineering (H)
Lab: ReadingPhotoresistorMod
Description: In this tuturial all we are doing is 
playing with the sensitivity on three leds.
*/

// These are our constants
const int sensorPin = 0;
const int ledPin1 = 9;
const int ledPin2 = 6;
const int ledPin3 = 5;

//These are the same global variables
int lightCal;
int lightVal;
void setup()
{
  //Setting up the outputs
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);

  //Again this acts as a single reading from the light sensor to compare in the loop
  lightCal = analogRead(sensorPin);

  //Serial monitor is started
  Serial.begin(9600);
}
void loop()
{
  //This reading is what we are comparing lightCal to.
  lightVal = analogRead(sensorPin);
  //if lightVal is less than lightCal minus x it's dark and turns a pin HIGH. We are playing with the sensivitivity.
  //The smaller the number the more sensitive.

  //Red
  if(lightVal < lightCal - 25) {
    digitalWrite(ledPin1,HIGH);
    Serial.println("RedOn");
  }
  //else, it is bright, turn LOW
  else {
    digitalWrite(ledPin1,LOW);
    Serial.println("RedOff");
  }
  
  //Green
  if(lightVal < lightCal - 50) {
    digitalWrite(ledPin2,HIGH);
    Serial.println("GreenOn");
  }
  //else, it is bright, turn LOW
  else{
    digitalWrite(ledPin2,LOW);
    Serial.println("GreenOff");
  }

  //Blue
  if(lightVal < lightCal - 100){
    digitalWrite(ledPin3,HIGH);
    Serial.println("BlueOn");
  }
  //else, it is bright, turn pin 9 LOW
  else{
    digitalWrite(ledPin3,LOW);
    Serial.println("BlueOff");
  }
}
