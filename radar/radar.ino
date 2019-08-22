#include "NewPing.h"

#define TRIGGER_PIN 10
#define ECHO_PIN 11
#define BUZZER_PIN 12
#define MAX_DISTANCE 3000

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);
}

void loop() {
  int d1 = sonar.ping_cm();
  delay(1000);
  int d2 = sonar.ping_cm();

  Serial.println(d2 - d1);

  if (d2 > 0 && (d2 - d1) > 5) {
    digitalWrite(BUZZER_PIN, HIGH);    
    delay(5000);    
    digitalWrite(BUZZER_PIN, LOW);    
  }
}
