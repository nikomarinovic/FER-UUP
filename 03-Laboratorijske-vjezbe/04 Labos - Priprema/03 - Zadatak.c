/*
Napišite program koji s tipkovnice učitava dva broja (tipa unsigned short int)
te ispisuje Hammingovu udaljenost za ta dva broja.
Hammingova udaljenost je broj pozicija na kojima se bitovi razlikuju.

Napomena: nije dopušteno koristiti polja (array).
*/

#include <stdio.h>

int main(void) {
    
    unsigned short int br1, br2;
    int i, razlika=0;

    printf("Unesite dva broja > ");
    scanf("%hu %hu", &br1, &br2);

    for(i=0;i<16;i++){
        if(((br1>>i)&1)!=((br2>>i)&1)){
            razlika ++;
        }
    }

    printf("Hammingova udaljenost: %d",razlika);

    return 0;
}
