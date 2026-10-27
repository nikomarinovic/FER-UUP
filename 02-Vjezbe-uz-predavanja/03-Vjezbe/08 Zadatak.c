#include <stdio.h>

int main(void) {
    int xa, ya, xb, yb, xc, yc;
    double xTezista, yTezista;

    printf("Upisite koordinate vrha trokuta A > ");
    scanf("%d %d", &xa, &ya);

    printf("Upisite koordinate vrha trokuta B > ");
    scanf("%d %d", &xb, &yb);

    printf("Upisite koordinate vrha trokuta C > ");
    scanf("%d %d", &xc, &yc);

    xTezista = (xa + xb + xc) / 3.0;
    yTezista = (ya + yb + yc) / 3.0;

    printf("Teziste trokuta A(%f, %f), B(%f, %f), C(%f, %f) jest T(%f, %f)",
           (double)xa, (double)ya,
           (double)xb, (double)yb,
           (double)xc, (double)yc,
           xTezista, yTezista);

    return 0;
}