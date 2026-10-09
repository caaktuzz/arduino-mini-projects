
#define ledPin_2 2
#define ledPin_3 3
#define ledPin_4 4
//#define ledPin_5 5
//#define ledPin_6 6
//#define ledPin_7 7

#define buttonPin 8

uint64_t timeStamp[3] = {0, 0, 0}; 
uint32_t light_cycle_num = 0;
uint32_t loop_number = 1; 

uint16_t period = 1000;

void timeSleep(int milliseconds) {
  uint64_t timeStamp = millis();
  while ((millis() - timeStamp < milliseconds)) {}
 }

String print_led_status(int pin_number) { 
  return String ("LED PIN " + String(pin_number) + " is working");
 }

void setup () {
  Serial.begin(9600);

  pinMode(ledPin_2, OUTPUT);
  pinMode(ledPin_3, OUTPUT);
  pinMode(ledPin_4, OUTPUT);
  //pinMode(ledPin_5, OUTPUT);
  //pinMode(ledPin_6, OUTPUT);
  //pinMode(ledPin_7, OUTPUT);

  pinMode(buttonPin, INPUT_PULLUP);
}


boolean timer (int delayy, uint8_t tS_num, uint8_t pin) {
  if (millis() - timeStamp[tS_num] >= delayy) {
    timeStamp[tS_num] += delayy;
     digitalWrite(pin, !digitalRead(pin));
     return true;
  } else return false;
 }


void loop () {
 loop_number += 1; 

 timer(100, 0, 4);
 timer(2000, 1, 4);
//  if (timer(1000, 0) == true) digitalWrite(4, !digitalRead(4)); 
  //if (timer(6000, 1) == true) digitalWrite(4, !digitalRead(4)); 

  if (digitalRead(buttonPin) == LOW) {
    Serial.println("BUTTON is pressed");
    digitalWrite(2, HIGH); 
  } else digitalWrite(2, LOW); 

}


 /*
  //timeSleep(50);
 //Serial.println("LOOP "+String(loop_number));

      light_cycle_num += 1;
     Serial.println(light_cycle_num);


   //if (digitalRead(ledPin_2) == HIGH) period = 500;
 // else period = 1000; 
  
  if (millis() - timeStamp >= 500){
      Serial.println(1); }

      
  if (digitalRead(buttonPin) == LOW) {
    digitalWrite(ledPin_2, HIGH); timeSleep(100);
    digitalWrite(ledPin_3, HIGH); timeSleep(100);
    digitalWrite(ledPin_4, HIGH); timeSleep(100);

  }
  else {
    digitalWrite(ledPin_2, LOW); timeSleep(100);
    digitalWrite(ledPin_3, LOW); timeSleep(100);
    digitalWrite(ledPin_4, LOW); timeSleep(100);

  }

}


/*
    digitalWrite(ledPin_5, HIGH); timeSleep(100);
    digitalWrite(ledPin_6, HIGH); timeSleep(100);
    digitalWrite(ledPin_7, HIGH); timeSleep(100);
    
    digitalWrite(ledPin_5, LOW); timeSleep(100);  
    digitalWrite(ledPin_6, LOW); timeSleep(100);
    digitalWrite(ledPin_7, LOW); timeSleep(100); 
    */
