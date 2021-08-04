#pragma once

enum comandi
{
	copy, //alloca indirizzo in indirizzo x perchè senò rompe 0
	carica, //carica costante in indirizzo 1

	somma, //somma mem[indirizzo] mem[indirizzo] in mem[0] 2
	sottrai,
	moltiplica,
	dividi,

	e, // mem[0] mem[indirizzo] && mem[indirizzo]
	o, // mem[0] mem[indirizzo] || mem[indirizzo]
	non, // mem[0] = !mem[indirizzo]
	uguale,
	nonuguale,
	minore,
	maggiore,
	minoreuguale,
	maggioreuguale,

	vai,	   //va a n comando 
	vai_vero,  //vai a n coamdo se mem[0] = 1 *vero* 
	vai_falso, //vai a n coamdo se mem[0] = 0 *falso* 
 
	scrivi,	 //scrive mem[indirizzo] 
	immetti, //imput in indirizzo 

	fine, //fine programma 
};

void comando_successivo();

void ALLOCA(int address1, int address2);

void CARICA(int data, int address1);

void SOMMA(int address1, int address2, int dest);

void SOTTRAI(int address1, int address2, int dest);

void MOLTIPLICA(int address1, int address2, int dest);

void DIVIDI(int address1, int address2, int dest);

void E(int address1, int address2, int dest);

void O(int address1, int address2, int dest);

void UGUALE(int address1, int address2, int dest);

void NONUGUALE(int address1, int address2, int dest);

void MINORE(int address1, int address2, int dest);

void MAGGIORE(int address1, int address2, int dest);

void MINOREUGUALE(int address1, int address2, int dest);

void MAGGIOREUGUALE(int address1, int address2, int dest);

void NON(int address1, int dest);

void VAI(int index);

void VAI_VERO(int index, int dest);

void VAI_FALSO(int index, int dest);

void SCRIVI(int address1);

void IMMETTI(int address1);