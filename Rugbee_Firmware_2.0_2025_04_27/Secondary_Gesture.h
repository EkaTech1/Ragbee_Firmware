// Secondary_Gesture Logic


//**************************************************************************************************************  Primary_Up_Secondary_Left_Gesture
void Primary_Up_Secondary_Left_Gesture()
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroZ >= Z_threshold) {

    Serial.println("Left Secondary Gesture Activated ");

    Primary_Up_Secondary_Left = true;
    long int Zero_Start_millis = millis();
    while (Primary_Up_Secondary_Left == true)
    {
      long int Current_millis = millis();
      if ((Current_millis - Zero_Start_millis) >= Delay_For_Identify_The_Gesture * 1000)
      {
        Primary_Up_Secondary_Left = false;
        Primary_Up = false;
        Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");
        Gesture_Message("G15");
        bleuart.write(Gesture_Val);
        Serial.println("Send the gesture value  =  " + String(Gesture_Val));
        delay(Delay_For_Gesture_Audio_Toast * 1000);
      }
      Primary_Up_Secondary_Left_Tertiary_Up_Gesture();
      Primary_Up_Secondary_Left_Tertiary_Down_Gesture();
    }
  }
}

//**************************************************************************************************************  Primary_Up_Secondary_Right_Gesture
void Primary_Up_Secondary_Right_Gesture()
{

  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroZ <= -Z_threshold)
  {
    Serial.println("Right Secondary Gesture Activated ");

    Primary_Up_Secondary_Right = true;
    long int Zero_Start_millis = millis();
    while (Primary_Up_Secondary_Right == true)
    {
      long int Current_millis = millis();
      if ((Current_millis - Zero_Start_millis) >= Delay_For_Identify_The_Gesture * 1000)
      {
        Primary_Up_Secondary_Right = false;
        Primary_Up = false;
        Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");
        Gesture_Message("G13");
        bleuart.write(Gesture_Val);
        Serial.println("Send the gesture value  =  " + String(Gesture_Val));
        delay(Delay_For_Gesture_Audio_Toast * 1000);
      }
      Primary_Up_Secondary_Right_Tertiary_Up_Gesture();
      Primary_Up_Secondary_Right_Tertiary_Down_Gesture();
    }
  }
}

//**************************************************************************************************************  Primary_Down_Secondary_Left_Gesture
void Primary_Down_Secondary_Left_Gesture()
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroZ >= Z_threshold) {

    Serial.println("Left Secondary Gesture Activated ");

    Primary_Down_Secondary_Left = true;
    long int Zero_Start_millis = millis();
    while (Primary_Down_Secondary_Left == true)
    {
      long int Current_millis = millis();
      if ((Current_millis - Zero_Start_millis) >= Delay_For_Identify_The_Gesture * 1000)
      {
        Primary_Down_Secondary_Left = false;
        Primary_Down = false;
        Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");
        Gesture_Message("G16");
        bleuart.write(Gesture_Val);
        Serial.println("Send the gesture value  =  " + String(Gesture_Val));
        delay(Delay_For_Gesture_Audio_Toast * 1000);
        Reset_All_Gesture_Flags();
        break;
      }
      Primary_Down_Secondary_Left_Tertiary_Up_Gesture();
      Primary_Down_Secondary_Left_Tertiary_Down_Gesture();
    }
  }
}

//**************************************************************************************************************  Primary_Down_Secondary_Right_Gesture

void Primary_Down_Secondary_Right_Gesture()
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroZ <= -Z_threshold)
  {
    Serial.println("Right Secondary Gesture Activated ");

    Primary_Down_Secondary_Right = true;
    long int Zero_Start_millis = millis();
    while (Primary_Down_Secondary_Right == true)
    {
      long int Current_millis = millis();
      if ((Current_millis - Zero_Start_millis) >= Delay_For_Identify_The_Gesture * 1000)
      {
        Primary_Down_Secondary_Right = false;
        Primary_Down = false;
        Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");
        Gesture_Message("G14");
        bleuart.write(Gesture_Val);
        Serial.println("Send the gesture value  =  " + String(Gesture_Val));
        delay(Delay_For_Gesture_Audio_Toast * 1000);
      }
      Primary_Down_Secondary_Right_Tertiary_Up_Gesture();
      Primary_Down_Secondary_Right_Tertiary_Down_Gesture();
    }
  }
}

