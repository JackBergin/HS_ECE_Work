/*
  Name: Jack Bergin
  Date: April 2, 2019
  Class: Electrical Engineering (H)
  Lab: Modified Touch Sensor
  Description: Used my  elegoo robot and can now control
  it through the touch sensor on the 101 board.The touch
  sensor acts as a on and off button for the bot.

  Could you use the accelerometer attached to your arm to bring the arm up and then forward to act as the 2g movements to initialize the motor.
*/

//Imports the on board accelerometer library
#include "CurieIMU.h"

//defines the motor output pins
int in1 = 6;
int in2 = 7;
int in3 = 8;
int in4 = 9;

//defines the enable output pins
int ENA = 5;
int ENB = 11;

void setup()
{
  //Set the defined pins to the output
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  //These never change state since we are always keeping the arduino and motors enabled
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);


  //*****************ALREADY COVERED IN BASIC VIDEO*******************************
  // Initialise the IMU
  CurieIMU.begin();
  CurieIMU.attachInterrupt(eventCallback);
  // Increase Accelerometer range to allow detection of stronger taps (< 3g)
  CurieIMU.setAccelerometerRange(3);
  // Reduce threshold to allow detection of weaker taps (>= 750mg)
  CurieIMU.setDetectionThreshold(CURIE_IMU_TAP, 750); // (750mg)
  // Set the time window for 2 taps as a double tap (<= 250 milliseconds)
  CurieIMU.setDetectionDuration(CURIE_IMU_DOUBLE_TAP, 250);
  // Enable Double-Tap detection
  CurieIMU.interrupts(CURIE_IMU_DOUBLE_TAP);
  //*****************ALREADY COVERED IN BASIC VIDEO*******************************

  //Sets up serial monitor
  Serial.begin(9600);
}

void loop() {/*Not being used*/}

//method to drive our car forward
void forward()
{
  //Left wheels clockwise
  digitalWrite(in1, HIGH);

  //in2 and 3 act as the left and right wheels' counterclockwise direction
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);

  //Right wheels clockwise
  digitalWrite(in4, HIGH);

  //Keep it going forward for 2 second
  delay(2000);
}

//Static metod replacing our void method
static void eventCallback()
{ 
  //Serial.println("Waiting for a tap");
  //If the board is doubletapped
  if (CurieIMU.getInterruptStatus(CURIE_IMU_DOUBLE_TAP))
  {
    //prints out message on serial monitor
    Serial.println("Double tapped");
    //delays for half a second
    delay(500);
    //It the tap occurs above the board or below to ensure it works
    if (CurieIMU.tapDetected(Z_AXIS, NEGATIVE))
    {
      //Accesses our forward method
      forward();

      //Serial monitor
      Serial.println("Forward: first if");
      //Put this message on the serial monitor for half a second
      delay(500);
    }
    /*
    if (CurieIMU.tapDetected(Z_AXIS, POSITIVE))
    {
      //Accesses our forward method
      forward();

      //Serial monitor
      Serial.println("Forward: second if");
      //Put this message on the serial monitor for half a second
      delay(500);
    }
    */
    else
    {
      //Turns off all motors off
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);

      //Prints out off on serial monitor
      Serial.println("Stop");
      //Put this message on the serial monitor for half a second
      delay(500);
    }
  }
}
