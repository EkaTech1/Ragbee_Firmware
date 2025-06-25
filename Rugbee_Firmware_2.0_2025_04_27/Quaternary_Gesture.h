//Quaternary Gesture Logic

// ***Primary_Up_Secondary_Left_Tertiary_Up_Quaternary_Left***

void Primary_Up_Secondary_Left_Tertiary_Up_Quaternary_Left_Gesture() 
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroZ >= Z_threshold)
  {
    long int Zero_Start_millis = millis();
    while (true)
    {
      long int Current_millis = millis();
      if ((Current_millis - Zero_Start_millis) >= Delay_For_Identify_The_Gesture * 1000)
      {
        Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");
        Serial.println("Primary_Up_Secondary_Left_Tertiary_Up_Quaternary_Left  Gesture Activated ");

        Primary_Up_Secondary_Left_Tertiary_Up = false;
        Primary_Up_Secondary_Left  = false;
        Primary_Up = false;

        bleuart.write( Gesture_Val);
        Serial.println("Send the gesture value  =  " + String(Gesture_Val));

        break;
      }
    }
  }
}
// ***Primary_Up_Secondary_Left_Tertiary_Up_Quaternary_Right***

void Primary_Up_Secondary_Left_Tertiary_Up_Quaternary_Right_Gesture()
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroZ <= -Z_threshold)
  {
    long int Zero_Start_millis = millis();
    while (true)
    {
      long int Current_millis = millis();
      if ((Current_millis - Zero_Start_millis) >= Delay_For_Identify_The_Gesture * 1000)
      {
        Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");
        Serial.println("Primary_Up_Secondary_Left_Tertiary_Up_Quaternary_Right  Gesture Activated ");

        Primary_Up_Secondary_Left_Tertiary_Up = false;
        Primary_Up_Secondary_Left  = false;
        Primary_Up = false;

        bleuart.write( Gesture_Val);
        Serial.println("Send the gesture value  =  " + String(Gesture_Val));

        break;
      }
    }
  }
}

// ***Primary_Up_Secondary_Left_Tertiary_Down_Quaternary_Left***

void Primary_Up_Secondary_Left_Tertiary_Down_Quaternary_Left_Gesture() 
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroZ >= Z_threshold)
  {
    long int Zero_Start_millis = millis();
    while (true)
    {
      long int Current_millis = millis();
      if ((Current_millis - Zero_Start_millis) >= Delay_For_Identify_The_Gesture * 1000)
      {
        Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");
        Serial.println("Primary_Up_Secondary_Left_Tertiary_Down_Quaternary_Left  Gesture Activated ");

        Primary_Up_Secondary_Left_Tertiary_Down = false;
        Primary_Up_Secondary_Left  = false;
        Primary_Up = false;

        bleuart.write( Gesture_Val);
        Serial.println("Send the gesture value  =  " + String(Gesture_Val));

        break;
      }
    }
  }
}

// *** Primary_Up_Secondary_Left_Tertiary_Down_Quaternary_Right

void Primary_Up_Secondary_Left_Tertiary_Down_Quaternary_Right_Gesture()
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroZ <= -Z_threshold)
  {
    long int Zero_Start_millis = millis();
    while (true)
    {
      long int Current_millis = millis();
      if ((Current_millis - Zero_Start_millis) >= Delay_For_Identify_The_Gesture * 1000)
      {
        Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");
        delay(100);
        Serial.println("Primary_Up_Secondary_Left_Tertiary_Down_Quaternary_Right  Gesture Activated ");

        Primary_Up_Secondary_Left_Tertiary_Down = false;
        Primary_Up_Secondary_Left  = false;
        Primary_Up = false;

        Gesture_Message("G29");
        bleuart.write( Gesture_Val);
        Serial.println("Send the gesture value  =  " + String(Gesture_Val));

        break;
      }
    }
  }
}

// ***Primary_Up_Secondary_Right_Tertiary_Up_Quaternary_Left***

