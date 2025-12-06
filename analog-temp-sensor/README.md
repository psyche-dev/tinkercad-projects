# Analog Temperature Sensor with and without Arduino Uno

This project demonstrates how to design and simulate an **analog temperature sensor circuit** using the TMP36 sensor in Tinkercad. The circuit is implemented both with and without an **Arduino Uno R3**, showcasing how temperature readings can be processed and displayed through LEDs representing different ranges.


## 🔧 Components Used
- Arduino Uno R3
- Breadboard
- TMP36 Temperature Sensor
- Resistors
- LEDs (4 units)
- Jumper wires
- Power supply (9V battery or USB via Arduino)


## ⚡ Circuit Overview
- The TMP36 sensor outputs an analog voltage proportional to temperature.
- The Arduino reads the sensor value from pin **A4**.
- Based on the calculated temperature, LEDs are activated to indicate ranges:
  - **≤ 0°C** → LED on pin 13
  - **1°C – 50°C** → LED on pin 12
  - **51°C – 90°C** → LED on pin 8
  - **> 90°C** → LED on pin 4


## 🖥️ Arduino Code
```cpp
void setup() {
  pinMode(A4, INPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  float tempC = -40 + 0.488155 * (analogRead(A4) - 20);

  if (tempC <= 0) {
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }

  if (tempC > 0 && tempC <= 50) {
    digitalWrite(12, HIGH);
  } else {
    digitalWrite(12, LOW);
  }

  if (tempC > 50 && tempC <= 90) {
    digitalWrite(8, HIGH);
  } else {
    digitalWrite(8, LOW);
  }

  if (tempC > 90) {
    digitalWrite(4, HIGH);
  } else {
    digitalWrite(4, LOW);
  }

  delay(10); // improve simulation performance
}
```


## 📊 Temperature Ranges
| Temperature (°C) | LED Pin | Status |
|------------------|---------|--------|
| ≤ 0              | 13      | ON     |
| 1 – 50           | 12      | ON     |
| 51 – 90          | 8       | ON     |
| > 90             | 4       | ON     |


## 🚀 How to Run
1. Open the project in [Tinkercad](https://www.tinkercad.com/things/4yxoeg0Ff9X-analog-temperature-sensor-with-and-without-arduino-uno/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard%2Fdesigns%2Fall).
2. Start the simulation and adjust the TMP36 sensor to test different temperature ranges.


## 📌 Notes
- The formula `-40 + 0.488155 * (analogRead(A4) - 20)` converts the analog reading to Celsius.
- Delay is added to stabilize simulation performance.
- This project can be extended with a **Serial Monitor** to display exact temperature values.