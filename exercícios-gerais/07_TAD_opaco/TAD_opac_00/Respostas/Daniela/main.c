#include <stdio.h>
#include <stdlib.h>

#include "circulo.h"

int main (){
    float centroX, centroY;
    float raio;
    float pontoX, pontoY;

    scanf("%f %f %f %f %f", &centroX, &centroY, &raio, &pontoX, &pontoY);
    tCirculo c = Circulo_Cria(centroX, centroY, raio);
    tPonto p = Pto_Cria(pontoX, pontoY);

    if (Circulo_Interior(c, p)){
        printf("1");
    } else {
        printf("0");
    }

    Circulo_Apaga(c);
    Pto_Apaga(p);

    return 0;
}