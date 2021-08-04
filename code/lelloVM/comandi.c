#include <stdio.h>
#include "comandi.h"
#include "vm.h"
#include "zwdata.h"


/*
---------PROGRAMMA
*/
void comando_successivo() {
	p_contatore += 4;
}

/*
---------MEMORIA
*/
void COPY(int address1, int address2) {
	mem[address1] = mem[address2];
	comando_successivo();
}

void CARICA(int data, int address1) {
	mem[address1] = data;
	comando_successivo();
}

/*
---------OPERAZIONI
*/
void SOMMA(int address1, int address2, int dest) {
	mem[dest] = mem[address1] + mem[address2];
	comando_successivo();
}

void SOTTRAI(int address1, int address2, int dest) {
	mem[dest] = mem[address1] - mem[address2];
	comando_successivo();
}

void MOLTIPLICA(int address1, int address2, int dest) {
	mem[dest] = mem[address1] * mem[address2];
	comando_successivo();
}

void DIVIDI(int address1, int address2, int dest) {
	mem[dest] = mem[address1] / mem[address2];
	comando_successivo();
}

/*
---------OPERATORI LOGICI
*/
void E(int address1, int address2, int dest) {
	mem[dest] = mem[address1] && mem[address2];
	comando_successivo();
}

void O(int address1, int address2, int dest) {
	mem[dest] = mem[address1] || mem[address2];
	comando_successivo();
}

void NON(int address1, int dest) {
	mem[dest] = !(mem[address1]);
	comando_successivo();
}

void UGUALE(int address1, int address2, int dest) {
	mem[dest] = (mem[address1] == mem[address2]);
	comando_successivo();
}

void NONUGUALE(int address1, int address2, int dest) {
	mem[dest] = (mem[address1] != mem[address2]);
	comando_successivo();
}

void MINORE(int address1, int address2, int dest) {
	mem[dest] = (mem[address1] < mem[address2]);
	comando_successivo();
}

void MAGGIORE(int address1, int address2, int dest) {
	mem[dest] = (mem[address1] > mem[address2]);
	comando_successivo();
}

void MINOREUGUALE(int address1, int address2, int dest) {
	mem[dest] = (mem[address1] <= mem[address2]);
	comando_successivo();
}

void MAGGIOREUGUALE(int address1, int address2, int dest) {
	mem[dest] = (mem[address1] >= mem[address2]);
	comando_successivo();
}

/*
---------FLUSSO PROGRAMMA
*/
void VAI(int index) {
	p_contatore = index * 4 - 4; //perchè ogni 4
}

void VAI_VERO(int index, int dest) {
	if (mem[dest] == 1) {
		p_contatore = index * 4 - 4; //perchè ogni 4
	}
	else {
		comando_successivo();
	}
}

void VAI_FALSO(int index, int dest) {
	if (mem[dest] == 0) {
		p_contatore = index * 4 - 4; //perchè ogni 4
	}
	else {
		comando_successivo();
	}
}

/*
---------IO
*/
void SCRIVI(int address1) {
	printf("%d",mem[address1]);
	comando_successivo();
}

void IMMETTI(int address1) {
	scanf("%d",&address1);
	comando_successivo();
}