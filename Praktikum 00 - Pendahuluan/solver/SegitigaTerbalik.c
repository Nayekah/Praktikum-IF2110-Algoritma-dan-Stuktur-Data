#include <stdio.h>

void draw(int ast) {
    int i, j, k;
    for (i = 0; i < ast; i++) {
        for (j = 0; j < i; j++) {
            printf(" ");
        }
        for (k = 0; k < 2 * (ast - i) - 1; k++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    draw(n);
    return 0;
}