//**************************************************************************************************************  Primary_Left_Secondary_Up_Gesture

void Primary_Left_Secondary_Up_Gesture()
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroY <= -Y_threshold) {

    Serial.println("Up Secondary Gesture Activated ");

    Primary_Left_Secondary_Up = true;
    long int Zero_Start_millis = millis();
    while (Primary_Left_Secondary_Up == true)
    {
      long int Current_millis = millis();
      if ((Current_millis - Zero_Start_millis) >= Delay_For_Identify_The_Gesture * 1000)
      {
        Primary_Left_Secondary_Up = false;
        Primary_Left = false;
        Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");
        Gesture_Message("G11");
        bleuart.write(Gesture_Val);
        Serial.println("Send the gesture value  =  " + String(Gesture_Val));
        delay(Delay_For_Gesture_Audio_Toast * 1000);
      }
      Primary_Left_Secondary_Up_Tertiary_Left_Gesture();
      Primary_Left_Secondary_Up_Tertiary_Right_Gesture();
    }
  }
}

//**************************************************************************************************************  Primary_Left_Secondary_Down_Gesture
void Primary_Left_Secondary_Down_Gesture()
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  //float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  //Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  //Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroY >= Y_threshold) {

    Serial.println("Primary Left Secondary Down Gesture Activated ");
    Gesture_Message("G12");
    bleuart.write(Gesture_Val);

    //Primary_Left_Secondary_Down = true;
    //long int Zero_Start_millis = millis();
   // while (Primary_Left_Secondary_Down == true)
    //{
      //long int Current_millis = millis();
      //if ((Current_millis - Zero_Start_millis) >= Delay_For_Identify_The_Gesture * 1000)
      //{
      if (current_mode == 98) {
        Serial.println("Gesture Mode (98): Left->Down detected. Performing screen back.");
        
        // Perform the screen back action
        Mobile_Screen_Back_Movement();

        // Send confirmation message via BLE
        //Gesture_Message("G12"); // Using G08 for this gesture
        //bleuart.write(Gesture_Val);
      } else {
        Serial.print("Other Mode (");
        Serial.print(current_mode);
        Serial.println("): Left->Down gesture detected but action is ignored.");
      }

      Reset_All_Gesture_Flags(); // Reset all gesture flags after processing
        
        // Reset gesture state flags
       // Primary_Left_Secondary_Down = false;
       // Primary_Left = false;
        
        //delay(Delay_For_Gesture_Audio_Toast * 1000); // Wait for audio toast if needed
        //break; // Exit the while loop, as the gesture sequence is complete
      //}
      //Primary_Left_Secondary_Down_Tertiary_Left_Gesture();
      //Primary_Left_Secondary_Down_Tertiary_Right_Gesture();
      delay(500);
    }
  }
//}

//**************************************************************************************************************  Primary_Right_Secondary_Up_Gesture
void Primary_Right_Secondary_Up_Gesture()
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroY <= -Y_threshold) {

    Serial.println("Up Secondary Gesture Activated ");

    Primary_Right_Secondary_Up = true;
    long int Zero_Start_millis = millis();
    while (Primary_Right_Secondary_Up == true)
    {
      long int Current_millis = millis();
      if ((Current_millis - Zero_Start_millis) >= Delay_For_Identify_The_Gesture * 1000)
      {
        Primary_Right_Secondary_Up = false;
        Primary_Right = false;
        Serial.println(" !!!!  No  Gesture movement found . Stop here !!!!");
        Gesture_Message("G09");
        bleuart.write( Gesture_Val);
        Serial.println("Send the gesture value  =  " + String(Gesture_Val));

        delay(Delay_For_Gesture_Audio_Toast * 1000);
      }
      Primary_Right_Secondary_Up_Tertiary_Left_Gesture();
      Primary_Right_Secondary_Up_Tertiary_Right_Gesture();
    }
  }
}

