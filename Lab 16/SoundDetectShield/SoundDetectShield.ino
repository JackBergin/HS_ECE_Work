
/*
Example sketch 15
SOUND DETECTOR
Use the sound detector to measure the volume of the surrounding area and change the
color of an RGB based on that volume.  
audio sensing board with three different outputs.
*/
 //pin variables
const int redPin = 5;
const int greenPin = 6;
const int bluePin = 9;
const int soundPin = 0;
//variables for storing raw sound and scaled value
int sound;
int scale;
void setup()
{
 //start the serial port a@ 9600bps
 Serial.begin(9600);
 //set RGB pins to OUTPUT
 pinMode(redPin, OUTPUT);
 pinMode(greenPin, OUTPUT);
 pinMode(bluePin, OUTPUT);
}
void loop()
{
 //read and store the audio from Envelope pin
 sound = analogRead(soundPin);
 //We use the map function to create a sound scale for the rgb led
//I changed the map values accordingly with my rooms level of silence
 scale = map(sound, 20, 400, 0, 3);

 //print values over the serial port for debugging
 Serial.print(sound);
 Serial.print("   ");
 Serial.println(scale);
 //switch case on scaled value
 switch (scale)
 {
    //if 0 RGB = Blue
    case 0:
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, HIGH);
    delay(500);//pause on
    break;

   //if 1 RGB = Green  
   case 1:
   digitalWrite(redPin, LOW);
   digitalWrite(greenPin, HIGH);
   digitalWrite(bluePin, LOW);
   delay(500);//pause on
   break;

   //if 2 RGB = Yellow  
   case 2:
   digitalWrite(redPin, HIGH);
   digitalWrite(greenPin, HIGH);
   digitalWrite(bluePin, LOW);
   delay(500);//pause on
   break;

   //if 3 RGB = Red
   case 3:
   digitalWrite(redPin, HIGH);
   digitalWrite(greenPin, LOW);
   digitalWrite(bluePin, LOW);
   delay(500);//pause on
   break;

   //default turn off
   default:
   digitalWrite(redPin, LOW);
   digitalWrite(greenPin, LOW);
   digitalWrite(bluePin, LOW);
   delay(500);//pause off
   break;
 }
}
