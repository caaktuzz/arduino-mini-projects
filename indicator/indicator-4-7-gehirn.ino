

//#define button1 10

// Пины сегментов (A, B, C, D, E, F, G, DP)
const int segPins[] = {2,3,4,5,6,7,8}; 
#define a 2
#define b 3
#define c 4
#define d 5
#define e 6
#define f 7
#define g 8
#define dp 9


// Пины общих анодов для 4-х разрядов (D1, D2, D3, D4)
const int digitPins[4] = {A2, A3, A4, A5}; 
#define D1 A2
#define D2 A3
#define D3 A4
#define D4 A5


int var = 0;

#define vr_x A0
#define vr_y A1
#define sw 10

uint64_t timeStamp = 0;

int16_t vr_x_data = 0;
int16_t vr_y_data = 0;
int8_t sw_data = 0;
int8_t crd = 9;

// Маска цифр от 0 до 9 для общего анода (0 — сегмент горит, 1 — не горит)
const byte digitCode[10][7] = {
  {0, 0, 0, 0, 0, 0, 1}, // 0
  {1, 0, 0, 1, 1, 1, 1}, // 1
  {0, 0, 1, 0, 0, 1, 0}, // 2
  {0, 0, 0, 0, 1, 1, 0}, // 3
  {1, 0, 0, 1, 1, 0, 0}, // 4
  {0, 1, 0, 0, 1, 0, 0}, // 5
  {0, 1, 0, 0, 0, 0, 0}, // 6
  {0, 0, 0, 1, 1, 1, 1}, // 7
  {0, 0, 0, 0, 0, 0, 0}, // 8
  {0, 0, 0, 0, 1, 0, 0}  // 9
};

//      A             ...2...
//   F     B          7  .  3
//      G             ...8...
//   E     c          6  .  4
//      D     DP      ...5...  9

void setup() {
  Serial.begin(9600);

 // pinMode(button1, INPUT_PULLUP); // кнопкa

  pinMode(a, OUTPUT); // сегменты индикатора
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(dp, OUTPUT);

  pinMode(D1, OUTPUT); // разряды индикатора
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);

  pinMode(sw, INPUT_PULLUP); // кнопка джойстика
}



void switch_digits(uint8_t number) {
  if (number == 0) {
    digitalWrite(a, LOW); digitalWrite(b, LOW); digitalWrite(c, LOW); digitalWrite(d, LOW);   // say 0
    digitalWrite(e, LOW); digitalWrite(f, LOW); digitalWrite(g, HIGH); digitalWrite(dp, HIGH); 
  }
  if (number == 1) {
    digitalWrite(a, HIGH); digitalWrite(b, LOW); digitalWrite(c, LOW); digitalWrite(d, HIGH);   // say 1
    digitalWrite(e, HIGH); digitalWrite(f, HIGH); digitalWrite(g, HIGH); digitalWrite(dp, HIGH);  
  }
  if (number == 2) {
    digitalWrite(a, LOW); digitalWrite(b, LOW); digitalWrite(c, HIGH); digitalWrite(d, LOW);   // say 2
    digitalWrite(e, LOW); digitalWrite(f, HIGH); digitalWrite(g, LOW); digitalWrite(dp, HIGH); 
  }
  if (number == 3) {
    digitalWrite(a, LOW); digitalWrite(b, LOW); digitalWrite(c, LOW); digitalWrite(d, LOW);   // say 3
    digitalWrite(e, HIGH); digitalWrite(f, HIGH); digitalWrite(g, LOW); digitalWrite(dp, HIGH); 
  }
  if (number == 4) {
    digitalWrite(a, HIGH); digitalWrite(b, LOW); digitalWrite(c, LOW); digitalWrite(d, HIGH);   // say 4
    digitalWrite(e, HIGH); digitalWrite(f, LOW); digitalWrite(g, LOW); digitalWrite(dp, HIGH); 
  }
  if (number == 5) {
    digitalWrite(a, LOW); digitalWrite(b, HIGH); digitalWrite(c, LOW); digitalWrite(d, LOW);   // say 5
    digitalWrite(e, HIGH); digitalWrite(f, LOW); digitalWrite(g, LOW); digitalWrite(dp, HIGH); 
  }
  if (number == 6) {
    digitalWrite(a, LOW); digitalWrite(b, HIGH); digitalWrite(c, LOW); digitalWrite(d, LOW);   // say 6
    digitalWrite(e, LOW); digitalWrite(f, LOW); digitalWrite(g, LOW); digitalWrite(dp, HIGH); 
  }
  if (number == 7) {
    digitalWrite(a, LOW); digitalWrite(b, LOW); digitalWrite(c, LOW); digitalWrite(d, HIGH);   // say 7
    digitalWrite(e, HIGH); digitalWrite(f, HIGH); digitalWrite(g, HIGH); digitalWrite(dp, HIGH);  
  }
  if (number == 8) {
    digitalWrite(a, LOW); digitalWrite(b, LOW); digitalWrite(c, LOW); digitalWrite(d, LOW);   // say 8
    digitalWrite(e, LOW); digitalWrite(f, LOW); digitalWrite(g, LOW); digitalWrite(dp, HIGH); 
  }
  if (number == 9) {
    digitalWrite(a, LOW); digitalWrite(b, LOW); digitalWrite(c, LOW); digitalWrite(d, LOW);   // say 9
    digitalWrite(e, HIGH); digitalWrite(f, LOW); digitalWrite(g, LOW); digitalWrite(dp, HIGH); 
  }
  if (number == 10) {
    digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH); digitalWrite(d, HIGH);   // say point
    digitalWrite(e, HIGH); digitalWrite(f, HIGH); digitalWrite(g, HIGH); digitalWrite(dp, LOW);
  }

  if (number == 11) {
    digitalWrite(D1, LOW); digitalWrite(D2, LOW); digitalWrite(D3, LOW); digitalWrite(D4, LOW); 
    digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH); digitalWrite(d, HIGH);   //don`t say anything
    digitalWrite(e, HIGH); digitalWrite(f, HIGH); digitalWrite(g, HIGH); digitalWrite(dp, HIGH);
 } 
}