void Primary_Up_Secondary_Right_Tertiary_Up_Quaternary_Left_Gesture() 
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroZ >= Z_threshold)
  {
    Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");
    Serial.println("Primary_Up_Secondary_Right_Tertiary_Up_Quaternary_Left  Gesture Activated ");

    Primary_Up_Secondary_Right_Tertiary_Up = false;
    Primary_Up_Secondary_Right  = false;
    Primary_Up = false;

    /*Gesture_Message("G15");
    bleuart.write( Gesture_Val);
    Serial.println("Send the gesture value  =  " + String(Gesture_Val));*/
  }
}

//***Primary_Up_Secondary_Right_Tertiary_Up_Quaternary_Right***

void Primary_Up_Secondary_Right_Tertiary_Up_Quaternary_Right_Gesture()
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroZ <= -Z_threshold)
  {
    Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");
    Serial.println("Primary_Up_Secondary_Right_Tertiary_Up_Quaternary_Right  Gesture Activated ");

    Primary_Up_Secondary_Right_Tertiary_Up = false;
    Primary_Up_Secondary_Right  = false;
    Primary_Up = false;

    /* Gesture_Message("G15");
    bleuart.write( Gesture_Val);
    Serial.println("Send the gesture value  =  " + String(Gesture_Val)); */
  }
}

// *** Primary_Up_Secondary_Right_Tertiary_Down_Quaternary_Left***

void Primary_Up_Secondary_Right_Tertiary_Down_Quaternary_Left_Gesture() 
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroZ >= Z_threshold)
  {
    Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");
    Serial.println("Primary_Up_Secondary_Right_Tertiary_Down_Quaternary_Left  Gesture Activated ");

    Primary_Up_Secondary_Right_Tertiary_Down = false;
    Primary_Up_Secondary_Right  = false;
    Primary_Up = false;

    Gesture_Message("G30");
    bleuart.write( Gesture_Val);
    Serial.println("Send the gesture value  =  " + String(Gesture_Val));
  }
}

//***Primary_Up_Secondary_Right_Tertiary_Down_Quaternary_Right***

void Primary_Up_Secondary_Right_Tertiary_Down_Quaternary_Right_Gesture()
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroZ <= -Z_threshold)
  {
    Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");
    Serial.println("Primary_Up_Secondary_Right_Tertiary_Down_Quaternary_Right  Gesture Activated ");

    Primary_Up_Secondary_Right_Tertiary_Down = false;
    Primary_Up_Secondary_Right  = false;
    Primary_Up = false;

    /* Gesture_Message("G15");
    bleuart.write( Gesture_Val);
    Serial.println("Send the gesture value  =  " + String(Gesture_Val)); */
  }
}

//***Primary_Down_Secondary_Left_Tertiary_Up_Quaternary_Left***

void Primary_Down_Secondary_Left_Tertiary_Up_Quaternary_Left_Gesture() 
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroZ >= Z_threshold)
  {
    Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");
    Serial.println("Primary_Down_Secondary_Left_Tertiary_Up_Quaternary_Left  Gesture Activated ");

    Primary_Down_Secondary_Left_Tertiary_Up = false;
    Primary_Down_Secondary_Left  = false;
    Primary_Down= false;

    /* Gesture_Message("G15");
    bleuart.write( Gesture_Val);
    Serial.println("Send the gesture value  =  " + String(Gesture_Val)); */
  }
}

//***Primary_Down_Secondary_Left_Tertiary_Up_Quaternary_Right***

void Primary_Down_Secondary_Left_Tertiary_Up_Quaternary_Right_Gesture()
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroZ <= -Z_threshold)
  {
    Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");
    Serial.println("Primary_Up_Secondary_Left_Tertiary_Up_Quaternary_Right  Gesture Activated ");

    Primary_Down_Secondary_Left_Tertiary_Up = false;
    Primary_Down_Secondary_Left  = false;
    Primary_Down = false;

    Gesture_Message("G31");
    bleuart.write( Gesture_Val);
    Serial.println("Send the gesture value  =  " + String(Gesture_Val));
  }
}

