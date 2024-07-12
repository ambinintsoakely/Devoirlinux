#include <stdio.h>
#include <stdlib.h>
#include "liat.h"
#include <string.h>

FILE *initialisation(char *A, char* mode)
{
    FILE *a = NULL;
    a = fopen(A, mode);
    if (a==NULL)
    {
        printf("Erreur");
        exit(1);
    }
    return a;
}

void get_args(char **argv, int argc, FILE *file)
{
   int i;
    for ( i=1; i<argc-2; i++){
        if (strcmp(argv[i], "-v") == 0)
        {
            printf("%s \n", argv[argc-1]);
        }
        if (strcmp(argv[i], "-n") == 0)
        {
            int nbr = nbr_ligne(argv[argc-1]);
            int n_arg = atoi(argv[i+1]);
            if (!(n_arg))
            {
                printf("Arguments invalides");
                exit(1);
            }
            tail_n(file, nbr, n_arg);
        }

        if (strcmp(argv[i], "-c") == 0)
        {
            int nbr = count_words(argv[argc-1]);
            int c_arg = atoi(argv[i+1]);
            if (!(c_arg))
            {
                printf("Arguments invalides");
                exit(1);
            }
            tail_c(file, nbr, c_arg);
        }

        if (strcmp(argv[i], "-f") == 0)
        {
            while (1)
            {
                FILE *file_tmp = NULL;
                file_tmp = initialisation(argv[argc-1], "r");
                int nbr = nbr_ligne(argv[argc-1]);
                tail_n(file_tmp, nbr, 4);
                fclose(file_tmp);
                
            }
        }
    }
}

void free_tab(char **tab, int nbr)
{
    int i;
    for (i=0; i<nbr; i++)
    {
        free(tab[i]);
    }
    free(tab);
}

void tail_n(FILE *fic, int nbr, int n)
{
    int i=0;
    char ligne[255];

    while (!feof(fic))
    {
        i++;
        fgets(ligne, 254, fic);
        if (i >= nbr-n && i < nbr)
        {
            printf("=> %s", ligne);
        }
    }
    rewind(fic);
}
void tail_c(FILE *fic, int nbr, int c)
{
    int i=0;
    int l;

    while ((l=fgetc(fic)) != EOF )
    {
        i++;
        if (i > nbr-c)
        {
            printf("%c", l);
        }
    }
    rewind(fic);

}


int nbr_ligne(char *name)
{
    int c = 0;
    char l[255];
    FILE *a = NULL;
    a = fopen(name, "r");
    if (a==NULL)
    {
        printf("Erreur ouverture");
        exit(1);
    }
    while (!feof(a))
    {
        fgets(l, 254, a);
        c++;
    }
    fclose(a);
    return c;
}
int count_words(char *name)
{
    int c = 0;
    int l;
    FILE *a = NULL;
    a = fopen(name, "r");
    if (a==NULL)
    {
        printf("Erreur ouverture");
        exit(1);
    }
    while ((l=fgetc(a)) != EOF)
    {
        c++;
    }
    fclose(a);
    return c;
}