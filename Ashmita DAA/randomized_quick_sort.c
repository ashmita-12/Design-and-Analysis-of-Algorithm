#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Include this header for time() function
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;}
// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Pivot element
    int i = (low - 1), j; // Index of smaller element
    for ( j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++; // Increment index of smaller element
            swap(&arr[i], &arr[j]);}}
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);}
int randomized_partition(int arr[], int low, int high) {
    int random = low + rand() % (high - low + 1); // Corrected range for rand() % (high - low + 1)
    swap(&arr[random], &arr[high]);
    return partition(arr, low, high);}
// Randomized QuickSort function
void randomized_quick_sort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array
        int pi = randomized_partition(arr, low, high);

        // Recursively sort elements before and after partition
        randomized_quick_sort(arr, low, pi - 1);
        randomized_quick_sort(arr, pi + 1, high);}}
int main() {
    int i, arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    srand(time(NULL)); // Seed for random number generation
    randomized_quick_sort(arr, 0, n - 1);
    printf("Sorted array: ");
    for ( i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;}
