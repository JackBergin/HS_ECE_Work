/*
Example sketch 04

// To keep track of all the LED pins, we'll use an "array."
// An array lets you store a group of variables, and refer to them
// by their position, or "index." Here we're creating an array of
// six integers, and initializing them to a set of values:
*/

int ledPins[] = {4,5,6,7,8,9};

void setup()
{
  for(int index = 0; index <= 5; index++)//Index will be the variable for the pin we want to control in the array. 
                                         //It is put in this for loop and can access the array as incremented accordingly.
  {
       pinMode(ledPins[index],OUTPUT);
  }
}


void loop()
{

  // This loop() will pick  1 of the 6 programs to run.
  // They have been disabled by commenting them out (putting "//" in front of them)
  // To try different LED programs 1 -6, remove
  // the "//" in front of the program below that you would like to run, and add "//"
  // in front of those you don't want to run. This will comment them out
  // (and disable) those lines of code and thus the program.


   //oneAfterAnotherNoLoop();   // Program 1 Lights up all the LEDs each in turn. When LED bar is all on it is then reversed and turns them off

   //oneAfterAnotherLoop();   // Program 2 is the as Program 1, but less redundant code

   //oneOnAtATime();   // Program 3 Turns on  the leds and then off each LED in succession, looping around the LED bar, start to finish to start    

   //pingPong();    // Program 4 Simulates a pong type tennis match back and forth between leds
       
   //marquee();    // Program 5 Simulates chase lights like you see on movie or theater signs   
     
   randomLED();   // And Program 6 blinks LEDs that have been randomly selected

}
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


/*
Program 3 oneOnAtATime()

This function will step through the LEDs,
lighting only one at at time.
*/

void oneOnAtATime()
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
}


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
