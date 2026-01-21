#include "pacote.h"
#include <stdio.h>
#include <stdlib.h>

struct pacote{
    Type type; //int 1, char =0
    int numElem;
    int numAlocado;
    void* vetor;
    int verificacao;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar um pacote a ser transmitido
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tPacote* CriaPacote(Type type, int numElem){
    tPacote* p = (tPacote*) calloc(1, sizeof(tPacote));
    p->numElem = numElem;
    p->numAlocado = 0;
    p->verificacao = 0;

    if (type == INT){
        p->vetor = calloc(numElem, sizeof(int));
    } else {
        p->vetor = calloc(numElem, sizeof(char));
    }

    return p;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param pac - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiPacote(tPacote* pac){
    free(pac->vetor);
    free(pac);
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param pac - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LePacote(tPacote* pac){
    if(type == INT){
        int* vet = (int*) pac->vetor;
        for (int i=0; i< pac->numElem; i++){
            scanf("%d", &vet[i]);
        }
    } else {
        char* vet = (char*) pac->vetor;
        for (int i=0; i< pac->numElem; i++){       
            scanf("%c", &vet[i]);
        }
    }
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param pac - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimePacote(tPacote* pac){

}

/**
 * @brief Calcula a soma de verificacao de um pacote e a armazena internamente
 *
 * @param pac - O vetor genérico que terá sua soma de verificacao calculada
 */
void CalculaSomaVerificacaoPacote(tPacote* pac){

    if (pac->type == INT){
        int* vet = (int*)pac->vetor;

        for (int i=0; i<pac->numElem; i++){
            verificacao =+ vet[i];
        }
    } else {
        char* vet = (char*)pac->vetor;
        
        for (int i=0; i<pac->numElem; i++){
            verificacao =+ vet[i];
        }
    }

}
