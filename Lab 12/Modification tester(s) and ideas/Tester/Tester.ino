/*
Name: Jack Bergin
Date 1/13/19
Class: Electrical Engineering (H)
Lab: Modification to the transistor tutorial
Description: We added a potentiometer to adjust 
the speed of the motor 

 */

// constant pin for the transistor connected to the motor
const int motorPin = 9;

//This is for the analog input pin the pot is connected to
int potValue = 0;

//Speed for the motor to run at
int newMotorSpeed = 0;

void setup() 
{
   //set motorPin as OUTPUT
   pinMode(motorPin, OUTPUT);

   //Begins serial monitor
   Serial.begin(9600); 
}

void loop() 
{
       //Sets up our potentiometer analoug value
       potValue = analogRead(A0); 
       
       //Checks if potentiometer is working
       Serial.println(potValue);
       Serial.println("-----");
       
       //Converts pot Values to 0-255 value for motor
       newMotorSpeed = map(potValue, 0, 1025, 0, 256);
       //Prints out the variable motor speed
       Serial.println(newMotorSpeed);

       
       //Sets up the motor to run at a different potentiometer input speed
       analogWrite(motorPin, newMotorSpeed);  
       // delay for differentTime variable 
       delay(50);   
}
