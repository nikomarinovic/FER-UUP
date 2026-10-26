// oponaša uzorak mete ispunjena 1 i razmacima
// maksimalan unos je 100

#include <stdio.h>

int main(void) {
    
    int n, i, j, x, y, d;
    int m[100][100] = {0};

    printf("Unesi dim kvadratne matrice > ");
    scanf("%d",&n);

    x = y = 0;
    d = n;

    while (d>0) {

        // vodoravni
        for(j=0; j<d; j++){
            m[x][y+j]=1;
            m[x+d-1][y+j]=1;
        }
        // okomiti
        for(i=0; i<d; i++){
            m[x+i][y]=1;
            m[x+i][y+d-1]=1;
        }
        x += 2;
        y += 2;
        d -= 4;
    }

    // ispis matrice
    for (i= 0; i < n; i++) {
        for (j= 0; j < n; j++) {
            if(m[i][j]){
                printf(" X ");
            }else{
                printf("   ");
            }
        }
        printf("\n");
    }

    return 0;
}