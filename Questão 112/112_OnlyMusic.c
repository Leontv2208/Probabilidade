#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define rep 100000

double calcula_chance(double a, double b){
    double count;
    for (int i = 0; i < rep; ++i) {
        int x = rand()%100;
        int y = rand()%100;
        //1 de 2 programas de 1 Hora são de musica-> 0.5 de chance de musica
        if(x<a){
            //2 de 6 programas de 1/2 hora são de musica -> 2/6 de chance
            if(y<b){
                count++;
            }
        }
    }
}

int main(){

    srand(time(NULL));

    double Musica1H = 50;
    double MusicaHalfH = 33.33;

    double OnlyMusicA = 0;
    //1Hour seguido halfHour
    OnlyMusicA = calcula_chance(Musica1H, MusicaHalfH);

    double OnlyMusicB;
    //halfHour seguido de 1Hour
    OnlyMusicB = calcula_chance(MusicaHalfH, Musica1H);

    printf("Chance do programa ser apenas de musica: %.4f\n", (OnlyMusicA/rep)*(OnlyMusicB/rep));


    return 0;
}