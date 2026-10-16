


#define vr_x A0
#define vr_y A1
#define sw 9


int16_t vr_x_data = 0;
int16_t vr_y_data = 0;
int8_t sw_data = 0;

int8_t crd = 0;


void setup() {
  Serial.begin(9600);
  pinMode(sw, INPUT_PULLUP); 
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

void loop() {
  delay(100);

  j_data();

  Serial.println("vr_x: "+String(vr_x_data)+" vr_y: "+String(vr_y_data)+" sw: "+String(sw_data)+"    crd: "+String(crd));

}
