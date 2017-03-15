/**Auteurs  : Prenom           Nom        **/
/**           Alexandre        Szymkiw    **/
/**           Simon            Fessy      **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Matieres.h"

#define MAX 200

/****************************************/
/**Fonction : initialiserMatieres*******/
/**Params :  **************************/
/**Sert à initialiser les piles*******/
/************************************/
PileMatieres *initialiserMatieres()
{
    PileMatieres *pileMatiere = malloc(sizeof(pileMatiere));
    pileMatiere->premier = NULL;
    pileMatiere->taille = 0;
    return pileMatiere;
}

/******************************************************/
/**Fonction : ajouterMatieres*************************/
/**Params :  PileMatieres * et char * ***************/
/**Sert à ajouter une matière dans la pile**********/
/**************************************************/
void ajouterMatieres(PileMatieres *p, char *chaine)
{

    Matieres *newMat = (Matieres *)malloc(sizeof(Matieres));
    newMat->m = (char *)malloc(strlen(chaine)*sizeof(MAX*sizeof(chaine)));

    if (p == NULL || newMat == NULL)
    {
        exit(EXIT_FAILURE);
    }

    strcpy(newMat->m,chaine);
    newMat->suivant = p->premier;
    p->premier = newMat;
    p->taille++;
}

/*********************************************/
/**Fonction : afficherMatieres***************/
/**Params :  PileMatieres * ****************/
/**Sert à afficher les matieres de la pile*/
/*****************************************/
void afficherMatieres(PileMatieres *p)
{
    int i = 1;

    if (p == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Matieres *mat = p->premier;
    if(mat == NULL){
        printf("Aucune donnee !! \n");
    }

    while (mat != NULL)
    {
        printf("Matiere numero %d : %s\n",i,mat->m);
        mat = mat->suivant;
        i++;
    }

    printf("\n");
}

/****************************************************/
/**Fonction : supprimerMatieres*********************/
/**Params :  PileMatieres * ***********************/
/**Sert à supprimer le dernier élément de la pile*/
/************************************************/
void supprimerMatieres(PileMatieres *p){
    printf("\n");
    if(p->taille == 0){
        printf("\n Aucune matiere a supprimer");
    }else{

        Matieres *suppMat = p->premier;
        p->premier = p->premier->suivant;

        free(suppMat->m);
        free(suppMat);

        p->taille--;

    }
}

