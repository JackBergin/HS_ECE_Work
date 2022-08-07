/*
Name: Jack Bergin
Date: 11/6/18
Class: Electrical Engineering (H)
Lab: SPDT Switch Modification
Description: In this tutorial I incorperated two SPDT switches
which will run the "Driving Multiple LEDs lab" much more smoothly
*/

// Create constants for the pins we will be using
const int switchPin1 = 3;  
const int switchPin2 = 2;

int ledPins[] = {7,6,5,4};



void setup()
{
   // Set up the switch pins to be an input:
   pinMode(switchPin1, INPUT);
   pinMode(switchPin2, INPUT);
   
   for(int index = 7; index <= 4; index--)
   {
      pinMode(ledPins[index],OUTPUT);
   }
     Serial.begin(9600);

}

void loop()
{
  int switchVal1;  
  switchVal1 = digitalRead(switchPin1);
  
  int switchVal2;  
  switchVal2 = digitalRead(switchPin2);

 
 if(switchVal2 == HIGH)
 {
    //One after another
    if(switchVal1 == HIGH)
    {
       Serial.println("One after another");
       int index;
       int delayTime = 100;

       for(index = 0; index <= 3; index++)
       {
          digitalWrite(ledPins[index], HIGH);
          delay(delayTime);              
       }  
                                     
       for(index = 3; index >= 0; index--)
       {
          digitalWrite(ledPins[index], LOW);
          delay(delayTime);
       }            
    }
    
    //One at a time
    if(switchVal1 == LOW)
    {
       Serial.println("One at a time");
       int index;
       int delayTime = 100; // milliseconds to pause between LEDs
                    // make this smaller for faster switching
         // step through the LEDs, from 0 to 5
       for(index = 0; index <= 3; index++)
       {
          digitalWrite(ledPins[index], HIGH);  // turn LED on
          delay(delayTime);                 // pause to slow down
          digitalWrite(ledPins[index], LOW);   // turn LED off
       }
    }
 }


 if(switchVal2 == LOW)
 {
     //Pingpong
     if(switchVal1 == HIGH)
     {
        Serial.println("Pingpong");
        int index;
        int delayTime = 100; // milliseconds to pause between LEDs
                    // make this smaller for faster switching
       for(index = 0; index <= 3; index++)
       {
          digitalWrite(ledPins[index], HIGH);  // turn LED on
          delay(delayTime);                 // pause to slow down
          digitalWrite(ledPins[index], LOW);   // turn LED off
       }

       for(index = 3; index >= 0; index--)
       {
          digitalWrite(ledPins[index], HIGH);  // turn LED on
          delay(delayTime);                 // pause to slow down
          digitalWrite(ledPins[index], LOW);   // turn LED off
       }
     }

     //Random LED
     if(switchVal1 == LOW)
     {
        Serial.println("Random LED");
        int index;
        int delayTime;
        index = random(4);  // pick a random LED
        delayTime = 100;
        digitalWrite(ledPins[index], HIGH);  // turn LED on
        delay(delayTime);                 // pause to slow down
        digitalWrite(ledPins[index], LOW);   // turn LED off
     }
 }
}
