#include  <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include "transceptorServices.h"
#include "hBridgeServices.h"
#include "controllerServices.h"

void setup()
{
	Serial.begin(9600);
	configurarRadio(RECEPTOR);
	configurarControle();
}
void loop()
{
	int a = lerAnalogicoDireito();
	Serial.println(a);
	delay(10);
}

