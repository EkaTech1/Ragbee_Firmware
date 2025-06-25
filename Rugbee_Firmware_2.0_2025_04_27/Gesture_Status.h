bool Gesture_User_Flag = true;

extern BLEHidAdafruit blehid;

// Primary_Top, Primary_Bottom, Primary_Left, Primary_Right, Primary_Tilt_Left, and Primary_Tilt_Right are boolean variables used to keep track of the primary gestures detected in different directions.

bool Primary_Up = false;
bool Primary_Down = false;
bool Primary_Left = false;
bool Primary_Right = false;
bool Primary_Tilt_Left = false;
bool Primary_Tilt_Right = false;

//************************************************Secondary gesture********************************************************

bool Primary_Up_Secondary_Left = false;
bool Primary_Up_Secondary_Right = false;
bool Primary_Down_Secondary_Left = false;
bool Primary_Down_Secondary_Right = false;
bool Primary_Left_Secondary_Up = false;
bool Primary_Left_Secondary_Down = false;
bool Primary_Right_Secondary_Up = false;
bool Primary_Right_Secondary_Down = false;
bool  Primary_Tilt_Left_Secondary_Tilt_Left = false ;
bool  Primary_Tilt_Left_Secondary_Tilt_Right = false ;
bool  Primary_Tilt_Right_Secondary_Tilt_Left = false ;
bool  Primary_Tilt_Right_Secondary_Tilt_Right = false ;

bool  Primary_Up_Secondary_Down = false ;
bool  Primary_Down_Secondary_Up = false ;
bool  Primary_Left_Secondary_Right = false ;
bool  Primary_Right_Secondary_Left = false ;

extern bool complex_gesture_part_matched_this_cycle; // New flag

//************************************************ tertiary gesture*************************************************************

bool Primary_Up_Secondary_Left_tertiary_Up = false; //Added
bool Primary_Up_Secondary_Left_tertiary_Down = false; // Added
bool Primary_Up_Secondary_Right_tertiary_Up = false; // Added
bool Primary_Up_Secondary_Left_Tertiary_Up = false;                                    //   39
bool Primary_Up_Secondary_Left_Tertiary_Down = false;                                  //   21
bool Primary_Down_Secondary_Left_Tertiary_Down = false;                                //   37
bool Primary_Down_Secondary_Left_Tertiary_Up = false;                                  //   23
bool Primary_Up_Secondary_Right_Tertiary_Up = false;                                   //  40
bool Primary_Up_Secondary_Right_Tertiary_Down = false;                                 //  22
bool Primary_Down_Secondary_Right_Tertiary_Down = false;                               //  24
bool Primary_Down_Secondary_Right_Tertiary_Up = false;                                 //  38
bool Primary_Left_Secondary_Up_Tertiary_Left = false;                                   //   43
bool Primary_Left_Secondary_Up_Tertiary_Right = false;                                  //   27
bool Primary_Right_Secondary_Up_Tertiary_Left = false;                                  //   25
bool Primary_Right_Secondary_Up_Tertiary_Right = false;                                 //   41
bool Primary_Left_Secondary_Down_Tertiary_Left = false;                                 //  44
bool Primary_Left_Secondary_Down_Tertiary_Right = false;                                //  28
bool Primary_Right_Secondary_Down_Tertiary_Left = false;                               //  26
bool Primary_Right_Secondary_Down_Tertiary_Right = false;                              //  42

bool Primary_Up_Secondary_Right_tertiary_Down = false;
bool Primary_Down_Secondary_Left_tertiary_Up = false;

bool Primary_Up_Secondary_Down_Tertiary_Up = false;
bool Primary_Down_Secondary_Up_Tertiary_Down = false;
bool Primary_Left_Secondary_Right_Tertiary_Left = false;
bool Primary_Right_Secondary_Left_Tertiary_Right = false;

//******************************************************Quaternary_Gesture***************************************************
bool Primary_Up_Secondary_Left_Tertiary_Up_Quaternary_Left = false;
bool Primary_Up_Secondary_Left_Tertiary_Up_Quaternary_Right = false;
bool Primary_Up_Secondary_Left_Tertiary_Down_Quaternary_Left = false;
bool Primary_Up_Secondary_Left_Tertiary_Down_Quaternary_Right = false;

