void verticalControl() {
  int verDeg = 90;
  lcd.setCursor(0, 1); //Set the cursor on the third column and the second row (counting starts at 0!).
  lcd.print("Verti Degrees: ");
  lcd.print(verDeg);
};
