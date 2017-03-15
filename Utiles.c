/**Auteurs  : Prenom           Nom        **/
/**           Alexandre        Szymkiw    **/
/**           Simon            Fessy      **/

#include <string.h>
#include "Utiles.h"

/************************************************/
/**Fonction : modifChaine***********************/
/**Params : char * ****************************/
/**Sert à prendre en compte les espaces*******/
/********************************************/
void modifChaine(char *chaine){
    char *p = strchr(chaine,'\n');

    if(p){
        *p = 0;
    }
}
