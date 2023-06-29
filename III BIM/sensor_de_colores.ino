#include <Stepper.h>
#include <Servo.h>
#define LDR    A0  
#define ledA  4  
#define ledV 2  
#define ledR  5
int servo = 3;
int stepsPerRevolution = 2048;
int motorSpeed = 15;
int infrarrojo = 7;
int resultado_azul, resultado_rojo, resultado_verde;
int resultado;
int tol = 8;
Stepper myStepper(stepsPerRevolution, 11, 9, 10, 8);
Servo ciervito; 
void obstaculito();
void setup() {
  Serial.begin(9600);
  myStepper.setSpeed(motorSpeed);
  ciervito.attach(servo);
  pinMode(infrarrojo,INPUT);
  pinMode(LDR, INPUT);
  pinMode(ledA, OUTPUT); 
  pinMode(ledV, OUTPUT); 
  pinMode(ledR, OUTPUT); 
  //Los leds inician en un estado de bajo
  digitalWrite(ledA, LOW);
  digitalWrite(ledV, LOW);
  digitalWrite(ledR, LOW); 
}
void loop() {
  obstaculito();
}
void obstaculito(){
  int inf = digitalRead(infrarrojo);
  if(inf == LOW){
  //Enviendo el led rojo
  digitalWrite(ledR, HIGH);
  //espero 50 milisegundos
  delay(50);
  //Leo el valor captado por la LDR
  resultado = analogRead(LDR);
  resultado_rojo = map(resultado, 0,1023,0,255);  //lo linealizo 
  digitalWrite(ledR, LOW);
  delay(50);
  //Enviendo el led verde
  digitalWrite(ledV, HIGH);
  //espero 50 milisegundos
  delay(50);
  //Leo el valor captado por la LDR
  resultado = analogRead(LDR);
  resultado_verde = map(resultado, 0,1023,0,255);  //lo linealizo 
  digitalWrite(ledV, LOW);
  delay(50);
   //Enviendo el led azul
  digitalWrite(ledA, HIGH);
  //espero 50 milisegundos
  delay(50);
  //Leo el valor captado por la LDR
  resultado = analogRead(LDR);
  resultado_azul = map(resultado, 0,1023,0,255);  //lo linealizo 
  digitalWrite(ledA, LOW);
  delay(50);
 if(resultado_azul > resultado_verde && resultado_azul > resultado_rojo){
  ciervito.write(0);
 }
 else{
  ciervito.write(90);
 }
 myStepper.step(0);
 delay(525);
 myStepper.step(stepsPerRevolution);
  }
  else{
    myStepper.step(stepsPerRevolution);
  }
  }
