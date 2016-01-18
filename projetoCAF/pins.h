#ifndef PIN_H
#define PIN_H

/*
0 - H
1 - H
2 - H
3 - H
4 - Contr
5 - H
6 - H
7 - Contr
8 - Contr
9 - Transcep 
10 - Transcep 
11 - Transcep
12 - Transcep
13 - Transcep
*/

/*
 *  DR1 = 2  (digital pin 2)
 *  CE  = 3
 *  CS  = 4
 *  CLK = 5
 *  DAT = 6
 */

#define cmd	7    // Laranja        
#define att	13   // Amarelo     
#define clk	8   // Azul
#define dado	A0    // Marrom

#define ENABLE  8
#define PWMD	9
#define PWME  10
#define ERR	11
#define DIRECTIONE	12
#define DIRECTIOND	13


/*
	11, 12, e 13 para os sinais MOSI, MISO e SCK, respectivamente. Os pinos CSN e CE serão ligados aos pinos 7 e 8
*/


#endif //PIN_H
