#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NOT_VISITED 0
#define VISITING 1
#define SAFE 2
#define UNSAFE 3

void dfs(int** graph, int* graphColSize, int* state, int node) {
    if (state[node] != NOT_VISITED) return;

    state[node] = VISITING;
    for (int i = 0; i < graphColSize[node]; i++) {
        int neighbor = graph[node][i];
        if (state[neighbor] == SAFE) continue;
        if (state[neighbor] == VISITING || state[neighbor] == UNSAFE) {
            state[node] = UNSAFE;
            return;
        }
        dfs(graph, graphColSize, state, neighbor);
        if (state[neighbor] == UNSAFE) {
            state[node] = UNSAFE;
            return;
        }
    }
    state[node] = SAFE;
}

int* eventualSafeNodes(int** graph, int graphSize, int* graphColSize, int* returnSize) {
    int* state = (int*)malloc(graphSize * sizeof(int));
    int* result = (int*)malloc(graphSize * sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < graphSize; i++) {
        state[i] = NOT_VISITED;
    }

    for (int i = 0; i < graphSize; i++) {
        if (state[i] == NOT_VISITED) {
            dfs(graph, graphColSize, state, i);
        }
    }

    for (int i = 0; i < graphSize; i++) {
        if (state[i] == SAFE) {
            result[(*returnSize)++] = i;
        }
    }

    free(state);
    return result;
}

