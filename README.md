# Gas & Flame Detection System

A safety monitoring system built with Arduino/ESP32 that detects gas leaks and fire. The system uses a verification counter to reduce false positives and features a smooth-scrolling LCD interface for alerts.

## Hardware Components
* [cite_start]**Microcontroller:** ESP32 or compatible Arduino board 
* [cite_start]**Gas Sensor:** Connected to Pin 27 [cite: 1]
* [cite_start]**Flame Sensor:** Connected to Pin 26 [cite: 1]
* [cite_start]**Buzzer:** Connected to Pin 25 [cite: 1]
* [cite_start]**I2C LCD (16x2):** Address 0x27, Pins 21 (SDA) & 22 (SCL) [cite: 1, 5]

## Features
* [cite_start]**False Alarm Prevention:** The system must detect gas or flame for 3 consecutive cycles before triggering the alarm[cite: 10, 11, 12].
* [cite_start]**Visual Alerts:** Displays "System Safe" during normal operation [cite: 4] [cite_start]and scrolls detailed alerts during detection[cite: 2, 3].
* [cite_start]**Auditory Alarms:** Triggers a buzzer when hazards are confirmed[cite: 10, 11].

## Setup Instructions
1. Wire the sensors and LCD according to the pin definitions in the code.
2. Install the `LiquidCrystal_I2C` library in your Arduino IDE.
3. Upload `sketch_apr6a.ino` to your board.
4. [cite_start]Open the Serial Monitor at 115200 baud to view real-time status[cite: 5, 7].# Gas-Flame-Detection-System
An Arduino-based safety system that detects gas leaks and fire using ESP32/Arduino, featuring an I2C LCD and buzzer alerts
