//-------------------------
// File:  test.c
// Comp.: gcc test.c -otest
// Run:   test
//-------------------------
#include <stdio.h>
#include <syslog.h>
#include <string.h>
int main()
{
    char *p;
    int i = 0;
    FILE *fil = fopen("Jurnal.txt", "w");
    for (i = 0; i < 5; i++)
    {
        fprintf(fil, "%d %d %d\n", i, i + 1, i + 2);
    }
    fclose(fil);

    static const char filename[] = "spiaggia1.txt";
    FILE *file = fopen(filename, "w");
    i = 0;
    char sup[3], copy[30];
    if (file != NULL)
    {
        fil = fopen("Jurnal.txt", "r");
        char line[3000];                              /* or other suitable maximum line size */
        while (fgets(line, sizeof line, fil) != NULL) /* read a line */
        {
            strcpy(copy, line);
            sprintf(sup, "%d", ((i % 3)));
            printf("SUP: %s\n", sup);
            p = strtok(line, " ");
            if (strcmp(p, sup) == 0)
            {
                printf("\tLINE: %s\n", copy);
                fprintf(file, "%s", copy);
            }
            i++;
        }
        fclose(file);
        fclose(fil);
        fopen("Jurnal.txt", "w");
        fclose(fil);
    }
    else
    {
        perror(filename); /* why didn't the file open? */
    }
    //Chiudo la connessione
}