#include <NewPing.h>
 
#define TRIGGER_PIN  2
#define ECHO_PIN     3
#define MAX_DISTANCE 200
#define THRESHOLD_DISTANCE 10
#define WAITING_TIME 7000

#define IN1  8
#define IN2  9
#define IN3  10
#define IN4  11

#define LED_PIN 4

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
unsigned long currTime, lastTime;
boolean isDown, isTimerOn;

int Steps = 0;
boolean Direction;// gre
unsigned long last_time;
unsigned long currentMillis ;
int steps_left;
long time;


void setup() {
  Serial.begin(9600);
  digitalWrite(LED_PIN, LOW);
  isDown = true;
  isTimerOn = false;

  pinMode(IN1, OUTPUT); 
  pinMode(IN2, OUTPUT); 
  pinMode(IN3, OUTPUT); 
  pinMode(IN4, OUTPUT); 
  // delay(1000);
  Direction = true;
}

void moveMotor() {
    steps_left=2050;
    Direction=!Direction;
  
    while(steps_left>0){
    currentMillis = micros();
    if(currentMillis-last_time>=1000){
    stepper(1); 
    time=time+micros()-last_time;
    last_time=micros();
    steps_left--;
    }
    }

}

void loop() {
  currTime = millis();

  int dist = sonar.ping_cm();
  
  if (dist <= THRESHOLD_DISTANCE && isDown) {
    Serial.println("UP");    
    isDown = false;
    digitalWrite(LED_PIN, HIGH);
    moveMotor();
    
  } 

  if (dist > THRESHOLD_DISTANCE && !isDown && !isTimerOn) {
    Serial.println("Timer on");
    lastTime = currTime;
    isTimerOn = true;
  }

  if (isTimerOn) {
    Serial.println(currTime - lastTime);
    
    if (currTime - lastTime >= WAITING_TIME) {
        Serial.println("DOWN");
        isTimerOn = false;      
        digitalWrite(LED_PIN, LOW);
        isDown = true;
        moveMotor();
    } 
    if (dist <= THRESHOLD_DISTANCE) {
        Serial.println("Timer off");
        isDown = false;
        isTimerOn = false;  
    }
  }
  delay(150);

}

void stepper(int xw){
  for (int x=0;x<xw;x++){
switch(Steps){
   case 0:
     digitalWrite(IN1, LOW); 
     digitalWrite(IN2, LOW);
     digitalWrite(IN3, LOW);
     digitalWrite(IN4, HIGH);
   break; 
   case 1:
     digitalWrite(IN1, LOW); 
     digitalWrite(IN2, LOW);
     digitalWrite(IN3, HIGH);
     digitalWrite(IN4, HIGH);
   break; 
   case 2:
     digitalWrite(IN1, LOW); 
     digitalWrite(IN2, LOW);
     digitalWrite(IN3, HIGH);
     digitalWrite(IN4, LOW);
   break; 
   case 3:
     digitalWrite(IN1, LOW); 
     digitalWrite(IN2, HIGH);
     digitalWrite(IN3, HIGH);
     digitalWrite(IN4, LOW);
   break; 
   case 4:
     digitalWrite(IN1, LOW); 
     digitalWrite(IN2, HIGH);
     digitalWrite(IN3, LOW);
     digitalWrite(IN4, LOW);
   break; 
   case 5:
     digitalWrite(IN1, HIGH); 
     digitalWrite(IN2, HIGH);
     digitalWrite(IN3, LOW);
     digitalWrite(IN4, LOW);
   break; 
     case 6:
     digitalWrite(IN1, HIGH); 
     digitalWrite(IN2, LOW);
     digitalWrite(IN3, LOW);
     digitalWrite(IN4, LOW);
   break; 
   case 7:
     digitalWrite(IN1, HIGH); 
     digitalWrite(IN2, LOW);
     digitalWrite(IN3, LOW);
     digitalWrite(IN4, HIGH);
   break; 
   default:
     digitalWrite(IN1, LOW); 
     digitalWrite(IN2, LOW);
     digitalWrite(IN3, LOW);
     digitalWrite(IN4, LOW);
   break; 
}
SetDirection();
}
} 
void SetDirection(){
if(Direction==1){ Steps++;}
if(Direction==0){ Steps--; }
if(Steps>7){Steps=0;}
if(Steps<0){Steps=7; }
}
