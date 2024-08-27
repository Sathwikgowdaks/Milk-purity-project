#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2, ct = 9;
LiquidCrystal mylcd(rs, en, d4, d5, d6, d7);

void setup() {
  // Initialize contrast pin as an output
  pinMode(ct, OUTPUT);
  
  // Set contrast value
  analogWrite(ct, 50); // Adjust the value as needed

  // Initialize LCD
  mylcd.begin(16, 2);
  mylcd.print("HELLO WORLD!");
}

void loop() {
 
}
