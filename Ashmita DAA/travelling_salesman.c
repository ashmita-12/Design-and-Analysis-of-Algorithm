#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int min(int a, int b) {
    return (a < b) ? a : b;
}
int tsp(int graph[][4], int path[], int n, int pos, int visited, int **dp) {
    if (visited == ((1 << n) - 1))
        return graph[pos][0];
    if (dp[visited][pos] != -1)
        return dp[visited][pos];
    int ans = INT_MAX, city;
    for ( city = 0; city < n; city++) {
        if ((visited & (1 << city)) == 0) {
            int newAns = graph[pos][city] + tsp(graph, path, n, city, visited | (1 << city), dp);
            if (newAns < ans) {
                ans = newAns;
                path[visited] = city;
            }
        }
    }
    return dp[visited][pos] = ans;}
int main() {
    int graph[4][4] = {{0, 10, 15, 20},
                       {10, 0, 35, 25},
                       {15, 35, 0, 30},
                       {20, 25, 30, 0}};
    int i, j, n = 4;
    int path[1 << n];
    int **dp = (int **)malloc((1 << n) * sizeof(int *));
    for ( i = 0; i < (1 << n); i++) {
        dp[i] = (int *)malloc(n * sizeof(int));
        for ( j = 0; j < n; j++)
            dp[i][j] = -1;
    }
    printf("Minimum cost is %d\n", tsp(graph, path, n, 0, 1, dp));
    for ( i = 0; i < (1 << n); i++)
        free(dp[i]);
    free(dp);
    return 0;}
