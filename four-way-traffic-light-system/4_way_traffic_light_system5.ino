//I2C Connection
#include <Wire.h>

int sec = 59;

void setup()
{
  Serial.begin(9600);  // Set COM port baudrate to 9600
  Wire.begin();  //Set I2C Bus as Master
  delay(100);  //delay to sync with the slaves
}

void loop()
{
  Wire.beginTransmission(3);
  Wire.write(sec);
  Wire.endTransmission();
    
  Wire.beginTransmission(2);
  Wire.write(sec);
  Wire.endTransmission();
    
  Wire.beginTransmission(1);
  Wire.write(sec);
  Wire.endTransmission();
    
  Wire.beginTransmission(4);
  Wire.write(sec);
  Wire.endTransmission();
  
  Serial.println(sec);
  
  sec--;
  
  if (sec == 0){
    sec = 59;
  }
   
  delay(1000);
}
  