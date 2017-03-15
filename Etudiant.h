/**Auteurs  : Prenom           Nom        **/
/**           Alexandre        Szymkiw    **/
/**           Simon            Fessy      **/


#ifndef ETUDIANT_H_INCLUDED
#define ETUDIANT_H_INCLUDED

/**Structure de Etudiant**/
typedef struct Etudiant Etudiant;
struct Etudiant
{
    char *nom;
    char *prenom;
    Etudiant *suivant;
};

/**Strucuture de la pile d'étudiants**/
typedef struct PileEtudiants PileEtudiants;
struct PileEtudiants
{
    Etudiant *premier;
    int taille;
};

/**Prototypes**/
PileEtudiants *initialiserEtudiant();
void ajouterEtudiant(PileEtudiants *p, char *chaineNom, char *chainePrenom);
void afficherEtudiant(PileEtudiants *p);
void rechercherEtudiant(PileEtudiants *p, char etudiantTrouver);
void supprimerEtudiant(PileEtudiants *p);

#endif // ETUDIANT_H_INCLUDED
