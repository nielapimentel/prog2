#include <stdio.h>
#include <stdlib.h>
#include "empresa.h"

int main (){

    int qtdEmpresa;
    scanf("%d\n", &qtdEmpresa);

    tEmpresa** bancoEmpresas[qtdEmpresa];

    for (int i=0; i<qtdEmpresa; i++){
        tEmpresa* e = CriaEmpresa();
        LeEmpresa(e);

        bancoEmpresas[i] = e;
    }

    for (int i=0; i<qtdEmpresa; i++){
        ImprimeEmpresa(bancoEmpresas[i]);
        ApagaEmpresa(bancoEmpresas[i]);
    }

    return 0;
}