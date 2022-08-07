/*
Name: Jack Bergin
Date: 1/10/19
Class: Electrical Engineering (H)
Lab: Sound Detector Modified
Description: In this tutaorial I replaced the rgb led with a motor and added two push press buttons. 
The buttons change the sensitivity to the sensor and the motor will react with the varying volume levels 
and change speeds according to the levels of sound.
*/

const int soundPin = 0;

//For the sensitivity buttons
const int button1 = 4;
const int button2 = 3;

//Pin for motor
const int motorPin = 9;

//Counters for the buttons
int counter1 = 0;
int counter2 = 0;

//variables for storing raw sound and scaled value
int sound;
int scale;


void setup()
{
   //start the serial port a@ 9600bps
   Serial.begin(9600);

   //Input values for both buttons
   pinMode(button1, INPUT);
   pinMode(button2, INPUT);

   //Set motor to pin 9 as output
   pinMode(motorPin, OUTPUT);
}
void loop()
{
   //read and store the audio from Envelope pin
   sound = analogRead(soundPin);

   //Works as 2 different map functions
   //sensitivitySetter();
   int buttonState1;
   buttonState1 = digitalRead(button1);

   int buttonState2;
   buttonState2 = digitalRead(button2);

    if (buttonState1 == LOW) 
    {
       counter1++;
       delay(50); 
    }

    if (buttonState2 == LOW)
    {
      counter2++;
      delay(50);
    }

    if(counter1 == 0)
    {
       Serial.println("No Map Set Up Yet");
       delay(10);
    }
    //else if counter is equal to 1, redPin is HIGH
    else if(counter1 == 1)
    { 
       scale = map(sound, 20, 200, 0, 3);
       Serial.println("High Sensitivity");
       delay(10);
    }
    else
    {
      counter1 = 0;
    }

  if(counter2 == 0)
  {
     Serial.println("No Map Set Up Yet");
     delay(10);
  }
  //else if counter is equal to 3 bluePin is HIGH
  else if(counter2 == 1)
  {
     scale = map(sound, 100, 400, 0, 3);
     Serial.println("Low Sensitivity");
     delay(10);
  }
  //else reset the counter to 0 (which turns all pins off)
  else
  {
    counter2 = 0;
  }

   //print values over the serial port for debugging
   Serial.println(scale);
   
   //switch case on scaled value
switch (scale)
{
   //if 0 motor is off
   case 0:
      analogWrite(motorPin, 0);  
      // delay for onTime milliseconds
      delay(50);    
      break;
      
   //if 1 motor goes 50 speed
   case 1:
      analogWrite(motorPin, 150);  
      // delay for onTime milliseconds
      delay(1000);   
      // turns the motor Off
      analogWrite(motorPin, 0);  
      // delay for offTime milliseconds
      delay(500); 
      break;
     
   //if 2 motor goes 100 speed
   case 2:
      analogWrite(motorPin, 200);  
      // delay for onTime milliseconds
      delay(1000);   
      // turns the motor Off
      analogWrite(motorPin, 0);  
      // delay for offTime milliseconds
      delay(500); 
     break;
     
   //if 3 motor speed goes 200
   case 3:
      analogWrite(motorPin, 250);  
      // delay for onTime milliseconds
      delay(1000);   
      // turns the motor Off
      analogWrite(motorPin, 0);  
      // delay for offTime milliseconds
      delay(500);  
     break;
     
   //default turn off
   default:
      analogWrite(motorPin, 0);  
      // delay for onTime milliseconds
      delay(50);     
      break;
 }
}
/*
void sensitivitySetter()
{
   int buttonState1;
   buttonState1 = digitalRead(button1);

   int buttonState2;
   buttonState2 = digitalRead(button2);

    if (buttonState1 == LOW) 
    {
       counter1++;
       delay(50); 
    }

    if (buttonState2 == LOW)
    {
      counter2++;
      delay(50);
    }

    if(counter1 == 0)
    {
       Serial.println("No Map Set Up Yet");
       delay(50);
    }
    //else if counter is equal to 1, redPin is HIGH
    else if(counter1 == 1)
    { 
       scale = map(sound, 20, 200, 0, 3);
       Serial.println("High Sensitivity");
       delay(50);
    }
    else
    {
      counter1 = 0;
    }

  if(counter2 == 0)
  {
     Serial.println("No Map Set Up Yet");
     delay(50);
  }
  //else if counter is equal to 3 bluePin is HIGH
  else if(counter2 == 1)
  {
     scale = map(sound, 100, 400, 0, 3);
     Serial.println("Low Sensitivity");
     delay(50);
  }
  //else reset the counter to 0 (which turns all pins off)
  else
  {
    counter2 = 0;
  }

}
*/
