#include <Stepper.h>

#define BTN_UP 52
#define BTN_DOWN 53

const int stepsPerRevolution = 200;  // passos por volta
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);            

void setup() {
  pinMode(BTN_UP, INPUT_PULLUP);  
  pinMode(BTN_DOWN, INPUT_PULLUP);
  myStepper.setSpeed(60);
  Serial.begin(9600);
}

bool handleButton(int BTN) {
  if (digitalRead(BTN) == LOW) {
    return true;
  }
  return false;  
}

void loop() {
  if (handleButton(BTN_UP)) {
    myStepper.step(stepsPerRevolution);
  }
  
  if (handleButton(BTN_DOWN)) {
    myStepper.step(-stepsPerRevolution);
  }
  
  delay(500);  
}
