#ifndef HISTORIQUE_H_INCLUDED
#define HISTORIQUE_H_INCLUDED
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <dirent.h>


void sauvegarde(int n,int j){
        int typeEcran=n;// La variable obtient le type d'ecran de veille 1, 2 ou 3
        time_t maintenant=time(NULL);//avoir l'heure
        struct tm tm_maintenant=*localtime(&maintenant);/// avoir l'heure locale
        char s_maintenant[sizeof "HH:MM:SS"];//stocker l'heure dans un tableau
        strftime(s_maintenant, sizeof s_maintenant,"%H:%M:%S",&tm_maintenant);
         FILE* fichier = NULL;//initaialisation d'un pointeur a null
        fichier=fopen("historique.txt","a++");//ouverture ou creation si il n'existe pas d'un fichie$
        if(fichier!=NULL){
                fprintf(fichier,"%s",s_maintenant);//on stocke le tableau d'heure
                if(typeEcran==1){// si ecran statique
                         int i;
                        struct dirent* fichierLu=NULL;
                         char* chemin=getenv("EXIASAVER1_PBM");
                         DIR* ouvrir=opendir(chemin);
                        if(ouvrir!=NULL){
                                for(i=0;i<j;i++){
                                         fichierLu=readdir(ouvrir);
                                }
                        }
                        fprintf(fichier,"statique");//on stocke le type d'ecran de veille
                        fprintf(fichier,"%s\n",fichier->d_image);// on stocke le nom de l'image
                }else if(typeEcran==2){
                        fprintf(fichier,"dynamique");//on stocke le type dynamqiue
                        fprintf(fichier,"5x3\n");// on stocke la taille de l'image
                }else if(typeEcran==3){//  type d'ecran interactif
                        fprintf(fichier,"interactif");//on stocke le type
                        fprintf(fichier,"position initial de l'avion\n");// on stocke la position in$

        }
        fclose(fichier);// fermeture du fichier
}




#endif // HISTORIQUE_H_INCLUDED
