#include <Ultrasonic.h>

#define BUZZER 5
#define multiplicadorTempo 10000 //cm*multiplicador = intervalo entre bips

Ultrasonic ultrasonic(12,11); // (Trig PIN,Echo PIN)

int distancia;

void setup() {
}

void loop()
{
  distancia = ultrasonic.Ranging(CM);
  delay(50); //intervalo para leitura do sensor
  
  if(distancia < 51){ //apita abaixo de 50 cm
    delay((int)(multiplicadorTempo/distancia));    
  }  
  tone(BUZZER, 2650, 100); //2650Hz 100ms
  
}
