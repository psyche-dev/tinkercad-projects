// C++ code
//
void setup()
{
  pinMode(A4, INPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop()
{
  if ((-40 + 0.488155 * (analogRead(A4) - 20)) <= 0) {
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }
  if ((-40 + 0.488155 * (analogRead(A4) - 20)) > 0 && (-40 + 0.488155 * (analogRead(A4) - 20)) <= 50) {
    digitalWrite(12, HIGH);
  } else {
    digitalWrite(12, LOW);
  }
  if ((-40 + 0.488155 * (analogRead(A4) - 20)) > 50 && (-40 + 0.488155 * (analogRead(A4) - 20)) <= 90) {
    digitalWrite(8, HIGH);
  } else {
    digitalWrite(8, LOW);
  }
  if ((-40 + 0.488155 * (analogRead(A4) - 20)) > 90) {
    digitalWrite(4, HIGH);
  } else {
    digitalWrite(4, LOW);
  }
  delay(10); // Delay a little bit to improve simulation performance
}