bool Primary_Up_Secondary_Right_Tertiary_Up_Quaternary_Left = false;
bool Primary_Up_Secondary_Right_Tertiary_Up_Quaternary_Right = false;
bool Primary_Up_Secondary_Right_Tertiary_Down_Quaternary_Left = false;
bool Primary_Up_Secondary_Right_Tertiary_Down_Quaternary_Right = false;


bool Primary_Down_Secondary_Left_Tertiary_Up_Quaternary_Left = false;
bool Primary_Down_Secondary_Left_Tertiary_Up_Quaternary_Right = false;
bool Primary_Down_Secondary_Left_Tertiary_Down_Quaternary_Left = false;
bool Primary_Down_Secondary_Left_Tertiary_Down_Quaternary_Right = false;

bool Primary_Down_Secondary_Right_Tertiary_Up_Quaternary_Left = false;
bool Primary_Down_Secondary_Right_Tertiary_Up_Quaternary_Right = false;
bool Primary_Down_Secondary_Right_Tertiary_Down_Quaternary_Left = false;
bool Primary_Down_Secondary_Right_Tertiary_Down_Quaternary_Right = false;

bool Primary_Left_Secondary_Up_Tertiary_Left_Quaternary_Up = false;
bool Primary_Left_Secondary_Up_Tertiary_Left_Quaternary_Down = false;
bool Primary_Left_Secondary_Up_Tertiary_Right_Quaternary_Up = false;
bool Primary_Left_Secondary_Up_Tertiary_Right_Quaternary_Down = false;

bool Primary_Left_Secondary_Down_Tertiary_Left_Quaternary_Up = false;
bool Primary_Left_Secondary_Down_Tertiary_Left_Quaternary_Down = false;
bool Primary_Left_Secondary_Down_Tertiary_Right_Quaternary_Up = false;
bool Primary_Left_Secondary_Down_Tertiary_Right_Quaternary_Down = false;

bool Primary_Right_Secondary_Up_Tertiary_Left_Quaternary_Up = false;
bool Primary_Right_Secondary_Up_Tertiary_Left_Quaternary_Down = false;
bool Primary_Right_Secondary_Up_Tertiary_Right_Quaternary_Up = false;
bool Primary_Right_Secondary_Up_Tertiary_Right_Quaternary_Down = false;

bool Primary_Right_Secondary_Down_Tertiary_Left_Quaternary_Up = false;
bool Primary_Right_Secondary_Down_Tertiary_Left_Quaternary_Down = false;
bool Primary_Right_Secondary_Down_Tertiary_Right_Quaternary_Up = false;
bool Primary_Right_Secondary_Down_Tertiary_Right_Quaternary_Down = false;


//////////////////////////////////////////////////////////////

int current_mode = 00;
bool Gesture_mode_mouse_activity = false;
//**********************************************************************
#define MOVE_STEP 100

String Old_Connection_Name = "";
String Last_BLE_Disconnect_Reason = "00";
char Gesture_Input[2] = {0, 0};
char Store_Gesture_Input[2] = {0, 0};
//long int Starting_Message_millis = 0;


//////////////////////////////////////////////////////////////*******************************************************FUNCTIONS***************************************************************



void Change_To_Gesture_Mode()
{
  Gesture_User_Flag = true;
//  Gesture_mode_mouse_activity = true;
  Serial.println("Change_To_Gesture_Mode");
  current_mode = 98;
  Gesture_Input[0] = 'G';
  Gesture_Input[1] = 'C';
  
}

void Change_To_Phone_Mode()
{
  Gesture_User_Flag = false;
  Gesture_mode_mouse_activity = true;
  Serial.println("Change_To_Phone_Mode");
  current_mode = 97;
  Gesture_Input[0] = 'G';
  Gesture_Input[1] = 'C';
}

void Change_To_Testing_mode()
{
  Gesture_User_Flag = true;
//  Gesture_mode_mouse_activity = true;
  Serial.println("Change_To_Testing mode");
  current_mode = 92;
  Gesture_Input[0] = 'G';
  Gesture_Input[1] = 'C';
  
}

void Change_To_Roman_lowercase_keyboard_Mode()
{
  Gesture_User_Flag = true;
  Gesture_mode_mouse_activity = false;
  Serial.println("Change_To_Roman_lowercase_keybord_Mode");
  current_mode = 96; 
  Gesture_Input[0] = 'G';
  Gesture_Input[1] = 'C';
}

