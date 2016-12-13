#include <stdio.h>
#include <stdlib.h>

#include "commandes.h"

int main()
{
    int system(const char* command)
    touche = commandeClavier();
    while(1){
        if(touche == 32){ // 3 : touche espace
            printf("C'est la touche %d \n", touche);
        } else if(touche == 24 ){ //24 : flèche du haut
            printf("haut");
        } else if(touche == 25){ // 25 : flèche du bas
            printf("Bas");
        } else if(touche == 26){ // 26 : flèche de droite
            printf("Droite");
        } else if(touche == 27){ // 27 : flèche de gauche
            printf("Gauche");
        } else{
            touche = commandeClavier();
        }
    }
    return 0;
}
