/*
Napišite funkciju naziva median tipa float koja će primati 3 realna broja a, b i c te vraćati njihov median.
Medijan je vrijednost u sredini grupe brojeva; odnosno, pola brojeva u grupi ima vrijednost veću od medijana, a pola brojeva ima vrijednost manju od medijana. Na primjeru od tri broja, medijan je uvijek srednji broj po vrijednosti.

Napisati glavni program koji s tipkovnice učitava tri realna broja, poziva funkciju median te ispisuje apsolutnu vrijednost razlike između mediana i srednje vrijednosti upisanih brojeva.

Sve realne vrijednosti ispisati s tri znamenke iza decimalne točke kao u navedenim primjerima ispisa programa. Primjeri izvršavanja programa:
*/

#include <stdio.h>

float median (float a, float b, float c);

int main(void) {
    
    float a, b, c, m, arsr, razlika;

    printf("Upisite tri realna broja > ");
    scanf("%f %f %f",&a,&b,&c);

    m = median(a,b,c);

    arsr=(a+b+c)/3.0;

    razlika = m - arsr;

    razlika = razlika < 0 ? razlika * -1 : razlika * 1;

    printf("Apsolutna vrijednost razlike mediana i srednje vrijednosti je: %.3f",razlika);

    return 0;
}
float median (float a, float b, float c){
    if((a >= b && a <= c) || (a <= b && a >= c)){
        return a;
    }
    else if((b >= a && b <= c) || (b <= a && b >= c)){
        return b;
    }
    else{
        return c;
    }
}