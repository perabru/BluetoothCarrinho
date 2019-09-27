// Pinos de controle do motor na Ponte H
#
define IN1 13# define IN2 12# define IN3 11# define IN4 10

// Pinos de controle da velocidade do motor na Ponte H
# define ENA_PIN 6# define ENB_PIN 9

// Velocidade de cada motor
# define M1_VEL 53 // Motor direita
# define M2_VEL 53 // Motor esquerda

//Dado que irá receber do bluetooth
char data = 0;
void frente(void) {
  digitalWrite(IN1, 0);
  digitalWrite(IN2, 1);

  digitalWrite(IN3, 1);
  digitalWrite(IN4, 0);

}

void tras(void) {
  digitalWrite(IN1, 0);
  digitalWrite(IN2, 1);

  digitalWrite(IN3, 0);
  digitalWrite(IN4, 1);
}

void direita(void) {
  digitalWrite(IN1, 0);
  digitalWrite(IN2, 0);

  digitalWrite(IN3, 1);
  digitalWrite(IN4, 0);
}

void esquerda(void) {
  digitalWrite(IN1, 0);
  digitalWrite(IN2, 1);

  digitalWrite(IN3, 0);
  digitalWrite(IN4, 0);
}

void parar(void) {
  digitalWrite(IN1, 0);
  digitalWrite(IN2, 0);

  digitalWrite(IN3, 0);
  digitalWrite(IN4, 0);

}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(ENA_PIN, OUTPUT);
  pinMode(ENB_PIN, OUTPUT);

  analogWrite(ENA_PIN, 127);
  analogWrite(ENB_PIN, 127);

  analogWrite(ENA_PIN, map(M1_VEL, 0, 100, 0, 255));
  analogWrite(ENB_PIN, map(M2_VEL, 0, 100, 0, 255));

  //frente();
  //direita();
  //while(1);
  parar();

}
void loop() {

  if (Serial.available() > 0) {
    data = Serial.read();
    Serial.print(data);
    Serial.print("\n");
    if (data == 'F')
      frente();
    else if (data = 'T')
      tras();
    else if (data = 'D')
      direita();
    else if (data = 'E')
      esquerda();
    else if (data = 'P')
      parar();

  }

}
