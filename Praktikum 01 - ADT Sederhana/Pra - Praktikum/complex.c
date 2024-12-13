#include <stdio.h>
#include "complex.h"


boolean IsCOMPLEXValid(float Re, float Im){
    return true;
}

void CreateComplex(COMPLEX *C, float Re, float Im){
    Real(*C) = Re;
    Imag(*C) = Im;
}

void BacaCOMPLEX(COMPLEX *C){
    float X, Y;

    scanf("%f %f", &X, &Y);
    CreateComplex(C, X, Y);
}

void TulisCOMPLEX(COMPLEX C) {
    if (Imag(C) >= 0) {
        printf("%.2f+%.2fi\n", Real(C), Imag(C));
    } else {
        printf("%.2f-%.2fi\n", Real(C), -Imag(C));
    }
}

COMPLEX AddCOMPLEX(COMPLEX C1, COMPLEX C2){
    COMPLEX res;

    Real(res) = Real(C1) + Real(C2);
    Imag(res) = Imag(C1) + Imag(C2);

    return res;
}

COMPLEX SubtractCOMPLEX(COMPLEX C1, COMPLEX C2){
    COMPLEX res;

    Real(res) = Real(C1) - Real(C2);
    Imag(res) = Imag(C1) - Imag(C2);

    return res;
}

COMPLEX MultiplyCOMPLEX(COMPLEX C1, COMPLEX C2){
    COMPLEX res;
    /* Rumus: (a + bi) * (c + di) = (ac - bd) + (ad + bc)i */

    Real(res) = (Real(C1) * Real(C2)) - (Imag(C1) * Imag(C2));
    Imag(res) = (Real(C1) * Imag(C2)) + (Imag(C1) * Real(C2));

    return res;
}

COMPLEX DivideCOMPLEX(COMPLEX C1, COMPLEX C2) {
    COMPLEX res;
    /* Rumus: (a + bi) / (c + di) = [(a + bi)(c - di)] / (c^2 + d^2) */
    /* Jika denominator bernilai 0, maka kembalikan nilai 0+0i */

    float denom = pow(Real(C2), 2) + pow(Imag(C2), 2);
    if (denom == 0) {
        Real(res) = 0;
        Imag(res) = 0;
        return res;
    } else {
        COMPLEX conjC2;
        Real(conjC2) = Real(C2);          
        Imag(conjC2) = -Imag(C2);        

        COMPLEX num = MultiplyCOMPLEX(C1, conjC2);  

        Real(res) = Real(num) / denom;    
        Imag(res) = Imag(num) / denom;    

        return res;
    }
}

float AbsCOMPLEX(COMPLEX C){
    /* Rumus: |C| = sqrt(Re^2 + Im^2) */

    float absComp;
    absComp = sqrt(pow(Real(C), 2) + pow(Imag(C), 2));

    return absComp;
}

COMPLEX ConjugateCOMPLEX(COMPLEX C) {
    COMPLEX res;
    
    /* Rumus: Conj(C) = Re - i*Im */
    Real(res) = Real(C);
    Imag(res) = -Imag(C);

    return res;
}

boolean CEQ(COMPLEX C1, COMPLEX C2) {
    return (Real(C1) == Real(C2)) && (Imag(C1) == Imag(C2));
}

boolean CNEQ(COMPLEX C1, COMPLEX C2){
    return (Real(C1) != Real(C2)) || (Imag(C1) != Imag(C2));
}
