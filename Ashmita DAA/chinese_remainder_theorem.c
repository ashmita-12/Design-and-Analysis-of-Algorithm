#include <stdio.h>
int extendedGCD(int a, int b, int *x, int *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;}
    int x1, y1;
    int gcd = extendedGCD(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;}
int modInverse(int a, int m) {
    int x, y;
    int g = extendedGCD(a, m, &x, &y);
    if (g != 1)
        return -1;
    else
        return (x % m + m) % m;}
int findMinX(int num[], int rem[], int k) {
	int i;
    int prod = 1;
    for ( i = 0; i < k; i++)
        prod *= num[i];
    int result = 0;
    for ( i = 0; i < k; i++) {
        int pp = prod / num[i];
        result += rem[i] * modInverse(pp, num[i]) * pp;}
    return result % prod;}
int main() {
    int num[] = {3, 4, 5};
    int rem[] = {2, 3, 1};
    int k = sizeof(num) / sizeof(num[0]);
    printf("x is %d\n", findMinX(num, rem, k));
    return 0;
}
