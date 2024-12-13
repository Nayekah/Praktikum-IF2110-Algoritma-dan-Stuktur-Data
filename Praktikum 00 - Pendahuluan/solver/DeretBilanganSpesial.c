#include <stdio.h>
#include <stdlib.h>

int main(){
    int a, b;
    scanf("%d %d", &a, &b);

    printf("%d", a);
    while (a < b){
        if (a % 2 == 1){
            a += 1;
            if (a > b){
                break;
            } else{
                printf(" %d", a);
            }
        } else{
            a *= 2;
            if (a > b){
                break;
            } else{
                printf(" %d", a);
            }
        }
    }

    printf("\n");
    return 0;
}