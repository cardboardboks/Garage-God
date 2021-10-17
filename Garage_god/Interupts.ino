void rising() {
  attachInterrupt(0, falling, FALLING);
  prev_time = micros();
}

void falling() {
  attachInterrupt(0, rising, RISING);
  pwm_value = micros() - prev_time;
}
