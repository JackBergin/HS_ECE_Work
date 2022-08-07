/*
Name: Jack Bergin
Date: 09/28/18
Class: Electrical Engineering (H)
Lab: Bluetooth Low Energy Modification
Description: In this lab I use BLE to turn on and 
off a circuit using a buzzer and rgb led.
 */


#include <CurieBLE.h>
BLEPeripheral blePeripheral;  // This is the BLE Peripheral Device (the board you're programming)
BLEService ledService("19B10000-E8F2-537E-4F6C-D104768A1214"); //BLE LED Service

//This is the BLE characteristic
BLEUnsignedCharCharacteristic switchCharacteristic("19B10001-E8F2-537E-4F6C-D104768A1214", BLERead | BLEWrite);

//Values of the red green and blue annodes of the rgb led.
const int RED_PIN = 5;
const int GREEN_PIN = 6;
const int BLUE_PIN = 9;

void setup() 
{
   pinMode(13, OUTPUT); //Gives power to the buzzer
   pinMode(RED_PIN, OUTPUT); //Gives power to the red part of RGB led
   pinMode(GREEN_PIN, OUTPUT);//Gives power to the green part of the RGB led
   pinMode(BLUE_PIN, OUTPUT);//Gives power to the blue part of the RGB led
  
   //These two commands will advertise a local name and service UUID for the arduino
   blePeripheral.setLocalName("arduino");
   blePeripheral.setAdvertisedServiceUuid(ledService.uuid());
   
   // These two commands add a service and characteristic
   blePeripheral.addAttribute(ledService);
   blePeripheral.addAttribute(switchCharacteristic);
   
   //This command sets the initial value for the characeristic
   switchCharacteristic.setValue(0);
   
   //And this command will begin advertising the BLE service
   blePeripheral.begin();
}

void loop() 
{
   //This line listens for the connection of the BLE peripherals
   BLECentral central = blePeripheral.central();
   
   //if a central is connected to the peripheral then it will access the while loop
   if (central)
   {
      //Once in the while loop we will access the first if
      while (central.connected())
      {
          //The if statement is used to determine if the remote device wrote to the characteristic
          if (switchCharacteristic.written())
          {
             //That value written to the characteristic will now be able to access this statement if the value is greater than 0.
             if (switchCharacteristic.value())
             {  
                 //This for loop will run the entire circuit that's set up on the breadboard.
                 for(int i = 0; i < 10000; i++) 
                 {
                    tone (13, 261); //Plays middle C
                    red(); //Turns on red color
                    delay(1000);

                    tone (13, 277); //Plays C#
                    green(); //Turns on green color etc.
                    delay(1000);

                    tone (13, 294); //Plays D
                    blue();
                    delay(1000);
   
                    tone (13, 311); //Plays D#
                    yellow();
                    delay(1000);
   
                    tone (13, 330); //Plays E
                    cyan();
                    delay(1000);
   
                    tone (13, 349); //Plays F
                    purple();
                    delay(1000);
   
                    tone (13, 370); //Plays F#
                    white();
                    delay(1000);
                 }
             }
          }
      }
   }
}
//These methods set up all of the colors for the RGB led by turning each red, green and blue annode 
//These methods are also used to create different colors by blending the rgb colors.
void red()
{
   digitalWrite(RED_PIN, HIGH);
   digitalWrite(GREEN_PIN, LOW);
   digitalWrite(BLUE_PIN, LOW); 
}
void green()
{
   digitalWrite(RED_PIN, LOW);
   digitalWrite(GREEN_PIN, HIGH);
   digitalWrite(BLUE_PIN, LOW);
}
void blue()
{
   digitalWrite(RED_PIN, LOW);
   digitalWrite(GREEN_PIN, LOW);
   digitalWrite(BLUE_PIN, HIGH);
}
void yellow()
{
   digitalWrite(RED_PIN, HIGH);
   digitalWrite(GREEN_PIN, HIGH);
   digitalWrite(BLUE_PIN, LOW);
}
void cyan()
{
   digitalWrite(RED_PIN, LOW);
   digitalWrite(GREEN_PIN, HIGH);
   digitalWrite(BLUE_PIN, HIGH);
}
void purple()
{
   digitalWrite(RED_PIN, HIGH);
   digitalWrite(GREEN_PIN, LOW);
   digitalWrite(BLUE_PIN, HIGH);
}
void white()
{
   digitalWrite(RED_PIN, HIGH);
   digitalWrite(GREEN_PIN, HIGH);
   digitalWrite(BLUE_PIN, HIGH);
}
