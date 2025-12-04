# Fire Alarm System with Temperature and Gas Sensor

This project simulates a **fire alarm system** using Arduino Uno in **Tinkercad Circuits**. It integrates a **temperature sensor** and a **gas sensor** to detect hazardous conditions. When thresholds are exceeded, the system activates an LED and a piezo buzzer to signal an alarm.

## 📖 Overview
- **Temperature Sensor (A1):** Reads ambient temperature.
- **Gas Sensor (A0):** Detects gas concentration levels.
- **LED (Pin 13):** Lights up when temperature exceeds 80°C.
- **Piezo Buzzer (Pin 7):** Sounds when gas concentration exceeds threshold.
- **Serial Monitor:** Displays real-time temperature and gas sensor readings.

This project demonstrates how Arduino can be used for **safety monitoring systems**.

## 🔧 Components
- Arduino Uno R3
- Temperature sensor (e.g., LM35/TMP36)
- Gas sensor (e.g., MQ series)
- LED
- Piezo buzzer
- Breadboard, resistors, jumper wires

## ⚡ Circuit Logic
1. **Temperature Calculation:**
   - Sensor output is read from pin A1.
   - Converted to millivolts:  
     \[
     V_{out1} = \frac{analogRead(A1)}{1023} \times 5000
     \]
   - Temperature in °C:  
     \[
     T = \frac{V_{out1} - 500}{10}
     \]

2. **Gas Sensor Reading:**
   - Sensor value read from pin A0.
   - Threshold set at **100** (analog value).

3. **Alarm Conditions:**
   - If **temperature ≥ 80°C**, LED turns ON.
   - If **gasSensor ≥ 100**, buzzer turns ON.
   - Otherwise, both remain OFF.

## 📊 Output Example
- **Serial Monitor:**
  ```
  in DegreeC= 85   GasSensor= 120
  ```
- LED ON when temperature ≥ 80°C.
- Buzzer ON when gasSensor ≥ 100.

## 🚀 How to Run
1. Open the project in [Tinkercad](https://www.tinkercad.com/things/1ufsRFCBvlm-fire-alarm-system/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard%2Fdesigns%2Fcircuits).
2. Build the circuit with the listed components.
3. Upload the provided code to Arduino Uno.
4. Start simulation.
5. Adjust sensor values to test alarm conditions.

## 📌 Notes
- Thresholds (80°C and gasSensor ≥ 100) can be adjusted depending on sensitivity requirements.
- This project is a **simulation**; real-world deployment requires calibration and safety certification.