#include  <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
#include "transceptorServices.h"
#include "hBridgeServices.h"
#include "controllerServices.h"

int msgg[1];
void setup()
{
	Serial.begin(9600);
	pinMode(A1,OUTPUT);
	configurarRadio(RECEPTOR);
}
void loop()
{
	int a = lerPotDir();
	Serial.println(a);
	delay(10);
}

