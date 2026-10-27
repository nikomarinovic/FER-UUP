#include <stdio.h>

int main(void) {
    int a, b, c;

    printf("Upisite tri broja > ");
    scanf("%d %d %d", &a, &b, &c);

    if ((a < b && b < c) || (a > b && b > c)) {
        printf("Brojevi su poredani i razliciti\n");
    } else {
        printf("Brojevi nisu poredani ili nisu razliciti\n");
    }

    return 0;
}