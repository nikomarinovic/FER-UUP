// KADANEOV ALGORITAM

#include <stdio.h>

int main(void) {
    
    int m, i;
    int trenutna_suma=0, najveca_suma=0;
    int trenutni_pocetak=0, pocetak=0, kraj=0;

    printf("Upisite velicinu polja m > ");
    scanf("%d", &m);

    int polje[m];

    printf("Upisite %d clanova polja m > ",m);

    for (i=0; i<m; i++){
        scanf("%d", &polje[i]);
    }

    for(i=0;i<m;i++){

        // Je li dosadašnja suma negativna?
        // DA -> odbacujemo dosadašnje pod-polje i krećemo od trenutnog elementa.
        // NE -> nastavljamo zbrajati trenutnom pod-polju sljedeći element.
        if(trenutna_suma < 0){
            trenutna_suma = polje[i];
            trenutni_pocetak = i;
        }else{
            trenutna_suma += polje[i];
        }

        if(trenutna_suma > najveca_suma){
            najveca_suma = trenutna_suma;
            pocetak = trenutni_pocetak;
            kraj = i;
        }
    }

    // ispis pod-polja

    printf("Pronadjeno pod-polje:");

    for (int i = pocetak; i <= kraj; i++) {
        printf(" %d", polje[i]);
    }
    printf("\n");

    printf("Najveca suma kontinuiranog pod-polja je: %d",najveca_suma);

    return 0;
}
