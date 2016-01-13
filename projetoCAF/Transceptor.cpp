#include "Transceptor.h"

Nrf2401 Radio;

void configura_receptor()
{
  Radio.localAddress = 1;
  Radio.rxMode(3);
}

void configura_emissor()
{
  Radio.remoteAddress = 1;
  Radio.txMode(3);
}

void emite(int valor1, int valor2)
{
  Radio.data[0] = valor1;
  Radio.data[1] = valor2;
  Radio.data[2] = 0;
  Radio.write(); 
  delay(30);
}

int lerAnalogDir()
{
  while(!Radio.available());
  Radio.read();
  return (Radio.data[0]);
}

int lerAnalogEsq()
{
  while(!Radio.available());
  Radio.read();
  return (Radio.data[1]);
}
