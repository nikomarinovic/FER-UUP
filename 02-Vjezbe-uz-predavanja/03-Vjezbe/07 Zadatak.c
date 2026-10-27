#include <stdio.h>

int main(void) {
    double a, b, c, d, e;
    int brojac = 0;

    printf("Upisite pet brojeva > ");
    scanf("%lf %lf %lf %lf %lf", &a, &b, &c, &d, &e);

    if (a > 0) brojac++;
    if (b > 0) brojac++;
    if (c > 0) brojac++;
    if (d > 0) brojac++;
    if (e > 0) brojac++;

    if (brojac >= 3) {
        printf("Barem tri su veca od nule\n");
    } else {
        printf("Niti tri nisu veca od nule\n");
    }

    return 0;
}