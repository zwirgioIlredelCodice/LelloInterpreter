#pragma once

enum comandi
{
	allocax, //alloca indirizzo in indirizzo x perchè senò rompe 0
	carica, //alloca costante in indirizzo 1

	somma, //somma mem[indirizzo] mem[indirizzo] in mem[0] 2
	sottrai,
	moltiplica,
	dividi,

	e, // mem[0] mem[indirizzo] && mem[indirizzo]
	o, // mem[0] mem[indirizzo] || mem[indirizzo]
	non, // mem[0] mem[indirizzo] ! mem[indirizzo]
	uguale,
	nonuguale,
	minore,
	maggiore,
	minoreuguale,
	maggioreuguale,

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

void SOTTRAI(int indirizzo1, int indirizzo2);

void MOLTIPLICA(int indirizzo1, int indirizzo2);

void DIVIDI(int indirizzo1, int indirizzo2);

void E(int indirizzo1, int indirizzo2);

void O(int indirizzo1, int indirizzo2);

void UGUALE(int indirizzo1, int indirizzo2);

void NONUGUALE(int indirizzo1, int indirizzo2);

void MINORE(int indirizzo1, int indirizzo2);

void MAGGIORE(int indirizzo1, int indirizzo2);

void MINOREUGUALE(int indirizzo1, int indirizzo2);

void MAGGIOREUGUALE(int indirizzo1, int indirizzo2);

void NON(int indirizzo1);

void VAI(int posizione);

void VAI_VERO(int posizione);

void VAI_FALSO(int posizione);

void SCRIVI(int indirizzo1);

void IMMETTI(int indirizzo1);