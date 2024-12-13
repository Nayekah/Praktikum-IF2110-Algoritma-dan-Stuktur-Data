#include <stdio.h>
#include "liststatik.h"


void CreateListStatik(ListStatik *l){
    IdxType i;

    for (i = 0; i < CAPACITY; i++){
        ELMT(*l, i) = MARK;
    }
}

int listLength(ListStatik l){
    int nEff = 0;

    while (ELMT(l, nEff) != MARK && nEff < CAPACITY){
        nEff++;
    }

    return nEff;
}

IdxType getFirstIdx(ListStatik l){
    return IDX_MIN;
}

IdxType getLastIdx(ListStatik l){
    return (listLength(l) - 1);
}

boolean isIdxValid(ListStatik l, IdxType i){
    return (i < CAPACITY && i >= IDX_MIN);
}

boolean isIdxEff(ListStatik l, IdxType i){
    return (i < listLength(l) && i >= IDX_MIN);
}

boolean isEmpty(ListStatik l){
    return ELMT(l, IDX_MIN) == MARK;
}

boolean isFull(ListStatik l){
    return ELMT(l, CAPACITY-1) != MARK;
}

void readList(ListStatik *l){
    int i, n;
    CreateListStatik(l);

    do{
        scanf("%d\n", &n);
    } while (n > CAPACITY || n < 0);

    for(i = 0; i < n; i++){
        int elmt;

        scanf("%d\n", &elmt);
        ELMT(*l, i) = elmt; 
    }
}

void printList(ListStatik l){
    if (isEmpty(l)){
        printf("[");
    } else{
        IdxType i;

        printf("[%d", ELMT(l, IDX_MIN));
        for(i = 1; i < listLength(l); i++){
            printf(",%d", ELMT(l, i));
    }
    }

    printf("]");
}

ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus){
    ListStatik res;
    CreateListStatik(&res);

    IdxType i;
    for(i = 0; i < listLength(l1); i++){
        if (plus){
            ELMT(res, i) = ELMT(l1, i) + ELMT(l2, i);
        } else{
            ELMT(res, i) = ELMT(l1, i) - ELMT(l2, i);
        }
    }
    return res;
}

boolean isListEqual(ListStatik l1, ListStatik l2){
    boolean status = true;

    if (listLength(l1) != listLength(l2)){
        status = false;
    }

    IdxType i;
    for(i = 0; i < listLength(l1); i++){
        if (ELMT(l1, i) != ELMT(l2, i)){
            status = false;
        }
    }
    return status;
}

int indexOf(ListStatik l, ElType val){
    int i;

    if (isEmpty(l)){
        return IDX_UNDEF;
    } else{
        for(i = 0; i < listLength(l); i++){
            if (ELMT(l, i) == val){
                return i;
            }
        }
        return IDX_UNDEF;
    }
}

void extremeValues(ListStatik l, ElType *max, ElType *min){
    *max = ELMT(l,IDX_MIN);
    *min = ELMT(l,IDX_MIN);

    int i;
    for(i = 1; i < listLength(l); i++){
        if(*min > ELMT(l,i)){
            *min = ELMT(l,i);
        }

        if(*max < ELMT(l,i)){
            *max = ELMT(l,i);
        }
    }
}

void insertFirst(ListStatik *l, ElType val){
    IdxType i;
    i = listLength(*l) - 1;

    while (i >= 0) {
        ELMT(*l, i + 1) = ELMT(*l, i);
        i--;
    }

    ELMT(*l, getFirstIdx(*l)) = val;
}

void insertAt(ListStatik *l, ElType val, IdxType idx){
    IdxType i;

    for (i = listLength(*l) - 1; i >= idx; i--) {
        ELMT(*l,i+1) = ELMT(*l,i);
    }

    ELMT(*l,idx) = val; 
}

void insertLast(ListStatik *l, ElType val){
    if (isEmpty(*l)){
        ELMT(*l, 0) = val;
    } else{
        ELMT(*l, listLength(*l)) = val;
    }
}

void deleteFirst(ListStatik *l, ElType *val){
    IdxType i;
    *val = ELMT(*l,getFirstIdx(*l));

    for (i = IDX_MIN; i < listLength(*l); i++) {
        ELMT(*l,i) = ELMT(*l,i+1);
    }
}

void deleteAt(ListStatik *l, ElType *val, IdxType idx){
    IdxType i;
    *val = ELMT(*l,idx);

    for (i = idx; i < listLength(*l); i++) {
        ELMT(*l,i) = ELMT(*l,i+1);
    }
}

void deleteLast(ListStatik *l, ElType *val){
    *val = ELMT(*l,getLastIdx(*l));

    ELMT(*l,getLastIdx(*l)) = MARK;
}

void sortList(ListStatik *l, boolean asc){
    int size = listLength(*l);
    
    for (int i = 1; i < size; i++) {
        ElType key = ELMT(*l, i);
        int j = i - 1;

        while ((j >= 0) && ((asc && ELMT(*l, j) > key) || (!asc && ELMT(*l, j) < key))) {
            ELMT(*l, j + 1) = ELMT(*l, j);
            j--;
        }
        ELMT(*l, j + 1) = key;
    }
}