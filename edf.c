#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar uma tarefa
struct tarefa
{
    int id;
    int tempo_de_execucao;
    int tempo_de_retorno;
};

// Função para calcular o tempo de retorno de uma tarefa
int calcular_tempo_de_retorno(struct tarefa *tarefa)
{
    return tarefa->tempo_de_execucao + tarefa->tempo_de_retorno;
}

// Função para ordenar as tarefas por tempo de retorno
void ordenar_tarefas(struct tarefa *tarefas, int n)
{
    int i, j;
    struct tarefa aux;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (calcular_tempo_de_retorno(&tarefas[i]) > calcular_tempo_de_retorno(&tarefas[j]))
            {
                struct tarefa aux = tarefas[i];
                tarefas[i] = tarefas[j];
                tarefas[j] = aux;
            }
        }
    }
}

// Função principal
int main()
{
    // Declarando variáveis
    int n;
    struct tarefa *tarefas;
    int i;

    // Lendo o número de tarefas
    printf("Digite o numero de tarefas: ");
    scanf("%d", &n);

    // Alocando memória para as tarefas
    tarefas = (struct tarefa *)malloc(n * sizeof(struct tarefa));

    // Lendo os dados das tarefas
    for (i = 0; i < n; i++)
    {
        printf("Digite o ID da tarefa %d: ", i + 1);
        scanf("%d", &tarefas[i].id);
        printf("Digite o tempo de execução da tarefa %d: ", i + 1);
        scanf("%d", &tarefas[i].tempo_de_execucao);
    }

    // Ordenando as tarefas por tempo de retorno
    ordenar_tarefas(tarefas, n);

    // Imprimindo as tarefas escalonadas
    printf("Tarefas escalonadas:\n");
    for (i = 0; i < n; i++)
    {
        printf("ID: %d, Tempo de execucao: %d, Tempo de retorno: %d\n", tarefas[i].id, tarefas[i].tempo_de_execucao, calcular_tempo_de_retorno(&tarefas[i]));
    }

    // Liberando memória
    free(tarefas);

    return 0;
}
