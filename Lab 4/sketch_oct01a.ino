/*
Example sketch 03
RGB LED  Make an RGB LED display a rainbow of colors!
*/
//In this basic lab we are using an RGB led which is an 
//led that can display a red blue and green light among 
//other color combinations based off of which annodes of the 
//led have power.

const int RED_PIN = 5;
const int GREEN_PIN = 6;
const int BLUE_PIN = 9;




int DISPLAY_TIME = 10; //Although this was included in the program it was never used.

void setup()
{
   //set the three pin variables as outputs
   pinMode(RED_PIN, OUTPUT);
   pinMode(GREEN_PIN, OUTPUT);
   pinMode(BLUE_PIN, OUTPUT);

   Serial.begin(9600);

}

void loop()
{
   // We've written a custom function called mainColors() that steps
   // through all eight of these colors. We're only "calling" the
   // function here (telling it to run). The actual function code
   // is further down in the sketch.
   mainColors();
}

// Here's the mainColors() custom function we've written.
void mainColors()
{
   // Off (all LEDs off):
   digitalWrite(RED_PIN, LOW);
   digitalWrite(GREEN_PIN, LOW);
   digitalWrite(BLUE_PIN, LOW);
   Serial.println("Off");


   delay(1000); //wait 1 second

   // Red (turn just the red LED on):
   digitalWrite(RED_PIN, HIGH);
   digitalWrite(GREEN_PIN, LOW);
   digitalWrite(BLUE_PIN, LOW);
   Serial.println("Red");

   delay(1000); //wait 1 seconds

   // Green (turn just the green LED on):
   digitalWrite(RED_PIN, LOW);
   digitalWrite(GREEN_PIN, HIGH);
   digitalWrite(BLUE_PIN, LOW);
   Serial.println("Green");

   delay(1000); //wait 1 second

   // Blue (turn just the blue LED on):
   digitalWrite(RED_PIN, LOW);
   digitalWrite(GREEN_PIN, LOW);
   digitalWrite(BLUE_PIN, HIGH);
   Serial.println("Blue");

   delay(1000); //wait 1 second

   // Yellow (turn red and green on):
   digitalWrite(RED_PIN, HIGH);
   digitalWrite(GREEN_PIN, HIGH);
   digitalWrite(BLUE_PIN, LOW);
   Serial.println("Yellow");

   delay(1000); //wait 1 second

   // Cyan (turn green and blue on):
   digitalWrite(RED_PIN, LOW);
   digitalWrite(GREEN_PIN, HIGH);
   digitalWrite(BLUE_PIN, HIGH);
   Serial.println("Cyan");

   delay(1000); //wait 1 second

   // Purple (turn red and blue on):
   digitalWrite(RED_PIN, HIGH);
   digitalWrite(GREEN_PIN, LOW);
   digitalWrite(BLUE_PIN, HIGH);
   Serial.println("Purple");

   delay(1000); //wait 1 second

   // White (turn all the LEDs on):
   digitalWrite(RED_PIN, HIGH);
   digitalWrite(GREEN_PIN, HIGH);
   digitalWrite(BLUE_PIN, HIGH);
   Serial.println("White");

   delay(1000); //wait 1 second
}
