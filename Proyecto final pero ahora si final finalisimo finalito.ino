#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h> 
#include <Wire.h> 

int Sensor = A0;
const int pin = A1;  // Pin analógico donde está conectado el sensor ACS712
float sensibilidad = 185;        // Sensibilidad del sensor ACS712 (ajusta esto según tu sensor)
float voltage = 0;           // Voltaje leído del sensor
float corriente = 0;           // Corriente calculada

const int pinAnalogico = A2; // Pin analógico al que se conecta el circuito
const float resistenciaConocida = 1000.0; // Resistencia conocida de 1kΩ
const int numLecturas = 10; // Número de lecturas promediadas
float sumaDeResistencias = 0.0;

#define direccion_lcd 0x27
#define filas 2
#define columnas 16
LiquidCrystal_I2C lcd_lenin(direccion_lcd, columnas, filas); 
SoftwareSerial bluet(10, 11);

void setup() {
  Serial.begin(9600);
  Serial.println("multimetro");
  bluet.begin(9600);
  lcd_lenin.init();
  lcd_lenin.backlight();
}

char receptor;
bool medicionvoltaje = false; // Variable para controlar la medición de voltaje
bool ohmimetro= false;//variables para controla el ohmimetro
bool medicioncorriente= false; // variables para controlar el amperaje
void loop() {
  if (bluet.available()) {
    receptor = bluet.read();
    Serial.println(receptor);

    switch (receptor) {
      case '1':
        Serial.println("medidor de  voltaje");
        medicionvoltaje = true; // Habilita la medición de voltaje
        ohmimetro= false;
        medicioncorriente= false;
        break;
        
      case'2':
      Serial.println("medidor de resistencia");
      ohmimetro= true;
      medicionvoltaje = false;
      medicioncorriente= false;
      break;

      case'3':
      Serial.println("medidor de corriente");
      medicioncorriente= true;
      medicionvoltaje = false;
      ohmimetro= false;
      break;
      
      case '4':
      Serial.println("off");
      lcd_lenin.clear();
      lcd_lenin.setCursor(0, 0);
      bluet.print(';');
      medicionvoltaje = false; // Deshabilita la medición de voltaje
      ohmimetro= false;
      medicioncorriente= false;
      break;
    }
  }

  if (medicionvoltaje) {
    float voltaje = (float)25 * analogRead(A0) / 1023;
    Serial.print("Voltaje medido = ");
    lcd_lenin.clear();
    lcd_lenin.setCursor(0, 0);
    lcd_lenin.print("Voltaje medido");
    Serial.println(voltaje);
    lcd_lenin.setCursor(0, 1);
    lcd_lenin.print("V:");
    bluet.print(voltaje);
    bluet.print(' ');
    bluet.print(' ');
    delay(750);
    ohmimetro= false;
    medicioncorriente= false; 
  }
 if(ohmimetro) {
  sumaDeResistencias = 0.0;

  for (int i = 0; i < numLecturas; i++) {
    int estado = analogRead(pinAnalogico);
    float voltaje = (5.0 / 1023.0) * estado;
    float resistenciaDesconocida = (voltaje * resistenciaConocida) / (5.0 - voltaje);
    sumaDeResistencias += resistenciaDesconocida;
    delay(10); // Pequeña pausa entre lecturas para evitar ruido
  }
  float resistenciaPromedio = sumaDeResistencias / numLecturas;
  Serial.print("Resistencia desconocida: ");
  Serial.println(resistenciaPromedio);
  bluet.print(resistenciaPromedio,2);
  bluet.print(' ');
  delay(500);

  

  delay(1000); // Puedes ajustar el tiempo de muestreo según tus necesidades
  ;
 }
  if(medicioncorriente) {
 int estado = analogRead(pin);  // Lee el valor analógico del sensor
  voltage = (estado / 1024.0) * 5000;    // Convierte el valor en milivoltios
  corriente = (voltage - 2500) / sensibilidad;      // Calcula la corriente en amperio  
  Serial.print("Corriente: ");
  lcd_lenin.clear();
  lcd_lenin.setCursor(0,0);
  lcd_lenin.print("corriente medida");
  Serial.print(corriente, 2);  // Imprime la corriente con 2 decimales
  lcd_lenin.setCursor(2,1);
  bluet.print(corriente, 2);
  bluet.print(' ');
  Serial.println(" A");
  lcd_lenin.setCursor(0,1);
  lcd_lenin.print("A:");
  delay(500);  
  
 }
}
