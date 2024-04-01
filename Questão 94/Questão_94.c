#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define rep 100000


typedef struct{
    double ProbCount;
    double PrometeCount;
    double ChequeCount;
}Doador;

int main(int argc, char const *argv[])
{
    Doador Ativo;
    Doador Passado;
    Doador Prospectivo;

    Ativo.ProbCount = 0;
    Ativo.PrometeCount = 0;
    Ativo.ChequeCount = 0;

    Passado.ProbCount = 0;
    Passado.PrometeCount = 0;
    Passado.ChequeCount = 0;

    Prospectivo.ProbCount = 0;
    Prospectivo.PrometeCount = 0;
    Prospectivo.ChequeCount = 0;

    srand(time(NULL));

    int x,y,z;

    for (int i = 0; i < rep; ++i) {
        //loop porcentagens
        x=rand()%100;
        y=rand()%100;
        z=rand()%100;


        if(x<50){
            Ativo.ProbCount++;
            if(y<40){
                Ativo.PrometeCount++;
                if(z<80){
                    Ativo.ChequeCount++;
                }
            }
        } else if(x>=(100-30)){
            Passado.ProbCount++;
            if(y<30){
                Passado.PrometeCount++;
                if(z<60){
                    Passado.ChequeCount++;
                }
            }
        } else {
            Prospectivo.ProbCount++;
            if(y<10){
                Prospectivo.PrometeCount++;
                if(z<50){
                    Prospectivo.ChequeCount++;
                }
            }
        }
    }

    //Chance doador ativo efetivar
    double Efetivo_Ativo = (Ativo.ProbCount/rep) * (Ativo.PrometeCount/Ativo.ProbCount) * (Ativo.ChequeCount/Ativo.PrometeCount);
    printf("Chance de ser ativo é %f\n", Efetivo_Ativo);

    //Chance doador passado efetivar
    double Efetivo_Passado = (Passado.ProbCount/rep) * (Passado.PrometeCount/Passado.ProbCount) * (Passado.ChequeCount/Passado.PrometeCount);
    printf("Chance de ser passado é %f\n", Efetivo_Passado);

    //Chance doador prospectivo efetivar
    double Efetivo_Prospectivo = (Prospectivo.ProbCount/rep) * (Prospectivo.PrometeCount/Prospectivo.ProbCount) * (Prospectivo.ChequeCount/Prospectivo.PrometeCount);
    printf("Chance de ser prospectivo é %f\n", Efetivo_Prospectivo);

    //Chance total de alguém efetivar
    double total = (Efetivo_Ativo+Efetivo_Passado+Efetivo_Prospectivo);

    printf("A chance de algum doador efetivar é de %.3f\n", total);

    return 0;
}