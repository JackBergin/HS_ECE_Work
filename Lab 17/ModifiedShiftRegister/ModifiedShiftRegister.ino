
/*
  Name: Jack Bergin
  Date: 2/3/19
  Class: Electrical Engineering (H)
  Lab: Shift Register Modification
  Description: In this lab we are using the eight additional pins from the shift
  register to act as a measurement on the sound detector used in the previous lab.
*/

// Pin definitions:
// The shift register uses a type of serial connection called SPI
// (Serial Peripheral Interface) that requires three pins:
int datapin = 2;
int clockpin = 3;
int latchpin = 4;
// We'll also declare a global variable for the data we're
// sending to the shift register:
byte data = 0;

//This will be the pin that we use for our analoug value for the sound detector
const int soundPin = A0;

//variables for storing raw sound and scaled values for sound detector
int sound;
int scale;

//Allows me to mess with the delay time by changing only one constant variable
int delaytime = 20;

void setup()
{
  // Set the three SPI pins to be outputs:
  pinMode(datapin, OUTPUT);
  pinMode(clockpin, OUTPUT);
  pinMode(latchpin, OUTPUT);
  //start the serial port a@ 9600bps
  Serial.begin(9600);
}

//Coverend this method in the basic tutorial
//(But in short it acts as a digitalWrite but for the shift register)
void shiftWrite(int desiredPin, boolean desiredState)
{
  bitWrite(data, desiredPin, desiredState);
  shiftOut(datapin, clockpin, MSBFIRST, data);
  digitalWrite(latchpin, HIGH);
  digitalWrite(latchpin, LOW);
}
//After a case statement is declared and LED/LEDs are turned 
//on it will shut them off to reset for another case statement
void resetLED()
{
  //Have all of our LEDs (1-7) turned off in four loop
  for (int i = 0; i <= 6; i++)
  {
    shiftWrite(i, LOW);
  }
}

void loop()
{
  //read and store the audio from Envelope pin
  sound = analogRead(soundPin);
  //We use the map function to create a sound scale for the 7 leds set up with the shift register
  //I changed the map values accordingly with my rooms level of silence
  scale = map(sound, 12, 150, 0, 6);

  //print values over the serial port for debugging
  Serial.print("Sound: ");
  Serial.println(sound);
  //Serial.print("   ");
  Serial.print("Scale: ");
  Serial.println(scale);

  //switch case on scaled value
  switch (scale)
  {
    //if 0 LED = 1Blue
    case 0:
      //Turns on the LED as wanted
      shiftWrite(0, HIGH);

      //Prints out which LED(s) are being turned on, on Serial monitor
      Serial.println("1 Blue LED ON");

      delay(delaytime);//pause on

      //Resets the leds for the next case
      resetLED();
      break;

    //if 1 LED = 2Blue
    case 1:
      //Turns on the LEDs as wanted
      shiftWrite(0, HIGH);
      shiftWrite(1, HIGH);

      //Prints out which LED(s) are being turned on, on Serial monitor
      Serial.println("2 Blue LEDs ON");

      delay(delaytime);//pause on

      //Resets the leds for the next case
      resetLED();
      break;

    //if 2 LED = 2Blue, 1Yellow
    case 2:
      //Turns on the LEDs as wanted
      shiftWrite(0, HIGH);
      shiftWrite(1, HIGH);
      shiftWrite(2, HIGH);

      //Prints out which LED(s) are being turned on, on Serial monitor
      Serial.println("2 Blue & 1 Yellow LED ON");

      delay(delaytime);//pause on
      
      //Resets the leds for the next case
      resetLED();
      break;

    //if 3 LED = 2Blue, 2Yellow
    case 3:
      //Turns on the LEDs as wanted
      shiftWrite(0, HIGH);
      shiftWrite(1, HIGH);
      shiftWrite(2, HIGH);
      shiftWrite(3, HIGH);

      //Prints out which LED(s) are being turned on, on Serial monitor
      Serial.println("2 Blue & 2 Yellow LEDs ON");

      delay(delaytime);//pause on
      
      //Resets the leds for the next case
      resetLED();
      break;

    //if 4 LED = 2Blue, 2Yellow, 1 Green
    case 4:
      //Turns on the LEDs as wanted
      shiftWrite(0, HIGH);
      shiftWrite(1, HIGH);
      shiftWrite(2, HIGH);
      shiftWrite(3, HIGH);
      shiftWrite(4, HIGH);

      //Prints out which LED(s) are being turned on, on Serial monitor
      Serial.println("2 Blue & 2 Yellow & 1 Green LED ON");

      delay(delaytime);//pause on
      
      //Resets the leds for the next case
      resetLED();
      break;

    //if 5 LED = 2Blue, 2Yellow, 2 Green
    case 5:
      //Turns on the LEDs as wanted
      shiftWrite(0, HIGH);
      shiftWrite(1, HIGH);
      shiftWrite(2, HIGH);
      shiftWrite(3, HIGH);
      shiftWrite(4, HIGH);
      shiftWrite(5, HIGH);

      //Prints out which LED(s) are being turned on, on Serial monitor
      Serial.println("2 Blue & 2 Yellow & 2 Green LEDs ON");

      delay(delaytime);//pause on
      
      //Resets the leds for the next case
      resetLED();
      break;

    //if 6 LED = 2Blue, 2Yellow, 2 Green
    case 6:
      //Turns on the LEDs as wanted
      shiftWrite(0, HIGH);
      shiftWrite(1, HIGH);
      shiftWrite(2, HIGH);
      shiftWrite(3, HIGH);
      shiftWrite(4, HIGH);
      shiftWrite(5, HIGH);
      shiftWrite(6, HIGH);

      //Prints out which LED(s) are being turned on, on Serial monitor
      Serial.println("2 Blue & 2 Yellow & 3 Green LEDs ON");

      delay(delaytime);//pause on
     
      //Resets the leds for the next case
      resetLED();
      break;


      //default turn off
    default:
      //Puts all LEDs off
      resetLED();

      Serial.println("Default, all LEDs off");
      delay(delaytime);//pause off
      break;
  }
}
