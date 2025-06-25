//#include "Tertiary_Gesture.h"

//***************************************************************************************************** Primary_Up_Secondary_Right_Tertiary_Up
void Primary_Up_Secondary_Left_Tertiary_Up_Gesture()
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroY <= -Y_threshold)
  {
    Serial.println("Primary_Up_Secondary_Left_Tertiary_Up  Gesture Activated ");

    Primary_Up_Secondary_Left_Tertiary_Up = true;
    long int Zero_Start_millis = millis();
    while (Primary_Up_Secondary_Left_Tertiary_Up == true)
    {
      long int Current_millis = millis();
      if ((Current_millis - Zero_Start_millis) >= Delay_For_Identify_The_Gesture * 1000)
      {
        Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");
        Primary_Up_Secondary_Left_Tertiary_Up = false;
        Primary_Up_Secondary_Left  = false;
        Primary_Up = false;
        Gesture_Message("G39");
        bleuart.write(Gesture_Val);
        Serial.println("Send the gesture value  =  " + String(Gesture_Val));
        delay(Delay_For_Gesture_Audio_Toast * 1000);
      }
      Primary_Up_Secondary_Left_Tertiary_Up_Quaternary_Right_Gesture();
      Primary_Up_Secondary_Left_Tertiary_Up_Quaternary_Left_Gesture();
    }
  }
}

//***Primary_Up_Secondary_Left_Tertiary_Down***

void Primary_Up_Secondary_Left_Tertiary_Down_Gesture()
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroY >= Y_threshold)
  {

    Serial.println("Primary_Up_Secondary_Left_Tertiary_Down  Gesture Activated ");
    Primary_Up_Secondary_Left_Tertiary_Down = true;
    long int Zero_Start_millis = millis();
    while (Primary_Up_Secondary_Left_Tertiary_Down == true)
    {
      long int Current_millis = millis();
      if ((Current_millis - Zero_Start_millis) >= Delay_For_Identify_The_Gesture * 1000)
      {
        Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");
        Primary_Up_Secondary_Left_Tertiary_Down = false;
        Primary_Up_Secondary_Left  = false;
        Primary_Up = false;
        Gesture_Message("G21");
        bleuart.write(Gesture_Val);
        Serial.println("Send the gesture value  =  " + String(Gesture_Val));
        delay(Delay_For_Gesture_Audio_Toast * 1000);
      }
      Primary_Up_Secondary_Left_Tertiary_Down_Quaternary_Right_Gesture();
      Primary_Up_Secondary_Left_Tertiary_Down_Quaternary_Left_Gesture();
    }
  }
}

//********************************************************************************************************* Primary_Up_Secondary_Right_Tertiary_Up
void Primary_Up_Secondary_Right_Tertiary_Up_Gesture()
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroY <= -Y_threshold)
  {
    Serial.println("Primary_Up_Secondary_Right_Tertiary_Up  Gesture Activated ");
    Primary_Up_Secondary_Right_Tertiary_Up = true;
    long int Zero_Start_millis = millis();
    while (Primary_Up_Secondary_Right_Tertiary_Up == true)
    {
      long int Current_millis = millis();
      if ((Current_millis - Zero_Start_millis) >= Delay_For_Identify_The_Gesture * 1000)
      {
        Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");
        Primary_Up_Secondary_Right_Tertiary_Up = false;
        Primary_Up_Secondary_Right = false;
        Primary_Up = false;
        Gesture_Message("G40");
        bleuart.write(Gesture_Val);
        Serial.println("Send the gesture value  =  " + String(Gesture_Val));
        delay(Delay_For_Gesture_Audio_Toast * 1000);
      }
      Primary_Up_Secondary_Right_Tertiary_Up_Quaternary_Right_Gesture();
      Primary_Up_Secondary_Right_Tertiary_Up_Quaternary_Left_Gesture();
    }
  }
}

//***Primary_Up_Secondary_Right_Tertiary_Down***

void Primary_Up_Secondary_Right_Tertiary_Down_Gesture()
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroY >= Y_threshold)
  {
    Serial.println("Primary_Up_Secondary_Right_Tertiary_Down  Gesture Activated ");

    Primary_Up_Secondary_Right_Tertiary_Down = true;
    long int Zero_Start_millis = millis();
    while (Primary_Up_Secondary_Right_Tertiary_Down == true)
    {
      long int Current_millis = millis();
      if ((Current_millis - Zero_Start_millis) >= Delay_For_Identify_The_Gesture * 1000)
      {
        Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");
        Primary_Up_Secondary_Right_Tertiary_Down = false;
        Primary_Up_Secondary_Right  = false;
        Primary_Up = false;
        Gesture_Message("G22");
        bleuart.write(Gesture_Val);
        Serial.println("Send the gesture value  =  " + String(Gesture_Val));
        delay(Delay_For_Gesture_Audio_Toast * 1000);
      }
      Primary_Up_Secondary_Right_Tertiary_Down_Quaternary_Right_Gesture();
      Primary_Up_Secondary_Right_Tertiary_Down_Quaternary_Left_Gesture();
    }
  }
}

