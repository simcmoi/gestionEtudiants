/**Auteurs  : Prenom           Nom        **/
/**           Alexandre        Szymkiw    **/
/**           Simon            Fessy      **/

#ifndef MATIERES_H_INCLUDED
#define MATIERES_H_INCLUDED

#define TAILLE_MAX 100


/**Structure Matieres**/
typedef struct Matieres Matieres;
struct Matieres
{
    char *m;
    int n;
    Matieres *suivant;
};

/**Structure PileMatieres**/
typedef struct PileMatieres PileMatieres;
struct PileMatieres
{
    Matieres *premier;
    int taille;
};

/**Prototypes**/
PileMatieres *initialiserMatieres();
void ajouterMatieres(PileMatieres *p, char *chaine);
void afficherMatieres(PileMatieres *p);
void supprimerMatieres(PileMatieres *p);

#endif
