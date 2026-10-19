// Izračun gravitacije na određenoj visini iznad Zemlje
#include <stdio.h>

#define MASA_ZEMLJE 5.9722e24f
#define POLUMJER_ZEMLJE 6.371e6f
#define GRAV_KONST 6.67408e-11f

int main(void) {
    int h;
    float g;
    float udalj_sr;

    printf("Upisite visinu (m) iznad povrsine Zemlje > ");
    scanf("%d", &h);

    udalj_sr = POLUMJER_ZEMLJE + h;
    g = MASA_ZEMLJE * GRAV_KONST / (udalj_sr * udalj_sr);

    printf("gravitacija na visini %d metara je priblizno %e m s(-2)", h, g);

    return 0;
}