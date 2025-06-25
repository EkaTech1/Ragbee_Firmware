#ifndef RAGBEE_BLE_MESSAGE_RECEIVED_H
#define RAGBEE_BLE_MESSAGE_RECEIVED_H

#include "Ragbee_BLE.h"
#include "Ragbee_info.h"

// Declare bleuart before use
extern BLEUart bleuart;

char Gesture_Val[20] = {};
void Gesture_Message(String Gesture_Number)
{
  Gesture_Val[0] = Gesture_Number[0];
  Gesture_Val[1] = Gesture_Number[1];
  Gesture_Val[2] = Gesture_Number[2];
  Serial.println("Sending Gesture Message " + String( Gesture_Val));
}

void processReceivedMessage(char *Mobile_Input_char) {
  Serial.print("Received: ");
  Serial.println(Mobile_Input_char);

  if (strcmp(Mobile_Input_char, "IN") == 0) {
    send_Rugbee_Info();  // Now this function is recognized
    bleuart.print("Rugbee Info Sent");  // Now bleuart is accessible
  } // Add mode change handling here
    else if (strcmp(Mobile_Input_char, "GMS") == 0) {
        Change_To_Gesture_Mode();
        bleuart.print("Gesture Mode Activated");
    }
    else if (strcmp(Mobile_Input_char, "GMP") == 0) {
        Change_To_Mouse_Mode();
        bleuart.print("Mouse Mode Activated");
    }
    // Add more modes as needed
    else {
        bleuart.print("Unknown Command");
    }
}

void Ble_Received() {
  char Mobile_Input_char[30] = {0};
  int i = 0;

  // Read available data from BLE UART
  while (bleuart.available() && i < 29) {
    char ch = (char) bleuart.read();
    Serial.write(ch);
    Mobile_Input_char[i++] = ch;
  }
  Mobile_Input_char[i] = '\0';  // Null-terminate the string

  processReceivedMessage(Mobile_Input_char);

  // Convert received data to String for easy processing
  String receivedData = String((char*)Mobile_Input_char);
  receivedData.trim();

  // Process RN (Rename Device)
  if (receivedData.startsWith("RN")) {
    receivedData.substring(2).toCharArray(deviceName, MAX_NAME_LENGTH);
    Bluefruit.setName(deviceName);
    Bluefruit.Advertising.start();
    NVIC_SystemReset();  // Reset system to apply changes

    // Process PN (Phone Name)
  } else if (receivedData.startsWith("PN")) {
    receivedData.substring(2).toCharArray(phoneName, MAX_NAME_LENGTH);

    // Process DG (Delay Value)
  } else if (receivedData.startsWith("DG")) {
    int newValue = receivedData.substring(2).toInt();
    if (newValue > 0 && newValue != Delay_For_Identify_The_Gesture) {
      Delay_For_Identify_The_Gesture = newValue;
      Serial.print("Updated Delay: ");
      Serial.println(Delay_For_Identify_The_Gesture);
    }
  }

  saveNamesToFlash();  // Save updated names to flash
  Serial.println("🔄 Updated Values!");
}
#endif  // RAGBEE_BLE_MESSAGE_RECEIVED_H
