
   // Nickname 
#include <bluefruit.h>   
#include <Adafruit_LittleFS.h>
#include <InternalFileSystem.h>

// Nickname
#define MAX_NAME_LENGTH 20

char deviceName[MAX_NAME_LENGTH] = "2.0";  // Default RN
char phoneName[MAX_NAME_LENGTH] = "2.0";   // Default PN
// Function to save names to internal flash
void saveNamesToFlash() {
    Adafruit_LittleFS_Namespace::File myFile(InternalFS);

    if (myFile.open("names.txt", Adafruit_LittleFS_Namespace::FILE_O_WRITE)) {
        myFile.seek(0);  // Move to the beginning to overwrite
        myFile.write(deviceName, strlen(deviceName));
        myFile.write("\n", 1);
        myFile.write(phoneName, strlen(phoneName));
        myFile.write("\n", 1);
        myFile.close();
        Serial.println("✅ Names saved to Flash.");
    } else {
        Serial.println("❌ Failed to save names.");
    }
}

// Function to load names from flash at startup
void loadNamesFromFlash() {
    Adafruit_LittleFS_Namespace::File myFile(InternalFS);

    if (myFile.open("names.txt", Adafruit_LittleFS_Namespace::FILE_O_READ)) {
        String line1 = myFile.readStringUntil('\n');  // Read first line (Device Name)
        String line2 = myFile.readStringUntil('\n');  // Read second line (Phone Name)

        line1.trim();
        line2.trim();

        line1.toCharArray(deviceName, MAX_NAME_LENGTH);
        line2.toCharArray(phoneName, MAX_NAME_LENGTH);

        myFile.close();
    } else {
        Serial.println("⚠ No saved names found. Using default (NA).");
    }
}

// Function to update name and restart BLE Advertising
void updateName(String input) {
    input.trim();

    if (input.startsWith("RN")) {  // Update Device Name
        input.substring(2).toCharArray(deviceName, MAX_NAME_LENGTH);
        delay(2000);
        saveNamesToFlash();
        // Stop BLE Advertising before changing name
        /*Bluefruit.Advertising.stop();
        Bluefruit.setName(deviceName);
        Bluefruit.ScanResponse.addName();
        Bluefruit.Advertising.start();*/
        NVIC_SystemReset();
    } else if (input.startsWith("PN")) {  // Update Phone Name
        input.substring(2).toCharArray(phoneName, MAX_NAME_LENGTH);
    }

    saveNamesToFlash();
    Serial.println("🔄 Updated Values!");
}

// Callback function when BLE device connects
void onConnect(uint16_t conn_handle) {
    Serial.println("🔗 BLE Connected!");
    
    // Send stored phone name over BLE UART
//    bleUart.print("PN: ");
//    bleUart.println(phoneName);

    Serial.print("📲 Sent PN: ");
    Serial.println(phoneName);
}



void internal_file_setup (){

      delay(2000);

    // Initialize Internal Flash Storage
    while (!InternalFS.begin()) {
        Serial.println("❌ Internal Flash Initialization Failed!");
        return;
    }
    // Load stored names from flash
    loadNamesFromFlash();

  
}
   
