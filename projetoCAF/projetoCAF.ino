#include  <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include "transceptorServices.h"
#include "hBridgeServices.h"
#include "controllerServices.h"

void setup()
{
	configurarRadio(RECEPTOR);
	configurarControle();
	configuraMotores();
}
void loop()
{
	potenciaMotorDireito(200);
}

