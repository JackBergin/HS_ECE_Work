#define LED 13
bool state = LOW;
char getstr;

void setup() 
{
   pinMode(LED, OUTPUT);
   Serial.begin(9600);
}

void loop() 
{
   getstr = Serial.read();
   if(getstr == 'A')
   {
     stateChange();
   }
}
void stateChange()
{
   state = !state;
   digitalWrite(LED, state);
}
