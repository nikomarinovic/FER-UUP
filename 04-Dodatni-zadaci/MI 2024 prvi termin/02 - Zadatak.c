#include <stdio.h>

int main(void) {
    
    int n, i, j, a, b;
    int najv_zbroj = 0, zbroj = 0;
    int prvi = 1;

    printf("Upisite red n > ");
    scanf("%d",&n);

    int mat[n][n];

    printf("Upisite elemente >\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&mat[i][j]);
        }
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            zbroj = mat[i][j];
            if(i > 0 && j > 0){
                zbroj += mat[i-1][j-1];
            }
            if(i > 0 && j < n-1){
                zbroj += mat[i-1][j+1];
            }
            if(prvi == 1){
                najv_zbroj = zbroj;
                prvi = 0;
            }
            if((zbroj >= najv_zbroj) || (zbroj >= najv_zbroj && i >= a) || (zbroj >= najv_zbroj && i == a && j > b)){
                najv_zbroj = zbroj;
                a = i;
                b = j;
            }
            zbroj = 0;
        }
    }

    printf("Najveci zbroj gornje-dijagonalnih elemenata je %d za element (%d, %d)",najv_zbroj, a, b);

    return 0;
}
