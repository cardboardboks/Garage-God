
int action_state = 0;
int action_change = 0;
int action_current_10 = 0;
int bootflag = 1;
int bootup = 0;

volatile int pwm_value = 0;
volatile int prev_time = 0;

unsigned long previousMillis = 0;
const long interval = 100;

const int numReadings = 2;

int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
long total = 0;                  // the running total
long action_current = 0;                // the average
long action_current_old = 0;

void setup() {
  Serial.begin(115200);

  Serial.println("\t");
  Serial.println("\t");
  Serial.println("-- Welcome to Garage God --");
  delay(1000);

  // when pin D2 goes high, call the rising function
  attachInterrupt(0, rising, RISING);

  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }

}

void loop() {

  Read_input();
  Action_selector();

}
