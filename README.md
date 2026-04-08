# Gas & Flame Detection System

[cite_start]A safety monitoring system built with Arduino/ESP32 that detects gas leaks and fire[cite: 1, 7]. [cite_start]The system uses a verification counter to reduce false positives and features a smooth-scrolling LCD interface for alerts[cite: 2, 8].

## Hardware Components
* [cite_start]**Microcontroller**: ESP32 or compatible Arduino board[cite: 5].
* [cite_start]**Gas Sensor**: MQ-series sensor connected to Pin 27[cite: 1].
* [cite_start]**Flame Sensor**: IR-based sensor connected to Pin 26[cite: 1].
* [cite_start]**Buzzer**: Alert siren connected to Pin 25[cite: 1].
* [cite_start]**I2C LCD (16x2)**: Address 0x27, Pins 21 (SDA) & 22 (SCL)[cite: 1, 5].

## Hardware Connection Table

| Component | Arduino/ESP32 Pin | Logic |
| :--- | :--- | :--- |
| **Gas Sensor** | Pin 27 | Input (LOW = Detected) |
| **Flame Sensor** | Pin 26 | Input (LOW = Detected) |
| **Buzzer** | Pin 25 | Output (HIGH = Alarm) |
| **LCD SDA** | Pin 21 | I2C Data |
| **LCD SCL** | Pin 22 | I2C Clock |

## Features
* [cite_start]**False Alarm Prevention**: The system must detect gas or flame for 3 consecutive cycles before triggering the alarm to ensure accuracy[cite: 9, 10, 12].
* [cite_start]**Visual Alerts**: Displays "System Safe" during normal operation and scrolls detailed alerts during hazard detection[cite: 4, 10, 11].
* [cite_start]**Auditory Alarms**: Triggers a continuous buzzer tone when hazards are confirmed[cite: 10, 11, 12].
* [cite_start]**Smooth Scrolling**: Custom function to scroll long alert messages across the I2C LCD[cite: 2, 3].

## Setup Instructions
1. [cite_start]**Wiring**: Connect the sensors, buzzer, and LCD according to the pin definitions above[cite: 1, 5].
2. [cite_start]**Libraries**: Install the `LiquidCrystal_I2C` and `Wire` libraries in your Arduino IDE[cite: 1].
3. [cite_start]**Upload**: Open `src/sketch_apr6a.ino` and upload it to your board[cite: 5].
4. [cite_start]**Monitor**: Open the Serial Monitor at **115200 baud** to view real-time status and sensor values[cite: 5, 7].
