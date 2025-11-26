#ifndef MATRICE_H
#define MATRICE_H

#include <stdio.h>
#include <stdlib.h>


typedef unsigned char **tMatrice;


extern tMatrice MatAllouer(int nbLignes, int nbColonnes);
extern void MatLiberer(tMatrice *pMat);
extern tMatrice MatLire(int *pNbLig, int *pNbCol);
extern void MatAfficher(tMatrice mat, int nbLignes, int nbColonnes);
extern tMatrice MatCopier(tMatrice Mat, int NbLig, int NbCol);

#endif