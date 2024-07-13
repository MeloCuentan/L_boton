#include <L_boton.h>


// Asignamos el valor del pin y lo configuramos como INPUT_PULLUP

L_boton::L_boton(uint8_t pin) {
  _pin = pin;
  pinMode(_pin, INPUT_PULLUP);
}


// Asignamos el valor del pin , lo configuramos como INPUT_PULLUP y 
// el tiempo que se activa el pulso largo

L_boton::L_boton(uint8_t pin, uint16_t TIEMPO_PULSO_LARGO) {
  _pin = pin;
  _TIEMPO_PULSO_LARGO = TIEMPO_PULSO_LARGO;
  pinMode(_pin, INPUT_PULLUP);
}

L_boton::L_boton(uint8_t pin, uint16_t TIEMPO_PULSO_CORTO, uint16_t TIEMPO_PULSO_LARGO) {
  _pin = pin;
  _TIEMPO_PULSO_CORTO = TIEMPO_PULSO_CORTO;
  _TIEMPO_PULSO_LARGO = TIEMPO_PULSO_LARGO;
  pinMode(_pin, INPUT_PULLUP);
}


// Leemos el estado del pin y si es pulso corto devolvemos 1, 
// si es largo 2 y si no se ha pulsado 0 

uint8_t L_boton::leerEstado() {
  
  uint8_t _respuesta = 0;
  
  _lecturaBoton = digitalRead(_pin);
  
  if ( _lecturaBoton == LOW
       &&
       _lecturaBotonAnterior == HIGH )
  {
    _lecturaBotonAnterior = _lecturaBoton;
    _tiempoInicio = millis();
    _tiempoPulsado = 0;
    _accionBoton = HIGH;
  }

  if ( _lecturaBoton == HIGH
       &&
       _lecturaBotonAnterior == LOW )
  {
    _lecturaBotonAnterior = _lecturaBoton;
    _accionBoton = LOW;
    _tiempoPulsado = millis() - _tiempoInicio;
  }

  if ( _tiempoPulsado > _TIEMPO_ANTI_REBOTE
       &&
       _tiempoPulsado < _TIEMPO_PULSO_CORTO )
  {
    _accionBoton = LOW;
    _tiempoPulsado = 0;
    _respuesta = PULSO_CORTO;
  }

  if ( millis() - _tiempoInicio
       >
       _TIEMPO_PULSO_LARGO && _accionBoton == HIGH )
  {
    _accionBoton = LOW;
    _tiempoPulsado = 0;
    _respuesta = PULSO_LARGO;
  }

    return _respuesta;

}
