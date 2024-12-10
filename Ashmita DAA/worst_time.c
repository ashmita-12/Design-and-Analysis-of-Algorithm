#include <stdio.h>
// Function to swap two elements
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}
// Partition function
int partition(int arr[], int low, int high, int pivot) {
	int i;
    for ( i = low; i < high; i++) {
        if (arr[i] == pivot) {
            swap(&arr[i], &arr[high]);
            break;
        }
    }
    int j;
    i = low - 1;
    for ( j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}
// Function to find the median of a small array
int find_median(int arr[], int n) {
	int i;
    for (i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    return arr[n / 2];
}
// Median of Medians function
int median_of_medians(int arr[], int low, int high, int k) {
    int n = high - low + 1;
    if (n <= 5) {
        // Find the k-th smallest element by sorting and returning the k-th element
        return find_median(arr + low, n);
    }
    int i, median[(n + 4) / 5];
    for (i = 0; i < n / 5; i++) {
        median[i] = find_median(arr + low + i * 5, 5);
    }
    if (i * 5 < n) {
        median[i] = find_median(arr + low + i * 5, n % 5);
        i++;
    }
    int med_of_med = median_of_medians(median, 0, i - 1, i / 2);
    int pivot_index = partition(arr, low, high, med_of_med);
    int rank = pivot_index - low + 1;
    if (k == rank)
        return arr[pivot_index];
    else if (k < rank)
        return median_of_medians(arr, low, pivot_index - 1, k);
    else
        return median_of_medians(arr, pivot_index + 1, high, k - rank);
}
int main() {
    int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3; // Find the 3rd smallest element
    int result = median_of_medians(arr, 0, n - 1, k);
    printf("The %d-th smallest element is %d\n", k, result);
    return 0;
}
