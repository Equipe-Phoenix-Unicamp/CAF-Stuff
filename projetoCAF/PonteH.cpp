#include "PonteH.h"
#include "pins.h"
#include "Arduino.h"

void configuraMotores(void)
{
    pinMode(PWME,OUTPUT);
    pinMode(PWMD,OUTPUT);
	  pinMode(DIRECTIONE,OUTPUT);
    pinMode(DIRECTIOND,OUTPUT);
	  pinMode(ENABLE,OUTPUT);
    pinMode(ERR,INPUT);
	
	  digitalWrite(ENABLE, HIGH);
}

void potenciaMotorDireito(int potencia)
{
  int dir;
  float pwm;
  
    if(potencia > 150)
    {
	    dir = LOW;
      pwm = (potencia - 125) * 1.3;
    }
    else if(potencia < 100)
    {
      dir = HIGH;
      pwm = (125 - potencia) * 1.3;
    }
    else
    {
      pwm = 0;
    }

    if(!digitalRead(ERR))
    {
      digitalWrite(ENABLE, LOW);
      delay(100);
      digitalWrite(ENABLE, HIGH);
    }
    
    analogWrite(PWMD,int(pwm));
    digitalWrite(DIRECTIOND, dir);
    
}

void potenciaMotorEsquerdo(int potencia)
{
  int dir;
  float pwm;
  
    if(potencia > 150)
    {
      dir = LOW;
      pwm = (potencia - 125) * 1.3;
    }
    else if(potencia < 100)
    {
      dir = HIGH;
      pwm = (125 - potencia) * 1.3;
    }
    else
    {
      pwm = 0;
    }

    if(!digitalRead(ERR))
    {
      digitalWrite(ENABLE, LOW);
      delay(100);
      digitalWrite(ENABLE, HIGH);
    }
    Serial.println(pwm);
    analogWrite(PWME,int(pwm));
    digitalWrite(DIRECTIONE, dir);
}
	
