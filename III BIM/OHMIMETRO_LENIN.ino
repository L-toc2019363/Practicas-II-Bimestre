#include <LiquidCrystal_I2C.h>
#include <Wire.h>  
#define direccion_lcd 0x27
#define filas 2
#define columnas 16
const float resistencia1= 1000.0;
LiquidCrystal_I2C lcd(direccion_lcd, columnas, filas);


// Pin analógico para medir la resistencia desconocida
const int resistencia2 = A0;

void setup() {
  lcd.init();
  lcd.backlight();

  lcd.print("Ohmetro de lenin :D");
  lcd.setCursor(0, 1);
  lcd.print("LISTO");
  delay(5000);
  lcd.clear();
}

void loop() {
  int lectura_de_pin = analogRead(resistencia2);
  float voltaje = lectura_de_pin * (5.0 / 1023.0);
  float resistencia2 = (lectura_de_pin*resistencia1 / (5.0 - voltaje));

  lcd.setCursor(0, 0);
  lcd.print("Voltaje: ");
  lcd.print(voltaje);
  lcd.print("V");

  lcd.setCursor(0, 1);
  lcd.print("Resistencia :");
  lcd.print(resistencia2);
  lcd.print(" ohmios");

  delay(1000);
  lcd.clear();
}
