#include <Wire.h>
#include <PCF8574.h>

const int ledPines[] = {2,4,5,6,7,8,9,10,11,12,13,A0,A1,A2,A3,A6,A7};
const int ledsitosI2C[] = {0,1,2,3,4};
const int numDepartamentos = 22;
long randomNumerito;
String inf_recibida; // Declaro una variable tipo string donde almacenaré la información recibida.
#define buzzerPin 3 
PCF8574 expansorin(0x20);
void setup()
{ 
  
  Serial.begin(9600); // Inicializo la comunicación serial a una velocidad de 9600 baudios.
  Wire.begin();
  expansorin.begin();
  for (int i = 0; i < 17; i++) {
    pinMode(ledPines[i], OUTPUT); // Declarar los pines de los LEDs como salidas
  }
  for (int i = 17; i < numDepartamentos; i++) {
   pinMode(ledsitosI2C[i], OUTPUT);  // Declarar los pines de los LEDs como salidas
  }
  
  pinMode(buzzerPin, OUTPUT); // Declarar el pin del buzzer como salida
}

void loop()
{
  randomNumerito = random(1, 22);
  Serial.print("pregunta: ");

  if (randomNumerito == 1) {
    Serial.println("¿Cuál es la capital de Petén?");
    verificarRespuesta("Flores", 0);
  } else if (randomNumerito == 2) {
    Serial.println("¿Cuál es la capital de Izabal?");
    verificarRespuesta("Puerto Barrios", 1);
  } else if (randomNumerito == 3) {
    Serial.println("¿Cuál es la capital de Alta Verapaz?");
    verificarRespuesta("Cobán", 2);
  } else if (randomNumerito == 4) {
    Serial.println("¿Cuál es la capital de Quiché?");
    verificarRespuesta("Santa Cruz del Quiché", 3);
  } else if (randomNumerito == 5) {
    Serial.println("¿Cuál es la capital de Huehuetenango?");
    verificarRespuesta("Huehuetenango", 4);
  } else if (randomNumerito == 6) {
    Serial.println("¿Cuál es la capital de Escuintla?");
    verificarRespuesta("Escuintla", 5);
  } else if (randomNumerito == 7) {
    Serial.println("¿Cuál es la capital de San Marcos?");
    verificarRespuesta("San Marcos", 6);
  } else if (randomNumerito == 8) {
    Serial.println("¿Cuál es la capital de Jutiapa?");
    verificarRespuesta("Jutiapa", 7);
  } else if (randomNumerito == 9) {
    Serial.println("¿Cuál es la capital de Baja Verapaz?");
    verificarRespuesta("Salamá", 8);
  } else if (randomNumerito == 10) {
    Serial.println("¿Cuál es la capital de Santa Rosa?");
    verificarRespuesta("Cuilapa", 9);
  } else if (randomNumerito == 11) {
    Serial.println("¿Cuál es la capital de Zacapa?");
    verificarRespuesta("Zacapa", 10);
  } else if (randomNumerito == 12) {
    Serial.println("¿Cuál es la capital de Suchitepéquez?");
    verificarRespuesta("Mazatenango", 11);
  } else if (randomNumerito == 13) {
    Serial.println("¿Cuál es la capital de Chiquimula?");
    verificarRespuesta("Chiquimula", 12);
  } else if (randomNumerito == 14) {
    Serial.println("¿Cuál es la capital de Guatemala?");
    verificarRespuesta("Guatemala", 13);
  } else if (randomNumerito == 15) {
    Serial.println("¿Cuál es la capital de Jalapa?");
    verificarRespuesta("Jalapa", 14);
  } else if (randomNumerito == 16) {
    Serial.println("¿Cuál es la capital de Chimaltenango?");
    verificarRespuesta("Chimaltenango", 15);
  } else if (randomNumerito == 17) {
    Serial.println("¿Cuál es la capital de Quetzaltenango?");
    verificarRespuesta("Quetzaltenango", 16);
  } else if (randomNumerito == 18) {
    Serial.println("¿Cuál es la capital de El Progreso?");
    verificarRespuesta("Guastatoya", 17);
  } else if (randomNumerito == 19) {
    Serial.println("¿Cuál es la capital de Retalhuleu?");
    verificarRespuesta("Retalhuleu", 18);
  } else if (randomNumerito == 20) {
    Serial.println("¿Cuál es la capital de Sololá?");
    verificarRespuesta("Sololá", 19);
  } else if (randomNumerito == 21) {
    Serial.println("¿Cuál es la capital de Totonicapán?");
    verificarRespuesta("Totonicapán", 20);
  } else if (randomNumerito == 22) {
    Serial.println("¿Cuál es la capital de Sacatepéquez?");
    verificarRespuesta("La Antigua Guatemala", 21);
  }

  delay(500);
}

