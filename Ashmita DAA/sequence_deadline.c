#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Job {
    char id;
    int deadline;
    int profit;
};
int compare(const void *a, const void *b) {
    return ((struct Job*)b)->profit - ((struct Job*)a)->profit;
}
void print_job_scheduling(struct Job arr[], int n) {
    qsort(arr, n, sizeof(struct Job), compare);
    int i, j, result[n];
    bool slot[n];
    for ( i = 0; i < n; i++)
        slot[i] = false;
    for ( i = 0; i < n; i++) {
        for ( j = arr[i].deadline - 1; j >= 0; j--) {
            if (!slot[j]) {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }
    printf("Scheduled jobs: ");
    for ( i = 0; i < n; i++)
        if (slot[i])
            printf("%c ", arr[result[i]].id);
    printf("\n");
}
int main() {
    struct Job arr[] = {{'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, {'d', 1, 25}, {'e', 3, 15}};
    int n = sizeof(arr) / sizeof(arr[0]);
    print_job_scheduling(arr, n);
    return 0;
}
