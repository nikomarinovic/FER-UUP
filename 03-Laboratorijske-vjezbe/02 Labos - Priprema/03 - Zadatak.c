/*
S tipkovnice učitati vrijednosti za broj redaka m i broj stupaca n dvodimenzijskog cjelobrojnog polja.
Ako vrijednosti m i n nisu jednake, prekinuti s izvršavanjem programa i ispisati odgovarajuću poruku.
Po retcima učitati prirodne brojeve kao vrijednosti članova polja od m redaka i n stupaca.
Nakon što su sve vrijednosti upisane, napisati program koji ispisuje razliku zbroja
kvadrata glavne dijagonalei sporedne dijagonale polja.
*/

#include <stdio.h>

int main(void) {
    
    int m,n,i,j,g=0,s=0,rez=0;

    printf("Unesi dimenzije: ");
    scanf("%d %d",&m,&n);

    int mat[m][n];

    if(m!=n){
        printf("Dimenzije ne odgovaraju kvadratnoj matrici!\n");
        return 0;
    }

    printf("Unesi clanove polja:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&mat[i][j]);
        }
    }

    printf("Odabrana je matrica: \n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf(" %d",mat[i][j]);
        }
        printf("\n");
    }

    for(i=0;i<m;i++){
        g += (mat[i][i])*(mat[i][i]);
    }
    j=n-1;
    for(i=0;i<m;i++){
        s += (mat[i][j])*(mat[i][j]);
        j--;
    }
    
    rez = g - s;

    printf("Razlika zbrojeva je %d.\n",rez);

    return 0;
}
