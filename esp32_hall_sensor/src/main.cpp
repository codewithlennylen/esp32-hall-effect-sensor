#include <Arduino.h>

/*
 * ESP32 Hall Effect Sensor Example (Internal & External)
 *
 * This example reads:
 * 1. The internal Hall effect sensor (analog value)
 * 2. An external A3144 Hall effect sensor on Pin 4 (digital value)
 *
 * A3144 Wiring:
 * VCC -> 3.3V
 * GND -> GND
 * OUT -> GPIO 4 (Pull-up is handled in code)
 */

const int A3144_PIN = 4;

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Initialize external A3144 sensor pin
  // A3144 is active-low (outputs LOW when magnet is detected)
  pinMode(A3144_PIN, INPUT_PULLUP);

  Serial.println("ESP32 Hall Sensors Initialized");
  Serial.println("------------------------------");
}

void loop() {
  // 1. Read the internal Hall sensor
  int internalHallValue = hallRead();

  // 2. Read the external A3144 sensor
  // A3144 outputs LOW (0) when magnet is detected, HIGH (1) otherwise
  bool externalMagnetDetected = (digitalRead(A3144_PIN) == LOW);



  // Output to serial monitor
  Serial.print("Internal Hall Value: ");
  Serial.print(internalHallValue);
  
  // This threshold needs to be calibrated for the exact setup you have
  if (abs(internalHallValue) > 60) {
    Serial.print(" [Internal Magnet Detected!]");
  }

  Serial.print(" | External A3144: ");
  if (externalMagnetDetected) {
    Serial.println("MAGNET DETECTED");
  } else {
    Serial.println("No magnet");
  }

  delay(500);
}
