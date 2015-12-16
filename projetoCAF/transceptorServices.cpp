#include "transceptorServices.h"

int msg[1];
int msgr[1];
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
	// msg[0] = 111;
	velo[0] = potenciaEsquerda;
	velo[1] = potenciaDireita;
	radio.write(velo, 2);
}
int lerPotDir(void)
{
	int velo[2];
	while(!radio.read( velo, 2 );
	return velo[0];
}
int lerPotEsq(void)
{
	// int velo[2];
	while ( ! radio.available() );
	if ( radio.available() )
    {
		radio.read( msgr, 1 );
	}
	return msgr[0];
}

