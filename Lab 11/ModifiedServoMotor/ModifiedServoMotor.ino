//include the servo library
#include <Servo.h>  
//create a servo object called servo1
Servo servo1;  

//Variable for the potentiometer
int potValue = 0;

//Degree for the potentiometer to change
int degree = 0;

void setup()
{
  //attach servo1 to pin 9 on the Arduino 101
  servo1.attach(9);

  //Serial monitor initalization
  Serial.begin(9600);
}
void loop()
{
  //Giving the pot an analog value
  potValue = analogRead(A0);

  //Then printing that on serial monitor
  Serial.println(potValue);
  Serial.println("-----");

  //This converts the analog value from the pot 
  //to a degree value
  degree = map(potValue, 0, 1023, 0, 181);
  Serial.print(degree);
  
  //Moves the servo with the degree value
  servo1.write(degree);
  delay(50);
}
