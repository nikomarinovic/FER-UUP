// Zamjena zadnjih znamenki brojeva a i b
#include <stdio.h>

int main(void) {
    int a, b, zadnjaA, zadnjaB;

    printf("Upisite 2 cijela broja > ");
    scanf("%d %d", &a, &b);

    zadnjaA = a % 10;
    zadnjaB = b % 10;

    a = zadnjaB;
    b = zadnjaA;

    printf("a = %d\n", a);
    printf("b = %d\n", b);

    return 0;
}