#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "historique.h"
#include <sys/types.h>
#include <dirent.h>

int  processusfils(){
        int n;
	int j;
	int i;
	srand(time(NULL));
	j=rand()%5+1;
        srand(time(NULL));
        n=rand()%3+1;
       // while(1){
                switch(n){
                        case 1:
				struct dirent* fichierLu=NULL;//declaration d'un pointeur vers la structure dirent
				char* chemin;
				chemin=getenv("EXIASAVER1_PBM");// on donne a la variable chemin le chemin vers le repertoire qui contient les images
				DIR* ouvrir;//pointeur
				ouvrir=opendir(chemin);//le pointeur va pointer vers le premier fichier du repertoire
				if(ouvrir!=NULL){
					for(i=0;i<j;i++){
						fichierLu=readdir(ouvrir);
					}
					char* argument[]={"statique",fichierLu->d_name};
					execl("EXIASAVER_HOME/ecranStatique",argument,NULL);
				}
				sauvegarde (n,argument);
				closedir(ouvrir);
				break;
                        case 2:
				char* argument[]="";
				sauvegarde(n, argument);
                               // execl("ecranDynamique","",NULL);
				printf("je suis l'ecran dynamique\n");
                                break;
                        case 3:
				char* argument[]="";
				sauvegarde(n,argument);
                                //execl("ecranInteractif","",NULL);
				printf("je suis l'ecran interactif\n");
                                break;
                }
       // }
	return n;
}

void main(){
	//lance la veille
	system("clear");
	int n;
	int pid=fork();
	switch(pid){
	case -1:
		printf("Erreur lors de la création");
		break;
	case 0:

		processusfils();
		break;
	}
}

