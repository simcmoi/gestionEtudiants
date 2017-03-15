/**Auteurs  : Prenom           Nom        **/
/**           Alexandre        Szymkiw    **/
/**           Simon            Fessy      **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Matieres.h"
#include "Notes.h"
#include "Etudiant.h"
#include "Utiles.h"

#define MAX 200



int main()
{
    /**Déclaration des variables**/
    int choix = -1; /**initialise la variable qui sert à faire un choix dans le menu**/
    int i;

    /**variables qui servent à enregistrer les valeurs saisies au clavier**/
    char mat[MAX];
    char nomEtu[MAX];
    char prenomEtu[MAX];

    int noteMatiere;
    float tabNotes[MAX];
    float tmpNote;


    char choix2 = 'n'; /**Variables qui sert à sortir de la boucle while**/

    /**initialisation des piles**/
    PileMatieres *pileMatiere = initialiserMatieres();
    PileEtudiants *pileEtudiant = initialiserEtudiant();

    FileNotes *fileNote = initialiserNotes();

    Etudiant *tmpEtu;

    /**Fin de déclaration de variables**/

    /**Affichage du menu**/
    while(choix != 0){

        system ("cls");
        printf("\n=====GESTION ETUDIANT=====!\n");
        printf("1) Afficher les étudiants\n");
        printf("2) Ajouter un étudiant\n");
        printf("3) Supprimer un étudiant\n");
        printf("4) Rechercher un étudiant\n");
        printf("5) Modifier un étudiant\n\n");

        printf("=====Notes=====!\n");
        printf("11) Voir la moyenne de chaque etudiants\n");
        printf("12) Voir les notes des étudiants dans une matière\n");
        printf("13) Ajouter une note dans une matière\n");
        printf("14) Voir la moyenne de chaque matieres\n");

        printf("=====Abscences=====!\n");
        printf("21) Faire l'appel des étudiants dans une matière\n");
        printf("24) Afficher les abscences\n\n");

        printf("=====Matières=====!\n");
        printf("31) Ajouter une matière\n");
        printf("33) Supprimer la dernière matière ajoutée\n");
        printf("34) Afficher les matières\n\n");


        printf("0) Quitter\n\n");

        printf("Votre choix : ");
        scanf("%d",&choix);

        switch(choix){

        case 1:
            system("cls");
            fflush(stdin);
            printf("======Affichage des etudiants=====\n");

            while(choix2 != 'o'){
                afficherEtudiant(pileEtudiant);
                printf("\n\n Voulez-vous retourner au menu ? ");
                scanf("%c",&choix2);
            }
            choix2 = 'n';

        break;
        case 2:
            system ("cls");
            fflush(stdin);

            printf("=====Ajouter un etudiant=====\n");
            printf("Nom de l etudiant :  ");
            fgets(nomEtu,sizeof(nomEtu),stdin);

            modifChaine(nomEtu);
            fflush(stdin);

            printf("\nPrenom de l etudiant :  ");
            fgets(prenomEtu,sizeof(prenomEtu),stdin);
            modifChaine(prenomEtu);

            fflush(stdin);

            ajouterEtudiant(pileEtudiant,nomEtu,prenomEtu);
        break;

        case 3:
            system("cls");
            fflush(stdin);
            printf("=====Supprimer un etudiant=====\n");
            supprimerNotes(fileNote,pileEtudiant,pileMatiere);
            supprimerEtudiant(pileEtudiant);
        break;

        case 12:
            system("cls");
            fflush(stdin);

            printf("Liste des matieres : \n");
            afficherMatieres(pileMatiere);
            printf("\n");

            printf("Dans quelle matiere voulez-vous afficher les notes ? (entrer un chiffre entre 1 et %d)",pileMatiere->taille);
            scanf("%d",&noteMatiere);

            fflush(stdin);
            system("cls");
            printf("======Affichage des Notes=====\n");

            while(choix2 != 'o'){
                afficherNotes(fileNote,pileEtudiant,pileMatiere,noteMatiere);
                printf("\n\n Voulez-vous retourner au menu ? ");
                scanf("%c",&choix2);
            }
            choix2 = 'n';
        break;

        case 13:
            system("cls");
            fflush(stdin);

            printf("Liste des matieres : \n");
            afficherMatieres(pileMatiere);
            printf("\n");

            if(pileMatiere->taille > 0 || pileEtudiant->taille > 0){
                printf("Dans quelle matiere voulez-vous entrer les notes ? (entrer un chiffre entre 1 et %d)",pileMatiere->taille);
                scanf("%d",&noteMatiere);

                fflush(stdin);
                system("cls");
                printf("=====Ajouter des notes=====\n");


                tmpEtu = pileEtudiant->premier;
                for(i=0;i<pileEtudiant->taille;i++){
                    printf("Note pour %s %s : ",tmpEtu->prenom,tmpEtu->nom);
                    scanf("%f",&tmpNote);
                    tabNotes[i] = tmpNote;
                    tmpEtu = tmpEtu->suivant;
                }
                ajouterNotes(fileNote,pileMatiere,pileEtudiant,tabNotes,noteMatiere);
            }else{
                while(choix2 != 'o'){
                    printf("ERREUR : Matiere manquante (nombre de matiere : %d) ou Etudiant manquant (nombre etudiants : %d)\n",pileMatiere->taille,pileEtudiant->taille);
                    printf("\n\n Voulez-vous retourner au menu ? ");
                    scanf("%c",&choix2);
                }
                choix2 = 'n';
            }

        break;

        case 31:
            system ("cls");

            printf("=====Ajouter une matiere=====\n");
            printf("Ajouter une matière : ");
            fflush(stdin);
            fgets(mat,sizeof(mat),stdin);
            modifChaine(mat);
            fflush(stdin);
            ajouterMatieres(pileMatiere,mat);
        break;

        case 33:
            system ("cls");

            printf("=====Supprimer une matiere=====\n");
            supprimerMatieres(pileMatiere);
        break;

        case 34:

            system ("cls");
            fflush(stdin);
            printf("=====Affichage des matieres=====\n");

            while(choix2 != 'o'){
                afficherMatieres(pileMatiere);
                printf("Voulez-vous revenir au menu ? (Tapez o pour revenir) : \n");
                scanf("%c",&choix2);
            }
            choix2 = 'n';
        break;

        case 0:
            system ("cls");
            printf("Application terminée !!");
        break;

        default:
            system ("cls");
            printf("ERREUR : Ce choix n'est pas disponible !!");
        break;

        }
    }

    return 0;

    /**Fin du programme **/
}
