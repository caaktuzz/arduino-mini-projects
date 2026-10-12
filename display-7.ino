
#define a 2
#define b 3
#define c 4
#define d 5
#define e 6
#define f 7
#define g 8
#define dp 9



void setup()                                                        //      A             ...2...
{                                                                   //   F     B          7  .  3
  pinMode(a, OUTPUT); pinMode(b, OUTPUT); pinMode(c, OUTPUT);       //      G             ...8...
  pinMode(d, OUTPUT); pinMode(e, OUTPUT); pinMode(f, OUTPUT);       //   E     c          6  .  4
  pinMode(g, OUTPUT); pinMode(dp, OUTPUT);                          //      D     DP      ...5...  9
}                                                                   //


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

int time = 1000;

void loop() {
  
 digits(0); delay(time); 
 digits(1); delay(time);
 digits(2); delay(time);
 digits(3); delay(time);
 digits(4); delay(time);
 digits(5); delay(time);
 digits(6); delay(time);
 digits(7); delay(time);
 digits(8); delay(time);
 digits(9); delay(time);
 digits(10); delay(700);
 reset();

}



/*
  digitalWrite(a, LOW); digitalWrite(b, LOW); digitalWrite(c, LOW); digitalWrite(d, LOW);   //don`t say anything
  digitalWrite(e, LOW); digitalWrite(f, LOW); digitalWrite(g, LOW); digitalWrite(dp, LOW);   //
  */