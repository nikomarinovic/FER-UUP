#include <stdio.h>

int main(void) {
    
    int i;
    int niz[10];
    float suma = 0.0, arsr;
    
    for (i = 0; i < 10; i++) {
        printf("Upisi %d. broj: ", i + 1);
        scanf("%d", &niz[i]);
        suma += niz[i];
    }
    arsr = suma / 10;

    printf("Aritmeticka sredina unesenih brojeva je: %.2f\n", arsr);

    printf("Uneseni brojevi veci od aritmeticke sredine su: ");
    for (i = 0; i < 10; i++) {
        if (niz[i] > arsr) {
            printf("%d, ", niz[i]);
        } 
    }
    printf("\n");

    return 0;
}
