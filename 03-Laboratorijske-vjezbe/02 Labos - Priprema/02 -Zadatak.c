/*
S tipkovnice učitati cijeli broj n koji predstavlja broj elemenata u polju.
Nakon toga učitati n cijelih brojeva u polje. Svaki od elemenata zamijeniti zbrojem
tog elementa i elemenata većih indeksa od trenutnog.
Nakon izračuna ispisati dobiveno polje.
*/

#include <stdio.h>

int main(void) {
    
    int n,i,j,suma=0,rez=0;

    printf("Unesite duljinu polja: ");
    scanf("%d",&n);

    int niz[n];

    printf("Unesite elemente polja:\n");
    for(i=0;i<n;i++){
        scanf("%d",&niz[i]);
    }

    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            suma += niz[j];
        }
        rez = suma + niz[i];
        niz[i]=rez;
        rez = 0;
        suma = 0;
    }

    printf("Izracunato polje:");
    for(i=0;i<n;i++){
        printf(" %d",niz[i]);
    }

    return 0;
}