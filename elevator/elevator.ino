#include <Stepper.h>

const int stepsPerRevolution = 2018;  // passos por volta
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);            

void setup() {
  myStepper.setSpeed(3);
  
}

void loop() {
  myStepper.step(500);
  delay(1000);
}
