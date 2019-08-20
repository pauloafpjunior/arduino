#include "NewPing.h"

#define TRIGGER_PIN 10
#define ECHO_PIN 11
#define BUZZER_PIN 12
#define MAX_DISTANCE 20

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);
}

void loop() {
  int distance = sonar.ping_cm();
  Serial.print("Ping: ");
  Serial.print(distance);
  Serial.println("cm");

  if (distance > 0 && distance < 7) {
    digitalWrite(BUZZER_PIN, HIGH);    
  } else {
    digitalWrite(BUZZER_PIN, LOW);    
  }
  delay(50); 

}
