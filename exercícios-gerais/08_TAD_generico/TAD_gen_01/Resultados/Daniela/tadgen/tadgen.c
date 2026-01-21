#include <stdio.h>
#include <stdlib.h>
#include "tadgen.h"

struct generic {
   int qtd;
   Type type;
   void* vetorGen;
};

tGeneric* CriaGenerico(Type type, int numElem) {
    tGeneric* g = (tGeneric*) calloc(1, sizeof(tGeneric));
    g->type = type;
    g->qtd = numElem;

    if(type == INT){
        g->vetorGen = calloc(g->qtd, sizeof(int));
    } else {
        g->vetorGen = calloc(g->qtd, sizeof(float));
    }

    return g;
}

void DestroiGenerico(tGeneric* gen) {
    free(gen->vetorGen);
    free(gen);
}

void LeGenerico(tGeneric* gen) {

    if(gen->type == INT){
        int* vet = (int*) gen->vetorGen;
        for (int i=0; i<gen->qtd; i++){
            scanf("%d", &vet[i]);
        }
   } else {
        float* vet = (float*) gen->vetorGen;
        for (int i=0; i<gen->qtd; i++){
            scanf("%f", &vet[i]);
        }
   }
}

void ImprimeGenerico(tGeneric* gen) {
   printf ("\nDigite o vetor:\n");

   if (gen == NULL) return;

   int i;

   if (gen->type == INT) {
       int* vet = (int*) gen->vetorGen;
       for (i = 0; i < gen->qtd; i++) {
           printf("%d ", vet[i]);
       }
   } else { // FLOAT
       float* vet = (float*) gen->vetorGen;
       for (i = 0; i < gen->qtd; i++) {
           printf("%.2f ", vet[i]);
       }
   }

   printf("\n");
}

