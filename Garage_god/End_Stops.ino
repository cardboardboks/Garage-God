void End_stops() {

  if (digitalRead(8) == LOW) {
    door_state = 0;
  }

  if (digitalRead(9) == LOW) {
    door_state = 1;
  }

}
