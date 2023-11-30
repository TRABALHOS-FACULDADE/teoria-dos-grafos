#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um intervalo
struct intervalo
{
    int inicio;
    int fim;
};

// Função para calcular o tempo de retorno de um intervalo
int calcular_tempo_de_retorno(struct intervalo *intervalo)
{
    return intervalo->fim - intervalo->inicio;
}

// Função para ordenar os intervalos por tempo de retorno
void ordenar_intervalos(struct intervalo *intervalos, int n)
{
    int i, j;
    struct intervalo aux;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (calcular_tempo_de_retorno(&intervalos[i]) > calcular_tempo_de_retorno(&intervalos[j]))
            {
                aux = intervalos[i];
                intervalos[i] = intervalos[j];
                intervalos[j] = aux;
            }
        }
    }
}

// Função principal
int main()
{
    // Declarando variáveis
    int n;
    struct intervalo *intervalos;
    int i;

    // Lendo o número de intervalos
    printf("Digite o numero de intervalos: ");
    scanf("%d", &n);

    // Alocando memória para os intervalos
    intervalos = (struct intervalo *)malloc(n * sizeof(struct intervalo));

    // Lendo os dados dos intervalos
    for (i = 0; i < n; i++)
    {
        printf("Digite o inicio do intervalo %d: ", i + 1);
        scanf("%d", &intervalos[i].inicio);
        printf("Digite o fim do intervalo %d: ", i + 1);
        scanf("%d", &intervalos[i].fim);
    }

    // Ordenando os intervalos por tempo de retorno
    ordenar_intervalos(intervalos, n);

    // Imprimindo os intervalos escalonados
    printf("Intervalos escalonados:\n");
    for (i = 0; i < n; i++)
    {
        printf("Inicio: %d, Fim: %d, Tempo de retorno: %d\n", intervalos[i].inicio, intervalos[i].fim, calcular_tempo_de_retorno(&intervalos[i]));
    }

    // Liberando memória
    free(intervalos);

    return 0;
}
