void horiControl() {
  lcd.backlight();
  int horiRead = analogRead(A3);
  int horiDeg = map(horiRead, 0, 1000, 0, 90);
  lcd.setCursor(0, 0); // Set the cursor on the first column and first row.
  lcd.print("Hori Degrees: ");
  lcd.print(horiDeg);
  if (horiDeg < 10) {
    delay(1000);
    lcd.clear();
  }
}
