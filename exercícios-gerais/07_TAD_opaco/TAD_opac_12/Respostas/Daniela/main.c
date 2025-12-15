#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int main(){
    Array* a = CriarArray();
    LerArray(a);
    OrdenarArray(a);

    int esperado=0;
    scanf ("%d", &esperado);

    int indice = -1;
    indice = BuscaBinariaArray(a, esperado);

    if (indice == -1){
        printf ("Elemento %d não encontrado no array (%d).\n", esperado, indice);
    }else {
        printf ("Elemento %d encontrado no índice %d.\n", esperado, indice);
    }
        

    DestruirArray(a);
}