#include <stdio.h>
#include <stdlib.h>
#include "lelloVM/vm.h"
#include "lelloASSEBLY/lelloBLER.h"



int main(int argc, char *argv[]) { //per command line argument
    if( argc == 2 ) {
        printf("eseguzione file %s\n", argv[1]);
    }
    else if( argc > 2 ) {
        printf("troppi argomenti.\n");
        return -1;
    }
    else {
        printf("immetti il nome del file da eseguire.\n");
        return -1;
    }

	int numero_righe = line_number(argv[1])+1;
    int numero_comandi = numero_righe*3;

    int* comandi_array;
    comandi_array = calloc(numero_comandi,sizeof(int)); //crea un array di int per tnenere tutti i comandi
    if (comandi_array == NULL)
    { 
        printf("non riesco a creare array comandi_array\n");
        return 1;
    }
    
    parse_lelloBLER(argv[1],comandi_array);

    //debug programma
    for (int i=0;i<numero_comandi;i++)
    {
        printf("%d ",comandi_array[i]);
    }
    printf("\noutput programma:\n");
	
	esegui(comandi_array);
	
	//debug memoria
	printf("\nmemoria\n");
	for(int i=0;i<50;i++) {
		printf("%d ",mem[i]);
	}
    printf("\n");
}