/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombre: lenin toc
 * Carnet: 2019363
 * Proyecto: potenciometro RGB
*/
#define led_verde 10
#define led_azul 11
#define led_rojo 6
#define potenciometro A0
int timee;
void setup() {
pinMode(led_verde, OUTPUT);
pinMode(led_azul, OUTPUT);
pinMode(led_rojo, OUTPUT);
}

void loop() {
timee = map(analogRead(potenciometro),0,1023,100,1000);
analogWrite(led_rojo, 174);
analogWrite(led_verde, 92);
analogWrite(led_azul, 230);
delay(timee);

analogWrite(led_rojo,  255);
analogWrite(led_verde,  255);
analogWrite(led_azul,  255);
delay(timee);

analogWrite(led_rojo,  0);
analogWrite(led_verde,  255);
analogWrite(led_azul,  255);
delay(timee);

analogWrite(led_rojo,  189);
analogWrite(led_verde, 174);
analogWrite(led_azul, 20);
delay(timee);

analogWrite(led_rojo, 255);
analogWrite(led_verde, 87);
analogWrite(led_azul, 35);
delay(timee);
