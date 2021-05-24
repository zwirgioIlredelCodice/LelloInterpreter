#include<stdio.h>
#include"comandi.h"
#include"vm.h"


/*
---------PROGRAMMA
*/
void comando_successivo() {
	p_contatore += 3;
}

/*
---------MEMORIA
*/
void ALLOCA(int indirizzo1, int indirizzo2) {
	mem[indirizzo2] = mem[indirizzo1];
	comando_successivo();
}

void CARICA(int costante, int indirizzo1) {
	mem[indirizzo1] = costante;
	comando_successivo();
}

/*
---------OPERAZIONI
*/
void SOMMA(int indirizzo1, int indirizzo2) {
	mem[0] = mem[indirizzo1] + mem[indirizzo2];
	comando_successivo();
}


/*
---------FLUSSO PROGRAMMA
*/
void VAI(int posizione) {
	p_contatore = posizione * 3; //perchè ogni 3
}

void VAI_VERO(int posizione) {
	if (mem[0] == 1) {
		p_contatore = posizione * 3; //perchè ogni 3
	}
	else {
		comando_successivo();
	}
}

void VAI_FALSO(int posizione) {
	if (mem[0] == 0) {
		p_contatore = posizione * 3; //perchè ogni 3
	}
	else {
		comando_successivo();
	}
}


/*
---------IO
*/
void SCRIVI(int indirizzo1) {
	printf("%d",mem[indirizzo1]);
	comando_successivo();
}

void IMMETTI(int indirizzo1) {
	scanf("%d",&indirizzo1);
	comando_successivo();
}