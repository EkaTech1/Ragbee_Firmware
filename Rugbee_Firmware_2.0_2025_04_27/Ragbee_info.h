#ifndef RAGBEE_INFO_H
#define RAGBEE_INFO_H

#include "Ragbee_BLE.h"  // Include to access bleuart

#define BUFFER_SIZE 50

String Firmwave_Update_Day   = "27";  
String Firmwave_Update_Month = "Apr";  
int Firmwave_Update_Year     = 2025;

#define Rugbee_Firmware_Version "02.01.01"

// Declare bleuart before using it
extern BLEUart bleuart;

void send_Rugbee_Info() {
    Serial.println("Sending Rugbee Info...");
    
    // Construct firmware info strings
    String firmwareDate = "FD" + String(Firmwave_Update_Month) + " " +  
                          String(Firmwave_Update_Day) + ", " + 
                          String(Firmwave_Update_Year);
    String firmwareTime = "TF" + String(__TIME__);
    
    // Convert and send firmware date
    char firmwareDateChar[20];
    firmwareDate.toCharArray(firmwareDateChar, sizeof(firmwareDateChar));
    Serial.println(firmwareDate);
    bleuart.write(firmwareDateChar);
    delay(3000);
    
    // Convert and send firmware time
    char firmwareTimeChar[20];
    firmwareTime.toCharArray(firmwareTimeChar, sizeof(firmwareTimeChar));
    Serial.println("Sending time");
    Serial.println(firmwareTimeChar);
    bleuart.write(firmwareTimeChar);
    delay(3000);
    
    // Construct and send firmware version
    String firmwareVersion = "VR" + String(Rugbee_Firmware_Version);
    Serial.println(firmwareVersion);
    bleuart.write(firmwareVersion.c_str());
    delay(3000);
    Battery_percentage();
}

#endif  // RAGBEE_INFO_H















/*#define BUFFER_SIZE 30

String Firmwave_Update_Day   = "014";  // 0.
String Firmwave_Update_Month = "Jan";  // Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
int Firmwave_Update_Year     = 2025;

#define FIRMWARE_VERSION_SIZE 10  // Define a valid size
#define Rugbee_Firmware_Version "02.01.01"

void Rugbee_Info() {
    // Check and send battery percentage
    // Battery_Percentage();
    delay(3000); // Allow time for battery status transmission (if necessary)

    // Format firmware update information
    char firmwareInfoData[BUFFER_SIZE];
    snprintf(firmwareInfoData, BUFFER_SIZE, "FD%s %s, %d", 
             Firmwave_Update_Month.c_str(), Firmwave_Update_Day.c_str(), Firmwave_Update_Year);

    char firmwareInfoTime[BUFFER_SIZE];
    snprintf(firmwareInfoTime, BUFFER_SIZE, "TF%s", __TIME__);

    // Send firmware update data
    bleuart.write(firmwareInfoData);
    delay(3000); // Allow time for data to process
    Ble_Received(); // Process BLE response (if needed)

    // Send firmware update time
    bleuart.write(firmwareInfoTime);
    delay(3000);
    Ble_Received();

    // Prepare firmware version string
    char firmwareVersion[FIRMWARE_VERSION_SIZE] = "VR";
    strncat(firmwareVersion, Rugbee_Firmware_Version, FIRMWARE_VERSION_SIZE - strlen(firmwareVersion) - 1);

    // Send firmware version
    bleuart.write(firmwareVersion);
    delay(3000);

    // Send phone nickname
    // bleuart.write(Phone_Nick_name);
    delay(3000);

    // Send "Rugbee Ready" signal
    bleuart.write("Rugbee_Ready");
};*/
