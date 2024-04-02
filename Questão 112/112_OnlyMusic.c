#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define rep 100000

int main(){

    srand(time(NULL));

    double OnlyMusicA = 0;
    //1Hour seguido halfHour
    for (int i = 0; i < rep; ++i) {
        int x = rand()%2;
        int y = rand()%6;
        //1 de 2 programas de 1 Hora são de musica-> 0.5 de chance de musica
        if(x<1){
            //2 de 6 programas de 1/2 hora são de musica -> 2/6 de chance
            if(y<2){
                OnlyMusicA++;
            }
        }
    }

    double OnlyMusicB;
    //halfHour seguido de 1Hour
    for (int i = 0; i < rep; ++i) {
        int x = rand()%6;
        int y = rand()%2;
        //1 de 2 programas de 1 Hora são de musica-> 0.5 de chance de musica
        if(x<2){
            //2 de 6 programas de 1/2 hora são de musica -> 2/6 de chance
            if(y<1){
                OnlyMusicB++;
            }
        }
    }

    printf("Chance do programa ser apenas de musica: %.4f\n", (OnlyMusicA/rep)*(OnlyMusicB/rep));


    return 0;
}