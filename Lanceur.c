#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "historique.h"
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

void processusfils()
{
    int j;
    char *nomImage;
    int n=2;
    int i;
    char* str;
    char chemin_executable[1024];//declaration de deux tableaux de caractères
    srand(time(NULL));
    n=rand()%3+1;
    srand(time(NULL));
    j=rand()%5+1;//tirage aléatoire d'un nombre entre 1 et 5
    char chemin_pbm[1024];
    struct dirent* imagePBM=NULL;
    switch(n)
        {
        case 1:
		str=getenv("EXIASAVER1_PBM");//str va recuperer le chemin de la variable d'environnement
        	if(str != NULL)
        	{
        		strcpy(chemin_pbm, str);//on copie la valeur de str dans chemin si cela-ci n'est pas vide
        	}
        	else
        	{
       			 getcwd(chemin_pbm, 1024); //sinon on donne autre chose(a rechercher)
    		}
    		DIR* ouvrir_pbm;//pointeur
    		ouvrir_pbm=opendir(chemin_pbm);//le pointeur va pointer vers le premier fichier du repertoire
    		if(ouvrir_pbm!=NULL)
   	 	{
        		for(i=0; i<j; i++) //se deplace jusqu'a j ème fichier pour le lire
        		{
            			imagePBM=readdir(ouvrir_pbm);//ouverture du fichier
        		}
		} 

            	str=getenv("EXIASAVER_HOME");//str va chercher le chemin dans EXIASAVER_HOME qui mene aux executables
            	if(str != NULL)
            	{
                	strcpy(chemin_executable, str);//on copie le chemin de str dans le variable chemin2
            	}
            	else
            	{
                	getcwd(chemin_executable, 1024);//sinon str est vide on donne autre chose au tableau chemin2
            	}

            	char* argument[]= {"ecranStatique",imagePBM->d_name,NULL}; // dans un tableau de caractère je met le type d'ecran de veille lancer ainsi que le nom de fichier pbm a ouvr$
            	strcat(chemin_executable, "ecranStatique");//on copie a la suite du chemin que contient deja le tableau /ecranStatique
       	
	     	execv(chemin_executable,argument);// on execute le programme ecranStatique en envoyant en paramètre le chemin vers le fichier a executer avec des paramètres notamment le nom$

            	sauvegarde (n,j);//fonction qui ecrit dans l'historique
            break;
        case 2:
            j=0;
            sauvegarde(n,j );
            str=getenv("EXIASAVER_HOME");
            if (str!=NULL)
            {
                strcpy(chemin_executable,str);
            }
            else
            {
                getcwd(chemin_executable,1024);
            }
            strcat(chemin_executable,"ecranDynamique");
            execl(chemin_executable,"",NULL);
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


int main(int argc, char *argv[])
{
    system("clear");
    if(argc==2)
    {
	if(strcmp(argv[1],"-stat")==0){
		int pid=fork();
		switch(pid){
		case -1:
			printf("Erreur lors de la création du processus fils\n");
			break;
		case 0:
			printf("Je suis le lecteur de l'historique\n");
			execl("lectureHistorique","",NULL);
		}
        }
    }
    else
    {
        int pid=fork();
        switch(pid)
        {
        case -1:
            printf("Erreur lors de la création");
            break;
        case 0:
            processusfils();
            break;
        }
    }
    return 0;
}


