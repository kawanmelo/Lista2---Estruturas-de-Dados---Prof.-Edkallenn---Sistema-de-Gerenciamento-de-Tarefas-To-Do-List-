#ifndef FILA_TAREFAS_H
#define FILA_TAREFAS_H

#include <stdio.h>
#include "Tarefa.h"

/*
** Função : Implementar um sistema de gerenciamento de tarefas (To-Do-List).
** Autor : Kawan Melo - 3º período turma F 2024.1
** Data : 30.05.2024
** Observações: Null
*/

typedef struct elementoFila ElementoFila;
struct elementoFila{
  Tarefa *tarefa;
  ElementoFila *next;
  ElementoFila *prev;
};

typedef struct{
  ElementoFila *inicio;
  ElementoFila *fim;
  int tam;
}FilaTarefas;

FilaTarefas* CriaFilaTarefas();
int IsEmptyFila(FilaTarefas *fila);
void AdiocionaNaFila(FilaTarefas *fila, Tarefa *tarefa);
Tarefa* RemovePrimeiroDaFila(FilaTarefas *fila);
Tarefa* RemoveDaFila();
void ExibeFila(FilaTarefas *fila);
void DestroyFila(FilaTarefas *fila);

#endif // FILA_TAREFAS