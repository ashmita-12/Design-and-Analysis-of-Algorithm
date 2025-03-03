#include <stdio.h>

int power(int x, unsigned int y, int p) {
    int res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

int main() {
    int x = 2, y = 5, p = 13;
    printf("Power is %d\n", power(x, y, p));
    return 0;
}
