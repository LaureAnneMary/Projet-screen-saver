#ifndef HISTORIQUE_H_INCLUDED
#define HISTORIQUE_H_INCLUDED
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

void sauvegarde(int n, char* argument){
      	int typeEcran=n;// La variable obtient le type d'ecran de veille 1, 2 ou 3
        time_t maintenant=time(NULL);//avoir l'heure
        struct tm tm_maintenant=*localtime(&maintenant);/// avoir l'heure locale
	char s_maintenant[sizeof "HH:MM:SS"];//stocker l'heure dans un tableau
	strftime(s_maintenant, sizeof s_maintenant,"%H:%M:%S",&tm_maintenant);
         FILE* fichier = NULL;//initaialisation d'un pointeur a null
        fichier=fopen("historique.txt","w");//ouverture ou creation si il n'existe pas d'un fichier texte historique
        if(fichier!=NULL){
                fprintf(fichier,"%s",s_maintenant);//on stocke le tableau d'heure
                if(typeEcran==1){// si ecran statique
                        fprintf(fichier,"1");//on stocke le type d'ecran de veille
                        fprintf(fichier,"%s\n",argument[1]);// on stocke le nom de l'image
                }else if(typeEcran==2){
                        fprintf(fichier,"2");//on stocke le type dynamqiue
                        fprintf(fichier,"5x3");// on stocke la taille de l'image
                }else if(typeEcran==3){//  type d'ecran interactif
                        fprintf(fichier,"3");//on stocke le type
                        fprintf(fichier,"position initial de l'avion");// on stocke la position initial de l'avion

        }
        fclose(fichier);// fermeture du fichier
}

#endif // HISTORIQUE_H_INCLUDED
