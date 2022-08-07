/*
Name: Jack Bergin
Date: 10/1/18
Class: Electrical Engineering (H)
Lab: RGB Led modification experiment
Description:
  In this lab I made a random number generator to chose which color is displayed on the RGB led. 
  I also added three leds to the circuit to show the different color schemes that make up the color
  that is displayed on the RGB led.  
*/

const int RED_PIN = 5;
const int GREEN_PIN = 6;
const int BLUE_PIN = 9;

int redLed = 13;
int greenLed = 12;
int blueLed = 11;

void setup()
{
   //set the three pin variables as outputs
   pinMode(RED_PIN, OUTPUT);
   pinMode(GREEN_PIN, OUTPUT);
   pinMode(BLUE_PIN, OUTPUT);

   //Sets the three modified pins to outputs
   pinMode(redLed, OUTPUT);
   pinMode(greenLed, OUTPUT);
   pinMode(blueLed, OUTPUT);

   Serial.begin(9600);

}

void loop()
{
   //The loop contionusly runs the main colors method forever
   mainColors();
}
   
void mainColors()
{
   //Sets up the random numbers to have a minimum and maximum
   int min = 1;
   int max = 8;

   //This is the random number generator generating numbers between 1 and 8
   int randomNumb = random(min,max);

   if(randomNumb == 1)
   {
      // Off (all LEDs off):
      digitalWrite(RED_PIN, LOW);
      digitalWrite(GREEN_PIN, LOW);
      digitalWrite(BLUE_PIN, LOW);

      //All individual leds off
      digitalWrite(redLed, LOW);
      digitalWrite(greenLed, LOW);
      digitalWrite(blueLed, LOW);
      
      Serial.println("Off");
      delay(3000); //wait 1 second
   }
   
   //For example, if the random number was two it would access this if statement
   if(randomNumb == 2)
   {
      //Where the color red is displayed by the RGB Led
      digitalWrite(RED_PIN, HIGH);
      digitalWrite(GREEN_PIN, LOW);
      digitalWrite(BLUE_PIN, LOW);

      //And the red led would light up on the bread board
      digitalWrite(redLed, HIGH);
      digitalWrite(greenLed, LOW);
      digitalWrite(blueLed, LOW);
      
      //This statement will send the serial monitor 
      //"red" which dentoes which color is being displayed. 
      Serial.println("Red");

      //And this statement will give a 1 second delay before 
      //going back to the random number generator for a new 
      //number to be created.
      delay(3000); //wait 1 second
   }

   if(randomNumb == 3)
   {
      // Green (turn just the green LED on):
      digitalWrite(RED_PIN, LOW);
      digitalWrite(GREEN_PIN, HIGH);
      digitalWrite(BLUE_PIN, LOW);

      //Turns on the individual green led
      digitalWrite(redLed, LOW);
      digitalWrite(greenLed, HIGH);
      digitalWrite(blueLed, LOW);

      //Tells serial monitor which color
      Serial.println("Green");
      delay(3000); //wait 1 second
   }

   if(randomNumb == 4)
   {
      // Blue (turn just the blue LED on):
      digitalWrite(RED_PIN, LOW);
      digitalWrite(GREEN_PIN, LOW);
      digitalWrite(BLUE_PIN, HIGH);

      //Shows blue individal blue led
      digitalWrite(redLed, LOW);
      digitalWrite(greenLed, LOW);
      digitalWrite(blueLed, HIGH);
     
      //Tells serial monitor which color
      Serial.println("Blue");
      delay(3000); //wait 1 second
   }

   if(randomNumb == 5)
   {
      // Yellow (turn red and green on):
      digitalWrite(RED_PIN, HIGH);
      digitalWrite(GREEN_PIN, HIGH);
      digitalWrite(BLUE_PIN, LOW);

      //Shows color scheme to make yellow
      digitalWrite(redLed, HIGH);
      digitalWrite(blueLed, LOW);
      digitalWrite(greenLed, HIGH);

      //Tells serial monitor which color
      Serial.println("Yellow");
      delay(3000); //wait 1 second
   }

   if(randomNumb == 6)
   {
      // Cyan (turn green and blue on):
      digitalWrite(RED_PIN, LOW);
      digitalWrite(GREEN_PIN, HIGH);
      digitalWrite(BLUE_PIN, HIGH);

      //Shows color scheme to make cyan
      digitalWrite(redLed, LOW);
      digitalWrite(greenLed, HIGH);
      digitalWrite(blueLed, HIGH);
      
      //Tells serial monitor which color
      Serial.println("Cyan");
      delay(3000); //wait 1 second
   }

   if(randomNumb == 7)
   {
      // Purple (turn red and blue on):
      digitalWrite(RED_PIN, HIGH);
      digitalWrite(GREEN_PIN, LOW);
      digitalWrite(BLUE_PIN, HIGH);

      //Shows color scheme to make purple
      digitalWrite(redLed, HIGH);
      digitalWrite(greenLed, LOW);
      digitalWrite(blueLed, HIGH);
      
      //Tells serial monitor which color
      Serial.println("Purple");
      delay(3000); //wait 1 second
   }

   if(randomNumb == 8)
   {
      // White (turn all the LEDs on):
      digitalWrite(RED_PIN, HIGH);
      digitalWrite(GREEN_PIN, HIGH);
      digitalWrite(BLUE_PIN, HIGH);
      
      //Shows color scheme to make white
      digitalWrite(redLed, HIGH);
      digitalWrite(greenLed, HIGH);
      digitalWrite(blueLed, HIGH);
     
      //Tells serial monitor which color
      Serial.println("White");
      delay(3000); //wait 1 second
   }
}
