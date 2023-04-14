int pin;
void setup()
{
  for( pin = 2; pin <= 11; pin++)
  {    
    pinMode(pin,OUTPUT);    
  }
}
void loop()
{
 for( pin = 2; pin <= 11; pin++)
  {    
    pinMode(pin,OUTPUT);
    digitalWrite(pin,HIGH);
    delay(50);
    digitalWrite(pin,LOW);
  }  
  for( pin = 11; pin >= 2; pin--)
  {  
    pinMode(pin,OUTPUT);
    digitalWrite(pin,HIGH);
    delay(50);
    digitalWrite(pin,LOW);
  }  
}