//***Primary_Down_Secondary_Left_Tertiary_Up***

void Primary_Down_Secondary_Left_Tertiary_Up_Gesture()
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroY <= -Y_threshold)
  {
    Serial.println("Primary_Down_Secondary_Left_Tertiary_Up  Gesture Activated ");
    Primary_Down_Secondary_Left_Tertiary_Up = true;
    long int Zero_Start_millis = millis();
    while (Primary_Down_Secondary_Left_Tertiary_Up == true)
    {
      long int Current_millis = millis();
      if ((Current_millis - Zero_Start_millis) >= Delay_For_Identify_The_Gesture * 1000)
      {
        Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");
        Primary_Down_Secondary_Left_Tertiary_Up = false;
        Primary_Down_Secondary_Left  = false;
        Primary_Down = false;
        Gesture_Message("G23");
        bleuart.write(Gesture_Val);
        Serial.println("Send the gesture value  =  " + String(Gesture_Val));
        delay(Delay_For_Gesture_Audio_Toast * 1000);
      }
      Primary_Down_Secondary_Left_Tertiary_Up_Quaternary_Right_Gesture();
      Primary_Down_Secondary_Left_Tertiary_Up_Quaternary_Left_Gesture();
    }
  }
}

//******************************************************************************************** Primary_Down_Secondary_Left_Tertiary_Down
void Primary_Down_Secondary_Left_Tertiary_Down_Gesture()
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroY >= Y_threshold)
  {
    Serial.println("Primary_Down_Secondary_Left_Tertiary_Down  Gesture Activated ");
    Primary_Down_Secondary_Left_Tertiary_Down = true;
    long int Zero_Start_millis = millis();
    while (Primary_Down_Secondary_Left_Tertiary_Down == true)
    {
      long int Current_millis = millis();
      if ((Current_millis - Zero_Start_millis) >= Delay_For_Identify_The_Gesture * 1000)
      {
        Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");
        Primary_Down_Secondary_Left_Tertiary_Down = false;
        Primary_Down_Secondary_Left  = false;
        Primary_Down = false;
        Gesture_Message("G37");
        bleuart.write(Gesture_Val);
        Serial.println("Send the gesture value  =  " + String(Gesture_Val));
        delay(Delay_For_Gesture_Audio_Toast * 1000);
      }
      Primary_Down_Secondary_Left_Tertiary_Down_Quaternary_Right_Gesture();
      Primary_Down_Secondary_Left_Tertiary_Down_Quaternary_Left_Gesture();
    }
  }
}
//***Primary_Down_Secondary_Right_Tertiary_Up_Gesture***

void Primary_Down_Secondary_Right_Tertiary_Up_Gesture()
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroY <= -Y_threshold)
  {
    Serial.println("Primary_Down_Secondary_Right_Tertiary_Up  Gesture Activated ");
    Primary_Down_Secondary_Right_Tertiary_Up = true;
    long int Zero_Start_millis = millis();
    while (Primary_Down_Secondary_Right_Tertiary_Up == true)
    {
      long int Current_millis = millis();
      if ((Current_millis - Zero_Start_millis) >= Delay_For_Identify_The_Gesture * 1000)
      {
        Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");
        Primary_Down_Secondary_Right_Tertiary_Up = false;
        Primary_Down_Secondary_Right  = false;
        Primary_Down = false;
        Gesture_Message("G24");
        bleuart.write(Gesture_Val);
        Serial.println("Send the gesture value  =  " + String(Gesture_Val));
        delay(Delay_For_Gesture_Audio_Toast * 1000);
      }
      Primary_Down_Secondary_Right_Tertiary_Up_Quaternary_Right_Gesture();
      Primary_Down_Secondary_Right_Tertiary_Up_Quaternary_Left_Gesture();
    }
  }
}
//*************************************************************************************************************Primary_Down_Secondary_Right_Tertiary_Down_Gesture
void Primary_Down_Secondary_Right_Tertiary_Down_Gesture()
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroY >= Y_threshold)
  {
    Serial.println("Primary_Down_Secondary_Right_Tertiary_Down  Gesture Activated ");
    Primary_Down_Secondary_Right_Tertiary_Down = true;
    long int Zero_Start_millis = millis();
    while (Primary_Down_Secondary_Right_Tertiary_Down == true)
    {
      long int Current_millis = millis();
      if ((Current_millis - Zero_Start_millis) >= Delay_For_Identify_The_Gesture * 1000)
      {
        Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");
        Primary_Down_Secondary_Right_Tertiary_Down = false;
        Primary_Down_Secondary_Right  = false;
        Primary_Down = false;
        Gesture_Message("G38");
        bleuart.write(Gesture_Val);
        Serial.println("Send the gesture value  =  " + String(Gesture_Val));
        delay(Delay_For_Gesture_Audio_Toast * 1000);
      }
      Primary_Down_Secondary_Right_Tertiary_Down_Quaternary_Right_Gesture();
      Primary_Down_Secondary_Right_Tertiary_Down_Quaternary_Left_Gesture();
    }
  }
}

