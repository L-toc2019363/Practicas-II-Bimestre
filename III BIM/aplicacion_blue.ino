#include <SoftwareSerial.h>
#include <DallasTemperature.h>
#include <OneWire.h>
#define led 4
SoftwareSerial bluet(10,11);
OneWire ourWire(2);
DallasTemperature
sensor_temp(&ourWire);

void setup() {
 pinMode(led, OUTPUT);
 Serial.begin(9600);
 Serial.println("encendido");
 bluet.begin(9600);
}
char receptor;
void loop() {
sensor_temp.requestTemperatures();
float temp=
sensor_temp.getTempCByIndex(0);
if(bluet.available()){
receptor=bluet.read();
Serial.println(receptor);

if(receptor == '1'){
Serial.println("on");
digitalWrite(led,HIGH);
}

if(receptor == '2'){
Serial.println("off");
digitalWrite(led,LOW);
}
}
if(Serial.available()){
Serial.write(Serial.read());
}
bluet.print(temp);
}
