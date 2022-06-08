/*  
    LIBRERÍA PARA CONTROLAR DOS ESTADOS DE UN PULSDOR (PULSO CORTO O PULSO LARGO)

    Al usar la librería, hay que añadir el pin que se use y el tiempo que se
  quiera poner para activar el pulso largo, de lo contrario, se usará 1sg que es
  el tiempo por defecto

    La libería devolverá:
    - 0 si no se ha pulsado
    - 1 si es un pulso corto (menor a 500 ms)
    - 2 si es un pulso largo (mayor a 1000 ms o el tiempo que se especifique)

*/


#ifndef L_boton_h
#define L_boton_h
#include "Arduino.h"


class L_boton {

  private:

    uint8_t pin;                                      // pin para usar el botón
    uint8_t  TIEMPO_ANTI_REBOTE = 25;                 // tiempo del anti rebote
    uint16_t TIEMPO_PULSO_CORTO = 500;                // menor a este tiempo será un pulso corto
    uint16_t TIEMPO_PULSO_LARGO = 1000;               // mayor a este tiempo será un pulso largo (tiempo por defecto)
    bool lecturaBoton;                                // variable donde guardamos la lectura del botón
    bool lecturaBotonAnterior = HIGH;                 // lectura del botón anterior
    bool accionBoton = LOW;                           // variable para saber si el botón ha cambiado
    uint32_t tiempoInicio;                            // contador de tiempo
    uint16_t tiempoPulsado;                           // medimos el tiempo que se ha pulsado

  public:

    L_boton(uint8_t pin);                               // función básica, solo el pin y tiempo por defecto
    L_boton(uint8_t pin, uint16_t TIEMPO_PULSO_LARGO);  // pin más el tiempo de activación largo
    uint8_t leerEstado();                             // leer estado del botón

};

#endif
