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
    char nomImage[100][100]; // va comporter le nom de notre fichier PBM tiré aléatoirement
};

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

    for (int i = 0 ;i < 20; i++) // boucle qui va commencer par la première colonne puis la deuxième après qu'on ait fini de lire toutes les valeurs de la première colonne
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

void tableauHorloge(int tableauPourImage[80][24])
{
    time_t seconds;
    struct tm actualTime;
    FILE* fichier = NULL;
    char lectureLigne[100] = "";
    int valeurCase;
    time(&seconds);
    actualTime=*localtime(&seconds);
    //printf("Il est actuellement %.2d:%.2d:%.2d\n", actualTime.tm_hour, actualTime.tm_min, actualTi$
    int tabHorloge[6] = {0};
    tableauPourImage[10][1] = 1;
    tableauPourImage[10][3] = 1;
    tableauPourImage[22][1] = 1;
    tableauPourImage[22][3] = 1;
    tabHorloge[0]=actualTime.tm_hour/10;
    tabHorloge[1]=actualTime.tm_hour%10;
    tabHorloge[2]=actualTime.tm_min/10;
    tabHorloge[3]=actualTime.tm_min%10;
    tabHorloge[4]=actualTime.tm_sec/10;
    tabHorloge[5]=actualTime.tm_sec%10;
    printf("\n");
    for(int i = 0; i < 6; i++)
    {
        switch(tabHorloge[i])
        {
        case 0:
            fichier = fopen("Chiffre0.pbm", "r");
            for(int a =0; a< 2 ; a++)
            {
                fgets(lectureLigne, 71,fichier);
            }
            fgets(lectureLigne, 71, fichier);
            for(int z = 0; z < 5; z++)
            {
                for(int k = 0; k < 3; k++)
                {
                    fscanf(fichier, "%d", &valeurCase);
                    tableauPourImage[(i*6)+k][z] = valeurCase;
                }
            }
	    fclose(fichier);
            break;
        case 1:
            fichier = fopen("Chiffre1.pbm", "r");
            for(int b =0; b< 3 ; b++)
            {
                fgets(lectureLigne, 71,fichier);
            }
            for(int z = 0; z < 5; z++)
            {
                for(int k = 0; k < 3; k++)
                {
                    fscanf(fichier, "%d", &valeurCase);
                    tableauPourImage[(i*6)+k][z] = valeurCase;
                }
            }
            fclose(fichier);
            break;
        case 2:
            fichier = fopen("Chiffre2.pbm", "r");
            for(int c =0; c< 3 ; c++)
            {
                fgets(lectureLigne, 71,fichier);
            }
            for(int z = 0; z < 5; z++)
	    {
                for(int k = 0; k < 3; k++)
                {
                    fscanf(fichier, "%d", &valeurCase);
                    tableauPourImage[(i*6)+k][z] = valeurCase;
                }
            }
            fclose(fichier);
            break;
        case 3:
            fichier = fopen("Chiffre3.pbm", "r");
            for(int q =0; q< 3 ; q++)
            {
                fgets(lectureLigne, 71,fichier);
            }
            for(int z = 0; z < 5; z++)
            {
                for(int k = 0; k < 3; k++)
                {
                    fscanf(fichier, "%d", &valeurCase);
                    tableauPourImage[(i*6)+k][z] = valeurCase;
                }
            }
            fclose(fichier);
            break;
	 case 4:
             fichier = fopen("Chiffre4.pbm", "r");
            for(int e =0; e< 3 ; e++)
            {
                fgets(lectureLigne, 71,fichier);
            }
            for(int z = 0; z < 5; z++)
            {
                for(int k = 0; k < 3; k++)
                {
                    fscanf(fichier, "%d", &valeurCase);
                    tableauPourImage[(i*6)+k][z] = valeurCase;
                }
            }
            fclose(fichier);
            break;
        case 5:
            fichier = fopen("Chiffre5.pbm", "r");
            for(int f =0; f< 3 ; f++)
            {
                fgets(lectureLigne, 71,fichier);
            }
            for(int z = 0; z < 5; z++)
            {
                for(int k = 0; k < 3; k++)
                {
                    fscanf(fichier, "%d", &valeurCase);
                    tableauPourImage[(i*6)+k][z] = valeurCase;
                }
            }
            fclose(fichier);
            break;
        case 6:
            fichier = fopen("Chiffre6.pbm", "r");
            for(int g =0; g< 3 ; g++)
            {
                fgets(lectureLigne, 71,fichier);
            }
            for(int z = 0; z < 5; z++)
            {
                for(int k = 0; k < 3; k++)
                {
                    fscanf(fichier, "%d", &valeurCase);
                    tableauPourImage[(i*6)+k][z] = valeurCase;
                }
            }
            fclose(fichier);
            break;
        case 7:
            fichier = fopen("Chiffre7.pbm", "r");
            for(int h =0; h< 3 ; h++)
            {
                fgets(lectureLigne, 71,fichier);
            }
            for(int z = 0; z < 5; z++)
            {
                for(int k = 0; k < 3; k++)
                {
                    fscanf(fichier, "%d", &valeurCase);
                    tableauPourImage[(i*6)+k][z] = valeurCase;
                }
            }
            fclose(fichier);
            break;
        case 8:
            fichier = fopen("Chiffre8.pbm", "r");
            for(int l =0; l< 3 ; l++)
            {
                fgets(lectureLigne, 71,fichier);
            }
            for(int z = 0; z < 5; z++)
            {
                for(int k = 0; k < 3; k++)
                {
                    fscanf(fichier, "%d", &valeurCase);
		    tableauPourImage[(i*6)+k][z] = valeurCase;
                }
            }
            fclose(fichier);
            break;
        case 9:
            fichier = fopen("Chiffre9.pbm", "r");
            for(int m =0; m< 3 ; m++)
            {
                fgets(lectureLigne, 71,fichier);
            }
            for(int z = 0; z < 5; z++)
            {
                for(int k = 0; k < 3; k++)
                {
                    fscanf(fichier, "%d", &valeurCase);
                    tableauPourImage[(i*6)+k][z] = valeurCase;
                }
            }
            fclose(fichier);
            break;
        default:
            exit(2);
            break;
        }
    }
}


#endif // PBM_H_INCLUDED

