#pragma once

enum comandi
{
	alloca, //alloca indirizzo in indirizzo
	carica, //alloca costante in indirizzo

	somma, //somma mem[indirizzo] mem[indirizzo] in mem[0]

	vai,	   //va a n comando
	vai_vero,  //vai a n coamdo se mem[0] = 1 *vero*
	vai_falso, //vai a n coamdo se mem[0] = 0 *falso*

	scrivi,	 //scrive mem[indirizzo]
	immetti, //imput in indirizzo

	fine, //fine programma
};

void comando_successivo();

void ALLOCA(int indirizzo1, int indirizzo2);

void CARICA(int costante, int indirizzo1);

void SOMMA(int indirizzo1, int indirizzo2);

void VAI(int posizione);

void VAI_VERO(int posizione);

void VAI_FALSO(int posizione);

void SCRIVI(int indirizzo1);

void IMMETTi(int indirizzo1);