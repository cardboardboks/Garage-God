void Door() {

  if (door_action == 0) { //or timer finished

    if (door_state == 0) { //closed, do nothing
      lcd.setCursor(4, 1);
      lcd.print ("Allready Closed");
      door_action = 2;
      // delay(2000);
    }
    if (door_state == 1) { //Opened, close it
      door_state = 3;
      //trigger door button
      //start timer and wait for door to close
      //   delay(2000);
    }
    if (door_state == 2) {//opening
      lcd.setCursor(4, 1);
      lcd.print ("Door Opening   ");
      //wait for open then the code wil run
      //    delay(2000);
    }
    if (door_state == 3) {//closing
      lcd.setCursor(4, 1);
      lcd.print ("Door Closing   ");
      //   delay(2000);
    }
    if (door_state == 4) {
      lcd.setCursor(4, 1);
      lcd.print (" !Door unknown!");
      door_state = 1;
      //try closing first
      //   delay(2000);
    }
  }
}

void Open_door(int duration) {
  if (door_state == 0) { //closed, do nothing
    lcd.setCursor(5, 1);
    lcd.print ("Allready Closed");
  }
  if (door_state == 1) {
    lcd.setCursor(5, 1);
    lcd.print ("Allready Open  ");
  }
  if (door_state == 2) {
    lcd.setCursor(5, 1);
    lcd.print ("Door Opening   ");
  }
  if (door_state == 3) {
    lcd.setCursor(5, 1);
    lcd.print ("Door Closing   ");
  }
  if (door_state == 4) {
    lcd.setCursor(5, 1);
    lcd.print (" !Door unknown!");
  }
}

void Cycle_door(int duration) {

}

void Crack_door(int duration) {

}

void Lights() {
  if (light_state == 0) {
    digitalWrite(LED_BUILTIN, LOW);
    //Turn lights off
  }
  if (light_state == 1) {
    digitalWrite(LED_BUILTIN, HIGH);
    //Turn lights on
  }


}
