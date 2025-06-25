#include "Ragbee_extensions.h"

BLEHidAdafruit blehid;

void setup() {
  Serial.begin(115200);
  internal_file_setup ();
  BLE_setup();
  LSM6DS3_Setup();
  LED_Setup();
}

void loop() {
  BLE_loop();
  Starting_Message();
  LED_loop();
  if (Device_Connect_Status == true && !Starting_Message_Flag)
  {
    Serial.println(" I am connected");
    if( Gesture_Input[0] == 'G'&& Gesture_Input[1] == 'C')
    {
    Rugbee_Gesture();
    }
    else if( Gesture_Input[0] == 'M'&& Gesture_Input[1] == 'C')
    {
    Rugbee_Mouse();
    }
  }
}