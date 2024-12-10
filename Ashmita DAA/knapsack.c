#include <stdio.h>
#include <stdlib.h>
// Structure to represent an item
typedef struct {
    int weight;
    int value;
} Item;
// Comparator function to sort items by value-to-weight ratio
int compare(const void *a, const void *b) {
    double r1 = ((Item*)a)->value / (double)((Item*)a)->weight;
    double r2 = ((Item*)b)->value / (double)((Item*)b)->weight;
    return r2 - r1; // Descending order
}
// Function to calculate maximum value in knapsack
double fractional_knapsack(Item items[], int n, int capacity) {
    qsort(items, n, sizeof(Item), compare); // Sort items by ratio
    double total_value = 0.0;
          int i;
    for ( i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            capacity -= items[i].weight;
            total_value += items[i].value;
        } else {
            total_value += items[i].value * ((double)capacity / items[i].weight);
            break;}}
    return total_value;
}
int main() {
    Item items[] = {{60, 100}, {100, 20}, {120, 30}};
    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 50;
    double max_value = fractional_knapsack(items, n, capacity);
    printf("Maximum value in Knapsack = %.2f\n", max_value);
    return 0;
}
