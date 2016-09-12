#include <Ultrasonic.h>

#define BUZZER 5
#define multiplicadorTempo 20 //cm*multiplicador = intervalo entre bips

Ultrasonic ultrasonic(12,11); // (Trig PIN,Echo PIN)

int distancia;

void setup() {
}

void loop()
{
  distancia = ultrasonic.Ranging(CM);
  delay(50);        //intervalo para leitura do sensor
     
  tone(BUZZER, 2650, 100); //2650Hz 100ms
  delay(distancia*multiplicadorTempo);
}
