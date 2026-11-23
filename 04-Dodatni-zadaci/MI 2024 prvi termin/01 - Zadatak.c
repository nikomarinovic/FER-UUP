#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    int n, i, j;
    int broj_parova = 0;
    int razmak = 0, najm_razmak;

    printf("upisite velicinu polja > ");
    scanf("%d",&n);

    int niz[n];

    printf("upisite elemente polja > ");

    for(i=0;i<n;i++){
        scanf("%d",&niz[i]);
    }
    najm_razmak = abs(niz[0]-niz[1]);
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            razmak = abs(niz[i]-niz[j]);
            if(razmak < najm_razmak){
                najm_razmak = razmak;
            }
        }
    }

    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            razmak = abs(niz[i]-niz[j]);
            if(razmak == najm_razmak){
                broj_parova++;
            }
        }
    }

    printf("najmanji razmak: %d\n",najm_razmak);
    printf("broj parova: %d",broj_parova);

    return 0;
}
