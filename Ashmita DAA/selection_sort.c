#include <stdio.h>

void selection_sort(int arr[], int n) {
	int i, j;
    for ( i = 0; i < n - 1; i++) {
        int min_idx = i;
        for ( j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        // Swap arr[min_idx] and arr[i]
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int i, arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    selection_sort(arr, n);
    printf("Sorted array: ");
    for ( i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
