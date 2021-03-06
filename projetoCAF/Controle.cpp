#include "Controle.h"
#include "pins.h"
#include "Arduino.h"

#define tempoInicio     20
#define tempoClk        20
#define tempoEntreByte  20
#define tempoEntreCiclo 40

int psxDado[6]; 
int psxMudou;

int psxCont;

boolean estado = 0;
 
void psxLeControle(void);
void psxGravaByte(int byteDado);
int psxLeByte(void);

void psxLeControle(void)
{
  int psxByte = 0;
  
  digitalWrite(cmd,HIGH);
  digitalWrite(clk,HIGH);
  digitalWrite(att,LOW);
  
  delayMicroseconds(tempoInicio);
  
  psxByte = 1;
  psxGravaByte(psxByte);
  
  psxByte = 66;
  psxGravaByte(psxByte);
  
  psxByte = 0;
  psxGravaByte(psxByte);
  
  for (psxCont = 0; psxCont<6; psxCont++)
    psxDado[psxCont] = psxLeByte();
    
  digitalWrite(att,HIGH);
}

void psxGravaByte(int byteDado)
{
  int c;
  for (c=0;c<=7;c++)
  {
    if(byteDado & (0x01<<c))
      digitalWrite(cmd,HIGH);
    else
      digitalWrite(cmd,LOW);
      
    digitalWrite(clk,LOW);
    delayMicroseconds(tempoClk);
    digitalWrite(clk,HIGH);
    delayMicroseconds(tempoClk);
  }
  digitalWrite(cmd,HIGH);
  delayMicroseconds(tempoEntreByte);
}

int psxLeByte(void)
{
  int aux = 0;
  int c;
  
  for (c=0;c<=7;c++)
  {
    digitalWrite(clk,LOW);
    delayMicroseconds(tempoClk);
    //Serial.println(analogRead(dado));
    if(analogRead(dado) > 400)
      bitClear(aux,c);
    else
      bitSet(aux,c);
    digitalWrite(clk,HIGH);
    delayMicroseconds(tempoClk);
  }
  delayMicroseconds(tempoEntreByte);
  return (aux);
}

void configurarControle(void)
{
    pinMode(cmd,OUTPUT);
    pinMode(att,OUTPUT);
    pinMode(clk,OUTPUT);
    pinMode(dado,INPUT_PULLUP);
}
int lerAnalogicoEsquerdo(void)
{
    psxLeControle();
    delayMicroseconds(20);
	return psxDado[5];
}
int lerAnalogicoDireito(void)
{
    psxLeControle();
    delayMicroseconds(20);
	return psxDado[3];
}
