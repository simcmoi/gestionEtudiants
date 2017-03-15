/**Auteurs  : Prenom           Nom        **/
/**           Alexandre        Szymkiw    **/
/**           Simon            Fessy      **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Notes.h"
#include "Etudiant.h"

#define MAX 200

/****************************************/
/**Fonction : initialiserNotes**********/
/**Params :  **************************/
/**Sert à initialiser les Files*******/
/************************************/
FileNotes *initialiserNotes(){
    FileNotes *fileNote = malloc(sizeof(*fileNote));

    fileNote->premier = NULL;


    return fileNote;
}

/**********************************************************************/
/**Fonction : ajouterNotes********************************************/
/**Params :  FileNotes * et PileEtudiants *e, double * , int ********/
/**Sert à ajouter les notes dans la file ***************************/
/******************************************************************/
void ajouterNotes(FileNotes *f,PileMatieres *m,PileEtudiants *e,float *tab,int r){
    int i;

    Notes *newNote = malloc(sizeof(*newNote));
    newNote->n = (float *)malloc(MAX*sizeof(newNote->n));

    for(i=0;i<MAX;i++){
        newNote->n[i] = (float **)malloc(MAX*sizeof(newNote->n));
    }
    for(i=0;i<e->taille;i++){
        newNote->n[i][r-1] = tab[i];
    }
    newNote->suivant = NULL;

    if(e->taille == 0 || m->taille == 0){
        printf("Aucun etudiant : impossible d ajoute une note !!");
    }else if(f->premier == NULL){
        f->premier = newNote;
    }else{
        Notes *tmp = f->premier;

        while(tmp->suivant != NULL){
            tmp = tmp->suivant;
        }
        tmp->suivant = newNote;
    }
}

/*****************************************************/
/**Fonction : supprimerNotes*************************/
/**Params :  FileNote * ****************************/
/**Sert à supprimer les notes d'un étudiant *******/
/*************************************************/
void supprimerNotes(FileNotes *f,PileEtudiants *e,PileMatieres *m){
    int i,j,k,l,p;
    float **tmp = (float *)malloc(MAX*sizeof(*tmp));
    int t = -1;
    for(p=0;p<MAX;p++){
        tmp[p] = (float **)malloc(MAX*sizeof(tmp));
    }
    if(f->premier != NULL){

        Notes *suppNote = f->premier;

        for(i=0;i<e->taille;i++){
            for(j=0;j<m->taille;j++){
                suppNote->n[i][j] = f->premier->n[i+1][j];
            }
        }
    }else{
        printf("Aucune note à supprimer");
    }
}

void afficherNotes(FileNotes *f,PileEtudiants *e,PileMatieres *m,int r){
    int i;
    if(f->premier == NULL){
        printf("Aucune notes a afficher !!\n");
    }else if(e->taille == 0 || m->taille == 0){
        printf("Aucune notes à afficher !!");
    }else{
        Etudiant *tmp = e->premier;
        for(i=0;i<e->taille;i++){
            if(f->premier->n[i][r-1] >= 0){
                printf("%d) %s %s : %f\n",i+1,tmp->prenom,tmp->nom,f->premier->n[i][r-1]);
            }else{
                printf("%d) %s %s : ABSENT\n",i,tmp->prenom,tmp->nom);
            }

            tmp = tmp->suivant;
        }
    }
}
