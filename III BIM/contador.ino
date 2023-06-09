/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombre: Lenin toc
 * Carnet: 2019363
 * Proyecto: Uso de interrupciones externas ejemplo 3 - Bimestre III
*/


//Directivas de preprocesador
#define btn_rising  2     //pin 2 utilizado para una interrupción externa por rising
#define btn_falling 3     //pih 3 utilizado para una interrupción externa por falling
#define A 4
#define B 5
#define C 6
#define D 7
#define E 8
#define F1 9
#define G 10
#define AA 11
#define BB 12
#define CC 13
#define DD 14
#define EE 15
#define FF 16
#define GG 17
void funcion_ISR_falling(void);
void funcion_ISR_rising(void);
void displaylenin(void);
//Variables
volatile static bool f_print=false; // variable para mostrar en texto en el loop
volatile static char i=0;  // variable que cuenta de 0 - 255;


void setup() {
  
  Serial.begin(19200); //Inicio la comunicación serial
  pinMode(btn_rising, INPUT);  //pin 2 como entrada
  pinMode(btn_falling, INPUT); //pin 3 como entrada
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);
  pinMode(E,OUTPUT);
  pinMode(F1,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(AA,OUTPUT);
  pinMode(BB,OUTPUT);
  pinMode(CC,OUTPUT);
  pinMode(DD,OUTPUT);
  pinMode(EE,OUTPUT);
  pinMode(FF,OUTPUT);
  pinMode(GG,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(btn_rising),funcion_ISR_rising,RISING);   //Anclar la interrupción del pin 2 a una funcion de ISR, disparada por el flanco ascendente
  attachInterrupt(digitalPinToInterrupt(btn_falling),funcion_ISR_falling,FALLING); //Anclar la interrupción del pin 3 a una funcion de ISR, disparada por el flanco descendente
}

