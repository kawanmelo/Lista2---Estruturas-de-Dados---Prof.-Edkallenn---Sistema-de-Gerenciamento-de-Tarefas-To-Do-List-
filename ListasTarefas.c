#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaTarefas.h"

/*
** Função : Implementar um sistema de gerenciamento de tarefas (To-Do-List).
** Autor : Kawan Melo - 3º período turma F 2024.1
** Data : 30.05.2024
** Observações: Null
*/

ListaTarefas* CriaListaTarefas(){
  ListaTarefas *listaTarefas = malloc(sizeof(ListaTarefas));
  listaTarefas->inicio = NULL;
  listaTarefas->fim = NULL;
  listaTarefas->tam = 0;
  return listaTarefas;
}


int isEmpty(ListaTarefas* listaTarefas){
  return (listaTarefas->tam == 0);
}


void AdicionaTarefaInicio(ListaTarefas *listaTarefas, Tarefa* tarefa){
  Elemento *elemento = malloc(sizeof(Elemento));
  elemento->tarefa = tarefa;
  elemento->next = listaTarefas->inicio;
  if(listaTarefas->inicio != NULL){
    listaTarefas->inicio->prev = elemento;
  }
  listaTarefas->inicio = elemento;
  elemento->prev = NULL;
  if(isEmpty(listaTarefas)){
    listaTarefas->fim = elemento;
  }
  listaTarefas->tam++;
}


void AdicionaTarefaFinal(ListaTarefas *listaTarefas, Tarefa *tarefa){
  Elemento *elemento = malloc(sizeof(Elemento));
  elemento->tarefa = tarefa;
  elemento->prev = listaTarefas->fim;
  if(listaTarefas->fim != NULL){
    listaTarefas->fim->next = elemento;
  }
  listaTarefas->fim = elemento;
  elemento->next = NULL;
  if(isEmpty(listaTarefas)){
    listaTarefas->inicio = elemento;
  }
  listaTarefas->tam++;
}


Tarefa* RemoveTarefaInicio(ListaTarefas *listaTarefas){
  if(isEmpty(listaTarefas)){
    printf("Não há tarefas na lista!\n");
    return NULL;
  }
  Elemento *elemento = listaTarefas->inicio;
  Tarefa *tarefa = elemento->tarefa;
  listaTarefas->inicio = listaTarefas->inicio->next;
  free(elemento);
  listaTarefas->tam--;
  return tarefa;
}


Tarefa* RemoveTarefaFinal(ListaTarefas *listaTarefas){
  if(isEmpty(listaTarefas)){
    printf("Não há tarefas na lista!\n");
    return NULL;
  }
  Elemento *elemento = listaTarefas->fim;
  Tarefa *tarefa = elemento->tarefa;
  listaTarefas->fim = listaTarefas->fim->prev;
  if(listaTarefas->fim != NULL){
    listaTarefas->fim->next = NULL;
  } else {
    listaTarefas->inicio = NULL;
  }
  free(elemento);
  listaTarefas->tam--;
  return tarefa;
}


Tarefa* RemoveTarefa(ListaTarefas *listaTarefas, int id) {
  if (isEmpty(listaTarefas)) {
    printf("Não há tarefas na lista!\n");
    return NULL;
  }

  Elemento *atual = listaTarefas->inicio;
  while (atual != NULL && atual->tarefa->id != id) {
    atual = atual->next;
  }

  if (atual == NULL) {
    printf("Tarefa não encontrada!\n");
    return NULL;
  }

  if (atual->prev == NULL) {
    listaTarefas->inicio = atual->next;
    if (listaTarefas->inicio != NULL) {
      listaTarefas->inicio->prev = NULL;
    } else { 
        listaTarefas->fim = NULL;
      }
    }
    
  else if (atual->next == NULL) { 
    listaTarefas->fim = atual->prev;
    listaTarefas->fim->next = NULL;
  } 
  
  else {
        atual->prev->next = atual->next;
        atual->next->prev = atual->prev;
    }

    Tarefa *tarefa = atual->tarefa;
    free(atual);
    listaTarefas->tam--;
    return tarefa;
}



void PercorreListaRecursivo(Elemento *elemento) {
    if (elemento == NULL) {
        return;
    }
    if (elemento->tarefa != NULL) {
        printf("Tarefa ID : %d\n", elemento->tarefa->id);
        printf("Descrição : %s\n", elemento->tarefa->descricao);
        printf("Prioridade : %d\n", elemento->tarefa->prioridade);
        printf("Data de Vencimento : %d\n\n", elemento->tarefa->dataVencimento);
    }
    PercorreListaRecursivo(elemento->next);
}


void ExibeListaTarefasRecursivo(ListaTarefas *listaTarefas) {
    if (isEmpty(listaTarefas)) {
        printf("Não há tarefas na lista!\n");
        return;
    }
    PercorreListaRecursivo(listaTarefas->inicio);
}


void DestroyListaTarefas(ListaTarefas *listaTarefas){
  Elemento *elemento = listaTarefas->inicio;
  Elemento *aux = NULL;
  while(elemento != NULL){
    aux = elemento;
    elemento = elemento->next;
    free(aux);
  }
}