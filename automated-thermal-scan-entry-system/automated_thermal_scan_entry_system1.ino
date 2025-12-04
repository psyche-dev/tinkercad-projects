//Master Arduino

#include <Wire.h>

#include<Servo.h>

float temp;  //declaring temperature sensor as integer

int x;  //declaring incoming data

int del = 10; //delay for blinking

int servoPin = 8;

Servo servo1;

void setup()
{
  Wire.begin();  // Set I2C Bus as Master
  pinMode(11, OUTPUT);  //Red Pin for LED RGB
  pinMode(9, OUTPUT);  // Green pin for LED RGB
  pinMode(10, OUTPUT);  //Blue pin for LED RGB
  pinMode(12, OUTPUT);  //Piezo pin
  servo1.attach(servoPin);
  Serial.begin(9600);  // Set COM port baudrate to 9600
}

void loop()
{
  servo1.write(0);
  
  Wire.requestFrom(1,3);  // Request 3-byte data from Slave 1
  if (Wire.available())  {  //Turns LED RGB Yellow if data available
    x = Wire.read(); //read value from 0 to 254
    
    
    //If distance is allowed
    if (x <= 254) { 
      temp = (-40 + 0.488155 * (x/0.7514792899)); //convert to actual temp in °C
      
      //LED on to prompt successful transfer
      analogWrite(11,255);
      analogWrite(9,255);
      analogWrite(10,0);
      
      //Print Temperature in °C
      Serial.print("Temp: "); 
      Serial.print(temp);
      Serial.print("\xB0"); //Print degree symbol
      Serial.print("C");
      Serial.println("");  //New print line
      
      //If temp < 37 && temp <= 35, blinking red and yellow light
      if (temp < 37 && temp >= 35) {   
        analogWrite(11,0);
        analogWrite(9,255);
        analogWrite(10,0);
        servo1.write(90);
        delay(2000); //allow LED to blink
      }
      
      if (temp > 37) {   
        analogWrite(11,255);
        analogWrite(9,0);
        analogWrite(10,0);
        servo1.write(0);
        tone(12,200,100);
        delay(2000); //allow LED to blink
      }
    
    //if temp sensor unavailable;set the LED off and print String below
    } else { 
      Serial.println("Unavailable to detect temperature");
      analogWrite(11,0);
      analogWrite(9,0);
      analogWrite(10,0);
      servo1.write(0);
      delay(200);
    }
  }
}