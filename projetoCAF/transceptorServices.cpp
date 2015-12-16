#include "transceptorService.h"
#include "Arduino.h"

#ifdef __cplusplus
extern "C" {
#endif

void configurarRadio(char modo)
{
	uint64_t pipes[2] = { 0xF0F0F0F0E1LL, 0xF0F0F0F0D2LL };
	RF24 radio(9,10);
	radio.begin();
	radio.setRetries(15,15);
	if ( modo == TRANSMISSOR )
    {
    	radio.openWritingPipe(pipes[0]);
    }	
    else
    {
    	radio.openReadingPipe(1,pipes[1]);
    }
}
void enviarPotencias(int potenciaDireita,int potenciaEsquerda)
{
	int velo[2];
	velo[0] = potenciaEsquerda;
	velo[1] = potenciaDireita;
	radio.write( &velo, 2*sizeof(int) );
}
int lerPotDir(void)
{
	int velo[2];
	while ( ! radio.available() );
	if ( radio.available() )
    {
		radio.startListening();
		radio.read( &velo, 2*sizeof(int) );
		radio.stopListening();
	}
	return velo[1];
}
int lerPotEsq(void);
{
	int velo[2];
	while ( ! radio.available() );
	if ( radio.available() )
    {
		radio.startListening();
		radio.read( &velo, 2*sizeof(int) );
		radio.stopListening();
	}
	return velo[0];
}	
#ifdef __cplusplus
}
#endif
