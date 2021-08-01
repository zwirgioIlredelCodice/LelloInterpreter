#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../lelloVM/comandi.h"
#include "lelloBLER.h"

int line_number(char nome_file[])
{
    FILE *fp;
    int count = 0; // Line counter (result)
    char c;        // To store a character read from file

    // Get file name from user. The file should be
    // either in current folder or complete path should be provided

    // Open the file
    fp = fopen(nome_file, "r");

    // Check if file exists
    if (fp == NULL)
    {
        printf("Could not open file %s", nome_file);
        return (-1);
    }

    // Extract characters from file and store in character c
    for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n') // Increment count if this character is newline
            count = count + 1;

    // Close the file
    fclose(fp);
    return count;
}

int parse_lelloBLER(char nome_file[], int comandi_array[])
{
    int p_comandi_array = 0;

    FILE *fp;

    char buff[100];
    char comando[20];
    char arg_1[20];
    char arg_2[20];

    int n_comando;
    int n_arg_1;
    int n_arg_2;

    char *token;
    const char delim[2] = " ";

    fp = fopen(nome_file, "r");

    if (fp == NULL)
    {
        printf("Could not open file %s", nome_file);
    }

    while (!feof(fp))
    {
        fgets(buff, 100, (FILE *)fp); //leggie una riga del file in buff

        token = strtok(buff, delim); //fa un token quando vede uno spazio
        strcpy(comando, token);      //copia la stringa nel comando

        int i = 0;
        while (token != NULL) //finchè non sono finiti i token
        {
            if (i == 1)
            {
                strcpy(arg_1, token);
            }
            if (i == 2)
            {
                strcpy(arg_2, token);
            }
            i++;
            token = strtok(NULL, delim);
        }
        n_arg_1 = atoi(arg_1);
        n_arg_2 = atoi(arg_2);

        if (strcmp("carica", comando) == 0) //se il comando è s_carica
        {
            n_comando = carica;
        }
        else if (strcmp("alloca", comando) == 0) 
        {
            n_comando = allocax;
        }
        else if (strcmp("somma", comando) == 0) 
        {
            n_comando = somma;
        }
        else if (strcmp("sottrai", comando) == 0) 
        {
            n_comando = sottrai;
        }
        else if (strcmp("moltiplica", comando) == 0) 
        {
            n_comando = moltiplica;
        }
        else if (strcmp("dividi", comando) == 0) 
        {
            n_comando = dividi;
        }
        else if (strcmp("e", comando) == 0)
        {
            n_comando = e;
        }
        else if (strcmp("o", comando) == 0)
        {
            n_comando = o;
        }
        else if (strcmp("non", comando) == 0)
        {
            n_comando = non;
        }
        else if (strcmp("uguale", comando) == 0)
        {
            n_comando = uguale;
        }
        else if (strcmp("nonuguale", comando) == 0)
        {
            n_comando = nonuguale;
        }
        else if (strcmp("minore", comando) == 0)
        {
            n_comando = minore;
        }
        else if (strcmp("maggiore", comando) == 0)
        {
            n_comando = maggiore;
        }
        else if (strcmp("minoreuguale", comando) == 0)
        {
            n_comando = minoreuguale;
        }
        else if (strcmp("maggioreuguale", comando) == 0)
        {
            n_comando = maggioreuguale;
        }
        else if (strcmp("vai", comando) == 0) 
        {
            n_comando = vai;
        }
        else if (strcmp("vai_vero", comando) == 0) 
        {
            n_comando = vai_vero;
        }
        else if (strcmp("via_falso", comando) == 0) 
        {
            n_comando = vai_falso;
        }
        else if (strcmp("scrivi", comando) == 0) 
        {
            n_comando = scrivi;
        }
        else if (strcmp("immetti", comando) == 0) 
        {
            n_comando = immetti;
        }
        else if (strcmp("fine", comando) == 0) 
        {
            n_comando = fine;
        }
        else {
            printf("comando non trovato a comando %d\n",p_comandi_array);
            return 1;
        }
        //lo mette nel array
        comandi_array[p_comandi_array] = n_comando;
        p_comandi_array++;
        comandi_array[p_comandi_array] = n_arg_1;
        p_comandi_array++;
        comandi_array[p_comandi_array] = n_arg_2;
        p_comandi_array++;
    }
    fclose(fp);
}
