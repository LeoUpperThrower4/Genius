#define LED_A 5
#define LED_B 6
#define LED_C 7

#define BUTTON_A 10
#define BUTTON_B 9
#define BUTTON_C 8

#define TEMPO_PISCA 600
#define TEMPO 150

#define QT_SEQ 12
int sorteados[QT_SEQ];

void setup() {
  Serial.begin(9600);

  pinMode(LED_A, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(LED_C, OUTPUT);

  pinMode(BUTTON_A, INPUT_PULLUP);
  pinMode(BUTTON_B, INPUT_PULLUP);
  pinMode(BUTTON_C, INPUT_PULLUP);

  randomSeed(analogRead(0));
}

void loop() {
  digitalWrite(LED_A, HIGH);
  digitalWrite(LED_B, HIGH);
  digitalWrite(LED_C, HIGH);
 
  le_botao();
  digitalWrite(LED_A, LOW);
  digitalWrite(LED_B, LOW);
  digitalWrite(LED_C, LOW);
 
  delay(500);

  
  for (int jogada = 0; jogada < QT_SEQ; jogada ++) {
 
    sorteados[jogada] = random(3);
    pisca_led(sorteados[jogada]);
    delay(TEMPO);
 
  }
  int vez;
  for (vez = 0; vez < QT_SEQ; vez ++) {
    Serial.println(sorteados[vez]);
    if (le_botao() == sorteados[vez]) {
      
      pisca_led(sorteados[vez]);
 
    }
    else {
      pisca_led(sorteados[vez]);
      break;
    }
  } 

  if (vez == QT_SEQ) {
    delay(1000);
    //ganhou
    Serial.println("ganhou");
  }
  else {
    delay(1000);
    //perdeu
    Serial.println("perdeu");
  }
}

void pisca_led(int posicao) {
  Serial.println(posicao);
 
  if (posicao == 0) {
    digitalWrite(LED_A, HIGH);
    delay(TEMPO_PISCA);
    digitalWrite(LED_A, LOW);
  }
  else if (posicao == 1) {
    digitalWrite(LED_B, HIGH);
    delay(TEMPO_PISCA);
    digitalWrite(LED_B, LOW);
  }
  else if (posicao == 2) {
    digitalWrite(LED_C, HIGH);
    delay(TEMPO_PISCA);
    digitalWrite(LED_C, LOW);
  }
  delay(100);
} 

int le_botao () {
 
  int result = -1;
 
  while (result == -1) {
    if (digitalRead(BUTTON_A) == LOW) {
      result = 0;
    }
    else if (digitalRead(BUTTON_B) == LOW) {
      result = 1;
    }
    else if (digitalRead(BUTTON_C) == LOW) {
      result = 2;
    }
  }
  Serial.println(result);
  return result;
}
