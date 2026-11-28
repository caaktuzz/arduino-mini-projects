#define LED_PIN 2

// Функция принимает ссылку на переменную времени и желаемый интервал
bool isTimerReady(unsigned long &prevTime, unsigned long interval) {
  unsigned long currentTime = millis();
  if (currentTime - prevTime >= interval) {
    prevTime = currentTime; // сброс 0таймера для следующего круга
    return true;            // если время прошло
  }
  return false;             // если еще не прошло
}

// переменные времени для разных задач
unsigned long ledTimer = 0;
unsigned long sensorTimer = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
  if (isTimerReady(ledTimer, 500)) { // задача 1
    Serial.println("делаем");
    //digitalWrite(LED_PIN, !digitalRead(LED_PIN));
  }
  
  if (isTimerReady(sensorTimer, 3000)) { // задача 2
    Serial.println("Прошло 3 секунды. Опрашиваю датчик...");
  }
}
