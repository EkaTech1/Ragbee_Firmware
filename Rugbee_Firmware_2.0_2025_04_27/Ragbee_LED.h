// Ragbee_LED_Code

/* /* This code defines functions for initializing and controlling LEDs, handling interrupts, and performing tests on switches and LEDs.
    The ezOutput.h library is included at the beginning, which is likely used to simplify the process of controlling the output pins for the LEDs.
    The Leds_Initialization() function initializes the pins for the LEDs and sets them to the low state.*/
/*
// RGB LED Status via BLE
  setColor("RED", 1, 0, 0);
  setColor("GREEN", 0, 1, 0);
  setColor("BLUE", 0, 0, 1);
  setColor("YELLOW", 1, 1, 0);
  setColor("CYAN", 0, 1, 1);
  setColor("MAGENTA", 1, 0, 1);
  setColor("WHITE", 1, 1, 1);
*/
    
// Helper function to set LED color and transmit status via BLE

#ifndef RAGBEE_LED_H
#define RAGBEE_LED_H

#include <Arduino.h>
#include <bluefruit.h>

// Note: Using the board's default LED pin definitions (LED_RED, LED_GREEN, LED_BLUE)
// to avoid redefinition warnings. These are typically defined in the board variant files.

// Forward declarations for external variables
extern BLEUart bleuart;
extern float batteryPercentage;

// Timer variables for non-blocking blink
unsigned long blink_previous_millis = 0;
bool blink_led_state = false;

// Sets the RGB LED color using PWM (analogWrite).
// Assumes a common anode LED (higher value = dimmer, 0 = full brightness).
void setLedColor(int r, int g, int b) {
  // Invert values for common anode behavior (255 is off, 0 = on)
  analogWrite(LED_RED, 255 - r);
  analogWrite(LED_GREEN, 255 - g);
  analogWrite(LED_BLUE, 255 - b);
}

void LED_Setup()
{
  // Initialize the pins for the LEDs
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);

  // Ensure all LEDs are off at startup
  setLedColor(0, 0, 0);

  // Display MAC Address
  uint8_t mac[6];
  Bluefruit.getAddr(mac);
  Serial.print("[INFO] MAC Address: ");
  for (int i = 0; i < 6; i++) {
    Serial.print(mac[i], HEX);
    if (i < 5) Serial.print(":");
  }
  Serial.println();
}

void LED_loop()
{
  unsigned long current_millis = millis();

  if (batteryPercentage >= 90) {
    // White for 90% and above
    setLedColor(255, 255, 255);
  }
  else if (batteryPercentage >= 30) {
    // Green for 30-89%
    setLedColor(0, 255, 0);
  }
  else if (batteryPercentage >= 10) {
    // Red for 10% to 30%
    setLedColor(255, 0, 0);
  }
  else {
    // Non-blocking blink Red for below 10%
    if (current_millis - blink_previous_millis >= 500) { // Blink interval: 500ms
      blink_previous_millis = current_millis;
      blink_led_state = !blink_led_state; // Toggle state

      if (blink_led_state) {
        setLedColor(255, 0, 0); // Red
      } else {
        setLedColor(0, 0, 0);   // Off
      }
    }
  }
}

#endif // RAGBEE_LED_H
