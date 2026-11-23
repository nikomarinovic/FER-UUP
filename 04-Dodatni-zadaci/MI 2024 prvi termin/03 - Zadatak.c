#include <stdio.h>

struct LEGO {
    char naziv[51];
    int serijski[5];
};

int main(void) {

    int i, j, k, broj;
    int ispisano = 0;
    
    struct LEGO figure[50] = {
        {"FireworkGuy", {14822018, 13562018, 43222017, 52112017, 34222018}},
        {"WrestlingChampion", {93212015, 34122015, 34772012, 22222014, 13452013}},
        {"CactusGirl", {32332018, 93212015, 34772012, 52112017, 34882016}},
        {"Dobby", {98762018, 97652018, 34772018, 32452016, 34212017}},
        {"Cheerleader", {12322010, 14562010, 32462010, 23762010, 98792010}},
        {"Zombie", {56432010, 76482010, 47822010, 78652010, 45322010}},
        {"Forestman", {23652010, 34762009, 64832008, 57532010, 54882009}},
        {"Mariachi/MaracaMan", {23672010, 93212010, 32452016, 54882010, 34672010}}
    };

    i = 8;
    while(i<50){
        printf("Unos %d. figure:\n",i+1);
        printf("Naziv: ");
        scanf("%50s",figure[i].naziv);
        if(figure[i].naziv[0] == '-'){
            break;
        }
        printf("Serijski brojevi: ");
        for(j=0;j<5;j++){
            scanf("%d",&figure[i].serijski[j]);
        }
        i++;
    }

    printf("Serijski broj dijela za provjeru: ");
    scanf("%d",&broj);

    printf("Figure koje sadrze dio %d su:\n",broj);

    for(k=0;k<i;k++){
        for(j=0;j<5;j++){
            if(broj / 10000 == figure[k].serijski[j] / 10000){
                printf("%s\n",figure[k].naziv);
                ispisano++;
            }
        }
    }

    if(ispisano == 0){
        printf("Nema figura!");
    }

    return 0;
}
