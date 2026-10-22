
// устранение дребезга контактов на кнопке 
// программа считывает только первое нажатие, игнорируя лишние 
// регистрирует поcледующее, только если кнопка отпущена до конца

#define button 13

bool lastReading = false;
bool stableState = true;

uint64_t lastDebonuceTime = 0;
uint16_t debonuceDelay = 50;
uint16_t countPressed = 0;

void setup() {
	Serial.begin(9600);
	pinMode(button, INPUT_PULLUP);
}

void button_processing(uint8_t buttonPin) {
  bool btn_status = digitalRead(buttonPin);

  if(btn_status != lastReading) {
	  lastDebonuceTime = millis();
   }
   
  if(millis() - lastDebonuceTime > debonuceDelay) {
	 if(btn_status != stableState) {
		  stableState = btn_status;
		  if(stableState == LOW) {
		     countPressed++;
		     Serial.println(countPressed);
		   }
	   }
   }  
  lastReading = btn_status; 
}

void button_processing_lite(uint8_t buttonPin) {
 //альтернативный, упрощённый вариант:
  bool btn_status = digitalRead(button);
  
  if (stableState == HIGH && btn_status == LOW) {
    countPressed++;
    Serial.println("BUTTON pressed "+String(countPressed));
   }
  stableState = btn_status;
}

void loop() {
  button_processing(button);
}
