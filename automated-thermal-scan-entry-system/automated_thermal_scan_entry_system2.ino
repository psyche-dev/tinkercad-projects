//Slave Arduino with Address(1)

#include <Wire.h>

float temp; // declaring temp sensor
int slider = 99; // set initial slider value to 99

long readUltrasonicDistance(int triggerPin, int echoPin) //Distance sensor equation from Tinkercad
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);  // Set COM port baudrate to 9600
  Wire.begin(1);  //Slave Adress Indication
  pinMode(A1, INPUT); //Temp Sensor Pin
  Wire.onRequest(requestEvent); // Called when requested
}

 
void loop()
{

}

void requestEvent()
{
  //temp sensor distance availability; set to <= 100cm
  if (0.01723 * readUltrasonicDistance(A0, A0) <= 100) { 
      slider = (analogRead(A1)-20) * 0.7514792899; //eq to set temp sensor slider to 0-255 
      temp = (-40 + 0.488155 * (slider/0.7514792899)); //temperature reading
      Wire.write(slider); //requested data by the master
      Serial.println(temp); //Print temperature on this monitor
            
  } else { //undetectable distance to detect temperature
      Wire.write(255); //allocated data for undetectable distance
  }
}