void loop() {  
  displaylenin();
  while(i>50){
  i=0;
}
  while(i<0){
  i=50;
  }  
}
//Funciones de ISR
void funcion_ISR_rising(void)
{  
 
   f_print = true;
   i++; 


}
void funcion_ISR_falling(void)
{
  
  f_print = true;
  i--;

}
void displaylenin(void){
    
if(f_print)
{
  f_print = false; //limpio la variable
  Serial.println(i); //imprimo el valor de I
}
  if(i==0){
 digitalWrite(A,LOW);
 digitalWrite(B,LOW);
 digitalWrite(C,LOW);
 digitalWrite(D,LOW);
 digitalWrite(E,LOW);
 digitalWrite(F1,LOW);
 digitalWrite(G,HIGH);
 digitalWrite(AA,HIGH);
 digitalWrite(BB,HIGH);
 digitalWrite(CC,HIGH);
 digitalWrite(DD,HIGH);
 digitalWrite(EE,HIGH);
 digitalWrite(FF,HIGH);
 digitalWrite(GG,HIGH);
  }
   if(i==1){
 digitalWrite(A,HIGH);
 digitalWrite(B,LOW);
 digitalWrite(C,LOW);
 digitalWrite(D,HIGH);
 digitalWrite(E,HIGH);
 digitalWrite(F1,HIGH);
 digitalWrite(G,HIGH);
 digitalWrite(AA,HIGH);
 digitalWrite(BB,HIGH);
 digitalWrite(CC,HIGH);
 digitalWrite(DD,HIGH);
 digitalWrite(EE,HIGH);
 digitalWrite(FF,HIGH);
 digitalWrite(GG,HIGH);
  }
     if(i==2){
 digitalWrite(A,LOW);
 digitalWrite(B,LOW);
 digitalWrite(C,HIGH);
 digitalWrite(D,LOW);
 digitalWrite(E,LOW);
 digitalWrite(F1,HIGH);
 digitalWrite(G,LOW);
 digitalWrite(AA,HIGH);
 digitalWrite(BB,HIGH);
 digitalWrite(CC,HIGH);
 digitalWrite(DD,HIGH);
 digitalWrite(EE,HIGH);
 digitalWrite(FF,HIGH);
 digitalWrite(GG,HIGH);
  }
     if(i==3){
 digitalWrite(A,LOW);
 digitalWrite(B,LOW);
 digitalWrite(C,LOW);
 digitalWrite(D,LOW);
 digitalWrite(E,HIGH);
 digitalWrite(F1,HIGH);
 digitalWrite(G,LOW);
 digitalWrite(AA,HIGH);
 digitalWrite(BB,HIGH);
 digitalWrite(CC,HIGH);
 digitalWrite(DD,HIGH);
 digitalWrite(EE,HIGH);
 digitalWrite(FF,HIGH);
 digitalWrite(GG,HIGH);
  }
     if(i==4){
 digitalWrite(A,HIGH);
 digitalWrite(B,LOW);
 digitalWrite(C,LOW);
 digitalWrite(D,HIGH);
 digitalWrite(E,HIGH);
 digitalWrite(F1,LOW);
 digitalWrite(G,LOW);
 digitalWrite(AA,HIGH);
 digitalWrite(BB,HIGH);
 digitalWrite(CC,HIGH);
 digitalWrite(DD,HIGH);
 digitalWrite(EE,HIGH);
 digitalWrite(FF,HIGH);
 digitalWrite(GG,HIGH);
  }
     if(i==5){
 digitalWrite(A,LOW);
 digitalWrite(B,HIGH);
 digitalWrite(C,LOW);
 digitalWrite(D,LOW);
 digitalWrite(E,HIGH);
 digitalWrite(F1,LOW);
 digitalWrite(G,LOW);
 digitalWrite(AA,HIGH);
 digitalWrite(BB,HIGH);
 digitalWrite(CC,HIGH);
 digitalWrite(DD,HIGH);
 digitalWrite(EE,HIGH);
 digitalWrite(FF,HIGH);
 digitalWrite(GG,HIGH);
  }
     if(i==6){
 digitalWrite(A,LOW);
 digitalWrite(B,HIGH);
 digitalWrite(C,LOW);
 digitalWrite(D,LOW);
 digitalWrite(E,LOW);
 digitalWrite(F1,LOW);
 digitalWrite(G,LOW);
 digitalWrite(AA,HIGH);
 digitalWrite(BB,HIGH);
 digitalWrite(CC,HIGH);
 digitalWrite(DD,HIGH);
 digitalWrite(EE,HIGH);
 digitalWrite(FF,HIGH);
 digitalWrite(GG,HIGH);
  }
     if(i==7){
 digitalWrite(A,LOW);
 digitalWrite(B,LOW);
 digitalWrite(C,LOW);
 digitalWrite(D,HIGH);
 digitalWrite(E,HIGH);
 digitalWrite(F1,HIGH);
 digitalWrite(G,HIGH);
 digitalWrite(AA,HIGH);
 digitalWrite(BB,HIGH);
 digitalWrite(CC,HIGH);
 digitalWrite(DD,HIGH);
 digitalWrite(EE,HIGH);
 digitalWrite(FF,HIGH);
 digitalWrite(GG,HIGH);
  }
     if(i==8){
 digitalWrite(A,LOW);
 digitalWrite(B,LOW);
 digitalWrite(C,LOW);
 digitalWrite(D,LOW);
 digitalWrite(E,LOW);
 digitalWrite(F1,LOW);
 digitalWrite(G,LOW);
 digitalWrite(AA,HIGH);
 digitalWrite(BB,HIGH);
 digitalWrite(CC,HIGH);
 digitalWrite(DD,HIGH);
 digitalWrite(EE,HIGH);
 digitalWrite(FF,HIGH);
 digitalWrite(GG,HIGH);
  }
     if(i==9){
 digitalWrite(A,LOW);
 digitalWrite(B,LOW);
 digitalWrite(C,LOW);
 digitalWrite(D,LOW);
 digitalWrite(E,HIGH);
 digitalWrite(F1,LOW);
 digitalWrite(G,LOW);
 digitalWrite(AA,HIGH);
 digitalWrite(BB,HIGH);
 digitalWrite(CC,HIGH);
 digitalWrite(DD,HIGH);
 digitalWrite(EE,HIGH);
 digitalWrite(FF,HIGH);
 digitalWrite(GG,HIGH);
  }
       if(i==10){
 digitalWrite(A,LOW);
 digitalWrite(B,LOW);
 digitalWrite(C,LOW);
 digitalWrite(D,LOW);
 digitalWrite(E,LOW);
 digitalWrite(F1,LOW);
 digitalWrite(G,HIGH);
 digitalWrite(AA,HIGH);
 digitalWrite(BB,LOW);
 digitalWrite(CC,LOW);
 digitalWrite(DD,HIGH);
 digitalWrite(EE,HIGH);
 digitalWrite(FF,HIGH);
 digitalWrite(GG,HIGH);         
  }
  if(i==11){
 digitalWrite(A,HIGH);
 digitalWrite(B,LOW);
 digitalWrite(C,LOW);
 digitalWrite(D,HIGH);
 digitalWrite(E,HIGH);
 digitalWrite(F1,HIGH);
 digitalWrite(G,HIGH);
 digitalWrite(AA,HIGH);
 digitalWrite(BB,LOW);
 digitalWrite(CC,LOW);
 digitalWrite(DD,HIGH);
 digitalWrite(EE,HIGH);
 digitalWrite(FF,HIGH);
 digitalWrite(GG,HIGH);         
  }
  if(i==12){
 digitalWrite(AA,HIGH);
 digitalWrite(BB,LOW);
 digitalWrite(CC,LOW);
 digitalWrite(DD,HIGH);
 digitalWrite(EE,HIGH);
 digitalWrite(FF,HIGH);
 digitalWrite(GG,HIGH);
 digitalWrite(A,LOW);
 digitalWrite(B,LOW);
 digitalWrite(C,HIGH);
 digitalWrite(D,LOW);
 digitalWrite(E,LOW);
 digitalWrite(F1,HIGH);
 digitalWrite(G,LOW);

}
  if(i==12){
 digitalWrite(AA,HIGH);
 digitalWrite(BB,LOW);
 digitalWrite(CC,LOW);
 digitalWrite(DD,HIGH);
 digitalWrite(EE,HIGH);
 digitalWrite(FF,HIGH);
 digitalWrite(GG,HIGH);
 digitalWrite(A,LOW);
 digitalWrite(B,LOW);
 digitalWrite(C,HIGH);
 digitalWrite(D,LOW);
 digitalWrite(E,LOW);
 digitalWrite(F1,HIGH);
 digitalWrite(G,LOW);
  }
  if(i==13){
 digitalWrite(AA,HIGH);
 digitalWrite(BB,LOW);
 digitalWrite(CC,LOW);
 digitalWrite(DD,HIGH);
 digitalWrite(EE,HIGH);
 digitalWrite(FF,HIGH);
 digitalWrite(GG,HIGH);
 digitalWrite(A,LOW);
 digitalWrite(B,LOW);
 digitalWrite(C,LOW);
 digitalWrite(D,LOW);
 digitalWrite(E,HIGH);
 digitalWrite(F1,HIGH);
 digitalWrite(G,LOW);
  }
  if(i==14){
 digitalWrite(AA,HIGH);
 digitalWrite(BB,LOW);
 digitalWrite(CC,LOW);
 digitalWrite(DD,HIGH);
 digitalWrite(EE,HIGH);
 digitalWrite(FF,HIGH);
 digitalWrite(GG,HIGH);
 digitalWrite(A,HIGH);
 digitalWrite(B,LOW);
 digitalWrite(C,LOW);
 digitalWrite(D,HIGH);
 digitalWrite(E,HIGH);
 digitalWrite(F1,LOW);
 digitalWrite(G,LOW);  
  }
  if(i==15){
 digitalWrite(AA,HIGH);
 digitalWrite(BB,LOW);
 digitalWrite(CC,LOW);
 digitalWrite(DD,HIGH);
 digitalWrite(EE,HIGH);
 digitalWrite(FF,HIGH);
 digitalWrite(GG,HIGH);
  digitalWrite(A,LOW);
 digitalWrite(B,HIGH);
 digitalWrite(C,LOW);
 digitalWrite(D,LOW);
 digitalWrite(E,HIGH);
 digitalWrite(F1,LOW);
 digitalWrite(G,LOW);  
  }
  if(i==16){
 digitalWrite(AA,HIGH);
 digitalWrite(BB,LOW);
 digitalWrite(CC,LOW);
 digitalWrite(DD,HIGH);
 digitalWrite(EE,HIGH);
 digitalWrite(FF,HIGH);
 digitalWrite(GG,HIGH);
  digitalWrite(A,LOW);
 digitalWrite(B,HIGH);
 digitalWrite(C,LOW);
 digitalWrite(D,LOW);
 digitalWrite(E,LOW);
 digitalWrite(F1,LOW);
 digitalWrite(G,LOW);
   
  }
  if(i==17){
 digitalWrite(AA,HIGH);
 digitalWrite(BB,LOW);
 digitalWrite(CC,LOW);
 digitalWrite(DD,HIGH);
 digitalWrite(EE,HIGH);
 digitalWrite(FF,HIGH);
 digitalWrite(GG,HIGH);
  digitalWrite(A,LOW);
 digitalWrite(B,LOW);
 digitalWrite(C,LOW);
 digitalWrite(D,HIGH);
 digitalWrite(E,HIGH);
 digitalWrite(F1,HIGH);
 digitalWrite(G,HIGH);  
  }
  if(i==18){
 digitalWrite(AA,HIGH);
 digitalWrite(BB,LOW);
 digitalWrite(CC,LOW);
 digitalWrite(DD,HIGH);
 digitalWrite(EE,HIGH);
 digitalWrite(FF,HIGH);
 digitalWrite(GG,HIGH);
  digitalWrite(A,LOW);
 digitalWrite(B,LOW);
 digitalWrite(C,LOW);
 digitalWrite(D,LOW);
 digitalWrite(E,LOW);
 digitalWrite(F1,LOW);
 digitalWrite(G,LOW);  
  }
  if(i==19){
 digitalWrite(AA,HIGH);
 digitalWrite(BB,LOW);
 digitalWrite(CC,LOW);
 digitalWrite(DD,HIGH);
 digitalWrite(EE,HIGH);
 digitalWrite(FF,HIGH);
 digitalWrite(GG,HIGH);
  digitalWrite(A,LOW);
 digitalWrite(B,LOW);
 digitalWrite(C,LOW);
 digitalWrite(D,LOW);
 digitalWrite(E,HIGH);
 digitalWrite(F1,LOW);
 digitalWrite(G,LOW);
  }
  if(i==20){
 digitalWrite(AA,LOW);
 digitalWrite(BB,LOW);
 digitalWrite(CC,HIGH);
 digitalWrite(DD,LOW);
 digitalWrite(EE,LOW);
 digitalWrite(FF,HIGH);
 digitalWrite(GG,LOW);
  digitalWrite(A,LOW);
 digitalWrite(B,LOW);
 digitalWrite(C,LOW);
 digitalWrite(D,LOW);
 digitalWrite(E,LOW);
 digitalWrite(F1,LOW);
 digitalWrite(G,HIGH); 
    }
  if(i==21){
   digitalWrite(AA,LOW);
 digitalWrite(BB,LOW);
 digitalWrite(CC,HIGH);
 digitalWrite(DD,LOW);
 digitalWrite(EE,LOW);
 digitalWrite(FF,HIGH);
 digitalWrite(GG,LOW);
  digitalWrite(A,HIGH);
 digitalWrite(B,LOW);
 digitalWrite(C,LOW);
 digitalWrite(D,HIGH);
 digitalWrite(E,HIGH);
 digitalWrite(F1,HIGH);
 digitalWrite(G,HIGH);  
    }
  if(i==22){
 digitalWrite(AA,LOW);
 digitalWrite(BB,LOW);
 digitalWrite(CC,HIGH);
 digitalWrite(DD,LOW);
 digitalWrite(EE,LOW);
 digitalWrite(FF,HIGH);
 digitalWrite(GG,LOW);
 digitalWrite(A,LOW);
 digitalWrite(B,LOW);
 digitalWrite(C,HIGH);
 digitalWrite(D,LOW);
 digitalWrite(E,LOW);
 digitalWrite(F1,HIGH);
 digitalWrite(G,LOW); 
    }
  if(i==23){
 digitalWrite(AA,LOW);
 digitalWrite(BB,LOW);
 digitalWrite(CC,HIGH);
 digitalWrite(DD,LOW);
 digitalWrite(EE,LOW);
 digitalWrite(FF,HIGH);
 digitalWrite(GG,LOW);
 digitalWrite(A,LOW);
 digitalWrite(B,LOW);
 digitalWrite(C,LOW);
 digitalWrite(D,LOW);
 digitalWrite(E,HIGH);
 digitalWrite(F1,HIGH);
 digitalWrite(G,LOW); 
    }
  if(i==24){
 digitalWrite(AA,LOW);
 digitalWrite(BB,LOW);
 digitalWrite(CC,HIGH);
 digitalWrite(DD,LOW);
 digitalWrite(EE,LOW);
 digitalWrite(FF,HIGH);
 digitalWrite(GG,LOW);
 digitalWrite(A,HIGH);
 digitalWrite(B,LOW);
 digitalWrite(C,LOW);
 digitalWrite(D,HIGH);
 digitalWrite(E,HIGH);
 digitalWrite(F1,LOW);
 digitalWrite(G,LOW); 
    }
  if(i==25){
 digitalWrite(AA,LOW);
 digitalWrite(BB,LOW);
 digitalWrite(CC,HIGH);
 digitalWrite(DD,LOW);
 digitalWrite(EE,LOW);
 digitalWrite(FF,HIGH);
 digitalWrite(GG,LOW);
 digitalWrite(A,LOW);
 digitalWrite(B,HIGH);
 digitalWrite(C,LOW);
 digitalWrite(D,LOW);
 digitalWrite(E,HIGH);
 digitalWrite(F1,LOW);
 digitalWrite(G,LOW);
    }
  if(i==26){
 digitalWrite(AA,LOW);
 digitalWrite(BB,LOW);
 digitalWrite(CC,HIGH);
 digitalWrite(DD,LOW);
 digitalWrite(EE,LOW);
 digitalWrite(FF,HIGH);
 digitalWrite(GG,LOW);
   digitalWrite(A,LOW);
 digitalWrite(B,HIGH);
 digitalWrite(C,LOW);
 digitalWrite(D,LOW);
 digitalWrite(E,LOW);
 digitalWrite(F1,LOW);
 digitalWrite(G,LOW);  
    }
  if(i==27){
 digitalWrite(AA,LOW);
 digitalWrite(BB,LOW);
 digitalWrite(CC,HIGH);
 digitalWrite(DD,LOW);
 digitalWrite(EE,LOW);
 digitalWrite(FF,HIGH);
 digitalWrite(GG,LOW);
   digitalWrite(A,LOW);
 digitalWrite(B,LOW);
 digitalWrite(C,LOW);
 digitalWrite(D,HIGH);
 digitalWrite(E,HIGH);
 digitalWrite(F1,HIGH);
 digitalWrite(G,HIGH);
  
    }
  if(i==28){
 digitalWrite(AA,LOW);
 digitalWrite(BB,LOW);
 digitalWrite(CC,HIGH);
 digitalWrite(DD,LOW);
 digitalWrite(EE,LOW);
 digitalWrite(FF,HIGH);
 digitalWrite(GG,LOW);
   digitalWrite(A,LOW);
 digitalWrite(B,LOW);
 digitalWrite(C,LOW);
 digitalWrite(D,LOW);
 digitalWrite(E,LOW);
 digitalWrite(F1,LOW);
 digitalWrite(G,LOW);  
    }
  if(i==29){
 digitalWrite(AA,LOW);
 digitalWrite(BB,LOW);
 digitalWrite(CC,HIGH);
 digitalWrite(DD,LOW);
 digitalWrite(EE,LOW);
 digitalWrite(FF,HIGH);
 digitalWrite(GG,LOW);
 digitalWrite(A,LOW);
 digitalWrite(B,LOW);
 digitalWrite(C,LOW);
 digitalWrite(D,LOW);
 digitalWrite(E,HIGH);
 digitalWrite(F1,LOW);
 digitalWrite(G,LOW);  
    }
  if(i==30){
 digitalWrite(AA,LOW);
 digitalWrite(BB,LOW);
 digitalWrite(CC,LOW);
 digitalWrite(DD,LOW);
 digitalWrite(EE,HIGH);
 digitalWrite(FF,HIGH);
 digitalWrite(GG,LOW);
 digitalWrite(A,LOW);
 digitalWrite(B,LOW);
 digitalWrite(C,LOW);
 digitalWrite(D,LOW);
 digitalWrite(E,LOW);
 digitalWrite(F1,LOW);
 digitalWrite(G,HIGH);   
    }
  if(i==31){
 digitalWrite(AA,LOW);
 digitalWrite(BB,LOW);
 digitalWrite(CC,LOW);
 digitalWrite(DD,LOW);
 digitalWrite(EE,HIGH);
 digitalWrite(FF,HIGH);
 digitalWrite(GG,LOW);
 digitalWrite(A,HIGH);
 digitalWrite(B,LOW);
 digitalWrite(C,LOW);
 digitalWrite(D,HIGH);
 digitalWrite(E,HIGH);
 digitalWrite(F1,HIGH);
 digitalWrite(G,HIGH);    
    }
  if(i==32){
 digitalWrite(AA,LOW);
 digitalWrite(BB,LOW);
 digitalWrite(CC,LOW);
 digitalWrite(DD,LOW);
 digitalWrite(EE,HIGH);
 digitalWrite(FF,HIGH);
 digitalWrite(GG,LOW);
 digitalWrite(A,LOW);
 digitalWrite(B,LOW);
 digitalWrite(C,HIGH);
 digitalWrite(D,LOW);
 digitalWrite(E,LOW);
 digitalWrite(F1,HIGH);
 digitalWrite(G,LOW);   
    }
  if(i==33){
 digitalWrite(AA,LOW);
 digitalWrite(BB,LOW);
 digitalWrite(CC,LOW);
 digitalWrite(DD,LOW);
 digitalWrite(EE,HIGH);
 digitalWrite(FF,HIGH);
 digitalWrite(GG,LOW);
 digitalWrite(A,LOW);
 digitalWrite(B,LOW);
 digitalWrite(C,LOW);
 digitalWrite(D,LOW);
 digitalWrite(E,HIGH);
 digitalWrite(F1,HIGH);
 digitalWrite(G,LOW);   
    }
  if(i==34){
 digitalWrite(AA,LOW);
 digitalWrite(BB,LOW);
 digitalWrite(CC,LOW);
 digitalWrite(DD,LOW);
 digitalWrite(EE,HIGH);
 digitalWrite(FF,HIGH);
 digitalWrite(GG,LOW);
 digitalWrite(A,HIGH);
 digitalWrite(B,LOW);
 digitalWrite(C,LOW);
 digitalWrite(D,HIGH);
 digitalWrite(E,HIGH);
 digitalWrite(F1,LOW);
 digitalWrite(G,LOW);   
    }
  if(i==35){
 digitalWrite(AA,LOW);
 digitalWrite(BB,LOW);
 digitalWrite(CC,LOW);
 digitalWrite(DD,LOW);
 digitalWrite(EE,HIGH);
 digitalWrite(FF,HIGH);
 digitalWrite(GG,LOW);
 digitalWrite(A,LOW);
 digitalWrite(B,HIGH);
 digitalWrite(C,LOW);
 digitalWrite(D,LOW);
 digitalWrite(E,HIGH);
 digitalWrite(F1,LOW);
 digitalWrite(G,LOW);   
    }
  if(i==36){
 digitalWrite(AA,LOW);
 digitalWrite(BB,LOW);
 digitalWrite(CC,LOW);
 digitalWrite(DD,LOW);
 digitalWrite(EE,HIGH);
 digitalWrite(FF,HIGH);
 digitalWrite(GG,LOW);
 digitalWrite(A,LOW);
 digitalWrite(B,HIGH);
 digitalWrite(C,LOW);
 digitalWrite(D,LOW);
 digitalWrite(E,LOW);
 digitalWrite(F1,LOW);
 digitalWrite(G,LOW);    
    }
  if(i==37){
 digitalWrite(AA,LOW);
 digitalWrite(BB,LOW);
 digitalWrite(CC,LOW);
 digitalWrite(DD,LOW);
 digitalWrite(EE,HIGH);
 digitalWrite(FF,HIGH);
 digitalWrite(GG,LOW);
 digitalWrite(A,LOW);
 digitalWrite(B,LOW);
 digitalWrite(C,LOW);
 digitalWrite(D,HIGH);
 digitalWrite(E,HIGH);
 digitalWrite(F1,HIGH);
 digitalWrite(G,HIGH);    
    }
  if(i==38){
 digitalWrite(AA,LOW);
 digitalWrite(BB,LOW);
 digitalWrite(CC,LOW);
 digitalWrite(DD,LOW);
 digitalWrite(EE,HIGH);
 digitalWrite(FF,HIGH);
 digitalWrite(GG,LOW);
 digitalWrite(A,LOW);
 digitalWrite(B,LOW);
 digitalWrite(C,LOW);
 digitalWrite(D,LOW);
 digitalWrite(E,LOW);
 digitalWrite(F1,LOW);
 digitalWrite(G,LOW);    
    }
  if(i==39){
 digitalWrite(AA,LOW);
 digitalWrite(BB,LOW);
 digitalWrite(CC,LOW);
 digitalWrite(DD,LOW);
 digitalWrite(EE,HIGH);
 digitalWrite(FF,HIGH);
 digitalWrite(GG,LOW); 
 digitalWrite(A,LOW);
 digitalWrite(B,LOW);
 digitalWrite(C,LOW);
 digitalWrite(D,LOW);
 digitalWrite(E,HIGH);
 digitalWrite(F1,LOW);
 digitalWrite(G,LOW);   
    }
 if(i==40){
  digitalWrite(AA,HIGH);
 digitalWrite(BB,LOW);
 digitalWrite(CC,LOW);
 digitalWrite(DD,HIGH);
 digitalWrite(EE,HIGH);
 digitalWrite(FF,LOW);
 digitalWrite(GG,LOW);
  digitalWrite(A,LOW);
 digitalWrite(B,LOW);
 digitalWrite(C,LOW);
 digitalWrite(D,LOW);
 digitalWrite(E,LOW);
 digitalWrite(F1,LOW);
 digitalWrite(G,HIGH); 
  }
 if(i==41){
  digitalWrite(AA,HIGH);
 digitalWrite(BB,LOW);
 digitalWrite(CC,LOW);
 digitalWrite(DD,HIGH);
 digitalWrite(EE,HIGH);
 digitalWrite(FF,LOW);
 digitalWrite(GG,LOW);
  digitalWrite(A,HIGH);
 digitalWrite(B,LOW);
 digitalWrite(C,LOW);
 digitalWrite(D,HIGH);
 digitalWrite(E,HIGH);
 digitalWrite(F1,HIGH);
 digitalWrite(G,HIGH); 
  }
 if(i==42){
  digitalWrite(AA,HIGH);
 digitalWrite(BB,LOW);
 digitalWrite(CC,LOW);
 digitalWrite(DD,HIGH);
 digitalWrite(EE,HIGH);
 digitalWrite(FF,LOW);
 digitalWrite(GG,LOW);
  digitalWrite(A,LOW);
 digitalWrite(B,LOW);
 digitalWrite(C,HIGH);
 digitalWrite(D,LOW);
 digitalWrite(E,LOW);
 digitalWrite(F1,HIGH);
 digitalWrite(G,LOW);
  }
 if(i==43){
  digitalWrite(AA,HIGH);
 digitalWrite(BB,LOW);
 digitalWrite(CC,LOW);
 digitalWrite(DD,HIGH);
 digitalWrite(EE,HIGH);
 digitalWrite(FF,LOW);
 digitalWrite(GG,LOW);
  digitalWrite(A,LOW);
 digitalWrite(B,LOW);
 digitalWrite(C,LOW);
 digitalWrite(D,LOW);
 digitalWrite(E,HIGH);
 digitalWrite(F1,HIGH);
 digitalWrite(G,LOW); 
  }
 if(i==44){
  digitalWrite(AA,HIGH);
 digitalWrite(BB,LOW);
 digitalWrite(CC,LOW);
 digitalWrite(DD,HIGH);
 digitalWrite(EE,HIGH);
 digitalWrite(FF,LOW);
 digitalWrite(GG,LOW);
 digitalWrite(A,HIGH);
 digitalWrite(B,LOW);
 digitalWrite(C,LOW);
 digitalWrite(D,HIGH);
 digitalWrite(E,HIGH);
 digitalWrite(F1,LOW);
 digitalWrite(G,LOW);  
  }
 if(i==45){
  digitalWrite(AA,HIGH);
 digitalWrite(BB,LOW);
 digitalWrite(CC,LOW);
 digitalWrite(DD,HIGH);
 digitalWrite(EE,HIGH);
 digitalWrite(FF,LOW);
 digitalWrite(GG,LOW);
  digitalWrite(A,LOW);
 digitalWrite(B,HIGH);
 digitalWrite(C,LOW);
 digitalWrite(D,LOW);
 digitalWrite(E,HIGH);
 digitalWrite(F1,LOW);
 digitalWrite(G,LOW); 
  }
 if(i==46){
  digitalWrite(AA,HIGH);
 digitalWrite(BB,LOW);
 digitalWrite(CC,LOW);
 digitalWrite(DD,HIGH);
 digitalWrite(EE,HIGH);
 digitalWrite(FF,LOW);
 digitalWrite(GG,LOW); 
 digitalWrite(A,LOW);
 digitalWrite(B,HIGH);
 digitalWrite(C,LOW);
 digitalWrite(D,LOW);
 digitalWrite(E,LOW);
 digitalWrite(F1,LOW);
 digitalWrite(G,LOW); 
  }
 if(i==47){
  digitalWrite(AA,HIGH);
 digitalWrite(BB,LOW);
 digitalWrite(CC,LOW);
 digitalWrite(DD,HIGH);
 digitalWrite(EE,HIGH);
 digitalWrite(FF,LOW);
 digitalWrite(GG,LOW);
 digitalWrite(A,LOW);
 digitalWrite(B,LOW);
 digitalWrite(C,LOW);
 digitalWrite(D,HIGH);
 digitalWrite(E,HIGH);
 digitalWrite(F1,HIGH);
 digitalWrite(G,HIGH);
  }
 if(i==48){
  digitalWrite(AA,HIGH);
 digitalWrite(BB,LOW);
 digitalWrite(CC,LOW);
 digitalWrite(DD,HIGH);
 digitalWrite(EE,HIGH);
 digitalWrite(FF,LOW);
 digitalWrite(GG,LOW); 
 digitalWrite(A,LOW);
 digitalWrite(B,LOW);
 digitalWrite(C,LOW);
 digitalWrite(D,LOW);
 digitalWrite(E,LOW);
 digitalWrite(F1,LOW);
 digitalWrite(G,LOW);
  }
 if(i==49){
  digitalWrite(AA,HIGH);
 digitalWrite(BB,LOW);
 digitalWrite(CC,LOW);
 digitalWrite(DD,HIGH);
 digitalWrite(EE,HIGH);
 digitalWrite(FF,LOW);
 digitalWrite(GG,LOW);
  digitalWrite(A,LOW);
 digitalWrite(B,LOW);
 digitalWrite(C,LOW);
 digitalWrite(D,LOW);
 digitalWrite(E,HIGH);
 digitalWrite(F1,LOW);
 digitalWrite(G,LOW);
  }
 if(i==50){
 digitalWrite(AA,LOW);
 digitalWrite(BB,HIGH);
 digitalWrite(CC,LOW);
 digitalWrite(DD,LOW);
 digitalWrite(EE,HIGH);
 digitalWrite(FF,LOW);
 digitalWrite(GG,LOW);
 digitalWrite(A,LOW);
 digitalWrite(B,LOW);
 digitalWrite(C,LOW);
 digitalWrite(D,LOW);
 digitalWrite(E,LOW);
 digitalWrite(F1,LOW);
 digitalWrite(G,HIGH);
  } 
}
