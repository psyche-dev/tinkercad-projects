# Four-Way Traffic Light System on Tinkercad

## 📖 Overview
This project simulates a **Four-Way Traffic Light System** using multiple Arduino Uno R3 boards in **Tinkercad Circuits**. It was developed as a mini-project to assess Computer Engineering interns’ understanding of Arduino programming, embedded systems, and I2C communication.  

The system integrates **traffic signals, pedestrian crossings, and turn signals**, synchronized through a master-slave Arduino setup.

## 🎯 Specifications
- Green LED duration: **10 seconds**
- Yellow LED duration: **5 seconds**
- Red LED duration: **15 seconds**
- Supports **turning vehicles** with dedicated signals
- Each traffic light controlled by a **slave Arduino**
- A **master Arduino** synchronizes all signals via I2C
- LCDs display:
  - Pedestrian crossing animations (walking/standing man)
  - Left-turn arrow
  - Countdown timer for each signal

## 🔧 Components
- 5 × Arduino Uno R3 (1 master, 4 slaves)
- 5 × Breadboards
- 4 × LCDs (16x2) with potentiometers for brightness
- 24 × LEDs (6 per slave Arduino: red, yellow, green)
- Resistors for LEDs and LCDs
- Jumper wires

## ⚡ Circuit Design
The system consists of:
- **Master Arduino**: Generates a 60-second countdown and transmits timing data via I2C.
- **Slave Arduinos**: Control LEDs and LCDs based on received timing signals.
- **Traffic Lights**: Each roadway has a main signal (MS) and a turn/pedestrian signal (TS/PS).
- **LCDs**: Display pedestrian animations, left-turn arrows, and countdown timers.

## 🖥️ Program Structure
### Master Arduino
- Initializes I2C communication (`Wire.h`).
- Sends countdown values to slave Arduinos.
- Synchronizes events with a 100ms delay.

### Slave Arduinos
- Receive timing data from master.
- Execute traffic light events:
  - **Main Signal (MS)**
  - **Turn Signal (TS)**
  - **Pedestrian Signal (PS)**
- Display animations and timers on LCDs.
- Use custom pixel functions for walking/standing man and arrow icons.

## 📊 Traffic Events
| Event | Traffic Light 1 | Traffic Light 2 | Traffic Light 3 | Traffic Light 4 |
|-------|-----------------|-----------------|-----------------|-----------------|
| 1     | Green (MS)      | Red             | Red             | Green (MS)      |
| 2     | Red             | Green (MS)      | Red             | Red             |
| 3     | Red             | Red             | Green (MS)      | Red             |
| 4     | Red             | Red             | Red             | Green (MS)      |

**Legend:**  
- MS = Main Signal  
- TS = Turn Signal  
- PS = Pedestrian Signal  
- R = Red, Y = Yellow, G = Green  

## 🚀 How to Run
1. Open the project in [Tinkercad](https://www.tinkercad.com/).
2. Connect Arduinos via I2C (master + 4 slaves).
3. Wire LEDs and LCDs according to the design.
4. Upload the master and slave codes to respective Arduinos.
5. Start simulation and observe traffic light cycles, pedestrian animations, and countdown timers.

## 🧩 Methodology
- **Planning & Design**: 3 days  
- **Coding & Testing**: 4 days (trial-and-error, LCD animation setup)  
- **Simulation & Analysis**: Multiple hours due to slow runtime  
- **Report Writing & Submission**: Final 2 days  

## 📌 Notes
- LCD animations adapted from *Teach Me Something* YouTube channel.
- Custom functions (`standingMan()`, `runningMan()`, `arrowIcon()`, `pixClear()`) handle LCD graphics.
- Simulation runtime in Tinkercad may be slow; patience is required to verify full cycles.

## 📚 References
1. PLC-based 4 Way Traffic Light Control System – InstrumentationTools  
2. Arduino LCD Animation Man Walking – YouTube  
3. [Arduino Reference](https://www.arduino.cc/en/Reference/HomePage)