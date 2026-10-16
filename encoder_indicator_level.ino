
#include <EncButton.h>
EncButton enc(11, 10, 9);

#define a 2
#define b 3
#define c 4
#define d 5
#define e 6
#define f 7
#define g 8
#define dp 11


int bright = 8; // уровень числа 0-9
bool state = 1;   // состояние светодиода

void setup()  {                                                     //      A             ...2...
  Serial.begin(9600);                                               //   F     B          7  .  3
  pinMode(a, OUTPUT); pinMode(b, OUTPUT); pinMode(c, OUTPUT);       //      G             ...8...
  pinMode(d, OUTPUT); pinMode(e, OUTPUT); pinMode(f, OUTPUT);       //   E     c          6  .  4
  pinMode(g, OUTPUT); pinMode(dp, OUTPUT);                          //      D     DP      ...5...  9
}

void digits(uint8_t number) {
  if (number == 0) {
    digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH); digitalWrite(d, HIGH);   // say 0
    digitalWrite(e, HIGH); digitalWrite(f, HIGH); digitalWrite(g, LOW); digitalWrite(dp, LOW); 
  }
  if (number == 1) {
    digitalWrite(a, LOW); digitalWrite(b, HIGH); digitalWrite(c, HIGH); digitalWrite(d, LOW);   // say 1
    digitalWrite(e, LOW); digitalWrite(f, LOW); digitalWrite(g, LOW); digitalWrite(dp, LOW);  
  }
  if ( number == 2) {
    digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, LOW); digitalWrite(d, HIGH);   // say 2
    digitalWrite(e, HIGH); digitalWrite(f, LOW); digitalWrite(g, HIGH); digitalWrite(dp, LOW); 
  }
  if (number == 3) {
    digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH); digitalWrite(d, HIGH);   // say 3
    digitalWrite(e, LOW); digitalWrite(f, LOW); digitalWrite(g, HIGH); digitalWrite(dp, LOW); 
  }
  if (number == 4) {
    digitalWrite(a, LOW); digitalWrite(b, HIGH); digitalWrite(c, HIGH); digitalWrite(d, LOW);   // say 4
    digitalWrite(e, LOW); digitalWrite(f, HIGH); digitalWrite(g, HIGH); digitalWrite(dp, LOW); 
  }
  if (number == 5) {
    digitalWrite(a, HIGH); digitalWrite(b, LOW); digitalWrite(c, HIGH); digitalWrite(d, HIGH);   // say 5
    digitalWrite(e, LOW); digitalWrite(f, HIGH); digitalWrite(g, HIGH); digitalWrite(dp, LOW); 
  }
  if (number == 6) {
    digitalWrite(a, HIGH); digitalWrite(b, LOW); digitalWrite(c, HIGH); digitalWrite(d, HIGH);   // say 6
    digitalWrite(e, HIGH); digitalWrite(f, HIGH); digitalWrite(g, HIGH); digitalWrite(dp, LOW); 
  }
  if (number == 7) {
    digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH); digitalWrite(d, LOW);   // say 7
    digitalWrite(e, LOW); digitalWrite(f, LOW); digitalWrite(g, LOW); digitalWrite(dp, LOW);  
  }
  if (number == 8) {
    digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH); digitalWrite(d, HIGH);   // say 8
    digitalWrite(e, HIGH); digitalWrite(f, HIGH); digitalWrite(g, HIGH); digitalWrite(dp, LOW); 
  }
  if (number == 9) {
    digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH); digitalWrite(d, HIGH);   // say 9
    digitalWrite(e, LOW); digitalWrite(f, HIGH); digitalWrite(g, HIGH); digitalWrite(dp, LOW); 
  }
  if (number == 10) {
    digitalWrite(a, LOW); digitalWrite(b, LOW); digitalWrite(c, LOW); digitalWrite(d, LOW);   // say point
    digitalWrite(e, LOW); digitalWrite(f, LOW); digitalWrite(g, LOW); digitalWrite(dp, HIGH);
  }
}

void reset() {
  digitalWrite(a, LOW); digitalWrite(b, LOW); digitalWrite(c, LOW); digitalWrite(d, LOW);   //don`t say anything
  digitalWrite(e, LOW); digitalWrite(f, LOW); digitalWrite(g, LOW); digitalWrite(dp, LOW);
  delay(30); 
 }


void loop() {
 enc.tick(); 
  
  if (enc.right()) { // повышение уровня яркости
    bright = constrain(bright + 1, 0, 10);
    Serial.println(bright);
   }
   
  if (enc.left()) { // понижение уровня яркости
    bright = constrain(bright - 1, 0, 10);
    Serial.println(bright);
   }
   
  if (enc.click()) state = !state; // переключение состояния 
  if (state == 0) bright = 0;

  digits(bright);

  //analogWrite(LED_PIN_3, bright); // запуск светодиода с установкой яркости
 
}
