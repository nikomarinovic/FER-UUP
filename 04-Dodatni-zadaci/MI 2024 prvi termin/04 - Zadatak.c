#include <stdio.h>

unsigned int funkcija(unsigned int broj);

int main(void) {

    unsigned int broj;
    int i;
    
    printf("Unesite broj > ");
    scanf("%u",&broj);

    printf("\nBroj binarno: ");
    for(i = 31 ; i>=0 ; i--){
        printf("%d",(broj>>i)&1);
    }

    broj = funkcija(broj);

    printf("\nObrnuti binarno: ");
    for(i = 31 ; i>=0 ; i--){
        printf("%d",(broj>>i)&1);
    }
    printf("\n");
    printf("Obrnuti dekadski: %u",broj);


    return 0;
}

unsigned int funkcija(unsigned int broj){
    unsigned int obrnuti = 0;
    int i;

    for(i=0;i<32;i++){
        obrnuti = obrnuti<<1;
        if(broj&1){
            obrnuti += 1;
        }
        broj = broj >> 1;
    }

    return obrnuti;
}