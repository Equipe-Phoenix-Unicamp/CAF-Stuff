#ifndef TRANSCEPTORES_H
#define TRANSCEPTORES_H

#include <Arduino.h>
#include  <SPI.h>
#include "Nrf2401.h"

extern Nrf2401 Radio;
void configura_receptor();
void configura_emissor();
void emite(int valor1, int valor2);
int lerAnalogDir();
int lerAnalogEsq();

#endif //TRANSCEPTORES_H