//***Primary_Down_Secondary_Left_Tertiary_Down_Quaternary_Left***

void Primary_Down_Secondary_Left_Tertiary_Down_Quaternary_Left_Gesture() 
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroZ >= Z_threshold)
  {
    Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");
    Serial.println("Primary_Down_Secondary_Left_Tertiary_Down_Quaternary_Left  Gesture Activated ");

    Primary_Down_Secondary_Left_Tertiary_Down = false;
    Primary_Down_Secondary_Left  = false;
    Primary_Down = false;

   /* Gesture_Message("G15");
    bleuart.write( Gesture_Val);
    Serial.println("Send the gesture value  =  " + String(Gesture_Val));*/
  }
}

//***Primary_Down_Secondary_Left_Tertiary_Down_Quaternary_Right***

void Primary_Down_Secondary_Left_Tertiary_Down_Quaternary_Right_Gesture()
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroZ <= -Z_threshold)
  {
    Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");
    delay(100);
    Serial.println("Primary_Down_Secondary_Left_Tertiary_Down_Quaternary_Right  Gesture Activated ");

    Primary_Down_Secondary_Left_Tertiary_Down = false;
    Primary_Down_Secondary_Left  = false;
    Primary_Down = false;
  /*
    Gesture_Message("G29");
    bleuart.write( Gesture_Val);
    Serial.println("Send the gesture value  =  " + String(Gesture_Val)); */
  }
}

//***Primary_Down_Secondary_Right_Tertiary_Up_Quaternary_Left***


void Primary_Down_Secondary_Right_Tertiary_Up_Quaternary_Left_Gesture() 
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroZ >= Z_threshold)
  {
    Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");
    Serial.println("Primary_Down_Secondary_Right_Tertiary_Up_Quaternary_Left  Gesture Activated ");

    Primary_Down_Secondary_Right_Tertiary_Up = false;
    Primary_Down_Secondary_Right  = false;
    Primary_Down = false;

    Gesture_Message("G32");
    bleuart.write( Gesture_Val);
    Serial.println("Send the gesture value  =  " + String(Gesture_Val));
  }
}

//***Primary_Down_Secondary_Right_Tertiary_Up_Quaternary_Right***

void Primary_Down_Secondary_Right_Tertiary_Up_Quaternary_Right_Gesture()
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroZ <= -Z_threshold)
  {
    Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");
    Serial.println("Primary_Down_Secondary_Right_Tertiary_Up_Quaternary_Right  Gesture Activated ");

    Primary_Down_Secondary_Right_Tertiary_Up = false;
    Primary_Down_Secondary_Right  = false;
    Primary_Down = false;

    /*Gesture_Message("G15");
    bleuart.write( Gesture_Val);
    Serial.println("Send the gesture value  =  " + String(Gesture_Val)); */
  }
}

// *** Primary_Down_Secondary_Right_Tertiary_Down_Quaternary_Left

void Primary_Down_Secondary_Right_Tertiary_Down_Quaternary_Left_Gesture() 
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroZ >= Z_threshold)
  {
    Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");
    Serial.println("Primary_Down_Secondary_Right_Tertiary_Down_Quaternary_Left  Gesture Activated ");

    Primary_Down_Secondary_Right_Tertiary_Down = false;
    Primary_Down_Secondary_Right  = false;
    Primary_Down = false;

    /*Gesture_Message("G30");
    bleuart.write( Gesture_Val);
    Serial.println("Send the gesture value  =  " + String(Gesture_Val));*/
  }
}

//***Primary_Down_Secondary_Right_Tertiary_Down_Quaternary_Right***

