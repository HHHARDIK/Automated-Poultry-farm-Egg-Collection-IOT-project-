#include <Stepper.h>

#define sensor 7

// Define Constants
const int STEPS_PER_REV = 200;
const int SPEED_CONTROL = A0; // Analog pin for speed control
const int MAX_SPEED = 1500;    // Maximum speed
 Stepper stepper_NEMA17(STEPS_PER_REV, 1, 2, 3, 4);

void setup() {
  Serial.begin(9600);
  // Set the maximum speed initially
  stepper_NEMA17.setSpeed(MAX_SPEED);
  pinMode(sensor, INPUT);
}

void loop() {
  bool value = digitalRead(sensor);
  // Read the sensor value:
  int sensorReading = analogRead(SPEED_CONTROL);
  // Map it to a range from 0 to 100:
  if (value == 0) {
    Serial.println("OFF");
    int motorSpeed = map(sensorReading, 0, 1023, 0, MAX_SPEED);
  // Set the motor speed:
    if (motorSpeed > 0) {
      stepper_NEMA17.setSpeed(motorSpeed);
    // Step 1/100 of a revolution:
      stepper_NEMA17.step(STEPS_PER_REV / 100);
    }
  }
  else{
    Serial.println("ONN");
  }
  
}
