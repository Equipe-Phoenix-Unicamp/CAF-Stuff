#include "transceptorServices.h"

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
	velo[1] = potenciaEsquerda;
	velo[0] = potenciaDireita;
	radio.write(velo, 2);
}
int lerPotDir(void)
{
	int velo[2];
	while(!radio.read( velo, 2 ));
	return velo[0];
}
int lerPotEsq(void)
{
	int velo[2];
	while(!radio.read( velo, 2 ));
	return velo[1];
}

