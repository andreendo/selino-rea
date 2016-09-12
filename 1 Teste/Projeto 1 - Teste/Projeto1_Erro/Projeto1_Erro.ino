#define LED1 3
#define LED2 4
#define LED3 5
#define LED4 6
#define POT A5

//Variaveis
int valorPot = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(POT, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);  
}

void loop() {  
  //Lê valor do potenciometro
  valorPot = analogRead(POT);

  //Controla LED 1
  if(valorPot > 255){
    digitalWrite(LED1, HIGH);
  } else{
    digitalWrite(LED2, LOW);
  }

  //Controla LED 2
  if(valorPot > 512){
    digitalWrite(LED3, HIGH);
  } else{
    digitalWrite(LED4, LOW);
  }

  //Controla LED 3
  if(valorPot > 768){
    digitalWrite(LED4, HIGH);
  } else{
    digitalWrite(LED3, LOW);
  }

  //Controla LED 4
  if(valorPot > 1000){
    digitalWrite(LED2, HIGH);
  } else{
    digitalWrite(LED1, LOW);
  }

}
