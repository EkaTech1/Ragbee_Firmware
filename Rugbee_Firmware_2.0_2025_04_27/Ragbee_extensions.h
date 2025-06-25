#ifndef RAGBEE_EXTENSIONS_H
#define RAGBEE_EXTENSIONS_H

void Ble_Received();
void send_Rugbee_Info();
void Initialization_Starting_Message();
void Starting_Message();
void Primary_Up_Gesture();
void Battery_percentage();

#include "Variable.h"
#include "Ragbee_internal.h"
#include "Gesture_Status.h"
#include "Ragbee_BLE.h"
#include "Power_mode.h"
#include "Ragbee_initial_position.h"
#include "Ragbee_BLE_message_received.h"
#include "LSM6DS3_Sensor.h"
#include "Ragbee_info.h"
#include "Quaternary_Gesture.h"
#include "Tertiary_Gesture.h"
#include "Secondary_Gesture.h"
#include "Primary_Gesture.h"

#include "Mouse_movement.h"
#include "Ragbee_LED.h"

#include "Ragbee_mode.h"






#endif
