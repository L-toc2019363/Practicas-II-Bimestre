#define push1 2 

#define push2 3

int L=0;

 

struct itemss

{

  char items[11];

  float precio_u;

  unsigned int stock;

  float precio_por_lote;

  unsigned int reserva;

};

itemss itemss1 = {"doritos",4.10,2,8.20,20};

itemss itemss2 = {"mountain",5.00,5,25.00,20};

itemss itemss3 = {"lays",7.50,4,30,20};

itemss itemss4 = {"lipton",5.00,10,50.00,20};

itemss chucherias []= {itemss1,itemss2,itemss3,itemss4};

 

void setup() {

  Serial.begin(9600);

  pinMode(push1,INPUT_PULLUP);

  pinMode(push2,INPUT_PULLUP);

}

 

void loop()

{

  if(digitalRead(push1)==LOW)

  {

    delay(100);

    L++;

     if(L>3)
     L=0;

Serial.println(L + 0);

Serial.println("productos");

Serial.println("Nombre del producto:");

Serial.println(chucherias[L].items);

Serial.println("precio unitario:");

Serial.println(chucherias[L].precio_u);

Serial.println("Stock:");

Serial.println(chucherias[L].stock);

Serial.println("Reserva:");

Serial.println(chucherias[L].reserva);

Serial.println("Precio por lote:");

Serial.println(chucherias[L].precio_por_lote);

  }

  if(digitalRead(push2)==LOW)

  {

    delay(100);

    L--;

    if(L<0) L=3;

Serial.println(L + 0);

Serial.println("productos");

Serial.println("Nombre del producto:");

Serial.println(chucherias[L].items);

Serial.println("precio unitario:");

Serial.println(chucherias[L].precio_u);

Serial.println("Stock:");

Serial.println(chucherias[L].stock);

Serial.println("Reserva:");

Serial.println(chucherias[L].reserva);

Serial.println("Precio por lote:");

Serial.println(chucherias[L].precio_por_lote);
 }
 delay(100);
}
