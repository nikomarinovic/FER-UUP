#include <stdio.h>

int binarni_palindrom(unsigned int n);

int main(void) {
    
    unsigned int n;
    _Bool palindrom;

    printf("Upisite broj > ");
    scanf("%u",&n);

    palindrom = binarni_palindrom(n);

    if(palindrom){
        printf("Broj je binarni palindrom.");
    }else{
        printf("Broj nije binarni palindrom.");
    }

    return 0;
}

int binarni_palindrom(unsigned int n){
    int duljina = 0;
    int i;

    while(n >> duljina){
        duljina++;
    }

    for(i = 0; i < duljina / 2; i++){

        int lijevi = (n >> (duljina-1-i))&1;
        int desni = (n >> i) & 1;

        if(lijevi!=desni){
            return 0;
        }
    }
    return 1;
}