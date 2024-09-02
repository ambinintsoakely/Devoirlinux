
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "headers.h"

int main(){
    
    int nbr[4];
    int nbr2[4];
    int n;

    char* ntab=entrer_ip();
    filtrage_ip(ntab,nbr,nbr2, n);
    printf("%d",n);
    //MSR(n,nbr2);
    adresse_reseau(ntab,nbr,nbr2,n);
    adresse_broadcast(nbr, nbr2);
    free(ntab);

    
    return 0;
    }