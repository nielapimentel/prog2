#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "ponto.h"

struct ponto
{
    float x, y;
};

tPonto Pto_Cria (float x, float y){
    tPonto p = (tPonto) calloc(1, sizeof(struct ponto));
    p->x = x;
    p->y = y;

    return p;
}

void Pto_Apaga (tPonto p){
    free(p);
}

float Pto_Acessa_x (tPonto p){
    return p->x;
}

float Pto_Acessa_y (tPonto p){
    return p->y;
}

void Pto_Atribui_x (tPonto p, float x){
    p->x = x;
}

void Pto_Atribui_y (tPonto p, float y){
    p->y = y;
}

float Pto_Distancia (tPonto p1, tPonto p2){
    float distancia = 0;

    distancia = sqrtf(powf(p1->y - p2->y, 2) + powf(p1->x - p2->x, 2));

    return distancia;
}