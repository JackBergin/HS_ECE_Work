/*
  Example sketch 20
  TAP DETECTION
  Use the 101 board's on-board IMU to detect a tap and double tap and react accordingly.
*/
#include "CurieIMU.h"
void setup()
{
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  // Initialise the IMU
  CurieIMU.begin();
  CurieIMU.attachInterrupt(eventCallback);
  // Increase Accelerometer range to allow detection of stronger taps (< 3g)
  CurieIMU.setAccelerometerRange(3);
  // Reduce threshold to allow detection of weaker taps (>= 750mg)
  CurieIMU.setDetectionThreshold(CURIE_IMU_TAP, 100); // (750mg)
  // Set the time window for 2 taps as a double tap (<= 250 milliseconds)
  CurieIMU.setDetectionDuration(CURIE_IMU_DOUBLE_TAP, 250);
  // Enable Double-Tap detection
  CurieIMU.interrupts(CURIE_IMU_DOUBLE_TAP);
}
void loop()
{
  // nothing happens in the loop because all the action happens
  // in the callback function.
}
static void eventCallback()
{
  if (CurieIMU.getInterruptStatus(CURIE_IMU_DOUBLE_TAP))
  {
    if (CurieIMU.tapDetected(Z_AXIS, NEGATIVE))
    {
      digitalWrite(5, HIGH);
      digitalWrite(6, LOW);
      delay(500);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      delay(250);
      digitalWrite(5, HIGH);
      digitalWrite(6, LOW);
      delay(500);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      delay(250);
    }

    else if (CurieIMU.tapDetected(Z_AXIS, POSITIVE))
    {
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);
      delay(500);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      delay(250);
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);
      delay(500);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      delay(250);
    }

    else
    {
      //digitalWrite(5, LOW);
      //digitalWrite(6, LOW);
    }
  }
}
