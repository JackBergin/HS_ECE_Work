/*
Name: Jack Bergin
Date: 2/26/19
Class: Electrical Engineering (H)
Lab: RTC Modification Lab
Description: With this modification I created a stopwatch with 
the inclusion of two buttons as added hardware.
*/

//LCD Library
#include <LiquidCrystal.h>

//LCD Pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//Button Pins
int button1 = 9;
int button2 = 6;

void setup()
{
  //Sets up and then clears LCD screen 
  lcd.begin(16, 2);
  lcd.clear();

  //Serial monitor
  Serial.begin(9600);

  //Initializes the buttons as imputs and then sets them to high
  pinMode(button1, INPUT);
  digitalWrite(button1, HIGH);
  
  pinMode(button2, INPUT);
  digitalWrite(button2, HIGH);
}

//Variables for the seconds and miliseconds conversion in the first while statement
double timer;
double firstTime; 
double secondTime;

void loop()
{ 
   //Clears after each loop
   lcd.clear();

   //Title for LCD
   lcd.print("Stopwatch");
   lcd.setCursor(0, 1);
   lcd.print("Press Start");
   delay(100);

 //If green button is pressed
 if(digitalRead(button1) == LOW)
 {
    //LCD is cleared again
    lcd.clear();

    //First timer for reset of if statement
    firstTime = millis();
   
   while(digitalRead(button2) == HIGH)
   {
     //While loop time
     secondTime = millis();

     //This gives us our LCD print time because second time will keep incramenting even after reset without subtracting firstTime
     timer = (secondTime - firstTime) / 1000;
     //Prints out on the LCD
     lcd.print(timer);

     //Prints out seconds after the time
     lcd.print(" Seconds");

     //Resets the cursor for each repetition in the while to 
     lcd.setCursor(0,0);

     //Prints out the different times and then official time
     Serial.println(secondTime);
     Serial.println(firstTime);
     Serial.println(timer);

     //Seperator
     Serial.println("......");

     //Delays every 100 milliseconds
     delay(100);
   }

   //If the red button is pushed then the timer will access this while statement
   if(digitalRead(button2) == LOW)
   {
     while(digitalRead(button1) == HIGH)
     {
        //Resets cursor back to 0
        lcd.setCursor(0,0);
        //Displays an unchanging final time
        lcd.print(timer);
        //Same delay as up in first while
        delay(100);
     }
   }
 }
}
