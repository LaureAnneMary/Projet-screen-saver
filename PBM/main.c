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

    choixAleatoireImage(&image); // on va choisir une image aléatoirement, on envoie "&image" pour utiliser par la suite le char de notre structure afin de stocker le nom du fichier PBM tiré aléatoirement

    FILE* fichier = NULL; // notre "FILE*" permet de récupérer le pointeur du fichier pour ensuite pouvoir le manipuler

    fichier = fopen(image.nomImage, "r"); // on ouvre le fichier qui est contenu dans le char de notre structure et on lui assigne "r" pour juste permettre de lire le fichier

    if(fichier != NULL) // peremt de s'assurer que le fichier s'est bien ouvert
    {
        //printf("Le fichier a bien été ouvert\n");
        lireResolution(fichier, &image); // cette fonction va permettre de stocker la résoltion de l'image PBM
        //printf("Votre image a une résolution de : %dx%d\n\n", image.largeurImage, image.longueurImage); // ici on va stocker les deux entiers de résoltuion (longueur x largeur) dans les variables de notre structure Pbm
        insererImageCentreeDansTableau(fichier, &image, tableauPourImage); // cette fonction va nous permettre d'insérer le code de l'image PBM dans notre tableau à deux dimensions tout en centrant l'image
        fclose(fichier); // après avoir fini de manipuler le fichier, il faut fermer le fichier pour libérer la mémoire vive
    }
    else // permet de savoir si le fichier ne s'est pas ouvert
    {
        printf("Impossible");
    }
    afficherTableau(tableauPourImage); // on va afficher le tableau à deux dimensions qui contient le code de l'image PBM, on va afficher un "X" quand la valeur est 0 et un " " quand la valeur est 1

    return 0;
}
