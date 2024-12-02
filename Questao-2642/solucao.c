#include <stdlib.h>
#include <limits.h>

// Definição da estrutura de grafo
typedef struct {
    int n;             // Número de nós
    int** adjMatrix;   // Matriz de adjacência para representar o grafo
} Graph;

// Função para criar o grafo
Graph* graphCreate(int n, int** edges, int edgesSize, int* edgesColSize) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->n = n;
    graph->adjMatrix = (int**)malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++) {
        graph->adjMatrix[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            graph->adjMatrix[i][j] = INT_MAX; // Inicializa com infinito
        }
    }

    for (int i = 0; i < edgesSize; i++) {
        int from = edges[i][0];
        int to = edges[i][1];
        int cost = edges[i][2];
        graph->adjMatrix[from][to] = cost;
    }

    return graph;
}

// Função para adicionar uma aresta ao grafo
void graphAddEdge(Graph* obj, int* edge, int edgeSize) {
    int from = edge[0];
    int to = edge[1];
    int cost = edge[2];
    obj->adjMatrix[from][to] = cost;
}

// Função para encontrar o caminho mais curto entre dois nós usando Dijkstra
int graphShortestPath(Graph* obj, int node1, int node2) {
    int n = obj->n;
    int* dist = (int*)malloc(n * sizeof(int));
    int* visited = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[node1] = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        if (dist[u] == INT_MAX) break;
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (obj->adjMatrix[u][v] != INT_MAX && dist[u] + obj->adjMatrix[u][v] < dist[v]) {
                dist[v] = dist[u] + obj->adjMatrix[u][v];
            }
        }
    }

    int result = (dist[node2] == INT_MAX) ? -1 : dist[node2];

    free(dist);
    free(visited);

    return result;
}

// Função para liberar a memória alocada para o grafo
void graphFree(Graph* obj) {
    for (int i = 0; i < obj->n; i++) {
        free(obj->adjMatrix[i]);
    }
    free(obj->adjMatrix);
    free(obj);
}
