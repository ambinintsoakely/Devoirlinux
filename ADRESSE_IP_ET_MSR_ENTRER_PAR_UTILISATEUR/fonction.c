#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bangiro.h"

char* enter(){

    char tab[100];
    
    printf("entrer l'adresse IP");
    scanf("%s",tab);
    char* ntab=(char*)malloc(strlen(tab)+1);
    strcpy(ntab,tab);
    
    return ntab;

}

void test(char* ntab,char* msr,int* nbr)
{
    
    char ip[20];
    
    if(sscanf(ntab,"%15[0-9.]",ip) == 1){
        if(sscanf(ip,"%d.%d.%d.%d",&nbr[0],&nbr[1],&nbr[2],&nbr[3]) == 4){
            if (nbr[0] >= 0 && nbr[0] <= 255 && nbr[1] >= 0 && nbr[1] <= 255 &&nbr[2] >= 0 && nbr[2] <= 255 && nbr[3] >= 0 && nbr[3] <= 255) {
      
            printf("entrer MSR");
            scanf("%s",msr);    
            }
    else{
        printf("pas une ip");
    }

        }
    else{
        printf("pas une ip");
    }
    }
    else{
        printf("pas une ip");
    }
        
}

void sortir(char* msr, int* nbr, int* nbr2) {
    char ip[20];
    
    if (sscanf(msr, "%15[0-9.]", ip) == 1) {
        if (sscanf(ip, "%d.%d.%d.%d", &nbr2[0], &nbr2[1], &nbr2[2], &nbr2[3]) == 4) {
            int valid = 1; 

            for (int i = 0; i < 4; i++) {
                if (nbr2[i] != 0 &&
                    nbr2[i] != 128 &&
                    nbr2[i] != 192 &&
                    nbr2[i] != 224 &&
                    nbr2[i] != 240 &&
                    nbr2[i] != 248 &&
                    nbr2[i] != 252 &&
                    nbr2[i] != 254 &&
                    nbr2[i] != 255) {
                    valid = 0; 
                    break;
                }
            }

            if (valid) {
                adresse_reseau(nbr, nbr2);
            } else {
                printf("Invalid MSR\n");
            }
        } else {
            printf("Invalid MSR\n");
        }
    } else {
        printf("Invalid MSR\n");
    }
}


void adresse_reseau(int* nbr,int* nbr2)
{
    
    int nbr3[100];
    int i;

   
    for(i=0 ; i < 4;i++)
    {
    nbr3[i]= nbr[i] & nbr2[i];
    }
    
    for(i=0;i < 4; i++){
        printf("%d.",nbr3[i]);
    }
}


void adresse_broadcast(int* nbr, int* nbr2) {
    int masque_inversé[4];
    int adresse_broadcast[4];
    int i=0;
    
    
    for ( i = 0; i < 4; i++) {
        masque_inversé[i] = 255 - nbr2[i];
    }
    
    
    for (int i = 0; i < 4; i++) {
        adresse_broadcast[i] = nbr[i] + masque_inversé[i];
        
        
        if (adresse_broadcast[i] > 255) {
            adresse_broadcast[i] = 255;
        }
    }
    
    printf("Adresse de diffusion : %d.%d.%d.%d\n", adresse_broadcast[0], adresse_broadcast[1], adresse_broadcast[2], adresse_broadcast[3]);
}





