#include <Keypad.h> //INCLUSÃO DE BIBLIOTECA

#define PIN_BUZZER 52
  
const byte qtdLinhas = 4; //QUANTIDADE DE LINHAS DO TECLADO
const byte qtdColunas = 4; //QUANTIDADE DE COLUNAS DO TECLADO

//CONSTRUÇÃO DA MATRIZ DE CARACTERES
char matriz_teclas[qtdLinhas][qtdColunas] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};


byte PinosqtdLinhas[qtdLinhas] = {3, 4, 5, 6}; //PINOS UTILIZADOS PELAS LINHAS
byte PinosqtdColunas[qtdColunas] = {8, 9, 10,11}; //PINOS UTILIZADOS PELAS COLUNAS

char passwd[4];
int index;

//INICIALIZAÇÃO DO TECLADO
Keypad meuteclado = Keypad( makeKeymap(matriz_teclas), PinosqtdLinhas, PinosqtdColunas, qtdLinhas, qtdColunas); 

void setup(){
  pinMode(PIN_BUZZER, OUTPUT);
  index = 0;
  
  Serial.begin(9600); //INICIALIZA A SERIAL
  Serial.println("Aperte uma tecla..."); //IMPRIME O TEXTO NO MONITOR SERIAL
  Serial.println(); //QUEBRA UMA LINHA NO MONITOR SERIAL
}
  
void loop(){
  char tecla_pressionada = meuteclado.getKey(); //VERIFICA SE ALGUMA DAS TECLAS FOI PRESSIONADA
  digitalWrite(PIN_BUZZER, LOW);
  
  if (tecla_pressionada){ //SE ALGUMA TECLA FOR PRESSIONADA, FAZ
    if (index == 4) index = 0;
    
    if (tecla_pressionada != '*') {
      passwd[index] = tecla_pressionada;
      index++;    
      //digitalWrite(PIN_BUZZER, HIGH);
      //delay(500);
    } else if (tecla_pressionada == '*') {
      
      
      if (passwd[0] == '1' && passwd[1] == '2' && passwd[2] == '3' && passwd[3] == '4') {
        Serial.println("Ok"); //IMPRIME O TEXTO NO MONITOR SERIAL
        for (int i = 0; i< 5; i++) {
          digitalWrite(PIN_BUZZER, HIGH);
          delay(200);
          digitalWrite(PIN_BUZZER, LOW);
          delay(200);
        }

      } else {
        Serial.println("err"); //IMPRIME O TEXTO NO MONITOR SERIAL
        buzz(PIN_BUZZER, 3951, 500);
      
      }
      index = 0;
    }

  
  }
}

void buzz(int targetPin, long frequency, long length) {
  digitalWrite(13, HIGH);
  long delayValue = 1000000 / frequency / 2;
  long numCycles = frequency * length / 1000;
  for (long i = 0; i < numCycles; i++) {
    digitalWrite(targetPin, HIGH);
    delayMicroseconds(delayValue);
    digitalWrite(targetPin, LOW);
    delayMicroseconds(delayValue);
  }
  digitalWrite(13, LOW);
 
}
