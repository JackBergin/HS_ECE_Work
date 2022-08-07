/*
Example sketch 11
SPINNING A MOTOR  Use a transistor to spin a motor at different speeds.
A transistor is a semiconductor device used to amplify or switch 
electronic signals and electrical power. Just think of it as an 
electrically controlled switch.

There are two types of transistors; a NPN and PNP Transistor.
The transistor we are using is an NPN transistor. 
It looks like the following. A NPN and PNP Transistor are made up of three prime parts.
The thing that differes from the two is the way in which their emmitors and collector are configured.
NPN as you can see has its emmitor on the bottom and collector on the top while PNP is reversed. 

Another new piece of hardware used in this video is a flyback diode. It is this piece and 
is used to have the flow of electricity flow one way to maintaine only one direction for the motor.
*/
// constant pin for the transistor connected to the motor
const int motorPin = 9;
void setup()
{
  //set motorPin as OUTPUT
  pinMode(motorPin, OUTPUT);
}
void loop()
{
 
  //*********************************************************************
  //*********************************************************************
  //*********************************************************************
 
  // Here we've used comments to disable some of the examples.
  // To try program 1 or program 2, uncomment (//) them to turn them on and
  // Add (//) to not use the program.
 
  //motorOnThenOff(); // Program 1 Blinky Blinky
  //motorOnThenOffWithSpeed();  // Program 2  Different Speeds one direction
  motorAcceleration(); // Program 3 acceleration + and -
 
  //*********************************************************************
  //*********************************************************************
  //*********************************************************************
}
// This function turns the motor on and off like the blinking LED.
// Try different values to affect the timing.
// Program 1
void motorOnThenOff()
{
  // milliseconds to turn the motor on
  int onTime = 3000;
  // milliseconds to turn the motor off
  int offTime = 3000;
  // turn the motor on (full speed)
  digitalWrite(motorPin, HIGH);
  // delay for onTime milliseconds
  delay(onTime);   
  // turn the motor off
  digitalWrite(motorPin, LOW);  
  // delay for offTime milliseconds
  delay(offTime);            
}

// Program 2
// This function alternates between two speeds.
// Try different values to affect the timing and speed.
void motorOnThenOffWithSpeed()
{
  // between 0 (stopped) and 255 (full speed)
  int Speed1 = 200;
   // milliseconds for speed 1
  int Time1 = 3000;
  // between 0 (stopped) and 255 (full speed)
  int Speed2 = 50;
  // milliseconds to turn the motor off
  int Time2 = 3000;  
  // turns the motor On
  analogWrite(motorPin, Speed1);  
  // delay for onTime milliseconds
  delay(Time1);   
  // turns the motor Off
  analogWrite(motorPin, Speed2);  
  // delay for offTime milliseconds
  delay(Time2);                
}

// Program 3
// This function slowly accelerates the motor to full speed,
// then back down to zero.
void motorAcceleration()
{
  // milliseconds between each speed step
  int speed;
  int delayTime = 20;
  // accelerate the motor
  for(speed = 0; speed <= 255; speed++)
  {
  // set the new speed
  analogWrite(motorPin,speed);
  // delay between speed steps
  delay(delayTime);            
  }
  // decelerate the motor
  for(speed = 255; speed >= 0; speed--)
  {
  // set the new speed
  analogWrite(motorPin,speed);
  // delay between speed steps
  delay(delayTime);            
  }
}
