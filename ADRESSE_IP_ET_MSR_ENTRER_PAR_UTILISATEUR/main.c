#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bangiro.h"


int main(void){
    
    char* ntab=enter();
    char msr[100];
    int nbr[100];
    int nbr2[100];

    test(ntab,msr,nbr);
    sortir(msr,nbr,nbr2);
    //adresse_reseau(nbr,nbr2);
    adresse_broadcast(nbr, nbr2);
     
     return 0;
}