void Change_To_Roman_uppercase_Keyboard_mode()
{
  Gesture_User_Flag = true;
  Gesture_mode_mouse_activity = false;
  Serial.println("Change_To_Roman_uppercase_Keyboard_mode");
  current_mode = 95; 
  Gesture_Input[0] = 'G';
  Gesture_Input[1] = 'C';
}

void Change_To_numaric_lowercase_Keyboard_mode()   
{
  Gesture_User_Flag = true;
  Gesture_mode_mouse_activity = false;
  Serial.println("Change_To_numaric_lowercase_Keyboard_mode");
  current_mode = 94; 
  Gesture_Input[0] = 'G';
  Gesture_Input[1] = 'C';
}

void Change_To_numaric_uppercase_Keyboard_mode()
{
  Gesture_User_Flag = true;
  Gesture_mode_mouse_activity = false;
  Serial.println("Change_To_numaric_uppercase_Keyboard_mode");
  current_mode = 93; 
  Gesture_Input[0] = 'G';
  Gesture_Input[1] = 'C';
}

void Change_To_Mouse_Mode()
{
  Serial.println("Change_To_Mouse_Mode");
   Gesture_mode_mouse_activity = true;
   current_mode = 99;
  Gesture_Input[0] = 'M';
  Gesture_Input[1] = 'C';
  
//  Mouse_Screen_Orgin_Point();
}

//BLEHidAdafruit blehid;
//blehid.begin();

void Mobile_Screen_Back_Movement()
{
  blehid.consumerKeyPress(HID_USAGE_CONSUMER_AC_BACK);

  delay(100); // Delay to ensure the key press is registered

  blehid.consumerKeyRelease();
  // blehid.mouseButtonPress(MOUSE_BUTTON_FORWARD);
  // blehid.mouseButtonPress(MOUSE_BUTTON_BACKWARD);
  // delay(100);
  // blehid.mouseButtonPress(MOUSE_BUTTON_FORWARD);
  // blehid.mouseButtonPress(MOUSE_BUTTON_BACKWARD);
}

void Mobile_Screen_Right_Movement()
{
  blehid.mouseScroll(-100);
  //blehid.mousePan(100);
}

void Mobile_Screen_Left_Movement()
{
  blehid.mouseScroll(100);
}

