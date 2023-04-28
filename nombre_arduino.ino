#include <LiquidCrystal.h>
int Trigger = 8;
int Echo = 9;
int ZumbadorPin = 10;
int personas;
int aH=880; 
#define RS  6
#define Enable 7
#define D4 2
#define D5 3
#define D6 4
#define D7 5
LiquidCrystal LCD_LENIN(RS, Enable, D4, D5, D6, D7); //Constructor que me permite usar la LCD
byte pata[] = {
  B00000,
  B10010,
  B10010,
  B10010,
  B01010,
  B00111,
  B11111,
  B11111
};

byte pataa[] = {
  B11111,
  B11111,
  B00111,
  B01010,
  B10010,
  B10010,
  B10010,
  B00000
};
byte pataaa[] = {
  B00000,
  B01000,
  B01000,
  B10000,
  B10000,
  B11000,
  B11110,
  B11000
};
byte pataaaa[] = {
  B11000,
  B11110,
  B11000,
  B10000,
  B01000,
  B01000,
  B00000,
  B00000
};
void setup() {
  Serial.begin(9600);
  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);
  pinMode(ZumbadorPin, OUTPUT);
  digitalWrite(ZumbadorPin, LOW);
  LCD_LENIN.begin(16,2);
  LCD_LENIN.createChar(1,pata);
  LCD_LENIN.createChar(2,pataa);
  LCD_LENIN.createChar(3,pataaa);
  LCD_LENIN.createChar(4,pataaaa);
  cero(); 
}

void loop() {
  int distancia = P();
  Serial.println(distancia);
if (distancia >= 6 && distancia <= 12) {
    personas++;
if( personas >= 17 ){
LCD_LENIN.clear();
LCD_LENIN.setCursor(0,0);
LCD_LENIN.write(1);
LCD_LENIN.setCursor(0,1);
LCD_LENIN.write(2);
LCD_LENIN.setCursor(1,0);
LCD_LENIN.write(3);
LCD_LENIN.setCursor(1,1);
LCD_LENIN.write(4);
delay(250);
tone(ZumbadorPin, aH, 500);
    delay(500+50);

LCD_LENIN.clear();
LCD_LENIN.setCursor(2,0);
LCD_LENIN.write(1);
LCD_LENIN.setCursor(2,1);
LCD_LENIN.write(2);
LCD_LENIN.setCursor(3,0);
LCD_LENIN.write(3);
LCD_LENIN.setCursor(3,1);
LCD_LENIN.write(4);
delay(250);
tone(ZumbadorPin, aH, 500);
    delay(500+50);
LCD_LENIN.clear();
LCD_LENIN.setCursor(4,0);
LCD_LENIN.write(1);
LCD_LENIN.setCursor(4,1);
LCD_LENIN.write(2);
LCD_LENIN.setCursor(5,0);
LCD_LENIN.write(3);
LCD_LENIN.setCursor(5,1);
LCD_LENIN.write(4);
delay(250);
tone(ZumbadorPin, aH, 500);
    delay(500+50);
LCD_LENIN.clear();
LCD_LENIN.setCursor(6,0);
LCD_LENIN.write(1);
LCD_LENIN.setCursor(6,1);
LCD_LENIN.write(2);
LCD_LENIN.setCursor(7,0);
LCD_LENIN.write(3);
LCD_LENIN.setCursor(7,1);
LCD_LENIN.write(4);
delay(250);
tone(ZumbadorPin, aH, 500);
    delay(500+50);
LCD_LENIN.clear();
LCD_LENIN.setCursor(8,0);
LCD_LENIN.write(1);
LCD_LENIN.setCursor(8,1);
LCD_LENIN.write(2);
LCD_LENIN.setCursor(9,0);
LCD_LENIN.write(3);
LCD_LENIN.setCursor(9,1);
LCD_LENIN.write(4);
delay(250);
tone(ZumbadorPin, aH, 500);
    delay(500+50);
LCD_LENIN.clear();
LCD_LENIN.setCursor(10,0);
LCD_LENIN.write(1);
LCD_LENIN.setCursor(10,1);
LCD_LENIN.write(2);
LCD_LENIN.setCursor(11,0);
LCD_LENIN.write(3);
LCD_LENIN.setCursor(11,1);
LCD_LENIN.write(4);
delay(250);
tone(ZumbadorPin,aH, 500);
    delay(500+50);
LCD_LENIN.clear();
LCD_LENIN.setCursor(12,0);
LCD_LENIN.write(1);
LCD_LENIN.setCursor(12,1);
LCD_LENIN.write(2);
LCD_LENIN.setCursor(13,0);
LCD_LENIN.write(3);
LCD_LENIN.setCursor(13,1);
LCD_LENIN.write(4);
delay(250);
tone(ZumbadorPin, aH, 500);
    delay(500+50);
LCD_LENIN.clear();
LCD_LENIN.setCursor(14,0);
LCD_LENIN.write(1);
LCD_LENIN.setCursor(14,1);
LCD_LENIN.write(2);
LCD_LENIN.setCursor(15,0);
LCD_LENIN.write(3);
LCD_LENIN.setCursor(15,1);
LCD_LENIN.write(4);
tone(ZumbadorPin, aH, 500);
    delay(500+50);

} 
switch (personas) {
case 1:
LCD_uno();
break;
case 2:
LCD_dos();
break;
case 3:
LCD_tres();
break;
case 4:
LCD_cuatro();
break;
case 5:
LCD_cinco();
break;
case 6:
LCD_seis();
break;
case 7:
LCD_siete();
break;
case 8:
LCD_ocho();
break;
case 9:
LCD_nueve();
break;
case 10:
LCD_diez();
break;
case 11:
LCD_once();
break;
case 12:
LCD_doce();
break;
case 13:
LCD_trece();
break;
case 14:
LCD_catorce();
break;
case 15:
LCD_quince();
break;
case 16:
LCD_diezyseis();
break; 

}
}
delay(700);
}