//**************************************************************************************************************  Primary_Right_Secondary_Down_Gesture
void Primary_Right_Secondary_Down_Gesture()
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroY >= Y_threshold) {

    Serial.println("Down Secondary Gesture Activated ");

    Primary_Right_Secondary_Down = true;
    long int Zero_Start_millis = millis();
    while (Primary_Right_Secondary_Down == true)
    {
      long int Current_millis = millis();
      if ((Current_millis - Zero_Start_millis) >= Delay_For_Identify_The_Gesture * 1000)
      {
        Primary_Right_Secondary_Down = false;
        Primary_Right = false;
        Serial.println(" !!!!  No  Gesture movement found . Stop here !!!!");
        Gesture_Message("G10");
        bleuart.write( Gesture_Val);
        Serial.println("Send the gesture value  =  " + String(Gesture_Val));

        delay(Delay_For_Gesture_Audio_Toast * 1000);
      }
      Primary_Right_Secondary_Down_Tertiary_Left_Gesture();
      Primary_Right_Secondary_Down_Tertiary_Right_Gesture();
    }
  }
}

//***Primary_Tilt_Left_Secondary_Tilt_Left_Gesture***
/*void Primary_Tilt_Left_Secondary_Tilt_Left_Gesture()
{
  float gyroX = myIMU.readFloatGyroX();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope X: "); Serial.println(gyroX, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroX <= -X_threshold) {

    Serial.println("Tilt_Left Secondary Gesture Activated ");

    Primary_Tilt_Left_Secondary_Tilt_Left = true ;
    long int Zero_Start_millis = millis();
    while (Primary_Tilt_Left_Secondary_Tilt_Left == true)
    {
      long int Current_millis = millis();
      if ((Current_millis - Zero_Start_millis) >= Delay_For_Identify_The_Gesture * 1000)
      {
        Primary_Tilt_Left_Secondary_Tilt_Left = false;
        Primary_Tilt_Left = false;
        Change_To_Mouse_Mode();
        //Serial.println("DEBUG: Skipped Change_To_Mouse_Mode()");
        Gesture_Message("G07");
        bleuart.write(Gesture_Val);
        Serial.println("DEBUG: Skipped bleuart.write()");
        Serial.println("Send the gesture value  =  " + String(Gesture_Val));
        Serial.print("DEBUG: Delay_For_Gesture_Audio_Toast value: ");
        Serial.println(Delay_For_Gesture_Audio_Toast);
        Serial.print("DEBUG: Calculated delay duration (ms): ");
        Serial.println(Delay_For_Gesture_Audio_Toast * 1000);

        delay(Delay_For_Gesture_Audio_Toast * 1000);
        Serial.println("DEBUG: About to break from secondary gesture loop");
        break;
      }
    }
    Serial.println("DEBUG: Exited Primary_Tilt_Left_Secondary_Tilt_Left_Gesture while loop");
  }
}*/

//***Primary_Tilt_Right_Secondary_Tilt_Right_Gesture***

