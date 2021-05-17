#include <stdio.h>
#include "lelloVM/comandi.h"
#include "lelloVM/vm.h"


void esegui() {
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

int main() {
	int pro[] = {1,666,2,1,222,3,2,2,3,6,0,0,8};
	
	esegui();
	
	printf("\nmemoria\n");
	for(int i=0;i<50;i++) {
		printf("%d ",mem[i]);
	}
}