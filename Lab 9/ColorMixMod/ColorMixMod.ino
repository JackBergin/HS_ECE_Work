/*
Name: Jack Bergin
Date: 12/22/18
Class: Electrical Engineering (H)
Lab: ColorMixMod
Description: In this lab we will be using the potentiometers 
of the basic along with the rgb led but will add three new 
leds to show the frequency and changes of frequency for the 
different colors on the RGB.
*/

//create constants for the three analog input pins
const int redPot = 0;
const int greenPot = 1;
const int bluePot = 2;
//create constants for the three RGB pins and new LED pins
const int redPin = 3;
const int greenPin = 6;
const int bluePin = 9;

//Creates constants for the three leds that were added
const int redLed = 13;
const int greenLed = 12;
const int blueLed = 11;
//create variables to store the red, green and blue values
int redVal;
int greenVal;
int blueVal;

void setup()
{
  //set the RGB pins and LED's as outputs
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
 
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);

  Serial.begin(9600);
}
void loop()
{
  //read the three analog input pins and store their value to the color variables
  redVal = analogRead(redPot);
  digitalWrite(redLed, HIGH);
  delay(redVal);
  digitalWrite(redLed, LOW);
  delay(redVal);

  greenVal = analogRead(greenPot);
  digitalWrite(greenLed, HIGH);
  delay(greenVal);
  digitalWrite(greenLed, LOW);
  delay(greenVal);

  blueVal = analogRead(bluePot);
  digitalWrite(blueLed, HIGH);
  delay(blueVal);
  digitalWrite(blueLed, LOW);
  delay(blueVal);

  //use the map() function to scale the 10 bit (0-1023) analog input value to an 8 bit
  //(0-255) PWM, or analogWrite() signal. Then store the new mapped value back in the
  //color variable
  redVal = map(redVal, 0, 1023, 0, 255);
  greenVal = map(greenVal, 0, 1023, 0, 255);
  blueVal = map(blueVal, 0, 1023, 0, 255);
  
  // use the analogWrite() function to write the color values to their respective
  // RGB pins.
  analogWrite(redPin, redVal);
  //Serial monitor set up
  if (redVal > 0) {Serial.print("RedON, ");}
  else{Serial.print("RedOFF, ");}
  
  analogWrite(greenPin, greenVal);
  if (greenVal > 0) {Serial.print("GreenON, ");}
  else{Serial.print("GreenOFF, ");}  
  
  analogWrite(bluePin, blueVal);
  if (blueVal > 0) {Serial.print("BlueON, ");}
  else{Serial.print("BlueOFF, ");}  

  //Acts for new row in net iteration
  Serial.println();

  //Setting redVal and other vals back to analog with this.

  

}
