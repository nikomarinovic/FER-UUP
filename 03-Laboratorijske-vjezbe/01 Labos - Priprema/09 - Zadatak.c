/*
Napišite program koji učitava dva prirodna broja a i b iz intervala [1, 1000].
Broj a predstavlja najmanju vrijednost,a broj b predstavlja najveću
vrijednost niza prirodnih brojeva [a, b].
*/

#include <stdio.h>

int main(void) {
    
    int a, b, i, zbroj = 0, brojac=1;

    printf("Upisite dva prirodna broja iz intervala [1, 1000] > ");
    scanf("%d %d", &a, &b);

    if((a<1 || a>1000) || (b<1 || b>1000)){
        printf("Brojevi moraju biti u intervalu [1, 1000].");
        return 0;
    }

    if(a > b){
        printf("Prvi broj mora biti manji od drugog broja.");
        return 0;
    }

    for(i=a; i<=b; i++){
        if(brojac % 3 == 0){
            zbroj = zbroj + i;
        }
        brojac++;
    }

    printf("Zbroj svakog treceg broja iznosi: %d", zbroj);

    return 0;
}