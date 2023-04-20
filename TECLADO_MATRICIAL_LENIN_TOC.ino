/*
   Fundacion Kinal
   Centro educativo tecnico laboral Kinal
   Quinto perito
   Quinto electronica
   Codigo Tecnico: EB5AM
   Curso: Taller de electronica digital y reparacion de computadoras I
   Proyecto: TECLADO MATRICIAL
   De: LENIN TOC
*/
#include <Keypad.h>
#define cols 4
#define rows 4
#define A 11
#define B 12
#define C 13
#define D 14
#define E 15
#define FF 16
#define G 17
#define H 18
char holdkey;
char keys[rows][cols] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};


byte pines_filas[rows] = {2,3,4,5};
byte pines_columnas[cols] = {6,7,8,9};

Keypad teclado_magico = Keypad( makeKeymap(keys), pines_filas, pines_columnas, rows,cols);

void setup() {
pinMode(A, OUTPUT);
pinMode(B, OUTPUT);
pinMode(C, OUTPUT);
pinMode(D, OUTPUT);
pinMode(E, OUTPUT);
pinMode(FF, OUTPUT);
pinMode(G, OUTPUT);
pinMode(H, OUTPUT);
}

void loop() 
{
 char tecla = teclado_magico.getKey();
  switch(tecla)
  {
    case '0':  
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(FF, HIGH);
    digitalWrite(G, LOW);
    delay(1500);
    break;
      
    case '1':
    digitalWrite(A, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(FF, LOW);
    digitalWrite(G, LOW);
    delay(1500);
    break;
    
    case '2':
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, LOW);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(FF, LOW);
    digitalWrite(G, HIGH);
    delay(1500);
    break;
      
    case '3':      
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, LOW);
    digitalWrite(FF, LOW);
    digitalWrite(G, HIGH);
    delay(1500);
    break;
  
    case '4':
    digitalWrite(A, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(FF, HIGH);
    digitalWrite(G, HIGH);
    delay(1500);
    break;
     
    case '5':
    digitalWrite(A, HIGH);
    digitalWrite(B, LOW);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, LOW);
    digitalWrite(FF, HIGH);
    digitalWrite(G, HIGH);
    delay(1500);
    break;
     
    case '6':
    digitalWrite(A, HIGH);
    digitalWrite(B, LOW);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(FF, HIGH);
    digitalWrite(G, HIGH);
    delay(1500);
    break;
    
    case '7':
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(FF, LOW);
    digitalWrite(G, LOW);
    delay(1500);
    break;
    
    case '8': 
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(FF, HIGH);
    digitalWrite(G, HIGH);
    delay(1500);
    break;
    
    case '9':
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(FF, HIGH);
    digitalWrite(G, HIGH);
    delay(1500);
    break;
     
    case 'A':
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, LOW);
    digitalWrite(E, HIGH);
    digitalWrite(FF, HIGH);
    digitalWrite(G, HIGH);
    delay(1500);
    break;
     
    case 'B':
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(FF, HIGH);
    digitalWrite(G, HIGH);
    delay(1500);
    break;
    
    case 'C':
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(FF, LOW);
    digitalWrite(G, HIGH);
    delay(1500);
    break;
     
    case 'D':
    digitalWrite(A, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(FF, LOW);
    digitalWrite(G, HIGH);
    delay(1500);
    break;
     
    case '*':  
    digitalWrite(A, HIGH);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(FF, HIGH);
    digitalWrite(G, HIGH);
    delay(1500);
    break;
   
    case '#':
    digitalWrite(A, HIGH);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, HIGH);
    digitalWrite(FF, HIGH);
    digitalWrite(G, HIGH);
    delay(1500);
    break;

    case NO_KEY:
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(FF, HIGH);
    digitalWrite(G, LOW);    
    digitalWrite(H, HIGH);
    break;
}
}
