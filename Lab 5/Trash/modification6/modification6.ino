/*
Program 6 randomLED()

This function will turn on random LEDs. Can you modify it so it
also lights them for random times?
*/

void randomLED()
{
  int index;
  int delayTime;
  // The random() function will return a semi-random number each
  // time it is called. See http://arduino.cc/en/Reference/Random
  // for tips on how to make random() even more random.
 
  //***************************************************************************************************
  //***************************************************************************************************
  //***************************************************************************************************
  index = random(6);  // pick a random LED
  // Try changing this number Try a larger number and then Try a small number
  // See how it effects the Pace.
  // Does not register 0 as a place holder so to use all LEDs you must put in the number 6
  //***************************************************************************************************
  //***************************************************************************************************
  //***************************************************************************************************
  delayTime = 100;
  digitalWrite(ledPins[index], HIGH);  // turn LED on
  delay(delayTime);                 // pause to slow down
  digitalWrite(ledPins[index], LOW);   // turn LED off
}
