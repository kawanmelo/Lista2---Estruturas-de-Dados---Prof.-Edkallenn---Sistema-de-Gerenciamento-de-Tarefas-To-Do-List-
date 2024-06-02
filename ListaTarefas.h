#ifndef LISTA_TAREFAS_H
#define LISTA_TAREFAS_H

#include <stdio.h>
#include "Tarefa.h"

/*
** Função : Implementar um sistema de gerenciamento de tarefas (To-Do-List).
** Autor : Kawan Melo - 3º período turma F 2024.1
** Data : 30.05.2024
** Observações: Null
*/

typedef struct elemento Elemento;
struct elemento{
  Tarefa *tarefa;
  Elemento *next;
  Elemento *prev;
};

typedef struct{
  Elemento *inicio;
  Elemento *fim;
  int tam;
}ListaTarefas;

ListaTarefas* CriaListaTarefas();
int isEmpty(ListaTarefas* listaTarefas);
void AdicionaTarefaInicio(ListaTarefas *listaTarefas, Tarefa* tarefa);
void AdicionaTarefaFinal(ListaTarefas *listaTarefas, Tarefa *tarefa);
Tarefa* RemoveTarefa(ListaTarefas *listaTarefas, int id);
Tarefa* RemoveTarefaInicio(ListaTarefas *listaTarefas);
Tarefa* RemoveTarefaFinal(ListaTarefas *listaTarefas);
void PercorreListaRecursivo(Elemento *elemento);
void ExibeListaTarefasRecursivo(ListaTarefas *listaTarefas);
void DestroyListaTarefas(ListaTarefas *listaTarefas);

#endif // LISTA_TAREFAS_H