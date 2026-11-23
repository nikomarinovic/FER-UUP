#include <stdio.h>

int main(void) {

    int m, n, i, j, k;
    int broj, maks, mod;

    printf("Unesite m i n: ");
    scanf("%d %d", &m, &n);

    while (m * n > 100) {
        printf("Unesite m i n: ");
        scanf("%d %d", &m, &n);
    }

    unsigned char niz[100][100];

    printf("Unesite elemente matrice:\n");

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%hhu", &niz[i][j]);
        }
    }

    for (i = 0; i < m; i++) {

        int frekvencija[256] = {0};

        for (j = 0; j < n; j++) {
            frekvencija[niz[i][j]]++;
        }

        maks = 0;
        mod = 0;

        for (k = 0; k < 256; k++) {
            if (frekvencija[k] >= maks && frekvencija[k] > 0) {
                maks = frekvencija[k];
                mod = k;
            }
        }

        printf("Redak %d: mod=%d\n", i + 1, mod);
    }

    return 0;
}