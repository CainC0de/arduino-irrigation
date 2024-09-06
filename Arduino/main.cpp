#include <Arduino.h>

// Definição dos pinos
const int sensorPin = A0; // Pino de entrada do sensor de umidade
const int valvulaPin = 7; // Pino de saída da válvula de irrigação

// Variáveis para armazenar os valores de umidade
int umidadeAtual = 0;
int umidadeAnterior = 0;

// Limites de umidade para iniciar a irrigação
const int umidadeMinima = 300; // Umidade mínima em que a irrigação será iniciada
const int umidadeMaxima = 600; // Umidade máxima em que a irrigação será interrompida

// Intervalo de tempo entre as verificações de umidade (em milissegundos)
const long intervaloVerificacao = 60000; // 1 minuto

// Função para ler a umidade do solo
int lerUmidade() {
  int leitura = analogRead(sensorPin);
  return map(leitura, 0, 1023, 0, 100); // Mapeia a leitura para um valor entre 0 e 100
}

// Função para verificar se a umidade está dentro dos limites
bool verificarUmidade() {
  return (umidadeAtual >= umidadeMinima && umidadeAtual <= umidadeMaxima);
}

// Função para controlar a válvula de irrigação
void controlarValvula(bool estado) {
  digitalWrite(valvulaPin, estado ? HIGH : LOW);
}

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(valvulaPin, OUTPUT);

  // Inicializa a comunicação serial para depuração
  Serial.begin(9600);
}

void loop() {
  // Lê a umidade atual do solo
  umidadeAtual = lerUmidade();

  // Verifica se a umidade está dentro dos limites
  bool dentroDosLimites = verificarUmidade();

  // Se a umidade está dentro dos limites, verifica se a válvula já está aberta
  if (dentroDosLimites && !digitalRead(valvulaPin)) {
    // Se a válvula já está aberta, mantém-a aberta por um tempo determinado
    delay(intervaloVerificacao);

    // Verifica novamente a umidade do solo
    umidadeAtual = lerUmidade();

    // Se a umidade ainda está dentro dos limites, mantém a válvula aberta
    if (verificarUmidade()) {
      controlarValvula(true);
    }
  } else {
    // Se a umidade não está dentro dos limites ou a válvula já está fechada, fecha a válvula
    controlarValvula(false);
  }

  // Imprime a umidade atual no monitor serial
  Serial.print("Umidade: ");
  Serial.print(umidadeAtual);
  Serial.print(" %");
  Serial.println();

  // Aguarda um tempo antes de fazer a próxima verificação
  delay(30000);
}