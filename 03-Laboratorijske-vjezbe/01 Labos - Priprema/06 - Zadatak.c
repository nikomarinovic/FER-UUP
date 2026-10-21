/*
Vrijednost pH je broj koji služi kao mjera kiselosti vodenih otopina te može poprimiti 
vrijednosti iz intervala [0, 14]. Ako je pH vrijednost manja od 7 kažemo da je otopina kisela. 
Ako je vrijednost veća od 7 onda je otopina lužnata. 
Ako je pH vrijednost jednaka 7 otopina je neutralna.
*/

#include <stdio.h>

int main(void) {

    int ph;

    printf("Unesite pH vrijednost otopine > ");
    scanf("%d",&ph);

    if(ph < 0 || ph > 14){
        printf("KRIVI UNOS");
        return 0;
    }

    if(ph < 7){
        printf("Otopina je kisela.");
    }
    if(ph > 7){
        printf("Otopina je luznata.");
    }
    if(ph == 7){
        printf("Otopina je neutralna.");
    }

    return 0;
}
