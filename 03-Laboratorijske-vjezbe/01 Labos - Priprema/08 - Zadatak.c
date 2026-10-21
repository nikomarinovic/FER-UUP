/*
S tipkovnice učitati neparan cijeli broj n. Ako je učitan paran broj,
ispisati poruku Neispravan·unos! i prekinuti s izvršavanjem programa.
Za učitani broj n, potrebno je ispisati niz znakova *, gdje konačni ispis predstavlja uzorak dijamanta.
Broj n predstavlja najveću duljinu niza *, koji se nalazi na sredini ispisa.
*/

#include <stdio.h>

int main(void) {
    
    int n, i, j;

    printf("Unesite broj > ");
    scanf("%d", &n);

    if(n % 2 == 0){
        printf("Neispravan unos!");
        return 0;
    }

    for(i=1 ; i<=n ; i+=2){
        for(j=0; j < (n-i)/2; j++){
            printf(" ");
        }
        for(j=0; j<i; j++){
            printf("*");
        }
        printf("\n");
    }

    for(i=(n-2) ; i>=1 ; i-=2 ){
        for(j=0; j < (n-i)/2 ; j++){
            printf(" ");
        }
        for(j=0; j<i; j++){
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
