/* Ispisuje opis unesene ocjene. */
#include<stdio.h>

int main (void) {

    int ocj;

    printf("Upisi ocjenu: ");
    scnaf("%d",&ocj);

    switch (ocj){
        case 5:
            printf("Odličan");
        case 4:
            printf("Vrlo dobar");
        case 3:
            printf("Dobar");
        case 2:
            printf("Dovoljan");
        case 1:
            printf("Nedovoljan");
    }

    return 0;

}  