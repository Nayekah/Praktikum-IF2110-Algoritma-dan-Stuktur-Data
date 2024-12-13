#include <stdio.h>
#include "liststatik.h"

int main() {
    ListStatik l, unique, count;
    
    CreateListStatik(&l);
    CreateListStatik(&unique);
    CreateListStatik(&count);

    readList(&l);
    
    int i;
    for (i = 0; i < CAPACITY; i++) {
        ELMT(count, i) = 0;
    }

    int j;
    for (j = 0; j < listLength(l); j++) {

        if (indexOf(unique, ELMT(l, j)) == IDX_UNDEF) {
            insertLast(&unique, ELMT(l, j));
        }
        
        ELMT(count, indexOf(unique, ELMT(l, j)))++;
    }

    printList(unique);
    printf("\n");

    int k;
    for (k = 0; k < listLength(unique); k++) {
        printf("%d %d\n", ELMT(unique, k), ELMT(count, k));
    }
    return 0;
}