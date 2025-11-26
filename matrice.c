#include "matrice.h"

typedef unsigned char **tMatrice;

//exo1
//la verificacion se hahce con el cast del malloc
tMatrice MatAllouer(int NbLig, int NbCol) {
    unsigned char *elements;
    tMatrice tab;
    elements = (unsigned char *) malloc(NbLig * NbCol * sizeof(unsigned char));
    if (elements == NULL) {
        printf("Erreur : allocation des elements echouee.\n");
        return NULL;
    }
    tab = (tMatrice) malloc(NbLig * sizeof(unsigned char *));
    if (tab == NULL) {
        printf("Erreur : allocation du tableau de pointeurs echouee.\n");
        free(elements);
        return NULL;
    }
    for (int i = 0; i < NbLig; i++) {
        tab[i] = elements + i * NbCol;
    }

    return tab;
}


//exo 2
tMatrice MatLire(int *pNbLig, int *pNbCol) {
    int i, j;
    tMatrice M;

    printf("Nombre de lignes : ");
    scanf("%d", pNbLig);
    printf("Nombre de colonnes : ");
    scanf("%d", pNbCol);

    M = MatAllouer(*pNbLig, *pNbCol);
    if (M == NULL) {
        return NULL;
    }

    printf("Entrez les elements de la matrice :\n");
    for (i = 0; i < *pNbLig; i++) {
        for (j = 0; j < *pNbCol; j++) {
            printf("M[%d][%d] = ", i, j);
            scanf("%hhu", &M[i][j]); 
        }
    }

    return M;
}   


//exo3
void MatAfficher(tMatrice Mat, int NbLig, int NbCol) {
    int i, j;
    printf("Matrice (%d x %d) :\n", NbLig, NbCol);
    for (i = 0; i < NbLig; i++) {
        for (j = 0; j < NbCol; j++) {
            printf("%3d ", Mat[i][j]); 
        }
        printf("\n");
    }
}

//exo4
tMatrice MatCopier(tMatrice Mat, int NbLig, int NbCol) {
    tMatrice copie;
    int i, j;

    copie = MatAllouer(NbLig, NbCol);
    if (copie == NULL) {
        return NULL;
    }

    for (i = 0; i < NbLig; i++) {
        for (j = 0; j < NbCol; j++) {
            copie[i][j] = Mat[i][j];
        }
    }

    return copie;
}


//exo5
void MatLiberer(tMatrice *pMat) {
    if (pMat != NULL && *pMat != NULL) {
        free((*pMat)[0]);
        free(*pMat);     
        *pMat = NULL;     
    }
}