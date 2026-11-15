/*
Napisati funkciju savrsen_kvadrat tipa int koja kao ulaz prima prirodni broj te kao izlaz vraća 1 ako je taj broj savršen kvadrat,
a ako nije onda vraća 0. Savršen kvadrat je broj dobiven kvadriranjem cijelog broja, npr. 16 je savršen kvadrat, jer je  = 4.
Napisati funkciju factorial tipa int koja također kao ulaz prima prirodni broj, a kao izlaz vraća faktorijelu unesenog broja.
Napisati funkciju zbroj_znamenaka tipa int koja kao ulaz prima prirodni broj, a kao izlaz vraća zbroj njegovih znamenaka.
Napisati glavni program koji učitava prirodni broj s tipkovnice, računa faktorijelu unesenog broja korištenjem funkcije factorial, 
računa zbroj znamenaka dobivene faktorijele korištenjem funkcije zbroj_znamenaka te ispisuje je li dobiveni zbroj savršen kvadrat korištenjem funkcije savrsen_kvadrat.
*/

#include <stdio.h>

int savrsen_kvadrat(int n);
int factorial(int n);
int zbroj_znamenaka(int n);

int main(void) {

    int n, fakt, zbroj, kvadrat;

    printf("Upisite prirodni broj > ");
    scanf("%d", &n);

    fakt = factorial(n);
    zbroj = zbroj_znamenaka(fakt);
    kvadrat = savrsen_kvadrat(zbroj);

    if (kvadrat == 1) {
        printf("Suma znamenaka od %d! je savrsen kvadrat.", n);
    } else {
        printf("Suma znamenaka od %d! nije savrsen kvadrat.", n);
    }

    return 0;
}

int factorial(int n) {

    int i, f = 1;

    for (i = 1; i <= n; i++) {
        f *= i;
    }

    return f;
}

int zbroj_znamenaka(int n) {

    int zbroj = 0;

    while (n > 0) {
        zbroj += n % 10;
        n /= 10;
    }

    return zbroj;
}

int savrsen_kvadrat(int n) {

    int i;

    for (i = 0; i * i <= n; i++) {
        if (i * i == n) {
            return 1;
        }
    }

    return 0;
}