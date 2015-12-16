#ifndef TRANSCEPTOR_H
#define TRANSCEPTOR_H

#define RECEPTOR 'r'
#define TRANSMISSOR 'e'

void configurarRadio(char modo);
void enviarPotencias(int potenciaDireita,int potenciaEsquerda);
int lerPotDir(void);
int lerPotEsq(void);

#endif //TRANSCEPTOR_H
