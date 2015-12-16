#ifndef TRANSCEPTOR_H
#define TRANSCEPTOR_H

#include <Arduino.h>
#include  <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"


#define RECEPTOR 'r'
#define TRANSMISSOR 'e'


extern RF24 radio;
void configurarRadio(char modo);
void enviarPotencias(int potenciaDireita,int potenciaEsquerda);
int lerPotDir(void);
int lerPotEsq(void);

#endif //TRANSCEPTOR_H
