void setup() 
{
   pinMode(13, OUTPUT); //sets ledPin to OUTPUT power
   Serial.begin (9400);
}

void loop() 
{
   digitalWrite(13, HIGH); //Delivers power to the breadboard
   digitalRead (13);
   Serial.println("Led is:    ");
   Serial.println (digitalRead(13));
   delay(1000); //Waits 1 second with pin 13 on high
  
   digitalWrite(13, LOW); //Turns power in pin 13 off
   digitalRead (13);
   Serial.println("Led is:    ");
   Serial.println (digitalRead(13));
   delay(1000);//Waits one second and then loops through and turns
               //power on again
}
