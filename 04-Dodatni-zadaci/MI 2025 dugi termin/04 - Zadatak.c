#include <stdio.h>

unsigned short kodiraj(int smjer, int koraci, int kamera, int svjetla, int hitno)
{
    unsigned short rezultat = 0;

    rezultat |= (smjer & 3);
    rezultat |= (koraci & 31) << 2;
    rezultat |= (kamera & 1) << 7;
    rezultat |= (svjetla & 1) << 8;
    rezultat |= (hitno & 1) << 9;

    return rezultat;
}

int main(void)
{
    int smjer, koraci, kamera, svjetla, hitno;

    printf("Upisite vrijednosti > ");
    scanf("%d %d %d %d %d", &smjer, &koraci, &kamera, &svjetla, &hitno);

    printf("%hu\n", kodiraj(smjer, koraci, kamera, svjetla, hitno));

    return 0;
}