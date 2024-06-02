#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ListaTarefas.h"
#include "PilhaTarefas.h"
#include "FilaTarefas.h"

/*
** Função : Implementar um sistema de gerenciamento de tarefas (To-Do-List).
** Autor : Kawan Melo - 3º período turma F 2024.1
** Data : 30.05.2024
** Observações: Null
*/

int GetCurrentDate() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int dateInt = (tm.tm_mday * 1000000) + ((tm.tm_mon + 1) * 10000) + (tm.tm_year + 1900);
    return dateInt;
}

/*

void VerificarTarefasAgendadas(FilaTarefas *fila, ListaTarefas *lista) {
    int data = GetCurrentDate();
    ElementoFila *elemento = fila->inicio;
    while (elemento != NULL) {
        ElementoFila *proximoElemento = elemento->next; // Salva o próximo elemento
        if (elemento->tarefa != NULL && elemento->tarefa->dataVencimento == data) {
            Tarefa *tarefaMove = RemoveDaFila(fila, elemento->tarefa->id);
            if (tarefaMove != NULL) {
                AdicionaTarefaFinal(lista, tarefaMove);
            }
        }
        elemento = proximoElemento; // Atualiza para o próximo elemento
    }
}

*/

void LimpaTela() {
    printf("Aperte enter para continuar...");
    getchar();
    system("clear");
}

int main() {
    // Criação das listas e fila
    ListaTarefas *toDoList = CriaListaTarefas();
    FilaTarefas *tarefasAgendadas = CriaFilaTarefas();
    PilhaTarefas *tarefasConcluidas = CreateStack();

    int opcao, id, prioridade, dataVencimento;
    char descricao[100];
    Tarefa *tarefa;

    do {
        printf("\n--- ToDoList ---\n");
        printf("1. Adicionar tarefa\n");
        printf("2. Agendar Tarefa\n");
        printf("3. Marcar tarefa como concluída\n");
        printf("4. Exibir tarefas\n");
        printf("5. Exibir tarefas agendadas\n");
        printf("6. Exibir tarefas concluídas\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer do teclado

        switch (opcao) {
            case 1:
                printf("ID da tarefa: ");
                scanf("%d", &id);
                getchar(); // Limpar o buffer do teclado
                printf("Descrição da Tarefa: ");
                fgets(descricao, sizeof(descricao), stdin);
                descricao[strcspn(descricao, "\n")] = 0; // Remover o caractere de nova linha
                printf("Prioridade da Tarefa (1 - baixa; 2 - média; 3 - alta): ");
                scanf("%d", &prioridade);
                getchar();
                dataVencimento = GetCurrentDate();
                tarefa = CriaTarefa(id, descricao, prioridade, dataVencimento);
                AdicionaTarefaFinal(toDoList, tarefa);
                printf("Tarefa adicionada!\n");
                LimpaTela();
                break;
            case 2:
                printf("ID da tarefa: ");
                scanf("%d", &id);
                getchar(); // Limpar o buffer do teclado
                printf("Descrição da Tarefa: ");
                fgets(descricao, sizeof(descricao), stdin);
                descricao[strcspn(descricao, "\n")] = 0; // Remover o caractere de nova linha
                printf("Prioridade da Tarefa (1 - baixa; 2 - média; 3 - alta): ");
                scanf("%d", &prioridade);
                printf("Data da tarefa (Formato: DDMMYYYY, EX: 11032005): ");
                scanf("%d", &dataVencimento);
                getchar();
                tarefa = CriaTarefa(id, descricao, prioridade, dataVencimento);
                int dataHoje = GetCurrentDate();
                if(dataVencimento == dataHoje){
                  AdicionaTarefaFinal(toDoList, tarefa);
                  printf("Tarefa agendada\n");
                  LimpaTela();
                  break;
                }
                AdiocionaNaFila(tarefasAgendadas, tarefa);
                printf("Tarefa agendada!\n");
                LimpaTela();
                break;
            case 3:
                if (isEmpty(toDoList)) {
                    printf("Não há tarefas na lista!\n");
                    LimpaTela();
                    break;
                }
                printf("Digite o ID da tarefa concluída: ");
                scanf("%d", &id);
                getchar();
                tarefa = RemoveTarefa(toDoList, id);
                if (tarefa != NULL) {
                    Push(tarefasConcluidas, tarefa);
                    printf("%s concluída!\n", tarefa->descricao);
                }
                LimpaTela();
                break;
            case 4:
                ExibeListaTarefasRecursivo(toDoList);
                LimpaTela();
                break;
            case 5:
                ExibeFila(tarefasAgendadas);
                LimpaTela();
                break;
            case 6:
                PrintStack(tarefasConcluidas);
                LimpaTela();
                break;
            case 0:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                LimpaTela();
                break;
        }
     //   VerificarTarefasAgendadas(tarefasAgendadas, toDoList);
    } while (opcao != 0);

    // Destruição das listas e fila
    DestroyListaTarefas(toDoList);
    DestroyFila(tarefasAgendadas);
    DestroyStack(tarefasConcluidas);

    return 0;
}