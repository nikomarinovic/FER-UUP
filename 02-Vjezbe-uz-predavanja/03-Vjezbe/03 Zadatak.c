#include <stdio.h>

int main(void) {
    int izbor;
    double f, c;

    printf("Program za konverziju Fahrenheit - Celsius ili obrnuto.\n");
    printf("Za F u C upisite 1, a za C u F bilo koji drugi cijeli broj > ");
    scanf("%d", &izbor);

    if (izbor == 1) {
        printf("Upisite temperaturu izrazenu u stupnjevima Fahrenheit > ");
        scanf("%lf", &f);

        c = (f - 32) * 5 / 9;

        printf(" %7.3f st. F = %8.3f st. C", f, c);
    } else {
        printf("Upisite temperaturu izrazenu u stupnjevima Celsius > ");
        scanf("%lf", &c);

        f = c * 9 / 5 + 32;

        printf(" %7.3f st. C = %8.3f st. F", c, f);
    }

    return 0;
}