#include "transceptorServices.h"
#include <Arduino.h>
#include  <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

int msg[1];
const uint64_t pipe = 0xE8E8F0F0E1LL;
RF24 radio(9,10);

void configurarRadio(char modo)
{
  radio.begin();
	if ( modo == TRANSMISSOR )
    {
    	radio.openWritingPipe(pipe);
    }
    else
    {
    	radio.openReadingPipe(1,pipe);
		  radio.startListening();
    }
}
void enviarPotencias(int potenciaDireita,int potenciaEsquerda)
{
	int velo[2];
	velo[0] = potenciaEsquerda;
	velo[1] = potenciaDireita;
	radio.write(velo, 2);
}
int lerPotDir(void)
{
	int velo[2];
	while ( ! radio.available() );
	if ( radio.available() )
    {
		radio.read( velo, 2 );
		radio.stopListening();
	}
	return velo[1];
}
int lerPotEsq(void)
{
	int velo[2];
	while ( ! radio.available() );
	if ( radio.available() )
    {
		radio.read( velo, 2 );
		radio.stopListening();
	}
	return velo[0];
}

