#include <stdio.h>
#include "vao.h"
int main(int argc[],char* argv[]){
    char* option=argv[1];
    char* filename=argv[2];
    FILE* fichier;

    entrer(&fichier,filename);
/*     compte_ligne(fichier);
     compte_word(fichier);              /// Tsy tokony appelena tsony
    caractere(fichier); */
    
   sorti(fichier,option);
    
    return 0;

}
