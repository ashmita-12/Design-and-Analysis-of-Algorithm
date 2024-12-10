#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;}
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1, j;
    for ( j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);}}
    swap(&arr[i + 1], &arr[high]);
    return i + 1;}
int randomized_partition(int arr[], int low, int high) {
    int random = low + rand() % (high - low + 1);
    swap(&arr[random], &arr[high]);
    return partition(arr, low, high);}
int randomized_select(int arr[], int low, int high, int k) {
    if (low == high)
        return arr[low];
    int pivot_index = randomized_partition(arr, low, high);
    int rank = pivot_index - low + 1;
    if (k == rank)
        return arr[pivot_index];
    else if (k < rank)
        return randomized_select(arr, low, pivot_index - 1, k);
    else
        return randomized_select(arr, pivot_index + 1, high, k - rank);}
int main() {
    int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3; // Find the 3rd smallest element
    srand(time(NULL)); // Seed for random number generation
    int result = randomized_select(arr, 0, n - 1, k);
    printf("The %d-th smallest element is %d\n", k, result);
    return 0;}
