#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "headers.h"l

void MSR(int n,int* nbr2);
void adresse_reseau(char* ntab,int* nbr,int* nbr2,int n);
char* entrer_ip(){
    char tab[100];
    
    
    printf("entrer l'adresse ip que tu veux savoir");
    scanf("%s",tab);
    char* ntab=(char*)malloc(strlen(tab)+1);
    strcpy(ntab,tab);
    return ntab;

} 

void filtrage_ip(char* ntab,int* nbr,int* nbr2,int n){
    
    char ip[20];
    if (sscanf(ntab, "%15[0-9.]s", ip) == 1) {
        if (sscanf(ip, "%d.%d.%d.%d", &nbr[0],&nbr[1], &nbr[2], &nbr[3]) == 4) {
            if (nbr[0] >= 0 && nbr[0] <= 255 && nbr[1] >= 0 && nbr[1] <= 255 &&
                nbr[2] >= 0 && nbr[2] <= 255 && nbr[3] >= 0 && nbr[3] <= 255) {
                
                    printf("etrer CIDR ");
                    scanf("%d",&n);
                    MSR(n,nbr2);

            } else {
                printf("pas une ip \n");
            }
        } else {
            printf("pas une ip\n");
        }
    } else {
        printf( "pas une ip\n");
    }
}


void MSR(int n,int* nbr2){
    int i;
    int j=31;
    unsigned int mask=0;
    
    for(i=0 ; i < n ; i++){
        mask=(unsigned int) mask+ pow(2,j);
        j--;
        
   
}
    
     nbr2[0]=(mask/(256*256*256))%256;
     nbr2[1]=(mask/(256*256))%256;
    nbr2[2]=(mask/(256))%256;
    nbr2[3]=mask%256;

    printf("MSR: %d.%d.%d.%d\n",nbr2[0], nbr2[1], nbr2[2], nbr2[3]); 
    //adresse_reseau(nbr,nbr2,n,ntab)
   
    } 


void adresse_reseau(char* ntab,int* nbr,int* nbr2,int n){
    
    int i;
    int nbr3[100];
    
    for(i=0;i < 4;i++){
        nbr3[i] = nbr[i] & nbr2[i];
    }
    for(i=0;i < 4;i++){
        printf("%d",nbr3[i]);
    }
}

void adresse_broadcast(int* nbr, int* nbr2) {
    int masque_inversé[4];
    int adresse_broadcast[4];
    
    
    
    for (int i = 0; i < 4; i++) {
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


