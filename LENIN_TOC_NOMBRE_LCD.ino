/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Perito en electonica
 * Quinto perito
 * EB5AM / EB5AV
 * Taller de electronica digital y reparacion de computadoras
 * Nombre: Profe Alejandro Lopez
 * Fecha: 27/04/2023
 * Proyecto: LCD por medio de I2C
*/

#include <LiquidCrystal.h>

#define RS  6
#define Enable 7
#define D4 2
#define D5 3
#define D6 4
#define D7 5
LiquidCrystal LCD_lenin(RS, Enable, D4, D5, D6, D7); //Constructor que me permite usar la LCD




void setup()
{
  LCD_lenin.begin(16,2); //Objeto de una LCD de 16 columnas x 2 filas
  LCD_lenin.print("LENIN TOC");
  LCD_lenin.setCursor(0,1);
  LCD_lenin.print("2019363");
}
void loop()
{
  
}