void Primary_Down_Secondary_Right_Tertiary_Down_Quaternary_Right_Gesture()
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroZ <= -Z_threshold)
  {
    Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");
    Serial.println("Primary_Down_Secondary_Right_Tertiary_Down_Quaternary_Right  Gesture Activated ");

    Primary_Down_Secondary_Right_Tertiary_Down = false;
    Primary_Down_Secondary_Right  = false;
    Primary_Down = false;

    /* Gesture_Message("G15");
    bleuart.write( Gesture_Val);
    Serial.println("Send the gesture value  =  " + String(Gesture_Val)); */
  }
}

//*** Primary_Left_Secondary_Up_Tertiary_Left_Quaternary_Up***

void Primary_Left_Secondary_Up_Tertiary_Left_Quaternary_Up_Gesture() {

  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroY <= -Y_threshold)
  {
    Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");
    Serial.println("Primary_Left_Secondary_Up_Tertiary_Left_Quaternary_Up Gesture Activated ");

    Primary_Left_Secondary_Up_Tertiary_Left = false;
    Primary_Left_Secondary_Up = false;
    Primary_Left= false;

    Gesture_Message("G46");
    bleuart.write( Gesture_Val);
    Serial.println("Send the gesture value  =  " + String(Gesture_Val)); 
  }
}

//***Primary_Left_Secondary_Up_Tertiary_Left_Quaternary_Down***

void Primary_Left_Secondary_Up_Tertiary_Left_Quaternary_Down_Gesture()
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroY >= Y_threshold)
  {
    Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");
    Serial.println("Primary_Left_Secondary_Up_Tertiary_Left_Quaternary_Down  Gesture Activated ");

    Primary_Left_Secondary_Up_Tertiary_Left = false;
    Primary_Left_Secondary_Up  = false;
    Primary_Left = false;

    /* Gesture_Message("G15");
    bleuart.write( Gesture_Val);
    Serial.println("Send the gesture value  =  " + String(Gesture_Val)); */
  }
}

//***Primary_Left_Secondary_Up_Tertiary_Right_Quaternary_Up***

void Primary_Left_Secondary_Up_Tertiary_Right_Quaternary_Up_Gesture() 
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroY <= -Y_threshold)
  {
    Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");
    Serial.println("Primary_Left_Secondary_Up_Tertiary_Right_Quaternary_Up Gesture Activated ");

    Primary_Left_Secondary_Up_Tertiary_Right = false;
    Primary_Left_Secondary_Up = false;
    Primary_Left= false;

    /* Gesture_Message("G46");
    bleuart.write( Gesture_Val);
    Serial.println("Send the gesture value  =  " + String(Gesture_Val)); */
  }
}

//***Primary_Left_Secondary_Up_Tertiary_Right_Quaternary_Down***

void Primary_Left_Secondary_Up_Tertiary_Right_Quaternary_Down_Gesture()
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroY >= Y_threshold)
  {
    Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");
    Serial.println("Primary_Left_Secondary_Up_Tertiary_Left_Quaternary_Down  Gesture Activated ");

    Primary_Left_Secondary_Up_Tertiary_Right = false;
    Primary_Left_Secondary_Up  = false;
    Primary_Left = false;

    Gesture_Message("G33");
    bleuart.write( Gesture_Val);
    Serial.println("Send the gesture value  =  " + String(Gesture_Val)); 
  }
}

//***Primary_Left_Secondary_Up_Tertiary_Left_Quaternary_Up***

void Primary_Left_Secondary_Down_Tertiary_Left_Quaternary_Up_Gesture() 
{

  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroY <= -Y_threshold)
  {
    Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");
    Serial.println("Primary_Left_Secondary_Down_Tertiary_Left_Quaternary_Up Gesture Activated ");

    Primary_Left_Secondary_Down_Tertiary_Left = false;
    Primary_Left_Secondary_Down = false;
    Primary_Left= false;

    /* Gesture_Message("G46");
    bleuart.write( Gesture_Val);
    Serial.println("Send the gesture value  =  " + String(Gesture_Val)); */
  }
}

//***Primary_Left_Secondary_Down_Tertiary_Left_Quaternary_Down***

