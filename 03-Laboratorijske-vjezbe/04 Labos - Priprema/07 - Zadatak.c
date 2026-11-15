/*
Napisati funkciju naziva djelitelj tipa int, koja za dva zadana prirodna broja  i  (parametri tipa int) računa najveći zajednički djelitelj.
Napisati funkciju naziva reduciraj tipa void, koja za zadane brojnik i nazivnik  i , koji predstavljaju razlomak  ispisuje reducirani oblik tog razlomka. Za izračun reduciranog razlomka koristiti funkciju djelitelj.
Napisati glavni program koji s tipkovnice učitava prirodne brojeve  i , ispisuje razlomak  te ispisuje njegov reducirani oblik korištenjem funkcije reduciraj.
*/

#include <stdio.h>

int djelitelj (int a, int b);
void reduciraj(int d, int a, int b);

int main(void) {

    int a, b, d;
    
    printf("Upisite brojnik i nazivnik: ");
    scanf("%d %d", &a, &b);

    d = djelitelj(a,b);

    printf("Razlomak: %d/%d\n",a,b);

    reduciraj(d,a,b);

    return 0;
}

int djelitelj (int a, int b){
    int najm = a, i, najv = 1;

    if(najm > b){
        najm = b;
    }

    for(i=1;i<=najm;i++){
        if((a%i == 0) && (b%i == 0)){
            najv = i;
        }
    }
    return najv;
}

void reduciraj(int d, int a, int b){
    if((a>b) && (a%b==0)){
        printf("Reduciran: %d",a/d);
    }else{
        a /= d;
        b /= d;
        printf("Reduciran: %d/%d",a,b);
    }
}