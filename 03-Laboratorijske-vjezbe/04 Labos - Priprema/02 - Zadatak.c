/*
Napišite program koji s tipkovnice učitava broj (tipa unsigned short int)
te ispisuje binarni zapis učitanog broja (bit po bit počevši od najznačajnijeg bita).
Potom program pronalazi i ispisuje indeks (0 do 15) najmanje značajnog bita postavljenog na vrijednost 0.
*/

#include <stdio.h>

int main(void) {
    
    unsigned short int broj;
    int i,indeks = -1;

    printf("Unesite broj > ");
    scanf("%hu",&broj);

    printf("Binarni zapis ucitanog broja: ");

    for(i=15;i>=0;i--){
        printf("%d",(broj>>i)&1);
    }

    printf("\n");

    for(i=0;i<=15;i++){
        if(((broj>>i)&1)==0){
            indeks = i;
            break;
        }
    }

    if(indeks == -1){
        printf("Nema bita s vrijednosti 0.");
    }else{
        printf("Indeks najmanje znacajnog bita s vrijednosti 0: %d",indeks);
    }

    return 0;
}
