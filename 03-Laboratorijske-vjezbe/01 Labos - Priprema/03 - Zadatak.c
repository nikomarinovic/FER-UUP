/*
S tipkovnice učitati troznamenkasti prirodni broj.
Na zaslon ispisati sumu parnih znamenki učitanog broja umanjenu za sumu neparnih znamenki.
*/

#include <stdio.h>

int main(void) {
    
    int br, sto, des, jed, parni = 0, neparni = 0, rez;

    printf("Upisite troznamenkasti prirodni broj > ");
    scanf("%d", &br);

    sto = br / 100;
    des = (br / 10) % 10;
    jed = br % 10;

    if(sto % 2 == 0){
        parni = parni + sto;
    }else{
        neparni = neparni + sto;
    }

    if(des % 2 == 0){
        parni = parni + des;
    }else{
        neparni = neparni + des;
    }

    if(jed % 2 == 0){
        parni = parni + jed;
    }else{
        neparni = neparni + jed;
    }

    rez = parni - neparni;

    printf("Rezultat: %d",rez);

    return 0;
}