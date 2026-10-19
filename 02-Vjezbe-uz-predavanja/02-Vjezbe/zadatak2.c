// Ispis prve, treće i pete znamenke peteroznamenkastog broja
#include <stdio.h>

int main(void) {
    int broj;

    printf("Upisite 5-znamenkasti cijeli broj > ");
    scanf("%d", &broj);

    printf("%d %d %d\n", broj / 10000, (broj / 100) % 10, broj % 10);

    return 0;
}