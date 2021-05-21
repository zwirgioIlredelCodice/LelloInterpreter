#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c[100];
    FILE *fptr;
    if ((fptr = fopen("allo.txt", "r")) == NULL)
    {
        printf("Error! File cannot be opened.");
        // Program exits if the file pointer returns NULL.
        exit(1);
    }

    // reads text until newline is encountered
    for (int x=0; x<4; x++)
    {
        fscanf(fptr, "%[^ \n]", c);
        printf("Data from the file:\n%s", c);
    }
    
    fclose(fptr);

    return 0;
}