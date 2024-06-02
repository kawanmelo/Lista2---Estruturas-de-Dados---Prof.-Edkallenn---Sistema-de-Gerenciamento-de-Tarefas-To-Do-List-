#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PilhaTarefas.h"

/*
** Função : Implementar um sistema de gerenciamento de tarefas (To-Do-List).
** Autor : Kawan Melo - 3º período turma F 2024.1
** Data : 30.05.2024
** Observações: Null
*/




PilhaTarefas* CreateStack(){
  PilhaTarefas *pilhaTarefas = malloc(sizeof(PilhaTarefas));
  pilhaTarefas->head = NULL;
  return pilhaTarefas;
}

void Push(PilhaTarefas *pilhaTarefas, Tarefa *tarefa){
  ElementoPilha *element = malloc(sizeof(ElementoPilha));
  element->tarefa = tarefa;
  element->next = pilhaTarefas->head;
  pilhaTarefas->head = element;
}

int IsEmpty(PilhaTarefas *pilhaTarefas){
  return (pilhaTarefas->head == NULL);
}

Tarefa* Pop(PilhaTarefas *pilhaTarefas){
  if(IsEmpty(pilhaTarefas)){
    printf("Pilha vazia!\n");
    return NULL;
  }
  ElementoPilha *aux = pilhaTarefas->head;
  Tarefa *tarefa = pilhaTarefas->head->tarefa;
  pilhaTarefas->head = pilhaTarefas->head->next;
  free(aux);
  return tarefa;
}

void Peek(PilhaTarefas *pilhaTarefas){
  if(IsEmpty(pilhaTarefas)){
    printf("Pilha vazia!\n");
    return;
  }
  printf("Última tarefa concluída: \n");
  printf("Tarefa #%d - %s\n\n", pilhaTarefas->head->tarefa->id, pilhaTarefas->head->tarefa->descricao);
}

void PrintStack(PilhaTarefas *pilhaTarefas){
  if(IsEmpty(pilhaTarefas)){
    printf("Pilha vazia!\n");
    return;
  }
  ElementoPilha *element = pilhaTarefas->head;
  printf("Tarefas Concluídas: \n\n");
  while(element != NULL){
    printf("Tarefa #%d - %s\n\n", element->tarefa->id, element->tarefa->descricao);
    element = element->next;
  }
}


void DestroyStack(PilhaTarefas *pilhaTarefas){
  ElementoPilha *element = pilhaTarefas->head;
  while(element != NULL){
    ElementoPilha *aux = element->next;
    free(element);
    element = aux;
  }
  free(pilhaTarefas);
}
