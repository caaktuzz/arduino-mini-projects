// управление тремя переменными при помощи энкодера:
// - нащёлкай кнопкой нужную переменную (1, 2 или 3 клика)
// - 1 переменная просто изменяется с постоянным шагом
// - 2 переменная: шаг 1, при зажатой кнопке - шаг 5
// - 3 переменная: шаг 1, при быстром вращении - шаг 5

#include <Arduino.h>
#include <EncButton.h>
EncButton enc(9, 10, 11);


int pins2[8] = {2,3,4,5,6,7,8,11};

#define a 2
#define b 3
#define c 4
#define d 5
#define e 6
#define f 7
#define g 8
#define dp 11 

int var = 0;

int bright = 128; // уровень яркости светодиода
bool state = 1;   // состояние светодиода

void setup() {
  Serial.begin(9600);
  
  pinMode(a, OUTPUT); 
  pinMode(b, OUTPUT); 
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT); 
  pinMode(e, OUTPUT); 
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
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
  if (number == 2) {
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
  
  if (enc.turn()) {
        var = constrain(var += 1 * enc.dir(), 0, 9);
        Serial.println(String("vars ") + var);  
        digits(var);
    }
}
