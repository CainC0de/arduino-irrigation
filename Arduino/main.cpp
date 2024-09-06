#include <Arduino.h>


const int sensorPin = A0; 
const int valvulaPin = 7; 

int umidadeAtual = 0;
int umidadeAnterior = 0;


const int umidadeMinima = 300; 
const int umidadeMaxima = 600;


const long intervaloVerificacao = 60000; 

int lerUmidade() {
  int leitura = analogRead(sensorPin);
  return map(leitura, 0, 1023, 0, 100); 
}


bool verificarUmidade() {
  return (umidadeAtual >= umidadeMinima && umidadeAtual <= umidadeMaxima);
}

void controlarValvula(bool estado) {
  digitalWrite(valvulaPin, estado ? HIGH : LOW);
}

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(valvulaPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  umidadeAtual = lerUmidade();


  bool dentroDosLimites = verificarUmidade();


  if (dentroDosLimites && !digitalRead(valvulaPin)) {

    delay(intervaloVerificacao);


    umidadeAtual = lerUmidade();


    if (verificarUmidade()) {
      controlarValvula(true);
    }
  } else {

    controlarValvula(false);
  }


  Serial.print("Umidade: ");
  Serial.print(umidadeAtual);
  Serial.print(" %");
  Serial.println();

  delay(30000);
}
