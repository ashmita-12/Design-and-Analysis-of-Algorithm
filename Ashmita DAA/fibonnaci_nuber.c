#include <stdio.h>

int fibonacci_iterative(int n) {
    if (n <= 0)
        return 0;
    if (n == 1)
        return 1;
    int a = 0, b = 1, next, i;
    for ( i = 2; i <= n; i++) {
        next = a + b;
        a = b;
        b = next;
    }
    return b;
}

int main() {
    int n = 10;
    printf("Fibonacci number %d is %d", n, fibonacci_iterative(n));
    return 0;
}