//***************************************************************************************************** Primary_Left_Secondary_Up_Tertiary_Left  Gesture
void Primary_Left_Secondary_Up_Tertiary_Left_Gesture()
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroZ >= Z_threshold)
  {
    Serial.println("Primary_Left_Secondary_Up_Tertiary_Left  Gesture Activated ");
    Primary_Left_Secondary_Up_Tertiary_Left = true;
    long int Zero_Start_millis = millis();
    while (Primary_Left_Secondary_Up_Tertiary_Left == true)
    {
      long int Current_millis = millis();
      if ((Current_millis - Zero_Start_millis) >= Delay_For_Identify_The_Gesture * 1000)
      {
        Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");
        Primary_Left_Secondary_Up_Tertiary_Left = false;
        Primary_Left_Secondary_Up  = false;
        Primary_Left = false;
        Gesture_Message("G43");
        bleuart.write(Gesture_Val);
        Serial.println("Send the gesture value  =  " + String(Gesture_Val));
        delay(Delay_For_Gesture_Audio_Toast * 1000);
      }
      Primary_Left_Secondary_Up_Tertiary_Left_Quaternary_Up_Gesture();
      Primary_Left_Secondary_Up_Tertiary_Left_Quaternary_Down_Gesture();
    }
  }
}
//*************************************************************************************************** Primary_Left_Secondary_Up_Tertiary_Right
void Primary_Left_Secondary_Up_Tertiary_Right_Gesture()
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroZ <= -Z_threshold)
  {
    Serial.println(" Primary_Left_Secondary_Up_Tertiary_Right  Gesture Activated ");
    Primary_Left_Secondary_Up_Tertiary_Right = true;
    long int Zero_Start_millis = millis();
    while (Primary_Left_Secondary_Up_Tertiary_Right == true)
    {
      long int Current_millis = millis();
      if ((Current_millis - Zero_Start_millis) >= Delay_For_Identify_The_Gesture * 1000)
      {
        Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");
        Primary_Left_Secondary_Up_Tertiary_Right = false;
        Primary_Left_Secondary_Up  = false;
        Primary_Left = false;
        Gesture_Message("G27");
        bleuart.write(Gesture_Val);
        Serial.println("Send the gesture value  =  " + String(Gesture_Val));
        delay(Delay_For_Gesture_Audio_Toast * 1000);
      }
      Primary_Left_Secondary_Up_Tertiary_Right_Quaternary_Up_Gesture();
      Primary_Left_Secondary_Up_Tertiary_Right_Quaternary_Down_Gesture();
    }
  }
}