// ===================== GESTURE FLAG RESET FUNCTIONS =====================
// Call these after gesture completion or timeout to prevent lockups.
void Reset_All_Gesture_Flags() {
  // Primary
  Primary_Up = false;
  Primary_Down = false;
  Primary_Left = false;
  Primary_Right = false;
  Primary_Tilt_Left = false;
  Primary_Tilt_Right = false;
  // Secondary
  Primary_Up_Secondary_Left = false;
  Primary_Up_Secondary_Right = false;
  Primary_Down_Secondary_Left = false;
  Primary_Down_Secondary_Right = false;
  Primary_Left_Secondary_Up = false;
  Primary_Left_Secondary_Down = false;
  Primary_Right_Secondary_Up = false;
  Primary_Right_Secondary_Down = false;
  Primary_Tilt_Left_Secondary_Tilt_Left = false;
  Primary_Tilt_Left_Secondary_Tilt_Right = false;
  Primary_Tilt_Right_Secondary_Tilt_Left = false;
  Primary_Tilt_Right_Secondary_Tilt_Right = false;
  Primary_Up_Secondary_Down = false;
  Primary_Down_Secondary_Up = false;
  Primary_Left_Secondary_Right = false;
  Primary_Right_Secondary_Left = false;
  // Tertiary
  Primary_Up_Secondary_Left_tertiary_Up = false;
  Primary_Up_Secondary_Left_tertiary_Down = false;
  Primary_Up_Secondary_Right_tertiary_Up = false;
  Primary_Up_Secondary_Left_Tertiary_Up = false;
  Primary_Up_Secondary_Left_Tertiary_Down = false;
  Primary_Down_Secondary_Left_Tertiary_Down = false;
  Primary_Down_Secondary_Left_Tertiary_Up = false;
  Primary_Up_Secondary_Right_Tertiary_Up = false;
  Primary_Up_Secondary_Right_Tertiary_Down = false;
  Primary_Down_Secondary_Right_Tertiary_Down = false;
  Primary_Down_Secondary_Right_Tertiary_Up = false;
  Primary_Left_Secondary_Up_Tertiary_Left = false;
  Primary_Left_Secondary_Up_Tertiary_Right = false;
  Primary_Right_Secondary_Up_Tertiary_Left = false;
  Primary_Right_Secondary_Up_Tertiary_Right = false;
  Primary_Left_Secondary_Down_Tertiary_Left = false;
  Primary_Left_Secondary_Down_Tertiary_Right = false;
  Primary_Right_Secondary_Down_Tertiary_Left = false;
  Primary_Right_Secondary_Down_Tertiary_Right = false;
  Primary_Up_Secondary_Right_tertiary_Down = false;
  Primary_Down_Secondary_Left_tertiary_Up = false;
  Primary_Up_Secondary_Down_Tertiary_Up = false;
  Primary_Down_Secondary_Up_Tertiary_Down = false;
  Primary_Left_Secondary_Right_Tertiary_Left = false;
  Primary_Right_Secondary_Left_Tertiary_Right = false;
  // Quaternary
  Primary_Up_Secondary_Left_Tertiary_Up_Quaternary_Left = false;
  Primary_Up_Secondary_Left_Tertiary_Up_Quaternary_Right = false;
  Primary_Up_Secondary_Left_Tertiary_Down_Quaternary_Left = false;
  Primary_Up_Secondary_Left_Tertiary_Down_Quaternary_Right = false;
  Primary_Up_Secondary_Right_Tertiary_Up_Quaternary_Left = false;
  Primary_Up_Secondary_Right_Tertiary_Up_Quaternary_Right = false;
  Primary_Up_Secondary_Right_Tertiary_Down_Quaternary_Left = false;
  Primary_Up_Secondary_Right_Tertiary_Down_Quaternary_Right = false;
  Primary_Down_Secondary_Left_Tertiary_Up_Quaternary_Left = false;
  Primary_Down_Secondary_Left_Tertiary_Up_Quaternary_Right = false;
  Primary_Down_Secondary_Left_Tertiary_Down_Quaternary_Left = false;
  Primary_Down_Secondary_Left_Tertiary_Down_Quaternary_Right = false;
  Primary_Down_Secondary_Right_Tertiary_Up_Quaternary_Left = false;
  Primary_Down_Secondary_Right_Tertiary_Up_Quaternary_Right = false;
  Primary_Down_Secondary_Right_Tertiary_Down_Quaternary_Left = false;
  Primary_Down_Secondary_Right_Tertiary_Down_Quaternary_Right = false;
  Primary_Left_Secondary_Up_Tertiary_Left_Quaternary_Up = false;
  Primary_Left_Secondary_Up_Tertiary_Left_Quaternary_Down = false;
  Primary_Left_Secondary_Up_Tertiary_Right_Quaternary_Up = false;
  Primary_Left_Secondary_Up_Tertiary_Right_Quaternary_Down = false;
  Primary_Left_Secondary_Down_Tertiary_Left_Quaternary_Up = false;
  Primary_Left_Secondary_Down_Tertiary_Left_Quaternary_Down = false;
  Primary_Left_Secondary_Down_Tertiary_Right_Quaternary_Up = false;
  Primary_Left_Secondary_Down_Tertiary_Right_Quaternary_Down = false;
  Primary_Right_Secondary_Up_Tertiary_Left_Quaternary_Up = false;
  Primary_Right_Secondary_Up_Tertiary_Left_Quaternary_Down = false;
  Primary_Right_Secondary_Up_Tertiary_Right_Quaternary_Up = false;
  Primary_Right_Secondary_Up_Tertiary_Right_Quaternary_Down = false;
  Primary_Right_Secondary_Down_Tertiary_Left_Quaternary_Up = false;
  Primary_Right_Secondary_Down_Tertiary_Left_Quaternary_Down = false;
  Primary_Right_Secondary_Down_Tertiary_Right_Quaternary_Up = false;
  Primary_Right_Secondary_Down_Tertiary_Right_Quaternary_Down = false;
}

void Reset_Gesture_Input() {
  Gesture_Input[0] = 'G';
  Gesture_Input[1] = 'C';
}
// ======================================================================
// Usage: Call Reset_All_Gesture_Flags() and Reset_Gesture_Input() after gesture completion or timeout in your gesture detection logic.
