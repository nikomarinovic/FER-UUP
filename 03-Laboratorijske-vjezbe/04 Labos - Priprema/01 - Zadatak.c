/*
Napišite program koji s tipkovnice učitava broj (tipa unsigned short int)
te ispisuje binarni zapis izmijenjenog broja (bit po bit počevši od najznačajnijeg bita).
Potom program pronalazi i ispisuje indeks (0 do 15) najznačajnijeg bita postavljenog na vrijednost 1.
*/

#include <stdio.h>

int main(void) {
    
    unsigned short int broj;
    int i, indeks=-1;

    printf("Unesite broj > ");
    scanf("%hu",&broj);

    printf("Binarni zapis ucitanog broja: ");

    for(i=15;i>=0;i--){
        printf("%d", (broj>>i)&1);

        if(((broj>>i)&1)==1 && indeks==-1){
            indeks = i;
        }
    }

    printf("\n");

    if(indeks == -1){
        printf("Nema bita s vrijednosti 1.");
    }else{
        printf("Indeks najznacajnijeg bita s vrijednosti 1: %d",indeks);
    }

    return 0;
}