//**********************************************************************************************  Primary_Left_Secondary_Down_Tertiary_Left
void Primary_Left_Secondary_Down_Tertiary_Left_Gesture()
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroZ >= Z_threshold)
  {
    Serial.println("Primary_Left_Secondary_Down_Tertiary_Left  Gesture Activated ");
    Primary_Left_Secondary_Down_Tertiary_Left = true;
    long int Zero_Start_millis = millis();
    while (Primary_Left_Secondary_Down_Tertiary_Left == true)
    {
      long int Current_millis = millis();
      if ((Current_millis - Zero_Start_millis) >= Delay_For_Identify_The_Gesture * 1000)
      {
        Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");
        Primary_Left_Secondary_Down_Tertiary_Left = false;
        Primary_Left_Secondary_Down = false;
        Primary_Left = false;
        Gesture_Message("G44");
        bleuart.write(Gesture_Val);
        Serial.println("Send the gesture value  =  " + String(Gesture_Val));
        delay(Delay_For_Gesture_Audio_Toast * 1000);
        break;
      }
      Primary_Left_Secondary_Down_Tertiary_Left_Quaternary_Up_Gesture();
      Primary_Left_Secondary_Down_Tertiary_Left_Quaternary_Down_Gesture();
    }
  }
}
//***************************************************************************************************** Primary_Left_Secondary_Down_Tertiary_Right
void Primary_Left_Secondary_Down_Tertiary_Right_Gesture()
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroZ <= -Z_threshold)
  {
    Serial.println("Primary_Left_Secondary_Down_Tertiary_Right  Gesture Activated ");
    Primary_Left_Secondary_Down_Tertiary_Right = true;
    long int Zero_Start_millis = millis();
    while (Primary_Left_Secondary_Down_Tertiary_Right == true)
    {
      long int Current_millis = millis();
      if ((Current_millis - Zero_Start_millis) >= Delay_For_Identify_The_Gesture * 1000)
      {
        Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");
        Primary_Left_Secondary_Down_Tertiary_Right = false;
        Primary_Left_Secondary_Down  = false;
        Primary_Left = false;
        Gesture_Message("G28");
        bleuart.write(Gesture_Val);
        Serial.println("Send the gesture value  =  " + String(Gesture_Val));
        delay(Delay_For_Gesture_Audio_Toast * 1000);
      }
      Primary_Left_Secondary_Down_Tertiary_Right_Quaternary_Up_Gesture();
      Primary_Left_Secondary_Down_Tertiary_Right_Quaternary_Down_Gesture();
    }
  }
}

//***Primary_Right_Secondary_Up_Tertiary_Left***
void Primary_Right_Secondary_Up_Tertiary_Left_Gesture()
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroZ >= Z_threshold)
  {
    Serial.println("Primary_Right_Secondary_Up_Tertiary_Left  Gesture Activated ");
    Primary_Right_Secondary_Up_Tertiary_Left = true;
    long int Zero_Start_millis = millis();
    while (Primary_Right_Secondary_Up_Tertiary_Left == true)
    {
      long int Current_millis = millis();
      if ((Current_millis - Zero_Start_millis) >= Delay_For_Identify_The_Gesture * 1000)
      {
        Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");
        Primary_Right_Secondary_Up_Tertiary_Left = false;
        Primary_Right_Secondary_Up  = false;
        Primary_Right = false;
        Gesture_Message("G25");
        bleuart.write(Gesture_Val);
        Serial.println("Send the gesture value  =  " + String(Gesture_Val));
        delay(Delay_For_Gesture_Audio_Toast * 1000);
      }
      Primary_Right_Secondary_Up_Tertiary_Left_Quaternary_Up_Gesture();
      Primary_Right_Secondary_Up_Tertiary_Left_Quaternary_Down_Gesture();
    }
  }
}


//******************************************************************************************************** Primary_Right_Secondary_Up_Tertiary_Right
void Primary_Right_Secondary_Up_Tertiary_Right_Gesture()
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroZ <= -Z_threshold)
  {
    Serial.println("Primary_Right_Secondary_Up_Tertiary_Right  Gesture Activated ");
    Primary_Right_Secondary_Up_Tertiary_Right = true;
    long int Zero_Start_millis = millis();
    while (Primary_Right_Secondary_Up_Tertiary_Right == true)
    {
      long int Current_millis = millis();
      if ((Current_millis - Zero_Start_millis) >= Delay_For_Identify_The_Gesture * 1000)
      {
        Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");
        Primary_Right_Secondary_Up_Tertiary_Right = false;
        Primary_Right_Secondary_Up  = false;
        Primary_Right = false;
        Gesture_Message("G41");
        bleuart.write(Gesture_Val);
        Serial.println("Send the gesture value  =  " + String(Gesture_Val));

        delay(Delay_For_Gesture_Audio_Toast * 1000);
      }
      Primary_Right_Secondary_Up_Tertiary_Right_Quaternary_Up_Gesture();
      Primary_Right_Secondary_Up_Tertiary_Right_Quaternary_Down_Gesture();
    }
  }
}

//***Primary_Right_Secondary_Down_Tertiary_Left***

