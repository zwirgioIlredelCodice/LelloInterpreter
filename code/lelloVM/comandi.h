#pragma once

enum comandi
{
	allocax, //alloca indirizzo in indirizzo x perchè senò rompe 0
	carica, //alloca costante in indirizzo 1

	somma, //somma mem[indirizzo] mem[indirizzo] in mem[0] 2

	vai,	   //va a n comando 3
	vai_vero,  //vai a n coamdo se mem[0] = 1 *vero* 4
	vai_falso, //vai a n coamdo se mem[0] = 0 *falso* 5
 
	scrivi,	 //scrive mem[indirizzo] 6
	immetti, //imput in indirizzo 7

	fine, //fine programma 8
};

void comando_successivo();

void ALLOCA(int indirizzo1, int indirizzo2);

void CARICA(int costante, int indirizzo1);

void SOMMA(int indirizzo1, int indirizzo2);

void VAI(int posizione);

void VAI_VERO(int posizione);

void VAI_FALSO(int posizione);

void SCRIVI(int indirizzo1);

void IMMETTI(int indirizzo1);