#include <stdio.h>

int main(void) {
    
    int m, n, i, j, maks = 0;

    do {
        printf("Unesite m i n: ");
        scanf("%d %d", &m, &n);
    } while (m * n > 100);

    int niz[m][n];

    printf("Unesite elemente matrice:\n");
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            scanf("%d",&niz[i][j]);
        }
    }
    printf("Matrica:\n");
    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){

            maks = 1;

            if(i > 0 && niz[i][j] <= niz[i-1][j]){
                maks = 0;
            }
            if(i < m-1 && niz[i][j] <= niz[i+1][j]){
                maks = 0;
            }
            if(j < n-1 && niz[i][j] <= niz[i][j+1]){
                maks=0;
            }
            if(j > 0 && niz[i][j] <= niz[i][j-1]){
                maks = 0;
            }

            if(maks == 1){
            printf("%4d*",niz[i][j]);
            }else{
                printf("%5d",niz[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}