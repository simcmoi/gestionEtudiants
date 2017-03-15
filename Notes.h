/**Auteurs  : Prenom           Nom        **/
/**           Alexandre        Szymkiw    **/
/**           Simon            Fessy      **/

#ifndef NOTES_H_INCLUDED
#define NOTES_H_INCLUDED

#include "Etudiant.h"
#include "Matieres.h"

#define MAX 200



/**Structure Notes**/
typedef struct Notes Notes;
struct Notes
{
    float **n;
    Notes *suivant;
};

/**Structure PileNotes**/
typedef struct FileNotes FileNotes;
struct FileNotes
{
    Notes *premier;
};

/**Prototypes**/
FileNotes *initialiserNotes();
void ajouterNotes(FileNotes *f,PileMatieres *m,PileEtudiants *e,float *tab,int r);
void supprimerNotes(FileNotes *f,PileEtudiants *e,PileMatieres *m);
void afficherMoyenneMatieres(FileNotes *f,PileMatieres *m);
void afficherNotes(FileNotes *f,PileEtudiants *e,PileMatieres *m,int r);
void afficherMoyenneParEleves(FileNotes *f,PileEtudiants *e,PileMatieres *m);

#endif // NOTES_H_INCLUDED
