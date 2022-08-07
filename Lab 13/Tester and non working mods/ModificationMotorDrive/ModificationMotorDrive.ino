/*
Example sketch 13
SparkFun Motor Controller with Inputs.  
Use the inputs to manually set the direction and speed of a motor.
*/
#include <SoftwareSerial.h>

//define the two direction logic pins and the speed / PWM pin
const int DIR_A = 5;
const int DIR_B = 4;
//const int PWM = 6;

int state = 0;

 void setup()
 {
   //set all pins as output
   pinMode(DIR_A, OUTPUT);
   pinMode(DIR_B, OUTPUT);
   //pinMode(PWM, OUTPUT);

   Serial.begin(38400); //Default communication rate of the BLE
  }
void loop()
{
   if (Serial.available() > 0) // Checks whether data is comming from the serial port
   {
      state = Serial.read(); // Reads the data from the serial port
   }
   if (state == '0')
   {
     //Keeps both motor directions off
     digitalWrite(DIR_A, LOW); 
     digitalWrite(DIR_B, LOW);
     
     // Send back, to the phone, the String "MOTOR: OFF"
     Serial.println("MOTOR: OFF");

     //Sets the state back to zero
     state = 0;
   }
   if (state == '1')
   {
      //Turns DIR_A on and keeps DIR_B off
      digitalWrite(DIR_A, HIGH);
      digitalWrite(DIR_B, LOW);

      //Send back, to the phone the String:
      Serial.println("MOTOR DIR_A: ON");
      
      delay(1000);
      state = 0;
   }
   if (state == '2')
   {
      //Turns DIR_A on and keeps DIR_B off
      digitalWrite(DIR_A, LOW);
      digitalWrite(DIR_B, HIGH);

      //Send back, to the phone the String:
      Serial.println("MOTOR DIR_B: ON");
      
      delay(1000);
      state = 0;
   }
}
