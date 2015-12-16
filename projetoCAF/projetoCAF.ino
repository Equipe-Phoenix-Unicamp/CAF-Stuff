

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
	// Serial.println(radio.available());
	 while (!radio.read(msgg, 1));
	 Serial.println(msgg[0]);
	 // if (radio.available())
// 	 	{
// 	 		radio.read(msgg, 1);
// 	 		Serial.println(msgg[0]);
// 	 		if (msgg[0] == 111)
// 	 		{
// 	 			delay(10);
// 	 		}
// 	 		else
// 	 		{
//
// 	 		}
// 	 		delay(10);
// 	 	}
// 	 	else
// 	 	{
// 	 		Serial.println("No radio available");
// 	 	}
 	// int a = lerPotDir();
	// Serial.println(a);
	// delay(10);
//  	if (a == 2)
//  	{
//  		digitalWrite(A1,HIGH);
//  		delay(1000);
//  		digitalWrite(A1,LOW);
//  		delay(1000);
//  	}
//  	else
//  	{
//  		digitalWrite(A1,HIGH);
//  		delay(500);
//  		digitalWrite(A1,LOW);
//  		delay(500);
//}
 }

