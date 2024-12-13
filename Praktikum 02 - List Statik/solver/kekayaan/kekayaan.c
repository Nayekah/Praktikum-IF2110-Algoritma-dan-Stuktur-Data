#include <stdio.h>
#include "liststatik.h"

int main() {
    ListStatik l, hasil;

    CreateListStatik(&l);
    CreateListStatik(&hasil);

    readList(&l);

    int length = listLength(l); 
    int inc = 1; 

    int i;
    for (i = length - 1; i >= 0; i--) {
        int sum = ELMT(l, i) + inc;
        if (sum == 10) {
            ELMT(l, i) = 0;
            inc = 1;
        } else {
            ELMT(l, i) = sum;
            inc = 0;
            break; 
        }
    }

    if (inc == 1) {
        int i;
        for (i = length; i > 0; i--) {
            ELMT(hasil, i) = ELMT(l, i - 1);
        }
        ELMT(hasil, 0) = 1;
        length++;
    } else {
        int i;
        for (i = 0; i < length; i++) {
            ELMT(hasil, i) = ELMT(l, i);
        }
    }

    int j;
    printf("%d", ELMT(hasil, 0));
    for (j = 1; j < length; j++) {
        printf(" %d", ELMT(hasil, j));
    }

    printf("\n");
    return 0;
}