/* 
* Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Perito en electonica
 * Quinto perito
 * EB5AM / EB5AV
 * Taller de electronica digital y reparacion de computadoras
 * Nombre: lenin toc
 * Fecha: 3/05/2023
 * Proyecto: LCD por medio de I2C
 */
#include <Wire.h>    
#include <LiquidCrystal_I2C.h> 
#define direccion_lcd 0x27
#define filas 2
#define columnas 16
#define LED_1 4
#define LED_2 5
#define LED_3 6
#define LED_4 7
#define LED_5 8
#define LED_6 9
#define LED_7 10
#define LED_8 11
#define LED_9 12
#define LED_10 13
int trigger = 2;
int echo = 3;
int tiempo;
int distancia; 
int ZumbadorPin = 14;
LiquidCrystal_I2C lcdlenin(direccion_lcd, columnas, filas); 


void setup()
{
lcdlenin.init();
lcdlenin.backlight(); 
Serial.begin(9600);
pinMode(trigger, OUTPUT);
pinMode(echo,INPUT);
digitalWrite(trigger,LOW);
pinMode(ZumbadorPin, OUTPUT);
pinMode(LED_1,OUTPUT);
pinMode(LED_2,OUTPUT);
pinMode(LED_3,OUTPUT);
pinMode(LED_4,OUTPUT);
pinMode(LED_5,OUTPUT);
pinMode(LED_6,OUTPUT);
pinMode(LED_7,OUTPUT);
pinMode(LED_8,OUTPUT);
pinMode(LED_9,OUTPUT);
pinMode(LED_10,OUTPUT);

}



void loop()
{
digitalWrite(trigger, HIGH);
delayMicroseconds(10);
digitalWrite(trigger, LOW);
tiempo= pulseIn(echo, HIGH);
distancia= tiempo/59;
Serial.print("distancia");
Serial.print(distancia);
Serial.println("cm");
delay(100);
if(distancia>=45){
lcdlenin.init();
lcdlenin.backlight(); 
lcdlenin.print("fuera de alcance");
digitalWrite( LED_1,HIGH);
digitalWrite( LED_2,HIGH);
digitalWrite( LED_3,HIGH);
digitalWrite( LED_4,LOW);
digitalWrite( LED_5,LOW);
digitalWrite( LED_6,LOW);
digitalWrite( LED_7,LOW);
digitalWrite( LED_8,LOW);
digitalWrite( LED_9,LOW);
digitalWrite( LED_10,LOW); 
}

if(distancia>=30 && distancia<=44 ){
lcdlenin.init();
lcdlenin.backlight(); 
lcdlenin.print("Persona/objeto ");
lcdlenin.setCursor(0,1);
lcdlenin.print("acercandose");
digitalWrite( LED_1,HIGH);
digitalWrite( LED_2,HIGH);
digitalWrite( LED_3,HIGH);
digitalWrite( LED_4,HIGH);
digitalWrite( LED_5,HIGH);
digitalWrite( LED_6,LOW);
digitalWrite( LED_7,LOW);
digitalWrite( LED_8,LOW);
digitalWrite( LED_9,LOW);
digitalWrite( LED_10,LOW); 
}


if(distancia>=15 && distancia<=29 ){
lcdlenin.init();
lcdlenin.backlight(); 
lcdlenin.print("Cuidado");
lcdlenin.setCursor(0,1);
lcdlenin.print("espacio Privado");
digitalWrite( LED_1,HIGH);
digitalWrite( LED_2,HIGH);
digitalWrite( LED_3,HIGH);
digitalWrite( LED_4,HIGH);
digitalWrite( LED_5,HIGH);
digitalWrite( LED_6,HIGH);
digitalWrite( LED_7,HIGH);
digitalWrite( LED_8,LOW);
digitalWrite( LED_9,LOW);
digitalWrite( LED_10,LOW); 
tone(ZumbadorPin,  1000 );
delay(5000);
noTone(ZumbadorPin);
}


if(distancia>=5 && distancia<=14 ){
lcdlenin.init();
lcdlenin.backlight(); 
lcdlenin.print("Invadiendo");
lcdlenin.setCursor(0,1);
lcdlenin.print("espacio Privado");
digitalWrite( LED_1,HIGH);
digitalWrite( LED_2,HIGH);
digitalWrite( LED_3,HIGH);
digitalWrite( LED_4,HIGH);
digitalWrite( LED_5,HIGH);
digitalWrite( LED_6,HIGH);
digitalWrite( LED_7,HIGH);
digitalWrite( LED_8,HIGH);
digitalWrite( LED_9,HIGH);
digitalWrite( LED_10,HIGH); 
 tone(ZumbadorPin,  2000);
 delay(10000);
 noTone(ZumbadorPin);
}
}
