/*
Name: Jack Bergin
Date: 12/23/18
Class: Electrical Engineering (H)
Lab: Tempature Sensor
Description: In this lab we will be using a RGB led 
as well as if statements to judge the weather and 
determine whether you should turn up the heat, down 
the heat or keep it as is.
*/

//analog input pin constant
const int tempPin = 0;

//raw reading variable
int tempVal;

//voltage variable
float volts;

//final temperature variables
float tempC;
float tempF;
//RGB variables

int red = 13;
int green = 12;
int blue = 11;
void setup()
{
   pinMode(red, OUTPUT);
   pinMode(green, OUTPUT);
   pinMode(blue, OUTPUT);
   // start the serial port at 9600 baud
   Serial.begin(9600);
   //9600 is the “baud rate,” or communications speed. When two devices are communicating with each other, both must be set to the same speed.
}
void loop()
{
   //read the temp sensor and store it in tempVal
   tempVal = analogRead(tempPin);
   
   //print out the 10 value from analogRead
   Serial.print("TempVal = ");
   Serial.print(tempVal);
   //print a spacer  
   Serial.print(" **** ");
   //converting that reading to voltage by multiplying the reading by 3.3V (voltage of     //the 101 board)
   volts = tempVal * 3.3;
   volts /= 1023.0;
   //print out the raw voltage over the serial port
   Serial.print("volts: ");
   Serial.print(volts, 3);
   //print out divider
   Serial.print(" **** ");
   //calculate temperature celsius from voltage
   //equation found on the sensor spec.
   tempC = (volts - 0.5) * 100 ;
   // print the celcius temperature over the serial port
   Serial.print(" degrees C: ");
   Serial.print(tempC);
   //print spacer
   Serial.print(" **** ");
   // Convert from celcius to fahrenheit
   tempF = (tempC * 9.0 / 5.0) + 32.0;
   //print the fahrenheit temperature over the serial port
   Serial.print(" degrees F: ");
   Serial.println(tempF);
   
   //So we are dealing with numbers that are not 
   //inbetween any of the if numbers
   tempF = round(tempF);
  
   if(50 < tempF && tempF < 64)
   {
      digitalWrite(blue, HIGH);
      delay(250);
      digitalWrite(blue, LOW);
      
      Serial.println("Turn the heat on bud");
   }
   
   tempF = round(tempF);

   if (65 < tempF && tempF < 75) 
   {
      digitalWrite(green, HIGH);
      delay(250);
      digitalWrite(green, LOW);

      Serial.println("Okay, don't change anything!");
   }
   
   tempF = round(tempF);
   
   if (76 < tempF && tempF < 100)
   {
      digitalWrite(red, HIGH);
      delay(250);
      digitalWrite(red, LOW);
      
      Serial.println("Alright bud, throttle it back.");
   }

   delay(750);
}
