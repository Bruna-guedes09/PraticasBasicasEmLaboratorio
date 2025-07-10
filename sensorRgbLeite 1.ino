// Definindo os pinos do sensor
const int S2 = 6; // Pino de saída
const int S3 = 7; // Pino de saída
const int sensorOut = 8; // Pino para ler o valor de entrada

// Variável de controle do tempo
int cont = 0;

// Variáveis para armazenar os valores das cores
int redValue = 0;
int greenValue = 0;
int blueValue = 0;

void setup() {
  // Configurando os pinos como saída ou entrada
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  Serial.begin(9600); //Inicia monitor serial
}

void loop() {

  while (cont<15) // Realiza as leituras por 15 segundo
  {
    // Detectando a cor vermelha: S2 e S3 com sinal LOW
    digitalWrite(S2, LOW);
    digitalWrite(S3, LOW);
    redValue = pulseIn(sensorOut, LOW); // Leitura da intensidade da cor
  
    // Detectando a cor verde: S2 e S3 com sinal HIGH
    digitalWrite(S2, HIGH);
    digitalWrite(S3, HIGH);
    greenValue = pulseIn(sensorOut, LOW); // Leitura da intensidade da cor
  
    // Detectando a cor azul: S2 com sinal LOW e S3 com sinal HIGH
    digitalWrite(S2, LOW);
    digitalWrite(S3, HIGH);
    blueValue = pulseIn(sensorOut, LOW); // Leitura da intensidade da cor
  
    // Exibindo os valores das cores no monitor serial
    Serial.print("Red: ");
    Serial.print(redValue);
    Serial.print(" Green: ");
    Serial.print(greenValue);
    Serial.print(" Blue: ");
    Serial.println(blueValue);
  
    delay(1000); // Espera de 1 segundo antes de repetir a leitura
  
    cont+=1; // Aumenta o contador -> define o intervalo de tempo
  }
  Serial.print("----------------Ponto de parada-----------");
  cont = 0;
  delay(60000);
}
