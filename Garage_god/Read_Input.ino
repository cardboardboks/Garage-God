void Read_input() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    total = total - readings[readIndex];
    readings[readIndex] = pwm_value;
    total = total + readings[readIndex];
    readIndex = readIndex + 1;

    if (readIndex >= numReadings) {
      readIndex = 0;
    }
    action_current = total / numReadings;

    if (action_current - action_current_old < 5 && action_current - action_current_old > -5) {
      action_current_10 = action_current / 100;
    }
    action_current_old = action_current;
  }
}
