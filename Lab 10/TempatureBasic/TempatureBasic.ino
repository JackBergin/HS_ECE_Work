/*
Example sketch 07

A temperature sensor is a device, typically, a 
thermocouple or RTD, that provides for temperature
measurement through an electrical signal. 
A thermocouple (T/C) is made from two dissimilar 
metals that generate electrical voltage in direct 
proportion to changes in temperature.*/

//analog input pin constant
const int tempPin = A1;
//raw reading variable
int tempVal;
//voltage variable
float volts;
//final temperature variables
float tempC;
float tempF;

void setup(){
  // start the serial port at 9600 baud
  Serial.begin(9600);
  //9600 is the “baud rate,” or communications speed. When two devices are communicating with each other, both must be set to the same speed.
}
void loop(){
   //read the temp sensor and store it in tempVal
   tempVal = analogRead(tempPin);
   //converting that reading to voltage by multiplying the reading by 3.3V (voltage of     //the 101 board)
   volts = tempVal * 2;
   volts /= 1023.0;
   //calculate temperature celsius from voltage
   //equation found on the sensor spec.
   tempC = (volts - 0.5) * 100 ;
   // Convert from celcius to fahrenheit
   tempF = (tempC * 9 / 5) + 32;
   //print the fahrenheit temperature over the serial port
   Serial.print(" degrees F: ");
   Serial.println(tempF);
   //wait a bit before taking another reading
   delay(1000);
}
