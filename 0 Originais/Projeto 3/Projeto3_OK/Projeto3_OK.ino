/*
  The circuit:
 * LCD RS pin to digital pin 7
 * LCD Enable pin to digital pin 6
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VDD pin to 5V
 * LCD V0 pin to pin 2 POT
 */

#define ldrPin A0
#define ledPin 9

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

int luminosidade;
String input;
bool autoMode = true;

void setup() {  
  lcd.begin(16, 2);   // set up the LCD's number of columns and rows
  lcd.print("Hello world!");

  pinMode(ldrPin, INPUT);
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  if(Serial.available()){
    input = Serial.readString();
    Serial.println(input+">>");
  
    if(input.equals("write")){      
      while(!Serial.available());   //espera receber algo
      input = Serial.readString();
      lcd.clear();  
      lcd.setCursor(0,0);    
      lcd.print(input);      
  
    }else if(input.equals("set")){
      while(!Serial.available()); //espera receber algo
      input = Serial.readString();
      if(input.equals("auto")){
        autoMode = true;
      } else if(input.toInt() > 0 && input.toInt() < 256){  //verificar se é numero entre 1 255
        autoMode = false;      
        analogWrite(ledPin, input.toInt());  //escreve valores entre 0 e 255  
      } else{
        Serial.println("Parametro invalido");
      }
    } else{
      Serial.println("Comando invalido");
    }
  }
  
  lcd.setCursor(0, 1);  //Segunda linha
  lcd.print(millis() / 1000);
  
  if(autoMode){
    luminosidade = analogRead(ldrPin);    //lê valores entre 0 e 1023
    //Serial.println(luminosidade);
    analogWrite(ledPin, luminosidade/4);  //escreve valores entre 0 e 255 
  }
}

