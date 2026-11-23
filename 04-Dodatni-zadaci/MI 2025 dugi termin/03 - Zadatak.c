#include <stdio.h>

#define MAX 50
#define KT 10

typedef struct {
    int start;
    int vrijeme[KT];
} Trkac;

int main(void)
{
    Trkac t[MAX], tmp;
    int n = 0, i, j, k;

    printf("Unos podataka:\n");
    while (n < MAX) {
        scanf("%d", &t[n].start);
        if (t[n].start == 0)
            break;
        for (k = 0; k < KT; k++)
            scanf("%d", &t[n].vrijeme[k]);
        n++;
    }

    /* sortiranje prema ukupnom vremenu (10. kontrolna tocka) */
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (t[j].vrijeme[KT - 1] > t[j + 1].vrijeme[KT - 1]) {
                tmp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = tmp;
            }
        }
    }

    printf("\n");
    printf("Start.br.  vrij.  pros.KT\n");
    printf("-------------------------\n");

    for (i = 0; i < n; i++) {
        float prosjek = t[i].vrijeme[KT - 1] / (float)KT;
        printf("%8d%7d%9.2f\n", t[i].start, t[i].vrijeme[KT - 1], prosjek);
    }

    return 0;
}