#include <stdio.h>
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
	copy_zwdata(&mem[address1], &mem[address2]); //copy zwdata address1 in zwdata address2
	comando_successivo();
}

void CARICA(int data, int address1) {
	int_to_zwdata(data, &mem[address1]); //now int only
	comando_successivo();
}

/*
---------OPERAZIONI
*/
void SOMMA(int address1, int address2, int dest) {
	add_zwdata(&mem[address1], &mem[address2], &mem[dest]); //add zwdata add1, add2 in dest
	comando_successivo();
}

void SOTTRAI(int address1, int address2, int dest) {
	subtract_zwdata(&mem[address1], &mem[address2], &mem[dest]); //subtract zwdata add1, add2 in dest
	comando_successivo();
}

void MOLTIPLICA(int address1, int address2, int dest) {
	multiply_zwdata(&mem[address1], &mem[address2], &mem[dest]); //multiply zwdata add1, add2 in dest
	comando_successivo();
}

void DIVIDI(int address1, int address2, int dest) {
	divide_zwdata(&mem[address1], &mem[address2], &mem[dest]); //divide zwdata add1, add2 in dest
	comando_successivo();
}

/*
---------OPERATORI LOGICI
*/
void E(int address1, int address2, int dest) {
	int i = and_zwdata(&mem[address1], &mem[address2]);
	int_to_zwdata(i, &mem[dest]);
	comando_successivo();
}

void O(int address1, int address2, int dest) {
	int i = and_zwdata(&mem[address1], &mem[address2]);
	int_to_zwdata(i, &mem[dest]);
	comando_successivo();
}

void NON(int address1, int dest) {
	int i = not_zwdata(&mem[address1]);
	int_to_zwdata(i, &mem[dest]);
	comando_successivo();
}

void UGUALE(int address1, int address2, int dest) {
	int i = equal_zwdata(&mem[address1], &mem[address2]);
	int_to_zwdata(i, &mem[dest]);
	comando_successivo();
}

void NONUGUALE(int address1, int address2, int dest) {
	int i = notequal_zwdata(&mem[address1], &mem[address2]);
	int_to_zwdata(i, &mem[dest]);
	comando_successivo();
}

void MINORE(int address1, int address2, int dest) {
	int i = less_zwdata(&mem[address1], &mem[address2]);
	int_to_zwdata(i, &mem[dest]);
	comando_successivo();
}

void MAGGIORE(int address1, int address2, int dest) {
	int i = great_zwdata(&mem[address1], &mem[address2]);
	int_to_zwdata(i, &mem[dest]);
	comando_successivo();
}

void MINOREUGUALE(int address1, int address2, int dest) {
	int i = lessequal_zwdata(&mem[address1], &mem[address2]);
	int_to_zwdata(i, &mem[dest]);
	comando_successivo();
}

void MAGGIOREUGUALE(int address1, int address2, int dest) {
	int i = greatequal_zwdata(&mem[address1], &mem[address2]);
	int_to_zwdata(i, &mem[dest]);
	comando_successivo();
}

/*
---------FLUSSO PROGRAMMA
*/
void VAI(int index) {
	p_contatore = index * 4 - 4; //perchè ogni 4
}

void VAI_VERO(int address1, int index) {
	int i = get_first_zwdata_digit(&mem[address1]);
	if (i == 1) {
		p_contatore = index * 4 - 4; //perchè ogni 4
	}
	else {
		comando_successivo();
	}
}

void VAI_FALSO(int address1, int index) {
	int i = get_first_zwdata_digit(&mem[address1]);
	if (i == 0) {
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
	print_zwdata(&mem[address1]);
	comando_successivo();
}

void IMMETTI(int address1) { //only int for now
	int data;
	scanf("%d",&data);
	int_to_zwdata(data, &mem[address1]);
	comando_successivo();
}