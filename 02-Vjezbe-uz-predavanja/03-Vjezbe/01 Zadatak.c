#include <stdio.h>
#include<math.h>
#define PI 3.14159f

int main(void) {
    
    float r, V;

    printf("Upisite radijus kugle > ");
    scanf("%f",&r);

    if(r<=0){
        printf("Neispravan radijus kugle");
        return 0;
    }

    V = (4.0f / 3.0f) * PI * pow(r,3);

    printf("Volumen kugle radijusa %.3f je %.3f",r,V);

    return 0;
}