#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 5 // Number of vertices in the graph

// Function to find the vertex with the minimum key value that is not yet included in MST
int minKey(int key[], bool mstSet[]) {
    int v, min = INT_MAX, min_index;

    for ( v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

// Function to print the constructed MST stored in parent[]
void printMST(int parent[], int graph[V][V]) {
	int i;
    printf("Edge \tWeight\n");
    for ( i = 1; i < V; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

// Function to construct and print MST for a graph represented using adjacency matrix representation
void primMST(int graph[V][V]) {
    int parent[V]; // Array to store the constructed MST
    int i, key[V];    // Key values used to pick minimum weight edge in cut
    bool mstSet[V]; // To represent set of vertices not yet included in MST
    // Initialize all keys as INFINITE
    for ( i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    // Always include the first 1st vertex in MST.
    key[0] = 0;      // Make key 0 so that this vertex is picked as first vertex
    parent[0] = -1; // First node is always root of MST
    int count;
    // The MST will have V vertices
    for ( count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet);
        // Add the picked vertex to the MST Set
        mstSet[u] = true;
        int v;
        for ( v = 0; v < V; v++)
            // graph[u][v] is non zero only for adjacent vertices of u
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    // Print the constructed MST
    printMST(parent, graph);
}

// Main function
int main() {
    // Example graph represented using adjacency matrix
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    // Print the solution
    primMST(graph);

    return 0;
}
