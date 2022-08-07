/*
Program 4 pingPong()

This function will step through the LEDs,
lighting one at at time in both directions.
*/

void pingPong()
{
  int index;
  int delayTime = 100; // milliseconds to pause between LEDs
                     // make this smaller for faster switching
  // step through the LEDs, from 0 to 5
  for(index = 0; index <= 5; index++)
  {
  digitalWrite(ledPins[index], HIGH);  // turn LED on
  delay(delayTime);                 // pause to slow down
  digitalWrite(ledPins[index], LOW);   // turn LED off
  }
  // step through the LEDs, from 5 to 0
  for(index = 5; index >= 0; index--)
  {
  digitalWrite(ledPins[index], HIGH);  // turn LED on
  delay(delayTime);                 // pause to slow down
  digitalWrite(ledPins[index], LOW);   // turn LED off
  }
}
