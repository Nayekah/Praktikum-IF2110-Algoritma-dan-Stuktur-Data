#include <stdio.h>
#include <math.h>
#include "point.h"

#define PI 3.14159265358979323846


void CreatePoint (POINT * P, float X, float Y){
    Absis(*P) = X;
    Ordinat(*P) = Y;
}

void BacaPOINT (POINT * P){
    float X, Y;

    scanf("%f %f", &X, &Y);
    CreatePoint(P, X, Y);
}

void TulisPOINT (POINT P){
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}


// Boolean
boolean EQ (POINT P1, POINT P2){
    return ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2)));
}

boolean NEQ (POINT P1, POINT P2){
    return ((Absis(P1) != Absis(P2)) || (Ordinat(P1) != Ordinat(P2)));
}


// Location of POINT (P)
boolean IsOrigin (POINT P){
    return ((Absis(P) == 0) && (Ordinat(P) == 0));
}

boolean IsOnSbX (POINT P){
    return (Ordinat(P) == 0);
}

boolean IsOnSbY (POINT P){
    return (Absis(P) == 0);
}

int Kuadran (POINT P){
    if ((Absis(P) > 0) && (Ordinat(P) > 0)){
        return 1;
    } else if ((Absis(P) < 0) && (Ordinat(P) > 0)){
        return 2;
    } else if ((Absis(P) < 0) && (Ordinat(P) < 0)){
        return 3;
    } else{
        return 4;
    }
}


// Operation
POINT NextX (POINT P){
    Absis(P)++;

    return P;
}

POINT NextY (POINT P){
    Ordinat(P)++;

    return P;
}

POINT PlusDelta (POINT P, float deltaX, float deltaY){
    Absis(P) += deltaX;
    Ordinat(P) += deltaY;

    return P;
}

POINT MirrorOf (POINT P, boolean SbX){
    if (SbX == true){
        Ordinat(P) *= -1;
    } else{
        Absis(P) *= -1;
    }
    return P;
}

float Jarak0 (POINT P){
    return sqrt(pow(Absis(P), 2) + pow(Ordinat(P), 2));
}

float Panjang (POINT P1, POINT P2){
    return sqrt(pow((Absis(P2)-Absis(P1)), 2) + pow((Ordinat(P2)-Ordinat(P1)), 2));
}

void Geser (POINT *P, float deltaX, float deltaY){
    Absis(*P) += deltaX;
    Ordinat(*P) += deltaY; 
}

void GeserKeSbX (POINT *P){
    Ordinat(*P) = 0;
}

void GeserKeSbY (POINT *P){
    Absis(*P) = 0;
}

void Mirror (POINT *P, boolean SbX){
     if (SbX == true){
        Ordinat(*P) *= -1;
    } else{
        Absis(*P) *= -1;
    }
}

void Putar (POINT *P, float Sudut){
    float radian = -1 * Sudut * PI / 180;

    CreatePoint(P, Absis(*P) * cos(radian) - Ordinat(*P) * sin(radian), Absis(*P) * sin(radian) + Ordinat(*P) * cos(radian));
}

void PersamaanLinearDuaVariabel (POINT P1, POINT P2){
    int a,b;

    // (y2-y1) / (x2-x1)
    a = (Ordinat(P2) - Ordinat (P1)) / (Absis(P2) - Absis(P1)); // gradien

    // y = ax + b -> b = y - ax
    b = Ordinat(P1) - (a * Absis(P1)); // nilai konstanta

    printf("(%d,%d)", a, b);
}
