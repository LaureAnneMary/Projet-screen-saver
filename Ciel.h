#ifndef CIEL_H_INCLUDED
#define CIEL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

typedef struct Ciel ciel;
struct ciel
{
    int largeurDécor = 80;
    int longueurDécor = 24;
    int Décor[largeurDécor][longueurDécor];
    }
struct avion
{
    int largeurAvion = 3;
    int longeurAvion= 5
    char Avion[100];
    }
void ouvrirDécor()
{
    image = "Avion.pbm";
    int Décor[largeurDécor][longueurDécor] = {0}; // on créer un tableau à deux dimensions rempli de 0

    FILE* fichier = NULL; // notre "FILE*" permet de récupérer le pointeur du fichier pour ensuite pouvoir le manipuler

    fichier = fopen(image, "r"); // on ouvre le fichier qui est contenu dans le char de notre structure et on lui assigne "r" pour juste permettre de lire le fichier

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

    return 0;}

void lireResolution(char *fichier, Pbm* p)
{
    char lectureLigne[10] = "";
    for(int i=0; i<2; i++)
    {
        fgets(lectureLigne, 71, fichier);
    }
    scanf(fichier, "%d, %d", &p->largeurAvion, &p->longueurAvion);
    }

void insererImageCentreeDansTableau(char *fichier, Avion* p, Décor[largeurDécor][longueurDécor])
{
    char lectureLigneFichier[100] = "";
    int binaireAvion;

    fgets(lectureLigneFichier, 71, fichier);

    while(fgets(lectureLigneFichier, 71, fichier) != NULL)
    {
        for(int z = 0; z < p->longueurAvion; z++)
        {
            for(int k=0; k < p->largeurAvion; k++)
            {
                fcanf(fichier, "%d", binaireAvion);
                Décor[k + ((largeurDécor - p-<largeurAvion)/2)][z + ((longueurDécor - p->longeurAvion)/2)] = binaireAvion;
            }
        }
    }
}

void afficherTableau(Décor[largeurDécor][longueurDécor]) // fonction qui va afficher notre tableau 2D
{
	char c[] = {226, 150, 136, 0}; //mettre à caractère blanc

    for (int i = 0 ;i < 24; i++) // boucle qui va commencer par la première colonne puis la deuxième après qu'on ait fini de lire toutes les valeurs de la première colonne
    {
        for (int j = 0;j < 80; j++) // boucle qui va lire un par un les données de la première ligne du tableau jusqu'à la dernière valeur
        {
            if(Décor[j][i] == 0) // si la valeur du tableau est un 0, on va afficher "X"
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


#endif // CIEL_H_INCLUDED
