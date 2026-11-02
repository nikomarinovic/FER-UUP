/*
S tipkovnice učitati cijeli broj n koji predstavlja broj redaka i stupaca dvodimenzionalnog polja.
Po retcima učitati cijele brojeve kao vrijednosti članova polja.
U drugo polje jednakih dimenzija upisati elemente jednake elementima prvog polja rotiranog za
90 stupnjeva u smjeru kazaljke na satu. Ispisati dobiveno polje.
*/

#include <stdio.h>

int main(void) {
    
    int n,i,j;

    printf("Unesite dimenzije polja: ");
    scanf("%d", &n);

    int niz[n][n];
    int niz2[n][n];

    printf("Unesite elemente polja: \n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&niz[i][j]);
        }
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            niz2[j][n - 1 - i] = niz[i][j];
        }
    }

    printf("Izracunato polje: \n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",niz2[i][j]);
        }
        printf("\n");
    }

    return 0;
}