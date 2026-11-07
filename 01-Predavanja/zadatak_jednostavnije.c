#include <stdio.h>

int main(void) {
    
    int br, suma=0;

    printf("Unesite prirodan broj > ");
    scanf("%d", &br);

    // zadnja znamenka
    suma += (br % 10);

    // prva znamenka

    while(br>=10){
        br /= 10;
    }

    suma += br;

    printf("Suma prve i zadnje znamenke broja iznosi: %d", suma);

    return 0;
}