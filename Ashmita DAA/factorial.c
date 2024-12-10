#include <stdio.h>

int factorial_iterative(int n) {
    int result = 1, i;
    for ( i = 1; i <= n; i++)
        result *= i;
    return result;
}

int main() {
    int n = 5;
    printf("Factorial of %d is %d", n, factorial_iterative(n));
    return 0;
}
