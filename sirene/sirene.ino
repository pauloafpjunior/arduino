#define BUZZER_PIN 8
#define BUTTON_PIN 2
#define BUZZER_TIME 10

int frequency = 0;
boolean toPlay = false;

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), changeStatus, FALLING);
}

void changeStatus() {
  toPlay = !toPlay;
}

void loop() {
  if (toPlay) {
    for (frequency = 150; frequency < 1500; frequency += 1)   {    
      tone(BUZZER_PIN, frequency, BUZZER_TIME);     
      delay(1); 
    }  
  }
  if (toPlay) {
    for (frequency = 1500; frequency > 150; frequency -= 1)   {    
      tone(BUZZER_PIN, frequency, BUZZER_TIME);     
      delay(1);  
    }  
  }
}
