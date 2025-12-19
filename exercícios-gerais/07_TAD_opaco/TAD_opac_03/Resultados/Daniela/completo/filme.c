#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "filme.h"

struct Filme
{
    int codigo;
    char nome[MAX_CARACTERES];
    int valor;
    int qtdEstoque;
    int qtdAlugada;
};

tFilme* CriarFilme(){
    tFilme* f = (tFilme*) calloc(1, sizeof(struct Filme));

    f->qtdAlugada = 0;

    return f;
}

void LeFilme(tFilme *filme, int codigo){

    scanf("%[^,],", filme->nome);
    scanf("%d,", &filme->valor);
    scanf("%d", &filme->qtdEstoque);

    //printf("\n%s %d %d\n", filme->nome, filme->valor, filme->qtdEstoque);

    filme->codigo = codigo;
}

void DestruirFilme (tFilme* filme){
    free(filme);
}

int ObterCodigoFilme (tFilme* filme){
    return filme->codigo;
}

void ImprimirNomeFilme (tFilme* filme){
    printf("%s", filme->nome);
}

int ObterValorFilme (tFilme* filme){
    return filme->valor;
}

int ObterQtdEstoqueFilme (tFilme* filme){
    return filme->qtdEstoque;
}

int ObterQtdAlugadaFilme (tFilme* filme){
    return filme->qtdAlugada;
}

int EhMesmoCodigoFilme (tFilme* filme, int codigo){
    if (filme->codigo == codigo){
        return 1;
    }
    return 0;
}

/**
 * @brief Incrementa a quantidade alugada e decrementa a quantidade em estoque do filme.
 * 
 * @param filme Ponteiro para o filme.
*/
void AlugarFilme (tFilme* filme){

    if (filme->qtdEstoque > 0){
        filme->qtdAlugada++;
        filme->qtdEstoque--;
    }
}

/**
 * @brief Decrementa a quantidade alugada e incrementa a quantidade em estoque do filme.
 * 
 * @param filme Ponteiro para o filme.
*/
void DevolverFilme (tFilme* filme){

    if (filme->qtdAlugada > 0){
        filme->qtdAlugada--;
        filme->qtdEstoque++;
    }
}

/**
 * @brief Compara dois filmes pelo nome.
 * 
 * @param filme1 Ponteiro para o primeiro filme.
 * @param filme2 Ponteiro para o segundo filme.
 * @return 1 se o nome do primeiro filme for maior que o nome do segundo filme, -1 se o nome do primeiro filme for menor que o nome do segundo filme, 0 se os nomes forem iguais.
*/
int CompararNomesFilmes (tFilme* filme1, tFilme* filme2){
    return strcmp(filme1->nome, filme2->nome);
}