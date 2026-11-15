/*
Napisati funkciju naziva e_approx tipa double, koja za zadani prirodni broj  (parametar tipa int) računa aproksimaciju Eulerove konstante po formuli .

Napisati glavni program koji s tipkovnice učitava prirodni broj , ispisuje vrijednost  izračunatu pomoću funkcije e_approx uz parametar . Zatim ispisuje razliku izračunate vrijednosti e_approx i vrijednosti konstante . Konstanta  se računa pozivom funkcije exp(1), definirane u biblioteci "math.h".

Sve vrijednosti ispisati s 12 znamenki iza decimalne točke kao u navedim primjerima ispisa programa. Primjeri izvršavanja programa:
*/

#include <stdio.h>
#include <math.h>

double e_approx(int n);

int main(void) {
    
    int n;
    double aproksimacija;

    printf("Upisite broj n: ");
    scanf("%d",&n);

    aproksimacija = e_approx(n);

    printf("Aproksimacija e: %.12f",aproksimacija);
    printf("\n");
    printf("Razlika: %.12f",aproksimacija-exp(1));

    return 0;
}

double e_approx (int n){
    int i;
    double suma = 1.0;
    double clan = 1.0;

    for(i=1; i<=n ; i++){
        clan = clan / i;
        suma = suma + clan;
    }

    return suma;
}
