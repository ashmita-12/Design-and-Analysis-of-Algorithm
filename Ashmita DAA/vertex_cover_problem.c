#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100
typedef struct {
    int u, v;
} Edge;
typedef struct {
    int numVertices;
    int numEdges;
    Edge edges[MAX];
} Graph;
void addEdge(Graph *graph, int u, int v) {
    graph->edges[graph->numEdges].u = u;
    graph->edges[graph->numEdges].v = v;
    graph->numEdges++;}
void vertexCover(Graph *graph) {
	int i;
    bool visited[graph->numVertices];
    for ( i = 0; i < graph->numVertices; i++)
        visited[i] = false;
    for ( i = 0; i < graph->numEdges; i++) {
        int u = graph->edges[i].u;
        int v = graph->edges[i].v;
        if (!visited[u] && !visited[v]) {
            visited[u] = true;
            visited[v] = true;}}
    printf("Vertex cover: ");
    for ( i = 0; i < graph->numVertices; i++) {
        if (visited[i])
            printf("%d ", i);}
    printf("\n");}
int main() {
    Graph graph;
    graph.numVertices = 7;
    graph.numEdges = 0;
    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 2);
    addEdge(&graph, 1, 3);
    addEdge(&graph, 1, 4);
    addEdge(&graph, 2, 4);
    addEdge(&graph, 3, 5);
    addEdge(&graph, 4, 5);
    addEdge(&graph, 5, 6);
    vertexCover(&graph);
    return 0;}
