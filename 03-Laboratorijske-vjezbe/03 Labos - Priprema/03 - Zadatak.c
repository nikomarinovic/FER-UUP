#include <stdio.h>

int main(void) {
    
    int n,i,j,suma_trenutnog=0,suma_proslog=0, razlika=0;

    printf("Unesite n > ");
    scanf("%d", &n);

    if(!(n>=1 && n<=10)){
        return 0;
    }

    int mat[n][n];

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d", &mat[i][j]);
        }
    }
    
    printf("Rezultat >");
    
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){         
            suma_trenutnog += mat[j][i];
        }

        if(i>0){
            razlika = suma_proslog - suma_trenutnog;
            printf(" %d",razlika);
        } 

        suma_proslog = suma_trenutnog;
        suma_trenutnog = 0;
    }

    razlika = suma_proslog;

    for(j = 0; j < n; j++){
        razlika -= mat[j][0];
    }

    printf(" %d", razlika);
    printf("\n");

    return 0;
}
