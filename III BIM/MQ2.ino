//librerias
#include <LedControl.h>
#include <Ticker.h>

//directivas
#define DIN   12   //pin 12 conectado al pin de datos del max7219.
#define CLOCK 11   //pin 11 conectado al pin de clock del max7219.
#define CS 10   //pin 10 conectado al pin de carga del max7219.

//Funcion
void isr_MQ2(void);
void MQ2MATRIZ();
void MQ2MATRIZ2();
//variables
volatile static bool estado_MQ2;

//constructores
Ticker isr_accion_MQ2(isr_MQ2, 10000);
LedControl matrix_unidades = LedControl(DIN,CLOCK,CS,1);

//variables BYTE
byte letter_F[8]= {        // array que contiene todos los elementos de las
 B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00111100,
B00111100};
byte letter_I[8]= {       // array que contiene todos los elementos de las
B00000000,
B00000000,
B00000000,
B00111100,
B01000010,
B01000010,
B00100100,
B00111100};

byte letter_R[8]= {       // array que contiene todos los elementos de las
B00000000,
B00000000,
B00111100,
B01000010,
B10000001,
B10000001,
B01000010,
B00111100};

byte letter_E[8]= {       // array que contiene todos los elementos de las
B00000110,
B00001010,
B00010010,
B00100010,
B01011101,
B01011101,
B01000010,
B00111100};

byte SYMBOL[8]= {     // array que contiene todos los elementos de las
B00000110,
B00001010,
B00010010,
B00100010,
B01111111,
B01111111,
B01111110,
B00111100
};

byte fuego[8]= {     // array que contiene todos los elementos de las
B00000110,
B00001110,
B00011110,
B00111110,
B01111111,
B01111111,
B01111110,
B00111100
};
byte hielo[8]= {     // array que contiene todos los elementos de las
 B10100101,
 B01100110,
 B11100111,
 B00011000,
 B00011000,
 B11100111,
 B01100110,
 B10100101
};
byte hielo2[8]= {     // array que contiene todos los elementos de las
B00000000,
B01000010,
B00100100,
B00011000,
B00011000,
B00100100,
B01000010,
B00000000
};

unsigned long update_delay = 850;
unsigned long update_delay2 = 50;

//Prototipos de funciones
int display_number(unsigned char number);





void setup() {
Serial.begin(9600);
pinMode(A0, INPUT);
isr_accion_MQ2.start();
estado_MQ2 = LOW;
matrix_unidades.shutdown(0,false); //Activo el max7219 para poder mostrar los digitos.
matrix_unidades.setIntensity(0,15);  //Brilo a la mitad
matrix_unidades.clearDisplay(0);  

}

void loop() {
   
isr_accion_MQ2.update();
}

int display_number(unsigned char number)
{

  switch (number)
  {
    case (0):
    {
      for(int i=0; i<8;i++)
      {
        matrix_unidades.setRow(0,i,letter_F[i]);
      }
      break;
    }
    
    case (1):
    {
      for(int i=0; i<8;i++)
      {
        matrix_unidades.setRow(0,i,letter_I[i]);
      }
      break;
    }

    
    case (2):
    {
      for(int i=0; i<8;i++)
      {
        matrix_unidades.setRow(0,i,letter_R[i]);
      }
      break;
    }
    
    
    case (3):
    {
      for(int i=0; i<8;i++)
      {
        matrix_unidades.setRow(0,i,letter_E[i]);
      }
      break;
    }
    
    case (4):
    {
      for(int i=0; i<8;i++)
      {
        matrix_unidades.setRow(0,i,SYMBOL[i]);
      }
      break;
    }
    
    case (5):
    {
      for(int i=0; i<8;i++)
      {
        matrix_unidades.setRow(0,i,fuego[i]);
      }
      break;
    }
        case (6):
    {
      for(int i=0; i<8;i++)
      {
        matrix_unidades.setRow(0,i,hielo[i]);
      }
      break;
    }
       case (7):
    {
      for(int i=0; i<8;i++)
      {
        matrix_unidades.setRow(0,i,hielo2[i]);
      }
      break;
    }
  }
}

void isr_MQ2(void)
{
  estado_MQ2 = analogRead(A0);
  int adc_mq = analogRead(A0);
  digitalWrite(A0, !estado_MQ2);
  Serial.println(adc_mq);
  
  if (adc_mq < 140){
    Serial.println("fuera de peligro");
  
  for(int i =0; i<8;i++){
  {
  matrix_unidades.setRow(0,i,hielo2[i]);
  matrix_unidades.setRow(0,i,hielo[i]);
  delay (update_delay2);
  }
}
}
  if (adc_mq > 141){
    Serial.println("peligro");
  
  for(int i =0; i<6;i++){
  {
    display_number(i);
    delay(update_delay);
  }
}
}
 
  }
