# Automated Thermal Scan Entry System

This project simulates an **automated entry system** that uses a **temperature sensor** and **ultrasonic distance sensor** to determine whether a person is allowed entry. The system integrates **two Arduinos (Master and Slave)** communicating via **I2C**, along with RGB LEDs, a servo motor (for gate control), and a piezo buzzer for alerts.

## 📖 Overview
- **Slave Arduino** measures temperature using a TMP36 sensor and checks distance using an ultrasonic sensor.
- **Master Arduino** receives data from the slave via I2C, processes the temperature, and controls:
  - RGB LED indicators
  - Servo motor (simulating gate opening/closing)
  - Piezo buzzer (alert for high temperature)

This design ensures that only individuals with acceptable body temperature are allowed entry.

## 🔧 Components
- 2 × Arduino Uno R3 (Master + Slave)
- 1 × TMP36 Temperature Sensor
- 1 × Ultrasonic Distance Sensor
- 1 × RGB LED
- 1 × Piezo Buzzer
- 1 × Micro Servo Motor
- Breadboard, resistors, jumper wires

## ⚡ Circuit Logic
- **Slave Arduino (Address 1):**
  - Reads distance from ultrasonic sensor.
  - If distance ≤ 100 cm, reads temperature from TMP36.
  - Converts analog sensor value to temperature (°C).
  - Sends scaled data (0–255) to Master via I2C.
  - If distance > 100 cm, sends `255` (unavailable).

- **Master Arduino:**
  - Requests data from Slave.
  - Converts received value back to temperature (°C).
  - Controls RGB LED:
    - **Yellow** → Data available
    - **Green** → Normal temperature (35–37 °C)
    - **Red** → High temperature (> 37 °C)
  - Controls Servo:
    - **90° (open)** → Normal temperature
    - **0° (closed)** → High temperature or unavailable
  - Activates Piezo buzzer when temperature > 37 °C.

## 📊 Temperature & Distance Logic
| Condition                  | LED Color | Servo | Buzzer |
|----------------------------|-----------|-------|--------|
| No person detected (>100cm)| OFF       | 0°    | OFF    |
| Person detected, Temp 35–37°C | Green    | 90°   | OFF    |
| Person detected, Temp >37°C   | Red      | 0°    | ON     |
| Data available (processing)   | Yellow   | —     | —      |

## 🚀 How to Run
1. Open the project in [Tinkercad](https://www.tinkercad.com/things/hicOZohI0Q1-automated-thermal-scan-entry-system/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard%2Fdesigns%2Fcircuits).
2. Start simulation.
3. Adjust TMP36 sensor and ultrasonic distance to test scenarios.

## 📌 Notes
- Temperature conversion formula:  
```latex
  T(°C) = -40 + 0.488155 * (slider / 0.7514792899)
```
- Servo simulates gate opening/closing.
- Piezo buzzer alerts when temperature exceeds threshold.