void Primary_Right_Secondary_Down_Tertiary_Left_Gesture()
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroZ >= Z_threshold)
  {
    Serial.println("Primary_Right_Secondary_Down_Tertiary_Left  Gesture Activated ");
    Primary_Right_Secondary_Down_Tertiary_Left = true;
    long int Zero_Start_millis = millis();
    while (Primary_Right_Secondary_Down_Tertiary_Left == true)
    {
      long int Current_millis = millis();
      if ((Current_millis - Zero_Start_millis) >= Delay_For_Identify_The_Gesture * 1000)
      {
        Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");

        Primary_Right_Secondary_Down_Tertiary_Left = false;
        Primary_Right_Secondary_Down  = false;
        Primary_Right = false;

        Gesture_Message("G26");
        bleuart.write( Gesture_Val);
        Serial.println("Send the gesture value  =  " + String(Gesture_Val));

        delay(Delay_For_Gesture_Audio_Toast * 1000);
      }
      Primary_Right_Secondary_Down_Tertiary_Left_Quaternary_Up_Gesture();
      Primary_Right_Secondary_Down_Tertiary_Left_Quaternary_Down_Gesture();
    }
  }
}
//********************************************************************************************************************* Primary_Right_Secondary_Down_Tertiary_Right

void Primary_Right_Secondary_Down_Tertiary_Right_Gesture()
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroZ <= -Z_threshold)
  {
    Serial.println(" Primary_Right_Secondary_Down_Tertiary_Right  Gesture Activated ");
    Primary_Right_Secondary_Down_Tertiary_Right = true;
    long int Zero_Start_millis = millis();
    while (Primary_Right_Secondary_Down_Tertiary_Right == true)
    {
      long int Current_millis = millis();
      if ((Current_millis - Zero_Start_millis) >= Delay_For_Identify_The_Gesture * 1000)
      {
        Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");

        Primary_Right_Secondary_Down_Tertiary_Right = false;
        Primary_Right_Secondary_Down  = false;
        Primary_Right = false;

        Gesture_Message("G42");
        bleuart.write( Gesture_Val);
        Serial.println("Send the gesture value  =  " + String(Gesture_Val));

        delay(Delay_For_Gesture_Audio_Toast * 1000);
      }
      Primary_Right_Secondary_Down_Tertiary_Right_Quaternary_Up_Gesture();
      Primary_Right_Secondary_Down_Tertiary_Right_Quaternary_Down_Gesture();
    }
  }
}

//*************************************************************************************************************
void Primary_Up_Secondary_Down_Tertiary_Up_Gesture()
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroY <= -Y_threshold)
  {
    Serial.println("Primary_Up_Secondary_Down_Tertiary_Up  Gesture Activated ");

    Primary_Up_Secondary_Down  = false;
    Primary_Up = false;

    Gesture_Message("G19");
    bleuart.write( Gesture_Val);
    Serial.println("Send the gesture value  =  " + String(Gesture_Val));

    delay(Delay_For_Gesture_Audio_Toast * 1000);
  }
}

//**************************************************************************************************

void Primary_Down_Secondary_Up_Tertiary_Down_Gesture()
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroY >= Y_threshold)
  {
    Serial.println("Primary_Down_Secondary_Up_Tertiary_Down  Gesture Activated ");

    Primary_Down_Secondary_Up  = false;
    Primary_Down = false;

    Gesture_Message("G19");
    bleuart.write( Gesture_Val);
    Serial.println("Send the gesture value  =  " + String(Gesture_Val));

    delay(Delay_For_Gesture_Audio_Toast * 1000);

  }
}

//*****************************************************************************************************
void Primary_Left_Secondary_Right_Tertiary_Left_Gesture()
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroZ >= Z_threshold)
  {
    Serial.println("Primary_Left_Secondary_Right_Tertiary_Left Gesture Activated ");

    Primary_Left_Secondary_Right  = false;
    Primary_Left = false;

    Gesture_Message("G20");
    bleuart.write( Gesture_Val);
    Serial.println("Send the gesture value  =  " + String(Gesture_Val));

    delay(Delay_For_Gesture_Audio_Toast * 1000);
  }
}

//***********************************************************************************************************
void Primary_Right_Secondary_Left_Tertiary_Right_Gesture()
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroZ <= -Z_threshold)
  {
    Serial.println("Primary_Right_Secondary_Left_Tertiary_Right  Gesture Activated ");

    Primary_Right_Secondary_Left_Tertiary_Right = true;

    Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");

    Primary_Right_Secondary_Left  = false;
    Primary_Right = false;

    Gesture_Message("G20");
    bleuart.write( Gesture_Val);
    Serial.println("Send the gesture value  =  " + String(Gesture_Val));

    delay(Delay_For_Gesture_Audio_Toast * 1000);
  }
}
