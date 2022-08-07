int ENA=5; int IN1=6; int IN2=7; int ENB=11; int IN3=8; int IN4=9; void setup() {
pinMode(IN1,OUTPUT); pinMode(IN2,OUTPUT); pinMode(IN3,OUTPUT); pinMode(IN4,OUTPUT); pinMode(ENA,OUTPUT); pinMode(ENB,OUTPUT); digitalWrite(ENA,HIGH); digitalWrite(ENB,HIGH);
}
void loop()
{
 
 
 digitalWrite(IN1,HIGH); digitalWrite(IN2,LOW); digitalWrite(IN3,LOW); digitalWrite(IN4,HIGH); delay(500); digitalWrite(IN1,LOW); digitalWrite(IN2,LOW); digitalWrite(IN3,LOW); digitalWrite(IN4,LOW); delay(500);
// left wheel goes forward // right wheel goes forward
//left wheel holds still
// right wheel holds still

digitalWrite(IN1,LOW); digitalWrite(IN2,HIGH); digitalWrite(IN3,HIGH); digitalWrite(IN4,LOW); delay(500); digitalWrite(IN1,LOW); digitalWrite(IN2,LOW); digitalWrite(IN3,LOW); digitalWrite(IN4,LOW); delay(500);
//left wheel is back up // right wheel is back up
// left wheel holds still // right wheel holds still
}