void Primary_Left_Secondary_Down_Tertiary_Left_Quaternary_Down_Gesture()
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroY >= Y_threshold)
  {
    Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");
    Serial.println("Primary_Left_Secondary_Down_Tertiary_Left_Quaternary_Down  Gesture Activated ");

    Primary_Left_Secondary_Down_Tertiary_Left = false;
    Primary_Left_Secondary_Down  = false;
    Primary_Left = false;

    Gesture_Message("G48");
    bleuart.write( Gesture_Val);
    Change_To_Phone_Mode();
    Serial.println("Send the gesture value  =  " + String(Gesture_Val)); 
  }
}

//***Primary_Left_Secondary_Down_Tertiary_Right_Quaternary_Down***

void Primary_Left_Secondary_Down_Tertiary_Right_Quaternary_Down_Gesture()
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroY >= Y_threshold)
  {
    Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");
    Serial.println("Primary_Left_Secondary_Down_Tertiary_Left_Quaternary_Down  Gesture Activated ");

    Primary_Left_Secondary_Down_Tertiary_Right = false;
    Primary_Left_Secondary_Down  = false;
    Primary_Left = false;

    /* Gesture_Message("G15");
    bleuart.write( Gesture_Val);
    Serial.println("Send the gesture value  =  " + String(Gesture_Val)); */
  }
}

//***Primary_Right_Secondary_Up_Tertiary_Left_Quaternary_Up***

void Primary_Right_Secondary_Up_Tertiary_Left_Quaternary_Up_Gesture() 
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroY <= -Y_threshold)
  {
    Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");
    Serial.println("Primary_Right_Secondary_Up_Tertiary_Left_Quaternary_Up Gesture Activated ");

    Primary_Right_Secondary_Up_Tertiary_Left = false;
    Primary_Right_Secondary_Up = false;
    Primary_Right= false;

    /* Gesture_Message("G46");
    bleuart.write( Gesture_Val);
    Serial.println("Send the gesture value  =  " + String(Gesture_Val)); */
  }
}

//***Primary_Right_Secondary_Up_Tertiary_Left_Quaternary_Down***

void Primary_Right_Secondary_Up_Tertiary_Left_Quaternary_Down_Gesture()
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroY >= Y_threshold)
  {
    Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");
    Serial.println("Primary_Right_Secondary_Up_Tertiary_Left_Quaternary_Down  Gesture Activated ");

    Primary_Right_Secondary_Up_Tertiary_Left = false;
    Primary_Right_Secondary_Up  = false;
    Primary_Right = false;

    Gesture_Message("G35");
    bleuart.write( Gesture_Val);
    Serial.println("Send the gesture value  =  " + String(Gesture_Val)); 
  }
}

//***Primary_Right_Secondary_Up_Tertiary_Right_Quaternary_Up***

void Primary_Right_Secondary_Up_Tertiary_Right_Quaternary_Up_Gesture() 
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroY <= -Y_threshold)
  {
    Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");
    Serial.println("Primary_Right_Secondary_Up_Tertiary_Right_Quaternary_Up Gesture Activated ");

    Primary_Right_Secondary_Up_Tertiary_Right = false;
    Primary_Right_Secondary_Up = false;
    Primary_Right= false;

    Gesture_Message("G45");
    bleuart.write( Gesture_Val);
    Serial.println("Send the gesture value  =  " + String(Gesture_Val)); 
  }
}

//***Primary_Right_Secondary_Up_Tertiary_Right_Quaternary_Down***

void Primary_Right_Secondary_Up_Tertiary_Right_Quaternary_Down_Gesture()
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroY >= Y_threshold)
  {
    Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");
    Serial.println("Primary_Left_Secondary_Up_Tertiary_Left_Quaternary_Down  Gesture Activated ");

    Primary_Left_Secondary_Up_Tertiary_Right = false;
    Primary_Left_Secondary_Up  = false;
    Primary_Left = false;

   /* Gesture_Message("G33");
    bleuart.write( Gesture_Val);
    Serial.println("Send the gesture value  =  " + String(Gesture_Val)); */
  }
}