void verificarRespuesta(String respuestaCorrecta, int departamento)
{
  while (!Serial.available()) {
    // Esperar a que llegue una respuesta por Bluetooth
  }
  inf_recibida = Serial.readString(); 
  inf_recibida.trim();
if(randomNumerito>0 && randomNumerito<=17){
  if (inf_recibida == respuestaCorrecta) {
    digitalWrite(ledPines[departamento], HIGH); 
    Serial.println("¡Respuesta correcta!");
  } else {
    Serial.println("respuesta incorrecta :(");
    digitalWrite(ledPines[departamento], LOW);
    tone(9,293.66,200);
    delay(200);
    tone(buzzerPin,293.66,100);
    delay(100);
    tone(buzzerPin,293.66,200);
    delay(200);
    tone(buzzerPin,293.66,100);
    delay(100);
    tone(buzzerPin,293.66,200);
    delay(200);
    tone(buzzerPin,293.66,100);
    delay(100);
    tone(buzzerPin,293.66,100);
    delay(100);
    tone(buzzerPin,293.66,100);
    delay(100);
    tone(buzzerPin,293.66,100);
    delay(100);
    tone(buzzerPin,293.66,200);
    delay(200);
    tone(buzzerPin,293.66,100);
    delay(100);
    tone(buzzerPin,293.66,200);
    delay(200);
    tone(buzzerPin,293.66,100);
    delay(100);
    tone(buzzerPin,293.66,200);
    delay(200);
    tone(buzzerPin,293.66,100);
    delay(100);
    tone(buzzerPin,293.66,100);
    delay(100);
    tone(buzzerPin,293.66,100);
    delay(100);
    tone(buzzerPin,293.66,100);
    delay(100);
    tone(buzzerPin,293.66,200);
    delay(200);
    tone(buzzerPin,293.66,100);
    delay(100);
    tone(buzzerPin,293.66,200);
    delay(200);
    tone(buzzerPin,293.66,100);
    delay(100);
    tone(buzzerPin,293.66,200);
    delay(200);
    tone(buzzerPin,293.66,100);
    delay(100);
    tone(buzzerPin,293.66,100);
    delay(100);
    tone(buzzerPin,440,100);
    delay(100);
    tone(buzzerPin,523.25,100);
    delay(100);
    tone(buzzerPin,587.33,100);
    delay(200);
    tone(buzzerPin,587.33,100);
    delay(200);
    tone(buzzerPin,587.33,100);
    delay(100);
    tone(buzzerPin,659.25,100);
    delay(100);
    tone(buzzerPin,698.45,100);
    delay(200);
    tone(buzzerPin,698.45,100);
    delay(200);
    tone(buzzerPin,698.45,100);
    delay(100);
    tone(buzzerPin,783.99,100);
    delay(100);
    tone(buzzerPin,659.25,100);
    delay(200);
    tone(buzzerPin,659.25,100);
    delay(200);
    tone(buzzerPin,587.33,100);
    delay(100);
    tone(buzzerPin,523.25,100);
    delay(100);
    tone(buzzerPin,523.25,100);
    delay(100);
    tone(buzzerPin,587.33,100);
    delay(300);
    tone(buzzerPin,440,100);
    delay(100);
    tone(buzzerPin,523.25,100);
    delay(100);
    tone(buzzerPin,587.33,100);
    delay(200);
    tone(buzzerPin,587.33,100);
    delay(200);
    tone(buzzerPin,587.33,100);
    delay(100);
    tone(buzzerPin,659.25,100);
    delay(100);
    tone(buzzerPin,698.45,100);
    delay(200);
    tone(buzzerPin,698.45,100);
    delay(200);
    tone(buzzerPin,698.45,100);
    delay(100);
    tone(buzzerPin,783.99,100);
    delay(100);
    tone(buzzerPin,659.25,100);
    delay(200);
    tone(buzzerPin,659.25,100);
    delay(200);
    tone(buzzerPin,587.33,100);
    delay(100);
    tone(buzzerPin,523.25,100);
    delay(100);
    tone(buzzerPin,587.33,100);
    delay(400);
    tone(buzzerPin,440,100);
    delay(100);
    tone(buzzerPin,523.25,100);
    delay(100);
    tone(buzzerPin,587.33,100);
    delay(200);
    tone(buzzerPin,587.33,100);
    delay(200);
    tone(buzzerPin,587.33,100);
    delay(100);
    tone(buzzerPin,698.45,100);
    delay(100);
    tone(buzzerPin,783.99,100);
    delay(200);
    tone(buzzerPin,783.99,100);
    delay(200);
    tone(buzzerPin,783.99,100);
    delay(100);
    tone(buzzerPin,880,100);
    delay(100);
    tone(buzzerPin,932.33,100);
    delay(200);
    tone(buzzerPin,932.33,100);
    delay(200);
    tone(buzzerPin,880,100);
    delay(100);
    tone(buzzerPin,783.99,100);
    delay(100);
    tone(buzzerPin,880,100);
    delay(100);
    tone(buzzerPin,587.33,100);
    delay(300);
    tone(buzzerPin,587.33,100);
    delay(100);
    tone(buzzerPin,659.25,100);
    delay(100);
    tone(buzzerPin,698.45,100);
    delay(200);
    tone(buzzerPin,698.45,100);
    delay(200);
    tone(buzzerPin,783.99,100);
    delay(200);
    tone(buzzerPin,880,100);
    delay(100);
    tone(buzzerPin,587.33,100);
    delay(300);
    tone(buzzerPin,587.33,100);
    delay(100);
    tone(buzzerPin,698.45,100);
    delay(100);
    tone(buzzerPin,659.25,100);
    delay(200);
    tone(buzzerPin,659.25,100);
    delay(200);
    tone(buzzerPin,698.45,100);
    delay(100);
    tone(buzzerPin,587.33,100);
    delay(100);
    tone(buzzerPin,659.25,100);
    delay(400);
    tone(buzzerPin,880,100);
    delay(100);
    tone(buzzerPin,1046.50,100);
    delay(100);
    tone(buzzerPin,1174.66,100);
    delay(200);
    tone(buzzerPin,1174.66,100);
    delay(200);
    tone(buzzerPin,1174.66,100);
    delay(100);
    tone(buzzerPin,1318.51,100);
    delay(100);
    tone(buzzerPin,1396.91,100);
    delay(200);
    tone(buzzerPin,1396.91,100);
    delay(200);
    tone(buzzerPin,1396.91,100);
    delay(100);
    tone(buzzerPin,1567.98,100);
    delay(100);
    tone(buzzerPin,1318.51,100);
    delay(200);
    tone(buzzerPin,1318.51,100);
    delay(200);
    tone(buzzerPin,1174.66,100);
    delay(100);
    tone(buzzerPin,1046.50,100);
    delay(100);
    tone(buzzerPin,1046.50,100);
    delay(100);
    tone(buzzerPin,1174.66,100);
    delay(300);
    tone(buzzerPin,880,100);
    delay(100);
    tone(buzzerPin,1046.50,100);
    delay(100);
    tone(buzzerPin,1174.66,100);
    delay(200);
    tone(buzzerPin,1174.66,100);
    delay(200);
    tone(buzzerPin,1174.66,100);
    delay(100);
    tone(buzzerPin,1318.51,100);
    delay(100);
    tone(buzzerPin,1396.91,100);
    delay(200);
    tone(buzzerPin,1396.91,100);
    delay(200);
    tone(buzzerPin,1396.91,100);
    delay(100);
    tone(buzzerPin,1567.98,100);
    delay(100);
    tone(buzzerPin,1318.51,100);
    delay(200);
    tone(buzzerPin,1318.51,100);
    delay(200);
    tone(buzzerPin,1174.66,100);
    delay(100);
    tone(buzzerPin,1046.50,100);
    delay(100);
    tone(buzzerPin,1174.66,100);
    delay(400);
    tone(buzzerPin,880,100);
    delay(100);
    tone(buzzerPin,1046.50,100);
    delay(100);
    tone(buzzerPin,1174.66,100);
    delay(200);
    tone(buzzerPin,1174.66,100);
    delay(200);
    tone(buzzerPin,1174.66,100);
    delay(100);
    tone(buzzerPin,1396.91,100);
    delay(100);
    tone(buzzerPin,1567.98,100);
    delay(200);
    tone(buzzerPin,1567.98,100);
    delay(200);
    tone(buzzerPin,1567.98,100);
    delay(100);
    tone(buzzerPin,1760,100);
    delay(100);
    tone(buzzerPin,1864.66,100);
    delay(200);
    tone(buzzerPin,1864.66,100);
    delay(200);
    tone(buzzerPin,1760,100);
    delay(100);
    tone(buzzerPin,1567.98,100);
    delay(100);
    tone(buzzerPin,1760,100);
    delay(100);
    tone(buzzerPin,1174.66,100);
    delay(300);
    tone(buzzerPin,1174.66,100);
    delay(100);
    tone(buzzerPin,1318.51,100);
    delay(100);
    tone(buzzerPin,1396.91,100);
    delay(200);
    tone(buzzerPin,1396.91,100);
    delay(200);
    tone(buzzerPin,1567.98,100);
    delay(200);
    tone(buzzerPin,1760,100);
    delay(100);
    tone(9,1174.66,100);
    delay(300);
    tone(buzzerPin,1174.66,100);
    delay(100);
    tone(buzzerPin,1396.91,100);
    delay(100);
    tone(buzzerPin,1318.51,100);
    delay(200);
    tone(buzzerPin,1318.51,100);
    delay(200);
    tone(buzzerPin,1174.66,100);
    delay(100);
    tone(buzzerPin,1108.73,100);
    delay(100);
    tone(buzzerPin,1174.66,100);
    delay(200);
    tone(buzzerPin,1174.66,100);
    delay(200);
    tone(buzzerPin,1318.51,100);
    delay(200);
    tone(buzzerPin,1396.91,100);
    delay(200);
    tone(buzzerPin,1396.91,100);
    delay(100);
    tone(buzzerPin,1396.91,100);
    delay(100);
    tone(buzzerPin,1567.98,100);
    delay(200);
    tone(buzzerPin,1760,300);
    delay(400);
    tone(buzzerPin,1396.91,100);
    delay(100);
    tone(buzzerPin,1174.66,100);
    delay(100);
    tone(buzzerPin,880,300);
    delay(600);
    tone(buzzerPin,1864.66,300);
    delay(400);
    tone(buzzerPin,1396.91,100);
    delay(100);
    tone(buzzerPin,1174.66,100);
    delay(100);
    tone(buzzerPin,932.33,300);
    delay(600);
    tone(buzzerPin,587.33,100);
    delay(100);
    tone(buzzerPin,440,100);
    delay(200);
    tone(buzzerPin,587.33,100);
    delay(300);
    tone(buzzerPin,554.36,100);
    delay(400);
    tone(buzzerPin,1567.98,100);
    delay(100);
    tone(buzzerPin,1567.98,100);
    delay(100);
    noTone(buzzerPin);
  }
}
if(randomNumerito>=18 && randomNumerito<=22){
  if (inf_recibida == respuestaCorrecta) {
    digitalWrite(ledsitosI2C[departamento], LOW); 
    Serial.println("¡Respuesta correcta!");
    noTone(buzzerPin);
  } 
  else {
    Serial.println("respuesta incorrecta :(");
    digitalWrite(ledsitosI2C[departamento], HIGH);
    tone(9,293.66,200);
    delay(200);
    tone(buzzerPin,293.66,100);
    delay(100);
    tone(buzzerPin,293.66,200);
    delay(200);
    tone(buzzerPin,293.66,100);
    delay(100);
    tone(buzzerPin,293.66,200);
    delay(200);
    tone(buzzerPin,293.66,100);
    delay(100);
    tone(buzzerPin,293.66,100);
    delay(100);
    tone(buzzerPin,293.66,100);
    delay(100);
    tone(buzzerPin,293.66,100);
    delay(100);
    tone(buzzerPin,293.66,200);
    delay(200);
    tone(buzzerPin,293.66,100);
    delay(100);
    tone(buzzerPin,293.66,200);
    delay(200);
    tone(buzzerPin,293.66,100);
    delay(100);
    tone(buzzerPin,293.66,200);
    delay(200);
    tone(buzzerPin,293.66,100);
    delay(100);
    tone(buzzerPin,293.66,100);
    delay(100);
    tone(buzzerPin,293.66,100);
    delay(100);
    tone(buzzerPin,293.66,100);
    delay(100);
    tone(buzzerPin,293.66,200);
    delay(200);
    tone(buzzerPin,293.66,100);
    delay(100);
    tone(buzzerPin,293.66,200);
    delay(200);
    tone(buzzerPin,293.66,100);
    delay(100);
    tone(buzzerPin,293.66,200);
    delay(200);
    tone(buzzerPin,293.66,100);
    delay(100);
    tone(buzzerPin,293.66,100);
    delay(100);
    tone(buzzerPin,440,100);
    delay(100);
    tone(buzzerPin,523.25,100);
    delay(100);
    tone(buzzerPin,587.33,100);
    delay(200);
    tone(buzzerPin,587.33,100);
    delay(200);
    tone(buzzerPin,587.33,100);
    delay(100);
    tone(buzzerPin,659.25,100);
    delay(100);
    tone(buzzerPin,698.45,100);
    delay(200);
    tone(buzzerPin,698.45,100);
    delay(200);
    tone(buzzerPin,698.45,100);
    delay(100);
    tone(buzzerPin,783.99,100);
    delay(100);
    tone(buzzerPin,659.25,100);
    delay(200);
    tone(buzzerPin,659.25,100);
    delay(200);
    tone(buzzerPin,587.33,100);
    delay(100);
    tone(buzzerPin,523.25,100);
    delay(100);
    tone(buzzerPin,523.25,100);
    delay(100);
    tone(buzzerPin,587.33,100);
    delay(300);
    tone(buzzerPin,440,100);
    delay(100);
    tone(buzzerPin,523.25,100);
    delay(100);
    tone(buzzerPin,587.33,100);
    delay(200);
    tone(buzzerPin,587.33,100);
    delay(200);
    tone(buzzerPin,587.33,100);
    delay(100);
    tone(buzzerPin,659.25,100);
    delay(100);
    tone(buzzerPin,698.45,100);
    delay(200);
    tone(buzzerPin,698.45,100);
    delay(200);
    tone(buzzerPin,698.45,100);
    delay(100);
    tone(buzzerPin,783.99,100);
    delay(100);
    tone(buzzerPin,659.25,100);
    delay(200);
    tone(buzzerPin,659.25,100);
    delay(200);
    tone(buzzerPin,587.33,100);
    delay(100);
    tone(buzzerPin,523.25,100);
    delay(100);
    tone(buzzerPin,587.33,100);
    delay(400);
    tone(buzzerPin,440,100);
    delay(100);
    tone(buzzerPin,523.25,100);
    delay(100);
    tone(buzzerPin,587.33,100);
    delay(200);
    tone(buzzerPin,587.33,100);
    delay(200);
    tone(buzzerPin,587.33,100);
    delay(100);
    tone(buzzerPin,698.45,100);
    delay(100);
    tone(buzzerPin,783.99,100);
    delay(200);
    tone(buzzerPin,783.99,100);
    delay(200);
    tone(buzzerPin,783.99,100);
    delay(100);
    tone(buzzerPin,880,100);
    delay(100);
    tone(buzzerPin,932.33,100);
    delay(200);
    tone(buzzerPin,932.33,100);
    delay(200);
    tone(buzzerPin,880,100);
    delay(100);
    tone(buzzerPin,783.99,100);
    delay(100);
    tone(buzzerPin,880,100);
    delay(100);
    tone(buzzerPin,587.33,100);
    delay(300);
    tone(buzzerPin,587.33,100);
    delay(100);
    tone(buzzerPin,659.25,100);
    delay(100);
    tone(buzzerPin,698.45,100);
    delay(200);
    tone(buzzerPin,698.45,100);
    delay(200);
    tone(buzzerPin,783.99,100);
    delay(200);
    tone(buzzerPin,880,100);
    delay(100);
    tone(buzzerPin,587.33,100);
    delay(300);
    tone(buzzerPin,587.33,100);
    delay(100);
    tone(buzzerPin,698.45,100);
    delay(100);
    tone(buzzerPin,659.25,100);
    delay(200);
    tone(buzzerPin,659.25,100);
    delay(200);
    tone(buzzerPin,698.45,100);
    delay(100);
    tone(buzzerPin,587.33,100);
    delay(100);
    tone(buzzerPin,659.25,100);
    delay(400);
    tone(buzzerPin,880,100);
    delay(100);
    tone(buzzerPin,1046.50,100);
    delay(100);
    tone(buzzerPin,1174.66,100);
    delay(200);
    tone(buzzerPin,1174.66,100);
    delay(200);
    tone(buzzerPin,1174.66,100);
    delay(100);
    tone(buzzerPin,1318.51,100);
    delay(100);
    tone(buzzerPin,1396.91,100);
    delay(200);
    tone(buzzerPin,1396.91,100);
    delay(200);
    tone(buzzerPin,1396.91,100);
    delay(100);
    tone(buzzerPin,1567.98,100);
    delay(100);
    tone(buzzerPin,1318.51,100);
    delay(200);
    tone(buzzerPin,1318.51,100);
    delay(200);
    tone(buzzerPin,1174.66,100);
    delay(100);
    tone(buzzerPin,1046.50,100);
    delay(100);
    tone(buzzerPin,1046.50,100);
    delay(100);
    tone(buzzerPin,1174.66,100);
    delay(300);
    tone(buzzerPin,880,100);
    delay(100);
    tone(buzzerPin,1046.50,100);
    delay(100);
    tone(buzzerPin,1174.66,100);
    delay(200);
    tone(buzzerPin,1174.66,100);
    delay(200);
    tone(buzzerPin,1174.66,100);
    delay(100);
    tone(buzzerPin,1318.51,100);
    delay(100);
    tone(buzzerPin,1396.91,100);
    delay(200);
    tone(buzzerPin,1396.91,100);
    delay(200);
    tone(buzzerPin,1396.91,100);
    delay(100);
    tone(buzzerPin,1567.98,100);
    delay(100);
    tone(buzzerPin,1318.51,100);
    delay(200);
    tone(buzzerPin,1318.51,100);
    delay(200);
    tone(buzzerPin,1174.66,100);
    delay(100);
    tone(buzzerPin,1046.50,100);
    delay(100);
    tone(buzzerPin,1174.66,100);
    delay(400);
    tone(buzzerPin,880,100);
    delay(100);
    tone(buzzerPin,1046.50,100);
    delay(100);
    tone(buzzerPin,1174.66,100);
    delay(200);
    tone(buzzerPin,1174.66,100);
    delay(200);
    tone(buzzerPin,1174.66,100);
    delay(100);
    tone(buzzerPin,1396.91,100);
    delay(100);
    tone(buzzerPin,1567.98,100);
    delay(200);
    tone(buzzerPin,1567.98,100);
    delay(200);
    tone(buzzerPin,1567.98,100);
    delay(100);
    tone(buzzerPin,1760,100);
    delay(100);
    tone(buzzerPin,1864.66,100);
    delay(200);
    tone(buzzerPin,1864.66,100);
    delay(200);
    tone(buzzerPin,1760,100);
    delay(100);
    tone(buzzerPin,1567.98,100);
    delay(100);
    tone(buzzerPin,1760,100);
    delay(100);
    tone(buzzerPin,1174.66,100);
    delay(300);
    tone(buzzerPin,1174.66,100);
    delay(100);
    tone(buzzerPin,1318.51,100);
    delay(100);
    tone(buzzerPin,1396.91,100);
    delay(200);
    tone(buzzerPin,1396.91,100);
    delay(200);
    tone(buzzerPin,1567.98,100);
    delay(200);
    tone(buzzerPin,1760,100);
    delay(100);
    tone(9,1174.66,100);
    delay(300);
    tone(buzzerPin,1174.66,100);
    delay(100);
    tone(buzzerPin,1396.91,100);
    delay(100);
    tone(buzzerPin,1318.51,100);
    delay(200);
    tone(buzzerPin,1318.51,100);
    delay(200);
    tone(buzzerPin,1174.66,100);
    delay(100);
    tone(buzzerPin,1108.73,100);
    delay(100);
    tone(buzzerPin,1174.66,100);
    delay(200);
    tone(buzzerPin,1174.66,100);
    delay(200);
    tone(buzzerPin,1318.51,100);
    delay(200);
    tone(buzzerPin,1396.91,100);
    delay(200);
    tone(buzzerPin,1396.91,100);
    delay(100);
    tone(buzzerPin,1396.91,100);
    delay(100);
    tone(buzzerPin,1567.98,100);
    delay(200);
    tone(buzzerPin,1760,300);
    delay(400);
    tone(buzzerPin,1396.91,100);
    delay(100);
    tone(buzzerPin,1174.66,100);
    delay(100);
    tone(buzzerPin,880,300);
    delay(600);
    tone(buzzerPin,1864.66,300);
    delay(400);
    tone(buzzerPin,1396.91,100);
    delay(100);
    tone(buzzerPin,1174.66,100);
    delay(100);
    tone(buzzerPin,932.33,300);
    delay(600);
    tone(buzzerPin,587.33,100);
    delay(100);
    tone(buzzerPin,440,100);
    delay(200);
    tone(buzzerPin,587.33,100);
    delay(300);
    tone(buzzerPin,554.36,100);
    delay(400);
    tone(buzzerPin,1567.98,100);
    delay(100);
    tone(buzzerPin,1567.98,100);
    delay(100);
    noTone(buzzerPin);
  }
}
}