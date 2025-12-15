#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "array.h"

struct Array {
    int* vetorNumeros;
    int tamVetor;
};

/**
 * @brief Inicializa um novo array, apontando data para NULL e tamanho para 0.
 * @return Ponteiro para a estrutura Array criada ou encerra caso não seja possível alocar memória.
 */
Array* CriarArray(){
    Array * v = (Array *) calloc (1, sizeof(Array));
    v->tamVetor = 0;
    v->vetorNumeros = NULL;

    return v;
}


/**
 * @brief Libera a memória alocada para o array.
 * @param array Ponteiro para a estrutura Array a ser destruída.
 */
void DestruirArray(Array *array){
    free(array->vetorNumeros);
    free(array);
}

/**
 * @brief Lê os elementos do array a partir da entrada padrão e aloca memória para eles.
 * @details A leitura é feita até encontrar um ponto final (.) na entrada.
 * @param array Ponteiro para a estrutura Array a ser preenchida.
 */
void LerArray(Array *array){
    char caracter;
    int inteiro = 0;

    while (scanf ("%d", &inteiro) == 1){
            array->vetorNumeros = realloc(array->vetorNumeros, (array->tamVetor+1) * sizeof(int));
            array->vetorNumeros[array->tamVetor] = inteiro;
            array->tamVetor++;
            
            scanf ("%c", &caracter);

            if (caracter == '.'){
                break;
            }
    }
}

/**
 * @brief Ordena os elementos do array em ordem crescente.
 * @param array Ponteiro para a estrutura Array a ser ordenada.
 */
void OrdenarArray(Array *array){
    int aux;

    for (int i =0; i<array->tamVetor - 1; i++){
        for (int j = i + 1; j< array->tamVetor; j++){            
            if (array->vetorNumeros[i] > array->vetorNumeros[j]){
                aux = array->vetorNumeros[i];
                array->vetorNumeros[i] = array->vetorNumeros[j];
                array->vetorNumeros[j] = aux;
            }
        }
    }
}

/**
 * @brief Realiza uma busca binária no array pelo elemento especificado.
 * @param array Ponteiro para a estrutura Array a ser buscada.
 * @param elementoBuscado Elemento a ser buscado no array.
 * @return Índice do elemento buscado no array, ou -1 caso não seja encontrado.
 */
int BuscaBinariaArray(Array *array, int elementoBuscado){
    int inicio = 0;
    int fim = array->tamVetor-1;

    while (inicio <= fim){
        int meio = (inicio + fim)/2;

        if (array->vetorNumeros[meio] == elementoBuscado){
            return meio;
        } else if (array->vetorNumeros[meio] < elementoBuscado){
            inicio = meio + 1;
        } else {
            fim = meio -1;
        }

    }

    return -1;
}
