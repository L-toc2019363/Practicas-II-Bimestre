/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombre: lenin toc
 * Carnet: 2019363
 * Proyecto: Uso de interrupciones de temporizador por medio de Ticker
*/

//Librerias
#include <Ticker.h>  
#include <OneWire.h>                
#include <DallasTemperature.h>


//Directivas de preprocesador
#define push_button 13 



//Funciones de ISR
void isr_temp(void); 
void isr_push(void); 


//Variables
volatile static bool estado_temp;
volatile static bool estado_push;

//Constructores 
Ticker isr_accion_temp(isr_temp, 10); 
Ticker isr_accion_push(isr_push, 3000);
OneWire ourWire(2);
DallasTemperature sensors(&ourWire); 

//void set up
  void setup() {
  Serial.begin(19200);  
  sensors.begin();
  isr_accion_temp.start();
  Serial.println("inicio de sensor temp");
  pinMode(push_button, INPUT);
  digitalWrite(push_button, LOW);
  isr_accion_push.start();   
  estado_push = LOW;
  Serial.println("inicion de push");
}

void loop() {
  isr_accion_temp.update();
   isr_accion_push.update();
}
void isr_push(void)
{
  estado_push = digitalRead(push_button); 
  if(estado_push == HIGH){
  digitalWrite(push_button, !estado_push);
  Serial.println("estado del push button");
  Serial.println("push button presionado");
}
  if(estado_push == LOW){
  digitalWrite(push_button, !estado_push);
  Serial.println("estado del push button");
  Serial.println("push button no  presionado");
}
}
void isr_temp(void)
{
  sensors.begin();
  sensors.requestTemperatures();   
  float tempC= sensors.getTempCByIndex(0);
  Serial.println("la temperatura actual es" );
  Serial.println(tempC);
  }
