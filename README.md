# Smart Automated Object Sorting System

An embedded mechatronics system simulated in Tinkercad that categorizes objects based on real-time ultrasonic distance measurements and actuates a servo mechanism.

## 📌 Hardware & Components (Simulated)
- **Microcontroller:** Arduino Uno R3
- **Sensors:** Parallax PING))) Ultrasonic Distance Sensor (Pin 7)
- **Actuators:** Micro Servo Motor (Pin 10)
- **Display:** 16x2 Parallel LCD Display (4-bit Mode: Pins 12, 11, 5, 4, 3, 2)

## ⚙️ How It Works
1. **Sensing:** The ultrasonic sensor continuously calculates object distance in centimeters.
2. **Logic:** If an object is detected within **10 cm**, the state-driven code triggers sorting mode.
3. **Actuation:** The servo arm rotates **90°** to divert the object and resets after 2 seconds.
4. **Telemetry:** The 16x2 LCD display provides dynamic distance metrics (`Dist: X cm`) and real-time status updates (`Action: SORT` / `Action: CLEAR`).

## 🛠️ Circuit Simulation & Demo
- **Tinkercad Interactive Simulation:** [Link to your Tinkercad project here]
