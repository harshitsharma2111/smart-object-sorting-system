# Smart Automated Object Sorting System

An embedded mechatronics system simulated in Tinkercad that categorizes objects based on real-time ultrasonic distance measurements and actuates a servo mechanism.

---

## 📸 System Overview & Telemetry

| Clear State (Distance > 10 cm) | Sorting State (Distance ≤ 10 cm) |
| :---: | :---: |
| ![Clear State](assets/lcd_clear_state.png) | ![Sort State](assets/lcd_sort_state.png) |
| **Status:** `Action: CLEAR` | **Status:** `Action: SORT` |

### Complete Circuit Wiring
![Circuit Diagram](assets/circuit_overview.png)

### Circuit Schematic
![Schematic](assets/circuit_schematic.png)

---

## 📌 Hardware Components
- **Microcontroller:** Arduino Uno R3
- **Sensor:** Parallax PING))) Ultrasonic Distance Sensor (Pin 7)
- **Actuator:** Micro Servo Motor (Pin 10)
- **Display:** 16x2 Parallel LCD Display (4-bit Mode: Pins 12, 11, 5, 4, 3, 2)

---

## ⚙️ Logic & Telemetry Flow
1. **Ultrasonic Sensing:** Time-of-flight calculated in centimeters via pulse duration.
2. **Dynamic Threshold:** Distance $\le 10\text{ cm}$ triggers sorting sequence.
3. **Actuation:** Micro servo rotates $90^\circ$ for 2 seconds to divert object before resetting.
4. **Live LCD Telemetry:** Line 1 updates real-time distance (`Dist: X cm`), Line 2 outputs system status (`Action: SORT` / `Action: CLEAR`).
