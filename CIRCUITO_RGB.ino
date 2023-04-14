#define PUSHBUTTON1 12
#define PUSHBUTTON2 11
#define LED_ROJO 10
#define LED_VERDE 9
#define LED_AZUL 8
void setup() {
pinMode(PUSHBUTTON1, INPUT_PULLUP);
pinMode(PUSHBUTTON2, INPUT_PULLUP);
pinMode(LED_ROJO, OUTPUT);
pinMode(LED_VERDE, OUTPUT);
pinMode(LED_AZUL, OUTPUT);
}
void loop() {
int ESTADO1 = digitalRead(PUSHBUTTON1);
int ESTADO2 = digitalRead(PUSHBUTTON2);
if(ESTADO1== LOW && ESTADO2 == HIGH) {
digitalWrite(LED_ROJO, HIGH);
digitalWrite(LED_VERDE, LOW);
digitalWrite(LED_AZUL, HIGH);
delay(500); 
digitalWrite(LED_ROJO, LOW);
digitalWrite(LED_VERDE, LOW);
digitalWrite(LED_AZUL, LOW);
} else if (ESTADO1 == LOW) {
digitalWrite(LED_ROJO, HIGH);
digitalWrite(LED_VERDE, HIGH);
digitalWrite(LED_AZUL, LOW);
} else if (ESTADO2 == LOW) {
digitalWrite(LED_ROJO, LOW);
digitalWrite(LED_VERDE, HIGH);
digitalWrite(LED_AZUL, HIGH);
} else {
digitalWrite(LED_ROJO, HIGH);
digitalWrite(LED_VERDE, LOW);
digitalWrite(LED_AZUL, LOW);
delay(500);
digitalWrite(LED_ROJO, LOW);
digitalWrite(LED_VERDE, HIGH);5yy3
delay(500);
digitalWrite(LED_ROJO, LOW);
digitalWrite(LED_VERDE, LOW);
digitalWrite(LED_AZUL, HIGH);
delay(500); 
}
}
