void powerControl() {
  int powerRead = analogRead(A1);
  spinVal = (255. / 1023.) * powerRead;
  analogWrite(spinPin, powerRead);
  int powerVal = map (powerRead, 0, 1000, 0, 100);
  lcd.setCursor(0, 2);
  lcd.print("Wheel Power: ");
  lcd.print(powerVal);
  lcd.print("%");
  Serial.println(powerRead);
}
void turnOff(){
  analogWrite (spinPin, 0);
}
