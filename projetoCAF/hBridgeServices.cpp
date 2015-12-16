#include "pins.h"
#include "Arduino.h"

#ifdef __cplusplus
extern "C" {
#endif

void configuraMotores()
{
    pinMode(PWME,INPUT);
    pinMode(PWMD,INPUT);
	pinMode(DIRECTIONE,OUTPUT);
    pinMode(DIRECTIOND,OUTPUT);
	pinMode(ENABLE,OUTPUT);
    pinMode(ERROR,INPUT);
	
	digitalWrite(ENABLE, HIGH);
}

void potenciaMotorDireito(int potencia)
{
	int direction = potencia>0?HIGH:LOW;
	int pwm = potencia<0?-potencia:potencia;
	analogWrite(PWMD,pwm);
	digitalWrite(DIRECTIOND, direction);
}

void potenciaMotorEsquerdo(int potencia)
{
	int direction = potencia>0?HIGH:LOW;
	int pwm = potencia<0?-potencia:potencia;
	analogWrite(PWME,pwm);
	digitalWrite(DIRECTIONE, direction);
}
	
#ifdef __cplusplus
}
#endif