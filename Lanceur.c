#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "historique.h"
#include <sys/types.h>
#include <dirent.h>

void processusfils(){
        int n;
        int j;
        int i;
        char* str;
 	    char chemin[1024];
 	    char chemin2[1024];//declaration de deux tableaux de caractères
        struct dirent* fichierLu=NULL;
        srand(time(NULL));
        j=rand()%5+1;//tirage aléatoire d'un nombre entre 1 et 5
        srand(time(NULL));
        n=rand()%3+1;
        while(1){
                switch(n){
                        case 1:
                                str=getenv("EXIASAVER1_PBM");//str va recuperer le chemin de la variable d'environnement
				if(str != NULL) strcpy(chemin, str);//on copie la valeur de str dans chemin si cela-ci n'est pas vide
				else getcwd(chemin, 1024); //sinon on donne autre chose(a rechercher)
				str=getenv("EXIASAVER_HOME");//str va chercher le chemin dans EXIASAVER_HOME qui mene aux executables
				if(str != NULL) strcpy(chemin2, str);//on copie le chemin de str dans le variable chemin2
				else getcwd(chemin2, 1024);//sinon str est vide on donne autre chose au tableau chemin2
                                DIR* ouvrir;//pointeur
                                ouvrir=opendir(chemin);//le pointeur va pointer vers le premier fichier du repertoire
                                if(ouvrir!=NULL){
                                        for(i=0;i<j;i++){//se deplace jusqu'a j ème fichier pour le lire
                                                fichierLu=readdir(ouvrir);//ouverture du fichier
                                        }
                                        char* argument[]={"statique",fichierLu->d_name,NULL};// dans un tableau de caractère je met le type d'ecran de veille lancer ainsi que le nom de fichier pbm a ouvrir.
                                        strcat(chemin2, "/ecranStatique");//on copie a la suite du chemin que contient deja le tableau /ecranStatique
					execl(chemin2,argument);// on execute le programme ecranStatique en envoyant en paramètre le chemin vers le fichier a executer avec des paramètres notamment le nom de l'image
                                }
                                sauvegarde (n,j);//fonction qui ecrit dans l'historique
                                closedir(ouvrir);//on ferme le fichier que l'on a ouvert
                                break;
                        case 2:
                                j=0;
                                sauvegarde(n,j );
                               // execl("ecranDynamique","",NULL);
                                printf("je suis l'ecran dynamique\n");
                                break;
                        case 3:
                                j=0;
                                sauvegarde(n,j);
                                //execl("ecranInteractif","",NULL);
                                printf("je suis l'ecran interactif\n");
                                break;
                }
       }
}
void main(int argc, char *argv[])
{
	system("clear");
	if(argc==2){
		if(strcmp(argv[1],"-stats")==0){
			execl("lectureHistorique","",NULL);
		}
	}else{
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
}
