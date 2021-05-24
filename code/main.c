#include <stdio.h>
#include <stdlib.h>
#include "lelloVM/vm.h"
#include "lelloASSEBLY/lelloBLER.h"



int main() {
	
    char prova[] = "example/allo.txt";

	int numero_comandi = line_number(prova)+1;

    int* comandi_array;
    comandi_array = calloc(numero_comandi*3,sizeof(int)); //crea un array di int per tnenere tutti i comandi
    if (comandi_array == NULL)
    { 
        printf("non riesco a creare array comandi_array\n");
        return 1;
    }
    
    parse_lelloBLER(prova,comandi_array);

    for (int i=0;i<numero_comandi*3;i++)
    {
        printf("%d ",comandi_array[i]);
    }
	
	esegui(comandi_array);
	
	//debug memoria
	printf("\nmemoria\n");
	for(int i=0;i<50;i++) {
		printf("%d ",mem[i]);
	}
}