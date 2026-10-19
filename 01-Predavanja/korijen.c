/* Racuna kvadratni korijen Newtonovom metodom. */
#include <stdio.h>
#include <math.h>

#define EPS 0.0001f

int main(void){
    float x, y = 1.0f, prosjek, diff = 1.0f;

    printf("Unesite broj: ");
    if (scanf("%f", &x) != 1)
        return 1;

    if (x < 0.0f) {
        printf("Broj mora biti veci ili jednak nuli.\n");
        return 1;
    }

    printf("\n%.4f = ", x);

    while (fabsf(diff) > EPS) {
        prosjek = (y + x / y) / 2.0f;
        diff = prosjek - y;

        printf("\n%.4f\t%.4f\t%.4f", x, y, diff);
        y = prosjek;
    }

    printf("\n%.4f\n", y);
    return 0;
}