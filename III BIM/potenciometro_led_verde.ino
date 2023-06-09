/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombre: lenin toc
 * Carnet: 2019363
 * Proyecto: controlar led por medio de potenciometro
*/
#define led_verde 3
int potenciometro = 0;
int brillo = 0;

void setup()
{
  pinMode(led_verde, OUTPUT);
}

void loop()
{
  brillo = analogRead (potenciometro)/4;
  analogWrite(led_verde,brillo);
}
