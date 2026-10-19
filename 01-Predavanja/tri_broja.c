/* Ispisuje uneseni broj i sljedeca dva broja. */
#include <stdio.h>

int main(void) {
   int broj;

   printf("Upisite cijeli broj > ");
   scanf("%d", &broj);

   printf("Rezultat: %d %d %d", broj, broj + 1, broj + 2);

   return 0;
}