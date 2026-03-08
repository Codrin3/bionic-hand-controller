# 🦾 Bionic Hand Controller

A simple, efficient, and responsive controller for a 5-finger bionic hand, built with an ESP microcontroller (ESP8266/ESP32). Each finger is actuated by a dedicated servo motor and controlled via individual push buttons.

![Bionic Hand Pictures]()
![1](https://github.com/user-attachments/assets/5a87579d-fa51-4a22-a1c4-b78868484b11)
![2](https://github.com/user-attachments/assets/9d3ccbfe-3401-4eb9-8588-7c846034a688)

## ✨ Features
* **Cross-Platform Code:** Automatically detects your board (ESP32 or ESP8266) and selects the appropriate libraries and pinouts using preprocessor directives.
* **Creative DIY Mechanics:** Built using accessible materials (cardboard, sewing thread, plastic straws) to simulate human finger articulation.
* **Individual Finger Control:** 5 independent servo motors pull the artificial tendons.
* **Toggle Action:** Press a button once to pull the thread and flex the finger (180°), press it again to release it (0°).
* **Software Debouncing:** Clean and reliable button reads without hardware noise interference.

## 🛠️ Hardware & Materials

**Electronics:**
* 1x **ESP32** OR **ESP8266** (NodeMCU/Wemos D1) development board.
* 5x **Servo Motors** (e.g., SG90 micro servos).
* 5x **Push Buttons** (Tactile switches).
* **External Power Supply:** (e.g., 5V Power Module or Battery Pack) - *Crucial: Do not power 5 servos directly from the ESP board to avoid sudden resets and power drops.*
* Breadboard and Jumper Wires.

**Mechanical Build:**
* **Cardboard:** Cut into the shape of a hand with scored joints for the knuckles.
* **Sewing Thread:** Acts as the tendons pulling the fingers.
* **Plastic Straws:** Cut into small pieces and glued to the cardboard to act as guides for the thread.
* Hot glue or strong tape.

## 🔌 Wiring Guide
1. Connect the 5 buttons to the designated GPIO pins (check the code for default pins based on your board) and GND. 
2. Connect the PWM signal wire of the 5 servos to the designated GPIO pins.
3. Power the servos using your **external 5V power supply**, ensuring the ground (GND) of the external supply is tied to the ground (GND) of the ESP board.
