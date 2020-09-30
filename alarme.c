//sensor para detectar movimentos
#include<stdio.h>
#include<stdlib.h>

int main ()
{
int LEDp = 13;                  // seleção do pino para o LED
int PINin = 2;                  // seleção do pino de entrada para o sensor PIR
int mov = LOW;                  // inicia-se assumindo nenhum movimento detectado
int val = 0;                    // variável para a leitura do status de saída
int altofalante = 10;           // conexão do buzzer em um pino PWM

void setup() {
  pinMode(LEDp, OUTPUT);        // declara LED como saída
  pinMode(PINin, INPUT);        // declara sensor como entrada
  pinMode(altofalante, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  val = digitalRead(PINin);      // leitura do valor de entrada
  if (val == HIGH) {            // verifica se a entrada possui valor alto
    digitalWrite(LEDp, HIGH);  // ativa o LED
    playTone(300, 160);
    delay(150);


    if (mov == LOW) {
      Serial.println("Movimento detectado!");
      //relatar a mudança de saída, não de estado
      mov = HIGH;
    }
  } else {
      digitalWrite(LEDp, LOW); // desliga o led
      playTone(0, 0);
      delay(300);

      if (mov == HIGH){
      Serial.println("Movimentação encerrada!");
      // relatar a mudança de saída, não de estado
      mov = LOW;
    }
  }
}
// duração em mili segundos, frequência em hertz
void playTone(long duration, int freq) {
    duration *= 1000;
    int period = (1.0 / freq) * 1000000;
    long elapsed_time = 0;
    while (elapsed_time < duration) {
        digitalWrite(altofalante,HIGH);
        delayMicroseconds(period / 2);
        digitalWrite(altofalante, LOW);
        delayMicroseconds(period / 2);
        elapsed_time += (period);
    }
}

}
