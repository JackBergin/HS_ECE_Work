void setup() 
{
   pinMode(13, OUTPUT);
   pinMode(12, OUTPUT);
   pinMode(8, OUTPUT);
}

void loop() 
{
   //These first three lines below will have both red on and blue off
   digitalWrite(13, HIGH);
   digitalWrite(12, LOW);
   digitalWrite(8, HIGH);
   delay(500); //Delay for half a second
   //These second three lines will have only blue on
   digitalWrite(13, LOW);
   digitalWrite(12, HIGH);
   digitalWrite(8, LOW);
   delay(500); //Delay for another half a second
}
