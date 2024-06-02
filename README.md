# Sistema de Gerenciamento de Tarefas (To-Do List)

## Objetivo

Desenvolver um sistema de gerenciamento de tarefas (To-Do List) em C, aplicando diferentes estruturas de dados para armazenar e manipular as tarefas.

## Funcionalidades

1. **Definição do TAD**: Criar um TAD para representar uma tarefa.
2. **Listas**: Utilizar uma lista encadeada para armazenar as tarefas a serem realizadas (To-Do List). Adicionar tarefas no início ou no final da lista.
3. **Pilhas**: Implementar uma pilha para armazenar tarefas concluídas. Quando uma tarefa é concluída, ela é removida da lista e movida para a pilha de tarefas concluídas.
4. **Filas**: Utilizar uma fila para agendar tarefas com data de vencimento. Ao adicionar uma tarefa com uma data futura, ela é colocada na fila para ser movida para a To-Do List quando a data chegar.
5. **Deques**: Implementar um deque para permitir a remoção eficiente tanto do início quanto do final da lista de tarefas.
6. **Funções adicionais**: Implementar uma função recursiva para percorrer a lista de tarefas e realizar alguma operação específica (ex: contar o número total de tarefas).

## Estrutura do Projeto

O projeto está dividido em vários arquivos principais, cada um responsável por uma parte específica do sistema:

1. **Fila Estática (`FilaEstatica.h`, `FilaEstatica.c`)**: Implementa a fila estática para o agendamento de consultas com médicos.
2. **Fila Dinâmica (`FilaDinamica.h`, `FilaDinamica.c`)**: Implementa a fila dinâmica para o agendamento de consultas com enfermagem.
3. **Interface de Usuário (`main.c`)**: Contém a função `main` e a interface de usuário para interagir com o sistema de agendamento.


## Contato
- **Autor:** Kawan Melo
- **Email:** [kawangcmelo@gmail.com](mailto:kawangcmelo@gmail.com)
- **LinkedIn:** [linkedin.com/in/kawanmelo](https://linkedin.com/in/kawanmelo)
