#define LED1 52
#define LED2 53
#define SENSOR 8

void changeLedStatus(int newStatus) {
  digitalWrite(LED1, newStatus);
  digitalWrite(LED2, newStatus);  
}

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(SENSOR, INPUT);

  changeLedStatus(LOW);
}


void loop() {
  if (digitalRead(SENSOR) == LOW) {
    changeLedStatus(LOW);    
  } else {
    changeLedStatus(HIGH);
  }
  
  delay(500);
}
