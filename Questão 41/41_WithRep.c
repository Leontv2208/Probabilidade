#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Rep 100000


int main(){

    srand(time(NULL));

    double B_Vermelhas = 8;
    double B_Brancas = 4;
    double B_Preta = 6;

    double DuasCada;

    double B_Urna = B_Brancas+B_Vermelhas+B_Preta;

    int C_Vermelha = (B_Vermelhas/B_Urna)*100;
    int C_Branca = (B_Brancas/B_Urna)*100;
    int C_Preta = (B_Preta/B_Urna)*100;

    for (int i=0;i<Rep;i++) {
        int VCount=0;
        int BCount=0;
        int PCount=0;

        for (int j = 0; j < 6; ++j) {
            int check = rand()%100;

            if(check<C_Vermelha){
                VCount++;
            } else if(check>=C_Vermelha && check<(C_Vermelha+C_Branca)) {
                BCount++;
            } else {
                PCount++;
            }
        }

        if(VCount==2 && BCount==2 && PCount==2){
            DuasCada++;
        }
    }

    printf("Com reposicao\n");
    //printf("%d %d %d\n", VCount, BCount, PCount);
    printf("Chance de duas cada: %f", DuasCada/Rep);


    return 0;
}