
#include <Wire.h> // Library for I2C communication
#include <LiquidCrystal_I2C.h> // Library for LCD

LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 20, 4); // Informs the program what type of LCD is being used

int spinVal = A1;
int spinPin = 9;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  int potPin = A3;
  int powerPin = A1;

  pinMode(powerPin, INPUT);
  pinMode(spinPin, OUTPUT);
}

void loop() {
  //The A2 pin is read to see if the on-switch is flicked on
  int onRead = analogRead(A2);
  //If the on switch is flicked, the following code is executed while it is on
  while (onRead > 500){
    //Function for the horizontal controls
    horiControl();
    // Function for the Vertical controls
    verticalControl();
    // Funtion for controlling the speed of the wheels
    powerControl();
  //The value is read again so the function also exits the while loop
  onRead = analogRead(A2);

  };
  //When the on switch is not flicked, the following code is run
  turnOff();
  lcd.clear();
  lcd.noBacklight();
}
