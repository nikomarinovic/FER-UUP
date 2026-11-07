/*
S tipkovnice učitati niz znakova (string) koji sigurno neće biti dulji od 150 znakova.
Niz može sadržavati bilo koji znak ASCII tablice koji se može tiskati (pozicije 32-126).
Treba napisati program koji će ukloniti sve znakove koji su uneseni, a koji nisu dio engleske abecede.
Ukoliko ulazni string ne sadrži niti jedan znak engleskog alfabeta treba ispisati tekst prazan string.
*/

#include <stdio.h>

int main(void) {
    
    char ulaz[150];
    char izlaz[150];
    int i;
    int k=0;

    printf("Upisite znakovni niz > ");
    fgets(ulaz,sizeof(ulaz),stdin);

    for(i=0; ulaz[i] != '\0' ; i++){
        if((ulaz[i] >= 'a' && ulaz[i] <= 'z') || (ulaz[i] >= 'A' && ulaz[i] <= 'Z')){
            izlaz[k++] = ulaz[i];
        }
    }

    izlaz[k] = '\0';

    printf("Izlazni znakovni niz je : ");
    if(k==0){
        printf("prazan string\n");
    }else{
        printf("%s\n",izlaz);
    }

    return 0;
}
