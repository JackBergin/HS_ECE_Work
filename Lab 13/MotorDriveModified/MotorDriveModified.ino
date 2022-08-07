/*
  Name: Jack Bergin
  Date: January 15, 2019
  Class: Electrical Engineering (H)
  Lab: Modified Motor Driver
  Description: Used my old elegoo robot of incorperate four motors and
  run them on a car like structure.
*/

//define motor output pins
int in1 = 6;
int in2 = 7;
int in3 = 8;
int in4 = 9;

//define the enable output pins
int ENA = 5;
int ENB = 11;

void setup()
{
  //Set the defined pins to the output
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  //Turns on and enables the arduino
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);

  //Sets up serial monitor
  Serial.begin(9600);
}

void loop()
{
  //Accesses our forward method
  forward();
  //Stops motor for 500 milliseconds
  halt();

  //Accesses our backward method
  backward();
  //Stops motor for 500 milliseconds
  halt();

  //Accesses left method
  left();
  //Stops motor for 500 milliseconds
  halt();

  //Accesses right method
  right();
  //Stops motor for 500 milliseconds
  halt();
}
//Forward method
void forward()
{
  //Turns on individual motors
  digitalWrite(in1, HIGH); //Left wheels
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); //Right wheels
  Serial.println("Forward");
  delay(500);
}

//Backward method
void backward()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH); //Reverse left wheels
  digitalWrite(in3, HIGH); //Reverse right wheels
  digitalWrite(in4, LOW);
  Serial.println("Back");
  delay(500);
}
//Left method
void left()
{
  digitalWrite(in1, HIGH); //Forward on left wheels
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH); //Backward on right wheels
  digitalWrite(in4, LOW);
  Serial.println("Left");
  delay(500);
}
//Right method
void right()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH); //Forward on right wheels
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); //Backward on left wheels
  Serial.println("Right");
  delay(500);
}

//Stop "halt" method
void halt()
{
  //Turns off all motors off
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  Serial.println("Stop");
  delay(500);
}
