#ifndef TI_H
#define TI_H

#include "image.h"
#include "matrice.h"

tImage Rotation(tImage Im);
tImage AppliquerTable(unsigned char Table[256], tImage Im);
void RemplirTableInversion(unsigned char Table[256]);
void RemplirTableGamma(double Gamma, unsigned char Table[256]);

#endif
