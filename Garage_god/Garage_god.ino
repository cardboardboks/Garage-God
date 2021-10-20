#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int action_special = 0;
int action_state = 0;
int action_change = 0;
int action_current_10 = 0;
int action_boot = 0;
int bootflag = 0;

int door_state = 4;
//0 - Closed
//1 - Open
//2 - Opening
//3 - Closing
//4 - Unknown

int door_action = 0;
//0 - Close
//1 - Open
//2 - Do nothing

int light_state = 0;
//0 - Off
//1 - On

int light_timer = 0;

long timer = 0;

volatile int pwm_value = 0;
volatile int prev_time = 0;

unsigned long previousMillis = 0;
const long interval = 100;

unsigned long previousMillis1 = 0;
const long interval1 = 500;

const int numReadings = 2;

int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
long total = 0;                  // the running total
long action_current = 0;                // the average
long action_current_old = 0;

#define I2C_ADDR    0x27  // Define I2C Address where the PCF8574A is
#define BACKLIGHT_PIN     3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7

LiquidCrystal_I2C       lcd(I2C_ADDR, En_pin, Rw_pin, Rs_pin, D4_pin, D5_pin, D6_pin, D7_pin);

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

  lcd.begin (20, 4, LCD_5x8DOTS);
  lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE); // init the backlight
  lcd.setBacklight(HIGH);

  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);

  lcd.setCursor(3, 0);
  lcd.print ("- Garage God -");

  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print ("Msg:       ");

  delay(1000);
  lcd.setCursor(0, 1);
  lcd.print ("Msg:Booting");

  delay(500);
  lcd.setCursor(0, 2);
  lcd.print ("Door State  :");

  delay(500);
  lcd.setCursor(0, 3);
  lcd.print ("Light State :");

  delay(500);
  while (timer < 100) {
    timer++;
    Read_input();
    lcd.setCursor(12, 1);
    lcd.print (timer);
  }

  door_action = 0;
  light_timer = 30;
  light_state = 0;


  delay(500);
  lcd.setCursor(0, 0);
  lcd.print ("                  ");

  while (bootflag < 6) {

    if (action_current_10 == 4 || action_current_10 == 0) {
      if (action_boot - action_current_10 != 0) {
        action_boot = action_current_10;
        bootflag++;
      }
    }

    lcd.setCursor(0, 0);
    lcd.print ("Err:System Locked   ");
    lcd.setCursor(19, 0);
    lcd.print (3 - (bootflag / 2));

    Read_input();
    Lcd();
    Lights();
    Door();
    End_stops();
  }

  lcd.setCursor(4, 1);
  lcd.print ("                ");
  lcd.setCursor(0, 0);
  lcd.print ("   - Garage God -   ");

}

void loop() {

  Read_input();
  Action_selector();
  Lcd();
  Lights();
  Door();
  End_stops();

}
