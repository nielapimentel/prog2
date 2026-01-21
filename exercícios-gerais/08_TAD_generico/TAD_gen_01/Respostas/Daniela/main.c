#include "tadgen.h"
#include <stdio.h>

int main (){
    Type type;
    int qtd;

    printf("tad_gen_01\nDigite o tipo e numero de elementos: ");
    scanf("%d %d", &type, &qtd);

    tGeneric* g;
    g = CriaGenerico(type, qtd);
    LeGenerico(g);
    ImprimeGenerico(g);
    DestroiGenerico(g);

    return 0;
}