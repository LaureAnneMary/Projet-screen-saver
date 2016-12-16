#include <stdio.h>
#include <stdlib.h>
#include <string.h> // bibliothèque pour l'utilisation des différentes fonctions de traitement de chaîne de caractères
#include <time.h>   // bibliothèque pour l'utilisation de l'heure local
#include <unistd.h>
#include "PBM.h"

int main()
{
    Pbm image; // "image" va contenir toutes nos variables situées dans la structure Pbm
    int tableauPourImage[80][24] = {0}; // on créer un tableau à deux dimensions rempli de 0

 

    FILE* fichier = NULL; // notre "FILE*" permet de récupérer le pointeur du fichier pour ensuite pouvoir le manipuler

    fichier = fopen("Avion droite.pbm", "r"); // on ouvre le fichier qui est contenu dans le char de notre structure et on lui assigne "r" po$

    if(fichier != NULL) // peremt de s'assurer que le fichier s'est bien ouvert
    {
        //printf("Le fichier a bien été ouvert\n");
        lireResolution(fichier, &image); // cette fonction va permettre de stocker la résoltion de l'image PBM
        //printf("Votre image a une résolution de : %dx%d\n\n", image.largeurImage, image.longueurImage); // ici on va stocker les deux entie$
        insererImageCentreeDansTableau(fichier, &image, tableauPourImage); // cette fonction va nous permettre d'insérer le code de l'image P$
        fclose(fichier); // après avoir fini de manipuler le fichier, il faut fermer le fichier pour libérer la mémoire vive
    }
    else // permet de savoir si le fichier ne s'est pas ouvert
    {
        printf("Impossible");
    }
    afficherTableau(tableauPourImage);
 return 0; 
}
