#define SENSOR_PIN A0 // fio vermelho
#define ALARME_PIN 13 // fio vermelho
#define TEMPO 10

int frequencia = 0;


void setup() {
  Serial.begin(9600);
  pinMode(ALARME_PIN, OUTPUT);

}

void soarAlarme() {
  for (frequencia = 150; frequencia < 1800; frequencia += 1) { // Tone que produz sirene de polícia
    tone(ALARME_PIN, frequencia, TEMPO);
    delay(3);
  }
}


void loop() {
  int valorLuz = analogRead(SENSOR_PIN);

  if (valorLuz < 200) {
    soarAlarme();
  }
  digitalWrite(ALARME_PIN, LOW);
  
  delay(100);

}
