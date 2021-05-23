#include <stdio.h>
#include <string.h>

int main()
{
    char s_alloca[] = "alloca";
    char s_carica[] = "carica";
    char s_somma[] = "somma";
    char s_vai[] = "vai";
    char s_vai_vero[] = "vai_vero";
    char s_via_falso[] = "vai_falso";
    char s_scrivi[] = "scrivi";
    char s_immetti[] = "immetti";
    char s_fine[] = "fine";

    FILE *fp;
    char buff[255];
    char comando[20];
    char arg_1[20];
    char arg_2[20];

    char *token;
    const char delim[2] = " ";

    fp = fopen("allo.txt", "r");
    while (!feof(fp))
    {
        fgets(buff, 255, (FILE *)fp); //leggie una riga del file in buff

        token = strtok(buff, delim); //fa un token quando vede uno spazio
        strcpy(comando,token); //copia la stringa nel comando

        int i=0;
        while (token != NULL) //finchè non sono finiti i token 
        {
            if (i == 1) {
                strcpy(arg_1,token);
            }
            if (i == 2) {
                strcpy(arg_2,token);
            }
            i++;
            token = strtok(NULL, delim);
        }
        if (strcmp(s_carica,comando) == 0) //se il comando è s_carica
        {
            printf("comando = %s, arg_1 = %s, arg_2 = %s",comando,arg_1,arg_2); // un pò di debug
        }
    }
    fclose(fp);
}