#include <stdio.h>
#include <math.h>
#include "circle.h"


boolean IsCIRCLEValid(float X, float Y, float R){
    return (R > 0);
}

void CreateCIRCLE(CIRCLE *C, float X, float Y, float R){
    Absis(Center(*C)) = X;
    Ordinat(Center(*C)) = Y;
    Radius(*C) = R;
}

void ReadCIRCLE(CIRCLE *C){
    float x, y, r;

    do{
        scanf("%f %f %f", &x, &y, &r);
        if (!IsCIRCLEValid(x, y, r)){
            printf("CIRCLE tidak valid\n");
        }
    } while (!IsCIRCLEValid(x, y, r));

    CreateCIRCLE(C, x, y, r);
}

void WriteCIRCLE(CIRCLE C){
    printf("P(%.2f,%.2f) r=%.2f", Absis(Center(C)), Ordinat(Center(C)), Radius(C));
}

float Circumference(CIRCLE C){
    return (2*3.14*Radius(C));
}

float Area(CIRCLE C){
    return (3.14*Radius(C)*Radius(C));
}

boolean IsPOINTInsideCIRCLE(CIRCLE C, POINT P){
    return Panjang(Center(C), P) < Radius(C);
}

boolean IsPOINTInEdgeCIRCLE(CIRCLE C, POINT P){
    return fabs(Panjang(Center(C), P) - Radius(C)) < 1e-6;
}

boolean IsCIRCLEInsideCIRCLE(CIRCLE C1, CIRCLE C2){
    return ((Panjang(Center(C1), Center(C2)) < fabs(Radius(C1) - Radius(C2))));
}

boolean IsCIRCLESTangents(CIRCLE C1, CIRCLE C2){
    float dist = Panjang(Center(C1), Center(C2));

    return ((dist == Radius(C1) + Radius(C2)) || (dist == fabs(Radius(C1) - Radius(C2))));
}

boolean IsCIRCLESIntersects(CIRCLE C1, CIRCLE C2){
    boolean
    small = fabs(Radius(C1) - Radius(C2)) < Panjang(Center(C1), Center(C2)),
    big =   (Radius(C1) + Radius(C2)) > Panjang(Center(C1), Center(C2));
    return (small && big);
}