/*
  Example sketch 19
  Controlling a Motor Using an Accelerometer
  Use the on-board accelerometer of the 101 board as an input to control
  a motor based on its orientation in space. If you tilt the 101 to the left,
  the motor spins in one direction; tilted to the right, it spins the opposite direction; and if it
  is flat, the motor stops.
*/
#include "CurieIMU.h"

const int DIR_A = 4;
const int DIR_B = 5;
const int PWM = 6;
// previous orientation (for comparison). Start at (-1) to start with

void setup()
{
  //set motor control pins to OUTPUT
  pinMode(DIR_A, OUTPUT);
  pinMode(DIR_B, OUTPUT);
  pinMode(PWM, OUTPUT);
  // Start the acceleromter
  CurieIMU.begin();
  // Set the accelerometer range to 2G
  CurieIMU.setAccelerometerRange(2);

  //Sets up the serial monitor
  Serial.begin(9600);
}
void loop()
{
  // read accelerometer:
  int x = CurieIMU.readAccelerometer(X_AXIS);
  int y = CurieIMU.readAccelerometer(Y_AXIS);
  int z = CurieIMU.readAccelerometer(Z_AXIS);
 
  // calculate the absolute values, to determine the largest
  int absX = abs(x);
  int absY = abs(y);
  int absZ = abs(z);
  if ( (absZ > absX) && (absZ > absY))
  {
    // base orientation on Z
    if (z > 0)
    {
      brake();
      Serial.println("Stop");
      delay(100);
    }
  }
  
  //else if Y is greater than X and Z its on edge
  else if ( (absY > absX) && (absY > absZ))
  {
    // if Y is positive orientation (digital pins up)and is set to 1
    if (y > 0)
    {
      forward();
      Serial.println("Forward");
      delay(100);
    }
    //the Y is in the negative orientation (analog pins up) and is set to 2
    else
    {
      reverse();
      Serial.println("Backward");
      delay(100);
    }
  }
  // Add additional programs below this line
}
//custom function for driving the motor forward
void forward()
{
  digitalWrite(DIR_A, HIGH);
  digitalWrite(DIR_B, LOW);
  digitalWrite(PWM, HIGH);
}
//custom function for driving the motor in reverse
void reverse()
{
  digitalWrite(DIR_A, LOW);
  digitalWrite(DIR_B, HIGH);
  digitalWrite(PWM, HIGH);
}
//custom function for braking the motor
void brake()
{
  digitalWrite(DIR_A, LOW);
  digitalWrite(DIR_B, LOW);
  digitalWrite(PWM, LOW);
}
