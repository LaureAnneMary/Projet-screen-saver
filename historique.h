#ifndef HISTORIQUE_H_INCLUDED
#define HISTORIQUE_H_INCLUDED
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
typedef struct Historique Historique;
struct Historique{
        struct tm instant;
        int typeEcran;
        char nomImage;
        int hauteur;
        int longueur;
        int positionX;
        int positionY;
        };

void sauvegarde(int n ){
        Historique historique;
        historique.typeEcran=n;
        time_t seconde;
        time(&seconde);
        historique.instant = *localtime(&seconde);
         FILE* fichier = NULL;
        fichier=fopen("historique.txt","w");
        if(fichier!=NULL){
                fprintf(fichier,"%d/%d/%d  %d:%d:%d",instant.tm_mday, instant.tm_mon+1,instant.tm_year,instant.tm_hour,instant.tm_min,instant.tm_sec);
                if(historique.typeEcran==1){
                        fprintf(fichier,"Statique");
                        fprintf(fichier,"%c\n",historique.nomImage);
                }else if(historique.typeEcran==2){
                        fprintf(fichier,"Dynamique");
                        fprintf(fichier,"%d*%d\n",historique.hauteur,historique.longueur)
                }else if(historique.typeEcran==3){
                        fprintf(fichier,"Interactif");
                        fprintf(fichier,"%d*%d\n",positionX, positionY);

        }
        fclose(fichier);
}

#endif // HISTORIQUE_H_INCLUDED
