/*
S tipkovnice je potrebno učitati niz znakova (string) niz. Niz neće biti dulji od 50 znakova te ga ne treba provjeravati.
Potrebno je ispisati koji se znak najčešće pojavljuje u nizu niz te koliko se puta ponovio taj znak.
Ukoliko postoji više znakova koji se ponavljaju jednako puta, tada je potrebno ispisati sve znakove,
te njihov broj ponavljanja. Ispis znakova treba biti takav da se prvo ispisuje onaj znak koji ima najmanju vrijednost
u ASCII tablici pa nakon njega znak sa sljedećom najmanjom vrijednosti i tako dalje.
*/


#include <stdio.h>

int main(void) {

    char niz[52];
    int brojac[256] = {0};
    int i;
    int max = 0;
    int broj_znakova = 0;
    int ispisano = 0;
    
    printf("Unesite niz > ");
    fgets(niz,sizeof(niz),stdin);

    for(i=0;niz[i]!='\0';i++){
        if(niz[i]!='\n'){
            brojac[(unsigned char)niz[i]]++;
        }
    }

    for(i=0;i<256;i++){
        if(brojac[i]>max){
            max = brojac[i];
        }
    }

    for(i=0;i<256;i++){
        if(brojac[i]==max){
            broj_znakova ++;
        }
    }

    if(broj_znakova == 1){
        printf("Znak ");
    }else{
        printf("Znakovi ");
    }

    for(i=0;i<256;i++){
        if(brojac[i]==max){
            if(ispisano > 0){
                printf(", ");
            }
            printf("\"%c\"",i);
            ispisano ++;
        }
    }

    if(ispisano == 1){
        printf(" se ponavlja %d puta.\n",max);
    }else{
        printf(" se ponavljaju %d puta.\n",max);
    }
    
    return 0;
}
