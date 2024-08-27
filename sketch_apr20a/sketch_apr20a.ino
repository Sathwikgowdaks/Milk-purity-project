#include <LiquidCrystal.h>

// Define the LCD pins
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // Set up the LCD's number of columns and rows
  lcd.begin(16, 2);
}

void loop() {
  // Display "Hello World"
  lcd.clear();
  lcd.print("Hello World");
  delay(1000); }// Wait for a second
