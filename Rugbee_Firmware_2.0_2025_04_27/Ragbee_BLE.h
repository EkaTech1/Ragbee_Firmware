#ifndef RAGBEE_BLE_H
#define RAGBEE_BLE_H

#include <bluefruit.h>

#include <Arduino.h>
#include "Wire.h"


#include "Ragbee_BLE_message_received.h"  // Include this before using Ble_Received()

//extern BLEUart bleuart;  // Ensure this is accessible
//extern BLEBas  blebas;
extern String Rugbee_Info;

bool Device_Connect_Status = false;

// Define Rugbee_Info here
extern String Rugbee_Info;

BLEDfu  bledfu;
BLEDis  bledis;
//BLEHidAdafruit blehid;
BLEUart bleuart;
BLEBas  blebas;
extern BLEHidAdafruit blehid;
//BLEHidAdafruit blehid;

// Constants
#define MOVE_STEP             10
#define MAX_PRPH_CONNECTION   1

// Global
uint8_t connection_count = 0;


void startAdv() {
  Bluefruit.Advertising.addFlags(BLE_GAP_ADV_FLAGS_LE_ONLY_GENERAL_DISC_MODE);
  Bluefruit.Advertising.addTxPower();
  Bluefruit.Advertising.addService(bleuart);
  Bluefruit.Advertising.addAppearance(BLE_APPEARANCE_HID_MOUSE);
  Bluefruit.ScanResponse.addName();

  Bluefruit.Advertising.addService(blehid);
  Bluefruit.Advertising.restartOnDisconnect(true);
  Bluefruit.Advertising.setInterval(32, 244);
  Bluefruit.Advertising.setFastTimeout(30);
  Bluefruit.Advertising.start(0);
}

void connect_callback(uint16_t conn_handle) {
  BLEConnection* connection = Bluefruit.Connection(conn_handle);
  char central_name[32] = { 0 };
  connection->getPeerName(central_name, sizeof(central_name));

  Serial.print("Connected to ");
  Serial.println(central_name);
  connection_count++;
  Serial.print("🔗 Connection count: ");
  Serial.println(connection_count);

  if (connection_count < MAX_PRPH_CONNECTION) {
    Serial.println("📡 Keep advertising...");
    Bluefruit.Advertising.start(0);
  }
  Initialization_Starting_Message();
  Device_Connect_Status = true;
  Gesture_Input[0] = 'G';                                         
  Gesture_Input[1] = 'C';
}

void disconnect_callback(uint16_t conn_handle, uint8_t reason) {
  (void)conn_handle;
  Serial.print("❌ Disconnected. Reason = 0x");
  Serial.println(reason, HEX);

  if (connection_count > 0) connection_count--;
}

void BLE_setup() {

  char Rugbee_Name[50] = {'R', 'a', 'g', 'b', 'e', 'e', '_', '2', '.', '0', '_'};
  // Copy characters from buffer to Rugbee_Rename array starting from index 7
  for (int i; i <= 39; i++)
  {
    Rugbee_Name[i + 11] = deviceName[i];
  }

  // Replace '-' with ' ' in Rugbee_Rename array
  for (int i = 0; i < 50 ; i++)
  {
    if (Rugbee_Name[i] == '-')
    {
      Rugbee_Name[i] = ' ';
    }
  }


  Serial.println("Starting BLE...");

  Bluefruit.autoConnLed(true);
  Bluefruit.configPrphBandwidth(BANDWIDTH_MAX);
  Bluefruit.begin();
  Bluefruit.setTxPower(4);
  //Bluefruit.setName("Ragbee_none");
  //Bluefruit.setName(deviceName);
  Bluefruit.setName(Rugbee_Name);
  Bluefruit.Periph.setConnInterval(9, 16);
  Bluefruit.Periph.setConnectCallback(connect_callback);
  Bluefruit.Periph.setDisconnectCallback(disconnect_callback);

  bledfu.begin();
  bledis.setManufacturer("Adafruit");
  bledis.setModel("Bluefruit Feather52");
  bledis.begin();
  bleuart.begin();
  blebas.begin();
  blebas.write(100);
  blehid.begin();

  startAdv();

  Serial.println("BLE Ready! Connect via the mobile app.");
}

void BLE_loop() {
  while (bleuart.available()) {
    Ble_Received();  // Now it will be recognized
  }

}

#endif  // RAGBEE_BLE_H
