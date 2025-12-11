#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empresa.h"
#include "funcionario.h"

struct empresa
{
  int idUnico;
  int qtdFuncionarios, qtdMax;
  tFuncionario** bancoFuncionarios;
};


/**
 * @brief Cria uma empresa "vazia"
 * 
 * Seus atributos devem ser inicializados com NULL (ponteiros), ou -1 caso contrário
 * @return TEmpresa* Ponteiro para empresa criada a partir do Id fornecido.
 */
tEmpresa* CriaEmpresa(){
  tEmpresa* e = (tEmpresa *) calloc(1, sizeof(tEmpresa));

  e->idUnico=-1;
  e->qtdFuncionarios = 0;
  e->qtdMax =1;
  e->bancoFuncionarios = NULL;

  return e;
}

/**
 * @brief Le os dados de uma empresa da entrada padrao.
 * @param *empresa - ponteiro para empresa que terá seus dados preenchidos
 */
void LeEmpresa(tEmpresa* empresa){
  scanf("%d %d\n", &empresa->idUnico, &empresa->qtdMax);
  empresa->bancoFuncionarios = (tFuncionario**) calloc(empresa->qtdMax, sizeof(tFuncionario*));
  for (int i=0; i<empresa->qtdMax; i++){
    tFuncionario* f = CriaFuncionario();
    LeFuncionario(f);

    ContrataFuncionarioEmpresa(empresa, f);
  }
}

/**
 * @brief Libera toda a memória alocada dinamicamente para uma empresa
 * @param *empresa - ponteiro para empresa que terá seus dados apagados e memória liberada
 */
void ApagaEmpresa(tEmpresa* empresa){
  for (int i=0; i<empresa->qtdFuncionarios; i++){
    ApagaFuncionario(empresa->bancoFuncionarios[i]);
  }
  free(empresa->bancoFuncionarios);
  free(empresa);
}


/**
 * @brief Adiciona um funcionario a uma empresa caso o id do funcionario ainda nao esteja registrado na empresa.
 * 
 * @param empresa Ponteiro para Empresa em que o funcionario deve ser adicionado.
 * @param funcionario Ponteiro para Funcionario que deve ser adicionado a empresa.
  */
void ContrataFuncionarioEmpresa(tEmpresa* empresa, tFuncionario* funcionario){
  int funcionarioJaExiste = 0;

  for (int i=0; i<empresa->qtdFuncionarios; i++){
    if (GetIdFuncionario(empresa->bancoFuncionarios[i]) == GetIdFuncionario(funcionario)){
      funcionarioJaExiste = 1;
      printf ("A empresa %d ja possui um funcionario com o id %d\n", empresa->idUnico, GetIdFuncionario(empresa->bancoFuncionarios[i]));
      ApagaFuncionario(funcionario);
      break;
    }
  }

  if (funcionarioJaExiste == 0){
    empresa->bancoFuncionarios[empresa->qtdFuncionarios] = funcionario;
    empresa->qtdFuncionarios++;
  }
}

/**
 * @brief Imprime todos os dados de um empresa.
 * 
 * @param empresa Ponteiro para Empresa a ser impressa no terminal.
 */
void ImprimeEmpresa(tEmpresa *empresa){
  printf ("Empresa %d:\n", empresa->idUnico);
  for (int i=0; i<empresa->qtdFuncionarios; i++){
    ImprimeFuncionario(empresa->bancoFuncionarios[i]);
  }
}
