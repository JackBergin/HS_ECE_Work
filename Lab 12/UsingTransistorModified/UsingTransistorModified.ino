/*
Name: Jack Bergin
Date 1/10/19
Class: Electrical Engineering (H)
Description: In this lab we are adding 
two buttons and a potentiometer to regulate 
to speed of the motor from either a button 
press or a potentiometer adjustment.
*/

//Constant pins for the spdt
const int switchPin1 = 3;  

//Constant button pins for the speed control
const int button1 = 4;
const int button2 = 5;

// constant pin for the transistor connected to the motor
const int motorPin = 9;

//This is for the analog input pin the pot is connected to
int sensorPin = 0;

//Setting up the counter for the two motor speed buttons
int counter1 = 0;
int counter2 = 0;

void setup()
{
   // Set up the switch pins to be an input:
   pinMode(switchPin1, INPUT);
   
   //set motorPin as OUTPUT
   pinMode(motorPin, OUTPUT);

   //Begins serial monitor
   Serial.begin(9600); 
}
void loop()
{
    int switchVal1;
    switchVal1 = digitalRead(switchPin1);

    Serial.println("Switch Not working");
    delay(200);
     //One after another
    if(switchVal1 == HIGH)
    { 
       Serial.println("Switch Left");
       delay(200);
       //This value stores a sensor value that uses the analogRead 
       //function to read the sensorPin value and store the value 
       //in the sensorValue variable.
       int sensorValue = analogRead(sensorPin); 
       int ratio = sensorValue/1024;
       int maxMotorSpeed = 255;
       int newMotorSpeed = maxMotorSpeed * ratio;
       analogWrite(motorPin, newMotorSpeed);  
       // delay for onTime milliseconds
       delay(500);   
       // turns the motor Off
       analogWrite(motorPin, 0);  
       // delay for offTime milliseconds
       //delay(10);           
       Serial.println("Potentiometer: " + sensorValue);
       Serial.println("Speed of Motor: " + newMotorSpeed);
       delay(100);
    }
    if (switchVal1 == LOW)
    {
      Serial.println("Switch Right");
      delay(200);
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
         Serial.println("Button Speed not selected");
         delay(10);
      }
      //else if counter is equal to 1, redPin is HIGH
      else if(counter1 == 1)
      { 
         analogWrite(motorPin, 180);  
         // delay for onTime milliseconds
         delay(1000);   
         // turns the motor Off
         analogWrite(motorPin, 0);  
         // delay for offTime milliseconds
         delay(10);           
         Serial.println("Low Speed");
         delay(10);
      }
      else
      {
        counter1 = 0;
      }
       
      //Second button speed setup
      if(counter2 == 0)
      {
         Serial.println("Button Speed not selecte");
         delay(10);
      }
      //else if counter is equal to 3 bluePin is HIGH
      else if(counter2 == 1)
      {
         analogWrite(motorPin, 250);  
         // delay for onTime milliseconds
         delay(1000);   
         // turns the motor Off
         analogWrite(motorPin, 0);  
         // delay for offTime milliseconds
         delay(10);           
         Serial.println("High Speed");
         delay(10);
      }
      //else reset the counter to 0 (which turns all pins off)
      else
      {
         counter2 = 0;
      }
      }
}
