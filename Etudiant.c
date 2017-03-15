/**Auteurs  : Prenom           Nom        **/
/**           Alexandre        Szymkiw    **/
/**           Simon            Fessy      **/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Etudiant.h"

#define MAX 200

/****************************************/
/**Fonction : initialiserEtudiant*******/
/**Params :  **************************/
/**Sert à initialiser les piles*******/
/************************************/
PileEtudiants *initialiserEtudiant()
{
    PileEtudiants *pileEtudiant = malloc(sizeof(pileEtudiant));
    pileEtudiant->premier = NULL;
    pileEtudiant->taille = 0;
    return pileEtudiant;
}

/***************************************************/
/**Fonction : ajouterEtudiant**********************/
/**Params :  PileEtudiants * et char * et char * */
/**Sert à ajouter un étudiant dans la pile*******/
/***********************************************/
void ajouterEtudiant(PileEtudiants *p, char *chaineNom, char *chainePrenom)
{
    Etudiant *newEtu = (Etudiant *)malloc(sizeof(Etudiant));
    newEtu->nom = (char *)malloc(MAX*sizeof(*chaineNom));
    newEtu->prenom = (char *)malloc(MAX*sizeof(*chainePrenom));
    if (p == NULL || newEtu == NULL)
    {
        exit(EXIT_FAILURE);
    }

    strcpy(newEtu->nom,chaineNom);
    strcpy(newEtu->prenom,chainePrenom);
    newEtu->suivant = p->premier;
    p->premier = newEtu;
    p->taille++;
}

/***************************************************/
/**Fonction : afficherEtudiant*********************/
/**Params :  PileEtudiants *  ********************/
/**Sert à afficher les étudiants de la pile******/
/***********************************************/
void afficherEtudiant(PileEtudiants *p){

    int i = 1;
    if (p == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Etudiant *etu = p->premier;
    if(etu == NULL){
        printf("Aucune donnee !! \n");
    }

    printf("id     Prenom     Nom\n");
    while (etu != NULL)
    {
        printf("%d) %s      %s\n",i,etu->prenom, etu->nom);
        etu = etu->suivant;
        i++;
    }
    printf("\n");

}

void supprimerEtudiant(PileEtudiants *p){
    printf("\n");
    if(p->taille == 0){
        printf("\n Aucune matiere a supprimer");
    }else{

        Etudiant *suppEtu = p->premier;
        p->premier = p->premier->suivant;

        free(suppEtu->nom);
        free(suppEtu->prenom);
        free(suppEtu);

        p->taille--;

    }
}
