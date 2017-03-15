/**Auteurs  : Prenom           Nom        **/
/**           Alexandre        Szymkiw    **/
/**           Simon            Fessy      **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "absences.h"

  printf("=====Absences=====!\n");
        printf("21) Faire l'appel des étudiants dans une matière\n");
        printf("22) Modifier une abscence\n");
        printf("23) Supprimer une abscence\n");
        printf("24) Afficher les abscences\n\n");

void FaireAppel(PileAbsences *p, char *matiere)
{
    printf("Entrez les absents : \n");
    Absences *newAbs = (Matieres *)malloc(sizeof(Matieres));
    newAbs->a = (char *)malloc(strlen(matiere)*sizeof(char *));

    if (p == NULL || newAbs == NULL)
    {
        exit(EXIT_FAILURE);
    }
   strcpy(newAbs->matiere);
    strcpy(newAbs->matiere);
    newAbs->suivant = p->premier;
    p->premier = newAbs;
    p->taille++;
}
void ModifierAbsences(PileAbsences *p, char *matiere){
} 

Void 
  
