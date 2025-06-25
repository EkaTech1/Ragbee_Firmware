
// Battery % code


#include <Adafruit_TinyUSB.h>  // For Serial over native USB

//#define PIN_VBAT A7  // Correct mapping for P0.31 (AIN7)
#define PIN_EN_BAT 14 // P0.14 must be set LOW to enable voltage reading

#define VBAT_DIVIDER_COMP (3.05F)  // Fine-tuned for charging voltage accuracy
#define VBAT_MV_PER_LSB (3000.0F / 1024.0F)  // ~2.93 mV per ADC step (10-bit, 3.0V ref)
#define REAL_VBAT_MV_PER_LSB (VBAT_DIVIDER_COMP * VBAT_MV_PER_LSB)

#define NUM_SAMPLES 5  // Reduced sample count for quicker voltage response

// Enable battery voltage read
void enableBatteryRead() {
  pinMode(PIN_EN_BAT, OUTPUT);
  digitalWrite(PIN_EN_BAT, LOW);  // Activate battery voltage read
  delay(5); // Allow circuit to stabilize
}

// Read the battery voltage with refined filtering
float readVBAT() {
  enableBatteryRead();
  analogReference(AR_INTERNAL_3_0);
  analogReadResolution(10);
  delay(1);

  float totalADC = 0;
  for (int i = 0; i < NUM_SAMPLES; i++) {
    totalADC += analogRead(PIN_VBAT);
    delay(3);  // Slight delay for stable charging voltage measurement
  }

  float avgADC = totalADC / NUM_SAMPLES;
  Serial.print("Averaged ADC Value: ");
  Serial.println(avgADC);

  return avgADC * REAL_VBAT_MV_PER_LSB; // Return battery voltage in mV
}

// Battery Percentage Calculation (Optimized)
uint8_t mvToPercent(float mvolts) {
  if (mvolts < 2700) return 0;  // Below 2.7V, battery empty
  if (mvolts > 4200) return 100;  // Cap at 100%
  
  return (mvolts - 2700) * 100 / (4200 - 2700);  // Linear scaling from 2.7V to 4.2V
}


void Battery_percentage() {
  float vbat_mv = readVBAT();           // Read battery voltage in mV
  uint8_t battPercent = mvToPercent(vbat_mv); // Convert mV to percentage
  Serial.print("VBAT = ");
  Serial.print(vbat_mv / 1000.0F, 2);   // Show voltage in volts
  Serial.print(" V (");
  Serial.print(battPercent);
  Serial.println("%)");                 // Show battery percentage
  delay(1000);
  batteryPercentage = battPercent;
  char BP_String[8];
  //snprintf(batteryPercentage, 1, 0, BP_String);
  snprintf(BP_String, sizeof(BP_String), "%.0f", batteryPercentage);
  char BATT_CHAR[20] = "BP";

  strcat(BATT_CHAR, BP_String);
  bleuart.write(BATT_CHAR);
}
