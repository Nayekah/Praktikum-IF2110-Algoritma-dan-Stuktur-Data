#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    int sum = 0;

    while(n--){
        int inp;
        scanf("%d", &inp);
        if (inp % k != 0){
            sum += inp;
        }
    }
    printf("%d\n", sum);

    return 0;
}