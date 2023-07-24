#include <L_boton.h>


// Asignamos el valor del pin y lo configuramos como INPUT_PULLUP

L_boton::L_boton(uint8_t _pin) {
  pin = _pin;
  pinMode(pin, INPUT_PULLUP);
}


// Asignamos el valor del pin , lo configuramos como INPUT_PULLUP y 
// el tiempo que se activa el pulso largo

L_boton::L_boton(uint8_t _pin, uint16_t _TIEMPO_PULSO_LARGO) {
  pin = _pin;
  TIEMPO_PULSO_LARGO = _TIEMPO_PULSO_LARGO;
  pinMode(pin, INPUT_PULLUP);
}

L_boton::L_boton(uint8_t _pin, uint16_t _TIEMPO_PULSO_CORTO, uint16_t _TIEMPO_PULSO_CORTO) {
  pin = _pin;
  TIEMPO_PULSO_CORTO = _TIEMPO_PULSO_CORTO;
  TIEMPO_PULSO_LARGO = _TIEMPO_PULSO_LARGO;
  pinMode(pin, INPUT_PULLUP);
}


// Leemos el estado del pin y si es pulso corto devolvemos 1, 
// si es largo 2 y si no se ha pulsado 0 

uint8_t L_boton::leerEstado() {
  
  uint8_t respuesta = 0;
  
  lecturaBoton = digitalRead(pin);
  
  if ( lecturaBoton == LOW
       &&
       lecturaBotonAnterior == HIGH )
  {
    lecturaBotonAnterior = lecturaBoton;
    tiempoInicio = millis();
    tiempoPulsado = 0;
    accionBoton = HIGH;
  }

  if ( lecturaBoton == HIGH
       &&
       lecturaBotonAnterior == LOW )
  {
    lecturaBotonAnterior = lecturaBoton;
    accionBoton = LOW;
    tiempoPulsado = millis() - tiempoInicio;
  }

  if ( tiempoPulsado > TIEMPO_ANTI_REBOTE
       &&
       tiempoPulsado < TIEMPO_PULSO_CORTO )
  {
    accionBoton = LOW;
    tiempoPulsado = 0;
    respuesta = PULSO_CORTO;
  }

  if ( millis() - tiempoInicio
       >
       TIEMPO_PULSO_LARGO && accionBoton == HIGH )
  {
    accionBoton = LOW;
    tiempoPulsado = 0;
    respuesta = PULSO_LARGO;
  }

    return respuesta;

}
