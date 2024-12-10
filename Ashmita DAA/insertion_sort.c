#include <stdio.h>

void insertion_sort(int arr[], int n) {
	int i;
    for ( i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int i, arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertion_sort(arr, n);
    printf("Sorted array: ");
    for ( i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
