#include <Wire.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h> // Include the LiquidCrystal I2C library

#define TEMP_SENSOR_PIN 2
#define PH_SENSOR_PIN A0

OneWire oneWire(TEMP_SENSOR_PIN);
DallasTemperature sensors(&oneWire);

float ph_value, sensor_value = 0;
float temperatureC = 27.0;
bool increaseTemp = true;

// Adjust these values according to your LCD module
const int I2C_ADDR = 0x27; // I2C address of the LCD
const int LCD_COLS = 16;
const int LCD_ROWS = 2;

LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLS, LCD_ROWS);

void setup() {
  Serial.begin(9600);
  sensors.begin();
  Wire.begin();
  
  // Initialize LCD with backlight control
  lcd.begin(LCD_COLS, LCD_ROWS); // Specify the number of columns and rows
  lcd.setBacklight(50); // Set backlight level to 50%
}

void loop() {
  // Generate a random number between -1 and 1
  int randomTempChange = random(-1, 2); // Returns a random number between -1 and 1

  // Add the random temperature change to the current temperature
  temperatureC += randomTempChange;

  // Ensure temperature remains within a reasonable range (e.g., 0 to 50 degrees Celsius)
  temperatureC = constrain(temperatureC, 0, 50);

  ph_value = analogRead(PH_SENSOR_PIN);
  sensor_value = (ph_value -100 ) / 35;

  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" °C");
  Serial.print("pH value: ");
  Serial.println(sensor_value);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  
  if (sensor_value < 6 && temperatureC > 25) {
    lcd.print("Grade B");
  } else if (sensor_value >= 6 && sensor_value <= 7 && temperatureC > 25) {
    lcd.print("Grade A");
  } else {
    lcd.print("Grade C");
  }
  
  delay(1000);
}
