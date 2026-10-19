/* Ispisuje uneseni broj i broj koji slijedi. */
#include <stdio.h>
int main(void) {
   int broj;

   printf("Upisite cijeli broj > ");
   scanf("%d", &broj);

   printf("Rezultat: %d %d", broj, broj + 1);

   return 0;
}