#include <stdio.h>
#include <stdlib.h>
#include"vm.h"
#include "comandi.h"

int p_contatore = 0; //il contatore del programma
int grandezza_memoria;
int* mem;

void inizzializza_memoria(int grandezza) {
	grandezza_memoria = grandezza;
	mem = calloc(grandezza_memoria,sizeof(int));
}

void esegui(int programma[], int numero_comandi) {
	numero_comandi -=3; // perchè p_contatore parte da zero e numero_comandi da 3
	while (programma[p_contatore] != fine) {
		
		if (p_contatore > numero_comandi -3) {
			printf("accesso a programma[x] inesistente [ERRORE]\n");
			return;
		}

		int arg1 = programma[p_contatore+1];
		int arg2 = programma[p_contatore+2];

 		switch (programma[p_contatore])
		{
		case allocax:
			ALLOCA(arg1, arg2);
			break;
		
		case carica:
			CARICA(arg1, arg2);
			break;
		
		case somma:
			SOMMA(arg1, arg2);
			break;
		
		case sottrai:
			SOTTRAI(arg1, arg2);
			break;

		case moltiplica:
			MOLTIPLICA(arg1, arg2);
			break;
		
		case dividi:
			DIVIDI(arg1, arg2);
			break;
		
		case uguale:
			UGUALE(arg1, arg2);
			break;

		case nonuguale:
			NONUGUALE(arg1, arg2);
			break;

		case minore:
			MINORE(arg1, arg2);
			break;

		case maggiore:
			MAGGIORE(arg1, arg2);
			break;
		
		case minoreuguale:
			MINOREUGUALE(arg1, arg2);
			break;

		case maggioreuguale:
			MAGGIOREUGUALE(arg1, arg2);
			break;

		case vai:
			VAI(arg1);
			break;
		
		case vai_vero:
			VAI_VERO(arg1);
			break;

		case vai_falso:
			VAI_FALSO(arg1);
			break;

		case scrivi:
			SCRIVI(arg1); 
			break;
		
		case immetti:
			IMMETTI(arg1);
		
		case fine:
			break;

		default:
			printf("comando non trovato= %d a %d",programma[p_contatore],p_contatore); //se non è nessuno dei comandi prima
			break;
		}
	}
}