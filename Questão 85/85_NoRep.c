//
// Created by leona on 27/03/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Rep 100000


int main(){

    srand(time(NULL));

    double VV, VB, BV, BB;

    for (int i=0;i<Rep;i++) {
        int x = rand() % 100;
        int y = rand() % 100;
        double B_Vermelhas = 7;
        double B_Brancas = 3;
        double B_Urna = 10;

        if (x < (B_Vermelhas/B_Urna)*100) {
            B_Vermelhas--;
            B_Urna--;
            if (y < (B_Vermelhas/B_Urna)*100) {
                VV++;
            } else {
                VB++;
            }
        } else {
            B_Brancas--;
            B_Urna--;
            if (y < (B_Brancas/B_Urna)*100) {
                BB++;
            } else {
                BV++;
            }
        }
    }

    printf("Sem reposicao\nEspaco Amostral = (V,V)(V,B)(B,V)(B,B)\n");
    printf("Chance (V,V): %.3f\n", VV/Rep);
    printf("Chance (V,B): %.3f\n", VB/Rep);
    printf("Chance (B,V): %.3f\n", BV/Rep);
    printf("Chance (B,B): %.3f\n", BB/Rep);

    return 0;
}