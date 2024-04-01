// A máquinas A e B produzem o mesmo tipo de parafuso.
// A porcentagem de parafusos defeituosos produzidos, respectivamente, pela máquina A e B é de 15% e de 5%.
// Foram misturados numa caixa 100 parafusos produzidos por A e 100 parafusos produzidos por B.
// Se tirarmos um parafuso ao acaso e ele for defeituoso,
// a probabilidade de que tenha sido produzido pela máquina A é de
// A( ) 10% B( ) 15% C( ) 30% D( ) 50% E( ) 75%

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100000

typedef struct
{
    int qtde;
    double C_def;
    int defeituosos;
} parafuso;

int main()
{
    srand(time(NULL));
    parafuso A,B;

    //parametros máquina A
    A.qtde = N;
    A.C_def = 15;
    A.defeituosos = 0;

    //parametros máquina B
    B.qtde = N;
    B.C_def = 5;
    B.defeituosos = 0;


    for (int i = 0; i < A.qtde; ++i) {
        if((rand()%100)<A.C_def){
            A.defeituosos+=1;
        }
    }
    printf("Quantidade de parafusos A defeituosos: %d\n", A.defeituosos);

    for (int j = 0; j < B.qtde; ++j) {
        if((rand()%100)<B.C_def){
            B.defeituosos+=1;
        }
    }
    printf("Quantidade de parafusos B defeituosos: %d\n", B.defeituosos);

    //total de parafusos com defeito
    int total_def = (A.defeituosos + B.defeituosos);
    printf("Quantidade parafusos defeituosos: %d\n", total_def);

    //Chance parafuso ser de A
    printf("Chance parafuso defeituoso ser de A = %0.4f\n", (A.defeituosos/(double)total_def));
    printf("Resultado Classico = 0.75\n");

    return 0;
}