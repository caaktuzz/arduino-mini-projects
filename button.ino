// announcement of pins
#define ledPin_4 4 
#define ledPin_5 5
#define ledPin_6 6

#define buttonPin 2

int num = 0;

// delay func
boolean timeSleep(int milliseconds) {
  uint64_t timeStamp = millis();
  while (true) {
    if(millis() - timeStamp >= milliseconds){
      return true;
    }
  }
  return false;
}

void setup () {
  Serial.begin(9600); // start seral-port

  pinMode(ledPin_4, OUTPUT);
  pinMode(ledPin_5, OUTPUT);
  pinMode(ledPin_6, OUTPUT);

  pinMode(buttonPin, INPUT_PULLUP);
}

void loop () {

  Serial.println(num += 1); // output number of cycles

  if (digitalRead(buttonPin) == LOW) { // switch on lightariki
    digitalWrite(ledPin_4, HIGH); timeSleep(100); 
    digitalWrite(ledPin_5, HIGH); timeSleep(100);
    digitalWrite(ledPin_6, HIGH); timeSleep(100);
  }
  else { // swith off lightariki
    digitalWrite(ledPin_4, LOW); timeSleep(100);
    digitalWrite(ledPin_5, LOW); timeSleep(100);
    digitalWrite(ledPin_6, LOW); timeSleep(100);
  }

}

