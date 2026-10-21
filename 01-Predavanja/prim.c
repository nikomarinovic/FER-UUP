#include <stdio.h>

int main(void) {
    
    int br, i, djeljiv = 0;
    
    printf("Upisi broj: ");
    if (scanf("%d", &br) != 1) {
        fprintf(stderr, "Neispravan unos.\n");
        return 1;
    }

    for (i = 2; i <= br / i; i++) {
        if (br % i == 0) {
            djeljiv = 1;
            break;
        }
    }

    if (br >= 2 && djeljiv == 0) {
        printf("Broj %d je prost.\n", br);
    } else {
        printf("Broj %d nije prost.\n", br);
    }

    return 0;
}
