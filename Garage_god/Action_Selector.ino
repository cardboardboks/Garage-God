/*
  0 - Idle State 0
  1 - Close Garge Door 14
  2 - Open Garage Door 24
  3 - Garage Lights On 34
  4 - Garage Lights Off 44
  5 - Cycle Garage Door 54
  6 - Crack Garge Door 64
  7 - Unsued 74
  8 - Close and Off 84
  9 - Idle State 94
*/

void Action_selector() {

  if (action_current_10 != action_change) {
    action_change = action_current_10;
    action_state = 1;
    if (bootflag == 1) {
      bootflag = 0;
      action_current_10 = 8;
    }
  }

  if (action_state == 1 && action_current_10 == 0) { //0 - Idle State
    action_state = 0;
    Debug();
    Serial.println("Idle State");
    delay(1000);
  }

  if (action_state == 1 && action_current_10 == 1) { //1 - Close Garge Door
    action_state = 0;
    Debug();
    Serial.println("Set Door to Close");
    delay(1000);
  }

  if (action_state == 1 && action_current_10 == 2) { //2 - Open Garage Door
    action_state = 0;
    Debug();
    Serial.println("Set Door to Open");
    delay(1000);
  }

  if (action_state == 1 && action_current_10 == 3) { //3 - Garage Lights On
    action_state = 0;
    Debug();
    Serial.println("Set Lights to On");
    delay(1000);
  }

  if (action_state == 1 && action_current_10 == 4) { //4 - Garage Lights Off
    action_state = 0;
    Debug();
    Serial.println("Set Lights to Off");
    delay(1000);
  }

  if (action_state == 1 && action_current_10 == 5) { //5 - Cycle Garage Door
    action_state = 0;
    Debug();
    Serial.println("Set Door to Cycle");
    delay(1000);
  }

  if (action_state == 1 && action_current_10 == 6) { //6 - Crack Garge Door
    action_state = 0;
    Debug();
    Serial.println("Set Door to Crack");
    delay(1000);
  }

  if (action_state == 1 && action_current_10 == 7) { //7 - Unsued
    action_state = 0;
    Debug();
    Serial.println("//7 - Unsued");
    delay(1000);
  }

  if (action_state == 1 && action_current_10 == 8) { //8 - Unsued
    action_state = 0;
    Debug();
    Serial.println("Set Door to Close");
    Serial.println("Set Lights to Off");
    delay(1000);
  }

  if (action_state == 1 && action_current_10 == 9) { //9 - Idle State
    action_state = 0;
    Debug();
    Serial.println("Idle State");
    delay(1000);
  }
}
