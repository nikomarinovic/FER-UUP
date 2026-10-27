#include <stdio.h>

int main(void) {
    double x, y;

    printf("Upisite dva broja (x i y) > ");
    scanf("%lf %lf", &x, &y);

    if (((x >= 5 && x <= 20) || (y >= 5 && y <= 20)) && x < y) {
        printf("Istina je\n");
    } else {
        printf("Nije istina\n");
    }

    return 0;
}