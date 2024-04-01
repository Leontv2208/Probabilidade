//
// Created by leona on 27/03/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 100
#define Rep 100000


int main(){

    srand(time(NULL));

    double VV, VB, BV, BB;

    for (int i=0;i<Rep;i++) {
        int x = rand() % max;
        int y = rand() % max;
        double B_Vermelhas = 7;
        double B_Brancas = 3;
        double B_Urna = B_Brancas+B_Vermelhas;

        if (x < (B_Vermelhas/B_Urna)*100) {
            B_Vermelhas--;
            if (y < (B_Vermelhas/B_Urna)*100) {
                VV++;
            } else {
                VB++;
            }
        } else {
            B_Brancas--;
            if (y < (B_Vermelhas/B_Urna)*100) {
                BV++;
            } else {
                BB++;
            }
        }
    }

    printf("Sem reposicao\nEspaco Amostral = (V,V)(V,B)(B,V)(B,B)\n");
    printf("Chance (V,V): %f\n", VV/Rep);
    printf("Chance (V,B): %f\n", VB/Rep);
    printf("Chance (B,V): %f\n", BV/Rep);
    printf("Chance (B,B): %f\n", BB/Rep);

    return 0;
}