#include <stdio.h>
#include <stdlib.h>
#include <string.h> // bibliothèque pour l'utilisation des différentes fonctions de traitement de ch$
#include <time.h>   // bibliothèque pour l'utilisation de l'heure local
#include <unistd.h>
#include "PBM.h"

int main(int argc, char *argv[])
{
    Pbm image; // "image" va contenir toutes nos variables situées dans la structure Pbm
    char chemin_pbm[1024];
    int tableauPourImage[80][24] = {0}; // on créer un tableau à deux dimensions rempli de 0
    if(argc==1)
  {
        StatiquechoixAleatoireImage(&image); // on va choisir une image aléatoirement, on envoie "&image" pour u$
    }
    else
    {
        char* argument=argv[1];
        strcpy(image.nomImage, argument);
        char* str;
        str=getenv("EXIASAVER1_PBM");
        if (str != NULL)
        {
            strcpy(chemin_pbm, str);//on copie la valeur de str dans chemin si cela-ci n'est pas vide
        }
        else
        {
            getcwd(chemin_pbm, 1024);
        }
        strcat(chemin_pbm,argument);
    }
    FILE* fichier = NULL; // notre "FILE*" permet de récupérer le pointeur du fichier pour ensuite p$

    fichier = fopen(chemin_pbm, "r"); // on ouvre le fichier qui est contenu dans le char de not$

    if(fichier != NULL) // peremt de s'assurer que le fichier s'est bien ouvert
    {
        //printf("Le fichier a bien été ouvert\n");
        lireResolution(fichier, &image); // cette fonction va permettre de stocker la résoltion de l$
        //printf("Votre image a une résolution de : %dx%d\n\n", image.largeurImage, image.longueurIm$
        insererImageCentreeDansTableau(fichier, &image, tableauPourImage); // cette fonction va nous$
        fclose(fichier); // après avoir fini de manipuler le fichier, il faut fermer le fichier pour$
    }
    else // permet de savoir si le fichier ne s'est pas ouvert
    {
        printf("Impossible");
    }
    afficherTableau(tableauPourImage); // on va afficher le tableau à deux dimensions qui contient l$

    return 0;
}
