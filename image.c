#include <stdio.h>
#include <stdlib.h>
#include "image.h"
#include "matrice.h"


tImage CreerImage(int L, int C){
    tImage Im;
    Im = (tImage) malloc(sizeof(struct sImage));
    if (Im == NULL) return NULL;

    Im->L = L;
    Im->C = C;

    Im->pixel = MatAllouer(L, C);
    if (Im->pixel == NULL){
        free(Im);
        return NULL;
    }

    return Im;
}

void DetruireImage(tImage *pIm){
    if (pIm != NULL && *pIm != NULL){
        MatLiberer(&((*pIm)->pixel));
        free(*pIm);
        *pIm = NULL;
    }
}


tImage LireImage(char nom[]){
    FILE *f;
    char magic[3];
    int L, C, max;
    int i, j;
    tImage Im;

    f = fopen(nom, "r");
    if (f == NULL){
        printf("Erreur ouverture fichier.\n");
        return NULL;
    }

    fscanf(f, "%s", magic);
    if (magic[0] != 'P' || magic[1] != '2'){
        printf("Format PGM non supporte.\n");
        fclose(f);
        return NULL;
    }
    //dimensions
    fscanf(f, "%d", &C); 
    fscanf(f, "%d", &L); 
    fscanf(f, "%d", &max);


    Im = CreerImage(L, C);
    if (Im == NULL){
        fclose(f);
        return NULL;
    }

    //lecture pixels
    for (i = 0; i < L; i++){
        for (j = 0; j < C; j++){
            int g;
            fscanf(f, "%d", &g);
            EcrirePixel(Im, i, j, (unsigned char)g);
        }
    }

    fclose(f);
    return Im;
}


int EcrireImage(tImage Im, char nom[]){
    FILE *f;
    int i, j;

    f = fopen(nom, "w");
    if (f == NULL){
        printf("Erreur creation fichier.\n");
        return 0;
    }

    fprintf(f, "P2\n");
    fprintf(f, "%d %d\n", Im->C, Im->L);
    fprintf(f, "255\n");

    for (i = 0; i < Im->L; i++){
        for (j = 0; j < Im->C; j++){
            fprintf(f, "%d ", LirePixel(Im, i, j));
        }
        fprintf(f, "\n");
    }

    fclose(f);
    return 1;
}
