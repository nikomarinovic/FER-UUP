#include <stdio.h>

int main(void) {
    
    int broj, prethodni;
    int redni = 0;
    int trenutna_duljina = 0, trenutni_pocetak = 0;
    int max_duljina = 0, max_pocetak = 0;

    printf("Upisite niz cijelih brojeva > ");

    while(1){
        scanf("%d",&broj);

        redni++;

        if(trenutna_duljina == 0){
            trenutna_duljina = 1;
            trenutni_pocetak = redni;
        }else if(broj > prethodni){
            trenutna_duljina++;
        }else{
            trenutna_duljina = 1;
            trenutni_pocetak = redni;
        }

        if(trenutna_duljina >= max_duljina){
            max_duljina = trenutna_duljina;
            max_pocetak = trenutni_pocetak;
        }

        prethodni = broj;

        if(broj == 0){
            break;
        }
    }

    printf("Najdulji strogo rastuci podniz duljine %d zapoceo je na %d. clanu.",max_duljina, max_pocetak);

    return 0;
}
