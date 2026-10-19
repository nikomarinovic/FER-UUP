/* Provjerava je li unesena godina prijestupna. */
#include<stdio.h>

int main(void){
    
    int god;

    printf("Upisi godinu: ");
    scanf("%d",&god);

    if(god % 400 == 0 || (god % 4 == 0  && god %100 != 0)){
        printf("Godina je prijestupna");
    }else{
        printf("Godina nije prijestupna");
    }

    return 0;
}