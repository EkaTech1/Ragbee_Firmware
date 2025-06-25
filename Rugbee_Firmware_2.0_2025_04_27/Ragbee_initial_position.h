int Send_message_delay = 7;

long int Starting_Message_millis = millis();
bool Starting_Message_Flag = true;

void Initialization_Starting_Message()
{
  Starting_Message_millis = millis();
  Starting_Message_Flag = true;
  
}

void Starting_Message()
{
  
  // This is an if statement that checks if the difference between the current time and the time when the last disconnect reason was recorded is greater than or equal to 10 seconds (10000 is the number of milliseconds in 10 seconds),
  // and if Last_Disconnect_Reason_Flag is true.
  long int Current_millis = millis();
  if (((Send_message_delay * 1000) <= ( Current_millis - Starting_Message_millis )) && (Starting_Message_Flag == true))
  {
    Battery_percentage();
    delay(2000);
    
    // If Gesture_User_Flag is false, it prints a different message to the Serial Monitor and writes the string "G99" to the BLE UART module using the bleuart.write() function.
    Serial.println("******************************************************   Sending GMP");
    Serial.println(" Message Sent = G97 (Phone Mode)");
    delay(1000);
    bleuart.write("G97");  //Phone Mode
    delay(2000);
    Starting_Message_Flag = false;
  }
}
