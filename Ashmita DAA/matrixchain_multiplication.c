#include <stdio.h>
#include <limits.h>

int matrix_chain_order(int p[], int n) {
    int m[n][n], i, L, k;
    for ( i = 1; i < n; i++)
        m[i][i] = 0;

    for ( L = 2; L < n; L++) {
        for ( i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for ( k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }
    return m[1][n - 1];
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Minimum number of multiplications is %d\n", matrix_chain_order(arr, size));
    return 0;
}
