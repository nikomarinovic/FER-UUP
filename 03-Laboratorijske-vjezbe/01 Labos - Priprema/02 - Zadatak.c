/*
S tipkovnice učitati prirodni broj koji predstavlja količinu novca u kunama.
Na zaslon ispisati kombinaciju kovanica od 5, 2 i 1 kune koje čine taj iznos.
Kovanice je potrebno odabrati tako da je ukupan broj kovanica minimalan.
*/

#include <stdio.h>

int main(void) {
    
    int kn, pet, dva, jedan;

    printf("Upisite iznos u kn > ");
    scanf("%d",&kn);

    printf("Kovanice:");

    pet = kn / 5;
    kn = kn % 5;
    
    dva = kn / 2;
    kn = kn % 2;

    jedan = kn;

    if(pet>0){
        printf("\n%d x 5 kn", pet);
    }
    if(dva>0){
        printf("\n%d x 2 kn", dva);
    }
    if(jedan>0){
        printf("\n%d x 1 kn", jedan);
    }

    return 0;
}
