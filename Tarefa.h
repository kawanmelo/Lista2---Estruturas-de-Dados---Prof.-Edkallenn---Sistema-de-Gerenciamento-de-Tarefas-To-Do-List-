#ifndef TAREFA_H
#define TAREFA_H

#include <stdio.h>

/*
** Função : Implementar um sistema de gerenciamento de tarefas (To-Do-List).
** Autor : Kawan Melo - 3º período turma F 2024.1
** Data : 30.05.2024
** Observações: Adicionei um campo identificador para facilitar o manuseio da estrutura.
*/

typedef struct {
int id; // identificador da tarefa
char descricao[100];
int prioridade; // 1 (baixa), 2 (média), 3 (alta)
int dataVencimento; // formato DDMMYYYY
} Tarefa;

Tarefa* CriaTarefa(int id, char descricao[100], int prioridade, int dataVencimento);

#endif // TAREFA_H