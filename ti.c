#include <stdio.h>
#include <math.h>
#include "ti.h"

tImage Rotation(tImage Im){
    int L = NbLig(Im);
    int C = NbCol(Im);

    tImage R = CreerImage(C, L);
    if (R == NULL) return NULL;

    int i, j;
    for (i = 0; i < L; i++){
        for (j = 0; j < C; j++){
            EcrirePixel(R, j, L-1-i,LirePixel(Im, i, j));
        }
    }

    return R;
}

tImage AppliquerTable(unsigned char Table[256], tImage Im){
    int L = NbLig(Im);
    int C = NbCol(Im);

    tImage R = CreerImage(L, C);
    if (R == NULL) return NULL;

    int i, j;
    unsigned char g;

    for (i = 0; i < L; i++){
        for (j = 0; j < C; j++){
            g = LirePixel(Im, i, j);
            EcrirePixel(R, i, j, Table[g]);
        }
    }

    return R;
}

void RemplirTableInversion(unsigned char Table[256]){
    int i;
    for (i = 0; i < 256; i++){
        Table[i] = 255 - i;
    }
}


void RemplirTableGamma(double Gamma, unsigned char Table[256]){
    int i;
    double x;

    for (i = 0; i < 256; i++){
        x = (double)i / 255.0;
        x = pow(x, Gamma);
        x = x * 255.0;
        Table[i] = (unsigned char)(round(x));
    }
}
