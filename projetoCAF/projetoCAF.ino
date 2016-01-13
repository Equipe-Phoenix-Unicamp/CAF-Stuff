/*
 * 
 * 
 * 
 */

#include "Transceptor.h"
#include "PonteH.h"
#include "Controle.h"

void setup(void)
{
  configura_receptor();
  configuraMotores();
  Serial.begin(9600);
}
 
void loop(void)
{
  int analog_dir;
  int analog_esq;
  analog_esq = lerAnalogEsq();
  analog_dir = lerAnalogDir();
  Serial.print(analog_esq);
  Serial.print(" , ");
  Serial.print(analog_dir);
  Serial.print("\n");
  potenciaMotorDireito(analog_dir);
  potenciaMotorEsquerdo(analog_esq);
}



/*void setup(void)
{
  configura_emissor();
  configurarControle();
  Serial.begin(9600);
}
 
void loop(void)
{
  int analog_esq;
  int analog_dir;
  analog_esq = lerAnalogicoEsquerdo();
  analog_dir = lerAnalogicoDireito();
  Serial.print(analog_esq);
  Serial.print(" ,, ");
  Serial.print(analog_dir);
  Serial.print("\n");
  emite(analog_esq,analog_dir);
}*/

 
