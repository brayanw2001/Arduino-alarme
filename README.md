




# Alarme com sensor de presença
![](https://i.imgur.com/DlURK1L.png)


 **Figura 1: representação do circuito no software Tinkercad**


___
## Introdução

>O trabalho desenvolvido trata-se de um sistema de alarme de presença, o qual é disparado quando detecta algo ou alguém em movimento dentro do seu raio de ação. Esse mesmo circuito também pode ser utilizado em câmeras de segurança ou alarmes comuns. Foi utilizado um Arduino Uno R3 para que os códigos fossem armazenados no sistema do alarme.

___

## Descrição do sistema

>A alma do sistema está no Arduino, o qual possibilita integração entre hardware e software. Além dele, faz-se imprescindível a utilização de uma protoboard para que seja efetuada de forma simples e prática a construção do circuito almejado. Os demais componentes eletrônicos utilizados estão listados abaixo e o esclarecimento de suas funções acontecem naturalmente ao decorrer do relatório.

* LED para indicar o funcionamento
* Resistor p/ o LED
* Sensor PIR (sensor de movimento de presença)
* Buzzer para emitir o sinal de movimento detectado

___
## Fluxograma
			    
![](https://i.imgur.com/zwtMq4A.png)


___

## Programação



>No bloco abaixo demonstra-se as variáveis utilizadas, as quais são relacionadas com a portas/pinos do Arduino. Suas respectivas funções estão explicadas individualmente nos comentários ao lado das variáveis.

```csharp=
int LEDp = 13;                  // seleção do pino para o LED
int PINin = 2;                  // seleção do pino de entrada para o sensor PIR
int mov = LOW;                  // inicia-se assumindo nenhum movimento detectado
int val = 0;                    // variável para a leitura do status de saída
int altofalante = 10;           // conexão do buzzer em um pino PWM
```

>Em void setup () definimos os pinos de entrada ou saída do Arduino. Em seguida, temos uma função loop que é responsável pela leitura do estado fornecido pelo Sensor PIR, e, caso esse estado seja alto (if), o buzzer será disparado nos parâmetros estabelecidos e o LED acenderá

```csharp=
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
```

>Relacionado com o bloco anterior, aqui temos uma estrutura if-else onde, num primeiro momento, temos que nenhum movimento foi detectado. A partir do momento em que se detecta algo e mov = HIGH, teremos impresso em texto ASCII na porta serial a mensagem de “movimento detectado!”. Do contrário, o sistema de alerta (composto por LED e Buzzer) irá desativar.

```csharp=
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
```

Os códigos abaixo definem os parâmetros do buzzer

```csharp=
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
```


___
[Link da simulação no TinkerCad](https://www.tinkercad.com/things/4Qvv4X0yHkm-alarme-com-sensor-pir/editel)



