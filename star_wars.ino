int trigger = 2;
int echo = 3;
int tiempo;
int distancia; 
int ZumbadorPin = 4;
int c=261; 
int d=294;
int e=329;
int f=349;
int g=391;
int gS=415;
int a=440;
int aS=455;
int b=466;
int cH=523;
int cSH=554;
int dH=587;
int dSH=622;
int eH=659;
int fH=698;
int fSH=740;
int gH=783;
int gSH=830;
int aH=880;
void setup() {
Serial.begin(9600);
pinMode(trigger, OUTPUT);
pinMode(echo,INPUT);
digitalWrite(trigger,LOW);
pinMode(ZumbadorPin, OUTPUT);
}

void loop() {
digitalWrite(trigger, HIGH);
delayMicroseconds(10);
digitalWrite(trigger, LOW);
tiempo= pulseIn(echo, HIGH);
distancia= tiempo/59;
Serial.print("distancia");
Serial.print(distancia);
Serial.println("cm");
delay(100);
if(distancia>=2 && distancia <=5){
   tone(ZumbadorPin, a, 500);
    delay(500+50);}
if(distancia>=6 && distancia <=10){
   tone(ZumbadorPin, f, 500);
    delay(500+50);}
if(distancia>=11 && distancia <=15){
   tone(ZumbadorPin, cH, 500);
    delay(500+50);}
if(distancia>=16 && distancia <=20){
   tone(ZumbadorPin, eH, 500);
    delay(500+50);}
if(distancia>=21 && distancia <=25){
   tone(ZumbadorPin, fH, 500);
    delay(500+50);}
if(distancia>=26 && distancia <=30){
   tone(ZumbadorPin, aH, 500);
    delay(500+50);}
if(distancia>=31 && distancia <=35){
   tone(ZumbadorPin,gSH, 500);
    delay(500+50);}
if(distancia>=36 && distancia <=40){
   tone(ZumbadorPin, fSH, 500);
    delay(500+50);}
if(distancia>=41 && distancia <=45){
   tone(ZumbadorPin, b, 500);
    delay(500+50);}
if(distancia>=46 && distancia <=50){
   tone(ZumbadorPin, aS, 500);
    delay(500+50);}
}
