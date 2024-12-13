#include <stdio.h>
#include "liststatik.h"

int main() {
    ListStatik l;
    CreateListStatik(&l);
    readList(&l);

    int freq[CAPACITY] = {0};


    for (int i = 0; i < listLength(l); i++) {
        freq[ELMT(l, i)]++;
    }

    int maxFreq = 0, secondMaxFreq = 0, maxNum = -1, secondMaxNum = -1;

    for (int i = 0; i < CAPACITY; i++) {
        if (freq[i] > maxFreq) {
            secondMaxFreq = maxFreq;
            secondMaxNum = maxNum;
            maxFreq = freq[i];
            maxNum = i;
        } else if (freq[i] > secondMaxFreq && freq[i] < maxFreq) {
            secondMaxFreq = freq[i];
            secondMaxNum = i;
        }
    }

    if (secondMaxFreq == 0) {
        printf("Tidak ada elemen kedua yang paling sering muncul\n");
    } else {
        printf("%d\n", secondMaxNum);
    }

    return 0;
}