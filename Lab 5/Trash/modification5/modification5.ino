/*
Program 5 marquee()

This function will mimic "chase lights" like those around signs.
*/

void marquee()
{
  int index;
  int delayTime = 200; // milliseconds to pause between LEDs
                     // Make this smaller for faster switching
  // Step through the first four LEDs
  // (We'll light up one in the lower 3 and one in the upper 3)
  for(index = 0; index <= 2; index++) // Step from 0 to 3
  {
  digitalWrite(ledPins[index], HIGH); // Turn a LED on
  digitalWrite(ledPins[index+3], HIGH);  // Skip four, and turn that LED on
  delay(delayTime);                   // Pause to slow down the sequence
  digitalWrite(ledPins[index], LOW);  // Turn the LED off
  digitalWrite(ledPins[index+3], LOW);   // Skip four, and turn that LED off
  }
}
