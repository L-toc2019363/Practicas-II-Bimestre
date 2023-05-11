/* 
* Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Perito en electonica
 * Quinto perito
 * EB5AM / EB5AV
 * Taller de electronica digital y reparacion de computadoras
 * Nombre: Lenin Toc
 * Fecha: 04/05/2023
 * practica 7
 */


//Librerias 
#include <Wire.h>    //Liberias para usar el protocolo i2c
#include <LiquidCrystal_I2C.h>  //Libreria que controla la LCD por medio de I2C
#include <OneWire.h>                
#include <DallasTemperature.h>
#include <Servo.h>
#include <Adafruit_NeoPixel.h>
//Directivas de preprocesador
#define direccion_lcd 0x27
#define filas 2
#define columnas 16
#define LED_RGB_VERDE 5
#define LED_RGB_AZUL 4
#define LED_RGB_ROJO 3
#define servomove 6
#define PUSH_BUTTON1 7
#define PUSH_BUTTON2 8
#define PUSH_BUTTON3 9
#define foco1 10
#define foco2 11
#define Cantidad_Leds 24
#define pin_Led 12
#define pin_radar 13
int ZumbadorPin = 14;
int estado=0;
void ifs();
void temperatuta ();
void setColor(int color);
enum colores
{
rojo, 
};
int color;
Servo servo_lenin;  
LiquidCrystal_I2C lcd(direccion_lcd, columnas, filas);
OneWire ourWire(2);                //Se establece el pin 2  como bus OneWire
DallasTemperature sensors(&ourWire); //Se declara una variable u objeto para nuestro sensor
Adafruit_NeoPixel anillo(Cantidad_Leds,pin_Led, NEO_GRB + NEO_KHZ800);
byte CA1[9] = {
  B00000,
  B11011,
  B11011,
  B11011,
  B00000,
  B11111,
  B10001,
  B01110
};
byte CA2[9] = {
  B00000,
  B11011,
  B11011,
  B11011,
  B00000,
  B01110,
  B10001,
  B10001
};
byte MED1[9] = {
  B00000,
  B11000,
  B11101,
  B01111,
  B00111,
  B01111,
  B00000,
  B00000
};
byte MED2[9] = {
  B00000,
  B11011,
  B11011,
  B11011,
  B00000,
  B11111,
  B00000,
  B00000
};
byte FRIO1[9] = {
  B01110,
  B11111,
  B11111,
  B00100,
  B00100,
  B00100,
  B10100,
  B11100
};
byte FRIO2[9] = {
  B01110,
  B11111,
  B00100,
  B10101,
  B00100,
  B10101,
  B00100,
  B11101
};
byte OFF[9] = {
  B00000,
  B01110,
  B11111,
  B10001,
  B10001,
  B10001,
  B10001,
  B11111
};
byte ON[9] = {
  B00000,
  B01110,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};
byte CERRADO[9] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

void setup() {
  sensors.begin();
  pinMode(LED_RGB_ROJO,OUTPUT);
  pinMode(LED_RGB_VERDE,OUTPUT);
  pinMode(LED_RGB_AZUL,OUTPUT);
  pinMode(PUSH_BUTTON1,INPUT);
  pinMode(PUSH_BUTTON2,INPUT);
  pinMode(PUSH_BUTTON3,INPUT);
  pinMode(foco1,OUTPUT);
  pinMode(foco2,OUTPUT);
  pinMode(servomove,OUTPUT);
  pinMode(ZumbadorPin, OUTPUT);
  anillo.begin(); 
  pinMode(pin_radar, INPUT);
  float temp =sensors.getTempCByIndex(0);
  servo_lenin.attach(servomove);
  lcd.init();
  lcd.backlight();
  lcd.createChar (0,CA1);
  lcd.createChar (1,CA2);
  lcd.createChar (2,MED1);
  lcd.createChar (3,MED2);
  lcd.createChar (4,FRIO1);
  lcd.createChar (5,FRIO2);
  lcd.createChar (6,OFF);
  lcd.createChar (7,ON);
  lcd.createChar (8,CERRADO);

}

