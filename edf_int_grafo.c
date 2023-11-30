#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Estrutura para representar um vértice de um grafo
struct vertice
{
    int id;
    int tempo_de_inicio;
    int tempo_de_fim;
};

// Estrutura para representar uma aresta de um grafo
struct aresta
{
    int origem;
    int destino;
    int tempo;
};

// Função para calcular o tempo de retorno de um intervalo
int calcular_tempo_de_retorno(struct vertice *vertice)
{
    return vertice->tempo_de_fim - vertice->tempo_de_inicio;
}

// Função para ordenar os intervalos por tempo de retorno
void ordenar_intervalos(struct vertice *vertices, int n)
{
    int i, j;
    struct vertice aux;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (calcular_tempo_de_retorno(&vertices[i]) > calcular_tempo_de_retorno(&vertices[j]))
            {
                aux = vertices[i];
                vertices[i] = vertices[j];
                vertices[j] = aux;
            }
        }
    }
}

// Função para encontrar o menor intervalo que não colide com nenhum intervalo anterior
struct vertice *encontrar_intervalo_menor(struct vertice *vertices, int n)
{
    int i, j;
    struct vertice *menor = NULL;
    int menor_tempo = INT_MAX;

    for (i = 0; i < n; i++)
    {
        int tempo_de_colisao = 0;
        for (j = 0; j < i; j++)
        {
            if (vertices[i].tempo_de_inicio >= vertices[j].tempo_de_fim)
            {
                break;
            }
            else if (vertices[i].tempo_de_fim <= vertices[j].tempo_de_inicio)
            {
                tempo_de_colisao = 0;
                break;
            }
            else
            {
                tempo_de_colisao = vertices[i].tempo_de_inicio - vertices[j].tempo_de_fim;
            }
        }
        if (tempo_de_colisao < menor_tempo)
        {
            menor = &vertices[i];
            menor_tempo = tempo_de_colisao;
        }
    }

    return menor;
}

// Função principal
int main()
{
    // Declarando variáveis
    int n;
    struct vertice *vertices;
    struct aresta *arestas;
    int i, j;

    // Lendo o número de intervalos
    printf("Digite o numero de intervalos: ");
    scanf("%d", &n);

    // Alocando memória para os intervalos
    vertices = (struct vertice *)malloc(n * sizeof(struct vertice));

    // Lendo os dados dos intervalos
    for (i = 0; i < n; i++)
    {
        vertices[i].id = i + 1;
        printf("Digite o inicio do intervalo %d: ", i + 1);
        scanf("%d", &vertices[i].tempo_de_inicio);
        printf("Digite o fim do intervalo %d: ", i + 1);
        scanf("%d", &vertices[i].tempo_de_fim);
    }

    // Criando o grafo
    arestas = (struct aresta *)malloc(n * sizeof(struct aresta));
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (vertices[i].tempo_de_inicio >= vertices[j].tempo_de_fim)
            {
                break;
            }
            else if (vertices[i].tempo_de_fim <= vertices[j].tempo_de_inicio)
            {
                continue;
            }
            else
            {
                arestas[i * n + j].origem = i;
                arestas[i * n + j].destino = j;
                arestas[i * n + j].tempo = vertices[j].tempo_de_fim - vertices[i].tempo_de_inicio;
            }
        }
    }

    // Ordenando os intervalos por tempo de retorno
    ordenar_intervalos(vertices, n);

    // Imprimindo os intervalos escalonados
    printf("Intervalos escalonados:\n");
    for (i = 0; i < n; i++)
    {
        printf("[ID - %d] Inicio: %d, Fim: %d\n", vertices[i].id, vertices[i].tempo_de_inicio, vertices[i].tempo_de_fim);
        encontrar_intervalo_menor(vertices, n);
    }

    // Liberando memória
    free(vertices);
    free(arestas);

    return 0;
}
