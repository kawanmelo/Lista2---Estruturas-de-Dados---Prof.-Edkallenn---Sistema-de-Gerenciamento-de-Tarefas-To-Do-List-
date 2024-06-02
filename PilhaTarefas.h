#ifndef PILHA_TAREFAS_H
#define PILHA_TAREFAS_H

#include <stdio.h>
#include "Tarefa.h"
/*
** Função : Implementar um sistema de gerenciamento de tarefas (To-Do-List).
** Autor : Kawan Melo - 3º período turma F 2024.1
** Data : 30.05.2024
** Observações: Null
*/

typedef struct elementoPilha ElementoPilha;
struct elementoPilha{
  Tarefa *tarefa;
  ElementoPilha *next;
};


typedef struct pilhaTarefas PilhaTarefas;
struct pilhaTarefas{
  ElementoPilha *head;
};

PilhaTarefas* CreateStack();
void Push(PilhaTarefas *pilhaTarefas, Tarefa *tarefa);
int IsEmpty(PilhaTarefas *pilhaTarefas);
Tarefa* Pop(PilhaTarefas *pilhaTarefas);
void Peek(PilhaTarefas *pilhaTarefas);
void PrintStack(PilhaTarefas *pilhaTarefas);
void DestroyStack(PilhaTarefas *pilhaTarefas);

#endif // PILHA_TAREFAS_H