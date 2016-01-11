#include "transceptorServices.h"

//const uint64_t pipe = 0xE8E8F0F0E1LL;
//RF24 radio(9,10);
Nrf2401 Radio;

void configurarRadio(char modo)
{
	if ( modo == TRANSMISSOR )
    {
    	Radio.remoteAddress = 1;
    	Radio.txMode(2);
    }
    else
    {
    	Radio.localAddress = 1;
    	Radio.rxMode(2);
    }
}

void enviarPotencias(int potenciaDireita,int potenciaEsquerda)
{
	int velo[2];
	velo[1] = potenciaEsquerda;
	velo[0] = potenciaDireita;
	Radio.data[0] = velo[0];
	Radio.data[1] = velo[1];
	Radio.write();
}

int lerPotDir(void)
{
	while(!Radio.available());
	Radio.read();
	return Radio.data[0];
}

int lerPotEsq(void)
{
	while(!Radio.available());
	Radio.read();
	return Radio.data[1];
}

