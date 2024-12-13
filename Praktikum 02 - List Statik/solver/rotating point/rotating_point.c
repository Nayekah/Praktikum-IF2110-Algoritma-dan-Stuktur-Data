#include <stdio.h>
#include "point.h"
#include "complex.h"


COMPLEX PowerCOMPLEX(COMPLEX C, int p) {
    COMPLEX res = C;

    for (int i = 0; i < p; i++) {
        res = MultiplyCOMPLEX(C, res);
    }

    return res;
}

void TransformPointByComplexPower(POINT *P, COMPLEX C, int n) {
    int i = 1;
    COMPLEX tfed = C;   

    if (n == 0) {
        printf("Titik keluar dari lingkaran pada iterasi ke 0");
    } else{
        for (i; i <= n; i++) {
            float x = Absis(*P);
            float y = Ordinat(*P);

            Absis(*P) = x*Real(C) - y*Imag(C);
            Ordinat(*P) = x*Imag(C) + y*Real(C);

            C = MultiplyCOMPLEX(C, tfed);

            if (Jarak0(*P) < 1){
                continue;
            } else{
                printf("Titik keluar dari lingkaran pada iterasi ke %d", i);
                return;
            }
        }
        
        printf("Titik tetap berada di dalam lingkaran setelah %d iterasi", n);
    }

}