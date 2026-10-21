/*
Ivica vas je zamolio da napišete program koji će izgenerirati jednostavnu brojalicu 
"eci peci pec eci peci pec eci ..." (primijetite da se iste tri riječi ponavljaju u istom redoslijedu). 
Napišite program koji će pročitati cijeli broj n s tipkovnice te će ispisati prvih n riječi brojalice. 
U slučaju unosa broja, koji je manji ili jednak nula ispišite "KRIVI UNOS".
*/

#include <stdio.h>

int main (void){

    int n, i;

    printf("Unesite broj rijeci brojalice > ");
    scanf("%d",&n);

    if(n<=0){
        printf("KRIVI UNOS");
    }
    else{
        for(i=1; i<=n ; i++){
            if(i % 3 == 1){
                printf("eci ");
            }else if(i % 3 == 2){
                printf("peci ");
            }else{
                printf("pec ");
            }
        }
    }

    return 0;
}