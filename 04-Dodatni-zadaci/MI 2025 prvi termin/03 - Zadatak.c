#include <stdio.h>
#include <math.h>

struct Student {
    int maticni_broj;
    int id_pitanja;
    int edgar;
    int nastavnik;
};

int main(void) {
    
    struct Student studenti[50];
    int brojac = 0, zbroj_razlika = 0;
    int i, broj_studenata = 0, ID;
    float varijanca = 0;
    float razlika;

    printf("Unos podataka:");

    i = 0;

    while (brojac < 50) {

        scanf("%d", &studenti[brojac].maticni_broj);

        if (studenti[brojac].maticni_broj == 0) {
            break;
        }

        scanf("%d %d %d",
            &studenti[brojac].id_pitanja,
            &studenti[brojac].edgar,
            &studenti[brojac].nastavnik);

        brojac++;
    }

    printf("\nUnesite ID pitanja za analizu: ");
    scanf("%d",&ID);
    printf("\n");


    for(i = 0; i<brojac; i++){
        if(studenti[i].id_pitanja == ID){
            broj_studenata++;
            zbroj_razlika += (studenti[i].edgar - studenti[i].nastavnik); 
        }
    }

    razlika = (float)zbroj_razlika / broj_studenata;

    for(i = 0; i<brojac; i++){
        if(studenti[i].id_pitanja == ID){
            varijanca += pow(((studenti[i].edgar - studenti[i].nastavnik)-razlika),2);
        }
    }

    varijanca = varijanca / (broj_studenata - 1); 

    printf("Rezultati:\n");
    printf("Broj studenata: %d\n",broj_studenata);
    printf("Prosjecna razlika: %.2f\n",razlika);
    printf("Varijanca: %.2f\n",varijanca);

    return 0;
}
