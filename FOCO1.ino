
int Trigger = 3;
int Echo = 2;
int A = 4;
int B = 5;
int C = 6;
int D = 7;
int E = 8;
int F = 9;
int G = 10;
int foco = 11;


int personas; 

void setup() {
  Serial.begin(9600);
  pinMode(Trigger, OUTPUT);
  pinMode(Echo, INPUT);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(foco, OUTPUT);
  digitalWrite(foco, HIGH);
  cero(); 
}

void loop() {
  int distancia = P();
  Serial.println(distancia);
  if (distancia >= 6 && distancia <= 9) {
    personas++;
    switch (personas) {
      case 1:
        display_uno();
        break;
      case 2:
        display_dos();
        break;
      case 3:
        display_tres();
        break;
      case 4:
        display_cuatro();
        break;
      case 5:
        display_cinco();
        break;
      case 6:
        display_seis();
        break;
      case 7:
        display_siete();
        break;
      case 8:
        display_ocho();
        break;
      case 9:
        display_nueve();
        break;
      case 10:
        digitalWrite(foco, LOW);
        display_nueve();
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
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
}
void  display_uno() {
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}
void  display_dos() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
}
void  display_tres() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
}
void  display_cuatro() {
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}
void  display_cinco() {
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}
void  display_seis() {
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}
void  display_siete() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}
void  display_ocho() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}
void  display_nueve() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}