void Primary_Tilt_Right_Secondary_Tilt_Right_Gesture()
{
  float gyroX = myIMU.readFloatGyroX();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope X: "); Serial.println(gyroX, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroX >= X_threshold) {

    Serial.println("Tilt_Right Secondary Gesture Activated ");

    Primary_Tilt_Right_Secondary_Tilt_Right = true ;
    long int Zero_Start_millis = millis();
    while (Primary_Tilt_Right_Secondary_Tilt_Right == true)
    {
      long int Current_millis = millis();
      if ((Current_millis - Zero_Start_millis) >= Delay_For_Identify_The_Gesture * 1000)
      {
        Primary_Tilt_Right_Secondary_Tilt_Right = false;
        Primary_Tilt_Right = false;
        Gesture_Message("G08");
        bleuart.write(Gesture_Val);
        Change_To_Gesture_Mode();
        Serial.println("Send the gesture value  =  " + String(Gesture_Val));
        delay(2000);
        Serial.println("Sending HGMS");
        bleuart.write("HGMS");
        delay(Delay_For_Gesture_Audio_Toast * 1000);
      }
    }
  }
}
//**************************************************************************************************************  Primary_Up_Secondary_Down
void Primary_Up_Secondary_Down_Gesture()
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroY >= Y_threshold) {

    Serial.println("Down Secondary Gesture Activated ");

    Primary_Up_Secondary_Left = true;

    long int Current_millis = millis();
    long int Zero_Start_millis = millis();
    while ( Primary_Up_Secondary_Down == true )
    {

      if (Delay_For_Identify_The_Gesture * 1000  <= ( Zero_Start_millis - Current_millis ))
      {

        Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");

        Primary_Up_Secondary_Down = false;
        Primary_Up = false;

        //Gesture_Message("G15");
        //bleuart.write( Gesture_Val);
        //Serial.println("Send the gesture value  =  " + String(Gesture_Val));

        delay(Delay_For_Gesture_Audio_Toast * 1000);
      }

      Primary_Up_Secondary_Down_Tertiary_Up_Gesture();


    }
  }
}
//**************************************************************************************************************  Primary_Down_Secondary_Up
void Primary_Down_Secondary_Up_Gesture()
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroY <= -Y_threshold) {

    Serial.println("Up Secondary Gesture Activated ");

    Primary_Down_Secondary_Up = true;

    long int Current_millis = millis();
    long int Zero_Start_millis = millis();
    while ( Primary_Down_Secondary_Up == true )
    {

      if (Delay_For_Identify_The_Gesture * 1000  <= ( Zero_Start_millis - Current_millis ))
      {

        Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");

        Primary_Down_Secondary_Up = false;
        Primary_Down = false;

        //Gesture_Message("G15");
        //bleuart.write( Gesture_Val);
        //Serial.println("Send the gesture value  =  " + String(Gesture_Val));

        delay(Delay_For_Gesture_Audio_Toast * 1000);
      }

      Primary_Down_Secondary_Up_Tertiary_Down_Gesture();


    }
  }
}
//**************************************************************************************************************  Primary_Left_Secondary_Right
void Primary_Left_Secondary_Right_Gesture()
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroZ <= -Z_threshold) {

    Serial.println("Right Secondary Gesture Activated ");

    Primary_Left_Secondary_Right = true;

    long int Current_millis = millis();
    long int Zero_Start_millis = millis();
    while ( Primary_Left_Secondary_Right == true )
    {

      if (Delay_For_Identify_The_Gesture * 1000  <= ( Zero_Start_millis - Current_millis ))
      {

        Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");

        Primary_Left_Secondary_Right = false;
        Primary_Left = false;

        //Gesture_Message("G15");
        // bleuart.write( Gesture_Val);
        // Serial.println("Send the gesture value  =  " + String(Gesture_Val));

        delay(Delay_For_Gesture_Audio_Toast * 1000);
      }

      Primary_Left_Secondary_Right_Tertiary_Left_Gesture();


    }
  }
}
//**************************************************************************************************************  Primary_Right_Secondary_Left
void Primary_Right_Secondary_Left_Gesture()
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroZ >= Z_threshold) {

    Serial.println("Left Secondary Gesture Activated ");

    Primary_Right_Secondary_Left = true;

    long int Current_millis = millis();
    long int Zero_Start_millis = millis();
    while ( Primary_Right_Secondary_Left == true )
    {

      if (Delay_For_Identify_The_Gesture * 1000  <= ( Zero_Start_millis - Current_millis ))
      {

        Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");

        Primary_Right_Secondary_Left = false;
        Primary_Right = false;

        //Gesture_Message("G15");
        //bleuart.write( Gesture_Val);
        //Serial.println("Send the gesture value  =  " + String(Gesture_Val));

        delay(Delay_For_Gesture_Audio_Toast * 1000);
      }

      Primary_Right_Secondary_Left_Tertiary_Right_Gesture();


    }
  }
}
