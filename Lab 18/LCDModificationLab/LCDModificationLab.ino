/*
Name: Jack Bergin
Date: 2/23/19
Class: Electrical Engineering (H)
Lab: LCD Modification Lab
Description: With this modification the tempature in fahrenheit will be displayed
on the LCD. The LEDs according with a tempature range will be turned on; blue = cold, 
green = perfect, red = hot.
*/

//****************************
//LCD constants and Libraries:

// Load the LiquidCrystal library, which will give us
// commands to interface to the LCD:
#include <LiquidCrystal.h>
// We initialize the library with the pins we're using.
// (Note that you can use different pins if needed.)
LiquidCrystal lcd(12,11,5,4,3,2);

//**********************
//Temp sensor constants:

//analog input pin constant
const int tempPin = 0;
//raw reading variable
int tempVal;
//voltage variable
float volts;
//final temperature variables
float tempC;
float tempF1;

//****************
//Light Constants:

int blue = 8;
int green = 7;
int red = 6;

void setup()
{
   //Set up for the LEDs
   pinMode(blue, OUTPUT);
   pinMode(green, OUTPUT);
   pinMode(red, OUTPUT);
  
   //Sets up the LCD for work
   lcd.begin(16, 2);

   // start the serial port at 9600 baud
   Serial.begin(9600);
}

void loop()
{
   //read the temp sensor and store it in tempVal
   tempVal = analogRead(tempPin);
   //converting that reading to voltage by multiplying the reading by 3.3V (voltage of     //the 101 board)
   volts = tempVal * 3.3;
   volts /= 1023.0;
   //calculate temperature celsius from voltage
   //equation found on the sensor spec.
   tempC = (volts - 0.5) * 100 ;
   
   // print the celcius temperature over the serial port
   Serial.print("Degrees C: ");
   Serial.println(tempC);
   
   // Convert from celcius to fahrenheit
   tempF1 = (tempC * 9.0 / 5.0) + 32.0;
   //print the fahrenheit temperature over the serial port
   Serial.print("Degrees F: ");
   Serial.println(tempF1);
   
   //Conversion over from float to int
   int tempF = tempF1;

   //Prints out the LCD fahrenheit temp
   Serial.print("LCD Temp: ");
   Serial.println(tempF);
   
   //Prints out the tempature on the first line of the LCD
   lcd.print("Tempature: ");
   lcd.print(tempF);
   //Temp rounds up for rounded comparisons
   tempF = round(tempF);

   //Sets LCD message to the next row
   lcd.setCursor(0,1);

   //Prints out message before serial return in the if statements:
   Serial.print("The tempature is: ");
   //Compares tempF between a range of -infinity to 64 degrees
   if(tempF <= 64)
   {
      //Puts on the blue led
      digitalWrite(blue, HIGH);
      //Prints out message on lcd
      lcd.print("Too cold");

      //Serial print out message
      Serial.println("Too cold");
   }
   //Compares tempF between a range of 65-75 degrees
   if (65 <= tempF && tempF <= 75) 
   {
      //Puts on the green led
      digitalWrite(green, HIGH);
      //Prints out message on lcd
      lcd.print("Perfect");

      //Serial print out message
      Serial.println("Perfect!");
   }
   
   //Compares tempF between a range of 76-infinity degrees
   if (76 <= tempF)
   {
      //Puts on the red led
      digitalWrite(red, HIGH);
      //Prints out message on lcd
      lcd.print("Too hot");

      //Serial print out message
      Serial.println("Too hot");
   }
   
   //wait a bit before taking another reading
   delay(1000);
   
   //Resets LCD for next loop iteration
   lcd.clear();

   //LED reset for the next loop iteration:
   digitalWrite(blue, LOW);
   digitalWrite(green, LOW);
   digitalWrite(red, LOW);

   //Seperates new loop
   Serial.println("******************");
}
