#include <stdio.h>
#include <string.h>
#include "vao.h"

void entrer(FILE** fichier,char* filename){
    
    *fichier=fopen(filename,"r");

}
int compte_ligne(FILE* fichier){
    int c=0;
    char ch[2000];
    rewind(fichier);
    while(fgets(ch,1500,fichier) != 0){
            c++;
    // Tsy ato ny return
    }
    return (c);
}
int compte_word(FILE* fichier){
    int c=0;
    int ch;  ///ITO tsy char
    int word;
    rewind (fichier);
    while((ch=fgetc(fichier))!=EOF){
     if(ch==' '||ch=='\t'||ch=='\n'){
        word=0;
     }
     else if(word==0){
        word=1;
        c++;
     }
     }

     return c;
 }
 int caractere(FILE* fichier){
    int c=0; //  Initialisena ny c !!!!!!
    int ch; /// tsy CHAR fa INT
    rewind(fichier); 
    while((ch=fgetc(fichier))!=EOF){
       if('\n'){
        c++;
       }
    }
    return c;
 }
 int octet(FILE* fichier){
    int c=0;
    int ch;
    while((ch=fgetc(fichier))!=EOF){
        c++;
        
    }
    return c;
 }
 int maxligne(FILE* fichier){
    int c=0;
    int tmp;
    char ch[100];
    rewind(fichier);
    while((fgets(ch, 99, fichier)) != NULL){
       for(int i=0;i<'\n';i++){
            for(int j=i+1;i<'\n';j++){
                if(ch[i]<ch[j]){
                    tmp=ch[i];
                    ch[i]=ch[j];
                    ch[j]=tmp;
                    break;
            }

        }
    }

    }
    return strlen(ch);
 }
void sorti(FILE* fichier,char* option){
    int l;
    int w;
    int q;
    int r;
    int s;
    if(strcmp(option,"-l")==0){
        l=compte_ligne(fichier);
        printf("%d",l);
    }
    else if(strcmp(option,"-w")==0){ /// == 0 strcmp
        w=compte_word(fichier);
        printf("%d",w);
    }
     else if(strcmp(option,"-m")==0){
        q=caractere(fichier);
        printf("%d",q);
    }
    else if(strcmp(option,"-c")==0){
        r=octet(fichier);
        printf("%d octet",r);
    }
    else if(strcmp(option,"-L")){
        s=maxligne(fichier);
        printf("%d",s);
    }
}



