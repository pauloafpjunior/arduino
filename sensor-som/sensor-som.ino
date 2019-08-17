#define SENSOR_PIN 9 // fio vermelho
#define FAN_PIN 31 // fio vermelho

bool fanStatus = false;

void setup() {
  Serial.begin(9600);
  pinMode(SENSOR_PIN, INPUT);  
  pinMode(FAN_PIN, OUTPUT);
}

void loop() {
  bool som = digitalRead(SENSOR_PIN);
  if (!som) {
    if (!fanStatus) {
      digitalWrite(FAN_PIN, HIGH);
      fanStatus = true;
    } else {
      digitalWrite(FAN_PIN, LOW);
      fanStatus = false;      
    }
    delay(500);
  }
}
