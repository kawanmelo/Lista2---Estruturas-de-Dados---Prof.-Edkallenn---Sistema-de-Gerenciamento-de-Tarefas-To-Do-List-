#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tarefa.h"

/*
** Função : Implementar um sistema de gerenciamento de tarefas (To-Do-List).
** Autor : Kawan Melo - 3º período turma F 2024.1
** Data : 30.05.2024
** Observações: Null
*/

Tarefa* CriaTarefa(int id, char descricao[100], int prioridade, int dataVencimento){
  Tarefa *tarefa = malloc(sizeof(Tarefa));
  tarefa->id = id;
  strcpy(tarefa->descricao, descricao);
  tarefa->prioridade = prioridade;
  tarefa->dataVencimento = dataVencimento;
  return tarefa;
}