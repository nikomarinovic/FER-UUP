/* Rastavlja uneseni broj na proste faktore. */
#include<stdio.h>

int main (void){

    int br, i = 2;
    int prvi = 1;
    
    printf("Upisi broj: ");
    scanf("%d",&br);

    printf("%d = ",br);

    while(br>1){
        if(br%i==0){
            if (!prvi) {
                printf(" * ");
            }
            printf("%d", i);
            prvi = 0;
            br = br/i;
        }else{
            i++;
        }
    }

    printf("\n");
    return 0;
}