#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Rep 1000000

int main(){

    srand(time(NULL));

    double defeituosas, boas, total_peças;
    double favoravel = 0;

    for (int i = 0; i < Rep; ++i) {
        defeituosas = 3;
        boas = 6;
        total_peças = 9;

        for (int j = 0; j < 5; ++j) {
            //chance de retirar defeituosa
            int x = rand()%100;

            if(x < ((defeituosas/total_peças)*100)){
                defeituosas--;
                total_peças--;
                if (j==4 && defeituosas==0){
                    favoravel++;
                } else if(defeituosas==0){
                    break;
                }
            } else {
                boas--;
                total_peças--;
            }
            //printf("%.f %.f %d\n ", boas, defeituosas, j);
        }
    }
    printf("Quantidade de pecas defeituosas retiradas no quinto teste: %.f\n", favoravel);
    printf("Chance de sair defeituosa no quinto teste: %f\n", favoravel/Rep);

    return 0;
}