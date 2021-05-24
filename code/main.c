#include <stdio.h>
#include "lelloVM/vm.h"
#include "lelloASSEBLY/lelloBLER.h"



int main() {
	
	int numero_comandi = line_number("allo.txt");

    int* comandi_array;
    comandi_array = calloc(numero_comandi*3,sizeof(int)); //crea un array di int per tnenere tutti i comandi
    if (comandi_array == NULL)
    { 
        printf("non riesco a creare array comandi_array\n");
        return 1;
    }
    
    parse_lelloBLER("allo.txt",comandi_array);

	//debug programma
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