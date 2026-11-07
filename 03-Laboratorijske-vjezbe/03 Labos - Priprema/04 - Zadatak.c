/*
S tipkovnice učitati cijele brojeve N, M, idxi i idxj. Nije potrebno provjeravati njihovu ispravnost.
Zatim inicijalizirati dvodimenzijsko polje polje veličine N(redaka) x M(stupaca) tako da nakon inicijalizacije svaki član polja ima vrijednost 0.

Potom, počevši od člana polje[idxi][idxj] popuniti matricu polje prema sljedećim pravilima:

Ako je vrijednost trenutnog člana polje[idxi][idxj] jednaka 1, popunjavanje matrice je gotovo
Ako je vrijednost trenutnog člana polje[idxi][idxj] jednaka 0, postavite mu vrijednost na 1,
te se pomaknite po retcima za idxi = idxi + i_smjer i po stupcima za idxj = idxj + j_smjer
Ako bi kretanje rezultiralo izlaskom iz matrice tj. ako bi idxi = idxi + i_smjer ili idxj = idxj + j_smjer rezultirali izlaskom iz matrice, smjer kretanja se onda mijenja na sljedeći način:
Kada stignemo do donjeg ili gornjeg ruba matrice, počinjemo se kretati po retcima u suprotnom smjeru (-i_smjer)
Kada stignemo do desnog ili lijevog ruba matrice, počinjemo se kretati po stupcima u suprotnom smjeru (-j_smjer)
U kutevima matrice je potrebno napraviti obje promjene smjera
Početni smjer kretanja je dijagonalno gore desno (indeks retka pada, a stupca raste):

po retcima i_smjer = -1
po stupcima j_smjer = 1
Na kraju ispišite dobivenu matricu polje nakon popunjavanja te duljinu prijeđenog puta (ukupni broj pomaka).
*/

#include <stdio.h>

int main(void) {
    
    int n,m,idxi,idxj,i,j;
    int i_smjer = -1;
    int j_smjer = 1;
    int duljina = 0; 

    printf("Upisite brojeve N, M, idxi i idxj > ");
    scanf("%d %d %d %d",&n,&m,&idxi,&idxj);

    int mat[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mat[i][j] = 0;
        }
    }

    i = idxi;
    j = idxj;

    while(mat[i][j] == 0){
        mat[i][j]=1;
        if(i + i_smjer < 0 || i + i_smjer > n-1){
            i_smjer *= -1;
        }
        if(j + j_smjer < 0 || j + j_smjer > m-1){
            j_smjer *= -1;
        }
        i += i_smjer;
        j += j_smjer;

        duljina ++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    printf("Duljina: %d\n",duljina);

    return 0;
}
