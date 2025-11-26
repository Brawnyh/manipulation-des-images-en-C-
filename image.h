#ifndef IMAGE_H
#define IMAGE_H

#include "matrice.h"

struct sImage {
    int L;
    int C;
    tMatrice pixel;
};
typedef struct sImage *tImage;

tImage CreerImage(int L, int C);
void DetruireImage(tImage *pIm);
tImage LireImage(char nom[]);
int EcrireImage(tImage Im, char nom[]);

#define NbLig(Im)  (Im->L)
#define NbCol(Im)  (Im->C)
#define LirePixel(Im,i,j)  ((Im)->pixel[i][j])
#define EcrirePixel(Im,i,j,v)  ((Im)->pixel[i][j]=(v))

#endif