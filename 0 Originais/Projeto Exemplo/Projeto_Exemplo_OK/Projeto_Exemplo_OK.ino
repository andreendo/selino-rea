#define BOTAO 2
#define LED1 6    //Vermelho
#define LED2 5    //Amarelo
#define LED3 3    //Verde
#define POT A5

//Variaveis
int valorPot = 0;
int leds[3] = {LED1, LED2, LED3};
int i = 0;
unsigned long lastPressed = 0;
unsigned long btnInterval = 500;

void setup() {
  // put your setup code here, to run once:
  pinMode(POT, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(BOTAO, INPUT);  
}

void loop() {  
  //Lê valor do potenciometro
  valorPot = analogRead(POT);

  //Escreve valor correspondente em PWM na porta (i) do LED
  analogWrite(leds[i], map(valorPot, 0, 1023, 0, 255));

  //Muda led sendo controlado
  if(digitalRead(BOTAO) && ((millis() - lastPressed) > btnInterval)){
    lastPressed = millis();
    if(i<2)
      i++;
    else
      i=0;
  }
}
