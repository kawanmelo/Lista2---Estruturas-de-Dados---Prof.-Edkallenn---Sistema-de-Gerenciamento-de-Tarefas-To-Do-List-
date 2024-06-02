#include <stdio.h>
#include <stdlib.h>
#include "FilaTarefas.h"

/*
** Função : Implementar um sistema de gerenciamento de tarefas (To-Do-List).
** Autor : Kawan Melo - 3º período turma F 2024.1
** Data : 30.05.2024
** Observações: Null
*/

FilaTarefas* CriaFilaTarefas(){
  FilaTarefas *fila = malloc(sizeof(FilaTarefas));
  fila->inicio = NULL;
  fila->fim = NULL;
  fila->tam = 0;
  return fila;
}


int IsEmptyFila(FilaTarefas *fila){
  return (fila->tam == 0);
}


void AdiocionaNaFila(FilaTarefas *fila, Tarefa *tarefa){
  ElementoFila *elemento = malloc(sizeof(ElementoFila));
  elemento->tarefa = tarefa;
  elemento->prev = fila->fim;
  elemento->next = NULL;
  if(fila->fim != NULL){
    fila->fim->next = elemento;
  }
  if(IsEmptyFila(fila)){
    fila->inicio = elemento;
  }
  fila->fim = elemento;
  fila->tam++;
}

Tarefa* RemoveDaFila(FilaTarefas *fila, int id){
  if(IsEmptyFila(fila)){
    printf("Não há tarefas na lista!\n");
    return NULL;
  }
  ElementoFila *atual = fila->inicio;
  while(atual != NULL && atual->tarefa->id != id){
    atual = atual->next;
  }
  if(atual == NULL){
    printf("Tarefa não encontrada!\n");
    return NULL;
  }
  if(atual->prev == NULL){
    atual->next->prev = NULL;
    fila->inicio = atual->next;
  }
  if(atual == fila->fim){
      fila->fim = fila->fim->prev;
  }
  else{
    atual->prev->next = atual->next;
    atual->next->prev = atual->prev;
  }
  Tarefa *tarefa = atual->tarefa;
  free(atual);
  fila->tam--;
  return tarefa;
}

Tarefa* RemovePrimeiroDaFila(FilaTarefas *fila){
  if(IsEmptyFila(fila)){
    printf("Não há tarefas agendadas!");
    return NULL;
  }
  ElementoFila *elemento = fila->inicio;
  Tarefa *tarefa = elemento->tarefa;
  fila->inicio = fila->inicio->next;
  fila->tam--;
  free(elemento);
  return tarefa;
}

void ExibeFila(FilaTarefas *fila) {
  if (IsEmptyFila(fila)) {
    printf("Não há tarefas agendadas!\n");
    return;
    }
  ElementoFila *elemento = fila->inicio;
  while (elemento != NULL) {
    if (elemento->tarefa != NULL) {
      printf("Tarefa ID : %d\n", elemento->tarefa->id);
      printf("Descrição : %s\n", elemento->tarefa->descricao);
      printf("Prioridade : %d\n", elemento->tarefa->prioridade);
      printf("Data de Vencimento : %d\n\n", elemento->tarefa->dataVencimento);
    }
    elemento = elemento->next;
  }
}


void DestroyFila(FilaTarefas *fila){
  ElementoFila *elemento = fila->inicio;
  while(elemento != NULL){
    ElementoFila *aux = elemento;
    free(aux);
    elemento = elemento->next;
  }
}