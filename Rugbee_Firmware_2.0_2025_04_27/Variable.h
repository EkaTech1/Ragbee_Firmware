
int Delay_For_Identify_The_Gesture = 4;
int Delay_For_Gesture_Audio_Toast =4;
float batteryPercentage = 0;


const float X_threshold = 100.0;  // Adjust threshold for sensitivity
const float Y_threshold = 100.0;  // Adjust threshold for sensitivity
const float Z_threshold = 100.0;  // Adjust threshold for sensitivity


//const float X_Y_threshold = 100.0;  // Adjust threshold for sensitivity
//const float Y_threshold = 100.0;  // Adjust threshold for sensitivity
//const float Z_threshold = 100.0;  // Adjust threshold for sensitivity



//const float X_Y_threshold = 100.0;  // Adjust threshold for sensitivity
//const float Y_threshold = 100.0;  // Adjust threshold for sensitivity
//const float Z_threshold = 100.0;  // Adjust threshold for sensitivity


//HEX TO BINARY STRING CONVERSION LOGIC 


String hexToBinary(String hexString) {
  String binaryString = "";

  for (int i = 0; i < hexString.length(); i++) {
    switch (hexString[i]) {
      case '0': binaryString += "0000"; break;
      case '1': binaryString += "0001"; break;
      case '2': binaryString += "0010"; break;
      case '3': binaryString += "0011"; break;
      case '4': binaryString += "0100"; break;
      case '5': binaryString += "0101"; break;
      case '6': binaryString += "0110"; break;
      case '7': binaryString += "0111"; break;
      case '8': binaryString += "1000"; break;
      case '9': binaryString += "1001"; break;
      case 'A': case 'a': binaryString += "1010"; break;
      case 'B': case 'b': binaryString += "1011"; break;
      case 'C': case 'c': binaryString += "1100"; break;
      case 'D': case 'd': binaryString += "1101"; break;
      case 'E': case 'e': binaryString += "1110"; break;
      case 'F': case 'f': binaryString += "1111"; break;
      default:
        // Handle unexpected characters
        binaryString += "????"; // or handle the error as you see fit
        break;
    }
  }

  return binaryString;
}
