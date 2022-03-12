#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int vertices, edges;
    struct Edge *edge;
};

struct Graph *createGraph(int vertices, int edges) {
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->edges = edges;
    graph->edge = (struct Edge *)malloc(edges * sizeof(struct Edge));
    return graph;
}

class BellmanFord {
    int v, edges = 0;
    int *dis;
    int **matrix;
    struct Graph *graph;

public:
    BellmanFord(int v) {
        v = v;

        matrix = new int *[v];
        dis = new int[v];
        for (int i = 0; i < v; i++) {
            matrix[i] = new int[v];
            dis[i] = INT_MAX;

            printf("Input row %d --> ", i);
            for (int j = 0; j < v; j++) {
                scanf("%d", &matrix[i][j]);
                if (matrix[i][j])
                    edges++;
            }
        }

        graph = createGraph(v, edges);
        int k = 0;
        for (int i = 0; i < v; i++)
            for (int j = 0; j < v; j++)
                if (matrix[i][j]) {
                    graph->edge[k].src = i;
                    graph->edge[k].dest = j;
                    graph->edge[k].weight = matrix[i][j];
                    k++;
                }

    }

    void BellmanFordAlgo(int src) {
        v = graph->vertices;
        edges = graph->edges;
        dis[src] = 0;
        int sum;

        for (int i = 1; i < v; i++)
            for (int j = 0; j < edges; j++) {
                sum = dis[graph->edge[j].src] + graph->edge[j].weight;
                if (dis[graph->edge[j].src] != INT_MAX && sum < dis[graph->edge[j].dest])
                    dis[graph->edge[j].dest] = sum;
            }

        for (int i = 0; i < edges; i++) {
            sum = dis[graph->edge[i].src] + graph->edge[i].weight;
            if (dis[graph->edge[i].src] != INT_MAX && sum < dis[graph->edge[i].dest]) {
                printf("The graph has a negative weight cycle");
                return;
            }
        }
        print();
    }

    void print() {
        printf("Vertex \tDistance from Source\n");
        for (int i = 0; i < v; ++i)
            printf("%d \t %d\n", i, dis[i]);
    }

};

int main() {
    int v;
    printf("Number of vertices --> ");
    scanf("%d", &v);

    BellmanFord obj(v);

    int source;
    printf("Source vertex --> ");
    scanf("%d", &source);

    obj.BellmanFordAlgo(source);
}
