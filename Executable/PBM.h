#ifndef PBM_H_INCLUDED
#define PBM_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // bibliothèque pour l'utilisation des différentes fonctions de traitement de chaîne de caractères
#include <time.h>   // bibliothèque pour l'utilisation de l'heure local
#include <unistd.h>



typedef struct Pbm Pbm; // on remplace "struct Pbm" par "Pbm" pour raccourcir le code
struct Pbm // définition de notre structure Pbm
{
    int largeurImage;   // ces deux int vont stocker la résolution de l'image
    int longueurImage;
    char nomImage[100]; // va comporter le nom de notre fichier PBM tiré aléatoirement
}

void StatiquechoixAleatoireImage(Pbm* p) // "Pbm* p" est un pointeur sur la structure
{
    int nombreAleatoire;
    int nombreTire;

    srand(time(NULL));      //initialisation de rand
    nombreAleatoire = rand();    //nombre_aleatoire prend la valeur d'un nombre aleatoire grace a la fonction rand()
    nombreTire = nombreAleatoire %5;    //on souhaite un nombre aleatoire de 5 valeurs possible, on utilise donc modulo 5

    switch(nombreTire) // on fait un switch pour pouvoir savoir quelle image tirée en fonction du nombre choihi
    {
        case 0:
            strcpy(p->nomImage, "Batman.pbm");
            break;
        case 1:
            strcpy(p->nomImage, "Captainamerica.pbm");
            break;
        case 2:
            strcpy(p->nomImage, "Wonderwoman.pbm");
            break;
        case 3:
            strcpy(p->nomImage, "Greenlantern.pbm");
            break;
        case 4:
            strcpy(p->nomImage, "Xmen.pbm");
            break;
        default:
            printf("Impossible");
            break;
    }
}

void insererImageCentreeDansTableau(char *fichier, Pbm* p, int tableauPourImage[80][24])
{
    char lectureLigneFichier[71] = ""; // on crée un char pour la lecture des lignes de fichier
    int binaireImagePBM; // variable qui permettra de stocker les différentes valeurs de code de l'image

    fgets(lectureLigneFichier, 71, fichier); // fgets permet de lire une ligne dans un fichier, ici fgets va nous permettre de passer la troisième ligne qui est inutile pour directement arrivé là où le code est définie

    while (fgets(lectureLigneFichier, 71, fichier) != NULL) // à partir d'ici, on va lire toutes le code de l'image jusqu'à la fin du fichier
    {
        for(int z = 0; z < p->longueurImage; z++) // boucle pour permettre de se positionner dans la première colonne
        {
            for(int k = 0; k < p->largeurImage; k++) // boucle pour lire toutes les données de la première ligne
            {
                fscanf(fichier, "%d", &binaireImagePBM); // on stocke l'entier lu dans notre variable "binaireImagePBM"
                // printf("%d", binaireImagePBM);
                tableauPourImage[k + ((80 - p->largeurImage)/2)][z + ((24 - p->longueurImage)/2)] = binaireImagePBM; // on stocke la valeur lue dans notre tableau 2D en partant d'un point précis pour centrer l'image grâc à un calcul
            }
            //printf("\n");
        }
    }
}

void lireResolution(char *fichier, Pbm* p) // fonction qui permet de stocker la résolution de l'image
{
    char lectureLigne[100] = ""; // char qui va permettre de stocker la ligne où est écrit la résoltuion de l'image

    for(int i = 0; i < 2; i++)
    {
        fgets(lectureLigne, 71, fichier); // on saute les deux premières lignes afin de se diriger directement là où est noté la résolution de l'image
    }
    fscanf(fichier, "%d %d", &p->largeurImage, &p->longueurImage); // on récupère les données de la résolution en les stockant dans les variables de notre structures
}

void afficherTableau(int tableauPourImage[80][24]) // fonction qui va afficher notre tableau 2D
{
	char c[] = {226, 150, 136, 0}; //mettre à caractère blanc

    for (int i = 0 ;i < 24; i++) // boucle qui va commencer par la première colonne puis la deuxième après qu'on ait fini de lire toutes les valeurs de la première colonne
    {
        for (int j = 0;j < 80; j++) // boucle qui va lire un par un les données de la première ligne du tableau jusqu'à la dernière valeur
        {
            if(tableauPourImage[j][i] == 0) // si la valeur du tableau est un 0, on va afficher "X"
            {
                printf(" ");
            }
            else // si la valeur n'est pas 0 dans le tableau, alors on affiche " " (espace)
            {
                printf("%s", c);
            }
        }
        printf("\n");
    }
    printf("\n");
}


#endif // PBM_H_INCLUDED
