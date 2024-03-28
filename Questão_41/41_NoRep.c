//
// Created by leona on 27/03/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RAND_MAX 100
#define Rep 100000


int main(){

    srand(time(NULL));

    double B_Vermelhas;
    double B_Brancas;
    double B_Preta;

    int DuasCada;

    double B_Urna = B_Brancas+B_Vermelhas+B_Preta;

    int C_Vermelha = (B_Vermelhas/B_Urna)*100;
    int C_Branca = (B_Brancas/B_Urna)*100;
    int C_Preta = (B_Preta/B_Urna)*100;

    for (int i=0;i<Rep;i++) {
        B_Vermelhas = 8;
        B_Brancas = 4;
        B_Preta = 6;

        int VCount=0;
        int BCount=0;
        int PCount=0;

        for (int j = 0; j < 6; ++j) {
            int check = rand()%RAND_MAX;

            if(check<C_Vermelha){
                VCount++;
                B_Vermelhas--;
            } else if(check>=C_Vermelha && check<(C_Vermelha+C_Branca)) {
                BCount++;
                B_Brancas--;
            } else {
                PCount++;
                B_Preta--;
            }
        }

        if(VCount==2 && BCount==2 && PCount==2){
            DuasCada+=1;
        }
    }

    printf("Sem reposicao\n");
    printf("Quantidade de duas cada: %d\n", DuasCada);

    printf("Chance: %f\n", DuasCada/Rep);

    return 0;
}