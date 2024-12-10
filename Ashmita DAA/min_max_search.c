#include <stdio.h>

void find_min_max(int arr[], int n, int *min, int *max) {
    *min = arr[0];
    *max = arr[0];
    int i;
    for ( i = 1; i < n; i++) {
        if (arr[i] < *min)
            *min = arr[i];
        if (arr[i] > *max)
            *max = arr[i];
    }
}

int main() {
    int arr[] = {3, 5, 7, 2, 8, -1, 4, 10, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    int min, max;
    find_min_max(arr, n, &min, &max);
    printf("Minimum value is %d\n", min);
    printf("Maximum value is %d\n", max);
    return 0;
}
