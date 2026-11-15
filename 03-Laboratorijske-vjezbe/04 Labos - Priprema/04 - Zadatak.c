/*
Napišite program koji s tipkovnice učitava broj (tipa unsigned short int) i na standardni izlaz ispisuje binarni zapis učitanog broja (bit po bit počevši od najznačajnijeg bita).

Potom program s tipkovnice treba učitavati po dva cijela broja koji predstavljaju:

poziciju bita (pozicija 0 se odnosi na najmanje značajan bit, a 15 na najznačajniji bit)
vrijednost na koju treba postaviti bit učitanog broja na toj poziciji
Nakon učitanog para brojeva potrebno je postaviti bit na učitanoj poziciji na tu (netom učitanu) vrijednost.

Učitavanje treba prekinuti kad se za poziciju učita vrijednost koja nije u intervalu [0, 15] ili kada se za vrijednost na koju treba postaviti bit broja učita vrijednost koja nije 0 ili 1.

Na kraju, program treba ispisati dekadski zapis izmijenjenog broja i binarni zapis izmijenjenog broja (bit po bit, počevši od najznačajnijeg bita).

Napomena: nije dopušteno koristiti polja (array).
*/

#include <stdio.h>

int main(void) {
    
    unsigned short int broj;
    int i,indeks,bit;

    printf("Unesite broj > ");
    scanf("%hu",&broj);

    printf("Binarni zapis broja: ");
    for(i=15;i>=0;i--){
        printf("%d",(broj>>i)&1);
    }

    printf("\n");

    while(1==1){
        printf("Unesite indeks i vrijednost bita > ");
        scanf("%d %d",&indeks,&bit);
        
        if(!((indeks >= 0 && indeks <= 15) && (bit == 1 || bit == 0))){
            break;
        }

        if(bit == 1){
            broj = broj | (1<<indeks);
        }else{
            broj = broj & ~ (1<<indeks);
        }
    }
    
    printf("\n");

    printf("Dekadski i binarni zapis izmijenjenog broja: %d ",broj);

    for(i=15;i>=0;i--){
        printf("%d",(broj>>i)&1);
    }

    return 0;
}
