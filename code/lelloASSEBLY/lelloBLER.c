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

void parse_lelloBLER(char nome_file[], int comandi_array[])
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

    fp = fopen("allo.txt", "r");
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
        if (strcmp("carica", comando) == 0) //se il comando è s_carica
        {
            n_comando = carica;
            n_arg_1 = atoi(arg_1);
            n_arg_2 = atoi(arg_2);
        }
        else if (strcmp("alloca", comando) == 0) 
        {
            n_comando = alloca;
            n_arg_1 = atoi(arg_1);
            n_arg_2 = atoi(arg_2);
        }
        else if (strcmp("somma", comando) == 0) 
        {
            n_comando = somma;
            n_arg_1 = atoi(arg_1);
            n_arg_2 = atoi(arg_2);
        }
        else if (strcmp("vai", comando) == 0) 
        {
            n_comando = vai;
            n_arg_1 = atoi(arg_1);
            n_arg_2 = 0;
        }
        else if (strcmp("vai_vero", comando) == 0) 
        {
            n_comando = vai_vero;
            n_arg_1 = atoi(arg_1);
            n_arg_2 = 0;
        }
        else if (strcmp("via_falso", comando) == 0) 
        {
            n_comando = vai_falso;
            n_arg_1 = atoi(arg_1);
            n_arg_2 = 0;
        }
        else if (strcmp("scrivi", comando) == 0) 
        {
            n_comando = vai_vero;
            n_arg_1 = atoi(arg_1);
            n_arg_2 = 0;
        }
        else if (strcmp("immetti", comando) == 0) 
        {
            n_comando = immetti;
            n_arg_1 = atoi(arg_1);
            n_arg_2 = 0;
        }
        else if (strcmp("fine", comando) == 0) 
        {
            n_comando = fine;
            n_arg_1 = 0;
            n_arg_2 = 0;
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