#include <stdio.h>
#include <stdlib.h>
#include "image.h"
#include "ti.h"

int main(void){
    tImage Im, Rot, Res;
    char nom[50];
    int choix;
    unsigned char Table[256];
    double gamma;

    printf("Nom du fichier image PGM a charger: ");
    scanf("%s", nom);

    Im = LireImage(nom);
    if (Im == NULL){
        printf("Erreur de chargement.\n");
        return 1;
    }

    printf("\n--- MENU ---\n");
    printf("1 - Rotation 90 degres\n");
    printf("2 - Inversion niveaux de gris (negatif)\n");
    printf("3 - Correction gamma\n");
    printf("Choix: ");
    scanf("%d", &choix);

    if (choix == 1){
        Rot = Rotation(Im);
        EcrireImage(Rot, "rotation.pgm");
        printf("Image enregistree: rotation.pgm\n");
        DetruireImage(&Rot);
    }
    else if (choix == 2){
        RemplirTableInversion(Table);
        Res = AppliquerTable(Table, Im);
        EcrireImage(Res, "negatif.pgm");
        printf("Image enregistree: negatif.pgm\n");
        DetruireImage(&Res);
    }
    else if (choix == 3){
        printf("Valeur de gamma: ");
        scanf("%lf", &gamma);

        RemplirTableGamma(gamma, Table);
        Res = AppliquerTable(Table, Im);
        EcrireImage(Res, "gamma.pgm");
        printf("Image enregistree: gamma.pgm\n");
        DetruireImage(&Res);
    }
    else{
        printf("Choix invalide.\n");
    }

    DetruireImage(&Im);
    return 0;
}
