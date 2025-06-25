
// Add Mouse movement code. 

void Rugbee_Mouse()
{
  // Read motion from IMU and move mouse
  float x = myIMU.readFloatAccelX();
  float y = myIMU.readFloatAccelY();

  // Simple tilt control (adjust threshold/speed as needed)
  if (x > 0.2) blehid.mouseMove(MOVE_STEP, 0);
  if (x < -0.2) blehid.mouseMove(-MOVE_STEP, 0);
  if (y > 0.2) blehid.mouseMove(0, -MOVE_STEP);
  if (y < -0.2) blehid.mouseMove(0, MOVE_STEP);

  delay(100);  // Adjust for sensitivity
}
