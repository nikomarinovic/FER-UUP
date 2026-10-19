/* Ispisuje trazeni broj clanova Fibonaccijevog niza. */
#include <stdio.h>

int main(void) {
    int n, i, a_i_minus2 = 1, a_i_minus1 = 1, a_i;

    printf("Upisite broj clanova Fibonaccijevog niza > ");
    scanf("%d", &n);

    if (n >= 1) printf("%d ", 1);
    if (n >= 2) printf("%d ", 1);

    for (i = 3; i <= n; i = i + 1) {
        a_i = a_i_minus1 + a_i_minus2;
        printf("%d ", a_i);
        a_i_minus2 = a_i_minus1;
        a_i_minus1 = a_i;
    }

    return 0;
}
