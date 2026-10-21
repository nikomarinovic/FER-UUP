#include <stdio.h>

int main(void) {
    
    int br, i = 0, j, pal = 1;
    int broj[10];

    printf("Upisi broj: ");
    if (scanf("%d", &br) != 1) {
        fprintf(stderr, "Neispravan unos.\n");
        return 1;
    }

    if (br < 0) {
        pal = 0;
    }

    // Vadimo znamenke iz broja i spremamo ih u niz 
    // broj je okrenut naopako, tj. znamenke su spremljene u obrnutom redoslijedu

    while (br > 0) {
        broj[i]=br%10;
        i++;
        br=br/10;
    }

    // Provjeravamo da li je broj palindrom
    // pal = 0 --> nije palindrom
    // pal = 1 --> jest palindrom

    for(j=0; j<i/2; j++){
        if(broj[j]!=broj[i-j-1]){
            pal = 0;
            break;
        }
    }

    if(pal==1){
        printf("Broj je palindrom\n");
    }else{
        printf("Broj nije palindrom\n");
    }

    return 0;
}