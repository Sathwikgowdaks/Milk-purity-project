#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h> // Include the LiquidCrystal_I2C library for I2C LCD

#define TEMP_SENSOR_PIN 2
#define PH_SENSOR_PIN A0

OneWire oneWire(TEMP_SENSOR_PIN);
DallasTemperature sensors(&oneWire);

float ph_value, sensor_value = 0;
float temperatureC = 25.0;
bool increaseTemp = true;

// Set the LCD address and dimensions
LiquidCrystal_I2C lcd(0x27, 16, 2); // Change 0x27 to the address of your LCD

void setup() {
  Serial.begin(9600);
  sensors.begin();
  pinMode(9, OUTPUT);
  analogWrite(9, 50);
  lcd.init(); // Initialize the LCD
  lcd.backlight(); // Turn on backlight
}

void loop() {
  if (increaseTemp) {
    temperatureC += 1.0;
  } else {
    temperatureC -= 1.0;
  }
  
  increaseTemp = !increaseTemp;

  ph_value = analogRead(PH_SENSOR_PIN);
  sensor_value = (ph_value ) / 35;

  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" °C");
  Serial.print("pH value: ");
  Serial.println(sensor_value);
  
  lcd.clear(); // Clear the LCD
  lcd.setCursor(0, 0); // Set cursor to the first column, first row
  
  if (sensor_value < 5) {
    lcd.print("Grade C");
  } else if (sensor_value >= 5 && sensor_value <= 7) {
    lcd.print("Grade A");
  } else {
    lcd.print("Grade B");
  }
  
  delay(1000);
}
