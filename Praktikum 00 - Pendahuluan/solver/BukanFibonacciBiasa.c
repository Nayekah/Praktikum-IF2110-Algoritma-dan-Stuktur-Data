#include <stdio.h>
#include <stdlib.h>

int fibo(int n, int a, int b) {
    
    if (n == 1) return a;
    if (n == 2) return b;

    int fi = a, se = b, res;

    for (int i = 3; i <= n; i++) {
        res = fi + se;
        fi = se;
        se = res;
    }

    return res;
}


int main() {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);

    printf("%d\n", fibo(n, a, b));

    return 0;
}