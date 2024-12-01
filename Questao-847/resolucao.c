#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int node;
    int mask;
    int dist;
} State;

typedef struct {
    State* data;
    int front, rear, size, capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->size = 0;
    queue->rear = capacity - 1;
    queue->data = (State*)malloc(capacity * sizeof(State));
    return queue;
}

bool isEmpty(Queue* queue) {
    return queue->size == 0;
}

void enqueue(Queue* queue, State item) {
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->data[queue->rear] = item;
    queue->size += 1;
}

State dequeue(Queue* queue) {
    State item = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size -= 1;
    return item;
}

int shortestPathLength(int** graph, int graphSize, int* graphColSize) {
    int finalMask = (1 << graphSize) - 1;
    bool visited[graphSize][finalMask + 1];
    memset(visited, 0, sizeof(visited));

    Queue* queue = createQueue(graphSize * finalMask);
    
    for (int i = 0; i < graphSize; i++) {
        State initialState = {i, 1 << i, 0};
        enqueue(queue, initialState);
        visited[i][1 << i] = true;
    }

    while (!isEmpty(queue)) {
        State current = dequeue(queue);
        if (current.mask == finalMask) {
            free(queue->data);
            free(queue);
            return current.dist;
        }
        for (int i = 0; i < graphColSize[current.node]; i++) {
            int neighbor = graph[current.node][i];
            int nextMask = current.mask | (1 << neighbor);
            if (!visited[neighbor][nextMask]) {
                visited[neighbor][nextMask] = true;
                State nextState = {neighbor, nextMask, current.dist + 1};
                enqueue(queue, nextState);
            }
        }
    }

    free(queue->data);
    free(queue);
    return -1;
}
