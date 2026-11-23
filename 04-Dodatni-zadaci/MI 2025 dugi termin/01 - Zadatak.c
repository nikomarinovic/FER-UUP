#include <stdio.h>

int main(void) {
    
    float a1, b1, a, b;
    float a_n_1, a_n_2;
    float b_n_1, b_n_2;
    int max, i;

    printf("Upisite clanove a1 i b1 > ");
    scanf("%f %f",&a1,&b1);

    printf("Upisite maksimalni broj clanova > ");
    scanf("%d",&max);

    printf("a( 1) =%8.2f, b( 1) =%8.2f",a1,b1);
   if(b1 >= 0 && max > 1){
        printf(";\n");
    }else{
        return 0;
    }

    for(i = 2; i <= max; i++){
        if(i==2){
            a = b1;
            b = a1;
            printf("a(%2d) =%8.2f, b(%2d) =%8.2f",i,a,i,b);

            if(b >= 0 && i < max){
                printf(";\n");
            }else{
                break;
            }

            a_n_1 = a;
            a_n_2 = a1;
            b_n_1 = b;
            b_n_2 = b1;

        }else{
            a = (10.0/9.0) * a_n_1 - (1.0/12.0) * b_n_2 + 5;
            b = (2.0/3.0) * b_n_1 - (1.0/19.0) * a_n_2 + 1;

            printf("a(%2d) =%8.2f, b(%2d) =%8.2f",i,a,i,b);

            a_n_2 = a_n_1;
            b_n_2 = b_n_1;
            a_n_1 = a;
            b_n_1 = b;

            if(b >= 0 && i < max){
                printf(";\n");
            }else{
                break;
            }
        }
    }

    return 0;
}