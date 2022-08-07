/*
Example sketch 18
DISPLAYING THE DATE AND TIME
This sketch reads the RTC data and prints it on the LCD screen
*/
//include the CurieTime Library
#include <CurieTime.h>
#include <LiquidCrystal.h>
//instantiate the lcd
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup()
{
  //start lcd at 16 x 2
  lcd.begin(16, 2);
  //clear the lcd
  lcd.clear();
  //set time to 5:31:15 on the 26th of Feburary, 2019. 
  setTime(5, 36, 45, 26, 02, 2019);
}
void loop()
{
 //create a character array of 16 characters for the time
 char clockTime[16];
 //use sprintf to create a time string of the hour, minte and seconds
 sprintf(clockTime, "  %2d:%2d:%2d ", hour(), minute(), second());
 //create a character array of 15 characters for the date
 char dateTime[16];
 //use sprintf to create a date string from month, day and year
 sprintf(dateTime, "   %2d/%2d/%4d   ", day(), month(), year());
 //set cursor to column 0, row 0
 lcd.setCursor(0, 0);
 //print the date string over lcd
 lcd.print(dateTime);
 //set cursor to column 0, row 1
 lcd.setCursor(0, 1);
 //print the time string over lcd
 lcd.print(clockTime);
}
