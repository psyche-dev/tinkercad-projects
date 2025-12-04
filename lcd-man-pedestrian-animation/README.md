# LCD Pedestrian Animation System with I2C

This project demonstrates how to use **two Arduino Uno boards** with **I2C communication** to control an LCD display that shows pedestrian animations (standing man, running man left/right, slipping animations, and arrow icons). The system simulates a pedestrian crossing indicator with countdown logic.

## 📖 Overview
- **Arduino 2 (Master):** Sends a countdown value (`sec`) to the slave via I2C.
- **Arduino 1 (Slave):** Receives data from the master and displays animations on a 16x2 LCD based on the received value.
- **Animations:** Standing man, running man (left/right), slipping man, and arrow icons.
- **Purpose:** Demonstrates custom LCD character creation and animation sequencing using Arduino.

## 🔧 Components
- 2 × Arduino Uno R3 (Master + Slave)
- 1 × 16x2 LCD Display
- Breadboard
- Jumper wires
- Potentiometer (for LCD contrast)

## ⚡ Circuit Logic
### Arduino 2 (Master)
- Initializes I2C communication.
- Sends a countdown value (`sec`) every second to the slave.
- Prints the countdown to the Serial Monitor.

### Arduino 1 (Slave)
- Receives countdown data via I2C.
- Based on the value of `n`:
  - **n > 10** → Displays **Standing Man**.
  - **5 < n ≤ 10** → Displays **Running Man Right**.
  - **n = 0** → Displays **Running Man Left**.
- Uses `lcd.createChar()` to define custom characters for animations.
- Functions include:
  - `standingMan()`
  - `runningManR()`
  - `runningManL()`
  - `arrowIcon()`
  - `pixClear()` (to clear specific LCD cells without wiping the entire display)

## 📊 Animation Logic
| Countdown Value | Animation Displayed |
|-----------------|----------------------|
| n > 10          | Standing Man         |
| 5 < n ≤ 10      | Running Man Right    |
| n = 0           | Running Man Left     |

## 🚀 How to Run
1. Connect both Arduinos via I2C (Master SDA/SCL → Slave SDA/SCL).
2. Wire the LCD to the Slave Arduino (pins 12, 11, 5, 4, 3, 2).
3. Upload **Master code** to Arduino 2.
4. Upload **Slave code** to Arduino 1.
5. Start simulation in [Tinkercad](https://www.tinkercad.com/).
6. Observe the LCD animations changing as the countdown decreases.

## 📌 Notes
- The project uses **custom LCD characters** to simulate animations.
- `pixClear()` is used instead of `lcd.clear()` to avoid erasing the arrow and timer.
- The simulation may run slowly in Tinkercad due to complex LCD updates.