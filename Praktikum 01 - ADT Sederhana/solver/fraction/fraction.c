#include <stdio.h>
#include <math.h>
#include "fraction.h"


int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

boolean IsFRACTIONValid(int N, int D){
    return D != 0;
}

void CreateFRACTION(FRACTION *F, int N, int R){
    Numerator(*F) = N;
    Denominator(*F) = R;
}

void ReadFRACTION(FRACTION *F){
    int N, R;

    do{
        scanf("%d %d", &N, &R);
        if (!IsFRACTIONValid(N, R)){
            printf("FRACTION tidak valid\n");
        }
    } while (!IsFRACTIONValid(N,R));

    CreateFRACTION(F, N, R);
}

void WriteFRACTION(FRACTION F){
    int a = Numerator(F);
    int b = Denominator(F);
    
    if (a == 0) {
        printf("0/1");
    } else{
        boolean swap = ((a < 0)^(b < 0));
        if (swap){
            printf("-");   
        } 

        F = SimplifyFRACTION(F);

        printf("%d/%d", abs(Numerator(F)), abs(Denominator(F)));
    }
}

FRACTION AddFRACTION(FRACTION F1, FRACTION F2) {
    int numerator = (Numerator(F1) * Denominator(F2)) + (Numerator(F2) * Denominator(F1));
    int denominator = Denominator(F1) * Denominator(F2);
    
    FRACTION res;
    CreateFRACTION(&res, numerator, denominator);
    
    return SimplifyFRACTION(res);
}

FRACTION SubtractFRACTION(FRACTION F1, FRACTION F2) {
    int numerator = (Numerator(F1) * Denominator(F2)) - (Numerator(F2) * Denominator(F1));
    int denominator = Denominator(F1) * Denominator(F2);
    
    FRACTION res;
    CreateFRACTION(&res, numerator, denominator);
    
    return SimplifyFRACTION(res);
}

FRACTION MultiplyFRACTION(FRACTION F1, FRACTION F2){
    int numerator = Numerator(F1) * Numerator(F2);
    int denominator = Denominator(F1) * Denominator(F2);
    
    FRACTION res;
    CreateFRACTION(&res, numerator, denominator);
    
    return SimplifyFRACTION(res);
}

FRACTION DivideFRACTION(FRACTION F1, FRACTION F2){
    int numerator = Numerator(F1) * Denominator(F2);
    int denominator = Denominator(F1) * Numerator(F2);
    
    FRACTION res;
    CreateFRACTION(&res, numerator, denominator);

    return SimplifyFRACTION(res);
}

FRACTION MultiplyNumberFRACTION(int n, FRACTION F1){
    int numerator = n * Numerator(F1);
    int denom = Denominator(F1);
    
    FRACTION res;
    CreateFRACTION(&res, numerator, denom);
    
    return SimplifyFRACTION(res);
}

FRACTION SimplifyFRACTION(FRACTION F) {
    int d = gcd(Numerator(F), Denominator(F));

    Numerator(F) /= d;
    Denominator(F) /= d;

    FRACTION res;
    CreateFRACTION(&res, Numerator(F), Denominator(F));

    return res;
}

float ToDecimal(FRACTION F){
    return (float)Numerator(F) / Denominator(F);
}