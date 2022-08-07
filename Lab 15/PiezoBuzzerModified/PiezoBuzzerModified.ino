/*
Name: Jack Bergin
Date: 10/23/18
Class: Electrical Engineering (H)
Lab: Button Press Modification
Description: In this tutorial I am showing how, by 
incorperating two leds, a speaker and two buttons 
I am able to make a piano like instrument.
*/

//Left to right with the buttons
 const int button1 = 7;
 const int button2 = 6;
 const int button3 = 5;
 const int button4 = 4;
 
 //Piezo Buzzer pin
 const int piezoPin = 9;    

 
 //create a variable to store a counter and set it to 0
 int counter1 = 0;
 int counter2 = 0;
 int counter3 = 0;
 int counter4 = 0;

void setup()
{
  // Set up the pushbutton pins to be an input:
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);

  //Set up the speaker pin to be outputs:
  pinMode(piezoPin, OUTPUT);

  //Serial monitor is started
  Serial.begin(9600);
}
void loop()
{
  int buttonState1;  
  buttonState1 = digitalRead(button1);

  int buttonState2;
  buttonState2 = digitalRead(button2);

  int buttonState3;
  buttonState3 = digitalRead(button3);

  int buttonState4;
  buttonState4 = digitalRead(button4);

  if (buttonState1 == LOW) 
  {
     counter1++;
     delay(50);
  }

  if (buttonState2 == LOW)
  {
    counter2++;
    delay(50);
  }
  
  if (buttonState3 == LOW) 
  {
     counter3++;
     delay(50);
  }

  if (buttonState4 == LOW)
  {
    counter4++;
    delay(50);
  }


//*****************************************************************
  if(counter1 == 0)
  {
     digitalWrite(piezoPin,LOW);
     Serial.println("Button 1 OFF");
     delay(50);
  }
  //else if counter is equal to 1, redPin is HIGH
  else if(counter1 == 1)
  {
     tone(piezoPin, 330, 50);
     Serial.println("Button 1 Pressed");
     delay(50);
  }
  else
  {
    counter1 = 0;
  }
//-----------------------------------------------------------------
  if(counter2 == 0)
  {
     digitalWrite(piezoPin,LOW);
     Serial.println("Button 2 OFF");
     delay(50);
  }
  //else if counter is equal to 3 bluePin is HIGH
  else if(counter2 == 1)
  {
     tone(piezoPin, 430, 50);
     Serial.println("Button 2 Pressed");
     delay(50);
  }
  //else reset the counter to 0 (which turns all pins off)
  else
  {
    counter2 = 0;
  }
//------------------------------------------------------------------
  if(counter3 == 0)
  {
     digitalWrite(piezoPin,LOW);
     Serial.println("Button 3 OFF");
     delay(50);
  }
  //else if counter is equal to 3 bluePin is HIGH
  else if(counter3 == 1)
  {
     tone(piezoPin, 530, 50);
     Serial.println("Button 3 Pressed");
     delay(50);
  }
  //else reset the counter to 0 (which turns all pins off)
  else
  {
    counter3 = 0;
  }
//--------------------------------------------------------------------
  if(counter4 == 0)
  {
     digitalWrite(piezoPin,LOW);
     Serial.println("Button 4 OFF");
     delay(50);
  }
  //else if counter is equal to 3 bluePin is HIGH
  else if(counter4 == 1)
  {
     tone(piezoPin, 630, 50);
     Serial.println("Button 4 Pressed");
     delay(50);
  }
  //else reset the counter to 0 (which turns all pins off)
  else
  {
    counter4 = 0;
  }
}
