// A máquinas A e B produzem o mesmo tipo de parafuso.
// A porcentagem de parafusos defeituosos produzidos, respectivamente, pela máquina A e B é de 15% e de 5%.
// Foram misturados numa caixa 100 parafusos produzidos por A e 100 parafusos produzidos por B.
// Se tirarmos um parafuso ao acaso e ele for defeituoso,
// a probabilidade de que tenha sido produzido pela máquina A é de
// A( ) 10% B( ) 15% C( ) 30% D( ) 50% E( ) 75%

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define RAND_MAX 100
#define N 100000

typedef struct
{
    int qtde;
    double C_def;
    int defeito;
} parafuso;

int main()
{
    srand(time(NULL));
    parafuso A,B;

    //parametros máquina A
    A.qtde = N;
    A.C_def = 15;
    A.defeito = 0;

    //parametros máquina B
    B.qtde = N;
    B.C_def = 5;
    B.defeito = 0;

    //quantidade total de parafusos produzidos
    double Qtde_Caixa = A.qtde + B.qtde;
    int x[A.qtde], y[B.qtde];

    for (int a = 0; a < A.qtde; ++a) {
        x[a]=rand()%RAND_MAX;
        y[a]=rand()%RAND_MAX;
    }


    for (int i = 0; i < A.qtde; ++i) {
        if((x[i])<A.C_def){
            A.defeito+=1;
        }
    }
    printf("Quantidade de parafusos A defeituosos: %d\n", A.defeito);

    for (int j = 0; j < B.qtde; ++j) {
        if(y[j]<B.C_def){
            B.defeito+=1;
        }
    }
    printf("Quantidade de parafusos B defeituosos: %d\n", B.defeito);

    //chance de algum parafuso ser defeituoso
    double Prob_Defeituoso = ((A.defeito/Qtde_Caixa) + (B.defeito/Qtde_Caixa))*100;
    printf("Prob_Defeituoso = %f\n", Prob_Defeituoso);

    return 0;
}