//***Primary_Right_Secondary_Up_Tertiary_Left_Quaternary_Up***

void Primary_Right_Secondary_Down_Tertiary_Left_Quaternary_Up_Gesture() 
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroY <= -Y_threshold)
  {
    Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");
    Serial.println("Primary_Right_Secondary_Down_Tertiary_Left_Quaternary_Up Gesture Activated ");

    Primary_Right_Secondary_Down_Tertiary_Left = false;
    Primary_Right_Secondary_Down = false;
    Primary_Right= false;

    Gesture_Message("G36");
    bleuart.write( Gesture_Val);
    Serial.println("Send the gesture value  =  " + String(Gesture_Val)); 
  }
}

//***Primary_Right_Secondary_Down_Tertiary_Left_Quaternary_Down***

void Primary_Right_Secondary_Down_Tertiary_Left_Quaternary_Down_Gesture()
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroY >= Y_threshold)
  {
    Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");
    Serial.println("Primary_Right_Secondary_Down_Tertiary_Left_Quaternary_Down  Gesture Activated ");

    Primary_Right_Secondary_Down_Tertiary_Left = false;
    Primary_Right_Secondary_Down  = false;
    Primary_Right = false;
  }
}

//***Primary_Right_Secondary_Down_Tertiary_Right_Quaternary_Up***

void Primary_Right_Secondary_Down_Tertiary_Right_Quaternary_Up_Gesture() 
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroY <= -Y_threshold)
  {
    Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");
    Serial.println("Primary_Right_Secondary_Down_Tertiary_Right_Quaternary_Up Gesture Activated ");

    Primary_Right_Secondary_Down_Tertiary_Right = false;
    Primary_Right_Secondary_Down = false;
    Primary_Right= false;

    /*Gesture_Message("G34");
    bleuart.write( Gesture_Val);
    Serial.println("Send the gesture value  =  " + String(Gesture_Val));*/ 
  }
}

// **** Primary_Left_Secondary_Down_Tertiary_Right_Quaternary_Up*****

void Primary_Left_Secondary_Down_Tertiary_Right_Quaternary_Up_Gesture() 
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroY <= -Y_threshold)
  {
    Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");
    Serial.println("Primary_Left_Secondary_Down_Tertiary_Right_Quaternary_Up Gesture Activated ");

    Primary_Left_Secondary_Down_Tertiary_Right = false;
    Primary_Left_Secondary_Down = false;
    Primary_Left= false;

    Gesture_Message("G34");
    bleuart.write( Gesture_Val);
    Serial.println("Send the gesture value  =  " + String(Gesture_Val)); 
  }
}

//***Primary_Right_Secondary_Down_Tertiary_Right_Quaternary_Down***

void Primary_Right_Secondary_Down_Tertiary_Right_Quaternary_Down_Gesture()
{
  float gyroY = myIMU.readFloatGyroY();  // Y-axis for UP/DOWN
  float gyroZ = myIMU.readFloatGyroZ();  // Z-axis for LEFT/RIGHT

  Serial.print("\nGyroscope Y: "); Serial.println(gyroY, 4);
  Serial.print("Gyroscope Z: "); Serial.println(gyroZ, 4);

  if (gyroY >= Y_threshold)
  {
    Serial.println(" !!!!  No  Gesture movement found . Stop here !!!! ");
    Serial.println("Primary_Right_Secondary_Down_Tertiary_Left_Quaternary_Down  Gesture Activated ");

    Primary_Right_Secondary_Down_Tertiary_Right = false;
    Primary_Right_Secondary_Down  = false;
    Primary_Right = false;

    Gesture_Message("G47");
    bleuart.write( Gesture_Val);
    Change_To_Testing_mode();
    Serial.println("Send the gesture value  =  " + String(Gesture_Val)); 
  }
}
