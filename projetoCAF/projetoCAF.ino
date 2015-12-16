

 #include  <SPI.h>
 #include "nRF24L01.h"
 #include "RF24.h"
 #include "transceptorServices.h"
 #include "hBridgeServices.h"
 #include "controllerServices.h"

 void setup()
 {
 	pinMode(A1,OUTPUT);
 	configurarRadio(RECEPTOR);
 }
 void loop()
 {
 	int a = lerPotDir();
 	if (a == 2)
 	{
 		digitalWrite(A1,HIGH);
 		delay(1000);
 		digitalWrite(A1,LOW);
 		delay(1000);
 	}
 	else
 	{
 		digitalWrite(A1,HIGH);
 		delay(500);
 		digitalWrite(A1,LOW);
 		delay(500);
 	}
 }

