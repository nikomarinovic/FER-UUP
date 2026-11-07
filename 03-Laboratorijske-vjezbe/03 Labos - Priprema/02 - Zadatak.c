/*
Napišite program koji će za dvodimenzijsko polje cijelih brojeva s jednakim brojem redaka i stupaca N
(kvadratnu matricu) izračunati sumu svih brojeva koji se nalaze u zadanom retku i stupcu.
Element matrice u kojem se zadani redak i stupac "sijeku" zbraja se samo jedanput.
S tipkovnice program treba učitati prirodni broj N.
Zatim je potrebno s tipkovnice učitati po retcima članove kvadratne matrice.
Na kraju je potrebno učitati redni broj retka i stupca čije elemente zbrajamo (0 je redni broj prvog retka/stupca).
Nije potrebno provjeravati ispravnost unesenih vrijednosti.
*/

#include <stdio.h>

int main(void) {
    
    int m, i, j,r,s,suma=0;

    printf("Upisite broj redaka/stupaca matrice > ");
    scanf("%d", &m);

    int mat[m][m];

    printf("Upisite %dx%d clanova > \n",m,m);
    for(i=0;i<m;i++){
        for(j=0;j<m;j++){
            scanf("%d", &mat[i][j]);
        }
    }

    printf("Upisite redni broj retka > ");
    scanf("%d",&r);

    printf("Upisite redni broj stupca > ");
    scanf("%d",&s);

    for(i=0;i<m;i++){
        suma += mat[r][i];
    }
    for(i=0;i<m;i++){
        if(i != r){
            suma += mat[i][s];
        }
    }

    printf("Suma brojeva koji se nalaze u retku %d i stupcu %d je %d.",r,s,suma);

    return 0;
}
