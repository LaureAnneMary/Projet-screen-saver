#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
int  processusfils(){
        int n;
        srand(time(NULL));
        n=rand()%3+1;
       // while(1){
                switch(n){
                        case 1:
                                printf("je suis l'ecran statique\n");
                                //execl("ecranStatique","",NULL);
                                break;
                        case 2:
                                printf("je suis l'ecran dynamique\n");
                                //execl("ecranDynamique","",NULL);
                                break;
                        case 3:
                                printf("je suis l'ecran interactif\n");
                                //execl("ecranInteractif","",NULL);
                                break;
                }
       // }
	return n;
}

void sauvegarde(int n){
	FILE* fichier = NULL;
	time_t secondes;
	struct tm instant;
	fichier=fopen("historique.txt","w");
	if(fichier!=NULL){
	fprintf(fichier,"%d/%d/%d  %d:%d:%d, %d",instant.tm_mday, instant.tm_mon+1,instant.tm_year,instant.tm_hour, instant.tm_min, instant.tm_sec, n); 
	}
	fclose(fichier);
}
void afficherhistorique(){
	FILE* fichier=NULL;
	char texte[7]="";
	fichier=fopen("historique.txt","r");
	if(fichier!=NULL){
		fscanf(fichier,"%d %d %d %d %d %d %d", %texte[0], %texte[1], %texte[2], %texte[3], %texte[4], %texte[5], %texte[6]);
		printf("%d/%d/%d  %d:%d:%d, %d",texte[0],texte[1],texte[2],texte[3],texte[4],texte[5],texte[6]);
	}
	fclose(fichier);
}
void main(){
	//lance la veille
	int n;
	int pid=fork();
	switch(pid){
	case -1:
		printf("Erreur lors de la création");
		break;
	case 0:

		n=processusfils();
		sauvegarde(n);
		break;
	}
	afficherhistorique();
}

