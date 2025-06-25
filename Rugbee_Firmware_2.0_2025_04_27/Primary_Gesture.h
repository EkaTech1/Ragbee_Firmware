//Primary Gesture Logic

// UP - (-Y)
// DOWN - (Y)
//RIGHT - (-Z)
//LEFT - (Z)

void Primary_Up_Gesture() {
  float gyroY = myIMU.readFloatGyroY();
  float gyroZ = myIMU.readFloatGyroZ();
  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);
  if (gyroY <= -Y_threshold) {
    Serial.println(" Up Primary Gesture Activated ");
    Primary_Up = true;
    long int Zero_Start_millis = millis();
    while (Primary_Up) {
      long int Current_millis = millis();
      if ((Current_millis - Zero_Start_millis) >= Delay_For_Identify_The_Gesture * 1000) {
        Primary_Up = false;
        Serial.println(" UP Gesture detected");
        Gesture_Message("G01");
        bleuart.write(Gesture_Val);
        delay(Delay_For_Gesture_Audio_Toast * 1000);
      }
      Primary_Up_Secondary_Left_Gesture();
      Primary_Up_Secondary_Right_Gesture();
      Primary_Up_Secondary_Down_Gesture();
    }
  }
}

void Primary_Down_Gesture() {
  float gyroY = myIMU.readFloatGyroY();
  float gyroZ = myIMU.readFloatGyroZ();
  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);
  if ( gyroY >= Y_threshold) {
    Serial.println(" Down Primary Gesture Activated ");
    Primary_Down = true;
    long int Zero_Start_millis = millis();
    while (Primary_Down) {
      long int Current_millis = millis();
      if ((Current_millis - Zero_Start_millis) >= Delay_For_Identify_The_Gesture * 1000) {
        Primary_Down = false;
        Serial.println(" Down Gesture detected");
        Gesture_Message("G02");
        bleuart.write(Gesture_Val);
        delay(Delay_For_Gesture_Audio_Toast * 1000);
        Reset_All_Gesture_Flags();
      }
      Primary_Down_Secondary_Left_Gesture();
      Primary_Down_Secondary_Right_Gesture();
      Primary_Down_Secondary_Up_Gesture();
    }
  }
}

void Primary_Left_Gesture() {
  float gyroY = myIMU.readFloatGyroY();
  float gyroZ = myIMU.readFloatGyroZ();
  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);
  if (gyroZ >= Z_threshold) {
    Serial.println("Primary Left Gesture Activated ");
    Primary_Left = true;
    long int Zero_Start_millis = millis();
    while (Primary_Left) {
      long int Current_millis = millis();
      if ((Current_millis - Zero_Start_millis) >= Delay_For_Identify_The_Gesture * 1000) {
        Mobile_Screen_Left_Movement();
        Primary_Left = false;
        Serial.println(" Left Gesture detected");
        Gesture_Message("G03");
        bleuart.write(Gesture_Val);
        delay(Delay_For_Gesture_Audio_Toast * 1000);
      }
      Primary_Left_Secondary_Up_Gesture();
      Primary_Left_Secondary_Down_Gesture();
      Primary_Left_Secondary_Right_Gesture();
    }
  }
}

void Primary_Right_Gesture() {
  float gyroY = myIMU.readFloatGyroY();
  float gyroZ = myIMU.readFloatGyroZ();
  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);
  if (gyroZ <= -Z_threshold) {
    Serial.println(" Right Primary Gesture Activated ");
    Primary_Right = true;
    long int Zero_Start_millis = millis();
    while (Primary_Right) {
      long int Current_millis = millis();
      if ((Current_millis - Zero_Start_millis) >= Delay_For_Identify_The_Gesture * 1000) {
        Mobile_Screen_Right_Movement();
        Primary_Right = false;
        Serial.println(" Right Gesture detected");
        Gesture_Message("G04");
        bleuart.write(Gesture_Val);
        delay(Delay_For_Gesture_Audio_Toast * 1000);
      }
      Primary_Right_Secondary_Up_Gesture();
      Primary_Right_Secondary_Down_Gesture();
      Primary_Right_Secondary_Left_Gesture();
    }
  }
}

void Primary_Tilt_Left_Gesture() {
  float gyroX = myIMU.readFloatGyroX();
  float gyroZ = myIMU.readFloatGyroZ();
  Serial.print("\nGyroscope X: "); Serial.println(gyroX, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);
  if (gyroX <= -X_threshold) {

    Serial.println("  Primary_Tilt_Left Gesture detected");

    Primary_Tilt_Left = true;
    delay(500);
    long int Zero_Start_millis = millis();
    while (Primary_Tilt_Left) {
      long int Current_millis = millis();
      if ((Current_millis - Zero_Start_millis) >= Delay_For_Identify_The_Gesture * 1000) {
        Serial.println(" !!!!  No  Gesture movement found . Stop here !!!!");
        Primary_Tilt_Left = false;
        Serial.println("  Only Tilt_Left Gesture detected");
        Gesture_Message("G05");
        bleuart.write(Gesture_Val);
        delay(Delay_For_Gesture_Audio_Toast * 1000);
        break;
      }
      //Primary_Tilt_Left_Secondary_Tilt_Left_Gesture();
    }
  }
}

void Primary_Tilt_Right_Gesture() {
  float gyroX = myIMU.readFloatGyroX();
  float gyroZ = myIMU.readFloatGyroZ();
  Serial.print("\nGyroscope X: "); Serial.println(gyroX, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);
  if (gyroX >= X_threshold) {

    Serial.println("Primary_Tilt_Right Gesture detected");

    Primary_Tilt_Right = true;
    delay(1000);
    long int Zero_Start_millis = millis();
    while (Primary_Tilt_Right) {
      long int Current_millis = millis();
      if ((Current_millis - Zero_Start_millis) >= Delay_For_Identify_The_Gesture * 1000) {
        Serial.println(" !!!!  No  Gesture movement found . Stop here !!!!");
        Primary_Tilt_Right = false;
        Serial.println("  Only Tilt_Right Gesture detected");
        Gesture_Message("G06");
        bleuart.write(Gesture_Val);
        delay(Delay_For_Gesture_Audio_Toast * 1000);
      }
      Primary_Tilt_Right_Secondary_Tilt_Right_Gesture();
    }
  }
}
/*
  void Primary_Tilt_Left_Gesture() {

  float gyroX = myIMU.readFloatGyroX();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope X: "); Serial.println(gyroX, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);
  if (gyroX <= -X_threshold) {
    Serial.println("  Tilt Left Gesture detected");
    Gesture_Message("G05");
    bleuart.write(Gesture_Val);
    delay(Delay_For_Gesture_Audio_Toast * 1000);

  }
  }

  void Primary_Tilt_Right_Gesture() {

  float gyroX = myIMU.readFloatGyroX();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope X: "); Serial.println(gyroX, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);
  if (gyroX >= X_threshold) {
    Serial.println("  Tilt Right Gesture detected");
    Gesture_Message("G06");
    bleuart.write(Gesture_Val);
    delay(Delay_For_Gesture_Audio_Toast * 1000);

  }
  }
*/

void Rugbee_Gesture()
{
  Primary_Up_Gesture();
  Primary_Down_Gesture();
  Primary_Left_Gesture();
  Primary_Right_Gesture();
  Primary_Tilt_Left_Gesture();
  Primary_Tilt_Right_Gesture();
  delay(100);
}