void switch_zone(uint8_t number, uint8_t status) {
  if(status == 0) digitalWrite(number, HIGH);
  else digitalWrite(number, LOW);
}

uint8_t digit = 0;
// Функция вывода 4-значного числа
void printNumber(int *arr, size_t size) {

    switch_zone(digitPins[digit], 0);
    switch_digits(arr[digit]);

    delay(3); 

    switch_zone(digitPins[digit], 1);
    switch_digits(11);

  digit += 1;
  if (digit >= 4) digit = 0;
}


void j_data() {
  vr_x_data = map(analogRead(vr_x), 0, 1023, -100, 100);
  vr_y_data = map(analogRead(vr_y), 0, 1023, -100, 100);
  sw_data = digitalRead(sw);

  if(vr_x_data > 50 && vr_y_data < 50) crd = 1;  // вперёд по оси х
  if(vr_x_data < -50 && vr_y_data < 50) crd = -1;  // назад по оси х

  if(vr_x_data < 50 && vr_y_data > 50) crd = 2;  // вперёд по оси у
  if(vr_x_data < 50 && vr_y_data < -50) crd = -2;  // назад по оси у

  if(vr_x_data > 50 && vr_y_data > 50) crd = 3;  // вперёд по диагонали х y
  if(vr_x_data < -50 && vr_y_data < -50) crd = -3;  // назад по дагонали x y

  if(vr_x_data > 50 && vr_y_data < -50) crd = 4;  // вперёд по диагонали -y -x
  if(vr_x_data < -50 && vr_y_data > 50) crd = -4;  // назад по диагонали -y -x

  if(vr_x_data < 50 && vr_y_data < 50 && vr_x_data > -50 && vr_y_data > -50) crd = 0;  // нейтральное положение
   
}

boolean timer (int delayy) {
  if (millis() - timeStamp >= delayy) {
    timeStamp += delayy;
     return true;
  } else return false;
 }


bool status = true;

uint16_t number = 0000;
uint16_t digits[4] = {0,0,0,0};
uint16_t time_s = 200;
uint8_t cv = 0;

void loop() {

  //Serial.println(number);
  j_data();
  //Serial.println("vr_x: "+String(vr_x_data)+" vr_y: "+String(vr_y_data)+" sw: "+String(sw_data)+"    crd: "+String(crd));
  if(timer(time_s) == true) {
    
    if(crd == 1) number += 1; 
    if(crd == -1) number -= 1;
    if(crd == 2) number = 0; 
    if(crd == -2) number += 100; 

    if(crd != 0) cv += 1;
    else {
      time_s = 200; 
      cv = 0;
     }
    
    if(cv > 5) {
      time_s -= 10;
      if(time_s < 10) time_s = 10; 
     }
    

    if(number < 0) number = 9999;
    if(number > 9999) number = 0;

    //if(sw_data == 0) status = !status;
    //if(status == false) switch_digits(11); 
    
    digits[0] = (number / 1000) % 10;
    digits[1] = (number / 100) % 10;
    digits[2] = (number / 10) % 10;
    digits[3] = number % 10;
  }

  //Serial.println(String(numbers[0]) +"  "+ String(numbers[1]) +"  "+ String(numbers[2]) +"  "+ String(numbers[3]));
  //Serial.println(numbers[3]*1000+numbers[2]*100+numbers[1]*10+numbers[0]);
  
  printNumber(digits, 4);

}
