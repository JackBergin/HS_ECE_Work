/*
 * Name: Jack Bergin
 * Date: April 3, 2019
 * Class: Electrical Engineering (H)
 * Lab: Modified Touc Sensor
 * Description: The sensor will pick up on a door knock, notify 
 * me with the piezo buzzer and then turn green to let the person into my room
 * 
 */

//Imports the on board accelerometer library
#include "CurieIMU.h"

const int buzzerPin = 6;
int greenLed = 5;
int redLed = 4;

void setup()
{
  //Sets up piezo as output
  pinMode(buzzerPin, OUTPUT);

  //Sets the leds as outputs
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);

  //*****************ALREADY COVERED IN BASIC VIDEO*******************************
  // Initialise the IMU
  CurieIMU.begin();
  CurieIMU.attachInterrupt(eventCallback);
  // Increase Accelerometer range to allow detection of stronger taps (< 3g)
  CurieIMU.setAccelerometerRange(3);
  // Reduce threshold to allow detection of weaker taps (>= 750mg)
  CurieIMU.setDetectionThreshold(CURIE_IMU_TAP, 50); // (750mg)
  // Set the time window for 2 taps as a double tap (<= 250 milliseconds)
  CurieIMU.setDetectionDuration(CURIE_IMU_DOUBLE_TAP, 250);
  // Enable Double-Tap detection
  CurieIMU.interrupts(CURIE_IMU_DOUBLE_TAP);
  //*****************ALREADY COVERED IN BASIC VIDEO*******************************
  Serial.begin(9600);

}

void loop(){}




//Static metod replacing our void method
static void eventCallback()
{
  //If the board is doubletapped
  Serial.println("Waiting for knock");
 
  if (CurieIMU.getInterruptStatus(CURIE_IMU_DOUBLE_TAP))
  {
    Serial.println("Knock on door");
    
    if (CurieIMU.tapDetected(Z_AXIS, NEGATIVE) || CurieIMU.tapDetected(Z_AXIS, POSITIVE))
    {
      digitalWrite(redLed, HIGH);
      delay(1000);
      digitalWrite(redLed, LOW);
      tone(buzzerPin, 400, 1000);
      digitalWrite(greenLed, HIGH);
      delay(1000);
      digitalWrite(greenLed, LOW);
    }
    else
    {
      digitalWrite(greenLed, LOW);
      digitalWrite(redLed, LOW);
    }
  }
}
