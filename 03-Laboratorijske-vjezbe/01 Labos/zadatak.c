#include <stdio.h>

int main(void) {
    
    int br, nbr, suma = 0, n = 0;

    printf("Unesite prirodan broj > ");
    scanf("%d", &br);

    nbr = br;

    while(nbr!=0){
        nbr = nbr / 10;
        n++;
    }

    if(n==1){
        suma = br * 2;
    }else{
        for(int i = 1; i<=n; i++){
            if(i==1){
                suma = suma + (br % 10);
            }
            if(i==n){
                suma = suma + (br % 10);
            }
            br = br / 10;
        }
    }

    printf("Suma prve i zadnje znamenke broja iznosi: %d", suma);

    return 0;
}