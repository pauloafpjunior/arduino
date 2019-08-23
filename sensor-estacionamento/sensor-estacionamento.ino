#include "NewPing.h"

#define TRIGGER_PIN 50
#define ECHO_PIN 51
#define BUZZER_PIN 8

#define MAX_DISTANCE 300

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER_PIN, OUTPUT);
  analogWrite(BUZZER_PIN, LOW);
}

void loop() {
  delay(50);
  
  int dist = sonar.ping_cm();
  Serial.print("Ping: ");
  Serial.print(dist);
  Serial.println("cm");

  if (dist == 0) {
    analogWrite(BUZZER_PIN, LOW);
  } else if (dist <= 10) {
    analogWrite(BUZZER_PIN, HIGH);
  } else if (dist <= 15) {    
    analogWrite(BUZZER_PIN, HIGH);
    delay(50);
    analogWrite(BUZZER_PIN, LOW);
  } else if (dist <= 20) {    
    analogWrite(BUZZER_PIN, HIGH);
    delay(100);
    analogWrite(BUZZER_PIN, LOW);
  } else if (dist <= 25) {    
    analogWrite(BUZZER_PIN, HIGH);
    delay(200);
    analogWrite(BUZZER_PIN, LOW);
  } else {
    analogWrite(BUZZER_PIN, LOW);
  }
}
