#include<Wire.h>

int sec = 15;
void setup()
{
  Serial.begin(9600);
  Wire.begin();
  delay(100);
}

void loop()
{
  Wire.beginTransmission(1);
  Wire.write(sec);
  Wire.endTransmission();
  Serial.println(sec);
  sec--;
  delay(1000);
}