void loop() {
ifs();
setColor(rojo);
ifs();
setColor(rojo);
ifs();
setColor(rojo);
ifs();

}




void ifs(){
int temp= sensors.getTempCByIndex(0);

 if(digitalRead(7) && estado==0){       
    lcd.setCursor(0,0);
    lcd.print("ABIERTO");
    delay(100);
    servo_lenin.write(90);        
    delay(100); 
    estado=1;                       
 }
 
  if(digitalRead(7) && estado==1){      
    
    lcd.setCursor(8,0);
    lcd.write(byte (8));    
    lcd.setCursor(0,0);
    lcd.print("CERRADO");
    delay(5);
    servo_lenin.write(0);            
    estado=0;                         
  }
   if(digitalRead(8) && estado==0){  
    lcd.setCursor(10,0);
    lcd.write(byte (6));
    digitalWrite(foco1,LOW); 
    estado=1;  
    delay(500);                      
  }
    if(digitalRead(8) && estado==1){  
    digitalWrite(foco1,HIGH);
    lcd.setCursor(10,0);
    lcd.write(byte (7)); 
    estado=0; 
    delay(500);                        
  }
     if(digitalRead(9) && estado==0){  
    digitalWrite(foco2,LOW); 
    lcd.setCursor(12,0);
    lcd.write(byte (6));
    estado=1;
    delay(500);                        
  }
  
    if(digitalRead(9) && estado==1){ 
    digitalWrite(foco2,HIGH); 
    lcd.setCursor(12,0);
    lcd.write(byte (7)); 
    estado=0;  
    delay(500);                       
  }
  

  
if(temp >25 && temp <40 ){
  digitalWrite(LED_RGB_ROJO, LOW);
  digitalWrite(LED_RGB_AZUL, HIGH);
  digitalWrite(LED_RGB_VERDE, HIGH);
  lcd.setCursor(0,1);
  lcd.write (byte (0));
  delay(100);
  lcd.setCursor(0,1);
  lcd.write (byte (1));
  delay(100);
} 
if(temp >21 && temp <24){
  digitalWrite(LED_RGB_ROJO, HIGH);
  digitalWrite(LED_RGB_AZUL, HIGH);
  digitalWrite(LED_RGB_VERDE, LOW);
  lcd.setCursor(0,1);
  lcd.write (byte (2));
  delay(100);
  lcd.setCursor(0,1);
  lcd.write (byte (3));
  delay(100);
}
if(temp >15 && temp<20){
  digitalWrite(LED_RGB_ROJO, LOW);
  digitalWrite(LED_RGB_AZUL, LOW);
  digitalWrite(LED_RGB_VERDE, HIGH); 
  lcd.setCursor(0,1);
  lcd.write (byte (4));
  delay(100);
  lcd.setCursor(0,1);
  lcd.write (byte (5));
  delay(100);
}
} 
void setColor(int color)

{
  int radar = digitalRead(pin_radar);
  switch(color)
  {
    case(rojo):
    {   
      if(radar == HIGH){
        for(int i =0; i<=7; i++)
        {
        anillo.setPixelColor(i,anillo.Color(255,105,180));
        anillo.show(); 
        delay(50);}
        tone(ZumbadorPin,  1000 );
        delay(500);
        noTone(ZumbadorPin);

        for( int i = 7; i >= 0; i--){
        anillo.setPixelColor(i,anillo.Color(0,0,0));
        anillo.show();  //muestro el color en el led
        delay(100);
        } 
        delay(500);                    
        }
}
int radar2 = digitalRead(pin_radar);
if (radar2 == LOW){

for(int i =0; i<=7; i++)
        {
        anillo.setPixelColor(i,anillo.Color(0,0,0));
        anillo.show();  //muestro el color en el led
        delay(100);}
        for( int i = 7; i >= 0; i--){
        anillo.setPixelColor(i,anillo.Color(0,0,0));
        anillo.show(); 
        delay(100);
        }              
        }
      break;
    }
}
