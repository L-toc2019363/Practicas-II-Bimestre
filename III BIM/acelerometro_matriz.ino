#include <SparkFun_ADXL345.h>
#include <SPI.h>
#include <Wire.h>
#include <LedControl.h>

#define entrada  10   //pin 12 conectado al pin de datos del max7219.
#define clock 8   //pin 11 conectado al pin de clock del max7219.
#define cs  9   //pin 10 conectado al pin de carga del max7219.

LedControl matrix = LedControl(entrada,clock,cs,1);
ADXL345 acelerometro = ADXL345();

byte number_0[8]= {        // array que contiene todos los elementos de las
  0b11111111,
  0b11111111,
  0b00000000,
  0b00011000,
  0b00011000,
  0b00000000,
  0b11111111,
  0b11111111
};
byte number_1[8]= {       // array que contiene todos los elementos de las
  0b11111111,
  0b11111111,
  0b00000000,
  0b00010000,
  0b00010000,
  0b00000000,
  0b11111111,
  0b11111111
};

byte number_2[8]= {       // array que contiene todos los elementos de las
  0b11111111,
  0b11111111,
  0b00000000,
  0b00100000,
  0b00100000,
  0b00000000,
  0b11111111,
  0b11111111
};

byte number_3[8]= {       // array que contiene todos los elementos de las
  0b11111111,
  0b11111111,
  0b00000000,
  0b01000000,
  0b01000000,
  0b00000000,
  0b11111111,
  0b11111111
};

byte number_4[8]= {     // array que contiene todos los elementos de las
  0b11111111,
  0b11111111,
  0b00000000,
  0b10000000,
  0b10000000,
  0b00000000,
  0b11111111,
  0b11111111
};

byte number_5[8]= {     // array que contiene todos los elementos de las
  0b11111111,
  0b11111111,
  0b00000000,
  0b00001000,
  0b00001000,
  0b00000000,
  0b11111111,
  0b11111111
};

byte number_6[8]= {       // array que contiene todos los elementos de las
  0b11111111,
  0b11111111,
  0b00000000,
  0b00000100,
  0b00000100,
  0b00000000,
  0b11111111,
  0b11111111
};
byte number_7[8]= {     // array que contiene todos los elementos de las
  0b11111111,
  0b11111111,
  0b00000000,
  0b00000010,
  0b00000010,
  0b00000000,
  0b11111111,
  0b11111111
};

byte number_8[8]= {       // array que contiene todos los elementos de las
  0b11111111,
  0b11111111,
  0b00000000,
  0b00000001,
  0b00000001,
  0b00000000,
  0b11111111,
  0b11111111
};



unsigned long delayy = 10;

void setup() {
  Serial.begin(9600);
  Serial.println("iniciar");
  Serial.println();
  acelerometro.powerOn();
  acelerometro.setRangeSetting(16);
  matrix.shutdown(0,false); //Activo el max7219 para poder mostrar los digitos.
  matrix.setIntensity(0,15);  //Brilo a la mitad 
  matrix.clearDisplay(0); 
}

void loop() {
matrix345();
}


void matrix345 (){
int x,y,z;
acelerometro.readAccel(&x,&y,&z);
Serial.print("X:");
Serial.print(x);
Serial.print("; ");
Serial.print("y:");
Serial.print(y);
Serial.print("z:");
Serial.print(z);
Serial.println("");
delay(50);
if(x==0 || x == 1){
  Serial.println("centrado");
  for(int i=0; i<8;i++)
      {
        matrix.setRow(0,i,number_0[i]);
      }  
} 
delay(delayy);
if(x>=-13 && x<=-2){
Serial.println("inclinado hacia la izquierda");
  for(int i=0; i<8;i++)
      {
        matrix.setRow(0,i,number_5[i]);
      }  
}
delay(delayy); 
  if(x>=-19&& x<=-14 ){
  Serial.println("mas inclininado a la izquierda");
  for(int i=0; i<8;i++)
      {
        matrix.setRow(0,i,number_6[i]);
      }  
} 
delay(delayy); 
if(x>=-29 && x<=-20){
  Serial.println("muy inclinado a la izquierda");
  for(int i=0; i<8;i++)
      {
        matrix.setRow(0,i,number_7[i]);
      }  
} 
delay(delayy);
 if(x>=-32 && x<=-30){
  Serial.println("totalmente inclinado a la izquierda");
  for(int i=0; i<8;i++)
      {
        matrix.setRow(0,i,number_8[i]);
      }  
} 
delay(delayy);
if(x>=3 && x<13){
  Serial.println("inclinado hacia la derecha");
  for(int i=0; i<8;i++)
      {
        matrix.setRow(0,i,number_1[i]);
      }  
}
delay(delayy); 
 if(x>=14 && x<=19){
  Serial.println("mas inclininado a la derecha");
  for(int i=0; i<8;i++)
      {
        matrix.setRow(0,i,number_2[i]);
      }  
}
delay(delayy);  
 if(x>=20 && x<=29){
  Serial.println("muy inclinado a la derecha");
  for(int i=0; i<8;i++)
      {
        matrix.setRow(0,i,number_3[i]);
      }  
} 
delay(delayy);
  if(x>=30 && x<=35){
  Serial.println("totalmente inclinado a la derecha");
  for(int i=0; i<8;i++)
      {
        matrix.setRow(0,i,number_4[i]);
      }  
}
delay(delayy);
}

