/*
Name: Jack Bergin
Date: March 26, 2019
Class: Electrical Engineering (H)
Lab: Modified Accelerometer Lab
Description: In this lab an LCD was added as well as a 
dice to create a random dice roll based off of the tilt 
of the accelerometer.
*/

// Load the LiquidCrystal library, which will give us
// commands to interface to the LCD:
#include <LiquidCrystal.h>
//Library for the accelerometer
#include "CurieIMU.h"

//Sets the perameters for the motors
const int DIR_A = 8;
const int DIR_B = 9;
const int PWM = 10;

// We initialize the pins we're using.
LiquidCrystal lcd(12,11,5,4,3,2);

void setup()
{
  //LCD Setup for the program:
  lcd.begin(16, 2);
  //Clears the LCD
  lcd.clear();
  //Prints out our initial message
  lcd.print("Roll the dice");
  
  //set motor control pins to OUTPUT
  pinMode(DIR_A, OUTPUT);
  pinMode(DIR_B, OUTPUT);
  pinMode(PWM, OUTPUT);
  
  // Start the acceleromter
  CurieIMU.begin();
  
  // Set the accelerometer range to 2G
  CurieIMU.setAccelerometerRange(2);

  //Sets up the serial monitor
  Serial.begin(9600);
}
void loop()
{
  // read accelerometer:
  int x = CurieIMU.readAccelerometer(X_AXIS);
  int y = CurieIMU.readAccelerometer(Y_AXIS);
  int z = CurieIMU.readAccelerometer(Z_AXIS);
 
  // calculate the absolute values, to determine the largest
  int absX = abs(x);
  int absY = abs(y);
  int absZ = abs(z);

  //If Z is greater than both the X and Y axis we will go into the next if statement
  if ( (absZ > absX) && (absZ > absY))
  {
    //If Z is now greater than zero this means that the accelerometer is level
    if (z > 0)
    {
      //Reset on the LCD
      lcd.clear();
      lcd.print("Roll the dice");
      
      //Shuts off all motor function
      brake();
      //Prints out:
      Serial.println("No Roll");

      //One second delay before next roll
      delay(1000);
    }
  }
  
  //else if Y is greater than X and Z its on edge
  else if ( (absY > absX) && (absY > absZ))
  {
    // if Y is positive orientation (digital pins up)and is set to 1
    if (y > 0)
    {
      //Turn the motor on for half a second 
      on();
      //Then turn off the motor
      brake();
      //Display the random dice roll on the LCD
      roll();

      //Confirm that the dice was rolled on Serial Monitor
      Serial.println("Roll");
    }
    //the Y is in the negative orientation (analog pins up) and is set to 2
    else
    {
      //Turn the motor on for half a second 
      on();
      //Then turn off the motor
      brake();
      //Display the random dice roll on the LCD
      roll();

      //Confirm that the dice was rolled on Serial Monitor
      Serial.println("Roll");
    }
  }
}

//Roll method
void roll()
{
   //Clears the LCD just in case
   lcd.clear();

   //Creates a random number between 1 and 6
   int randomRoll = random(1, 6);

   //Prints our the random number
   Serial.print("Random Number: ");
   Serial.println(randomRoll);
  
   //Prints out the roll on LCD
   if (randomRoll == 1)
   {   
       //Prints out the number
       lcd.print("One");
       //Prints out the die number
       lcd.print("  .");
      
       //2 second delay
       delay(2000);
   }   
   else if (randomRoll == 2)
   {
       //Prints out number
       lcd.print("Two");
       //Prints out die number
       lcd.print(" ..");
     
       //2 second delay
       delay(2000);
   }
   else if (randomRoll == 3)
   {
       //Prints out number
       lcd.print("Three");
       //Prints out die number
       lcd.print(" ...");
      
       //2 second delay
       delay(2000);
   }
   else if (randomRoll == 4)
   {
       //Prints out number
       lcd.print("Four");
       //Prints out die number
       lcd.print("    ..");
       lcd.setCursor(0,1);
       lcd.print("        ..");

       //2 second delay
       delay(2000);
   }
   else if (randomRoll == 5)
   {
       //Prints out number
       lcd.print("Five");
       //Prints out die number
       lcd.print("    ..");
       lcd.setCursor(0,1);
       lcd.print("     ...");
       
       //2 second delay
       delay(2000);
   }
   else if (randomRoll == 6)
   {
       //Prints out number
       lcd.println("Six");
       //Prints out die number
       lcd.print("    ...");
       lcd.setCursor(0,1);
       lcd.print("    ...");

       //2 second delay
       delay(2000);
   }
}
//Drives the motor to rotate counterclockwise 
void on()
{
  //DIR_A is counterclockwide
  digitalWrite(DIR_A, HIGH);
  digitalWrite(DIR_B, LOW);
  digitalWrite(PWM, HIGH);

  //half second delay
  delay(500);
}

//Stops the motor
void brake()
{
  digitalWrite(DIR_A, LOW);
  digitalWrite(DIR_B, LOW);
  digitalWrite(PWM, LOW);
}