int P() { 
  digitalWrite(Trigger, HIGH);
  delay(1);
  digitalWrite(Trigger, LOW);
  int Tiempo = pulseIn(Echo, HIGH);
  int Distancia = Tiempo / 59;
  return Distancia;
}


void cero() {
 LCD_LENIN.begin(16,2); 
 LCD_LENIN.print("personas adentro");
 LCD_LENIN.setCursor(0,1);
 LCD_LENIN.print("0");
}
void  LCD_uno() {
 LCD_LENIN.begin(16,2); 
 LCD_LENIN.print("personas adentro");
 LCD_LENIN.setCursor(0,1);
 LCD_LENIN.print("1");
}
void  LCD_dos() {
 LCD_LENIN.begin(16,2); 
 LCD_LENIN.print("personas adentro ");
 LCD_LENIN.setCursor(0,1);
 LCD_LENIN.print("2");
}
void  LCD_tres() {
 LCD_LENIN.begin(16,2); 
 LCD_LENIN.print("personas adentro ");
 LCD_LENIN.setCursor(0,1);
  LCD_LENIN.print("3");
}
void  LCD_cuatro() {
 LCD_LENIN.begin(16,2); 
 LCD_LENIN.print("personas adentro ");
 LCD_LENIN.setCursor(0,1);
  LCD_LENIN.print("4");
}
void  LCD_cinco() {
 LCD_LENIN.begin(16,2); 
 LCD_LENIN.print("personas adentro ");
 LCD_LENIN.setCursor(0,1);
  LCD_LENIN.print("5");
}
void  LCD_seis() {
 LCD_LENIN.begin(16,2); 
 LCD_LENIN.print("personas adentro ");
 LCD_LENIN.setCursor(0,1);
  LCD_LENIN.print("6");
}
void  LCD_siete() {
 LCD_LENIN.begin(16,2); 
 LCD_LENIN.print("personas adentro ");
 LCD_LENIN.setCursor(0,1);
  LCD_LENIN.print("7");
}
void  LCD_ocho() {
 LCD_LENIN.begin(16,2); 
 LCD_LENIN.print("personas adentro ");
 LCD_LENIN.setCursor(0,1);
  LCD_LENIN.print("8");
}
void LCD_nueve () {
 LCD_LENIN.begin(16,2); 
 LCD_LENIN.print("personas adentro ");
 LCD_LENIN.setCursor(0,1);
  LCD_LENIN.print("9");
}
void LCD_diez() {
 LCD_LENIN.begin(16,2); 
 LCD_LENIN.print("personas adentro ");
 LCD_LENIN.setCursor(0,1);
  LCD_LENIN.print("10");
}
void LCD_once() {
 LCD_LENIN.begin(16,2); 
 LCD_LENIN.print("personas adentro ");
 LCD_LENIN.setCursor(0,1);
  LCD_LENIN.print("11");
}
void  LCD_doce() {
 LCD_LENIN.begin(16,2); 
 LCD_LENIN.print("personas adentro ");
 LCD_LENIN.setCursor(0,1);
  LCD_LENIN.print("12");
}
void LCD_trece() {
 LCD_LENIN.begin(16,2); 
 LCD_LENIN.print("personas adentro ");
 LCD_LENIN.setCursor(0,1);
  LCD_LENIN.print("13");
}
void LCD_catorce() {
 LCD_LENIN.begin(16,2); 
 LCD_LENIN.print("personas adentro ");
 LCD_LENIN.setCursor(0,1);
  LCD_LENIN.print("14");
}
void LCD_quince() {
 LCD_LENIN.begin(16,2); 
 LCD_LENIN.print("personas adentro ");
 LCD_LENIN.setCursor(0,1);
  LCD_LENIN.print("15");
}
void LCD_diezyseis() {
 LCD_LENIN.begin(16,2); 
 LCD_LENIN.print("personas adentro ");
 LCD_LENIN.setCursor(0,1);
 LCD_LENIN.print("16");
}
