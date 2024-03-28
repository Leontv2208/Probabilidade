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

    double B_Vermelhas = 7;
    double B_Brancas = 3;

    double VV, VB, BV, BB;

    double B_Urna = B_Brancas+B_Vermelhas;

    double C_Vermelha = (B_Vermelhas/B_Urna)*100;
    double C_Branca = (B_Brancas/B_Urna)*100;

    for (int i=0;i<Rep;i++) {
        int x = rand() % RAND_MAX;
        int y = rand() % RAND_MAX;

        if (x < C_Vermelha) {
            if (y < C_Vermelha) {
                VV++;
            } else {
                VB++;
            }
        } else {
            if (y < C_Vermelha) {
                BV++;
            } else {
                BB++;
            }
        }
    }

    printf("Com reposicao\nEspaco Amostral = (V,V)(V,B)(B,V)(B,B)\n");
    printf("Chance (V,V): %.2f\n", VV/Rep);
    printf("Chance (V,B): %.2f\n", VB/Rep);
    printf("Chance (B,V): %.2f\n", BV/Rep);
    printf("Chance (B,B): %.2f\n", BB/Rep);

    return 0;
};