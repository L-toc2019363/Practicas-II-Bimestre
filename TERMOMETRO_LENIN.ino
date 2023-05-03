/* 
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Perito en electonica
 * Quinto perito
 * EB5AM / EB5AV
 * Taller de electronica digital y reparacion de computadoras
 * Nombre: Profe Alejandro Lopez
 * Fecha: 27/04/2023
 * Proyecto: Sensor de Temperatura DS18B20
 */

//Librerias
#include <OneWire.h>                
#include <DallasTemperature.h>
 #include <Wire.h> 
#include <LiquidCrystal_I2C.h> 
//Constructores
OneWire ourWire(2);                //Se establece el pin 2  como el pin que utilizaremos para el protocolo OneWire
DallasTemperature sensors(&ourWire); //Se declara una objeto para nuestro sensor
#define direccion_lcd 0x27
#define filas 2
#define columnas 16
#define LED_ROJO 3
#define LED_AMARILLO 4
#define LED_AZUL 5
LiquidCrystal_I2C lcd_lenin(direccion_lcd, columnas, filas); //LCD con direccion 0x20 y tamanio 16x2
byte termometro[] = {
  B01110,
  B01010,
  B01010,
  B01010,
  B11011,
  B10001,
  B10001,
  B01110
};

void setup() {
delay(1000);
Serial.begin(9600);   //Inicio la comunicacion serial
sensors.begin();   //Se inicia el sensor
pinMode(LED_ROJO,INPUT);
pinMode(LED_AMARILLO,INPUT);
pinMode(LED_AZUL,INPUT);
lcd_lenin.createChar(1,termometro);
}
 
void loop() {
lcd_lenin.init();
lcd_lenin.backlight();
sensors.requestTemperatures();   //Se envía el comando para leer la temperatura
float temp= sensors.getTempCByIndex(0); //Se obtiene la temperatura en ºC
float temp1 = sensors.getTempFByIndex(0); //Se obtiene la temperatura en ºF
Serial.print("Temperatura= ");
Serial.print(temp);
Serial.println(" C");
Serial.print("Temperatura=");
Serial.print(temp1);
Serial.println("ºF");
if(temp>= 30){
lcd_lenin.setCursor(2,0);
lcd_lenin.print("Temperatura");
lcd_lenin.setCursor(1,1);
lcd_lenin.print(temp);
lcd_lenin.setCursor(10,1);
lcd_lenin.print(temp1);
lcd_lenin.setCursor(0,0);
lcd_lenin.write(1);
lcd_lenin.setCursor(0,1);
lcd_lenin.print("C");
lcd_lenin.setCursor(10,1);
lcd_lenin.print("F");
digitalWrite(LED_ROJO,HIGH); 
digitalWrite(LED_AZUL,LOW);
digitalWrite(LED_AMARILLO,LOW);

}
if(temp<=15){
lcd_lenin.setCursor(2,0);
lcd_lenin.print("Temperatura");
lcd_lenin.setCursor(1,1);
lcd_lenin.print(temp);
lcd_lenin.setCursor(10,1);
lcd_lenin.print(temp1);
lcd_lenin.setCursor(0,0);
lcd_lenin.write(1);
lcd_lenin.setCursor(0,1);
lcd_lenin.print("C");
lcd_lenin.setCursor(9,1);
lcd_lenin.print("F");
digitalWrite(LED_ROJO,LOW); 
digitalWrite(LED_AZUL,HIGH);
digitalWrite(LED_AMARILLO,LOW);
}

if(temp>=14.99 && temp<=29.99){
lcd_lenin.setCursor(2,0);
lcd_lenin.print("Temperatura");
lcd_lenin.setCursor(1,1);
lcd_lenin.print(temp);
lcd_lenin.setCursor(10,1);
lcd_lenin.print(temp1);
lcd_lenin.setCursor(0,0);
lcd_lenin.write(1);
lcd_lenin.setCursor(0,1);
lcd_lenin.print("C");
lcd_lenin.setCursor(9,1);
lcd_lenin.print("F");
digitalWrite(LED_ROJO,LOW); 
digitalWrite(LED_AZUL,LOW);
digitalWrite(LED_AMARILLO,HIGH);
}
}
