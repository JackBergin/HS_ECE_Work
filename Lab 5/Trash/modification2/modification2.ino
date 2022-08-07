/*
Program 2 oneAfterAnotherLoop()

This function does exactly the same thing as oneAfterAnotherNoLoop(),
but it takes advantage of for() loops and the array to do it with
much less typing.
*/

void oneAfterAnotherLoop()
{
  int index;
  int delayTime = 100; // milliseconds to pause between LEDs
                     // make this smaller for faster switching
  // Turn all the LEDs on:
  // This for() loop will step index from 0 to 5
  // (putting "++" after a variable means add one to it)
  // and will then use digitalWrite() to turn that LED on.
  for(index = 0; index <= 5; index++)
  {
  digitalWrite(ledPins[index], HIGH);
  delay(delayTime);              
  }                                
  // Turn all the LEDs off:
  // This for() loop will step index from 5 to 0
  // (putting "--" after a variable means subtract one from it)
  // and will then use digitalWrite() to turn that LED off.
  for(index = 5; index >= 0; index--)
  {
  digitalWrite(ledPins[index], LOW);
  delay(delayTime);
  }            
}
