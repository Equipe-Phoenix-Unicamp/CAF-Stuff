#include "PonteH.h"
#include "pins.h"
#include "Arduino.h"

void configuraMotores(void)
{
    pinMode(PWME,INPUT);
    pinMode(PWMD,INPUT);
	  pinMode(DIRECTIONE,OUTPUT);
    pinMode(DIRECTIOND,OUTPUT);
	  pinMode(ENABLE,OUTPUT);
    pinMode(ERR,INPUT);
	
	  digitalWrite(ENABLE, HIGH);
}

void potenciaMotorDireito(int potencia)
{
  int direction;
  int pwm;
  
  if(digitalRead(ERR))
  {
    if(potencia > 150)
    {
	    direction = HIGH;
      pwm = int((potencia - 125) * 1.5);
    }
    else if(potencia < 100)
    {
      direction = LOW;
      pwm = int((125 - potencia) * 1.5);
    }
    else
    {
      pwm = 0;
    }
    analogWrite(PWMD,pwm);
    digitalWrite(DIRECTIOND, direction);
  }
  else
  {
    digitalWrite(ENABLE, LOW);
    delay(100);
    digitalWrite(ENABLE, HIGH);
  }
}

void potenciaMotorEsquerdo(int potencia)
{
  int direction;
  int pwm;
  
  if(digitalRead(ERR))
  {
    if(potencia > 150)
    {
      direction = LOW;
      pwm = int((potencia - 125) * 1.5);
    }
    else if(potencia < 100)
    {
      direction = HIGH;
      pwm = int((125 - potencia) * 1.5);
    }
    else
    {
      pwm = 0;
    }
    analogWrite(PWMD,pwm);
    digitalWrite(DIRECTIOND, direction);
  }
  else
  {
    digitalWrite(ENABLE, LOW);
    delay(100);
    digitalWrite(ENABLE, HIGH);
  }
}
	
