void Lcd() {

  unsigned long currentMillis1 = millis();
  if (currentMillis1 - previousMillis1 >= interval1) {
    previousMillis1 = currentMillis1;

    lcd.setCursor(3, 0);
    lcd.print ("              ");
    lcd.setCursor(0, 0);
    lcd.print ("Raw Input:");
    lcd.setCursor(10, 0);
    lcd.print (action_current_10);
    lcd.setCursor(12, 0);
    lcd.print (action_change);
    lcd.setCursor(14, 0);
    lcd.print ("");


    //Status

    if ((action_current_10 == 0 || action_current_10 == 9) && (door_state == 0 || door_state == 1)) {
      lcd.setCursor(4, 1);
      lcd.print ("System Idle     ");
    }

    //Door State
    lcd.setCursor(13, 2);
    if (door_state == 0) {
      lcd.print ("Closed ");
    }
    if (door_state == 1) {
      lcd.print ("Open   ");
    }
    if (door_state == 2) {
      lcd.print ("Opening");
    }
    if (door_state == 3) {
      lcd.print ("Closing");
    }
    if (door_state == 4) {
      lcd.print ("Unknown");
    }

    //Light State
    lcd.setCursor(13, 3);
    if (light_state == 0) {
      lcd.print ("Off");
    }
    if (light_state == 1) {
      lcd.print ("On ");
    }
  }
}
