/* Odreduje je li uneseni broj pozitivan, negativan ili nula. */
#include<stdio.h>

int main (void) {

    int br;

    printf("Upisi broj: ");
    scanf("%d", &br);

    if(br>0){
        printf("Broj je veći od nule.");
    } else if(br < 0){
        printf("Broj je manji od nule.");
    } else {
        printf("Broj je jednak nuli.");
    }

    return 0;
}