/*
Name: Jack Bergin
Date: 09/26/18
Class: Electrical Engineering (H)
Lab: Potientiometer Basic experiment
Description: In this lab we will be using a POT resistor
to regulate the flow of electricity to the anode of the led
thus controlling the frequency of the led's blinking light going
from a slow and steady blink to one that looks constantly on.
*/

int sensorPin = 0; //This is for the analog input pin the pot is connected to.

int ledPin = 13; //This variable denotes which pin the wire connecting the resistor and the arduino connect to
  
void setup() //this function sets up the future loop function once when the sketch starts up
{
  pinMode(ledPin, OUTPUT); //set pin 13 on the arduino to a 5V power OUTPUT

}
void loop() //This loop function is used to run its inner code forever or for long as the user wants it to go
{
  int sensorValue = analogRead(sensorPin); //This value stores a sensor value that uses the analogRead function to read the sensorPin value and store the value in the sensorValue variable.

  digitalWrite(ledPin, HIGH); //Gives power to the led
  delay(sensorValue); //This is the time the power is on for depending on the value of the POT         

  digitalWrite(ledPin, LOW); //After the delay this turns the led off
  delay(sensorValue); //And again this uses the sensor value of the POT to determine the time the led stays off for       
  
  //After all of this code, since we are in a loop, the loop brings us back to the top at int sensorValue to start the loop again
}
