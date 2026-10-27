#include <stdio.h>

int main(void) {

    int br1, br2;

    printf("Upisite dva broja > ");
    scanf("%d %d",&br1,&br2);

    if((br1 > 100 && br2 < 100) || (br1 < 100 && br2 > 100)){
        printf("Jedan je veci, drugi je manji od 100");
    }

    return 0;
}