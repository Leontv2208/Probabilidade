#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define rep 100000

typedef struct{
    int Prob;
    double Count;
    int Promete;
    double PrometeCount;
    double NaoPrometeCount;
    int Cheque;
    double ChequeCount;
    double SemChequeCount;
}Doador;

int main(int argc, char const *argv[])
{
    Doador Ativo;
    Doador Passado;
    Doador Prospectivo;

    Ativo.Prob = 50;
    Ativo.Promete = 40;
    Ativo.Cheque = 80;

    Passado.Prob = 30;
    Passado.Promete = 30;
    Passado.Cheque = 60;

    Prospectivo.Prob = 20;
    Prospectivo.Promete = 10;
    Prospectivo.Cheque = 50;

    srand(time(NULL));

    int x,y,z;

    for (int i = 0; i < rep; ++i) {
        //loop porcentagens
        x=rand()%100;
        y=rand()%100;
        z=rand()%100;


        if(x<Ativo.Prob){
            Ativo.Count++;

            if(y<Ativo.Promete){
                Ativo.PrometeCount++;

                if(z<Ativo.Cheque){
                    Ativo.ChequeCount++;
                } else {
                    Ativo.SemChequeCount++;
                }
            } else {
                Ativo.NaoPrometeCount+=1;
            }

        } else if(x>(Ativo.Prob-1) && x<(Ativo.Prob+Passado.Prob)){
            Passado.Count++;

            if(y<Passado.Promete){
                Passado.PrometeCount++;

                if(z<Passado.Cheque){
                    Passado.ChequeCount++;
                } else {
                    Passado.SemChequeCount++;
                }
            } else {
                Passado.NaoPrometeCount++;
            }
        } else {
            Prospectivo.Count++;
            if(y<Prospectivo.Promete){
                Prospectivo.PrometeCount++;

                if(z<Prospectivo.Cheque){
                    Prospectivo.ChequeCount++;
                } else {
                    Prospectivo.SemChequeCount++;
                }
            } else {
                Prospectivo.NaoPrometeCount++;
            }
        }
    }

    //Chance doador ativo efetivar
    double Efetivo_Ativo = (Ativo.Count/rep)*(Ativo.PrometeCount/rep)*(Ativo.ChequeCount/rep);
    printf("Chance de ser ativo é %f\n", Efetivo_Ativo);

    //Chance doador passado efetivar
    double Efetivo_Passado = (Passado.Count/rep)*(Passado.PrometeCount/rep)*(Passado.ChequeCount/rep);
    printf("Chance de ser passado é %f\n", Efetivo_Passado);

    //Chance doador prospectivo efetivar
    double Efetivo_Prospectivo = (Prospectivo.Count/rep)*(Prospectivo.PrometeCount/rep)*(Prospectivo.ChequeCount/rep);
    printf("Chance de ser prospectivo é %f\n", Efetivo_Prospectivo);

    //Chance total de alguém efetivar
    double total = Efetivo_Ativo+Efetivo_Passado+Efetivo_Prospectivo;

    printf("A chance de algum doador efetivar é de %f\n", total);

    return 0;
}