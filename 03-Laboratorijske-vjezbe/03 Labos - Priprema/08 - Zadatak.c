/*
S tipkovnice učitati niz znakova (string) koji sigurno neće biti dulji od 200 znakova.
Niz može sadržavati bilo koji znak ASCII tablice koji se može tiskati (pozicije 32-126).
Odredite i na zaslon ispišite obrnuti niz i pri tome sva mala slova pretvorite u velika.
*/

#include <stdio.h>
#include<string.h>

int main(void) {
    
    char ulaz[200];
    char obrnuto[200];
    int i;
    int k=0;

    printf("Upisite znakovni niz > ");
    fgets(ulaz,sizeof(ulaz),stdin);

    for(i=strlen(ulaz)-1; i>=0 ; i--){
        if(ulaz[i] >= 32 && ulaz[i]<=126){
            if(ulaz[i] >= 'a' && ulaz[i]<= 'z'){
                obrnuto[k++] = ulaz[i] - 32;
            }else{
                obrnuto[k++] = ulaz[i];
            }
        }
    }
    obrnuto[k] = '\0';

    printf("Obrnuti niz: %s\n",obrnuto);

    return 0;
}
