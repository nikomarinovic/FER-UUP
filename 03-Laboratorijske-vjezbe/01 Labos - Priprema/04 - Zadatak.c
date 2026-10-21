/*
S tipkovnice učitati prirodan broj koji predstavlja broj dana (uneseni broj nije potrebno provjeravati).
Potrebno je pretvoriti zadani broj dana u odgovarajući broj godina, tjedana i dana.
Zanemarite postojanje prijestupnih godina (pretpostavite da svaka godina ima 365 dana).
*/

#include <stdio.h>

int main(void) {
    
    int br, god, tj, dan;

    printf("Unesite broj dana > ");
    scanf("%d",&br);

    god = br / 365;
    br = br % 365;

    tj = br / 7;
    br = br % 7;

    dan = br;

    printf("Unos odgovara razdoblju od %d godina %d tjedana i %d dana", god,tj,dan);

    return 0;
}