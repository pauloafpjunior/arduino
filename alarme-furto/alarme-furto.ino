#include "IRremote.h"
#include "TimerOne.h"

#define IRREC_PIN 2

IRrecv irrecv(IRREC_PIN);     
decode_results results;   

volatile bool systemStatus;
volatile bool firstRead;

void keyPressed() {
  if (irrecv.decode(&results)) {
    keyCheck(); 
    irrecv.resume(); // receive the next value
  }
}

void alarmCheck() {
  if (firstRead) {
      firstRead = false;
      Serial.println("Leu pos1");   
  } else {
      Serial.println("Leu pos2");   
  }  
}

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  irrecv.enableIRIn(); 
  attachInterrupt(digitalPinToInterrupt(IRREC_PIN), keyPressed, CHANGE);
  systemStatus = false;
  firstRead = true;
  Timer1.initialize(5000000);
  Timer1.attachInterrupt(alarmCheck); 
  Timer1.stop();
}

void loop() {
  if (systemStatus) {
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);                       // wait for a second
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    delay(1000); 
  } else {
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  }
}

void keyCheck() {
  switch(results.value) {
    case 0xFF22DD: 
      systemStatus = true;        
      Timer1.start();
      Serial.println("Start timer");   
      break;
    case 0xFFC23D: 
      systemStatus = false; 
      Timer1.stop();
      Serial.println("Stop timer");   
      break;
  }
} 
