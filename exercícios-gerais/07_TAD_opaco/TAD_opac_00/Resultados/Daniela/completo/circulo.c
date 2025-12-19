#include <stdio.h>
#include <stdlib.h>

#include "circulo.h"

struct circulo
{
    tPonto* centro;
    float raio;
};

tCirculo Circulo_Cria (float x, float y, float r){
    tCirculo c = (tCirculo)calloc(1,sizeof(struct circulo));
    c->centro = Pto_Cria(x, y);

    c->raio = r;

    // printf("CENTRO X:%f\n", Pto_Acessa_x(c->centro));
    // printf("CENTRO Y:%f\n", Pto_Acessa_y(c->centro));
    // printf("RAIO: %f\n", c->raio);

    return c;
}

void Circulo_Apaga (tCirculo c){
    Pto_Apaga(c->centro);
    free(c);
}

tPonto Circulo_Acessa_Centro (tCirculo c){
    return c->centro;
}

float Circulo_Acessa_Raio (tCirculo c){
    return c->raio;
}

void Circulo_Atribui_Centro (tCirculo c, tPonto p){
    Pto_Atribui_x(c->centro, Pto_Acessa_x(p));
    Pto_Atribui_y(c->centro, Pto_Acessa_y(p));
}

void Circulo_Atribui_Raio (tCirculo c, float r){
    c->raio = r;
}

int Circulo_Interior (tCirculo c, tPonto p){
    // printf("CENTRO X:%f\n", Pto_Acessa_x(c->centro));
    // printf("CENTRO Y:%f\n", Pto_Acessa_y(c->centro));
    // printf("RAIO: %f\n", c->raio);

    tPonto centro = Circulo_Acessa_Centro(c);
    float raio = Circulo_Acessa_Raio(c);

    if (Pto_Distancia(centro, p) <= raio){
        return 1;
    }
    return 0;
}