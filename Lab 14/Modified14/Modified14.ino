/*
Name: Jack Bergin
Date: January 19, 2019
Class: Electrical Engineering (H)
Lab: Modified Motor Driver
Description: Used my old elegoo robot and can now control the four motors with bluetooth low energy. \
 */
//Variable for the Bluetooth HC-08
char getstr;

//defines the motor output pins
int in1=6;
int in2=7;
int in3=8;
int in4=9;

//defines the enable output pins
int ENA=5;
int ENB=11;

void setup() 
{
  //Set the defined pins to the output
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);

  //These never change state since we are always keeping the arduino and motors enabled
  digitalWrite(ENA,HIGH); 
  digitalWrite(ENB,HIGH);

  //Sets up serial monitor
  Serial.begin(9600);
}

void loop() 
{  
   //Retrieves a char value from the arduino transfered from phone to HC-08 to arduino
   getstr = Serial.read(); 

   //Uses these ifs the access each individual method based off of the input from the ble app.
   if(getstr=='f')
   {
      forward();
   }
   else if(getstr=='b')
   {
      backward();
   }
   else if(getstr=='l')
   {
      left();
   }
   else if(getstr=='r')
   {
      right();
   }
   else if(getstr=='s')
   {
      halt();
   }
}
//Forward method
void forward()
{ 
  //Left wheels clockwise
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  //Right wheels clockwise
  digitalWrite(in4,HIGH);
 
  //Serial monitor
  Serial.println("Forward");
}

//Backward method
void backward()
{
  digitalWrite(in1,LOW);
  //Left wheels counter clockwise
  digitalWrite(in2,HIGH);
  //Right wheels counter clockwise
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  
  //Serial monitor
  Serial.println("Backward");
}
//Left method
void left()
{
  //Left wheels clockwise
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  //Right wheels counter clockwise
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW); 
  
  //Serial monitor
  Serial.println("Left");
}
//Right method
void right()
{
  digitalWrite(in1,LOW);
  //Left wheels counter clockwise
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  //Right wheels clockwise
  digitalWrite(in4,HIGH);
  
  //Serial monitor
  Serial.println("Right");
}

//Stop "halt" method
void halt()
{
  //Turns off all motors off
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);

  //Prints out off on serial monitor
    Serial.println("Stop");
}
