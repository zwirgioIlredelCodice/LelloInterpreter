#include <stdio.h>
#include"vm.h"
#include "comandi.h"

int p_contatore = 0; //il contatore del programma
int mem[50]; //la memoria disponibile

void esegui(int programma[]) {
	while (programma[p_contatore] != fine) {

		int arg1 = programma[p_contatore+1];
		int arg2 = programma[p_contatore+2];

 		switch (programma[p_contatore])
		{
		case alloca:
			ALLOCA(arg1, arg2);
			break;
		
		case carica:
			CARICA(arg1, arg2);
			break;
		
		case somma:
			SOMMA(arg1, arg2);
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
			IMMETTi(arg1);
		
		case fine:
			break;

		default:
			printf("comando non trovato= %d a %d",programma[p_contatore],p_contatore); //se non è nessuno dei comandi prima
			break;
		}
	}
}