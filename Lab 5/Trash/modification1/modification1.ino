/*
Program 1 oneAfterAnotherNoLoop()
This function will light one LED, delay for delayTime, then light
the next LED, and repeat until all the LEDs are on. It will then
turn them off in the reverse order.
*/

void oneAfterAnotherNoLoop()
{
// time (milliseconds) to pause between LEDs
  int delayTime = 100;
  // turn all the LEDs on:
  digitalWrite(ledPins[0], HIGH);  //Turns on LED #0 (pin 4)
  delay(delayTime);              //wait delayTime milliseconds
  digitalWrite(ledPins[1], HIGH);  //Turns on LED #1 (pin 5)
  delay(delayTime);             //wait delayTime milliseconds
  digitalWrite(ledPins[2], HIGH);  //Turns on LED #2 (pin 6)
  delay(delayTime);             //wait delayTime milliseconds
  digitalWrite(ledPins[3], HIGH);  //Turns on LED #3 (pin 7)
  delay(delayTime);             //wait delayTime milliseconds
  digitalWrite(ledPins[4], HIGH);  //Turns on LED #4 (pin 8)
  delay(delayTime);             //wait delayTime milliseconds
  digitalWrite(ledPins[5], HIGH);  //Turns on LED #5 (pin 9)
  delay(delayTime);             //wait delayTime milliseconds
  // turn all the LEDs off:
  digitalWrite(ledPins[5], LOW);   //Turn off LED #5 (pin 9)
  delay(delayTime);             //wait delayTime milliseconds
  digitalWrite(ledPins[4], LOW);   //Turn off LED #4 (pin 8)
  delay(delayTime);             //wait delayTime milliseconds
  digitalWrite(ledPins[3], LOW);   //Turn off LED #3 (pin 7)
  delay(delayTime);             //wait delayTime milliseconds
  digitalWrite(ledPins[2], LOW);   //Turn off LED #2 (pin 6)
  delay(delayTime);             //wait delayTime milliseconds
  digitalWrite(ledPins[1], LOW);   //Turn off LED #1 (pin 5)
  delay(delayTime);             //wait delayTime milliseconds
  digitalWrite(ledPins[0], LOW);   //Turn off LED #0 (pin 4)
  delay(delayTime);             //wait delayTime milliseconds  
}
