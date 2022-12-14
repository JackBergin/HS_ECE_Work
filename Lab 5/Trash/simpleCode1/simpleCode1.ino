/*
Example sketch 04

MULTIPLE LEDs.  Make six LEDs dance. Dance LEDs, dance!
// To keep track of all the LED pins, we'll use an "array."
// An array lets you store a group of variables, and refer to them
// by their position, or "index." Here we're creating an array of
// six integers, and initializing them to a set of values:
*/

int ledPins[] = {4,5,6,7,8,9};

void setup()
{
  //create a local variable to store the index of which pin we want to control
  int index;
  // For the for() loop below, these are the three statements:
  //   1. index = 0;  Before starting, make index = 0.
  //   2. index <= 5;   If index is less or equal to 5, run the following code
  //   3. index++   Putting "++" after a variable means "add one to it".
  // When the test in statement 2 is finally false, the sketch
  // will continue.
  // This for() loop will make index = 0, then run the pinMode()
  // statement within the brackets. It will then do the same thing
  // for index = 2, index = 3, etc. all the way to index = 5.

  for(index = 0; index <= 5; index++)
  {
  pinMode(ledPins[index],OUTPUT);
  }
}


void loop()
{
//**************************************************************************************
//**************************************************************************************
//**************************************************************************************

  // This loop() will pick  1 of the 6 programs to run.
  // They have been disabled by commenting them out (putting "//" in front of them)
  // To try different LED programs 1 -6, remove
  // the "//" in front of the program below that you would like to run, and add "//"
  // in front of those you don't want to run. This will comment them out
  // (and disable) those lines of code and thus the program.


//oneAfterAnotherNoLoop();   // Program 1 Light up all the LEDs each in turn. When LED bar is all on reverse and turn them off

//oneAfterAnotherLoop();   // Program 2 Same as Program 1, but with more elegant code

//oneOnAtATime();   // Program 3 Turn on and then off each LED in succession.  Looping around the LED bar, start to finish to start    

//pingPong();   // Program 4 Tennis match back and forth
       
//marquee();   // Program 5 Chase lights like you see on movie or theater signs   
     
//randomLED();   // Program 6 Blink LEDs randomly selected LEDs

//****************************************************************************************
//****************************************************************************************
//****************************************************************************************
}
