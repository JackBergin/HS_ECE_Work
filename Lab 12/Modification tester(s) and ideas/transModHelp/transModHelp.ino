// constant pin for the transistor connected to the motor
const int motorPin = 9;

//This is for the analog input pin the pot is connected to
int sensorPin1 = A0;
int sensorPin2 = A1;

void setup() 
{
   //set motorPin as OUTPUT
   pinMode(motorPin, OUTPUT);

   //Begins serial monitor
   Serial.begin(9600); 
}

void loop() 
{
       
       
       //Sets up our potentiometer analoug value
       int sensorValue1 = analogRead(sensorPin1); 
       //Checks if potentiometer is working
       Serial.println("Potentiometer 1: " + sensorValue1);
       
       //Converts pot Values to 0-255 value for motor
       int newMotorSpeed = map(sensorValue1, 0, 1023, 0, 254);

       
       //Creates a ratio of 1 to then multiply to the speed to change speed
       //int ratio1 = sensorValue1/1024;
       //Checks to see if the ratio is working
       Serial.println("Speed: " + newMotorSpeed);
       //Maximum speed
       //int maxMotorSpeed = 255;
       //New variable speed
       //int newMotorSpeed = maxMotorSpeed * ratio1;

       //Sets up our potentiometer analoug value
       int sensorValue2 = analogRead(sensorPin2);
       //Checks to see if the potentiometer is working
       Serial.println("Potentiometer 2: " + sensorValue2);
       
       //Converts pot Values to 0-3000 value for time
       int differentTime = map(sensorValue2, 0, 1023, 0, 2999);       
       
       //Creates a ratio from our potentiometer to multiply to our max time 
       //int ratio2 = sensorValue2/1024;
       //Checks to see if the conversion is working
       Serial.println("Ratio 1: " + differentTime);
       //Max time we need
       //int maxTime = 3000;
       //Variable times by multiplying the ma time by the ratio
       //int differentTime = maxTime*ratio2;
       
       //Sets up the motor to run at a different potentiometer input speed
       analogWrite(motorPin, newMotorSpeed);  
       // delay for differentTime variable 
       delay(differentTime);   
       // turns the motor Off
       analogWrite(motorPin, 0);  
       //delays for delayTime
       delay(differentTime);
       // delay for offTime milliseconds
       Serial.println("Speed of Motor: " + newMotorSpeed);
       delay(100);
}
