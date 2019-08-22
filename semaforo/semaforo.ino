#define RED_PIN 53
#define YELLOW_PIN 52
#define GREEN_PIN 51

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
}

void trocarStatus(int tmp_sec, int red, int yellow, int green) {
  digitalWrite(RED_PIN, red);
  digitalWrite(YELLOW_PIN, yellow);
  digitalWrite(GREEN_PIN, green);
  delay(tmp_sec * 1000);
}

void loop() {
  trocarStatus(5, HIGH, LOW, LOW); // turn on red light
  trocarStatus(7, LOW, LOW, HIGH); // turn on green light
  trocarStatus(2, LOW, HIGH, LOW); // turn on green light
}
