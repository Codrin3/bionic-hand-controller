// Note: If using an ESP8266, replace this with #include <Servo.h>
#include <ESP32Servo.h> 

const int NUM_FINGERS = 5;

// TODO: Update these pins according to your specific ESP8266 wiring
const int servoPins[NUM_FINGERS] = {12, 27, 13, 25, 34}; 
const int buttonPins[NUM_FINGERS] = {14, 33, 32, 26, 2};

Servo servos[NUM_FINGERS];

int buttonStates[NUM_FINGERS] = {0};
int lastButtonStates[NUM_FINGERS] = {0};
bool fingerExtended[NUM_FINGERS] = {false}; // false = 0 degrees, true = 180 degrees

void setup() {
  Serial.begin(115200);
  Serial.println("Bionic Hand System started");

  for (int i = 0; i < NUM_FINGERS; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
    servos[i].attach(servoPins[i]);
    servos[i].write(0); 
  }
}

void loop() {
  for (int i = 0; i < NUM_FINGERS; i++) {
    buttonStates[i] = digitalRead(buttonPins[i]);

    // Execute action only on button press (HIGH to LOW transition)
    if (buttonStates[i] == LOW && lastButtonStates[i] == HIGH) {
      
      if (fingerExtended[i]) {
        servos[i].write(0);
        Serial.printf("Finger %d retracted (0 degrees)\n", i);
      } else {
        servos[i].write(180);
        Serial.printf("Finger %d extended (180 degrees)\n", i);
      }

      fingerExtended[i] = !fingerExtended[i];
      
      // Debouncing to ignore mechanical button noise
      delay(300);
    }

    lastButtonStates[i] = buttonStates[i];
  }
  
  delay(10);
}