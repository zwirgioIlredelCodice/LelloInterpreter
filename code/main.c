#include <stdio.h>
#include <stdlib.h>
#include "lelloVM/vm.h"
#include "lelloASSEBLY/lelloBLER.h"

int main(int argc, char *argv[])
{ //per command line argument
	
	int error=0;
	
    if (argc == 2)
    {
        FILE *fp = fopen(argv[1], "r");
        // Check if file exists
        if (fp == NULL)
        {
            printf("file %s non esistente [ERRORE]\n", argv[1]);
            return -1;
        }
    }
    else if (argc > 2)
    {
        printf("troppi argomenti [ERRORE]\n");
        return -1;
    }
    else
    {
        printf("immetti il nome del file da eseguire [ERRORE]\n");
        return -1;
    }

    printf("eseguzione file %s\n", argv[1]);

    int numero_righe = line_number(argv[1]) + 1;
    int numero_comandi = numero_righe * 3;

    int *comandi_array;
    comandi_array = calloc(numero_comandi, sizeof(int)); //crea un array di int per tnenere tutti i comandi
    if (comandi_array == NULL)
    {
        printf("non riesco a creare array comandi_array [ERRORE]\n");
        return 1;
    }

    error = parse_lelloBLER(argv[1], comandi_array);
	
	//debug programma
	printf("\noutput programma:\n");
    for (int i = 0; i < numero_comandi; i++)
    {
        printf("%d ", comandi_array[i]);
    }
	
	if (error > 0)
	{
		printf("ERROR at parse_lellBLER, exit...\n");
		return 1;
	}

    /*
    ---------ESEGUZIONE
    */
    printf("\noutput esecuzione:\n");
    inizzializza_memoria(50);
    esegui(comandi_array);

    //debug memoria
    printf("\nmemoria\n");
    for (int i = 0; i < grandezza_memoria; i++)
    {
        printf("%d ", (mem[i]));
    }
    
    printf("\n");
}
