//
// Created by leona on 27/03/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Rep 1000


int main(){

    srand(time(NULL));

    int B_Vermelhas, B_Brancas, B_Preta;
    int DuasCada;
    int B_Urna = B_Brancas+B_Vermelhas+B_Preta;
    int check;

    for (int i = 0; i < Rep; ++i) {

        B_Vermelhas = 8;
        B_Brancas = 4;
        B_Preta = 6;

        int VCount=0;
        int BCount=0;
        int PCount=0;

        for (int j = 0; j < 6; ++j) {
            check = rand()%B_Urna;

            if(check<B_Brancas){
                B_Brancas--;
                BCount++;
            } else if (check>B_Brancas&&check<(B_Brancas+B_Preta)){
                B_Preta--;
                PCount++;
            } else {
                B_Vermelhas--;
                VCount++;
            }
            if(VCount==2&&PCount==2&&BCount==2){
                printf("a\n");
            }

        }


    }


    printf("Sem reposicao\n");
    printf("Quantidade de duas cada: %d\n", DuasCada);

    printf("Chance: %f\n", (double)DuasCada/Rep);

    return 0;
}