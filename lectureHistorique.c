#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void main(){
	int choix=1;
	FILE* fichier=NULL;
       	int lecteur=0;
        fichier=fopen("historique.txt","r");
	printf("Bonjour, tu es dans le menu de l'historique.\n Si tu veux ton historique en fonction de l'heure tape 1. \n Si tu veux ton historique en fonction du type, tape 2\n");
	printf("Choisi soit 1, soit 2: ");
        //scanf("%d",&choix);
	
	switch(choix)
	{
	case 1:
		if(fichier!=NULL){
			do{	
				lecteur=fgetc(fichier);
				printf("%c",lecteur);
			}while(lecteur!=EOF); // on lit un a un les caractères du fichier tant que l'on est pas arriver a EOF End Of File
		fclose(fichier);
		}
		break;
	case 2:	

		system("sort historique.txt");
                fclose(fichier);
		break;
	default :
		printf("Non");
	}
}
