/*
Name: Jack Bergin
Date: 10/11/18
Class: Electrical Engineering(H)
Lab: Driving Multiple Leds Modification
Description:
In this modification I have created a pong simulation in which 
the light from the led is rallied back and fourth between leds 
and a speaker is used to generate a pong sounding effect.
*/
const int a = 440; //This is the frequency we want the speaker to play at
const int speakerPin = 13; //This is the pin for the speaker

int ledPins[] = {4,5,6,7,8,9}; //This array holds the values for the pin numbers of the leds

void setup()
{
  pinMode(speakerPin, OUTPUT); //Identifies that power will be given to speaker

  for(int index = 0; index <= 5; index++)//Quickly initalizes all of the led pins as output pins
  {
       pinMode(ledPins[index],OUTPUT);
  }

  Serial.begin(9600); //Begins serial monitor
}


void loop()
{
   pong();//Creates a better ping pong simulation between the lights.  
}

//This method in my opinion is better than the tone method because there is less information you need to plug in
void beep(int note, int duration)
{
  //Play tone on buzzerPin
  tone(speakerPin, note, duration);
}

void pong()
{
  int delayTime = 1000; // 1 second pause inbetween LEDs
  
  //Fence post error solution
  digitalWrite(ledPins[0], HIGH);  // turn LED on
  Serial.println("LED1");
  
  beep (a, 250); //Plays frequency for 250 milliseconds
 
  delay(1000); // pauses LED on for 1 second
  digitalWrite(ledPins[0], LOW); // turns LED off

  //Goes through leds 1-4 in a ping pong fashion
  for(int index = 1; index <= 4; index++)
  {
     digitalWrite(ledPins[index], HIGH);  // turn LED on

     //Prints out in serial monitor which led is being turned on
     Serial.print("LED"); 
     Serial.println(index+1);
     
     beep (a, 250); //Again plays the pong frequency
     delay(delayTime); // pauses LED on for 1 second
     digitalWrite(ledPins[index], LOW); //then turns off the LED
  }

  //Fence post error solution
     digitalWrite(ledPins[5], HIGH);  // turn LED on
     Serial.println("Led6");
     beep (a, 250);
     delay(1000);                 // pause to slow down
     digitalWrite(ledPins[5], LOW);   // turn LED off

  //Goes back the way it came from 4-1. 
  //Virtually the same as the loop above but it goes in the reverse order.
  for(int index = 4; index >= 1; index--)
  {
     digitalWrite(ledPins[index], HIGH);  // turn LED on
     Serial.print("Led");
     Serial.println(index+1);
     beep (a, 250);
     delay(delayTime);                 // pause to slow down
     digitalWrite(ledPins[index], LOW);   // turn LED off
  }
}
