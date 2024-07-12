#include <stdio.h>
#include <stdlib.h>
#include "liat.h"


int main(int argc, char *argv[])
{
    char *filename = argv[argc-1];
    FILE *fichier = initialisation(filename, "r");

    int nbr = nbr_ligne(filename);

    int n_tail;
    get_args(argv, argc,fichier);

    //tail_n(fichier, nbr, n_tail);

    return (0);
}

