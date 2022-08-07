/*
Name: Jack Bergin
Date: 09/27/18
Class: Electrical Engineering (H)
Lab: Potientiometer Mod experiment
Description: In this lab we will be using a POT resistor
to regulate the flow of electricity to an RGB led
thus controlling the frequency of the led's changing of colors.
*/

int sensorPin = 0; //This is for the analog input pin the pot is connected to.

//create variables for pin numbers. We are making them constants here, because they never change.
const int RED_PIN = 5;
const int GREEN_PIN = 6;
const int BLUE_PIN = 9;

void setup() //Sets up all of the pins on arduino to give OUTPUT to the RGB anodes of the led
{
   //Sets up all of the pins on arduino to give OUTPUT to the RGB anodes of the led
   pinMode(RED_PIN, OUTPUT);
   pinMode(GREEN_PIN, OUTPUT);
   pinMode(BLUE_PIN, OUTPUT);

   Serial.begin(9600); //Begins serial monitor
}

void loop()
{
  //Created a function to be run in the loop making it more organized. This also allows for more things to be put into the loop.
  mainColors();
}

void mainColors()
{
   int sensorValue = analogRead(sensorPin); //We initialize the sensor value for the potentiometer so that we can use it for our time delay.

   //Turns off all leds for delay alloted time
   digitalWrite(RED_PIN, LOW);    
   digitalWrite(GREEN_PIN, LOW);
   digitalWrite(BLUE_PIN, LOW);
   
   Serial.print("Off");
   Serial.println(" "+sensorValue);
  
   delay(sensorValue); 
   
   //RGB led goes red for delay time
   digitalWrite(RED_PIN, HIGH);
   digitalWrite(GREEN_PIN, LOW);
   digitalWrite(BLUE_PIN, LOW);

   Serial.print("Red");
   Serial.println(" "+sensorValue);

   delay(sensorValue); 

   //RGB led goes green for delay time
   digitalWrite(RED_PIN, LOW);
   digitalWrite(GREEN_PIN, HIGH);
   digitalWrite(BLUE_PIN, LOW);

   Serial.print("Green");
   Serial.println(" "+sensorValue);

   delay(sensorValue); 

   //RGB led goes blue for delay time
   digitalWrite(RED_PIN, LOW);
   digitalWrite(GREEN_PIN, LOW);
   digitalWrite(BLUE_PIN, HIGH);

   Serial.print("Blue");
   Serial.println(" "+sensorValue);

   delay(sensorValue); 

   //RGB led goes yellow for delay time
   digitalWrite(RED_PIN, HIGH);
   digitalWrite(GREEN_PIN, HIGH);
   digitalWrite(BLUE_PIN, LOW);

   Serial.print("Yellow");
   Serial.println(" "+sensorValue);

   delay(sensorValue); 

   //RGB led goes cyan for delay time
   digitalWrite(RED_PIN, LOW);
   digitalWrite(GREEN_PIN, HIGH);
   digitalWrite(BLUE_PIN, HIGH);

   Serial.print("Cyan");
   Serial.println(" "+sensorValue);

   delay(sensorValue);

   //RGB led goes purple for delay time
   digitalWrite(RED_PIN, HIGH);
   digitalWrite(GREEN_PIN, LOW);
   digitalWrite(BLUE_PIN, HIGH);

   Serial.print("Purple");
   Serial.println(" "+sensorValue);

   delay(sensorValue); 

   //RGB led goes white for delay time
   digitalWrite(RED_PIN, HIGH);
   digitalWrite(GREEN_PIN, HIGH);
   digitalWrite(BLUE_PIN, HIGH);

   Serial.print("White");
   Serial.println(" "+sensorValue);
   
   delay(sensorValue);
}
