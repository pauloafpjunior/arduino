#include "IRremote.h"

#define BUZZER_PIN 8
#define IRREC_PIN 2

IRrecv irrecv(IRREC_PIN);     
decode_results results;   

int frequency = 0;
volatile boolean toPlay;

void keyPressed() {
  if (irrecv.decode(&results)) {
    keyCheck(); 
    irrecv.resume();
  }
}

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  toPlay = false;
  irrecv.enableIRIn(); 
  
  attachInterrupt(digitalPinToInterrupt(IRREC_PIN), keyPressed, CHANGE);
}

void loop() {

  if (toPlay) {
    digitalWrite(LED_BUILTIN, HIGH);
    analogWrite(BUZZER_PIN, HIGH);
    delay(500) ;
    analogWrite(BUZZER_PIN, LOW);
    digitalWrite(LED_BUILTIN, LOW);
  }
  delay(500);
}

void keyCheck() {
  switch(results.value) {
    case 0xFF22DD: 
      toPlay = true;              
      break;
    case 0xFFC23D: 
      toPlay = false;        
      break;
  }
} 
