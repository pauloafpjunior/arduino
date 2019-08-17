#define ALARME_PIN 13 // fio vermelho
#define TEMPO 10

int frequencia = 0;
int executar = 1;

void setup() {
  pinMode(ALARME_PIN, OUTPUT);
}

void soarAlarme() {
  for (frequencia = 150; frequencia < 1800; frequencia += 1) { // Tone que produz sirene de polícia
    tone(ALARME_PIN, frequencia, TEMPO);
    delay(3);
  }
}

void loop() {
 if (executar == 1) {
  soarAlarme();
  executar = 0;
  digitalWrite(ALARME_PIN, LOW);
 }
}
