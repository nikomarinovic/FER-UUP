/*
Napišite program koji s tipkovnice učitava prirodni broj N (broj članova polja) te učitava polje od N prirodnih brojeva.
Zatim s tipkovnice učitati novi prirodni broj te indeks na koji će biti dodan u postojeće polje.
Ostali članovi polja se u odnosu na umetnutog člana pomiču udesno, a zadnji član će izaći "izvan" polja.
Program treba ispisati početno te novodobiveno polje.
*/

#include <stdio.h>

int main(void) {
    
    int n,i,nb,ind;
    

    printf("Unesite broj clanova polja:");
    scanf("%d", &n);
    printf("\n");

    int niz[n];

    printf("Unesite clanove polja (%d):\n",n);
    for(i= 0; i<n; i++){
        scanf("%d", &niz[i]);
    }

    printf("Unesite vrijednost novog clana te indeks:\n");
    scanf("%d %d",&nb,&ind);

    printf("Pocetno polje\n");
    for(i=0;i<n;i++){
        printf("%d ",niz[i]);
    }
    printf("\n");

    for(i = n - 1; i > ind; i--) {
        niz[i] = niz[i - 1];
    }

    niz[ind]=nb;

    printf("Novodobiveno polje\n");
    for(i=0;i<n;i++){
        printf("%d ",niz[i]);
    }

    return 0;
}