
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
  pinMode(a, OUTPUT); pinMode(b, OUTPUT); pinMode(c, OUTPUT);       //      G             ...8..
  pinMode(d, OUTPUT); pinMode(e, OUTPUT); pinMode(f, OUTPUT);       //   E     c          6  .  4
  pinMode(g, OUTPUT); pinMode(dp, OUTPUT);                           //      D      DP     ...5...  9
}                                                                   //

void digits(uint8_t number) {
  if (number == 0) {
    digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH); digitalWrite(d, HIGH);   // say 0
    digitalWrite(e, HIGH); digitalWrite(f, HIGH); digitalWrite(g, LOW); digitalWrite(dp, LOW); //
  
  }
  if (number == 1) {
    digitalWrite(a, LOW); digitalWrite(b, HIGH); digitalWrite(c, HIGH); digitalWrite(d, LOW);   // say 1
    digitalWrite(e, LOW); digitalWrite(f, LOW); digitalWrite(g, LOW); digitalWrite(dp, LOW);  //
  }
  if ( number == 2) {
    digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, LOW); digitalWrite(d, HIGH);   // say 2
    digitalWrite(e, HIGH); digitalWrite(f, LOW); digitalWrite(g, HIGH); digitalWrite(dp, LOW); //
  }
  if (number == 3) {
    digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH); digitalWrite(d, HIGH);   // say 3
    digitalWrite(e, LOW); digitalWrite(f, LOW); digitalWrite(g, HIGH); digitalWrite(dp, LOW); //
  }
  if (number == 4) {

  }
  if (number == 5) {

  }
  if (number == 6) {

  }
  if (number == 7) {

  }
  if (number == 8) {

  }
  if (number == 9) {

  }
  if (number == 10) {

  }
 }


void reset() {
  digitalWrite(a, LOW); digitalWrite(b, LOW); digitalWrite(c, LOW); digitalWrite(d, LOW);   //don`t say anything
  digitalWrite(e, LOW); digitalWrite(f, LOW); digitalWrite(g, LOW); digitalWrite(dp, LOW);
  delay(30); 
 }

void loop() {
  
  digits(0); delay(1000); 
  digits(1); delay(1000);
  digits(2); delay(1000);
  digits(3); delay(1000);

}



/*
  digitalWrite(a, LOW); digitalWrite(b, LOW); digitalWrite(c, LOW); digitalWrite(d, LOW);   //don`t say anything
  digitalWrite(e, LOW); digitalWrite(f, LOW); digitalWrite(g, LOW); digitalWrite(dp, LOW);   //
  */