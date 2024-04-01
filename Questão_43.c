#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Rep 100000
#define max 100

int main(){

    srand(time(NULL));

    double defeituosas, boas;
    double total_peças = defeituosas+boas;
    double C_Defeito = defeituosas/total_peças;
    int favoravel;

    for (int i = 0; i < Rep; ++i) {
        defeituosas = 3;
        boas = 6;

        for (int j = 0; j < 5; ++j) {

            //chance de retirar defeituosa
            if(rand() % max < C_Defeito){
                defeituosas--;

            }

        }
    }
    printf("Quantidade de pecas defeituosas retiradas no quinto teste: %d\n", favoravel);
    printf("Chance de sair defeituosa no quinto teste: %f\n", (double)favoravel/Rep);

    return 0;
}