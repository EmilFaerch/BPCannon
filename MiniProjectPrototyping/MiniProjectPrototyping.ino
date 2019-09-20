/* I2C LCD with Arduino example code. More info: https://www.makerguides.com */

// Include the libraries:
// LiquidCrystal_I2C.h: https://github.com/johnrickman/LiquidCrystal_I2C
#include <Wire.h> // Library for I2C communication
#include <LiquidCrystal_I2C.h> // Library for LCD

// Wiring: SDA pin is connected to A4 and SCL pin to A5.
// Connect to LCD via I2C, default address 0x27 (A0-A2 not jumpered)
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 20, 4); // Change to (0x27,16,2) for 16x2 LCD.

int spinVal = A1;
int spinPin = 9;
void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  int potPin = A3;
  int onSwitch = A2;
  int powerPin = A1;

  pinMode(powerPin, INPUT);
  pinMode(spinPin, OUTPUT);
}

void loop() {
  int onRead = analogRead(A2);
  while (onRead > 500){

    horiControl();
    // Vertical degrees
    verticalControl();
    // power value
    powerControl();
  onRead = analogRead(A2);

  };
  turnOff();
  lcd.clear();
  lcd.noBacklight();
}
