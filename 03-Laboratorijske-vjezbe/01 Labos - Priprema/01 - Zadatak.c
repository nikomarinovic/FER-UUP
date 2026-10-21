/*
tipkovnice učitati četveroznamenkasti broj (nije potrebno provjeravati ispravnost upisa).
Ako je zbroj znamenke tisućica i znamenke desetica jednak zbroju znamenke stotica i znamenke jedinica, potrebno je 
ispisati "Provjera je uspješna!", a u suprotnom treba ispisati apsolutnu vrijednost razlike tih dviju suma.
*/

#include <stdio.h>

int main(void) {
    
    int br, tis, sto, des, jed;
    int suma1, suma2, razlika;

    printf("Unesite cetveroznamenkasti broj > ");
    scanf("%d",&br);

    tis = br / 1000;
    sto = (br/100)%10;
    des = (br/10)%10;
    jed = br%10;

    suma1 = tis + des;
    suma2 = sto + jed;

    if(suma1==suma2){
        printf("Provjera je uspjesna!");
    }
    else{
        razlika = suma1 - suma2;
        if (razlika < 0){
            razlika = razlika * -1;
        }
        printf("Apsolutna razlika suma je %d", razlika);
    }

    return 0;
    
}
