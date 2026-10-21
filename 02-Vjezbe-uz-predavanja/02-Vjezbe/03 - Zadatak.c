// Učitavanje četiri znamenke i sastavljanje broja m
#include <stdio.h>

int main(void) {
    int z1, z2, z3, z4, m;

    printf("Upisite 4 cijela broja (po jednu znamenku) > ");
    scanf("%d %d %d %d", &z1, &z2, &z3, &z4);

    printf("z1 = %d\n", z1);
    printf("z2 = %d\n", z2);
    printf("z3 = %d\n", z3);
    printf("z4 = %d\n", z4);

    m = z1 * 1000 + z2 * 100 + z3 * 10 + z4;

    printf("m = %d\n", m);

    return 0;
}