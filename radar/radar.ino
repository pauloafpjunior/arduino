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
  int dist1 = sonar.ping_cm();
  delay(1000);
  int dist2 = sonar.ping_cm();
  
  int dist_dif = dist2 - dist1;
  if (dist_dif < 0) dist_dif = dist_dif * (-1);
  
  Serial.print("Dist Dif: ");
  Serial.print(dist_dif);
  Serial.println("cm");      

  if (dist_dif >= 45) {
    analogWrite(BUZZER_PIN, HIGH);
  } else {
    analogWrite(BUZZER_PIN, LOW);        
  }
}
  
