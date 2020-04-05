#define RELE_PIN 8
#define BOTAO_PIN 9


void setup() {
  pinMode(RELE_PIN, OUTPUT);
  pinMode(BOTAO_PIN, OUTPUT);

  digitalWrite(RELE_PIN, HIGH);
  digitalWrite(BOTAO_PIN, HIGH);
  
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(BOTAO_PIN)) {
    Serial.println("DESLigado");
    digitalWrite(RELE_PIN, HIGH);
  } else {
    Serial.println("Ligado");
    digitalWrite(RELE_PIN, LOW);
  }

  delay(150);
}
