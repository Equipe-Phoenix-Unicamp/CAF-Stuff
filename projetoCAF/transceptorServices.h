#ifndef TRANSCEPTOR_H
#define TRANSCEPTOR_H

#include <Arduino.h>
#include  <SPI.h>
#include "Nrf2401.h"

#define RECEPTOR 'r'
#define TRANSMISSOR 'e'


extern Nrf2401 Radio;
void configurarRadio(char modo);
void enviarPotencias(int potenciaDireita,int potenciaEsquerda);
int lerPotDir(void);
int lerPotEsq(void);

#endif //TRANSCEPTOR_H
