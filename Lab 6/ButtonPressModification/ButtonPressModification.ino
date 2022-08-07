/*
Name: Jack Bergin
Date: 10/23/18
Class: Electrical Engineering (H)
Lab: Button Press Modification
Description: In this tutorial I am showing how, by 
incorperating two leds, a speaker and two buttons 
I am able to make a piano like instrument.
*/

// First we'll set up constants for the pin numbers.
// This will make it easier to follow the code below.
// pushbutton pin
 const int blueButtonPin = 5;
 const int redButtonPin = 3;
 
 //Speaker pins
 const int speaker1 = 13;    
 
 //Led Pins
 const int blueLEDPin = 10;
 const int redLEDPin = 8;
 
 //create a variable to store a counter and set it to 0
 int counterBlue = 0;
 int counterRed = 0;

void setup()
{
  // Set up the pushbutton pins to be an input:
  pinMode(blueButtonPin, INPUT);
  pinMode(redButtonPin, INPUT);

  // Set up the LED pins to be outputs:
  pinMode(blueLEDPin, OUTPUT);  
  pinMode(redLEDPin,OUTPUT);

  //Set up the speaker pin to be outputs:
  pinMode(speaker1, OUTPUT);

  //Serial monitor is started
  Serial.begin(9600);
}
void loop()
{
  int buttonState1;  
  buttonState1 = digitalRead(blueButtonPin);

  int buttonState2;
  buttonState2 = digitalRead(redButtonPin);

  if (buttonState1 == LOW) // light the LED
  {
     counterBlue++;
     delay(250);
  }

  if (buttonState2 == LOW)
  {
    counterRed++;
    delay(250);
  }
  
  if(counterBlue == 0)
  {
     digitalWrite(speaker1,LOW);
     digitalWrite(blueLEDPin,LOW);
     digitalWrite(redLEDPin,LOW);
     Serial.println("BlueOff");
  }
  //else if counter is equal to 1, redPin is HIGH
  else if(counterBlue == 1)
  {
     tone(speaker1, 440, 250);
     digitalWrite(blueLEDPin,HIGH);
     digitalWrite(redLEDPin,LOW);
     Serial.println("BlueON");
  }
  else
  {
    counterBlue = 0;
  }
  
  
  if(counterRed == 0)
  {
     digitalWrite(speaker1,LOW);
     digitalWrite(blueLEDPin,LOW);
     digitalWrite(redLEDPin,LOW);
     Serial.println("RedOff");

  }
  //else if counter is equal to 3 bluePin is HIGH
  else if(counterRed == 1)
  {
     tone(speaker1, 523, 250);
     digitalWrite(blueLEDPin,LOW);
     digitalWrite(redLEDPin,HIGH);
     Serial.println("RedOn");

  }
  //else reset the counter to 0 (which turns all pins off)
  else
  {
   counterRed = 0;
  }
}
