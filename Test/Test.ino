#include <L_boton.h>                            // Incluímos libería

// creamos variables para el pulsador 1 y se asignará el tiempo por defecto (1000 ms)
const int pin1 = 12;                          // pin del pulsdor 1
int lecturaPulsador1 = 0;                     // lectura del pulsador 1

// creamos variables para el pulsador 2 y asignamos el tiempo del pulso largo
const int pin2 = 33;                          // pin del pusador 2
const int pulsoLargo2 = 2000;                 // pulso largo del puslador 2
int lecturaPulsador2 = 0;                     // lectura del pulsador 2

// Creamos los botones que se necesiten
L_boton pulsador1(pin1);  
L_boton pulsador2(pin2, pulsoLargo2);

void setup() {
  Serial.begin(115200);                       // Inicializamos el monitor serie
}

void loop() {
  lecturaPulsador1 = pulsador1.leerEstado();  // Guardamos el valor leído del pulsador 1
  lecturaPulsador2 = pulsador2.leerEstado();  // Guardamos el valor leído del pulsador 2

  // Según el valor hacemos una cosa u otra
  if (lecturaPulsador1 == PULSO_CORTO){
    Serial.println("PULSADOR 1 CORTO");
  } else if (lecturaPulsador1 == 2){
    Serial.println("PULSADOR 1 LARGO");
  }
  if (lecturaPulsador2 == PULSO_LARGO){
    Serial.println("PULSADOR 2 CORTO");
  } else if (lecturaPulsador2 == 2){
    Serial.println("PULSADOR 2 LARGO");
  }  
}
